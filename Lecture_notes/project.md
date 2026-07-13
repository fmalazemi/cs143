# C++ Project: Dynamic Matrix and Polynomial Classes


## Mandatory Implementation Policy

Every constructor, destructor, operator, method, helper function, and function prototype listed in this document is **mandatory**.

Students must:

- Implement every listed function.
- Use the exact function names, parameter types, return types, and `const` qualifiers shown.
- Not remove, rename, replace, or skip any listed function.
- Ensure that every function compiles and behaves as described.
- Ensure that all functions are testable through the provided automated input and output files.

A missing or incorrectly declared function may cause compilation failure or failed automated test cases.


## Objective

Design and implement two C++ classes:

1. A **Matrix** class.
2. A **Polynomial** class.

Both classes must use **dynamic memory** and support operations that return new objects of the same class.

---

# Part 1: Matrix Class

## Description

The `Matrix` class represents a two-dimensional matrix whose number of rows and columns can change during program execution.

The matrix must be stored using **dynamic memory**. Fixed-size arrays are not allowed.

The class should maintain and update:

- The number of rows.
- The number of columns.
- The dynamically allocated matrix data.

Whenever a row or column is added, the class must correctly allocate new memory, copy the existing values, initialize the new cells, release the old memory, and update the row and column counts.

## Mandatory Functionality

The `Matrix` class must support:

- A default constructor.
- A parameterized constructor.
- A copy constructor.
- A destructor.
- A copy-assignment operator.
- Matrix addition using `operator+`.
- Matrix subtraction using `operator-`.
- Matrix multiplication using `operator*`.
- Matrix comparison using `operator==`.
- Input and output operations.
- Accessing and modifying individual matrix elements.

## Element Access Using `operator[]`

The `Matrix` class must overload the subscript operator so that students can access matrix elements using two pairs of square brackets:

```cpp
matrix[row][column]
```

This syntax must support both reading and updating an element.

### Reading an Element

```cpp
int value = matrix[1][2];
```

The expression above reads the element located at row `1` and column `2`.

### Updating an Element

```cpp
matrix[1][2] = 50;
```

The expression above changes the element located at row `1` and column `2` to `50`.

### Required Operator Prototypes

A possible implementation is to return a pointer to the selected row:

```cpp
int* operator[](int row);
const int* operator[](int row) const;
```

The first overload allows an element to be modified. The second overload allows elements of a constant matrix to be read without modification.

Example:

```cpp
Matrix A(3, 4);

A[0][0] = 10;
A[2][3] = 25;

cout << A[0][0] << endl;
cout << A[2][3] << endl;
```

### Input Assumption

Students may assume that every row and column index used with `operator[]` is valid. Therefore, no bounds checking is required.

The following implementation is sufficient:

```cpp
int* operator[](int row);
const int* operator[](int row) const;
```

The testing files will not contain invalid indices.

---

## Dynamic Row and Column Operations

Students must implement functions that allow the matrix to grow dynamically.

Mandatory function prototypes:

```cpp
void addRow();
void addRow(const int values[]);
void addColumn();
void addColumn(const int values[]);
```

Students must implement these prototypes exactly as specified in this document.

### `addRow()`

This function should:

- Increase the number of rows by one.
- Preserve all existing matrix values.
- Initialize the new row with default values, such as zero.
- Update the row count.

Example:

```text
Original matrix:

1 2
3 4

After addRow():

1 2
3 4
0 0
```

### `addRow(values)`

This function should:

- Add a new row containing user-provided values.
- Require the number of values to match the current number of columns.
- Preserve all existing values.
- Update the row count.

Example:

```text
Original matrix:

1 2
3 4

New row:

5 6

Result:

1 2
3 4
5 6
```

### `addColumn()`

This function should:

- Increase the number of columns by one.
- Preserve all existing matrix values.
- Initialize the new column with default values, such as zero.
- Update the column count.

Example:

```text
Original matrix:

1 2
3 4

After addColumn():

1 2 0
3 4 0
```

### `addColumn(values)`

This function should:

- Add a new column containing user-provided values.
- Require the number of values to match the current number of rows.
- Preserve all existing values.
- Update the column count.

Example:

