# C++ Programming Project

## Project Evaluation 

### Deadline 24-Jul-2026 11:59pm

You are required to:
 - Submit your source file (.h and .cpp) through Moodle.
 - Do a Demo. 
 
NOTE: During the demonstration, students should be able to explain their design decisions, dynamic memory management, deep-copy implementation, operator overloading, and the functionality of each required method. Students may also be asked to modify or extend parts of their code during the demonstration to verify their understanding. Failure to adequately explain the implementation may result in a reduced grade, even if the program functions correctly.




# Dynamic Matrix and Polynomial Classes

## 1. Project Objective

Design and implement two C++ classes:

1. `Matrix`
2. `Polynomial`

Both classes must use dynamic memory and must correctly implement the Rule of Three.

---

# 2. General Project Rules

- Every constructor, destructor, operator, and method listed in this document is mandatory.
- Students must use the exact required prototypes.
- Fixed-size arrays and STL containers are not allowed for storing matrix values or polynomial terms.
- Students may assume that all input is valid.
- No bounds checking or input validation is required.
- Students may add private helper functions.
- Students must not remove, rename, or modify any required public function.
- All dynamically allocated memory must be released correctly.
- The project must compile without errors.

---

# Part I — Matrix Class

## 3. Matrix Overview

The `Matrix` class represents a two-dimensional matrix whose number of rows and columns may change during program execution.

The matrix must use dynamically allocated memory.

## 4. Required Matrix Data Members

The class must maintain:

- The number of rows.
- The number of columns.
- A dynamically allocated two-dimensional array.

A possible design is:

```cpp
class Matrix
{
private:
    int rows;
    int columns;
    int** data;
};
```

---

## 5. Required Matrix Interface

```cpp
class Matrix
{
private:
    int rows;
    int columns;
    int** data;

public:
    Matrix();
    Matrix(int rows, int columns);
    Matrix(const Matrix& other);
    Matrix& operator=(const Matrix& other);
    ~Matrix();

    int getRows() const;
    int getColumns() const;

    int* operator[](int row);
    const int* operator[](int row) const;

    void addRow();
    void addRow(const int values[]);

    void addColumn();
    void addColumn(const int values[]);

    void removeRow(int rowIndex);
    void removeColumn(int columnIndex);

    void swapRows(int row1, int row2);
    void swapColumns(int column1, int column2);

    Matrix operator+(const Matrix& other) const;
    Matrix operator-(const Matrix& other) const;
    Matrix operator*(const Matrix& other) const;
    Matrix operator*(int scalar) const;

    bool operator==(const Matrix& other) const;

    bool isSquare() const;
    bool isDiagonal() const;
    bool isIdentity() const;
    bool isSymmetric() const;

    int trace() const;
    Matrix transpose() const;

    friend std::ostream& operator<<(std::ostream& output,
                                    const Matrix& matrix);
};
```

---

## 6. Matrix Constructors and Destructor

### 6.1 Default Constructor

```cpp
Matrix();
```

Creates an empty matrix.

Expected state:

```text
rows = 0
columns = 0
data = nullptr
```

### 6.2 Parameterized Constructor

```cpp
Matrix(int rows, int columns);
```

Creates a matrix with the specified dimensions.

Required behavior:

- Allocate the required dynamic memory.
- Initialize every element to zero.
- Store the row and column counts.

### 6.3 Copy Constructor

```cpp
Matrix(const Matrix& other);
```

Creates a new matrix as a deep copy of another matrix.

Required behavior:

- Allocate new memory.
- Copy every matrix value.
- Ensure that the two objects do not share the same data.

Example:

```cpp
Matrix A(2, 2);
Matrix B = A;

B[0][0] = 100;
```

Changing `B` must not change `A`.

### 6.4 Copy-Assignment Operator

```cpp
Matrix& operator=(const Matrix& other);
```

Required behavior:

1. Check for self-assignment.
2. Release the current object's old memory.
3. Copy the dimensions.
4. Allocate new memory.
5. Copy all values.
6. Return `*this`.

### 6.5 Destructor

```cpp
~Matrix();
```

Required behavior:

- Delete every dynamically allocated row.
- Delete the row-pointer array.
- Prevent memory leaks.

---

## 7. Matrix Element Access

### Non-Constant Access

```cpp
int* operator[](int row);
```

Allows reading and updating elements:

```cpp
A[1][2] = 50;
int value = A[1][2];
```

### Constant Access

```cpp
const int* operator[](int row) const;
```

Allows read-only access to constant matrix objects.

All row and column indices used during testing will be valid.

---

## 8. Matrix Dimension Functions

### `getRows()`

```cpp
int getRows() const;
```

Returns the current number of rows.

### `getColumns()`

```cpp
int getColumns() const;
```

Returns the current number of columns.

---

## 9. Dynamic Matrix Operations

