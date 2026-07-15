// testPolynomial.cpp
// Test driver for the Polynomial class.
// Compile:  g++ -std=c++11 -Wall Polynomial.cpp testPolynomial.cpp -o testPolynomial

#include <iostream>
#include <cmath>
#include "Polynomial.h"

using namespace std;

static int testsRun = 0;
static int testsPassed = 0;

void check(const char* label, bool condition)
{
    testsRun++;
    if (condition) testsPassed++;
    cout << (condition ? "  [PASS] " : "  [FAIL] ") << label << endl;
}

// Coefficients are doubles, so compare with a tolerance.
bool nearly(double a, double b)
{
    return fabs(a - b) < 1e-9;
}

void section(const char* title)
{
    cout << "\n===== " << title << " =====" << endl;
}

int main()
{
    // ------------------------------------------------------------------
    section("1. Constructors and destructor");
    // ------------------------------------------------------------------
    {
        Polynomial zero;
        check("default constructor: termCount == 0", zero.getTermCount() == 0);
        cout << "  Zero polynomial prints as: " << zero << endl;

        Polynomial p;
        p.addTerm(3, 2);
        p.addTerm(5, 0);
        check("after two addTerm calls: termCount == 2", p.getTermCount() == 2);
        cout << "  p = " << p << "   (expected 3x^2 + 5)" << endl;
    }

    // ------------------------------------------------------------------
    section("2. Deep copy (copy constructor)");
    // ------------------------------------------------------------------
    {
        Polynomial p;
        p.addTerm(4, 3);
        p.addTerm(2, 1);
        p.addTerm(-6, 0);             // 4x^3 + 2x - 6

        Polynomial q = p;             // copy constructor
        check("copy has the same term count", q.getTermCount() == 3);
        check("copy has the same coefficients", nearly(q.getCoefficient(3), 4));

        q.addTerm(100, 3);            // mutate the copy
        check("modifying the copy does not touch the original",
              nearly(p.getCoefficient(3), 4));
        check("the copy really changed", nearly(q.getCoefficient(3), 104));

        p.removeTerm(1);
        check("modifying the original does not touch the copy",
              nearly(q.getCoefficient(1), 2));

        Polynomial emptyCopy = Polynomial();
        check("copying an empty polynomial is safe", emptyCopy.getTermCount() == 0);
    }

    // ------------------------------------------------------------------
    section("3. Deep copy (copy assignment)");
    // ------------------------------------------------------------------
    {
        Polynomial p;
        p.addTerm(4, 3);
        p.addTerm(2, 1);

        Polynomial q;
        q.addTerm(9, 9);              // give q existing memory to release
        q.addTerm(8, 8);
        q.addTerm(7, 7);

        q = p;
        check("assignment copies the term count", q.getTermCount() == 2);
        check("assignment discards the old terms", nearly(q.getCoefficient(9), 0));
        check("assignment copies the new terms", nearly(q.getCoefficient(3), 4));

        q.addTerm(50, 3);
        check("assignment is a deep copy", nearly(p.getCoefficient(3), 4));

        p = p;                        // self-assignment must not corrupt or crash
        check("self-assignment leaves the object intact",
              p.getTermCount() == 2 && nearly(p.getCoefficient(3), 4));

        Polynomial empty;
        p = empty;                    // assigning an empty polynomial
        check("assigning an empty polynomial empties the target",
              p.getTermCount() == 0);
    }

    // ------------------------------------------------------------------
    section("4. addTerm behaviour");
    // ------------------------------------------------------------------
    {
        Polynomial p;
        p.addTerm(3, 2);
        p.addTerm(5, 0);              // 3x^2 + 5

        p.addTerm(4, 2);              // combine with the existing x^2 term
        check("adding to an existing exponent combines coefficients",
              nearly(p.getCoefficient(2), 7));
        check("combining does not create a duplicate term", p.getTermCount() == 2);
        cout << "  after addTerm(4,2): " << p << "   (expected 7x^2 + 5)" << endl;

        p.addTerm(-7, 2);             // coefficient becomes zero -> term is dropped
        check("a term whose coefficient reaches zero is removed",
              p.getTermCount() == 1);
        check("the zero exponent lookup returns 0", nearly(p.getCoefficient(2), 0));
        cout << "  after addTerm(-7,2): " << p << "   (expected 5)" << endl;

        p.addTerm(0, 5);              // adding a zero coefficient
        check("adding a zero coefficient stores nothing", p.getTermCount() == 1);

        Polynomial big;
        for (int i = 0; i < 30; i++) big.addTerm(1, i);
        check("many additions grow the array correctly", big.getTermCount() == 30);
        for (int i = 0; i < 30; i++) big.addTerm(-1, i);
        check("cancelling every term empties the polynomial",
              big.getTermCount() == 0);
    }

    // ------------------------------------------------------------------
    section("5. removeTerm");
    // ------------------------------------------------------------------
    {
        Polynomial p;
        p.addTerm(4, 3);
        p.addTerm(2, 1);
        p.addTerm(-6, 0);             // 4x^3 + 2x - 6

        p.removeTerm(1);
        check("removeTerm reduces the term count", p.getTermCount() == 2);
        check("removeTerm removes the right term", nearly(p.getCoefficient(1), 0));
        check("removeTerm preserves the other terms",
              nearly(p.getCoefficient(3), 4) && nearly(p.getCoefficient(0), -6));
        cout << "  after removeTerm(1): " << p << "   (expected 4x^3 - 6)" << endl;

        p.removeTerm(99);             // exponent that is not present
        check("removing a missing exponent changes nothing", p.getTermCount() == 2);

        p.removeTerm(3);
        p.removeTerm(0);
        check("removing every term leaves an empty polynomial",
              p.getTermCount() == 0);
    }

    // ------------------------------------------------------------------
    section("6. simplify");
    // ------------------------------------------------------------------
    {
        Polynomial p;
        p.addTerm(1, 0);
        p.addTerm(5, 3);
        p.addTerm(2, 1);
        p.addTerm(4, 2);              // added out of order on purpose

        p.simplify();
        check("simplify keeps every distinct term", p.getTermCount() == 4);
        check("simplify preserves the values",
              nearly(p.getCoefficient(3), 5) && nearly(p.getCoefficient(0), 1));
        cout << "  simplified: " << p
             << "   (expected descending: 5x^3 + 4x^2 + 2x + 1)" << endl;

        p.simplify();                 // simplify must be idempotent
        check("simplify is safe to call twice", p.getTermCount() == 4);

        Polynomial empty;
        empty.simplify();
        check("simplify on an empty polynomial is safe", empty.getTermCount() == 0);
    }

    // ------------------------------------------------------------------
    section("7. Information functions");
    // ------------------------------------------------------------------
    {
        Polynomial p;
        p.addTerm(2, 1);
        p.addTerm(5, 3);
        p.addTerm(-7, 0);             // 5x^3 + 2x - 7

        check("degree returns the highest exponent", p.degree() == 3);
        check("getCoefficient finds an existing exponent",
              nearly(p.getCoefficient(3), 5));
        check("getCoefficient finds the constant term",
              nearly(p.getCoefficient(0), -7));
        check("getCoefficient returns 0 for a missing exponent",
              nearly(p.getCoefficient(2), 0));

        // P(2) = 5*8 + 2*2 - 7 = 37
        check("evaluate(2) == 37", nearly(p.evaluate(2), 37));
        // P(0) = -7
        check("evaluate(0) == -7", nearly(p.evaluate(0), -7));
        // P(-1) = -5 - 2 - 7 = -14
        check("evaluate(-1) == -14", nearly(p.evaluate(-1), -14));
        // P(0.5) = 5*0.125 + 1 - 7 = -5.375
        check("evaluate(0.5) == -5.375", nearly(p.evaluate(0.5), -5.375));

        Polynomial zero;
        check("evaluate on the zero polynomial returns 0",
              nearly(zero.evaluate(3), 0));
    }

    // ------------------------------------------------------------------
    section("8. Derivative");
    // ------------------------------------------------------------------
    {
        Polynomial p;
        p.addTerm(3, 3);
        p.addTerm(2, 2);
        p.addTerm(-5, 0);             // 3x^3 + 2x^2 - 5

        Polynomial d = p.derivative(); // 9x^2 + 4x
        check("derivative: correct x^2 coefficient", nearly(d.getCoefficient(2), 9));
        check("derivative: correct x coefficient", nearly(d.getCoefficient(1), 4));
        check("derivative: constant term disappears", d.getTermCount() == 2);
        check("derivative leaves the original unchanged",
              p.getTermCount() == 3 && nearly(p.getCoefficient(0), -5));
        cout << "  P(x)  = " << p << endl;
        cout << "  P'(x) = " << d << "   (expected 9x^2 + 4x)" << endl;

        Polynomial constant;
        constant.addTerm(42, 0);
        Polynomial cd = constant.derivative();
        check("derivative of a constant is the zero polynomial",
              cd.getTermCount() == 0);

        Polynomial second = d.derivative();  // 18x + 4
        check("second derivative works", nearly(second.getCoefficient(1), 18) &&
                                         nearly(second.getCoefficient(0), 4));
    }

    // ------------------------------------------------------------------
    section("9. Arithmetic operators");
    // ------------------------------------------------------------------
    {
        Polynomial a;
        a.addTerm(3, 2);
        a.addTerm(1, 0);              // 3x^2 + 1

        Polynomial b;
        b.addTerm(2, 2);
        b.addTerm(4, 1);              // 2x^2 + 4x

        Polynomial sum = a + b;       // 5x^2 + 4x + 1
        check("operator+ combines like terms", nearly(sum.getCoefficient(2), 5));
        check("operator+ carries unmatched terms across",
              nearly(sum.getCoefficient(1), 4) && nearly(sum.getCoefficient(0), 1));
        check("operator+ leaves the operands unchanged",
              a.getTermCount() == 2 && b.getTermCount() == 2);
        cout << "  a + b = " << sum << "   (expected 5x^2 + 4x + 1)" << endl;

        Polynomial diff = a - b;      // x^2 - 4x + 1
        check("operator- subtracts like terms", nearly(diff.getCoefficient(2), 1));
        check("operator- negates unmatched terms",
              nearly(diff.getCoefficient(1), -4));
        cout << "  a - b = " << diff << "   (expected x^2 - 4x + 1)" << endl;

        Polynomial selfDiff = a - a;
        check("subtracting a polynomial from itself gives zero",
              selfDiff.getTermCount() == 0);

        // (x + 2)(x + 3) = x^2 + 5x + 6
        Polynomial f, g;
        f.addTerm(1, 1); f.addTerm(2, 0);
        g.addTerm(1, 1); g.addTerm(3, 0);
        Polynomial product = f * g;
        check("operator*: correct x^2 term", nearly(product.getCoefficient(2), 1));
        check("operator*: middle terms combined",
              nearly(product.getCoefficient(1), 5));
        check("operator*: correct constant", nearly(product.getCoefficient(0), 6));
        check("operator*: no duplicate exponents", product.getTermCount() == 3);
        cout << "  (x + 2)(x + 3) = " << product
             << "   (expected x^2 + 5x + 6)" << endl;

        // (x + 1)(x - 1) = x^2 - 1  -- the x terms must cancel
        Polynomial h, k;
        h.addTerm(1, 1); h.addTerm(1, 0);
        k.addTerm(1, 1); k.addTerm(-1, 0);
        Polynomial hk = h * k;
        check("operator*: cancelling terms are dropped", hk.getTermCount() == 2);
        check("operator*: (x+1)(x-1) == x^2 - 1",
              nearly(hk.getCoefficient(2), 1) && nearly(hk.getCoefficient(0), -1));

        Polynomial zero;
        Polynomial timesZero = a * zero;
        check("multiplying by the zero polynomial gives zero",
              timesZero.getTermCount() == 0);

        Polynomial scaled = a * 2.5;  // 7.5x^2 + 2.5
        check("scalar multiply scales every coefficient",
              nearly(scaled.getCoefficient(2), 7.5) &&
              nearly(scaled.getCoefficient(0), 2.5));
        check("scalar multiply leaves the operand unchanged",
              nearly(a.getCoefficient(2), 3));

        Polynomial scaledZero = a * 0.0;
        check("scaling by zero empties the polynomial",
              scaledZero.getTermCount() == 0);
    }

    // ------------------------------------------------------------------
    section("10. Comparison");
    // ------------------------------------------------------------------
    {
        Polynomial a;
        a.addTerm(3, 2);
        a.addTerm(1, 0);

        Polynomial b;                 // same terms, added in a different order
        b.addTerm(1, 0);
        b.addTerm(3, 2);

        Polynomial c;
        c.addTerm(3, 2);
        c.addTerm(2, 0);

        Polynomial d;
        d.addTerm(3, 2);

        check("equal polynomials compare equal regardless of insertion order",
              a == b);
        check("different coefficients compare unequal", !(a == c));
        check("different term counts compare unequal", !(a == d));
        check("a polynomial equals itself", a == a);

        Polynomial e1, e2;
        check("two zero polynomials are equal", e1 == e2);
    }

    // ------------------------------------------------------------------
    section("11. Output formatting");
    // ------------------------------------------------------------------
    {
        Polynomial p;
        p.addTerm(5, 3);
        p.addTerm(2, 1);
        p.addTerm(-7, 0);
        cout << "  5x^3 + 2x - 7  ->  " << p << endl;

        Polynomial q;
        q.addTerm(1, 1);
        cout << "  x              ->  " << q << endl;

        Polynomial r;
        r.addTerm(-1, 2);
        r.addTerm(1, 0);
        cout << "  -x^2 + 1       ->  " << r << endl;

        Polynomial s;
        cout << "  zero           ->  " << s << endl;

        cout << "  (chained: " << p << " | " << q << ")" << endl;
        check("operator<< is chainable and does not crash", true);
    }

    // ------------------------------------------------------------------
    cout << "\n==================================" << endl;
    cout << "Polynomial tests passed: " << testsPassed << " / " << testsRun << endl;
    cout << "==================================" << endl;

    return (testsPassed == testsRun) ? 0 : 1;
}
