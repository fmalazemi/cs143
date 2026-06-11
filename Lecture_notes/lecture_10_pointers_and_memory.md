# CS143 — Lecture 10: Pointers &amp; Memory

> **Course:** CS143 Introduction to C++ · **Instructor:** Dr. Fawaz Alazemi
> **Audience:** Students who completed CS101 (Python). Assumes only basic Python (variables, `if`, loops, functions).
> **Builds on:** Lecture 6 (arrays in memory), Lecture 7 (references), Lecture 9 (scope).

---

## Table of Contents

1. [Introduction](#1-introduction)
2. [What Is a Pointer?](#2-what-is-a-pointer)
3. [Address-of and Dereference](#3-address-of-and-dereference)
4. [Pointers and Functions](#4-pointers-and-functions)
5. [Pointers and Arrays](#5-pointers-and-arrays)
6. [Pointers vs. References](#6-pointers-vs-references)
7. [Static and Dynamic Memory](#7-static-and-dynamic-memory)
8. [Static Memory: The Stack](#8-static-memory-the-stack)
9. [Dynamic Memory: new and delete](#9-dynamic-memory-new-and-delete)
10. [Dynamic Arrays](#10-dynamic-arrays)
11. [Data That Outlives a Function](#11-data-that-outlives-a-function)
12. [Common Mistakes](#12-common-mistakes)
13. [Practice Exercises](#13-practice-exercises)
14. [Summary](#14-summary)

---

## 1. Introduction

Every variable in a program lives somewhere in memory, at a numbered location called its **address**. You saw this in Lecture 6: the boxes of an array sit at addresses that increase by the size of each element.

A **pointer** is a variable that stores an address. Instead of holding a number like `42`, it holds *where* a `42` is kept. That one idea unlocks three things:

- A function can **change** a variable that belongs to its caller.
- You can **walk through arrays** efficiently.
- You can use **dynamic memory** — ask for space while the program runs.

**The plan for this lecture:**

- **Part A — Pointers:** what they are and how to use them.
- **Part B — Static and Dynamic Memory:** the two places data lives — the **stack** (static) and the **heap** (dynamic).

**Python note:** Python hides addresses and frees memory for you. C++ lets you work with both directly — powerful, but it requires care.

---

## 2. What Is a Pointer?

A pointer stores the address of another variable. Below, `p` points to `x`: it holds the address where `x` lives, not the value `42` itself.

```
   p (a pointer)            x (an int)
 +------------+           +------------+
 |    1000    | --------> |     42     |
 +------------+           +------------+
 lives at 2000            lives at 1000
```

```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 42;
    int *p = &x;        // p stores the address of x

    cout << x  << endl; // 42       (the value)
    cout << &x << endl; // address  (e.g. 0x7ffd...)
    cout << p  << endl; // same address as &x
    return 0;
}
```

**Output:**
```
42
0x7ffd1234abcd
0x7ffd1234abcd
```

(The exact address differs every run; the point is that `p` and `&x` print the **same** address.) The declaration `int *p;` means "`p` is a pointer to an `int`" — the `*` marks it as a pointer.

---

## 3. Address-of and Dereference

Pointers use two operators that are opposites of each other.

| Operator | Name | Meaning |
|----------|------|---------|
| `&x` | address-of | gives the address of `x` |
| `*p` | dereference | gives the value stored at the address in `p` |

**Dereferencing** means "follow the pointer to the value it points to." You can read *and* write through it.

```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 42;
    int *p = &x;        // p points to x

    cout << *p << endl; // 42  (read the value via the pointer)

    *p = 100;           // change x THROUGH the pointer
    cout << x << endl;  // 100 (x itself changed)
    return 0;
}
```

**Output:**
```
42
100
```

Because `p` points to `x`, writing `*p = 100` changes `x` itself. The pointer and the variable share the same box.

**Null pointers.** A pointer that points to nothing should be set to `nullptr`. Never dereference a null pointer — it crashes the program.

```cpp
int *p = nullptr;        // points to nothing
if (p != nullptr) {
    cout << *p << endl;  // only use it if valid
}
```

---

## 4. Pointers and Functions

In Lecture 7 you used a **reference** to let a function change the caller's variable. A pointer does the same job: pass the **address**, and the function can change the original through it.

```cpp
#include <iostream>
using namespace std;

void addOne(int *p) {
    *p = *p + 1;     // change the original through the pointer
}

int main() {
    int n = 5;
    addOne(&n);       // pass the address of n
    cout << n << endl;
    return 0;
}
```

**Output:**
```
6
```

A very common use is swapping two values:

```cpp
#include <iostream>
using namespace std;

void swap(int *a, int *b) {
    int temp = *a;   // save the value a points to
    *a = *b;         // a's box gets b's value
    *b = temp;       // b's box gets the saved value
}

int main() {
    int x = 1, y = 2;
    swap(&x, &y);    // pass both addresses
    cout << x << " " << y << endl;
    return 0;
}
```

**Output:**
```
2 1
```

---

## 5. Pointers and Arrays

An array's name is really the **address of its first element**. So a pointer can step through an array.

```
   p             arr[0]   arr[1]   arr[2]
 +------+       +------+ +------+ +------+
 | 1000 | ----> |  10  | |  20  | |  30  |
 +------+       +------+ +------+ +------+
                  1000     1004     1008
```

```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[3] = {10, 20, 30};
    int *p = arr;        // arr is the address of arr[0]

    for (int i = 0; i < 3; i++) {
        cout << *(p + i) << " ";  // value at p + i
    }
    cout << endl;
    return 0;
}
```

**Output:**
```
10 20 30
```

Adding `i` to a pointer moves it `i` elements forward. In fact, `p[i]` means exactly the same as `*(p + i)` — array indexing is pointer math underneath.

---

## 6. Pointers vs. References

Pointers and references both let a function share a variable, but they differ in important ways.

| Feature | Reference (`&`) | Pointer (`*`) |
|---------|-----------------|---------------|
| What it is | another name for a variable | a variable holding an address |
| Must be set at start | yes, always | no (but it should be) |
| Can be null | no | yes (`nullptr`) |
| Can point elsewhere later | no | yes |
| Need `*` to read the value | no | yes (`*p`) |

**Guideline:** prefer a reference for simple sharing. Use a pointer when you need to repoint it, allow a "nothing" value, or manage dynamic memory — which is exactly where we go next.

---

## 7. Static and Dynamic Memory

A running C++ program uses memory in two main areas. They behave very differently.

| Area | Also called | Behaviour |
|------|-------------|-----------|
| **Static** | the **stack** | holds local variables; size fixed in the code; created and freed *for you*; fast but small |
| **Dynamic** | the **heap** | memory you request with `new`; size and lifetime chosen at run time; large and flexible, but *you* must free it |

A local pointer lives on the stack, but the value it points to (from `new`) lives on the heap:

```
            MEMORY
 +-------------------------+
 |  STACK (static)         |   p (pointer) ----+
 |  grows down  v          |                   |
 |- - - - - - - - - - - - -|                   |
 |  HEAP (dynamic)         |                   |
 |  grows up    ^          |   new int -> 50 <-+
 +-------------------------+
```

**Python note:** Python manages all of this automatically. C++ gives you the stack for free, but the heap is your responsibility.

---

## 8. Static Memory: The Stack

Local variables are placed on the **stack** automatically. They disappear when their `{ }` block ends — you do nothing.

```cpp
#include <iostream>
using namespace std;

void f() {
    int x = 5;        // x is created on the stack
    int arr[3];       // also on the stack
    cout << x << endl;
}                     // x and arr are freed automatically here

int main() {
    f();
    return 0;
}
```

**Output:**
```
5
```

Each function call gets its own stack **frame** (you saw this in recursion, Lecture 8). The stack is small, so a huge local array or very deep recursion causes a **stack overflow**.

---

## 9. Dynamic Memory: new and delete

The keyword `new` lets a program ask for memory **while it runs**, and returns a pointer to it. The keyword `delete` gives that memory back.

```cpp
#include <iostream>
using namespace std;

int main() {
    int *p = new int;    // reserve one int on the heap

    *p = 50;             // use it through the pointer
    cout << *p << endl;  // 50

    delete p;            // free the memory
    return 0;
}
```

**Output:**
```
50
```

Here is the lifetime difference between the two kinds of memory:

```cpp
int main() {
    { int s = 10; cout << s << endl; }   // s ends at the brace
    int *h = new int;
    *h = 20;
    cout << *h << endl;                  // lives until we delete
    delete h;
    return 0;
}
```

The stack variable `s` ends automatically at the closing brace. The heap value lives until *you* call `delete`. **Rule:** every `new` needs exactly one matching `delete`.

---

## 10. Dynamic Arrays

A fixed array needs a size known when you write the code. A **heap array** can have a size chosen *while the program runs*.

```cpp
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "How many? ";
    cin >> n;

    int *a = new int[n];     // size decided at run time!

    for (int i = 0; i < n; i++)
        a[i] = i * i;        // 0, 1, 4, 9, ...

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    delete[] a;              // free an ARRAY with delete[]
    return 0;
}
```

**Output (if the user types 5):**
```
How many? 5
0 1 4 9 16
```

A normal array cannot do this — its size must be fixed in the code. The heap lets the size come from input. Free an array with `delete[]`, not `delete`.

---

## 11. Data That Outlives a Function

A stack variable dies when its function ends, so you must never return the address of a local. To hand data back from a function, put it on the **heap**.

**Wrong — returns a dead address:**
```cpp
int* makeNumber() {
    int x = 7;     // on the stack
    return &x;     // x dies when the function ends!
}
```

**Right — the heap survives:**
```cpp
int* makeNumber() {
    int *p = new int;  // on the heap
    *p = 7;
    return p;          // still valid after return
}
// the caller must delete it later
```

Here is a function that builds and returns a whole array:

```cpp
#include <iostream>
using namespace std;

int* makeSquares(int n) {
    int *a = new int[n];
    for (int i = 0; i < n; i++)
        a[i] = (i + 1) * (i + 1);
    return a;            // heap data survives the return
}

int main() {
    int *sq = makeSquares(4);
    for (int i = 0; i < 4; i++)
        cout << sq[i] << " ";
    cout << endl;
    delete[] sq;         // caller frees it
    return 0;
}
```

**Output:**
```
1 4 9 16
```

Whoever receives the pointer must `delete[]` it.

---

## 12. Common Mistakes

**1. Uninitialized (wild) pointer**

**Wrong:**
```cpp
int *p;      // points to a random address
*p = 5;      // writes to unknown memory
```

**Correct:**
```cpp
int x;
int *p = &x; // point it at a real variable first
*p = 5;
```

**Explanation:** a pointer with no value points to a random place in memory. Always point it at something valid (or `nullptr`) before using it.

**2. Dereferencing a null pointer**

**Wrong:**
```cpp
int *p = nullptr;
cout << *p;   // crash: nothing is there
```

**Correct:**
```cpp
int *p = nullptr;
if (p != nullptr) cout << *p;
```

**Explanation:** `nullptr` means "points to nothing." Check before dereferencing.

**3. Forgetting the address-of operator**

**Wrong:**
```cpp
int x = 5;
int *p = x;    // ERROR: x is a value, not an address
```

**Correct:**
```cpp
int x = 5;
int *p = &x;   // store the ADDRESS of x
```

**Explanation:** a pointer must be given an address, so use `&x`, not `x`.

**4. Memory leak (new without delete)**

**Wrong:**
```cpp
int *p = new int;
*p = 50;
// program ends without delete p; — memory leaked
```

**Correct:**
```cpp
int *p = new int;
*p = 50;
delete p;     // give the memory back
```

**Explanation:** memory reserved with `new` is not freed automatically. Every `new` needs a matching `delete`.

**5. Dangling pointer**

**Wrong:**
```cpp
int* f() {
    int x = 7;
    return &x;   // x dies when f ends
}
```

**Correct:**
```cpp
int* f() {
    int *p = new int;   // heap memory survives
    *p = 7;
    return p;
}
```

**Explanation:** returning the address of a local gives a pointer to memory that no longer exists. Return heap memory instead (and `delete` it later).

**6. Wrong delete form**

**Wrong:**
```cpp
int *a = new int[5];
delete a;        // should be delete[]
```

**Correct:**
```cpp
int *a = new int[5];
delete[] a;      // free arrays with delete[]
```

**Explanation:** free a single value with `delete`, and an array with `delete[]`.

---

## 13. Practice Exercises

Try each one before opening the solution. Exercises 1–5 cover pointers; 6–10 cover memory.

**Exercise 1.** Declare `int x = 7;` and a pointer `p` to it. Print `x`, the address `&x`, and the value `*p`.

<details>
<summary>Click to see solution</summary>

```cpp
int x = 7;
int *p = &x;
cout << x  << endl;   // 7
cout << &x << endl;   // address of x
cout << *p << endl;   // 7
```
</details>

**Exercise 2.** Use a pointer to change `x` to 99. Print `x` before and after.

<details>
<summary>Click to see solution</summary>

```cpp
int x = 10;
int *p = &x;
cout << x << endl;   // 10
*p = 99;
cout << x << endl;   // 99
```
</details>

**Exercise 3.** Write a function `void doubleIt(int *p)` that doubles the value the pointer points to.

<details>
<summary>Click to see solution</summary>

```cpp
void doubleIt(int *p) {
    *p = *p * 2;
}

int main() {
    int n = 8;
    doubleIt(&n);
    cout << n << endl;   // 16
}
```
</details>

**Exercise 4.** Given `int a[5]`, use a pointer to print all five elements.

<details>
<summary>Click to see solution</summary>

```cpp
int a[5] = {1, 2, 3, 4, 5};
int *p = a;
for (int i = 0; i < 5; i++)
    cout << *(p + i) << " ";
cout << endl;   // 1 2 3 4 5
```
</details>

**Exercise 5.** Write a function `void swap(int *a, int *b)` that swaps two integers using pointers.

<details>
<summary>Click to see solution</summary>

```cpp
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}
// in main: int x = 3, y = 8; swap(&x, &y);  -> 8 3
```
</details>

**Exercise 6.** Create one `int` on the heap, store 42 in it, print it, then `delete` it.

<details>
<summary>Click to see solution</summary>

```cpp
int *p = new int;
*p = 42;
cout << *p << endl; // 42
delete p;
```
</details>

**Exercise 7.** Read `n`, make a dynamic array of `n` ints, fill it with `1..n`, print them, then free with `delete[]`.

<details>
<summary>Click to see solution</summary>

```cpp
int n;
cin >> n;
int *a = new int[n];
for (int i = 0; i < n; i++) a[i] = i + 1;
for (int i = 0; i < n; i++) cout << a[i] << " ";
cout << endl;
delete[] a;
```
</details>

**Exercise 8.** Read `n` numbers into a heap array and print their sum.

<details>
<summary>Click to see solution</summary>

```cpp
int n;
cin >> n;
int *a = new int[n];
int sum = 0;
for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
}
cout << "Sum = " << sum << endl;
delete[] a;
```
</details>

**Exercise 9.** **Fix the leak:** a loop does `new int` each pass but never frees. Rewrite it so each allocation is deleted.

<details>
<summary>Click to see solution</summary>

```cpp
for (int i = 0; i < 3; i++) {
    int *p = new int;
    *p = i;
    cout << *p << " ";
    delete p;        // free EACH pass
}
```
</details>

**Exercise 10.** **Fix the dangling pointer:** a function returns the address of a local variable. Rewrite it to return heap memory.

<details>
<summary>Click to see solution</summary>

```cpp
// before (wrong): int* f() { int x = 7; return &x; }

int* f() {
    int *p = new int;   // heap, not stack
    *p = 7;
    return p;           // valid after return
}
// caller: int *r = f(); ...; delete r;
```
</details>

---

## 14. Summary

### Key Concepts

- A **pointer** stores the **address** of another variable; `&x` gives an address, `*p` the value at it.
- Pointers let a function change the caller's variable and let you walk arrays.
- Memory has two areas: **static** (the stack) and **dynamic** (the heap).

### Important Points

1. `int *p = &x;` makes `p` point to `x`; `*p = 100;` changes `x`.
2. Set unused pointers to `nullptr`, and never dereference a null pointer.
3. **Stack** (static) variables are created and freed automatically with their scope.
4. **Heap** (dynamic) memory is requested with `new` and must be released with `delete`.
5. A **dynamic array** (`new int[n]`) lets the size be chosen at run time; free it with `delete[]`.
6. To return data from a function, put it on the heap — never return the address of a local.
7. Avoid leaks, dangling pointers, double deletes, and the wrong `delete` form.

### Quick Reference

```cpp
int x = 42;
int *p = &x;       // p points to x
cout << *p;        // 42  (value at the address)
*p = 100;          // changes x to 100
p = nullptr;       // points to nothing

int *q = new int;      // dynamic: one int on the heap
*q = 5;
delete q;              // free it

int *arr = new int[n]; // dynamic array, size from run time
delete[] arr;          // free an array
```

### Next Steps

Pointers plus dynamic memory are the building blocks for **dynamic data structures** — linked lists, stacks, and trees — where the number of elements is not known in advance. Those are natural topics to explore next.