Every operation in this section must preserve all unaffected matrix values and correctly update the matrix dimensions.

### 9.1 Add a Zero Row

```cpp
void addRow();
```

Before:

```text
1 2 3
4 5 6
```

After:

```text
1 2 3
4 5 6
0 0 0
```

### 9.2 Add a Row with Values

```cpp
void addRow(const int values[]);
```

Example:

```cpp
int values[] = {7, 8, 9};
A.addRow(values);
```

Before:

```text
1 2 3
4 5 6
```

After:

```text
1 2 3
4 5 6
7 8 9
```

### 9.3 Remove a Row

```cpp
void removeRow(int rowIndex);
```

Example:

```cpp
A.removeRow(1);
```

Before:

```text
1 2 3
4 5 6
7 8 9
```

After:

```text
1 2 3
7 8 9
```

### 9.4 Add a Zero Column

```cpp
void addColumn();
```

Before:

```text
1 2
3 4
```

After:

```text
1 2 0
3 4 0
```

### 9.5 Add a Column with Values

```cpp
void addColumn(const int values[]);
```

Example:

```cpp
int values[] = {5, 6};
A.addColumn(values);
```

Before:

```text
1 2
3 4
```

After:

```text
1 2 5
3 4 6
```

### 9.6 Remove a Column

```cpp
void removeColumn(int columnIndex);
```

Example:

```cpp
A.removeColumn(1);
```

Before:

```text
1 2 5
3 4 6
```

After:

```text
1 5
3 6
```

### 9.7 Swap Rows

```cpp
void swapRows(int row1, int row2);
```

Exchanges every value in the two specified rows.

### 9.8 Swap Columns

```cpp
void swapColumns(int column1, int column2);
```

Exchanges every value in the two specified columns.

---

## 10. Matrix Arithmetic Operators

### Addition

```cpp
Matrix operator+(const Matrix& other) const;
```

Returns a new matrix containing the sum.

### Subtraction

```cpp
Matrix operator-(const Matrix& other) const;
```

Returns a new matrix containing the difference.

### Matrix Multiplication

```cpp
Matrix operator*(const Matrix& other) const;
```

Returns the matrix product.

### Scalar Multiplication

```cpp
Matrix operator*(int scalar) const;
```

Returns a new matrix in which every element is multiplied by the scalar.

---

## 11. Matrix Comparison

```cpp
bool operator==(const Matrix& other) const;
```

Returns `true` only when both matrices have identical dimensions and values.

---

## 12. Matrix Property Functions

### Square Matrix

```cpp
bool isSquare() const;
```

Returns `true` when the number of rows equals the number of columns.

### Diagonal Matrix

```cpp
bool isDiagonal() const;
```

Returns `true` when the matrix is square and every non-diagonal value is zero.

### Identity Matrix

```cpp
bool isIdentity() const;
```

Returns `true` when the matrix is square, every diagonal value is `1`, and every non-diagonal value is `0`.

### Symmetric Matrix

```cpp
bool isSymmetric() const;
```

Returns `true` when:

```text
A[i][j] == A[j][i]
```

for every valid position.

---

## 13. Matrix Calculations

### Trace

```cpp
int trace() const;
```

Returns the sum of the main diagonal.

Example:

```text
1 2 3
4 5 6
7 8 9
```

Result:

```text
1 + 5 + 9 = 15
```

### Transpose

```cpp
Matrix transpose() const;
```

Returns a new transposed matrix.

Before:

```text
1 2 3
4 5 6
```

After:

```text
1 4
2 5
3 6
```

---

## 14. Matrix Output

```cpp
friend std::ostream& operator<<(std::ostream& output,
                                const Matrix& matrix);
```

Prints the matrix using the required output format.

---

# Part II — Polynomial Class

## 15. Polynomial Overview

The `Polynomial` class represents a polynomial as a dynamically allocated array of terms.

Each term stores:

- A coefficient.
- An exponent.

Example:

```text
5x^3 + 2x - 7
```

Terms:

```text
(5, 3)
(2, 1)
(-7, 0)
```

---

## 16. Required Term Structure

```cpp
struct Term
{
    double coefficient;
    int exponent;
};
```

---

## 17. Required Polynomial Interface

```cpp
class Polynomial
{
private:
    Term* terms;
    int termCount;

public:
    Polynomial();
    Polynomial(const Polynomial& other);
    Polynomial& operator=(const Polynomial& other);
    ~Polynomial();

    int getTermCount() const;

    void addTerm(double coefficient, int exponent);
    void removeTerm(int exponent);
    void simplify();

    int degree() const;
    double getCoefficient(int exponent) const;
    double evaluate(double x) const;

    Polynomial derivative() const;

    Polynomial operator+(const Polynomial& other) const;
    Polynomial operator-(const Polynomial& other) const;
    Polynomial operator*(const Polynomial& other) const;
    Polynomial operator*(double scalar) const;

    bool operator==(const Polynomial& other) const;

    friend std::ostream& operator<<(std::ostream& output,
                                    const Polynomial& polynomial);
};
```