```text
Original matrix:

1 2
3 4

New column:

5
6

Result:

1 2 5
3 4 6
```

## Important Matrix Requirements

- The matrix size must be completely dynamic.
- The number of rows and columns must always reflect the actual matrix size.
- No memory leaks are allowed.
- No dangling pointers are allowed.
- Existing data must not be lost when rows or columns are added.
- Matrix operators must return a `Matrix` object.
- The testing files will only request operations with compatible matrix dimensions.

---

# Part 2: Polynomial Class

## Description

The `Polynomial` class represents a polynomial as a dynamic collection of terms.

Each term should contain:

- A coefficient.
- An exponent.

For example:

```text
5x^3 + 2x - 7
```

contains the terms:

```text
(5, 3)
(2, 1)
(-7, 0)
```

The polynomial must use **dynamic memory** so that terms can be added during program execution.

A fixed-size array is not allowed.

## Suggested Term Structure

Students must define the following structure:

```cpp
struct Term {
    double coefficient;
    int exponent;
};
```

The `Polynomial` class must store its terms using dynamically allocated memory.

## Mandatory Functionality

The `Polynomial` class must support:

- A default constructor.
- A copy constructor.
- A destructor.
- A copy-assignment operator.
- Adding a term.
- Polynomial addition using `operator+`.
- Polynomial subtraction using `operator-`.
- Polynomial multiplication using `operator*`.
- Polynomial equality comparison using `operator==`.
- Evaluating the polynomial for a given value of `x`.
- Input and output operations.
- Returning a `Polynomial` object from polynomial arithmetic operations.

## Adding Terms Dynamically

Suggested function prototype:

```cpp
void addTerm(double coefficient, int exponent);
```

The function must behave as follows:

### Case 1: The exponent does not already exist

A new term should be dynamically added to the polynomial.

Example:

```text
Current polynomial:

3x^2 + 5

Add:

2x^4

Result:

2x^4 + 3x^2 + 5
```

### Case 2: The exponent already exists

The new coefficient must be added to the existing coefficient.

Example:

```text
Current polynomial:

3x^2 + 5

Add:

4x^2

Result:

7x^2 + 5
```

The class must not store two separate terms with the same exponent.

### Case 3: The resulting coefficient becomes zero

If combining terms produces a coefficient of zero, the term should be removed from the polynomial.

Example:

```text
Current polynomial:

3x^2 + 5

Add:

-3x^2

Result:

5
```

## Polynomial Addition

The addition operator must return a new `Polynomial` object.

Example:

```cpp
Polynomial p3 = p1 + p2;
```

When adding two polynomials:

- Terms with matching exponents must be combined.
- Terms with different exponents must be preserved.
- The returned polynomial must not contain duplicate exponents.
- Zero-coefficient terms should not be stored.

Example:

```text
P1 = 3x^2 + 2x + 1
P2 = 4x^2 - 2x + 5

P1 + P2 = 7x^2 + 6
```

## Polynomial Multiplication

The multiplication operator must also return a new `Polynomial` object.

For every term in the first polynomial, multiply it by every term in the second polynomial.

When two generated terms have the same exponent, they must be combined automatically using `addTerm()`.

Example:

```text
P1 = x + 1
P2 = x + 2

P1 * P2 = x^2 + 3x + 2
```

## Important Polynomial Requirements

- The number of terms must be completely dynamic.
- Terms must be stored using dynamic memory.
- Duplicate exponents are not allowed.
- Adding an existing exponent must update its coefficient.
- A term whose coefficient becomes zero must be removed.
- Polynomial operations must return a `Polynomial` object.
- No memory leaks or dangling pointers are allowed.
- The polynomial must be stored in descending order of exponent.

---

# Deep Copy Requirements

Because both classes use dynamically allocated memory, a shallow copy is not sufficient. Each object must own its own independent copy of the allocated data.

A deep copy is required in the following cases.

## 1. Copy Constructor

A deep copy is required when a new object is created from an existing object.

```cpp
Matrix B = A;
Polynomial p2 = p1;
```

The new object must allocate its own memory and copy all matrix values or polynomial terms. Modifying the copied object must not affect the original object.

