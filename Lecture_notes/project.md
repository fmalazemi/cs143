# C++ Programming Project

## Dynamic Matrix and Polynomial Classes

This specification combines the Matrix and Polynomial requirements into
a single, well-organized document.

## General Requirements

-   All listed constructors, operators, and methods are **mandatory**.
-   Use dynamic memory only.
-   Implement the Rule of Three.
-   Assume all input is valid.
-   Grading is based on automated input/output files.

------------------------------------------------------------------------

# Part I --- Matrix Class

## Mandatory Public Interface

``` cpp
Matrix();
Matrix(int rows,int cols);
Matrix(const Matrix&);
~Matrix();
Matrix& operator=(const Matrix&);

Matrix operator+(const Matrix&) const;
Matrix operator-(const Matrix&) const;
Matrix operator*(const Matrix&) const;
Matrix operator*(int scalar) const;

bool operator==(const Matrix&) const;

int* operator[](int row);
const int* operator[](int row) const;

friend ostream& operator<<(ostream&, const Matrix&);

int getRows() const;
int getColumns() const;

void addRow();
void addRow(const int values[]);
void addColumn();
void addColumn(const int values[]);
void removeRow(int rowIndex);
void removeColumn(int columnIndex);
void swapRows(int row1,int row2);
void swapColumns(int col1,int col2);

bool isSquare() const;
bool isDiagonal() const;
bool isIdentity() const;
bool isSymmetric() const;
int trace() const;
Matrix transpose() const;
```

Deep copy is mandatory for copying, assignment, returning matrices, and
resizing.

------------------------------------------------------------------------

# Part II --- Polynomial Class

``` cpp
struct Term{
 double coefficient;
 int exponent;
};
```

## Mandatory Public Interface

``` cpp
Polynomial();
Polynomial(const Polynomial&);
~Polynomial();
Polynomial& operator=(const Polynomial&);

Polynomial operator+(const Polynomial&) const;
Polynomial operator-(const Polynomial&) const;
Polynomial operator*(const Polynomial&) const;
Polynomial operator*(double scalar) const;

bool operator==(const Polynomial&) const;
friend ostream& operator<<(ostream&, const Polynomial&);

void addTerm(double coefficient,int exponent);
void removeTerm(int exponent);
void simplify();
int degree() const;
double getCoefficient(int exponent) const;
double evaluate(double x) const;
Polynomial derivative() const;
int getTermCount() const;
```

Deep copy is mandatory for copying, assignment, returning polynomials,
and resizing.

------------------------------------------------------------------------

# Testing

-   Automated grading uses input/output files.
-   Output must exactly match the expected output.
-   Every required function will be tested.
