# CS143 — Lecture 4: The `for` Loop in C++

**Instructor:** Dr. Fawaz Alazemi
**Course:** CS143 — Introduction to C++
**Prerequisite:** Lecture 3 (the `while` loop)

---

## Table of Contents

1. [Introduction](#1-introduction)
2. [From `while` to `for`](#2-from-while-to-for)
3. [Anatomy of a `for` Loop](#3-anatomy-of-a-for-loop)
4. [The Order of Execution](#4-the-order-of-execution)
5. [Changing the Step](#5-changing-the-step)
6. [Adding Up With a `for` Loop](#6-adding-up-with-a-for-loop)
7. [Choosing `for` or `while`](#7-choosing-for-or-while)
8. [Python `range()` vs. C++ `for`](#8-python-range-vs-c-for)
9. [Worked Examples](#9-worked-examples)
10. [Common Mistakes](#10-common-mistakes)
11. [Practice Exercises](#11-practice-exercises)
12. [Summary](#12-summary)

---

## 1. Introduction

A **`for` loop** is a control structure that repeats a block of code a known number of times. It gathers the three parts of a counting loop — the start value, the stopping condition, and the update step — into a single, easy-to-read line.

**Why the `for` loop matters:**

- It keeps all loop control in one clear place, which makes counting code easy to read.
- It is the natural choice when you already know how many times to repeat.
- It reduces mistakes, because you are less likely to forget the update step.
- It maps directly onto Python's `for ... in range(...)`, which you already know.

**Real-world analogies:**

- Climbing a staircase: you start on step 1, keep going while there are steps left, and move up one step each time.
- A countdown timer before a rocket launch: start at 10, continue while the number is at least 1, and subtract one each second.
- Stamping a row of 20 envelopes: you know exactly how many to do before you begin.

**When to use it:** Reach for a `for` loop whenever the number of repetitions is known in advance, such as "print the numbers 1 to 100" or "do this exactly 5 times".

---

## 2. From `while` to `for`

You already wrote counting loops with `while`. A `for` loop expresses the same idea, but collects the **start**, **condition**, and **update** onto one line.

**The `while` version (Lecture 3):**

```cpp
#include <iostream>
using namespace std;

int main() {
    int i = 1;            // start
    while (i <= 5) {      // condition
        cout << i << " ";
        i++;              // update
    }
    cout << endl;
    return 0;
}
```

**The `for` version (this lecture):**

```cpp
#include <iostream>
using namespace std;

int main() {
    // for (start; condition; update)
    for (int i = 1; i <= 5; i++) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
```

**Output (both programs):**
```
1 2 3 4 5
```

Both loops do exactly the same work. The `for` loop simply keeps the loop control together, so a reader can understand the whole loop by reading one line.

---

## 3. Anatomy of a `for` Loop

A `for` loop header has three parts, separated by semicolons:

```cpp
for (int i = 1; i <= 5; i++) {
    cout << i << " ";   // the body: the repeated work
}
```

| Part | Example | Meaning |
| --- | --- | --- |
| Start | `int i = 1` | Runs once, at the very beginning. Sets up the counter. |
| Condition | `i <= 5` | A true/false test, checked **before** each pass. |
| Update | `i++` | Runs **after** each pass, then the condition is checked again. |

Key points to remember:

- The three parts are separated by semicolons `;`, not commas.
- The counter variable (here `i`) is usually declared inside the `for` header.
- The body is wrapped in braces `{ }`.

---

## 4. The Order of Execution

Understanding the order of the parts helps you predict exactly what a loop will do. For `for (int i = 1; i <= 3; i++)`, the steps run like this:

| Step | `i` | `i <= 3` ? | Prints |
| --- | --- | --- | --- |
| start | 1 | — | — |
| pass 1 | 1 | true | 1 |
| pass 2 | 2 | true | 2 |
| pass 3 | 3 | true | 3 |
| check | 4 | false | stop |

```cpp
#include <iostream>
using namespace std;

int main() {
    for (int i = 1; i <= 3; i++) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
```

**Output:**
```
1 2 3
```

The repeating pattern each pass is: **check condition → run body → do update → check again**. When `i` becomes 4, the condition is false, so the loop ends and the program continues after the closing brace.

---

## 5. Changing the Step

The **update** part controls the step size and direction. By changing it, the same loop shape can count in different ways.

**Count by 2:**

```cpp
#include <iostream>
using namespace std;

int main() {
    for (int i = 2; i <= 10; i += 2) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
```

**Output:**
```
2 4 6 8 10
```

**Count down:**

```cpp
#include <iostream>
using namespace std;

int main() {
    for (int i = 5; i >= 1; i--) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
```

**Output:**
```
5 4 3 2 1
```

Use `i += 2` to skip values, and `i--` to count downward. The condition must match the direction: when counting down, the test uses `>=`.

---

## 6. Adding Up With a `for` Loop

A very common pattern is to keep a running total in a variable called an **accumulator**. You set it to 0 before the loop, then add to it on each pass.

```cpp
#include <iostream>
using namespace std;

int main() {
    int n, sum = 0;        // accumulator starts at 0
    cout << "Enter n: ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        sum += i;          // add i to the running total
    }
    cout << "Sum = " << sum << endl;
    return 0;
}
```

**Output (user types 5):**
```
Enter n: 5
Sum = 15
```

This program adds 1 + 2 + 3 + 4 + 5. The counter `i` exists only inside the loop, while `sum` is declared outside so it keeps its value after the loop ends.

---

## 7. Choosing `for` or `while`

Both loops can solve the same problems, so choose the one that makes your intent clearer.

| Situation | Better choice | Reason |
| --- | --- | --- |
| You know the count in advance | `for` | All loop control sits on one line. |
| Counting with an index (1 to n) | `for` | The header reads like a counting sentence. |
| The count is unknown | `while` | Stop on a condition or sentinel value. |
| Reading input until a stop value | `while` | You do not know how many values will come. |

Any `for` loop can be rewritten as a `while` loop, and any `while` loop can be rewritten as a `for` loop. The rule of thumb: use `for` for known counts, and `while` for unknown counts.

---

## 8. Python `range()` vs. C++ `for`

You used `for i in range(...)` in Python. The C++ `for` header carries the same three pieces of information, written out explicitly.

**Python:**

```python
for i in range(1, 6):
    print(i)
```

**C++:**

```cpp
for (int i = 1; i < 6; i++) {
    cout << i << endl;
}
```

**Output (both):**
```
1
2
3
4
5
```

| `range` part | Python | C++ part |
| --- | --- | --- |
| start | `range(1, ...)` | `int i = 1` |
| stop (not included) | `range(..., 6)` | `i < 6` |
| step | `range(..., 2)` | `i += 2` |

**Important:** In Python, the stop value is *not* included, so `range(1, 6)` reaches 5. The matching C++ condition is therefore `i < 6` (or, equivalently, `i <= 5`). This is a common source of off-by-one errors for students coming from Python.

---

## 9. Worked Examples

### Worked Example 1 — Print 1 to 10

```cpp
#include <iostream>
using namespace std;

int main() {
    // start at 1, run while i <= 10, add 1 each pass
    for (int i = 1; i <= 10; i++) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
```

**Output:**
```
1 2 3 4 5 6 7 8 9 10
```

This shows the basic counting shape of a `for` loop, printing the numbers on one line separated by spaces.

### Worked Example 2 — Multiplication Table

```cpp
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    for (int i = 1; i <= 10; i++) {
        cout << n << " x " << i << " = " << n * i << endl;
    }
    return 0;
}
```

**Output (user types 3):**
```
3 x 1 = 3
3 x 2 = 6
3 x 3 = 9
...
3 x 10 = 30
```

Here the counter `i` is used inside the calculation `n * i` to build each line of the times table.

### Worked Example 3 — Factorial

```cpp
#include <iostream>
using namespace std;

int main() {
    int n;
    long fact = 1;          // product accumulator starts at 1
    cout << "Enter n: ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        fact = fact * i;    // multiply by i each pass
    }
    cout << n << "! = " << fact << endl;
    return 0;
}
```

**Output (user types 5):**
```
Enter n: 5
5! = 120
```

This multiplies 1 × 2 × 3 × 4 × 5. The accumulator `fact` starts at **1**, not 0, because multiplying by 0 would always give 0. The type `long` is used because factorials grow very quickly.

---

## 10. Common Mistakes

**1. Semicolon right after the `for` header**

**Wrong:**
```cpp
for (int i = 1; i <= 5; i++);   // stray semicolon
    cout << i << endl;          // not part of the loop
```

**Correct:**
```cpp
for (int i = 1; i <= 5; i++) {
    cout << i << endl;
}
```

**Explanation:** The semicolon makes the loop body empty, so the `cout` line runs only once (and `i` is out of scope). Remove the semicolon and use braces.

**2. Using commas instead of semicolons**

**Wrong:**
```cpp
for (int i = 1, i <= 5, i++) {   // commas
```

**Correct:**
```cpp
for (int i = 1; i <= 5; i++) {   // semicolons
```

**Explanation:** The three parts of a `for` header must be separated by semicolons. Commas cause a compiler error.

**3. Off-by-one error**

**Wrong:**
```cpp
// Intended to print 1 to 10, but stops at 9
for (int i = 1; i < 10; i++) {
    cout << i << " ";
}
```

**Correct:**
```cpp
for (int i = 1; i <= 10; i++) {
    cout << i << " ";
}
```

**Explanation:** `i < 10` stops at 9. To include 10, use `i <= 10`. Decide carefully whether the last value should be included.

**4. Forgetting the update step**

**Wrong:**
```cpp
for (int i = 1; i <= 5; ) {   // no update
    cout << i << " ";
}
```

**Correct:**
```cpp
for (int i = 1; i <= 5; i++) {
    cout << i << " ";
}
```

**Explanation:** With no update, `i` never changes, the condition stays true, and the loop runs forever (an infinite loop). Always include the update.

**5. Using the counter after the loop**

**Wrong:**
```cpp
for (int i = 1; i <= 5; i++) {
    cout << i << " ";
}
cout << i;   // error: i no longer exists here
```

**Correct:**
```cpp
int i;
for (i = 1; i <= 5; i++) {
    cout << i << " ";
}
cout << i;   // now i is still in scope
```

**Explanation:** A counter declared inside the `for` header only exists inside the loop. If you need the value afterward, declare the variable before the loop.

---

## 11. Practice Exercises

Write a complete C++ program for each task using a `for` loop.

**Exercise 1.** Print the numbers from 1 to 20, each on its own line.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    for (int i = 1; i <= 20; i++) {
        cout << i << endl;
    }
    return 0;
}
```
</details>

**Exercise 2.** Print the multiples of 5 from 5 to 50 on one line (step by 5).
Expected output: `5 10 15 20 25 30 35 40 45 50`

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    for (int i = 5; i <= 50; i += 5) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
```
</details>

**Exercise 3.** Read a number `n` and print the sum of the numbers from 1 to `n`.
Expected behavior: if `n` is 5, the output is `Sum = 15`.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int n, sum = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    cout << "Sum = " << sum << endl;
    return 0;
}
```
</details>

**Exercise 4.** Read a number `n` and print it counting down from `n` to 1.
Expected behavior: if `n` is 5, the output is `5 4 3 2 1`.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = n; i >= 1; i--) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
```
</details>

**Exercise 5.** Read a number `n` and print the sum of the even numbers from 1 to `n`.
Expected behavior: if `n` is 10, the output is `Even sum = 30`.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int n, sum = 0;
    cin >> n;
    for (int i = 2; i <= n; i += 2) {
        sum += i;
    }
    cout << "Even sum = " << sum << endl;
    return 0;
}
```
</details>

---

## 12. Summary

### Key Concepts

- A `for` loop puts the **start**, **condition**, and **update** on one line.
- The **update** controls the step size and direction.
- An **accumulator** keeps a running total (start at 0 to add, at 1 to multiply).
- Use a `for` loop when the number of repetitions is known.

### Important Points

1. The three parts of the header are separated by semicolons `;`, not commas.
2. The order each pass is: check condition, run body, do update, check again.
3. The condition is checked **before** every pass.
4. `i <= n` and `i < n` give different counts — watch for off-by-one errors.
5. A stray semicolon right after `for (...)` creates an empty body.
6. Forgetting the update creates an infinite loop.
7. A counter declared in the header exists only inside the loop.
8. C++ `for` matches Python's `range(start, stop, step)`, but the stop value is not included.

### Quick Reference

```cpp
// General shape of a for loop
for (int i = start; i <= limit; i += step) {
    // repeated work goes here
}
```

### Next Steps

In the next lecture we will study **nested loops** — placing one loop inside another to work with rows and columns, tables, and patterns.