## 2. Copy-Assignment Operator

A deep copy is required when an existing object is assigned another object.

```cpp
Matrix B;
B = A;

Polynomial p2;
p2 = p1;
```

The assignment operator should:

- Check for self-assignment.
- Release the object's old memory.
- Allocate new memory.
- Copy the source object's data.
- Return the current object by reference.

```cpp
Matrix& operator=(const Matrix& other);
Polynomial& operator=(const Polynomial& other);
```

## 3. Returning Objects from Operators

Arithmetic operators return new objects:

```cpp
Matrix C = A + B;
Matrix D = A * B;

Polynomial p3 = p1 + p2;
Polynomial p4 = p1 * p2;
```

Each returned object must own independent dynamic memory and remain valid after the operator function finishes.

## 4. Passing Objects by Value

Passing an object by value invokes the copy constructor:

```cpp
void processMatrix(Matrix m);
void processPolynomial(Polynomial p);
```

A deep copy is required. When copying is unnecessary, prefer passing by constant reference:

```cpp
void processMatrix(const Matrix& m);
void processPolynomial(const Polynomial& p);
```

## 5. Resizing Dynamic Storage

Deep-copy-like behavior is required whenever internal storage changes.

For a matrix, adding a row or column requires:

1. Allocating a larger memory block.
2. Copying all existing values.
3. Adding the new row or column.
4. Releasing the old memory.
5. Updating the row and column counts.

For a polynomial, adding or removing a term may require:

1. Allocating a new terms array.
2. Copying existing terms.
3. Inserting, updating, or removing a term.
4. Releasing the old memory.
5. Updating the number of terms.

## 6. Storing Objects in Arrays or Containers

Copies may also occur when objects are stored in arrays, classes, or containers.

```cpp
Matrix matrices[3];
matrices[1] = matrices[0];

std::vector<Polynomial> polynomials;
polynomials.push_back(p1);
```

Each copied object must manage its own memory independently.

## Why Shallow Copy Is Incorrect

A shallow copy copies only the pointer address, causing two objects to share the same memory.

This can lead to:

- Changes in one object affecting another.
- Dangling pointers.
- Double deletion.
- Memory corruption.
- Program crashes or undefined behavior.

With deep copy, each object owns a separate memory block.

## Rule of Three

Both classes must correctly implement:

```cpp
ClassName(const ClassName& other);
ClassName& operator=(const ClassName& other);
~ClassName();
```

Incorrect deep-copy behavior may cause failed automated tests, memory errors, or incorrect results.


# Required Function Prototypes

Students must implement the following public interfaces. The internal private helper functions may be designed freely, but the prototypes below must be supported exactly so that the classes can be tested automatically.

## Required `Matrix` Class Interface

```cpp
class Matrix {
private:
    int rows;
    int columns;
    int** data;

public:
    // Constructors, destructor, and deep copying
    Matrix();
    Matrix(int rows, int columns);
    Matrix(const Matrix& other);
    Matrix& operator=(const Matrix& other);
    ~Matrix();

    // Matrix dimensions
    int getRows() const;
    int getColumns() const;

    // Element access
    int* operator[](int row);
    const int* operator[](int row) const;

    // Dynamic resizing
    void addRow();
    void addRow(const int values[]);
    void addColumn();
    void addColumn(const int values[]);

    // Matrix arithmetic and comparison
    Matrix operator+(const Matrix& other) const;
    Matrix operator-(const Matrix& other) const;
    Matrix operator*(const Matrix& other) const;
    bool operator==(const Matrix& other) const;

    // File and stream input/output
    friend std::ostream& operator<<(std::ostream& output, const Matrix& matrix);
};
```

### Matrix Prototype Notes

- `Matrix()` creates an empty matrix.
- `Matrix(int rows, int columns)` creates a matrix of the requested size and initializes all elements to zero.
- The copy constructor and copy-assignment operator must perform a deep copy.
- `operator[]` must support both reading and updating elements using `matrix[row][column]`.
- `addRow()` and `addColumn()` add a zero-initialized row or column.
- The overloaded versions receive the values of the new row or column.
- Arithmetic operators must return new independent `Matrix` objects.
- The stream operators must work with files as well as `cin` and `cout`.

