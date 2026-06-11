# CS143 — Lecture 11: Multidimensional Arrays

> **Course:** CS143 Introduction to C++ · **Instructor:** Dr. Fawaz Alazemi
> **Audience:** Students who completed CS101 (Python). **This topic was not covered in CS101, so it is new.**
> **Builds on:** Lecture 5 (nested loops) and Lecture 6 (arrays).

---

## Table of Contents

1. [Introduction](#1-introduction)
2. [Declaring and Initializing a 2D Array](#2-declaring-and-initializing-a-2d-array)
3. [Accessing Elements](#3-accessing-elements)
4. [Looping Over a Grid](#4-looping-over-a-grid)
5. [How a 2D Array Lives in Memory](#5-how-a-2d-array-lives-in-memory)
6. [Passing a 2D Array to a Function](#6-passing-a-2d-array-to-a-function)
7. [Higher Dimensions](#7-higher-dimensions)
8. [Common Mistakes](#8-common-mistakes)
9. [Practice Exercises](#9-practice-exercises)
10. [Summary](#10-summary)

---

## 1. Introduction

A **multidimensional array** stores data in more than one direction. The most common kind is the **two-dimensional (2D) array**: a grid with **rows** and **columns**, like a table or a spreadsheet.

This idea is new — it was not part of your Python course — but it is built from two things you already know in C++:

- A **1D array** is a single row of boxes (Lecture 6).
- **Nested loops** let you move through rows and columns (Lecture 5).

Put them together and you get a 2D array, visited with nested loops.

**Why 2D arrays matter:**

- They model anything shaped like a grid: tables, game boards, images (pixels), and matrices.
- They group related rows of data under one name.
- They are the natural step from single lists to structured data.

A 2D array of 2 rows and 3 columns looks like this:

```
        col 0   col 1   col 2
row 0 [   1   ][   2   ][   3   ]
row 1 [   4   ][   5   ][   6   ]
```

Each cell has two indices: first the **row**, then the **column**. Both start at 0. The cell holding `6` is at row 1, column 2 — written `m[1][2]`.

---

## 2. Declaring and Initializing a 2D Array

Declare a 2D array by giving two sizes: the number of rows, then the number of columns.

```cpp
int grid[2][3];     // 2 rows, 3 columns (empty)
```

You can fill it at the same time using nested braces — one inner `{ }` per row.

```cpp
int m[2][3] = {
    {1, 2, 3},   // row 0
    {4, 5, 6}    // row 1
};
```

The first number is the row count and the second is the column count, so `m` has 2 × 3 = 6 cells in total. Both counts must be known when you write the code.

---

## 3. Accessing Elements

Reach any cell with `a[row][col]` — always the row first, then the column.

```cpp
#include <iostream>
using namespace std;

int main() {
    int m[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    cout << m[0][0] << endl;  // 1  (row 0, col 0)
    cout << m[1][2] << endl;  // 6  (row 1, col 2)

    m[0][2] = 99;             // change one cell
    cout << m[0][2] << endl;  // 99
    return 0;
}
```

**Output:**
```
1
6
99
```

Valid rows run from 0 to (rows − 1), and valid columns run from 0 to (cols − 1).

---

## 4. Looping Over a Grid

To visit every cell, use **nested loops**: the outer loop chooses a row, and the inner loop visits each column in that row.

```cpp
#include <iostream>
using namespace std;

int main() {
    int m[2][3] = {{1, 2, 3}, {4, 5, 6}};

    for (int r = 0; r < 2; r++) {       // each row
        for (int c = 0; c < 3; c++) {   // each column
            cout << m[r][c] << " ";
        }
        cout << endl;   // new line after each row
    }
    return 0;
}
```

**Output:**
```
1 2 3 
4 5 6 
```

The `endl` belongs to the **outer** loop, so each row prints on its own line. The same nested-loop shape is used to *read* a grid:

```cpp
int g[2][2];
for (int r = 0; r < 2; r++)
    for (int c = 0; c < 2; c++)
        cin >> g[r][c];   // fill in row order
```

Here is a complete program that totals each row and the whole grid:

```cpp
#include <iostream>
using namespace std;

int main() {
    int m[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int total = 0;

    for (int r = 0; r < 2; r++) {
        int rowSum = 0;
        for (int c = 0; c < 3; c++) {
            rowSum += m[r][c];
        }
        cout << "Row " << r << " sum: " << rowSum << endl;
        total += rowSum;
    }
    cout << "Total: " << total << endl;
    return 0;
}
```

**Output:**
```
Row 0 sum: 6
Row 1 sum: 15
Total: 21
```

---

## 5. How a 2D Array Lives in Memory

Memory is really one long line. C++ stores a 2D array **row by row** — all of row 0, then all of row 1. This is called **row-major** order.

```
        row 0                    row 1
 +----+----+----+        +----+----+----+
 |  1 |  2 |  3 |        |  4 |  5 |  6 |
 +----+----+----+        +----+----+----+
 1000 1004 1008          1012 1016 1020
[0][0][0][1][0][2]       [1][0][1][1][1][2]
```

Because the rows are laid out one after another, the computer can find any cell with simple arithmetic:

```
address of m[r][c] = base + (r * cols + c) * elementSize
```

This is also **why** a function needs to know the number of columns (see the next section): without `cols`, it cannot work out where each cell is.

---

## 6. Passing a 2D Array to a Function

When you pass a 2D array to a function, you may leave the **row** count empty, but you **must** give the **column** count.

```cpp
#include <iostream>
using namespace std;

// the column count (3) is required; rows passed as a value
void printGrid(int g[][3], int rows) {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < 3; c++)
            cout << g[r][c] << " ";
        cout << endl;
    }
}

int main() {
    int m[2][3] = {{1, 2, 3}, {4, 5, 6}};
    printGrid(m, 2);
    return 0;
}
```

**Output:**
```
1 2 3 
4 5 6 
```

The column count is required because C++ stores the array in row-major order and needs `cols` to locate each cell.

---

## 7. Higher Dimensions

You can add more dimensions. A **3D array** is like a stack of grids (layers).

```cpp
int cube[2][3][4];     // 2 layers, 3 rows, 4 columns

cube[0][1][2] = 5;     // three indices now
```

Each extra dimension adds one index and one nested loop: 2D needs two loops, 3D needs three. In practice, 2D covers most needs; use 3D only when the data is truly three-dimensional.

**Comparison with Python.** Now that you have seen 2D arrays, you may notice they resemble a Python list of lists:

```python
m = [[1, 2, 3],
     [4, 5, 6]]
print(m[1][2])   # 6
```

The access `m[row][col]` is identical. The difference: a C++ 2D array is a **fixed rectangle** of one type, while a Python list of lists can grow and can have rows of different lengths.

---

## 8. Common Mistakes

**1. Swapping the row and column**

**Wrong:**
```cpp
int m[2][3];
m[2][1] = 5;     // row 2 does not exist (rows are 0 and 1)
```

**Correct:**
```cpp
int m[2][3];
m[1][2] = 5;     // row first (0–1), then column (0–2)
```

**Explanation:** the first index is the row, the second is the column. Mixing them reads the wrong cell or goes out of range.

**2. Going out of range**

**Wrong:**
```cpp
int m[2][3];
for (int r = 0; r <= 2; r++)   // r reaches 2: out of range
    for (int c = 0; c <= 3; c++)
        m[r][c] = 0;
```

**Correct:**
```cpp
int m[2][3];
for (int r = 0; r < 2; r++)    // 0..1
    for (int c = 0; c < 3; c++) // 0..2
        m[r][c] = 0;
```

**Explanation:** use `< rows` and `< cols`, not `<=`. The last valid index is size − 1.

**3. `endl` in the wrong place**

**Wrong:**
```cpp
for (int r = 0; r < 2; r++)
    for (int c = 0; c < 3; c++) {
        cout << m[r][c] << " ";
        cout << endl;            // breaks after every cell
    }
```

**Correct:**
```cpp
for (int r = 0; r < 2; r++) {
    for (int c = 0; c < 3; c++)
        cout << m[r][c] << " ";
    cout << endl;                // one new line per row
}
```

**Explanation:** put `endl` after the inner loop so each row stays on one line.

**4. Missing the column count in a function**

**Wrong:**
```cpp
void printGrid(int g[][], int rows) { /* ... */ }   // ERROR
```

**Correct:**
```cpp
void printGrid(int g[][3], int rows) { /* ... */ }  // column count given
```

**Explanation:** the column count is required so C++ can locate each cell in row-major memory.

**5. Mismatched initializer braces**

**Wrong:**
```cpp
int m[2][3] = {1, 2, 3, 4, 5, 6, 7};   // too many values
```

**Correct:**
```cpp
int m[2][3] = {
    {1, 2, 3},
    {4, 5, 6}
};
```

**Explanation:** a 2×3 array holds exactly 6 values, grouped one row per inner `{ }`. Giving the wrong number of values is an error.

---

## 9. Practice Exercises

Try each one before opening the solution.

**Exercise 1.** Declare a 3×3 array, read 9 numbers into it, and print it as a grid.

<details>
<summary>Click to see solution</summary>

```cpp
int g[3][3];
for (int r = 0; r < 3; r++)
    for (int c = 0; c < 3; c++)
        cin >> g[r][c];

for (int r = 0; r < 3; r++) {
    for (int c = 0; c < 3; c++)
        cout << g[r][c] << " ";
    cout << endl;
}
```
</details>

**Exercise 2.** Read a 2×3 array and print the sum of all elements.

<details>
<summary>Click to see solution</summary>

```cpp
int m[2][3], sum = 0;
for (int r = 0; r < 2; r++)
    for (int c = 0; c < 3; c++) {
        cin >> m[r][c];
        sum += m[r][c];
    }
cout << "Sum = " << sum << endl;
```
</details>

**Exercise 3.** Read a 3×3 array and print the sum of each row.

<details>
<summary>Click to see solution</summary>

```cpp
int m[3][3];
for (int r = 0; r < 3; r++)
    for (int c = 0; c < 3; c++)
        cin >> m[r][c];

for (int r = 0; r < 3; r++) {
    int rowSum = 0;
    for (int c = 0; c < 3; c++)
        rowSum += m[r][c];
    cout << "Row " << r << ": " << rowSum << endl;
}
```
</details>

**Exercise 4.** Read a 3×3 array and print the largest element.

<details>
<summary>Click to see solution</summary>

```cpp
int m[3][3];
for (int r = 0; r < 3; r++)
    for (int c = 0; c < 3; c++)
        cin >> m[r][c];

int big = m[0][0];
for (int r = 0; r < 3; r++)
    for (int c = 0; c < 3; c++)
        if (m[r][c] > big) big = m[r][c];
cout << "Largest = " << big << endl;
```
</details>

**Exercise 5.** Build a 4×4 array where each cell equals `(row + 1) * (col + 1)`, and print it (a multiplication table).

<details>
<summary>Click to see solution</summary>

```cpp
int t[4][4];
for (int r = 0; r < 4; r++) {
    for (int c = 0; c < 4; c++) {
        t[r][c] = (r + 1) * (c + 1);
        cout << t[r][c] << "\t";
    }
    cout << endl;
}
```
**Output (first rows):**
```
1	2	3	4
2	4	6	8
3	6	9	12
4	8	12	16
```
</details>

**Exercise 6.** Read two 2×2 matrices and print their sum (add matching cells).

<details>
<summary>Click to see solution</summary>

```cpp
int a[2][2], b[2][2];
for (int r = 0; r < 2; r++)
    for (int c = 0; c < 2; c++) cin >> a[r][c];
for (int r = 0; r < 2; r++)
    for (int c = 0; c < 2; c++) cin >> b[r][c];

for (int r = 0; r < 2; r++) {
    for (int c = 0; c < 2; c++)
        cout << a[r][c] + b[r][c] << " ";
    cout << endl;
}
```
</details>

---

## 10. Summary

### Key Concepts

- A **2D array** is a grid of rows and columns: `int m[rows][cols]`.
- Access a cell with `m[row][col]` — row first, both starting at 0.
- **Nested loops** (outer = rows, inner = columns) fill, read, and print a grid.

### Important Points

1. The first size is the number of rows; the second is the number of columns.
2. Initialize with one inner `{ }` per row.
3. Valid indices are 0 to rows − 1 and 0 to cols − 1.
4. Put `endl` after the inner loop so each row prints on its own line.
5. In memory, a 2D array is stored **row by row** (row-major order).
6. When passing to a function, the **column count is required**: `int g[][cols]`.
7. More dimensions add one index and one nested loop each.

### Quick Reference

```cpp
int m[2][3] = {{1,2,3},{4,5,6}};   // declare + fill
int x = m[1][2];                   // read a cell (row, col) -> 6
m[0][0] = 99;                      // write a cell

for (int r = 0; r < 2; r++) {      // visit every cell
    for (int c = 0; c < 3; c++)
        cout << m[r][c] << " ";
    cout << endl;
}

void f(int g[][3], int rows);      // column count required
```

### Next Steps

Grids appear everywhere — spreadsheets, images, and game boards. A natural next step is combining 2D arrays with functions and, later, with pointers to build more flexible, dynamically sized tables.
