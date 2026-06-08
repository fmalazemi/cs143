# CS143 — Lecture 2: Making Decisions in C++

**Topic:** Conditional Statements — `if`, `if-else`, `if-else-if`, and nested `if`
**Instructor:** Dr. Fawaz Alazemi
**Builds on:** Lecture 1 (`cout`, `cin`, variables, types)
**Assumed background:** CS101 with Python (you already know `if`, `if-else`, `elif`, and nesting)

---

## Table of Contents

1. [Introduction](#1-introduction)
2. [Conditions: True or False](#2-conditions-true-or-false)
   - [Comparison Operators](#21-comparison-operators)
   - [Logical Operators](#22-logical-operators)
3. [The Simple `if`](#3-the-simple-if)
4. [The `if-else`](#4-the-if-else)
5. [The `if-else if-else` Chain](#5-the-if-else-if-else-chain)
6. [Nested `if`](#6-nested-if)
7. [Python vs. C++ Comparison](#7-python-vs-c-comparison)
8. [Common Mistakes](#8-common-mistakes)
9. [Practice Exercises](#9-practice-exercises)
10. [Summary](#10-summary)

---

## 1. Introduction

A **conditional statement** lets a program make a choice. The program checks whether something is true, and only then runs a certain block of code. This is how software reacts differently to different input.

**Why this matters:**

- Almost every useful program must make decisions (login checks, grading, prices, menus).
- Conditions let one program handle many different situations.
- They are the foundation for more advanced topics such as loops and validation.
- You already use this idea daily in Python; here you learn the C++ form.

**Real-world analogies:**

- *Traffic light:* if the light is green, you go; otherwise you stop.
- *Bank machine:* if your balance is enough, the withdrawal is allowed; otherwise it is refused.
- *Exam grading:* if the mark is 60 or more, the result is "Pass"; otherwise "Fail".

**When to use it:** any time your program must choose between two or more paths based on a value.

The good news: the *idea* is identical to Python. In C++ the condition goes inside parentheses `( )`, the body goes inside braces `{ }`, and each statement ends with a semicolon `;`.

---

## 2. Conditions: True or False

A **condition** is a question that the computer answers with `true` or `false`. You build conditions from two kinds of operators.

### 2.1 Comparison Operators

These compare two values:

| Operator | Meaning                  | Example    | Result when `x = 5` |
| -------- | ------------------------ | ---------- | ------------------- |
| `==`     | equal to                 | `x == 5`   | `true`              |
| `!=`     | not equal to             | `x != 3`   | `true`              |
| `>`      | greater than             | `x > 10`   | `false`             |
| `<`      | less than                | `x < 10`   | `true`              |
| `>=`     | greater than or equal to | `x >= 5`   | `true`              |
| `<=`     | less than or equal to    | `x <= 4`   | `false`             |

> **Important:** `=` means *assign a value*, while `==` means *compare*. Mixing these up is the most common beginner error.

### 2.2 Logical Operators

These combine or reverse conditions. Note how they differ from Python.

| C++  | Python | Meaning                       | Example                  |
| ---- | ------ | ----------------------------- | ------------------------ |
| `&&` | `and`  | true only if **both** are true | `age >= 18 && hasID`     |
| `||` | `or`   | true if **at least one** is true | `day == 6 || day == 7` |
| `!`  | `not`  | reverses true/false           | `!finished`              |

---

## 3. The Simple `if`

The simple `if` runs a block of code **only when** its condition is true. If the condition is false, the block is skipped.

**Syntax:**

```cpp
if (condition) {
    // this runs only when the condition is true
}
```

**Example — checking adulthood:**

```cpp
#include <iostream>
using namespace std;

int main() {
    int age;
    cout << "Enter your age: ";
    cin >> age;

    // The body runs only if the condition is true
    if (age >= 18) {
        cout << "You are an adult." << endl;
    }

    cout << "Done." << endl;  // this line always runs
    return 0;
}
```

**Output (user types 20):**
```
Enter your age: 20
You are an adult.
Done.
```

**Output (user types 15):**
```
Enter your age: 15
Done.
```

Notice that "Done." prints in both runs, because it is outside the `if` block.

---

## 4. The `if-else`

The `if-else` chooses between **two** paths. Exactly one block runs — never both, never neither.

**Syntax:**

```cpp
if (condition) {
    // runs when the condition is true
} else {
    // runs when the condition is false
}
```

**Example — even or odd:**

```cpp
#include <iostream>
using namespace std;

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;

    // The % operator gives the remainder; 0 means the number is even
    if (number % 2 == 0) {
        cout << "Even" << endl;
    } else {
        cout << "Odd" << endl;
    }
    return 0;
}
```

**Output (user types 4):**
```
Enter a number: 4
Even
```

**Output (user types 7):**
```
Enter a number: 7
Odd
```

---

## 5. The `if-else if-else` Chain

When there are **many** possible paths, you join several conditions in a chain. C++ checks them from top to bottom and stops at the **first** condition that is true. The final `else` catches everything else.

**Syntax:**

```cpp
if (condition1) {
    // path 1
} else if (condition2) {
    // path 2
} else if (condition3) {
    // path 3
} else {
    // none of the above
}
```

**Example — letter grade:**

```cpp
#include <iostream>
using namespace std;

int main() {
    int mark;
    cout << "Enter your mark: ";
    cin >> mark;

    // Checked top to bottom; the first true branch wins
    if (mark >= 90) {
        cout << "Grade A" << endl;
    } else if (mark >= 80) {
        cout << "Grade B" << endl;
    } else if (mark >= 70) {
        cout << "Grade C" << endl;
    } else {
        cout << "Grade F" << endl;
    }
    return 0;
}
```

**Output (user types 85):**
```
Enter your mark: 85
Grade B
```

> **Note:** In C++ you write `else if` as **two words**. There is no `elif` keyword as there is in Python.

---

## 6. Nested `if`

A **nested `if`** is one `if` placed inside another. The inner `if` is reached **only when** the outer condition is true. Use nesting when a second question only makes sense after the first one is answered.

**Example — driving eligibility:**

```cpp
#include <iostream>
using namespace std;

int main() {
    int age, hasLicense;   // hasLicense: 1 = yes, 0 = no
    cout << "Enter age and license (1/0): ";
    cin >> age >> hasLicense;

    if (age >= 18) {                 // outer question
        if (hasLicense == 1) {       // inner question
            cout << "You can drive." << endl;
        } else {
            cout << "Get a license first." << endl;
        }
    } else {
        cout << "Too young to drive." << endl;
    }
    return 0;
}
```

**Output (age = 20, hasLicense = 1):**
```
Enter age and license (1/0): 20 1
You can drive.
```

**Output (age = 20, hasLicense = 0):**
```
Enter age and license (1/0): 20 0
Get a license first.
```

**Output (age = 15, hasLicense = 1):**
```
Enter age and license (1/0): 15 1
Too young to drive.
```

The inner check about the license is never reached when the person is under 18.

---

## 7. Python vs. C++ Comparison

You already know the logic from Python. Only the punctuation changes.

| Idea                | Python              | C++                       |
| ------------------- | ------------------- | ------------------------- |
| Start a condition   | `if x > 0:`         | `if (x > 0) {`            |
| Else-if branch      | `elif x == 0:`      | `else if (x == 0) {`      |
| Else branch         | `else:`             | `else {`                  |
| Group the body      | indentation         | braces `{ }`              |
| "and" / "or" / "not"| `and` / `or` / `not`| `&&` / `||` / `!`         |
| Boolean values      | `True` / `False`    | `true` / `false`          |
| End of a statement  | (nothing)           | semicolon `;`             |

**Same task in both languages:**

*Python:*
```python
if mark >= 60:
    print("Pass")
else:
    print("Fail")
```

*C++:*
```cpp
if (mark >= 60) {
    cout << "Pass" << endl;
} else {
    cout << "Fail" << endl;
}
```

---

## 8. Common Mistakes

**Mistake 1 — Using `=` instead of `==`**

**Wrong:**
```cpp
if (x = 5) {          // assigns 5 to x, condition is always true
    cout << "Five";
}
```

**Correct:**
```cpp
if (x == 5) {         // compares x with 5
    cout << "Five";
}
```

**Explanation:** A single `=` stores a value; double `==` compares. The wrong version changes `x` and always runs the block.

---

**Mistake 2 — A semicolon right after the condition**

**Wrong:**
```cpp
if (age >= 18);       // the ; ends the if; the block below always runs
{
    cout << "Adult";
}
```

**Correct:**
```cpp
if (age >= 18) {
    cout << "Adult";
}
```

**Explanation:** The stray `;` makes the body of the `if` empty, so the message prints no matter what `age` is.

---

**Mistake 3 — Using `elif` instead of `else if`**

**Wrong:**
```cpp
if (m >= 90) { ... }
elif (m >= 80) { ... }   // elif does not exist in C++
```

**Correct:**
```cpp
if (m >= 90) { ... }
else if (m >= 80) { ... }
```

**Explanation:** `elif` is a Python keyword. C++ uses two separate words: `else if`.

---

**Mistake 4 — Forgetting the braces with more than one line**

**Wrong:**
```cpp
if (passed)
    cout << "Well done" << endl;
    cout << "You may continue" << endl;  // NOT part of the if!
```

**Correct:**
```cpp
if (passed) {
    cout << "Well done" << endl;
    cout << "You may continue" << endl;
}
```

**Explanation:** Without braces, only the first line belongs to the `if`. The second line always runs. Always use `{ }` to be safe.

---

**Mistake 5 — Using `and` / `or` words out of habit**

**Wrong:**
```cpp
if (age >= 18 and hasID) { ... }   // not standard style in this course
```

**Correct:**
```cpp
if (age >= 18 && hasID) { ... }
```

**Explanation:** Use the symbol operators `&&` and `||` for combining conditions in C++. Reaching for Python's `and`/`or` is a common slip.

---

## 9. Practice Exercises

Write a complete C++ program for each task, then test it by running it.

**Exercise 1 — Pass or Fail**
Read a test mark (0–100). Print `Pass` if it is 60 or more, otherwise `Fail`.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int mark;
    cin >> mark;
    if (mark >= 60) {
        cout << "Pass" << endl;
    } else {
        cout << "Fail" << endl;
    }
    return 0;
}
```
**Output (mark = 72):**
```
Pass
```
</details>

---

**Exercise 2 — Even or Odd**
Read an integer and print whether it is `Even` or `Odd`.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n % 2 == 0) {
        cout << "Even" << endl;
    } else {
        cout << "Odd" << endl;
    }
    return 0;
}
```
**Output (n = 7):**
```
Odd
```
</details>

---

**Exercise 3 — Letter Grade**
Read a mark (0–100) and print a letter grade: A (≥90), B (≥80), C (≥70), D (≥60), otherwise F.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int m;
    cin >> m;
    if (m >= 90) {
        cout << "A" << endl;
    } else if (m >= 80) {
        cout << "B" << endl;
    } else if (m >= 70) {
        cout << "C" << endl;
    } else if (m >= 60) {
        cout << "D" << endl;
    } else {
        cout << "F" << endl;
    }
    return 0;
}
```
**Output (m = 82):**
```
B
```
</details>

---

**Exercise 4 — Largest of Three**
Read three integers and print the largest of the three.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if (a >= b && a >= c) {
        cout << a << endl;
    } else if (b >= c) {
        cout << b << endl;
    } else {
        cout << c << endl;
    }
    return 0;
}
```
**Output (a b c = 4 9 7):**
```
9
```
</details>

---

**Exercise 5 — Discount (Nested if)**
Read `age` and `isStudent` (1 = yes, 0 = no). If age is under 12 **or** the person is a student, print `Discount`; otherwise print `Full price`. Use a nested `if`.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int age, isStudent;
    cin >> age >> isStudent;
    if (age < 12) {
        cout << "Discount" << endl;
    } else {
        if (isStudent == 1) {
            cout << "Discount" << endl;
        } else {
            cout << "Full price" << endl;
        }
    }
    return 0;
}
```
**Output (age = 20, isStudent = 1):**
```
Discount
```
</details>

---

## 10. Summary

### Key Concepts

- A **condition** is an expression that is either `true` or `false`.
- `if` runs a block only when the condition is true.
- `if-else` chooses between two paths.
- `if-else if-else` chooses among many paths, top to bottom.
- A **nested `if`** places one decision inside another.

### Important Points

1. Conditions must be inside parentheses: `if (condition)`.
2. Use braces `{ }` for the body, even when it is one line.
3. Use `==` to compare and `=` to assign — never mix them.
4. Never put a semicolon directly after `if (condition)`.
5. C++ uses `else if` (two words), not `elif`.
6. Combine conditions with `&&`, `||`, and `!`.
7. In an `if-else if` chain, only the first true branch runs.
8. The inner block of a nested `if` runs only when the outer condition is true.

### Quick Reference

```cpp
// Simple if
if (condition) { /* ... */ }

// if-else
if (condition) { /* ... */ } else { /* ... */ }

// if-else if-else chain
if (c1) { /* ... */ }
else if (c2) { /* ... */ }
else { /* ... */ }

// Nested if
if (outer) {
    if (inner) { /* ... */ }
}
```

### Next Steps

In the next lecture we move on to **loops in C++** — the `while` loop and the `for` loop — so your programs can repeat work many times.