## Required `Term` Structure

```cpp
struct Term {
    double coefficient;
    int exponent;
};
```

## Required `Polynomial` Class Interface

```cpp
class Polynomial {
private:
    Term* terms;
    int termCount;

public:
    // Constructor, destructor, and deep copying
    Polynomial();
    Polynomial(const Polynomial& other);
    Polynomial& operator=(const Polynomial& other);
    ~Polynomial();

    // Polynomial information
    int getTermCount() const;

    // Dynamic term management
    void addTerm(double coefficient, int exponent);

    // Polynomial arithmetic and comparison
    Polynomial operator+(const Polynomial& other) const;
    Polynomial operator-(const Polynomial& other) const;
    Polynomial operator*(const Polynomial& other) const;
    bool operator==(const Polynomial& other) const;

    // Polynomial evaluation
    double evaluate(double x) const;

    // File and stream input/output
    friend std::ostream& operator<<(std::ostream& output,
                                    const Polynomial& polynomial);
};
```

### Polynomial Prototype Notes

- `Polynomial()` creates the zero polynomial with no stored terms.
- The copy constructor and copy-assignment operator must perform a deep copy.
- `addTerm()` must add a new exponent or combine the coefficient with an existing exponent.
- If the resulting coefficient is zero, that term must be removed.
- Polynomial terms should be stored in descending order of exponent.
- Arithmetic operators must return new independent `Polynomial` objects.
- `evaluate(x)` returns the polynomial value for the supplied value of `x`.
- The stream operators must work with files as well as `cin` and `cout`.

## Header Requirement

The class declarations should be placed in header files, for example:

```text
Matrix.h
Polynomial.h
```

Their implementations may be placed in corresponding source files:

```text
Matrix.cpp
Polynomial.cpp
```

Students may add private helper functions when needed, but they must not remove or change the required public prototypes.

---

# Input Validity Assumption

Students may assume that **all input is correct and valid**. No validation or error checking is required before executing any function.

This includes the following assumptions:

- Matrix dimensions are valid.
- Matrix dimensions are compatible for addition, subtraction, and multiplication.
- Row and column indices are within range.
- Arrays passed to `addRow()` and `addColumn()` contain the correct number of values.
- Polynomial exponents and coefficients are valid.
- Every requested operation can be performed correctly.
- Input files follow the specified format.

The submitted program will not be tested with invalid input. Students should focus on dynamic memory management, deep copying, operator overloading, and producing the correct output.

---

# Testing

All submitted programs will be tested using **input and output files**.

- Each test case will provide an input file.
- The program must read all required data from the provided input file.
- The program must generate output that exactly matches the expected output file.
- Output values, spaces, line breaks, symbols, and ordering must follow the required format exactly.
- Any difference between the produced output and the expected output may cause the test case to fail.

Students should not depend on interactive prompts such as:

```text
Enter the number of rows:
Enter a coefficient:
```

unless such prompts are explicitly required in the expected output.

The program should be designed so that it can be tested automatically.

---

# General Requirements

- Use classes and encapsulation appropriately.
- Use dynamic memory correctly.
- Follow the Rule of Three by implementing:
  - Copy constructor.
  - Copy-assignment operator.
  - Destructor.
- Avoid global variables.
- Use clear function names.
- Use meaningful variable names.
- Add comments for important logic.
- Ensure that all dynamically allocated memory is released.
- The program must compile without errors or warnings.

---

All constructors, methods, operators, and helper functions listed in this document are mandatory and must be implemented exactly as specified.

# Mandatory Matrix Functionality

The following functions are mandatory in the `Matrix` class:

```cpp
bool isSquare() const;
bool isDiagonal() const;
bool isIdentity() const;
bool isSymmetric() const;

void swapRows(int row1, int row2);
void swapColumns(int col1, int col2);

void removeRow(int rowIndex);
void removeColumn(int columnIndex);

int trace() const;

Matrix operator*(int scalar) const;
Matrix transpose() const;
```

## Matrix Property Functions

### `isSquare()`

```cpp
bool isSquare() const;
```

Returns `true` when the number of rows is equal to the number of columns.