---

## 18. Polynomial Constructors and Destructor

### 18.1 Default Constructor

```cpp
Polynomial();
```

Creates the zero polynomial.

Expected state:

```text
terms = nullptr
termCount = 0
```

### 18.2 Copy Constructor

```cpp
Polynomial(const Polynomial& other);
```

Required behavior:

- Allocate a new term array.
- Copy all terms.
- Ensure that the copied object does not share memory with the original.

### 18.3 Copy-Assignment Operator

```cpp
Polynomial& operator=(const Polynomial& other);
```

Required behavior:

1. Check for self-assignment.
2. Release old memory.
3. Allocate a new term array.
4. Copy all terms.
5. Update the term count.
6. Return `*this`.

### 18.4 Destructor

```cpp
~Polynomial();
```

Releases the dynamically allocated term array.

---

## 19. Polynomial Term Management

### 19.1 Add a New Term

```cpp
void addTerm(double coefficient, int exponent);
```

Example:

```cpp
Polynomial p;

p.addTerm(3, 2);
p.addTerm(5, 0);
```

Result:

```text
3x^2 + 5
```

### 19.2 Add to an Existing Exponent

Before:

```text
3x^2 + 5
```

Operation:

```cpp
p.addTerm(4, 2);
```

After:

```text
7x^2 + 5
```

The class must not store duplicate exponents.

### 19.3 Remove a Term Automatically

Before:

```text
7x^2 + 5
```

Operation:

```cpp
p.addTerm(-7, 2);
```

After:

```text
5
```

A term whose coefficient becomes zero must be removed.

### 19.4 Remove a Term Explicitly

```cpp
void removeTerm(int exponent);
```

Before:

```text
4x^3 + 2x - 6
```

Operation:

```cpp
p.removeTerm(1);
```

After:

```text
4x^3 - 6
```

The terms array and term count must be updated.

### 19.5 Simplify

```cpp
void simplify();
```

Required behavior:

- Combine duplicate exponents.
- Remove zero-coefficient terms.
- Sort terms in descending order of exponent.
- Ensure that every exponent appears only once.

---

## 20. Polynomial Information Functions

### Term Count

```cpp
int getTermCount() const;
```

Returns the number of currently stored terms.

### Degree

```cpp
int degree() const;
```

Returns the highest exponent.

### Coefficient Lookup

```cpp
double getCoefficient(int exponent) const;
```

Returns the coefficient associated with the requested exponent.

Returns `0` when the exponent does not exist.

### Evaluation

```cpp
double evaluate(double x) const;
```

Returns the polynomial value at `x`.

---

## 21. Polynomial Calculus

### Derivative

```cpp
Polynomial derivative() const;
```

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

---

## 22. Polynomial Arithmetic Operators

### Addition

```cpp
Polynomial operator+(const Polynomial& other) const;
```

Returns a new polynomial containing the sum.

### Subtraction

```cpp
Polynomial operator-(const Polynomial& other) const;
```

Returns a new polynomial containing the difference.

### Polynomial Multiplication

```cpp
Polynomial operator*(const Polynomial& other) const;
```

Returns a new polynomial containing the product.

Terms with equal exponents must be combined.

### Scalar Multiplication

```cpp
Polynomial operator*(double scalar) const;
```

Returns a new polynomial in which every coefficient is multiplied by the scalar.

---

## 23. Polynomial Comparison

```cpp
bool operator==(const Polynomial& other) const;
```

Returns `true` when both polynomials contain equivalent terms.

---

## 24. Polynomial Output

```cpp
friend std::ostream& operator<<(std::ostream& output,
                                const Polynomial& polynomial);
```

Prints the polynomial using the required output format.

---

# Part III — Deep Copy and Shallow Copy

## 25. Shallow Copy

A shallow copy copies only pointer addresses.

```text
Object A ----\
              ---> Same memory
Object B ----/
```

Problems caused by shallow copying:

- Modifying one object may modify the other.
- One object may hold a dangling pointer.
- Both destructors may delete the same memory.
- The program may crash.
- Undefined behavior may occur.

Shallow copying is not acceptable in this project.

---

## 26. Deep Copy

A deep copy creates independent memory.

```text
Object A ---> Memory block A
Object B ---> Memory block B
```

After copying, modifying one object must not affect the other.

Deep copying is required for:

- Matrix copy constructor.
- Matrix copy-assignment operator.
- Polynomial copy constructor.
- Polynomial copy-assignment operator.
- Returning objects from arithmetic operators.
- Adding or removing matrix rows and columns.
- Adding or removing polynomial terms.
