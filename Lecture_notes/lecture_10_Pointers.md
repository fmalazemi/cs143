# CS143 — Lecture 10: Pointers

> **Course:** CS143 Introduction to C++ · **Instructor:** Dr. Fawaz Alazemi
> **Audience:** Students who completed CS101 (Python). Assumes only basic Python (variables, `if`, loops, functions).
> **Builds on:** Lecture 6 (arrays in memory) and Lecture 7 (references).

---

## Table of Contents

1. [Introduction](#1-introduction)
2. [What Is a Pointer?](#2-what-is-a-pointer)
3. [Address-of and Dereference](#3-address-of-and-dereference)
4. [Pointers and Functions](#4-pointers-and-functions)
5. [Pointers and Arrays](#5-pointers-and-arrays)
6. [Dynamic Memory: new and delete](#6-dynamic-memory-new-and-delete)
7. [Pointers vs. References](#7-pointers-vs-references)
8. [Common Mistakes](#8-common-mistakes)
9. [Practice Exercises](#9-practice-exercises)
10. [Summary](#10-summary)

---

## 1. Introduction

Every variable in a program lives somewhere in memory, at a numbered location called its **address**. You saw this in Lecture 6: the boxes of an array sit at addresses that increase by the size of each element.

A **pointer** is a variable that stores an address. Instead of holding a number like `42`, it holds *where* a `42` is kept.

**Why pointers matter:**

- They let a function change a variable that belongs to the caller.
- They let you walk through arrays efficiently.
- They make dynamic memory (asking for space while the program runs) possible.
- They are the foundation for data structures such as linked lists and trees.

**A real-world analogy:** a pointer is like a house address written on a piece of paper. The paper is not the house, but it tells you exactly where to find it. If you give someone the address, they can visit the house and even change what is inside.

**Python note:** Python uses addresses internally too, but it hides them. C++ lets you work with addresses directly — powerful, but it requires care.

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

We read this as "`p` points to `x`." The arrow means `p` holds the address of `x`.

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

(The exact address differs every run; the point is that `p` and `&x` print the **same** address.)

The declaration `int *p;` means "`p` is a pointer to an `int`." The `*` in the declaration marks `p` as a pointer.

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
#include <iostream>
using namespace std;

int main() {
    int *p = nullptr;        // points to nothing

    if (p != nullptr) {
        cout << *p << endl;  // only use it if valid
    } else {
        cout << "p points to nothing" << endl;
    }
    return 0;
}
```

**Output:**
```
p points to nothing
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

We pass `&x` and `&y` (addresses), and inside the function we work with `*a` and `*b` (the values).

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

Adding `i` to a pointer moves it `i` elements forward, and `*(p + i)` reads that element. In fact, `p[i]` means exactly the same as `*(p + i)` — array indexing is pointer math underneath.

---

## 6. Dynamic Memory: new and delete

So far, variables had a fixed size known when you wrote the code. The keyword `new` lets a program ask for memory **while it runs**, and returns a pointer to it. The keyword `delete` gives that memory back.

```cpp
#include <iostream>
using namespace std;

int main() {
    int *p = new int;    // reserve memory for one int

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

**The rule:** every `new` needs a matching `delete`. Forgetting `delete` wastes memory — this is called a **memory leak**. (Allocating whole arrays with `new[]` and freeing them with `delete[]` is a later topic.)

---

## 7. Pointers vs. References

Pointers and references both let a function share a variable, but they differ in important ways.

| Feature | Reference (`&`) | Pointer (`*`) |
|---------|-----------------|---------------|
| What it is | another name for a variable | a variable holding an address |
| Must be set at start | yes, always | no (but it should be) |
| Can be null | no | yes (`nullptr`) |
| Can point elsewhere later | no | yes |
| Need `*` to read the value | no | yes (`*p`) |

**Guideline:** prefer a reference when you simply need to share a variable. Use a pointer when you need to repoint it, allow a "nothing" value, or manage dynamic memory.

---

## 8. Common Mistakes

**1. Uninitialized (wild) pointer**

**Wrong:**
```cpp
int *p;      // points to a random address
*p = 5;      // writes to unknown memory — crash or corruption
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
if (p != nullptr) {
    cout << *p;
}
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

**4. Dangling pointer**

**Wrong:**
```cpp
int* makePtr() {
    int local = 10;
    return &local;   // local disappears when the function ends
}
```

**Correct:**
```cpp
int* makePtr() {
    int *p = new int;   // memory that lives on
    *p = 10;
    return p;           // caller must delete it later
}
```

**Explanation:** a local variable is destroyed when its function ends, so a pointer to it becomes invalid (dangling). Return memory that outlives the function instead.

**5. Memory leak (new without delete)**

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

---

## 9. Practice Exercises

Try each one before opening the solution.

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

**Exercise 2.** Use a pointer to change `x` to 99. Print `x` before and after the change.

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

**Exercise 3.** Write a function `void doubleIt(int *p)` that doubles the value the pointer points to. Test it in `main`.

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
for (int i = 0; i < 5; i++) {
    cout << *(p + i) << " ";
}
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
// in main:
int x = 3, y = 8;
swap(&x, &y);
cout << x << " " << y << endl;   // 8 3
```
</details>

**Exercise 6.** Use `new` to create one `int`, store 50 in it, print it, then `delete` it.

<details>
<summary>Click to see solution</summary>

```cpp
int *p = new int;   // reserve memory
*p = 50;
cout << *p << endl; // 50
delete p;           // free memory
```
</details>

---

## 10. Summary

### Key Concepts

- A **pointer** is a variable that stores the **address** of another variable.
- `&x` gives an address; `*p` gives the value at that address (dereferencing).
- Writing through a pointer (`*p = 100`) changes the variable it points to.

### Important Points

1. Declare a pointer with `int *p;` — the `*` marks it as a pointer.
2. `int *p = &x;` makes `p` point to `x`.
3. Pass a pointer to a function to let it change the caller's variable.
4. An array name is the address of its first element, so pointers can walk arrays (`*(p + i)` equals `p[i]`).
5. Set unused pointers to `nullptr`, and never dereference a null pointer.
6. `new` reserves memory and returns a pointer; every `new` needs a matching `delete`.
7. Prefer references for simple sharing; use pointers to repoint, allow "nothing", or manage memory.

### Quick Reference

```cpp
int x = 42;
int *p = &x;     // p points to x
cout << *p;      // 42  (value at the address)
*p = 100;        // changes x to 100
p = nullptr;     // points to nothing

int *q = new int;  // reserve memory while running
*q = 5;
delete q;          // free it
```

### Next Steps

Pointers are the building block for **dynamic data structures** — such as linked lists, stacks, and trees — where the number of elements is not known in advance. Those are natural topics to explore next.
