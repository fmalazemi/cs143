# C++ Programming Project

# Dynamic Matrix and Polynomial Classes

## 1. Project Objective

Design and implement two C++ classes:

-   `Matrix`
-   `Polynomial`

Both classes **must use dynamic memory** and correctly implement the
**Rule of Three**.

------------------------------------------------------------------------

# 2. General Requirements

## Mandatory Requirements

Every constructor, destructor, operator, and function listed in this
document is **mandatory**.

Students must:

-   Use exactly the required function prototypes.
-   Use dynamic memory (no STL containers or fixed-size arrays).
-   Implement deep copying correctly.
-   Assume all input is valid.
-   Produce output exactly matching the expected output.

------------------------------------------------------------------------

# Part I --- Matrix Class

## Overview

Implement a dynamically allocated two-dimensional matrix.

## Private Data Members

-   rows
-   columns
-   dynamically allocated 2D array

## Constructors and Destructor

### Matrix()

Creates an empty matrix.

Expected behavior:

-   rows = 0
-   columns = 0
-   data = nullptr

------------------------------------------------------------------------

### Matrix(int rows, int columns)

Creates a matrix having the requested dimensions.

Expected behavior:

-   Allocate dynamic memory.
-   Initialize every element to zero.

------------------------------------------------------------------------

### Matrix(const Matrix& other)

Copy constructor.

Expected behavior:

-   Allocate a completely new memory block.
-   Copy every element from `other`.
-   Perform a **deep copy**.

Example:

``` cpp
Matrix A(3,3);
Matrix B = A;
```

Changing `B` must NOT modify `A`.

------------------------------------------------------------------------

### Matrix& operator=(const Matrix& other)

Copy-assignment operator.

Expected behavior:

1.  Check for self assignment.
2.  Release old memory.
3.  Allocate new memory.
4.  Copy every element.
5.  Return `*this`.

------------------------------------------------------------------------

### \~Matrix()

Destructor.

Expected behavior:

-   Release every allocated row.
-   Release the row-pointer array.
-   Avoid memory leaks.

------------------------------------------------------------------------

## Required Public Interface

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

friend ostream& operator<<(ostream&,const Matrix&);

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

## Function Descriptions

Each function listed above is mandatory.

-   `operator+` : returns a new matrix equal to the sum.
-   `operator-` : returns the difference.
-   `operator*` : matrix multiplication.
-   `operator*(int)` : scalar multiplication.
-   `operator==` : compares two matrices.
-   `operator[]` : enables `A[row][column]`.
-   `addRow()` / `addColumn()` : dynamically increase size.
-   `removeRow()` / `removeColumn()` : dynamically shrink size.
-   `swapRows()` / `swapColumns()` : exchange rows or columns.
-   `transpose()` : returns the transpose.
-   `trace()` : returns the diagonal sum.
-   `isSquare()`, `isDiagonal()`, `isIdentity()`, and `isSymmetric()`
    return the corresponding matrix property.

------------------------------------------------------------------------

# Part II --- Polynomial Class

## Overview

Implement a polynomial using dynamic memory.

## Required Structure

``` cpp
struct Term
{
    double coefficient;
    int exponent;
};
```

## Constructors and Destructor

### Polynomial()

Creates an empty polynomial.

Expected behavior:

-   No terms are stored.

------------------------------------------------------------------------

### Polynomial(const Polynomial& other)

Copy constructor.

Expected behavior:

-   Allocate a new dynamic array.
-   Copy every term.
-   Perform a deep copy.

------------------------------------------------------------------------

### Polynomial& operator=(const Polynomial& other)

Expected behavior:

-   Release existing memory.
-   Allocate new memory.
-   Copy all terms.
-   Return `*this`.

------------------------------------------------------------------------

### \~Polynomial()

Releases all allocated memory.

------------------------------------------------------------------------

## Required Public Interface

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

friend ostream& operator<<(ostream&,const Polynomial&);

void addTerm(double coefficient,int exponent);
void removeTerm(int exponent);

void simplify();

int degree() const;
double getCoefficient(int exponent) const;

double evaluate(double x) const;
Polynomial derivative() const;

int getTermCount() const;
```

## Function Descriptions

-   `addTerm()` inserts a new term or combines coefficients having the
    same exponent.
-   `removeTerm()` removes one term.
-   `simplify()` combines duplicate exponents, removes zero
    coefficients, and sorts descending.
-   `degree()` returns the largest exponent.
-   `getCoefficient()` returns the coefficient for an exponent.
-   `evaluate()` computes the polynomial value.
-   `derivative()` returns the derivative.
-   Arithmetic operators always return new polynomial objects.

------------------------------------------------------------------------

# Deep Copy vs Shallow Copy

## Shallow Copy

A shallow copy copies only pointer addresses.

    Matrix A ----              ---> Same memory
    Matrix B ----/

Problems:

-   Both objects share the same memory.
-   Modifying one changes the other.
-   Both destructors delete the same memory.
-   Causes dangling pointers and double deletion.

A shallow copy **must not** be used.

------------------------------------------------------------------------

## Deep Copy

A deep copy allocates completely new memory.

    Matrix A ---> Memory Block A

    Matrix B ---> Memory Block B

Both objects become completely independent.

Deep copying is mandatory for:

-   Copy constructor
-   Copy-assignment operator
-   Returning objects
-   Dynamic resizing

The same requirements apply to both the Matrix and Polynomial classes.

------------------------------------------------------------------------

# Automated Testing

The project will be graded using automated input and output files.

Students should not print prompts such as:

    Enter the number of rows:

unless explicitly required.

Every required function will be tested individually.
