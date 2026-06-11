# CS143 — Lecture 9: Types, Scope &amp; Casting

> **Course:** CS143 Introduction to C++ · **Instructor:** Dr. Fawaz Alazemi
> **Audience:** Students who completed CS101 (Python). Assumes only basic Python (variables, `if`, loops, functions).
> **Builds on:** Lecture 1 (variables) and Lecture 7 (functions).

---

## Table of Contents

1. [Introduction](#1-introduction)
2. [Variable Types](#2-variable-types)
3. [Scope: Local and Global Variables](#3-scope-local-and-global-variables)
   - [Local and Block Scope](#local-and-block-scope)
   - [Global Variables](#global-variables)
   - [Shadowing](#shadowing)
4. [Overflow and Underflow](#4-overflow-and-underflow)
   - [Overflow](#overflow)
   - [Underflow](#underflow)
5. [Casting (Type Conversion)](#5-casting-type-conversion)
   - [Implicit Conversion](#implicit-conversion)
   - [Explicit Casting](#explicit-casting)
   - [The Integer-Division Trap](#the-integer-division-trap)
6. [Common Mistakes](#6-common-mistakes)
7. [Practice Exercises](#7-practice-exercises)
8. [Summary](#8-summary)

---

## 1. Introduction

In Python, a variable can hold any kind of value and can change type at any time. C++ is different: you choose a **type** when you declare a variable, and the variable keeps that type for its whole life. This is called **static typing**.

```python
# Python (dynamic)
x = 5        # an int now
x = "hello"  # a string now — allowed
```

```cpp
// C++ (static)
int x = 5;       // x is an int, always
// x = "hello";  // ERROR: wrong type
```

**Why this matters:**

- A fixed type fixes the **size** (in bytes) and the **range** (smallest to largest value) of a variable.
- That size limit is the cause of **overflow** and **underflow**.
- Mixing types forces **conversions**, which can quietly change or lose data.
- Knowing **scope** tells you where a variable can be used and when it disappears.

This lecture connects these four ideas: types, scope, overflow/underflow, and casting.

---

## 2. Variable Types

C++ has several built-in types. Each one stores a particular kind of value and takes a fixed amount of memory.

| Type | Typical size | Holds | Example |
|------|--------------|-------|---------|
| `int` | 4 bytes | whole numbers | `42` |
| `long long` | 8 bytes | very large whole numbers | `9000000000` |
| `double` | 8 bytes | decimal numbers | `3.14159` |
| `float` | 4 bytes | smaller decimals | `3.14f` |
| `char` | 1 byte | a single character | `'A'` |
| `bool` | 1 byte | `true` or `false` | `true` |
| `string` | varies | text | `"Sara"` |

A 4-byte `int` can hold roughly −2.1 billion to +2.1 billion. If you need larger whole numbers, use `long long`.

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    int age = 20;          // whole number
    double price = 4.50;   // decimal number
    char grade = 'A';      // one character
    bool passed = true;    // true / false
    string name = "Sara";  // text

    cout << name << " " << age << " " << grade << endl;
    return 0;
}
```

**Output:**
```
Sara 20 A
```

**Choosing a type:** pick the smallest type that fits your data. Use `int` for counting, `double` for money or measurements, `char` for one letter, and `string` for words.

---

## 3. Scope: Local and Global Variables

**Scope** is the region of code where a variable can be used. A variable exists only inside the braces `{ }` where it was declared.

### Local and Block Scope

A **local** variable is declared inside a function or block. It is visible only there, and it disappears when the block ends.

```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 10;        // local to main
    {
        int y = 20;    // local to this block only
        cout << x << " " << y << endl;   // both visible here
    }
    cout << x << endl;  // y does NOT exist here
    return 0;
}
```

**Output:**
```
10 20
10
```

Think of scopes as nested boxes: an inner box can see the variables of the boxes around it, but the outer boxes cannot see inside the inner box.

### Global Variables

A **global** variable is declared outside every function. Every function can read and change it, and it lives for the whole run of the program.

```cpp
#include <iostream>
using namespace std;

int counter = 0;   // global: declared outside all functions

void addOne() {
    counter++;      // any function can use the global
}

int main() {
    addOne();
    addOne();
    cout << counter << endl;
    return 0;
}
```

**Output:**
```
2
```

Use globals sparingly. When many functions change one global, bugs become hard to trace.

### Shadowing

If a local variable has the same name as a global variable, the local one is used inside that function. This is called **shadowing**, and the global is left untouched.

```cpp
#include <iostream>
using namespace std;

int x = 100;        // global x

void show() {
    int x = 5;      // local x hides the global
    cout << "Inside: " << x << endl;
}

int main() {
    show();
    cout << "Global: " << x << endl;
    return 0;
}
```

**Output:**
```
Inside: 5
Global: 100
```

To avoid confusion, do not reuse the same name for a local and a global variable.

---

## 4. Overflow and Underflow

Because each type has a fixed size, it can hold only a limited range of values. Going outside that range causes a wrong result.

### Overflow

**Overflow** happens when a value goes past the **maximum** the type can hold. The value wraps around to the minimum, like a car odometer rolling over from its highest number back to zero.

```cpp
#include <iostream>
using namespace std;

int main() {
    int big = 2147483647;       // the largest int
    cout << big + 1 << endl;     // overflow!

    long long safe = 2147483647;
    cout << safe + 1 << endl;    // plenty of room
    return 0;
}
```

**Output:**
```
-2147483648
2147483648
```

Adding 1 to the largest `int` wraps to the most negative number. The `long long` version has room, so it stays correct. **Fix:** choose a type big enough for the values you expect.

### Underflow

**Underflow** is the opposite: a value is too small to store. This happens in two ways.

An **unsigned** type cannot be negative, so going below 0 wraps to its largest value:

```cpp
#include <iostream>
using namespace std;

int main() {
    unsigned int u = 0;
    cout << u - 1 << endl;   // wraps to the top
    return 0;
}
```

**Output:**
```
4294967295
```

A `double` can also be so small that the computer cannot store it, so it becomes `0`. In short: overflow is "too big to fit," and underflow is "too small to fit."

---

## 5. Casting (Type Conversion)

**Casting** means changing a value from one type to another. Some conversions happen automatically; others you write on purpose.

### Implicit Conversion

C++ converts some types automatically. Going from a smaller type to a larger one (**widening**) is safe.

```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 5;
    double d = a;       // int -> double (automatic)
    cout << d << endl;

    double pi = 3.9;
    int n = pi;         // double -> int: decimals DROPPED
    cout << n << endl;
    return 0;
}
```

**Output:**
```
5
3
```

Going from `double` to `int` (**narrowing**) **truncates** the value: it cuts off the decimal part, it does **not** round. So `3.9` becomes `3`.

### Explicit Casting

You can cast on purpose in two ways. The `static_cast` form is preferred in C++ because it is clearer and safer.

```cpp
#include <iostream>
using namespace std;

int main() {
    double pi = 3.9;
    int a = (int)pi;                 // C-style cast
    int b = static_cast<int>(pi);    // C++ style
    cout << a << " " << b << endl;
    return 0;
}
```

**Output:**
```
3 3
```

### The Integer-Division Trap

When both sides of a division are `int`, C++ performs integer division and throws away the fraction. Cast one value to `double` to keep the decimals.

```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 7, b = 2;
    cout << a / b << endl;             // 3  (wrong!)
    cout << (double)a / b << endl;     // 3.5
    cout << static_cast<double>(a) / b << endl;  // 3.5
    return 0;
}
```

**Output:**
```
3
3.5
3.5
```

This is one of the most common surprises for students coming from Python, where `7 / 2` already gives `3.5`.

---

## 6. Common Mistakes

**1. Integer division loses the fraction**

**Wrong:**
```cpp
double avg = (a + b) / 2;    // both int -> integer division
```

**Correct:**
```cpp
double avg = (double)(a + b) / 2;   // cast first
```

**Explanation:** when both operands are `int`, the division drops the fraction *before* it is stored in the `double`. Cast to `double` first so the decimals survive.

**2. Assuming `int` never overflows**

**Wrong:**
```cpp
int total = 2000000000 + 2000000000;   // overflow
```

**Correct:**
```cpp
long long total = 2000000000LL + 2000000000LL;
```

**Explanation:** the sum is larger than an `int` can hold, so it wraps to a wrong (often negative) value. Use `long long` for large numbers.

**3. Expecting `double` → `int` to round**

**Wrong:**
```cpp
int n = 3.9;    // expecting 4
```

**Correct:**
```cpp
int n = (int)(3.9 + 0.5);   // add 0.5 to round, then cast -> 4
```

**Explanation:** casting to `int` truncates (drops the decimals), it does not round. Add `0.5` before casting if you want rounding for positive numbers.

**4. Using a variable out of scope**

**Wrong:**
```cpp
{
    int y = 20;
}
cout << y;     // ERROR: y does not exist here
```

**Correct:**
```cpp
int y = 20;    // declare in the scope where you need it
{
    // use y here
}
cout << y;     // OK
```

**Explanation:** a variable exists only inside the braces where it was declared. Declare it in a wide enough scope for where you use it.

**5. Mixing signed and unsigned**

**Wrong:**
```cpp
unsigned int u = 0;
cout << u - 1;     // huge number, not -1
```

**Correct:**
```cpp
int u = 0;
cout << u - 1;     // -1, as expected
```

**Explanation:** an `unsigned` value cannot be negative, so `0 - 1` underflows to a very large number. Use a signed type when values can go below zero.

---

## 7. Practice Exercises

Try each one before opening the solution.

**Exercise 1.** Declare one variable of each type (`int`, `double`, `char`, `bool`, `string`), give each a value, and print them with labels.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    int age = 20;
    double price = 4.5;
    char grade = 'A';
    bool ok = true;
    string name = "Sara";
    cout << age << " " << price << " " << grade
         << " " << ok << " " << name << endl;
    return 0;
}
```
**Output:** `20 4.5 A 1 Sara`
</details>

**Exercise 2.** Read two integers and print their average as a decimal number (cast so you do not lose the fraction).

<details>
<summary>Click to see solution</summary>

```cpp
int a, b;
cin >> a >> b;
cout << (double)(a + b) / 2 << endl;
// 3 and 4 -> 3.5
```
</details>

**Exercise 3.** Read a `double` and print it cast to an `int`. In a comment, say whether it rounds or truncates.

<details>
<summary>Click to see solution</summary>

```cpp
double d;
cin >> d;
int n = (int)d;   // truncates: drops the decimals (does NOT round)
cout << n << endl;
// 3.9 -> 3
```
</details>

**Exercise 4.** Set an `int` to its maximum (2147483647), add 1, and print it. Then do the same with `long long` and compare.

<details>
<summary>Click to see solution</summary>

```cpp
int big = 2147483647;
cout << big + 1 << endl;     // -2147483648 (overflow)

long long safe = 2147483647;
cout << safe + 1 << endl;    // 2147483648 (correct)
```
</details>

**Exercise 5.** Create a global `count = 100`. In a function, make a local `count = 5` and print it; print the global from `main`. Observe shadowing.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int count = 100;            // global

void f() {
    int count = 5;         // local hides the global
    cout << count << endl; // 5
}

int main() {
    f();
    cout << count << endl; // 100
    return 0;
}
```
**Output:**
```
5
100
```
</details>

**Exercise 6.** Read a character and print its integer (ASCII) code by casting `char` to `int`.

<details>
<summary>Click to see solution</summary>

```cpp
char c;
cin >> c;
int code = (int)c;   // cast char to int
cout << c << " = " << code << endl;
// 'A' -> A = 65
```
</details>

---

## 8. Summary

### Key Concepts

- C++ is **statically typed**: each variable has a fixed type, size, and range.
- **Scope** decides where a variable can be used; **local** stays in its braces, **global** is everywhere.
- **Overflow** is going past the maximum; **underflow** is going below the minimum or too close to zero.
- **Casting** converts a value from one type to another, automatically or on purpose.

### Important Points

1. Choose the smallest type that fits your data; use `long long` for very large whole numbers.
2. A variable exists only inside the braces where it was declared.
3. Avoid unnecessary globals, and avoid giving a local the same name as a global (shadowing).
4. Adding past a type's maximum wraps around — the result becomes wrong.
5. Converting `double` to `int` **truncates**; it does not round.
6. Cast one operand to `double` before dividing to keep the fraction.
7. Do not mix signed and unsigned values when a result could be negative.

### Quick Reference

```cpp
int n = 5;                     // whole number
double d = 5;                  // widening: 5 -> 5.0 (automatic)
int t = (int)3.9;              // narrowing: 3.9 -> 3 (truncates)
int s = static_cast<int>(3.9); // preferred C++ cast -> 3
double avg = (double)a / b;    // keep decimals in division
long long big = 9000000000LL;  // avoid int overflow
```

### Next Steps

With types, scope, and conversions understood, you are ready to combine them safely in larger programs and to explore more advanced types and data structures.
