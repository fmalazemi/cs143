# C++ Project: Dynamic Matrix and Polynomial Classes

## General Requirements

-   **All functions listed in this document are mandatory.**
-   Implement the function prototypes exactly as specified.
-   Use dynamic memory (no fixed-size arrays).
-   Implement the Rule of Three for both classes.
-   Assume **all input is valid**. No error checking or input validation
    is required.
-   The project will be graded using **input/output files**. Your output
    must exactly match the expected output.

------------------------------------------------------------------------

# Part I --- Matrix Class

## Overview

Implement a `Matrix` class that stores a dynamically allocated 2D
matrix. The number of rows and columns must be completely dynamic.

## Required Data

-   Number of rows
-   Number of columns
-   Dynamically allocated matrix data

## Mandatory Constructors and Operators

``` cpp
Matrix();
Matrix(int rows, int cols);
Matrix(const Matrix& other);
~Matrix();
Matrix& operator=(const Matrix& other);

Matrix operator+(const Matrix& other) const;
Matrix operator-(const Matrix& other) const;
Matrix operator*(const Matrix& other) const;
Matrix operator*(int scalar) const;

bool operator==(const Matrix& other) const;

int* operator[](int row);
const int* operator[](int row) const;

friend ostream& operator<<(ostream&, const Matrix&);
```

## Mandatory Accessors

``` cpp
int getRows() const;
int getColumns() const;
```

## Mandatory Dynamic Operations

``` cpp
void addRow();
void addRow(const int values[]);

void addColumn();
void addColumn(const int values[]);

void removeRow(int rowIndex);
void removeColumn(int columnIndex);

void swapRows(int row1, int row2);
void swapColumns(int col1, int col2);
```

Adding/removing rows or columns must preserve existing values while
reallocating memory.

## Mandatory Matrix Algorithms

``` cpp
bool isSquare() const;
bool isDiagonal() const;
bool isIdentity() const;
bool isSymmetric() const;

int trace() const;

Matrix transpose() const;
```

### Behavior

-   `isSquare()` returns true if rows == columns.
-   `isDiagonal()` returns true if all non-diagonal elements are zero.
-   `isIdentity()` returns true if the matrix is an identity matrix.
-   `isSymmetric()` returns true if `A[i][j] == A[j][i]`.
-   `trace()` returns the sum of the main diagonal.
-   `transpose()` returns a new transposed matrix.

## Deep Copy Requirements

A deep copy is mandatory for:

-   Copy constructor
-   Copy-assignment operator
-   Returning matrices from operators
-   Resizing after adding/removing rows or columns

------------------------------------------------------------------------

# Part II --- Polynomial Class

## Overview

Implement a `Polynomial` class using a dynamically allocated array of
terms.

## Required Structure

``` cpp
struct Term
{
    double coefficient;
    int exponent;
};
```

## Mandatory Constructors and Operators

``` cpp
Polynomial();
Polynomial(const Polynomial& other);
~Polynomial();
Polynomial& operator=(const Polynomial& other);

Polynomial operator+(const Polynomial& other) const;
Polynomial operator-(const Polynomial& other) const;
Polynomial operator*(const Polynomial& other) const;
Polynomial operator*(double scalar) const;

bool operator==(const Polynomial& other) const;

friend ostream& operator<<(ostream&, const Polynomial&);
```

## Mandatory Functions

``` cpp
void addTerm(double coefficient, int exponent);
void removeTerm(int exponent);

void simplify();

int degree() const;
double getCoefficient(int exponent) const;

double evaluate(double x) const;

Polynomial derivative() const;

int getTermCount() const;
```

## Behavior

-   `addTerm()` inserts a new term or combines coefficients if the
    exponent already exists.
-   If a coefficient becomes zero, remove that term.
-   `removeTerm()` removes the specified exponent.
-   `simplify()` combines duplicate exponents, removes zero
    coefficients, and sorts terms by descending exponent.
-   `degree()` returns the largest exponent.
-   `getCoefficient()` returns 0 if the exponent does not exist.
-   `derivative()` returns the derivative as a new polynomial.

## Deep Copy Requirements

A deep copy is mandatory for:

-   Copy constructor
-   Copy-assignment operator
-   Returning polynomials from operators
-   Resizing the dynamic terms array

------------------------------------------------------------------------

# Testing

Your project will be tested automatically.

-   All test cases use **input files** and **expected output files**.
-   Your program must produce output that exactly matches the expected
    output.
-   Do not add extra prompts or messages unless explicitly required.

Failure to implement any mandatory function may result in compilation
errors or failed automated tests.
