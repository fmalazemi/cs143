# CS143 — Lecture 5: Nested `if` and Nested Loops

**Course:** CS143 — Introduction to C++
**Instructor:** Dr. Fawaz Alazemi
**Audience:** Students who completed CS101 (Python)

---

## Table of Contents

1. [Introduction](#introduction)
2. [Part A — Nested `if`](#part-a--nested-if)
   - [What Is a Nested `if`?](#what-is-a-nested-if)
   - [Syntax](#nested-if-syntax)
   - [Nested `if` vs. else-if Chain](#nested-if-vs-else-if-chain)
   - [Worked Examples (Nested `if`)](#worked-examples-nested-if)
3. [Part B — Nested Loops](#part-b--nested-loops)
   - [What Is a Nested Loop?](#what-is-a-nested-loop)
   - [Syntax and Trace](#nested-loop-syntax-and-trace)
   - [Worked Examples (Nested Loops)](#worked-examples-nested-loops)
4. [Comparison With Python](#comparison-with-python)
5. [Common Mistakes](#common-mistakes)
6. [Practice Exercises](#practice-exercises)
7. [Summary](#summary)

---

## Introduction

**Nesting** means placing one control structure inside another: an `if` inside an `if`, or a loop inside a loop. The inner structure is part of the body of the outer one, so it only runs when the outer structure allows it.

You have already used nesting in CS101. The idea is exactly the same in C++ — only the punctuation changes. In Python you mark levels with **indentation**; in C++ you mark them with **braces** `{ }`.

### Why nesting matters

- It lets you ask a **follow-up question** only after a first question is true.
- It is the standard tool for working with **grids and tables** (rows and columns).
- It lets you draw **patterns and shapes** such as triangles and squares.
- It models real decisions that have **more than one stage**.

### Real-world analogies

- **Airport gate:** First check *"Do you have a boarding pass?"* Only if yes do you then check *"Is it the correct flight?"* The second check is nested inside the first.
- **Spreadsheet:** To fill a table, you go through each **row**, and for each row you fill every **column**. The column work is nested inside the row work.
- **Class register:** For each **student** (outer), you read every **subject grade** (inner).

### When to use it

Use a **nested `if`** when a second decision only makes sense after the first decision is true. Use a **nested loop** whenever your data or output has two dimensions, such as rows and columns.

---

## Part A — Nested `if`

### What Is a Nested `if`?

A nested `if` is an `if` statement placed **inside the body** of another `if`. The inner test is only reached when the outer test is true.

> **Question form:** "Are you old enough to drive? *If yes*, do you also have a license?"
> The license question is never asked unless the age question is already true.

### Nested `if` Syntax

```cpp
#include <iostream>
using namespace std;

int main() {
    int age, license;          // license: 1 = yes, 0 = no
    cin >> age >> license;

    if (age >= 18) {           // outer test
        if (license == 1) {    // inner test (only if outer is true)
            cout << "You can drive" << endl;
        } else {
            cout << "Get license" << endl;
        }
    } else {
        cout << "Too young" << endl;
    }
    return 0;
}
```

**Output (age = 20, license = 1):**
```
You can drive
```

**Output (age = 20, license = 0):**
```
Get license
```

**Output (age = 15, license = 1):**
```
Too young
```

Each opening brace `{` must have a matching closing brace `}`. Indentation does not control the program in C++, but it helps **you** see the levels clearly.

### Nested `if` vs. else-if Chain

These two structures look similar but solve different problems.

| Use a **nested `if`** when… | Use an **else-if chain** when… |
| --- | --- |
| The second test only makes sense after the first is true | You pick exactly **one** option from a list |
| The tests check **different** things (age, then license) | The tests check the **same** value (a mark → A/B/C) |

If you find yourself nesting more than two or three levels deep, the code becomes hard to read. Often you can flatten it by combining tests with `&&`:

**Deeply nested:**
```cpp
if (age >= 18) {
    if (license == 1) {
        cout << "Drive";
    }
}
```

**Flatter and clearer:**
```cpp
if (age >= 18 && license == 1) {
    cout << "Drive";
}
```

### Worked Examples (Nested `if`)

#### Example 1 — Pass, and Maybe Distinction

```cpp
#include <iostream>
using namespace std;

int main() {
    int mark;
    cin >> mark;

    if (mark >= 50) {              // first: did the student pass?
        cout << "Pass" << endl;
        if (mark >= 85) {          // only checked if they passed
            cout << "With distinction!" << endl;
        }
    } else {
        cout << "Fail" << endl;
    }
    return 0;
}
```

**Output (mark = 90):**
```
Pass
With distinction!
```

**Output (mark = 60):**
```
Pass
```

**Output (mark = 40):**
```
Fail
```

The distinction test is only reached for students who already passed.

#### Example 2 — Ticket Price by Age and Membership

```cpp
#include <iostream>
using namespace std;

int main() {
    int age, member;          // member: 1 = yes, 0 = no
    cin >> age >> member;

    if (age < 13) {
        cout << "Child: free" << endl;
    } else {
        if (member == 1) {    // nested: only for non-children
            cout << "Member: 5 KD" << endl;
        } else {
            cout << "Adult: 10 KD" << endl;
        }
    }
    return 0;
}
```

**Output (age = 10, member = 0):**
```
Child: free
```

**Output (age = 30, member = 1):**
```
Member: 5 KD
```

**Output (age = 30, member = 0):**
```
Adult: 10 KD
```

Membership only matters once we know the person is not a child.

#### Example 3 — Sign and Parity

```cpp
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n > 0) {                 // first: is it positive?
        if (n % 2 == 0) {        // nested: is it even?
            cout << "Positive and even" << endl;
        } else {
            cout << "Positive and odd" << endl;
        }
    } else {
        cout << "Not positive" << endl;
    }
    return 0;
}
```

**Output (n = 6):**
```
Positive and even
```

**Output (n = 9):**
```
Positive and odd
```

The parity test only runs when the number is positive.

---

## Part B — Nested Loops

### What Is a Nested Loop?

A nested loop is a loop placed inside another loop. The **inner** loop runs all the way through for **each single pass** of the **outer** loop.

If the outer loop runs 3 times and the inner loop runs 4 times, the inner body runs **3 × 4 = 12** times in total.

> **Mental model:** outer loop = **rows**, inner loop = **columns**.

### Nested Loop Syntax and Trace

```cpp
#include <iostream>
using namespace std;

int main() {
    // outer uses i, inner uses j (different names!)
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            cout << i << j << " ";
        }
        cout << endl;   // new line after each row
    }
    return 0;
}
```

**Output:**
```
11 12 13
21 22 23
31 32 33
```

**Trace:**

| i | j values | prints |
| --- | --- | --- |
| 1 | 1, 2, 3 | 11 12 13 |
| 2 | 1, 2, 3 | 21 22 23 |
| 3 | 1, 2, 3 | 31 32 33 |

For each value of `i`, the inner loop counts `j` from 1 to 3 completely. The `endl` after the inner loop ends each row.

### Worked Examples (Nested Loops)

#### Example 4 — A Rectangle of Stars

```cpp
#include <iostream>
using namespace std;

int main() {
    int rows = 3, cols = 5;
    for (int r = 1; r <= rows; r++) {       // each row
        for (int c = 1; c <= cols; c++) {   // each column
            cout << "*";
        }
        cout << endl;                       // move to next line
    }
    return 0;
}
```

**Output:**
```
*****
*****
*****
```

The `endl` belongs to the **outer** loop, not the inner one. Placing it inside the inner loop would break the line after every single star.

#### Example 5 — A Multiplication Grid

```cpp
#include <iostream>
using namespace std;

int main() {
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            cout << i * j << "\t";   // \t = a tab gap
        }
        cout << endl;
    }
    return 0;
}
```

**Output:**
```
1   2   3   4
2   4   6   8
3   6   9   12
4   8   12  16
```

Each cell is `i * j`. The tab character `\t` lines the numbers up into neat columns.

#### Example 6 — A Right Triangle (Inner Depends on Outer)

```cpp
#include <iostream>
using namespace std;

int main() {
    int n = 5;
    for (int i = 1; i <= n; i++) {
        // the inner limit depends on the OUTER counter i
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}
```

**Output:**
```
*
**
***
****
*****
```

The key idea is that the inner condition is `j <= i`. Row 1 prints 1 star, row 2 prints 2 stars, and so on. The inner loop is allowed to **depend on** the outer counter.

---

## Comparison With Python

The structure is identical in both languages. Python marks the level with indentation; C++ marks it with braces.

**Python:**
```python
for i in range(1, 4):
    for j in range(1, 4):
        print(i * j, end=" ")
    print()
```

**C++:**
```cpp
for (int i = 1; i < 4; i++) {
    for (int j = 1; j < 4; j++) {
        cout << i * j << " ";
    }
    cout << endl;
}
```

| Idea | Python | C++ |
| --- | --- | --- |
| Mark a level | indentation | braces `{ }` |
| Start of inner block | `:` then indent | `{` |
| End of inner block | dedent | `}` |
| `and` / `or` / `not` | `and` / `or` / `not` | `&&` / `\|\|` / `!` |
| End each statement | nothing | `;` |

---

## Common Mistakes

**1. Using the same counter name for both loops**

**Wrong:**
```cpp
for (int i = 1; i <= 3; i++) {
    for (int i = 1; i <= 3; i++) {   // reuses i
        cout << i;
    }
}
```

**Correct:**
```cpp
for (int i = 1; i <= 3; i++) {
    for (int j = 1; j <= 3; j++) {   // different name
        cout << j;
    }
}
```

**Explanation:** Reusing the same name for the inner loop hides the outer counter and makes the logic confusing. Always use different names, such as `i` and `j`.

---

**2. Placing `endl` in the wrong place**

**Wrong:**
```cpp
for (int r = 1; r <= 3; r++) {
    for (int c = 1; c <= 5; c++) {
        cout << "*" << endl;   // breaks the line every star
    }
}
```

**Correct:**
```cpp
for (int r = 1; r <= 3; r++) {
    for (int c = 1; c <= 5; c++) {
        cout << "*";
    }
    cout << endl;             // one line break per row
}
```

**Explanation:** A new line should usually end a full **row**, so the `endl` belongs to the outer loop, after the inner loop finishes.

---

**3. Using `=` instead of `==` in a condition**

**Wrong:**
```cpp
if (license = 1) {            // assigns 1, always true
    cout << "Can drive";
}
```

**Correct:**
```cpp
if (license == 1) {           // compares
    cout << "Can drive";
}
```

**Explanation:** A single `=` stores a value; a double `==` compares values. Using `=` by mistake makes the condition almost always true.

---

**4. Forgetting the braces**

**Wrong:**
```cpp
if (age >= 18)
    if (license == 1)
        cout << "Drive";
    else
        cout << "No license";   // which if does this else belong to?
```

**Correct:**
```cpp
if (age >= 18) {
    if (license == 1) {
        cout << "Drive";
    } else {
        cout << "No license";
    }
}
```

**Explanation:** Without braces, an `else` pairs with the nearest unmatched `if`, which is easy to get wrong. Always use braces in nested code to make the pairing clear.

---

**5. Using a fixed inner limit when it should depend on the outer counter**

**Wrong:**
```cpp
for (int i = 1; i <= 5; i++) {
    for (int j = 1; j <= 5; j++) {   // always 5 -> a square
        cout << "*";
    }
    cout << endl;
}
```

**Correct:**
```cpp
for (int i = 1; i <= 5; i++) {
    for (int j = 1; j <= i; j++) {   // depends on i -> a triangle
        cout << "*";
    }
    cout << endl;
}
```

**Explanation:** To draw a triangle, the number of stars must change each row. Linking the inner condition to the outer counter (`j <= i`) achieves this.

---

## Practice Exercises

Write a complete C++ program for each task and test it. Solutions are provided below each exercise.

**Exercise 1 (nested `if`).** Read a number. If it is positive, print `Positive`; then, if it is also even, print `and even`. If it is not positive, print `Not positive`.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n > 0) {
        cout << "Positive" << endl;
        if (n % 2 == 0) {
            cout << "and even" << endl;
        }
    } else {
        cout << "Not positive" << endl;
    }
    return 0;
}
```
</details>

**Exercise 2 (nested `if`).** Read three integers and print the largest, using nested `if` statements.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if (a >= b) {
        if (a >= c) cout << a << endl;
        else        cout << c << endl;
    } else {
        if (b >= c) cout << b << endl;
        else        cout << c << endl;
    }
    return 0;
}
```
</details>

**Exercise 3 (nested `if`).** Read a mark (0–100). Print `Pass` if it is 50 or more; inside that, print `Distinction` if it is 85 or more. Otherwise print `Fail`.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int m;
    cin >> m;
    if (m >= 50) {
        cout << "Pass" << endl;
        if (m >= 85) {
            cout << "Distinction" << endl;
        }
    } else {
        cout << "Fail" << endl;
    }
    return 0;
}
```
</details>

**Exercise 4 (nested `if`).** Read `age` and `hasTicket` (1/0). If age is 18 or more, then if `hasTicket` is 1 print `Enter`, otherwise print `Buy a ticket`. If under 18, print `Not allowed`.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int age, hasTicket;
    cin >> age >> hasTicket;
    if (age >= 18) {
        if (hasTicket == 1) {
            cout << "Enter" << endl;
        } else {
            cout << "Buy a ticket" << endl;
        }
    } else {
        cout << "Not allowed" << endl;
    }
    return 0;
}
```
</details>

**Exercise 5 (nested loop).** Print a 5 × 5 square made of the character `#`.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    for (int r = 1; r <= 5; r++) {
        for (int c = 1; c <= 5; c++) {
            cout << "#";
        }
        cout << endl;
    }
    return 0;
}
```

**Output:**
```
#####
#####
#####
#####
#####
```
</details>

**Exercise 6 (nested loop).** Read `n` and print a right triangle of stars with `n` rows.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}
```

**Output (n = 4):**
```
*
**
***
****
```
</details>

**Exercise 7 (nested loop).** Print a number triangle with 4 rows, where row `i` shows the numbers 1 up to `i`.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= i; j++) {
            cout << j;
        }
        cout << endl;
    }
    return 0;
}
```

**Output:**
```
1
12
123
1234
```
</details>

**Exercise 8 (nested loop).** Read `n` and print an inverted star triangle: the first row has `n` stars, and the last row has 1 star.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    // row i prints (n - i + 1) stars
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i + 1; j++) {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}
```

**Output (n = 4):**
```
****
***
**
*
```
</details>

---

## Summary

### Key Concepts

- A **nested `if`** places one decision inside another; the inner test runs only when the outer test is true.
- A **nested loop** runs its inner loop fully for each pass of the outer loop.
- For grids and shapes: **outer loop = rows**, **inner loop = columns**.
- The inner loop may **depend on** the outer counter (for example, `j <= i`) to create triangles.

### Important Points

1. Match every `{` with a `}`, and indent to show the levels clearly.
2. An `else` pairs with the nearest unmatched `if`; use braces to remove all doubt.
3. Use a nested `if` for follow-up questions; use an else-if chain to pick one option from a list.
4. Flatten deep nesting with `&&` when the tests can be combined.
5. Use **different** counter names for the outer and inner loops (`i` and `j`).
6. Place `endl` after the inner loop to end each row, not inside it.
7. The total number of inner passes is **outer count × inner count**; very large loops can be slow.

### Quick Reference

```cpp
// Nested if
if (outerTest) {
    if (innerTest) {
        // both true
    } else {
        // outer true, inner false
    }
} else {
    // outer false
}

// Nested loop (rows and columns)
for (int i = 1; i <= rows; i++) {
    for (int j = 1; j <= cols; j++) {
        // work for cell (i, j)
    }
    cout << endl;   // end of a row
}
```

### Next Steps

You have now covered the C++ basics, decisions (`if`, `if-else`, `if-else if`), loops (`while`, `for`), and nesting. A natural next topic is **arrays**, which let you store and loop over many values at once — a perfect partner for the loops you just learned.
