# C++ Project: Dynamic Matrix and Polynomial Classes

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

## Minimum Required Functionality

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
- Appropriate error checking for invalid dimensions and indices.

## Dynamic Row and Column Operations

Students must implement functions that allow the matrix to grow dynamically.

Suggested function prototypes:

```cpp
void addRow();
void addRow(const int values[]);
void addColumn();
void addColumn(const int values[]);
```

The exact prototypes may be adjusted depending on the final design.

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
- Operations with incompatible dimensions must be handled correctly.

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

Students may define a structure such as:

```cpp
struct Term {
    double coefficient;
    int exponent;
};
```

The `Polynomial` class may then store a dynamically allocated array of `Term` objects.

## Minimum Required Functionality

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
- The polynomial should preferably be stored in descending order of exponent.

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
- Validate indices, dimensions, and exponents where necessary.
- Use clear function names.
- Use meaningful variable names.
- Add comments for important logic.
- Ensure that all dynamically allocated memory is released.
- The program must compile without errors or warnings.

---

Additional requirements, exact function prototypes, input format, output format, and bonus tasks may be announced later.