### `isDiagonal()`

```cpp
bool isDiagonal() const;
```

Returns `true` when the matrix is square and every element outside the main diagonal is zero.

### `isIdentity()`

```cpp
bool isIdentity() const;
```

Returns `true` when the matrix is square, every main-diagonal element is `1`, and every other element is `0`.

### `isSymmetric()`

```cpp
bool isSymmetric() const;
```

Returns `true` when the matrix is square and:

```text
matrix[i][j] == matrix[j][i]
```

for every valid row and column.

## Matrix Modification Functions

### `swapRows()`

```cpp
void swapRows(int row1, int row2);
```

Exchanges all elements in the two specified rows.

### `swapColumns()`

```cpp
void swapColumns(int col1, int col2);
```

Exchanges all elements in the two specified columns.

### `removeRow()`

```cpp
void removeRow(int rowIndex);
```

Removes the specified row, preserves all remaining values, reallocates the dynamic memory, and decreases the number of rows by one.

### `removeColumn()`

```cpp
void removeColumn(int columnIndex);
```

Removes the specified column, preserves all remaining values, reallocates the dynamic memory, and decreases the number of columns by one.

## Matrix Calculations

### `trace()`

```cpp
int trace() const;
```

Returns the sum of the elements on the main diagonal.

Example:

```text
1 2 3
4 5 6
7 8 9
```

The trace is:

```text
1 + 5 + 9 = 15
```

The input matrix may be assumed to be square when this function is called.

### Scalar Multiplication

```cpp
Matrix operator*(int scalar) const;
```

Returns a new matrix in which every element is multiplied by the given scalar.

Example:

```cpp
Matrix B = A * 3;
```

### `transpose()`

```cpp
Matrix transpose() const;
```

Returns a new matrix whose rows become columns and whose columns become rows.

Example:

```text
Original:

1 2 3
4 5 6

Transpose:

1 4
2 5
3 6
```

The transpose operation should be implemented using the named function `transpose()`.

> Note: The notation `A^-1` normally represents the inverse of a matrix, not its transpose. Therefore, this project uses `transpose()` to avoid mathematical ambiguity.

---

# Mandatory Polynomial Functionality

The following functions are mandatory in the `Polynomial` class:

```cpp
int degree() const;
double getCoefficient(int exponent) const;
void removeTerm(int exponent);
Polynomial derivative() const;
Polynomial operator*(double scalar) const;
void simplify();
```

## Polynomial Functions

### `degree()`

```cpp
int degree() const;
```

Returns the highest exponent currently stored in the polynomial.

Example:

```text
4x^5 + 2x^2 + 1
```

The degree is:

```text
5
```

### `getCoefficient()`

```cpp
double getCoefficient(int exponent) const;
```

Returns the coefficient of the term with the specified exponent.

If no term with that exponent exists, the function should return `0`.

Example:

```text
P(x) = 3x^4 + 2x - 7
```

Then:

```cpp
p.getCoefficient(4);  // Returns 3
p.getCoefficient(1);  // Returns 2
p.getCoefficient(3);  // Returns 0
```

### `removeTerm()`

```cpp
void removeTerm(int exponent);
```

Removes the term with the specified exponent.

The function must update the dynamically allocated terms array and decrease the number of terms.

### `derivative()`

```cpp
Polynomial derivative() const;
```

Returns a new polynomial representing the derivative of the current polynomial.

For each term:

```text
a*x^n
```

the derivative is:

```text
a*n*x^(n-1)
```

Example:

```text
P(x)  = 3x^3 + 2x^2 - 5
P'(x) = 9x^2 + 4x
```

Constant terms should not appear in the returned polynomial.

### Polynomial Scalar Multiplication

```cpp
Polynomial operator*(double scalar) const;
```

Returns a new polynomial in which every coefficient is multiplied by the given scalar.

Example:

```cpp
Polynomial result = p * 2.5;
```

### `simplify()`

```cpp
void simplify();
```

Simplifies the polynomial by:

- Combining terms with equal exponents.
- Removing terms whose coefficient is zero.
- Sorting terms in descending order of exponent.
- Ensuring that no exponent appears more than once.

The function modifies the current polynomial object.

