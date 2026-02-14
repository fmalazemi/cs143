# Lecture 9: Multidimensional Arrays in C++

## Welcome

In the previous lecture, you learned about one-dimensional arrays. Now you will learn how to work with multidimensional arrays, which allow you to organize data in tables, matrices, and more complex structures.

**Why multidimensional arrays are important:**
- Represent tables and grids of data
- Store matrices for mathematical operations
- Organize complex data structures
- Model real-world scenarios (game boards, spreadsheets, etc.)

---

## Table of Contents

1. [Introduction to Multidimensional Arrays](#introduction-to-multidimensional-arrays)
2. [Two-Dimensional Arrays](#two-dimensional-arrays)
3. [Accessing 2D Array Elements](#accessing-2d-array-elements)
4. [Looping Through 2D Arrays](#looping-through-2d-arrays)
5. [2D Array Operations](#2d-array-operations)
6. [2D Arrays and Functions](#2d-arrays-and-functions)
7. [Three-Dimensional Arrays](#three-dimensional-arrays)
8. [Common Mistakes](#common-mistakes)
9. [Practice Exercises](#practice-exercises)
10. [Summary](#summary)

---

## Introduction to Multidimensional Arrays

A **multidimensional array** is an array of arrays. The most common is a two-dimensional (2D) array.

**Real-world analogies:**
- **1D Array:** A single row of mailboxes
- **2D Array:** A grid of seats in a theater (rows and columns)
- **3D Array:** A building with multiple floors, each having rows and columns

### Visual Representation

**1D Array:**
```
[10] [20] [30] [40] [50]
```

**2D Array:**
```
[10] [20] [30] [40]
[50] [60] [70] [80]
[90] [100] [110] [120]
```

Three rows, four columns - like a table or spreadsheet.

---

## Two-Dimensional Arrays

A 2D array is essentially a table with rows and columns.

### Declaration Syntax

```cpp
dataType arrayName[rows][columns];
```

**Examples:**
```cpp
int matrix[3][4];      // 3 rows, 4 columns (12 elements total)
double grades[5][3];   // 5 students, 3 subjects
char grid[10][10];     // 10x10 grid
```

### Initialization

**Method 1: Row by row (recommended for readability)**
```cpp
int matrix[3][4] = {
    {1, 2, 3, 4},      // Row 0
    {5, 6, 7, 8},      // Row 1
    {9, 10, 11, 12}    // Row 2
};
```

**Method 2: Flat initialization**
```cpp
int matrix[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
// Elements filled row by row automatically
```

**Method 3: Partial initialization**
```cpp
int matrix[3][4] = {
    {1, 2},         // Rest of row 0 becomes 0
    {5, 6},         // Rest of row 1 becomes 0
    {9, 10}         // Rest of row 2 becomes 0
};
// Result:
// 1  2  0  0
// 5  6  0  0
// 9  10 0  0
```

**Method 4: Initialize all to zero**
```cpp
int matrix[3][4] = {0};
// All elements become 0
```

### Understanding Row and Column Indices

```cpp
int matrix[3][4] = {
    {1,  2,  3,  4},    // Row 0
    {5,  6,  7,  8},    // Row 1
    {9,  10, 11, 12}    // Row 2
};
//   Col0 Col1 Col2 Col3
```

- **First index** = Row number (0 to rows-1)
- **Second index** = Column number (0 to columns-1)

### Complete Example

```cpp
#include <iostream>
using namespace std;

int main() {
    int matrix[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    
    cout << "Element at [0][0]: " << matrix[0][0] << endl;
    cout << "Element at [1][2]: " << matrix[1][2] << endl;
    
    return 0;
}
```

**Output:**
```
Element at [0][0]: 1
Element at [1][2]: 6
```

---

## Accessing 2D Array Elements

Use two indices: `array[row][column]`

### Examples

```cpp
#include <iostream>
using namespace std;

int main() {
    int matrix[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    
    cout << matrix[0][0] << endl;   // 1  (row 0, column 0)
    cout << matrix[0][3] << endl;   // 4  (row 0, column 3)
    cout << matrix[1][2] << endl;   // 7  (row 1, column 2)
    cout << matrix[2][3] << endl;   // 12 (row 2, column 3)
    
    return 0;
}
```

### Modifying Elements

```cpp
#include <iostream>
using namespace std;

int main() {
    int matrix[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    
    cout << "Before: " << matrix[0][1] << endl;
    
    matrix[0][1] = 100;  // Change element at row 0, column 1
    
    cout << "After: " << matrix[0][1] << endl;
    
    return 0;
}
```

**Output:**
```
Before: 2
After: 100
```

### Reading Input

```cpp
#include <iostream>
using namespace std;

int main() {
    int matrix[2][3];
    
    cout << "Enter 6 numbers (2 rows, 3 columns):" << endl;
    
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "Element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
    
    cout << "\nYou entered:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
```

---

## Looping Through 2D Arrays

Use **nested loops** - outer loop for rows, inner loop for columns.

### Basic Pattern

```cpp
for (int i = 0; i < rows; i++) {        // Loop through rows
    for (int j = 0; j < columns; j++) { // Loop through columns
        // Access: matrix[i][j]
    }
}
```

### Printing a 2D Array

```cpp
#include <iostream>
using namespace std;

int main() {
    int matrix[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;  // New line after each row
    }
    
    return 0;
}
```

**Output:**
```
1 2 3 4
5 6 7 8
9 10 11 12
```

### Processing All Elements

```cpp
#include <iostream>
using namespace std;

int main() {
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    // Double each element
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrix[i][j] *= 2;
        }
    }
    
    // Print result
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
```

**Output:**
```
2 4 6
8 10 12
14 16 18
```

---

## 2D Array Operations

### Sum of All Elements

```cpp
#include <iostream>
using namespace std;

int main() {
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    int sum = 0;
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            sum += matrix[i][j];
        }
    }
    
    cout << "Sum of all elements: " << sum << endl;
    
    return 0;
}
```

**Output:**
```
Sum of all elements: 45
```

### Finding Maximum Element

```cpp
#include <iostream>
using namespace std;

int main() {
    int matrix[3][4] = {
        {12, 45, 23, 67},
        {89, 34, 56, 12},
        {78, 90, 23, 45}
    };
    
    int max = matrix[0][0];
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            if (matrix[i][j] > max) {
                max = matrix[i][j];
            }
        }
    }
    
    cout << "Maximum element: " << max << endl;
    
    return 0;
}
```

**Output:**
```
Maximum element: 90
```

### Row Sum

```cpp
#include <iostream>
using namespace std;

int main() {
    int matrix[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    
    for (int i = 0; i < 3; i++) {
        int rowSum = 0;
        for (int j = 0; j < 4; j++) {
            rowSum += matrix[i][j];
        }
        cout << "Sum of row " << i << ": " << rowSum << endl;
    }
    
    return 0;
}
```

**Output:**
```
Sum of row 0: 10
Sum of row 1: 26
Sum of row 2: 42
```

### Column Sum

```cpp
#include <iostream>
using namespace std;

int main() {
    int matrix[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    
    for (int j = 0; j < 4; j++) {
        int colSum = 0;
        for (int i = 0; i < 3; i++) {
            colSum += matrix[i][j];
        }
        cout << "Sum of column " << j << ": " << colSum << endl;
    }
    
    return 0;
}
```

**Output:**
```
Sum of column 0: 15
Sum of column 1: 18
Sum of column 2: 21
Sum of column 3: 24
```

### Transpose Matrix

Swap rows and columns.

```cpp
#include <iostream>
using namespace std;

int main() {
    int matrix[3][2] = {
        {1, 2},
        {3, 4},
        {5, 6}
    };
    
    int transpose[2][3];
    
    // Transpose
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }
    
    cout << "Original:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << "\nTranspose:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << transpose[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
```

**Output:**
```
Original:
1 2
3 4
5 6

Transpose:
1 3 5
2 4 6
```

### Matrix Addition

```cpp
#include <iostream>
using namespace std;

int main() {
    int matrix1[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    
    int matrix2[2][3] = {
        {7, 8, 9},
        {10, 11, 12}
    };
    
    int result[2][3];
    
    // Add matrices
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    
    cout << "Result:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
```

**Output:**
```
Result:
8 10 12
14 16 18
```

### Search in 2D Array

```cpp
#include <iostream>
using namespace std;

int main() {
    int matrix[3][4] = {
        {12, 45, 23, 67},
        {89, 34, 56, 12},
        {78, 90, 23, 45}
    };
    
    int target = 56;
    bool found = false;
    int row = -1, col = -1;
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            if (matrix[i][j] == target) {
                found = true;
                row = i;
                col = j;
                break;
            }
        }
        if (found) break;
    }
    
    if (found) {
        cout << target << " found at position [" << row << "][" << col << "]" << endl;
    } else {
        cout << target << " not found" << endl;
    }
    
    return 0;
}
```

**Output:**
```
56 found at position [1][2]
```

---

## 2D Arrays and Functions

### Passing 2D Arrays to Functions

When passing 2D arrays, you **must specify the number of columns**.

```cpp
void functionName(int arr[][COLUMNS], int rows)
```

**Why?** The compiler needs to know column size to calculate memory addresses.

### Example: Print 2D Array

```cpp
#include <iostream>
using namespace std;

void printMatrix(int arr[][4], int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 4; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int matrix[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    
    printMatrix(matrix, 3);
    
    return 0;
}
```

**Output:**
```
1 2 3 4
5 6 7 8
9 10 11 12
```

### Example: Sum of Matrix

```cpp
#include <iostream>
using namespace std;

int sumMatrix(int arr[][3], int rows) {
    int sum = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 3; j++) {
            sum += arr[i][j];
        }
    }
    return sum;
}

int main() {
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    int total = sumMatrix(matrix, 3);
    cout << "Sum: " << total << endl;
    
    return 0;
}
```

**Output:**
```
Sum: 45
```

### Example: Matrix Multiplication

```cpp
#include <iostream>
using namespace std;

void multiplyMatrices(int a[][3], int b[][2], int result[][2], int rows1, int cols2) {
    // a is rows1 x 3, b is 3 x cols2, result is rows1 x cols2
    
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main() {
    int a[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    
    int b[3][2] = {
        {7, 8},
        {9, 10},
        {11, 12}
    };
    
    int result[2][2];
    
    multiplyMatrices(a, b, result, 2, 2);
    
    cout << "Result:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
```

**Output:**
```
Result:
58 64
139 154
```

---

## Three-Dimensional Arrays

A 3D array is an array of 2D arrays. Think of it as multiple pages of tables.

### Declaration and Initialization

```cpp
int cube[2][3][4];  // 2 pages, 3 rows per page, 4 columns per row
```

**Initialization:**
```cpp
int cube[2][3][4] = {
    {   // Page 0
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    },
    {   // Page 1
        {13, 14, 15, 16},
        {17, 18, 19, 20},
        {21, 22, 23, 24}
    }
};
```

### Accessing 3D Array Elements

```cpp
cube[page][row][column]
```

**Example:**
```cpp
#include <iostream>
using namespace std;

int main() {
    int cube[2][3][2] = {
        {
            {1, 2},
            {3, 4},
            {5, 6}
        },
        {
            {7, 8},
            {9, 10},
            {11, 12}
        }
    };
    
    cout << cube[0][0][0] << endl;  // 1
    cout << cube[0][2][1] << endl;  // 6
    cout << cube[1][1][0] << endl;  // 9
    cout << cube[1][2][1] << endl;  // 12
    
    return 0;
}
```

### Looping Through 3D Arrays

Use **three nested loops**.

```cpp
#include <iostream>
using namespace std;

int main() {
    int cube[2][3][4] = {
        {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12}
        },
        {
            {13, 14, 15, 16},
            {17, 18, 19, 20},
            {21, 22, 23, 24}
        }
    };
    
    for (int i = 0; i < 2; i++) {          // Pages
        cout << "Page " << i << ":" << endl;
        for (int j = 0; j < 3; j++) {      // Rows
            for (int k = 0; k < 4; k++) {  // Columns
                cout << cube[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    
    return 0;
}
```

**Output:**
```
Page 0:
1 2 3 4
5 6 7 8
9 10 11 12

Page 1:
13 14 15 16
17 18 19 20
21 22 23 24
```

---

## Common Mistakes

### Mistake 1: Confusing Row and Column Order

**Wrong:**
```cpp
int matrix[3][4];
matrix[2][5] = 10;  // Column index out of bounds!
```

**Correct:**
```cpp
int matrix[3][4];  // 3 rows, 4 columns
matrix[2][3] = 10; // Valid: last element
```

### Mistake 2: Not Specifying Column Size in Functions

**Wrong:**
```cpp
void printMatrix(int arr[][], int rows, int cols) {  // Error!
    // ...
}
```

**Correct:**
```cpp
void printMatrix(int arr[][4], int rows) {
    // Column size must be specified
}
```

### Mistake 3: Incorrect Loop Bounds

**Wrong:**
```cpp
int matrix[3][4];
for (int i = 0; i <= 3; i++) {     // Goes beyond rows!
    for (int j = 0; j <= 4; j++) { // Goes beyond columns!
        cout << matrix[i][j];
    }
}
```

**Correct:**
```cpp
int matrix[3][4];
for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
        cout << matrix[i][j];
    }
}
```

### Mistake 4: Forgetting Nested Loops

**Wrong:**
```cpp
int matrix[3][4];
for (int i = 0; i < 3; i++) {
    cout << matrix[i];  // Prints address, not values!
}
```

**Correct:**
```cpp
int matrix[3][4];
for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
        cout << matrix[i][j] << " ";
    }
    cout << endl;
}
```

### Mistake 5: Matrix Dimension Mismatch in Operations

**Wrong:**
```cpp
int a[2][3], b[3][4], result[2][3];  // Wrong result size!
multiplyMatrices(a, b, result);
```

**Correct:**
```cpp
int a[2][3], b[3][4], result[2][4];  // Correct: 2x3 * 3x4 = 2x4
multiplyMatrices(a, b, result);
```

---

## Practice Exercises

### Exercise 1: Diagonal Sum

Write a program that calculates the sum of diagonal elements in a square matrix.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    int sum = 0;
    
    for (int i = 0; i < 3; i++) {
        sum += matrix[i][i];  // Main diagonal
    }
    
    cout << "Diagonal sum: " << sum << endl;
    
    return 0;
}
```

**Output:**
```
Diagonal sum: 15
```
</details>

---

### Exercise 2: Identity Matrix

Write a function that checks if a matrix is an identity matrix (1s on diagonal, 0s elsewhere).

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

bool isIdentity(int arr[][3], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == j) {
                if (arr[i][j] != 1) return false;
            } else {
                if (arr[i][j] != 0) return false;
            }
        }
    }
    return true;
}

int main() {
    int matrix1[3][3] = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };
    
    int matrix2[3][3] = {
        {1, 0, 0},
        {0, 2, 0},
        {0, 0, 1}
    };
    
    if (isIdentity(matrix1, 3)) {
        cout << "Matrix 1 is identity" << endl;
    }
    
    if (!isIdentity(matrix2, 3)) {
        cout << "Matrix 2 is not identity" << endl;
    }
    
    return 0;
}
```
</details>

---

### Exercise 3: Rotate Matrix 90 Degrees

Write a program that rotates a square matrix 90 degrees clockwise.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

void rotate90(int arr[][3], int size) {
    // Transpose
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            int temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }
    
    // Reverse each row
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size / 2; j++) {
            int temp = arr[i][j];
            arr[i][j] = arr[i][size - 1 - j];
            arr[i][size - 1 - j] = temp;
        }
    }
}

int main() {
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    cout << "Before:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    rotate90(matrix, 3);
    
    cout << "\nAfter 90° rotation:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
```

**Output:**
```
Before:
1 2 3
4 5 6
7 8 9

After 90° rotation:
7 4 1
8 5 2
9 6 3
```
</details>

---

### Exercise 4: Saddle Point

Write a program that finds a saddle point in a matrix (minimum in its row and maximum in its column).

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    bool found = false;
    
    for (int i = 0; i < 3; i++) {
        // Find minimum in row i
        int minCol = 0;
        for (int j = 1; j < 3; j++) {
            if (matrix[i][j] < matrix[i][minCol]) {
                minCol = j;
            }
        }
        
        // Check if it's maximum in its column
        bool isSaddle = true;
        for (int k = 0; k < 3; k++) {
            if (matrix[k][minCol] > matrix[i][minCol]) {
                isSaddle = false;
                break;
            }
        }
        
        if (isSaddle) {
            cout << "Saddle point: " << matrix[i][minCol] 
                 << " at [" << i << "][" << minCol << "]" << endl;
            found = true;
        }
    }
    
    if (!found) {
        cout << "No saddle point found" << endl;
    }
    
    return 0;
}
```
</details>

---

### Exercise 5: Spiral Print

Write a program that prints a matrix in spiral order.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int matrix[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    
    int top = 0, bottom = 2, left = 0, right = 3;
    
    cout << "Spiral order: ";
    
    while (top <= bottom && left <= right) {
        // Print top row
        for (int i = left; i <= right; i++) {
            cout << matrix[top][i] << " ";
        }
        top++;
        
        // Print right column
        for (int i = top; i <= bottom; i++) {
            cout << matrix[i][right] << " ";
        }
        right--;
        
        // Print bottom row
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                cout << matrix[bottom][i] << " ";
            }
            bottom--;
        }
        
        // Print left column
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                cout << matrix[i][left] << " ";
            }
            left++;
        }
    }
    
    cout << endl;
    
    return 0;
}
```

**Output:**
```
Spiral order: 1 2 3 4 8 12 11 10 9 5 6 7
```
</details>

---

### Exercise 6: Student Grade Management

Create a program to store and analyze grades for 5 students across 4 subjects.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int grades[5][4] = {
        {85, 90, 78, 92},
        {88, 76, 95, 89},
        {92, 88, 84, 90},
        {78, 82, 88, 85},
        {95, 91, 87, 93}
    };
    
    // Calculate student averages
    cout << "Student averages:" << endl;
    for (int i = 0; i < 5; i++) {
        int sum = 0;
        for (int j = 0; j < 4; j++) {
            sum += grades[i][j];
        }
        double avg = sum / 4.0;
        cout << "Student " << (i + 1) << ": " << avg << endl;
    }
    
    // Calculate subject averages
    cout << "\nSubject averages:" << endl;
    for (int j = 0; j < 4; j++) {
        int sum = 0;
        for (int i = 0; i < 5; i++) {
            sum += grades[i][j];
        }
        double avg = sum / 5.0;
        cout << "Subject " << (j + 1) << ": " << avg << endl;
    }
    
    // Overall average
    int totalSum = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            totalSum += grades[i][j];
        }
    }
    double overallAvg = totalSum / 20.0;
    cout << "\nOverall average: " << overallAvg << endl;
    
    return 0;
}
```
</details>

---

## Summary

### What We Learned Today

- **Multidimensional arrays** - Arrays of arrays
- **2D arrays** - Tables with rows and columns
- **Declaration** - `dataType array[rows][columns];`
- **Nested loops** - Process 2D arrays with two loops
- **2D array operations** - Sum, max, transpose, addition, multiplication
- **Functions** - Must specify column size when passing 2D arrays
- **3D arrays** - Three dimensions (pages, rows, columns)

---

## Key Takeaways

1. **2D arrays = tables** - Think in rows and columns
2. **Two indices** - `array[row][column]`
3. **Nested loops required** - Outer for rows, inner for columns
4. **Column size in functions** - Must be specified for 2D arrays
5. **Row-major order** - Elements stored row by row in memory
6. **3D arrays** - Add another dimension (pages/layers)
7. **Applications** - Matrices, game boards, spreadsheets, images

---

## Next Lecture Preview

In the next lecture, we will learn about:
- Character arrays and C-style strings
- String operations and functions
- The C++ string class
- String manipulation techniques

---

## Homework

**Assignment 1:** Write a program that finds the largest element in each row of a matrix and stores them in a 1D array.

**Assignment 2:** Create a function that checks if two matrices are equal (same dimensions and same elements).

**Assignment 3:** Write a program that implements a simple Tic-Tac-Toe game using a 3x3 2D array. Allow two players to make moves and check for a winner.

---

## Resources

- [cppreference.com - Arrays](https://en.cppreference.com/w/cpp/language/array)
- [learncpp.com - Multidimensional Arrays](https://www.learncpp.com/cpp-tutorial/multidimensional-arrays/)

---

**Multidimensional arrays open up many possibilities for organizing and processing complex data.**
