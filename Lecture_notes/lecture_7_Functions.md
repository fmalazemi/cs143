# CS143 — Lecture 7: Functions (No Recursion)

> **Instructor:** Dr. Fawaz Alazemi
> **Audience:** Students who completed CS101 (Python)
> **Note:** Recursion (a function that calls itself) is covered in a later lecture.

## Table of Contents

1. [Introduction](#introduction)
2. [From Python to C++](#from-python-to-c)
3. [Why Use Functions?](#why-use-functions)
4. [Anatomy of a Function](#anatomy-of-a-function)
5. [Calling a Function](#calling-a-function)
6. [Parameters and Arguments](#parameters-and-arguments)
7. [Returning a Value vs. void](#returning-a-value-vs-void)
8. [Function Prototypes](#function-prototypes)
9. [Pass by Value vs. Pass by Reference](#pass-by-value-vs-pass-by-reference)
10. [Local Scope](#local-scope)
11. [Python vs. C++ Comparison](#python-vs-c-comparison)
12. [Common Mistakes](#common-mistakes)
13. [Practice Exercises](#practice-exercises)
14. [Summary](#summary)

---

## Introduction

A **function** is a named block of code that performs one job. You give it inputs, it does its work, and it may hand back a result. Functions let you write a piece of logic once and reuse it as many times as you like.

**Why functions matter:**

- They remove repeated code, so you write the logic only once.
- They let you fix a bug in one place instead of many.
- They break a long program into small, named pieces that are easy to read.
- They make your code easier to test and to share.

**Real-world analogies:**

- A **vending machine:** you put money in (input), it gives you a snack (output).
- A **recipe:** you provide ingredients (parameters) and follow the steps to produce a dish (result).
- A **black box:** you do not need to know the inside; you only need to know what goes in and what comes out.

**When to use:** any time a task is repeated, or any time a block of `main` would be clearer if it had a name.

---

## From Python to C++

You already wrote functions in CS101 using `def`. C++ uses the same idea, but you must state the **types**: the type the function returns, and the type of each input.

**Python:**

```python
def add(a, b):
    return a + b

print(add(2, 3))   # 5
```

**C++:**

```cpp
#include <iostream>
using namespace std;

int add(int a, int b) {   // int = return type; int a, int b = typed inputs
    return a + b;
}

int main() {
    cout << add(2, 3) << endl;   // 5
    return 0;
}
```

**Output:**
```
5
```

The new parts compared to Python are the **return type** (`int`) written before the name, and a **type for every parameter**.

---

## Why Use Functions?

| Without functions | With functions |
|---|---|
| The same code is copied many times | Write the logic once, use it anywhere |
| A fix must be made in every copy | Fix a bug in one place |
| One long `main` is hard to read | Each function has a clear, named job |

Think of a function as a small machine: you give it inputs, it does a job, and it may return a result.

---

## Anatomy of a Function

```cpp
int square(int x) {     // header: return type, name, parameter
    return x * x;       // body: the work, then a result
}
```

| Part | Example | Meaning |
|---|---|---|
| Return type | `int` | the kind of value the function gives back |
| Name | `square` | how you call it later |
| Parameters | `(int x)` | the inputs, each with a type |
| `return` | `return x * x;` | sends a value back to the caller |

---

## Calling a Function

When you call a function, the program jumps into it, runs its body, then comes back with the returned value.

```
main()                          int square(int x)
  cout << square(5);  --- call with 5 -->   return x * x;
                      <-- return 25 ----
```

```cpp
#include <iostream>
using namespace std;

int square(int x) {
    return x * x;
}

int main() {
    cout << square(5) << endl;   // square(5) becomes 25
    return 0;
}
```

**Output:**
```
25
```

The expression `square(5)` is replaced by the value `25`, which is then printed.

---

## Parameters and Arguments

A **parameter** is the named input inside the function. An **argument** is the real value you pass when you call it.

```cpp
#include <iostream>
using namespace std;

// a and b are PARAMETERS
int add(int a, int b) {
    return a + b;
}

int main() {
    // 2 and 3 are ARGUMENTS
    cout << add(2, 3) << endl;    // 5
    cout << add(10, 7) << endl;   // 17
    return 0;
}
```

**Output:**
```
5
17
```

The number and types of arguments must match the parameters in the function header.

---

## Returning a Value vs. void

A function whose return type is **not** `void` must use `return` to give back a value. A `void` function does a job but returns nothing.

**Returns a value:**

```cpp
int twice(int x) {
    return x * 2;     // hands back a number
}
// usage: int y = twice(6);   // y is 12
```

**Returns nothing (`void`):**

```cpp
#include <iostream>
using namespace std;

void greet() {
    cout << "Hello!" << endl;   // just does a job
}

int main() {
    greet();
    return 0;
}
```

**Output:**
```
Hello!
```

---

## Function Prototypes

C++ reads a file from top to bottom. It must know a function **before** you call it. A **prototype** is a one-line promise that gives the function's shape: return type, name, and parameter types, ending with a semicolon.

```cpp
#include <iostream>
using namespace std;

int add(int a, int b);   // prototype (declared before use)

int main() {
    cout << add(2, 3) << endl;
    return 0;
}

int add(int a, int b) {  // full definition comes later
    return a + b;
}
```

**Output:**
```
5
```

**Shortcut:** if you write the whole function above `main`, you do not need a separate prototype.

---

## Pass by Value vs. Pass by Reference

**By value** (no `&`): the function receives a **copy** of the input. Changing it does not affect the original.

**By reference** (`int &x`): the function shares the **same** variable. A change inside the function is seen outside.

```
By value (a copy):        By reference (same box):
  main: x = [5]             main: x ─┐
  func: x = [5] (copy)               ├─ [5]  (shared)
                            func: x ─┘
```

**Example 1 — Largest of Two (returns `int`):**

```cpp
#include <iostream>
using namespace std;

int maxOfTwo(int a, int b) {
    if (a > b) return a;
    else       return b;
}

int main() {
    cout << maxOfTwo(8, 3) << endl;   // 8
    cout << maxOfTwo(4, 9) << endl;   // 9
    return 0;
}
```

**Output:**
```
8
9
```

**Example 2 — A Row of Stars (`void`):**

```cpp
#include <iostream>
using namespace std;

void printStars(int n) {
    for (int i = 0; i < n; i++) {
        cout << "*";
    }
    cout << endl;
}

int main() {
    printStars(3);
    printStars(6);
    return 0;
}
```

**Output:**
```
***
******
```

**Example 3 — Is It Even? (returns `bool`):**

```cpp
#include <iostream>
using namespace std;

bool isEven(int n) {
    return (n % 2 == 0);
}

int main() {
    int x;
    cin >> x;
    if (isEven(x))
        cout << x << " is even" << endl;
    else
        cout << x << " is odd" << endl;
    return 0;
}
```

**Output (input `7`):**
```
7 is odd
```

**Example 4 — Swap (needs references):**

```cpp
#include <iostream>
using namespace std;

void swap(int &a, int &b) {   // references share the originals
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 1, y = 2;
    swap(x, y);
    cout << x << " " << y << endl;
    return 0;
}
```

**Output:**
```
2 1
```

Without the `&`, `swap` would only exchange copies and `main` would still print `1 2`.

---

## Local Scope

A variable declared inside a function is **local** to it: it exists only there, and it disappears when the function ends.

```cpp
#include <iostream>
using namespace std;

void demo() {
    int x = 99;        // local to demo
    cout << x << endl;
}

int main() {
    int x = 5;         // a different x, local to main
    demo();            // prints 99
    cout << x << endl; // prints 5
    return 0;
}
```

**Output:**
```
99
5
```

The two `x` variables are completely separate.

---

## Python vs. C++ Comparison

| Idea | Python | C++ |
|---|---|---|
| Define | `def add(a, b):` | `int add(int a, int b) {` |
| Return a value | `return a + b` | `return a + b;` |
| Return type | not stated | written before the name |
| Parameter types | not stated | written for each one |
| No return value | returns `None` | `void` |
| Declare before use | not needed | needed (prototype) |

**Takeaway:** the concept of inputs and outputs is the same; C++ asks you to state the types and to declare a function before you call it.

---

## Common Mistakes

**1. Missing return type**

**Wrong:**
```cpp
add(int a, int b) {     // no return type
    return a + b;
}
```
**Correct:**
```cpp
int add(int a, int b) {
    return a + b;
}
```
**Explanation:** Every C++ function needs a return type (`int`, `double`, `void`, …). Without one the program will not compile.

**2. Forgetting to return a value**

**Wrong:**
```cpp
int square(int x) {
    int result = x * x;   // computed but never returned
}
```
**Correct:**
```cpp
int square(int x) {
    return x * x;
}
```
**Explanation:** A function with a non-`void` return type must use `return` to hand a value back.

**3. Calling a function before it is known**

**Wrong:**
```cpp
int main() {
    cout << add(2, 3);   // add not declared yet
}
int add(int a, int b) { return a + b; }
```
**Correct:**
```cpp
int add(int a, int b);   // prototype first

int main() {
    cout << add(2, 3);
}
int add(int a, int b) { return a + b; }
```
**Explanation:** C++ reads top to bottom. Define the function first, or add a prototype before `main`.

**4. Forgetting the parentheses when calling**

**Wrong:**
```cpp
greet;     // does nothing
```
**Correct:**
```cpp
greet();   // actually calls the function
```
**Explanation:** A function call needs `()`, even when there are no arguments.

**5. Expecting a by-value parameter to change the original**

**Wrong:**
```cpp
void addOne(int x) {   // x is a copy
    x = x + 1;         // original is not changed
}
```
**Correct:**
```cpp
void addOne(int &x) {  // x is a reference
    x = x + 1;         // original IS changed
}
```
**Explanation:** Use a reference (`&`) when the function should change the caller's variable.

---

## Practice Exercises

**Exercise 1.** Write a function `int cube(int x)` that returns `x` cubed, and call it in `main`.
*Expected:* `cube(3)` prints `27`.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int cube(int x) {
    return x * x * x;
}

int main() {
    cout << cube(3) << endl;   // 27
    return 0;
}
```
</details>

**Exercise 2.** Write a `void` function `printLine(int n)` that prints `n` dash characters on one line.
*Expected:* `printLine(5)` prints `-----`.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

void printLine(int n) {
    for (int i = 0; i < n; i++)
        cout << "-";
    cout << endl;
}

int main() {
    printLine(5);   // -----
    return 0;
}
```
</details>

**Exercise 3.** Write `int maxOfThree(int a, int b, int c)` that returns the largest of three numbers.
*Expected:* `maxOfThree(4, 9, 7)` returns `9`.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int maxOfThree(int a, int b, int c) {
    int m = a;
    if (b > m) m = b;
    if (c > m) m = c;
    return m;
}

int main() {
    cout << maxOfThree(4, 9, 7) << endl;   // 9
    return 0;
}
```
</details>

**Exercise 4.** Write `bool isPositive(int n)` that returns `true` when `n` is greater than 0, and use it inside an `if`.
*Expected:* input `5` prints `Positive`.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

bool isPositive(int n) {
    return (n > 0);
}

int main() {
    int x;
    cin >> x;
    if (isPositive(x))
        cout << "Positive" << endl;
    else
        cout << "Not positive" << endl;
    return 0;
}
```
</details>

**Exercise 5.** Write `double average(int a, int b, int c)` that returns the average of three numbers.
*Expected:* `average(2, 3, 5)` returns about `3.33333`.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

double average(int a, int b, int c) {
    return (a + b + c) / 3.0;   // 3.0 keeps the decimals
}

int main() {
    cout << average(2, 3, 5) << endl;   // 3.33333
    return 0;
}
```
</details>

**Exercise 6.** Write a `void` function `swap(int &a, int &b)` that swaps two values, and show it works in `main`.
*Expected:* starting from `x = 1, y = 2`, the program prints `2 1`.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 1, y = 2;
    swap(x, y);
    cout << x << " " << y << endl;   // 2 1
    return 0;
}
```
</details>

---

## Summary

### Key Concepts

- A function is a named block of code with a return type, a name, parameters, and a body.
- Calling a function jumps into it and returns with a value.
- `void` functions do a job but return nothing; other functions must `return` a value.
- Parameters can be passed by value (a copy) or by reference (the original).
- Variables declared inside a function are local to it.

### Important Points

1. Every function needs a return type.
2. A non-`void` function must return a value of that type.
3. Declare a function before you call it — define it first or use a prototype.
4. The number and types of arguments must match the parameters.
5. A function call always needs parentheses `()`.
6. Use a reference (`&`) when the function should change the caller's variable.
7. Local variables disappear when the function ends.

### Quick Reference

```cpp
// return-a-value function
returnType name(type p1, type p2) {
    // ... work ...
    return value;     // required for non-void
}

// void function (no value returned)
void name(type p1) {
    // ... work ...
}

// prototype (declare before use)
returnType name(type p1, type p2);

// pass by reference (can change the caller's variable)
void name(int &x);
```

### Next Steps

The next topic is **recursion** — a function that calls itself to solve a problem in smaller pieces.
