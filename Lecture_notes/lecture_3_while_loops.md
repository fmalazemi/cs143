# CS143 — Introduction to C++
## Lecture 3: The `while` Loop

**Instructor:** Dr. Fawaz Alazemi
**Builds on:** Lecture 2 (conditions and comparisons)
**Audience:** Students who completed CS101 (Python)

---

## Table of Contents

1. [Introduction](#1-introduction)
2. [Why We Need Loops](#2-why-we-need-loops)
3. [The Three Parts of a Loop](#3-the-three-parts-of-a-loop)
4. [Tracing a Loop Step by Step](#4-tracing-a-loop-step-by-step)
5. [Counting and Adding Up](#5-counting-and-adding-up)
6. [Stopping on a Special Value (Sentinel)](#6-stopping-on-a-special-value-sentinel)
7. [`break` and `continue`](#7-break-and-continue)
8. [Python vs. C++](#8-python-vs-c)
9. [Common Mistakes](#9-common-mistakes)
10. [Practice Exercises](#10-practice-exercises)
11. [Summary](#11-summary)

---

## 1. Introduction

A **loop** is a way to repeat a block of code many times without writing it again and again. The `while` loop repeats its body **as long as a condition stays true**.

You already used `while` loops in Python. The idea is exactly the same in C++ — only the punctuation changes: the condition goes inside parentheses `( )`, and the body goes inside braces `{ }`.

**Why loops matter:**

- They save you from copying the same line hundreds of times.
- They let a program handle any amount of work, even amounts decided while the program runs.
- They are the heart of almost every useful program.
- They make your code shorter, clearer, and easier to fix.

**Real-world analogies:**

- *Climbing stairs:* keep stepping up **while** you have not reached the top floor.
- *Filling a glass:* keep pouring **while** the glass is not full.
- *Reading a book:* keep turning pages **while** there are pages left.

**When to use `while`:** Use a `while` loop when you do **not** know in advance how many times you must repeat — for example, reading numbers from a user until they decide to stop.

---

## 2. Why We Need Loops

Without a loop, repeating work means copying the same statement over and over:

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << 1 << endl;
    cout << 2 << endl;
    cout << 3 << endl;
    // What about printing 1 to 1000? This does not scale.
    return 0;
}
```

**Output:**
```
1
2
3
```

A loop asks the computer to do the repeating for us:

```cpp
#include <iostream>
using namespace std;

int main() {
    int i = 1;
    while (i <= 1000) {   // repeat for 1, 2, ... up to 1000
        cout << i << endl;
        i++;
    }
    return 0;
}
```

The second version prints **one thousand** lines, but the code stays just as short.

---

## 3. The Three Parts of a Loop

Every correct `while` loop has three parts. Missing any one of them causes a bug.

```cpp
int i = 1;            // 1. START: create and set the counter

while (i <= 5) {      // 2. CONDITION: keep going while this is true
    cout << i << endl; //    body: the repeated work
    i++;              // 3. UPDATE: move the counter toward the end
}
```

**Output:**
```
1
2
3
4
5
```

| Part | What it does | Where it goes |
| --- | --- | --- |
| **Start** | Creates the counter and gives it a first value | Before the loop |
| **Condition** | A true/false test, checked before each pass | Inside `( )` |
| **Update** | Changes the counter so the loop will eventually stop | Inside the body |

> **Warning:** If you forget the **update**, the condition never becomes false and the loop runs forever. This is called an **infinite loop**.

The short form `i++` means "add one to `i`". It is the same as `i = i + 1`. Likewise, `i--` subtracts one, and `i += 2` adds two.

---

## 4. Tracing a Loop Step by Step

To understand a loop, follow it one pass at a time. Here we trace `int i = 1; while (i <= 3)`:

| Pass | `i` before | `i <= 3` ? | prints | `i` after `i++` |
| --- | --- | --- | --- | --- |
| 1 | 1 | true | `1` | 2 |
| 2 | 2 | true | `2` | 3 |
| 3 | 3 | true | `3` | 4 |
| 4 | 4 | **false** | (stop) | — |

When `i` becomes `4`, the condition `i <= 3` is false, so the loop ends and the program continues after the closing brace.

**Tip:** When a loop misbehaves, draw a small table like this on paper. It quickly shows whether the counter ever reaches the stop value.

---

## 5. Counting and Adding Up

A very common job is to add up a series of numbers. We use a variable called an **accumulator** that grows on each pass.

```cpp
#include <iostream>
using namespace std;

int main() {
    int n, i = 1, sum = 0;   // sum (the accumulator) starts at 0
    cout << "Enter n: ";
    cin >> n;

    while (i <= n) {
        sum = sum + i;       // add the current i to the total
        i++;
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

The loop adds `1 + 2 + 3 + 4 + 5 = 15`. The most important habit here is to set the accumulator to `0` **before** the loop starts.

---

## 6. Stopping on a Special Value (Sentinel)

Sometimes you do not know how many values the user will enter. You can keep looping until they type a special "stop" value, called a **sentinel**.

```cpp
#include <iostream>
using namespace std;

int main() {
    int x, total = 0;
    cout << "Enter numbers (0 to stop):" << endl;

    cin >> x;               // read the first value
    while (x != 0) {        // keep going until the user enters 0
        total = total + x;
        cin >> x;           // read the next value
    }
    cout << "Total = " << total << endl;
    return 0;
}
```

**Output (user types 4, 6, 10, 0):**
```
Total = 20
```

This pattern is exactly where the `while` loop is the best choice: the number of repetitions is decided **while** the program runs, not before.

> **Read-before-loop, read-again-inside:** Notice we read one value *before* the loop, then read the next value at the *end* of the body. This common shape makes sure the sentinel itself is never added to the total.

---

## 7. `break` and `continue`

Two keywords give you extra control inside a loop.

**`break`** — leave the loop immediately:

```cpp
int i = 1;
while (i <= 10) {
    if (i == 5) break;   // stop the whole loop now
    cout << i << " ";
    i++;
}
```

**Output:**
```
1 2 3 4
```

**`continue`** — skip the rest of this pass and go to the next one:

```cpp
int i = 0;
while (i < 5) {
    i++;
    if (i == 3) continue; // skip printing 3
    cout << i << " ";
}
```

**Output:**
```
1 2 4 5
```

Use these sparingly. A clear condition is usually easier to read than a loop full of `break` statements.

---

## 8. Python vs. C++

| Idea | Python | C++ |
| --- | --- | --- |
| Start the loop | `while i < 5:` | `while (i < 5) {` |
| Group the body | indentation | `{ braces }` |
| Add one | `i += 1` | `i++;` (or `i += 1;`) |
| Leave early | `break` | `break;` |
| Skip a pass | `continue` | `continue;` |
| End each statement | (nothing) | `;` (semicolon) |

The loop idea is identical. C++ simply asks for parentheses, braces, and semicolons.

---

## 9. Common Mistakes

**Mistake 1 — Forgetting the update (infinite loop)**

**Wrong:**
```cpp
int i = 1;
while (i <= 5) {
    cout << i << endl;
    // i is never changed, so the loop never ends
}
```

**Correct:**
```cpp
int i = 1;
while (i <= 5) {
    cout << i << endl;
    i++;   // move toward the stop value
}
```

**Explanation:** Without `i++`, the condition `i <= 5` is always true and the program freezes. Always change the counter inside the loop.

---

**Mistake 2 — A semicolon right after `while`**

**Wrong:**
```cpp
int i = 1;
while (i <= 5);   // this semicolon makes the body empty
{
    cout << i << endl;
    i++;
}
```

**Correct:**
```cpp
int i = 1;
while (i <= 5) {
    cout << i << endl;
    i++;
}
```

**Explanation:** The stray `;` becomes the loop's whole body — an empty action — so the loop runs forever and the braces below run only once. Never put `;` directly after the condition.

---

**Mistake 3 — Using `=` instead of `==`**

**Wrong:**
```cpp
int i = 1;
while (i = 5) {   // assigns 5 to i; the value 5 is "true", so it loops forever
    cout << i << endl;
}
```

**Correct:**
```cpp
int i = 1;
while (i == 5) {  // compares i with 5
    cout << i << endl;
}
```

**Explanation:** A single `=` stores a value; double `==` compares. In a condition you almost always want `==`.

---

**Mistake 4 — Counter not started**

**Wrong:**
```cpp
int i;            // i has no known value
while (i <= 5) {  // the test uses garbage
    cout << i << endl;
    i++;
}
```

**Correct:**
```cpp
int i = 1;        // give the counter a clear first value
while (i <= 5) {
    cout << i << endl;
    i++;
}
```

**Explanation:** A variable with no starting value holds an unpredictable number. Always set the counter before the loop.

---

**Mistake 5 — Off-by-one error**

**Wrong:**
```cpp
int i = 1;
while (i < 5) {   // stops at 4, not 5
    cout << i << endl;
    i++;
}
```

**Correct:**
```cpp
int i = 1;
while (i <= 5) {  // includes 5
    cout << i << endl;
    i++;
}
```

**Explanation:** `<` and `<=` differ by exactly one pass. Decide carefully whether the last value should be included.

---

## 10. Practice Exercises

Write a complete C++ program for each task using a `while` loop.

**Exercise 1 — Count to ten**
Print the numbers from 1 to 10, each on its own line.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int i = 1;
    while (i <= 10) {
        cout << i << endl;
        i++;
    }
    return 0;
}
```
**Output:** the numbers 1 through 10, one per line.
</details>

---

**Exercise 2 — Even numbers**
Print the even numbers from 2 to 20 on one line.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int i = 2;
    while (i <= 20) {
        cout << i << " ";
        i += 2;          // jump by 2 each pass
    }
    cout << endl;
    return 0;
}
```
**Output:**
```
2 4 6 8 10 12 14 16 18 20
```
</details>

---

**Exercise 3 — Factorial**
Read a number `n` and compute its factorial (1 × 2 × … × n).

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int n, i = 1;
    long fact = 1;       // products grow quickly, so use long
    cin >> n;
    while (i <= n) {
        fact = fact * i;
        i++;
    }
    cout << n << "! = " << fact << endl;
    return 0;
}
```
**Output (n = 5):**
```
5! = 120
```
</details>

---

**Exercise 4 — Multiplication table**
Read `n` and print its multiplication table from n×1 up to n×10.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int n, i = 1;
    cin >> n;
    while (i <= 10) {
        cout << n << " x " << i << " = " << n * i << endl;
        i++;
    }
    return 0;
}
```
**Output (n = 3, first lines):**
```
3 x 1 = 3
3 x 2 = 6
3 x 3 = 9
```
</details>

---

**Exercise 5 — Count positive numbers**
Keep reading numbers until the user enters a negative number. Print how many positive numbers were entered.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int x, count = 0;
    cin >> x;
    while (x >= 0) {        // stop on the first negative number
        count = count + 1;
        cin >> x;
    }
    cout << "Positives: " << count << endl;
    return 0;
}
```
**Output (user types 5, 8, 2, -1):**
```
Positives: 3
```
</details>

---

## 11. Summary

### Key Concepts
- A `while` loop repeats its body while a condition stays true.
- Every loop has three parts: **start**, **condition**, and **update**.
- An **accumulator** (starting at 0) is used to add up values.
- A **sentinel** value lets you stop when the count is unknown.

### Important Points
1. The condition is checked **before** every pass.
2. Always give the counter a starting value before the loop.
3. Always change the counter inside the loop so it can end.
4. Use `==` to compare; `=` only assigns.
5. Do not put a semicolon directly after `while (...)`.
6. Watch the difference between `<` and `<=` (off-by-one).
7. `break` leaves the loop; `continue` skips to the next pass.

### Quick Reference
```cpp
int i = START;            // 1. start
while (CONDITION) {       // 2. condition
    // body: repeated work
    i++;                  // 3. update
}
```

### Next Steps
**Lecture 4** introduces the `for` loop — a tidy way to gather the three parts (start, condition, update) onto a single line.
