# CS143 — Lecture 8: Recursion

> **Course:** CS143 Introduction to C++ · **Instructor:** Dr. Fawaz Alazemi
> **Audience:** Students who completed CS101 (Python). Assumes only basic Python (variables, `if`, loops, functions).
> **Prerequisite:** Lecture 7 (Functions). *Recursion is the topic of this lecture.*

---

## Table of Contents

1. [Introduction](#1-introduction)
2. [The Two Parts of Recursion](#2-the-two-parts-of-recursion)
3. [How Recursion Works (The Call Stack)](#3-how-recursion-works-the-call-stack)
4. [Worked Examples](#4-worked-examples)
   - [Example 1: Countdown](#example-1-countdown)
   - [Example 2: Factorial](#example-2-factorial)
   - [Example 3: Sum From 1 to n](#example-3-sum-from-1-to-n)
5. [Recursion vs. Iteration](#5-recursion-vs-iteration)
6. [Common Mistakes](#6-common-mistakes)
7. [Practice Exercises](#7-practice-exercises)
8. [Summary](#8-summary)

---

## 1. Introduction

**Recursion** is when a function solves a problem by calling *itself* on a smaller version of the same problem. The function keeps reducing the problem step by step until it becomes small enough to answer directly.

You already used functions in Lecture 7. Recursion is simply a function whose body contains a call to that same function.

**Why recursion matters:**

- Some problems are naturally defined in terms of smaller copies of themselves (for example, a factorial).
- It can express a solution in fewer, clearer lines than a loop.
- It is the foundation for many later topics: tree traversal, sorting algorithms, and divide-and-conquer.
- Understanding the call stack helps you reason about how *all* function calls work.

**Real-world analogies:**

- **Two mirrors facing each other** show a smaller copy inside a smaller copy, again and again.
- **Russian nesting dolls (matryoshka):** open one doll to find a smaller doll inside, until you reach the tiniest one that does not open.
- **A line of people passing a question back:** each person asks the next person and waits for the answer, until someone at the front can answer directly.

**When to use it:** reach for recursion when a problem can be described as "do one small step, then solve the same problem on a smaller input."

---

## 2. The Two Parts of Recursion

Every correct recursive function has **two** parts.

| Part | Job | Example (factorial) |
|------|-----|---------------------|
| **Base case** | The simplest input, answered directly with no further call. It **stops** the recursion. | factorial of 1 is 1 |
| **Recursive case** | Do one step, then call the function again on a **smaller** input. | n! = n × (n − 1)! |

```cpp
#include <iostream>
using namespace std;

int factorial(int n) {
    if (n <= 1) return 1;            // base case: stop here
    return n * factorial(n - 1);     // recursive case: smaller n
}

int main() {
    cout << factorial(4) << endl;
    return 0;
}
```

**Output:**
```
24
```

**Important:** always write the base case first. Without it, or if the input never gets smaller, the function never stops.

---

## 3. How Recursion Works (The Call Stack)

When a function calls itself, the earlier call **pauses** and waits for the new call to finish. These paused calls pile up in an area of memory called the **call stack**. When the base case is reached, the calls finish one by one and return their values back up the stack.

Consider `factorial(3)`:

```
factorial(3)  = 3 * factorial(2)      <- waits for factorial(2)
                    factorial(2) = 2 * factorial(1)   <- waits for factorial(1)
                                        factorial(1) = 1   (base case, returns)
```

The values then return back up:

```
factorial(1) returns 1
factorial(2) returns 2 * 1 = 2
factorial(3) returns 3 * 2 = 6
```

**Going down** the calls get deeper; **coming back up** each call finishes its multiplication and returns. The final answer of `factorial(3)` is `6`.

---

## 4. Worked Examples

### Example 1: Countdown

A recursive `void` function that prints a count and then a message. This is the easiest kind to trace because each step prints something.

```cpp
#include <iostream>
using namespace std;

void countdown(int n) {
    if (n == 0) {              // base case
        cout << "Done!" << endl;
        return;                // stop
    }
    cout << n << " ";          // one step
    countdown(n - 1);          // smaller problem
}

int main() {
    countdown(3);
    return 0;
}
```

**Output:**
```
3 2 1 Done!
```

`countdown(3)` prints `3`, then calls `countdown(2)`, then `countdown(1)`, then `countdown(0)` which prints `Done!` and stops. Each call uses a smaller `n`, heading toward the base case `n == 0`.

### Example 2: Factorial

A recursive function that returns a value. `factorial(n)` returns `n` multiplied by the factorial of `n − 1`, until it reaches 1.

```cpp
#include <iostream>
using namespace std;

int factorial(int n) {
    if (n <= 1) return 1;            // base case
    return n * factorial(n - 1);     // recursive case
}

int main() {
    cout << factorial(3) << endl;
    cout << factorial(5) << endl;
    return 0;
}
```

**Output:**
```
6
120
```

### Example 3: Sum From 1 to n

This has the same shape as factorial, but it adds instead of multiplies. The base case returns `0`.

```cpp
#include <iostream>
using namespace std;

int sumTo(int n) {
    if (n == 0) return 0;          // base case
    return n + sumTo(n - 1);       // recursive case
}

int main() {
    cout << sumTo(4) << endl;      // 4 + 3 + 2 + 1 + 0
    return 0;
}
```

**Output:**
```
10
```

`sumTo(4)` = 4 + `sumTo(3)` = 4 + 3 + `sumTo(2)` … down to `sumTo(0)`, which returns 0.

---

## 5. Recursion vs. Iteration

Many problems can be solved with **either** a loop (iteration) or recursion. Below, both versions compute a factorial.

**Loop version:**
```cpp
int factLoop(int n) {
    int result = 1;
    for (int i = 2; i <= n; i++)
        result *= i;
    return result;
}
```

**Recursive version:**
```cpp
int factRec(int n) {
    if (n <= 1) return 1;
    return n * factRec(n - 1);
}
```

| Aspect | Loop (iteration) | Recursion |
|--------|------------------|-----------|
| Speed | Usually faster | Slightly slower (call overhead) |
| Memory | Constant | Uses the call stack (one frame per call) |
| Readability | Good for counting | Clearer for "smaller copies of itself" |
| Risk | Infinite loop | Stack overflow (no base case) |

**Rule of thumb:** if a loop is obvious and simple, use it. Use recursion when the problem is naturally recursive and the recursive version is easier to read.

---

## 6. Common Mistakes

**1. No base case**

**Wrong:**
```cpp
int bad(int n) {
    return n + bad(n - 1);   // never stops
}
```

**Correct:**
```cpp
int good(int n) {
    if (n == 0) return 0;    // base case stops it
    return n + good(n - 1);
}
```

**Explanation:** without a base case the function calls itself forever, the call stack fills up, and the program crashes with a **stack overflow**.

**2. The input never gets smaller**

**Wrong:**
```cpp
int sumTo(int n) {
    if (n == 0) return 0;
    return n + sumTo(n);     // still n, never reaches 0
}
```

**Correct:**
```cpp
int sumTo(int n) {
    if (n == 0) return 0;
    return n + sumTo(n - 1); // moves toward the base case
}
```

**Explanation:** each recursive call must move closer to the base case. Calling `sumTo(n)` again with the same `n` never stops.

**3. Checking the base case too late**

**Wrong:**
```cpp
void countdown(int n) {
    cout << n << " ";
    countdown(n - 1);        // recurses before checking
    if (n == 0) return;      // too late
}
```

**Correct:**
```cpp
void countdown(int n) {
    if (n == 0) return;      // check first
    cout << n << " ";
    countdown(n - 1);
}
```

**Explanation:** the base case must be checked **before** the recursive call, otherwise the function recurses past the stopping point.

**4. Forgetting to return the recursive result**

**Wrong:**
```cpp
int factorial(int n) {
    if (n <= 1) return 1;
    n * factorial(n - 1);    // result is thrown away
}
```

**Correct:**
```cpp
int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);   // return the value
}
```

**Explanation:** a non-`void` function must `return` its computed value. Without `return`, the function produces a meaningless result.

**5. Wrong base-case value**

**Wrong:**
```cpp
int factorial(int n) {
    if (n == 0) return 0;          // 0 makes everything 0
    return n * factorial(n - 1);
}
```

**Correct:**
```cpp
int factorial(int n) {
    if (n <= 1) return 1;          // multiplying identity is 1
    return n * factorial(n - 1);
}
```

**Explanation:** because the results are multiplied, the base case must return `1`. Returning `0` would make every answer `0`.

---

## 7. Practice Exercises

Try each one before opening the solution. Each solution is a complete, runnable function.

**Exercise 1.** Write a recursive `int power(int base, int exp)` that returns `base` raised to `exp`. (Base case: `exp == 0` returns 1.)

<details>
<summary>Click to see solution</summary>

```cpp
int power(int base, int exp) {
    if (exp == 0) return 1;            // base case
    return base * power(base, exp - 1);
}
// power(2, 3) -> 8
```
</details>

**Exercise 2.** Write a recursive `void printDown(int n)` that prints `n, n-1, ..., 1`.

<details>
<summary>Click to see solution</summary>

```cpp
void printDown(int n) {
    if (n == 0) return;     // base case
    cout << n << " ";       // print first
    printDown(n - 1);       // then recurse
}
// printDown(4) -> 4 3 2 1
```
</details>

**Exercise 3.** Write a recursive `void printUp(int n)` that prints `1, 2, ..., n`. *(Hint: recurse first, then print.)*

<details>
<summary>Click to see solution</summary>

```cpp
void printUp(int n) {
    if (n == 0) return;     // base case
    printUp(n - 1);         // recurse FIRST
    cout << n << " ";       // then print
}
// printUp(4) -> 1 2 3 4
```

Printing *after* the recursive call reverses the order, so the numbers come out smallest first.
</details>

**Exercise 4.** Write a recursive `int countDigits(int n)` that returns how many digits a positive number has. *(Hint: `n / 10` removes the last digit.)*

<details>
<summary>Click to see solution</summary>

```cpp
int countDigits(int n) {
    if (n < 10) return 1;            // base case: one digit
    return 1 + countDigits(n / 10);
}
// countDigits(572) -> 3
```
</details>

**Exercise 5.** Write a recursive `int fib(int n)` that returns the n-th Fibonacci number. (Base cases: `fib(0)=0`, `fib(1)=1`.)

<details>
<summary>Click to see solution</summary>

```cpp
int fib(int n) {
    if (n <= 1) return n;        // fib(0)=0, fib(1)=1
    return fib(n - 1) + fib(n - 2);  // two recursive calls
}
// fib(6) -> 8
```

Note: this makes **two** recursive calls each time, so it does a lot of repeated work for large `n`.
</details>

**Exercise 6.** Write a recursive `int multiply(int a, int b)` that multiplies using repeated addition. (Base case: `b == 0` returns 0.)

<details>
<summary>Click to see solution</summary>

```cpp
int multiply(int a, int b) {
    if (b == 0) return 0;          // base case
    return a + multiply(a, b - 1);
}
// multiply(4, 3) -> 12
```
</details>

---

## 8. Summary

### Key Concepts

- Recursion is a function that **calls itself** on a smaller version of the same problem.
- A recursive function needs a **base case** (to stop) and a **recursive case** (to shrink the problem).
- Paused calls pile up on the **call stack**, then return values back up once the base case is reached.

### Important Points

1. Always write the base case first.
2. Make sure the input gets **smaller** on every recursive call.
3. A non-`void` function must `return` the result of the recursive call.
4. Choose the base-case value carefully (e.g., `1` for products, `0` for sums).
5. Recursion and loops can often solve the same problem — pick the clearer one.
6. Loops are usually faster and use less memory; recursion is clearer for naturally recursive problems.
7. No base case (or input that never shrinks) causes a **stack overflow** crash.

### Quick Reference

```cpp
returnType functionName(parameters) {
    if (/* base case condition */) {
        return /* simple answer */;          // stops the recursion
    }
    // do one step, then call on a SMALLER input
    return /* combine */ functionName(/* smaller input */);
}
```

### Next Steps

You now have the full beginner toolkit: input/output, decisions, loops, arrays, strings, functions, and recursion. A natural next step is applying recursion to data structures and to simple algorithms such as binary search and merge sort.
