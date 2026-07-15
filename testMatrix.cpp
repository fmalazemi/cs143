// testMatrix.cpp
// Test driver for the templated Matrix class.
// Compile:  g++ -std=c++11 -Wall Matrix.cpp testMatrix.cpp -o testMatrix

#include <iostream>
#include "Matrix.h"

using namespace std;

static int testsRun = 0;
static int testsPassed = 0;

void check(const char* label, bool condition)
{
    testsRun++;
    if (condition) testsPassed++;
    cout << (condition ? "  [PASS] " : "  [FAIL] ") << label << endl;
}

void section(const char* title)
{
    cout << "\n===== " << title << " =====" << endl;
}

// Fills a matrix with 1, 2, 3, ... in row-major order.
template <typename T>
void fillSequential(Matrix<T>& m)
{
    T value = T(1);
    for (int i = 0; i < m.getRows(); i++)
        for (int j = 0; j < m.getColumns(); j++)
        {
            m[i][j] = value;
            value = value + T(1);
        }
}

int main()
{
    // ------------------------------------------------------------------
    section("1. Constructors and destructor");
    // ------------------------------------------------------------------
    {
        Matrix<int> empty;
        check("default constructor: 0 rows", empty.getRows() == 0);
        check("default constructor: 0 columns", empty.getColumns() == 0);

        Matrix<int> A(2, 3);
        check("parameterized constructor: rows == 2", A.getRows() == 2);
        check("parameterized constructor: columns == 3", A.getColumns() == 3);

        bool allZero = true;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 3; j++)
                if (A[i][j] != 0) allZero = false;
        check("parameterized constructor: all elements zero", allZero);
    }

    // ------------------------------------------------------------------
    section("2. Deep copy (copy constructor)");
    // ------------------------------------------------------------------
    {
        Matrix<int> A(2, 2);
        fillSequential(A);            // 1 2 / 3 4

        Matrix<int> B = A;            // copy constructor
        check("copy has same values", B[0][0] == 1 && B[1][1] == 4);

        B[0][0] = 100;
        check("modifying copy does not affect original", A[0][0] == 1);
        check("copy actually changed", B[0][0] == 100);

        A[1][1] = -5;
        check("modifying original does not affect copy", B[1][1] == 4);
    }

    // ------------------------------------------------------------------
    section("3. Deep copy (copy assignment)");
    // ------------------------------------------------------------------
    {
        Matrix<int> A(2, 2);
        fillSequential(A);            // 1 2 / 3 4

        Matrix<int> C(5, 5);          // different size on purpose
        C = A;                        // must release old memory and resize
        check("assignment copies dimensions", C.getRows() == 2 && C.getColumns() == 2);
        check("assignment copies values", C[1][0] == 3);

        C[1][0] = 999;
        check("assignment is a deep copy", A[1][0] == 3);

        A = A;                        // self-assignment must not corrupt or crash
        check("self-assignment leaves object intact",
              A.getRows() == 2 && A.getColumns() == 2 && A[1][1] == 4);

        Matrix<int> D, E;
        D = E;                        // assigning an empty matrix
        check("assigning empty matrix is safe", D.getRows() == 0);
    }

    // ------------------------------------------------------------------
    section("4. Element access");
    // ------------------------------------------------------------------
    {
        Matrix<int> A(2, 3);
        A[1][2] = 50;
        check("write then read via operator[]", A[1][2] == 50);

        const Matrix<int> constA = A;
        check("const operator[] reads correctly", constA[1][2] == 50);
    }

    // ------------------------------------------------------------------
    section("5. addRow / addColumn");
    // ------------------------------------------------------------------
    {
        Matrix<int> A(2, 3);
        fillSequential(A);            // 1 2 3 / 4 5 6

        A.addRow();                   // append a zero row
        check("addRow(): row count is 3", A.getRows() == 3);
        check("addRow(): new row is zero", A[2][0] == 0 && A[2][1] == 0 && A[2][2] == 0);
        check("addRow(): old values preserved", A[0][0] == 1 && A[1][2] == 6);

        A.removeRow(2);
        int rowValues[] = {7, 8, 9};
        A.addRow(rowValues);
        check("addRow(values): row count is 3", A.getRows() == 3);
        check("addRow(values): values stored",
              A[2][0] == 7 && A[2][1] == 8 && A[2][2] == 9);
        cout << "  Matrix after addRow({7,8,9}):" << endl << A;

        Matrix<int> B(2, 2);
        fillSequential(B);            // 1 2 / 3 4

        B.addColumn();
        check("addColumn(): column count is 3", B.getColumns() == 3);
        check("addColumn(): new column is zero", B[0][2] == 0 && B[1][2] == 0);
        check("addColumn(): old values preserved", B[0][1] == 2 && B[1][0] == 3);

        B.removeColumn(2);
        int colValues[] = {5, 6};
        B.addColumn(colValues);
        check("addColumn(values): values stored", B[0][2] == 5 && B[1][2] == 6);
        cout << "  Matrix after addColumn({5,6}):" << endl << B;
    }

    // ------------------------------------------------------------------
    section("6. removeRow / removeColumn");
    // ------------------------------------------------------------------
    {
        Matrix<int> A(3, 3);
        fillSequential(A);            // 1 2 3 / 4 5 6 / 7 8 9

        A.removeRow(1);               // drop the middle row
        check("removeRow: row count is 2", A.getRows() == 2);
        check("removeRow: correct row removed",
              A[0][0] == 1 && A[1][0] == 7 && A[1][2] == 9);
        cout << "  After removeRow(1):" << endl << A;

        A.removeColumn(1);            // drop the middle column
        check("removeColumn: column count is 2", A.getColumns() == 2);
        check("removeColumn: correct column removed",
              A[0][0] == 1 && A[0][1] == 3 && A[1][0] == 7 && A[1][1] == 9);
        cout << "  After removeColumn(1):" << endl << A;

        Matrix<int> B(1, 1);
        B.removeRow(0);
        check("removing the last row empties the matrix", B.getRows() == 0);
    }

    // ------------------------------------------------------------------
    section("7. swapRows / swapColumns");
    // ------------------------------------------------------------------
    {
        Matrix<int> A(3, 3);
        fillSequential(A);            // 1 2 3 / 4 5 6 / 7 8 9

        A.swapRows(0, 2);
        check("swapRows exchanges rows",
              A[0][0] == 7 && A[0][2] == 9 && A[2][0] == 1 && A[2][2] == 3);
        check("swapRows leaves other rows alone", A[1][1] == 5);

        A.swapRows(1, 1);             // swapping a row with itself
        check("swapping a row with itself is harmless", A[1][1] == 5);

        Matrix<int> B(2, 3);
        fillSequential(B);            // 1 2 3 / 4 5 6
        B.swapColumns(0, 2);
        check("swapColumns exchanges columns",
              B[0][0] == 3 && B[0][2] == 1 && B[1][0] == 6 && B[1][2] == 4);
    }

    // ------------------------------------------------------------------
    section("8. Arithmetic operators");
    // ------------------------------------------------------------------
    {
        Matrix<int> A(2, 2);
        fillSequential(A);            // 1 2 / 3 4
        Matrix<int> B(2, 2);
        B[0][0] = 5; B[0][1] = 6; B[1][0] = 7; B[1][1] = 8;

        Matrix<int> sum = A + B;      // 6 8 / 10 12
        check("operator+ adds elementwise",
              sum[0][0] == 6 && sum[0][1] == 8 && sum[1][0] == 10 && sum[1][1] == 12);
        check("operator+ leaves operands unchanged", A[0][0] == 1 && B[0][0] == 5);

        Matrix<int> diff = B - A;     // 4 4 / 4 4
        check("operator- subtracts elementwise",
              diff[0][0] == 4 && diff[1][1] == 4);

        Matrix<int> product = A * B;  // [1 2; 3 4] * [5 6; 7 8] = [19 22; 43 50]
        check("operator* (matrix) multiplies correctly",
              product[0][0] == 19 && product[0][1] == 22 &&
              product[1][0] == 43 && product[1][1] == 50);
        cout << "  A * B:" << endl << product;

        // Non-square product: (2x3) * (3x2) -> (2x2)
        Matrix<int> M(2, 3);
        fillSequential(M);            // 1 2 3 / 4 5 6
        Matrix<int> N(3, 2);
        fillSequential(N);            // 1 2 / 3 4 / 5 6
        Matrix<int> MN = M * N;       // [22 28; 49 64]
        check("operator* handles non-square dimensions",
              MN.getRows() == 2 && MN.getColumns() == 2 &&
              MN[0][0] == 22 && MN[0][1] == 28 &&
              MN[1][0] == 49 && MN[1][1] == 64);

        Matrix<int> scaled = A * 3;   // 3 6 / 9 12
        check("operator* (scalar) scales every element",
              scaled[0][0] == 3 && scaled[1][1] == 12);
        check("scalar multiply leaves operand unchanged", A[1][1] == 4);
    }

    // ------------------------------------------------------------------
    section("9. Comparison");
    // ------------------------------------------------------------------
    {
        Matrix<int> A(2, 2);
        fillSequential(A);
        Matrix<int> B(2, 2);
        fillSequential(B);
        Matrix<int> C(2, 3);
        Matrix<int> D(2, 2);
        fillSequential(D);
        D[1][1] = 0;

        check("equal matrices compare equal", A == B);
        check("different dimensions compare unequal", !(A == C));
        check("different values compare unequal", !(A == D));
        check("a matrix equals itself", A == A);
    }

    // ------------------------------------------------------------------
    section("10. Property functions");
    // ------------------------------------------------------------------
    {
        Matrix<int> square(3, 3);
        Matrix<int> rect(2, 3);
        check("isSquare: true for 3x3", square.isSquare());
        check("isSquare: false for 2x3", !rect.isSquare());

        Matrix<int> diagonal(3, 3);
        diagonal[0][0] = 4; diagonal[1][1] = 7; diagonal[2][2] = -1;
        check("isDiagonal: true for a diagonal matrix", diagonal.isDiagonal());
        check("isIdentity: false for a non-unit diagonal", !diagonal.isIdentity());

        diagonal[0][2] = 9;
        check("isDiagonal: false with an off-diagonal value", !diagonal.isDiagonal());

        Matrix<int> identity(3, 3);
        identity[0][0] = 1; identity[1][1] = 1; identity[2][2] = 1;
        check("isIdentity: true for I3", identity.isIdentity());
        check("isDiagonal: identity is also diagonal", identity.isDiagonal());
        check("isSymmetric: identity is symmetric", identity.isSymmetric());

        Matrix<int> symmetric(3, 3);
        symmetric[0][0] = 1; symmetric[0][1] = 2; symmetric[0][2] = 3;
        symmetric[1][0] = 2; symmetric[1][1] = 4; symmetric[1][2] = 5;
        symmetric[2][0] = 3; symmetric[2][1] = 5; symmetric[2][2] = 6;
        check("isSymmetric: true for a symmetric matrix", symmetric.isSymmetric());

        symmetric[0][1] = 99;
        check("isSymmetric: false once broken", !symmetric.isSymmetric());
        check("isSymmetric: false for a non-square matrix", !rect.isSymmetric());
    }

    // ------------------------------------------------------------------
    section("11. trace and transpose");
    // ------------------------------------------------------------------
    {
        Matrix<int> A(3, 3);
        fillSequential(A);            // 1 2 3 / 4 5 6 / 7 8 9
        check("trace == 1 + 5 + 9 == 15", A.trace() == 15);

        Matrix<int> B(2, 3);
        fillSequential(B);            // 1 2 3 / 4 5 6
        Matrix<int> Bt = B.transpose();
        check("transpose: dimensions flipped",
              Bt.getRows() == 3 && Bt.getColumns() == 2);
        check("transpose: values relocated",
              Bt[0][0] == 1 && Bt[0][1] == 4 &&
              Bt[1][0] == 2 && Bt[1][1] == 5 &&
              Bt[2][0] == 3 && Bt[2][1] == 6);
        check("transpose leaves the original unchanged",
              B.getRows() == 2 && B[0][1] == 2);
        cout << "  B:" << endl << B;
        cout << "  B transposed:" << endl << Bt;

        Matrix<int> Btt = Bt.transpose();
        check("transposing twice returns the original", Btt == B);
    }

    // ------------------------------------------------------------------
    section("12. Other permitted element types");
    // ------------------------------------------------------------------
    {
        Matrix<double> D(2, 2);
        D[0][0] = 1.5; D[0][1] = 2.0;
        D[1][0] = 3.0; D[1][1] = 4.5;
        check("Matrix<double>: trace == 6.0", D.trace() == 6.0);
        Matrix<double> Dscaled = D * 2.0;
        check("Matrix<double>: scalar multiply", Dscaled[0][0] == 3.0);
        cout << "  Matrix<double>:" << endl << D;

        Matrix<double> Dcopy = D;
        Dcopy[0][0] = 0.0;
        check("Matrix<double>: deep copy", D[0][0] == 1.5);

        Matrix<long> L(2, 2);
        L[0][0] = 1000000L; L[1][1] = 2000000L;
        check("Matrix<long>: trace == 3000000", L.trace() == 3000000L);

        Matrix<float> F(2, 2);
        F[0][0] = 0.5f; F[1][1] = 1.5f;
        check("Matrix<float>: trace == 2.0f", F.trace() == 2.0f);

        // Uncomment either line below: each must FAIL to compile.
        // Matrix<char> badChar;
        // Matrix<std::string> badString;
    }

    // ------------------------------------------------------------------
    section("13. Chained operations and temporaries");
    // ------------------------------------------------------------------
    {
        Matrix<int> A(2, 2);
        fillSequential(A);            // 1 2 / 3 4

        Matrix<int> result = (A + A) * 2;   // 4 8 / 12 16
        check("chained operators produce the right result",
              result[0][0] == 4 && result[1][1] == 16);

        Matrix<int> t = A.transpose().transpose() + A;
        check("temporaries clean up without corrupting values",
              t[0][0] == 2 && t[1][1] == 8);

        Matrix<int> grown(1, 1);
        for (int i = 0; i < 20; i++) { grown.addRow(); grown.addColumn(); }
        check("repeated growth keeps dimensions correct",
              grown.getRows() == 21 && grown.getColumns() == 21);
        for (int i = 0; i < 20; i++) { grown.removeRow(0); grown.removeColumn(0); }
        check("repeated shrinking keeps dimensions correct",
              grown.getRows() == 1 && grown.getColumns() == 1);
    }

    // ------------------------------------------------------------------
    cout << "\n==================================" << endl;
    cout << "Matrix tests passed: " << testsPassed << " / " << testsRun << endl;
    cout << "==================================" << endl;

    return (testsPassed == testsRun) ? 0 : 1;
}
