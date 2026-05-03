# C++ Programming — Lecture: Dynamic vs Static Memory & Pointers

## Table of Contents

1. [Introduction](#introduction)
2. [Static Memory Allocation](#static-memory-allocation)
   - [Stack Memory](#stack-memory)
   - [Global and Static Variables](#global-and-static-variables)
3. [Pointers](#pointers)
   - [Declaring and Initializing Pointers](#declaring-and-initializing-pointers)
   - [Dereferencing and Address-of](#dereferencing-and-address-of)
   - [Pointer Arithmetic](#pointer-arithmetic)
4. [Dynamic Memory Allocation](#dynamic-memory-allocation)
   - [new and delete](#new-and-delete)
   - [Dynamic Arrays](#dynamic-arrays)
5. [Static vs Dynamic: Side-by-Side Comparison](#static-vs-dynamic-side-by-side-comparison)
6. [Common Memory Mistakes](#common-memory-mistakes)
7. [Practice Exercises](#practice-exercises)
8. [Summary](#summary)

---

## Introduction

Memory management is one of C++'s most powerful — and most dangerous — features. Unlike Python, which handles memory automatically, C++ gives you direct control over how and when memory is allocated and freed.

**Why this matters:**
- Understanding memory is essential for writing efficient programs
- Bugs related to memory (leaks, dangling pointers) are common sources of crashes
- Dynamic allocation lets you create data structures of any size at runtime
- Pointers are the foundation of linked lists, trees, and other advanced data structures

**Real-world analogies:**
- **Static memory** is like a reserved parking spot — fixed in size, always available while you're in the building, automatically freed when you leave.
- **Dynamic memory** is like renting a hotel room — you request space when you need it, use it as long as you want, but you must explicitly check out (free it) when done.
- **A pointer** is like a slip of paper with an address on it — it doesn't hold the value itself, it tells you *where* to find it.

---

## Static Memory Allocation

### Stack Memory

Static (stack) memory is allocated at compile time. The compiler decides how much space variables need, and that space is automatically managed.

```cpp
#include <iostream>
using namespace std;

void stackDemo() {
    int x = 10;         // Allocated on the stack
    double pi = 3.14;   // Also on the stack
    int arr[5] = {1, 2, 3, 4, 5};  // Fixed-size array on the stack

    cout << "x = " << x << endl;
    cout << "pi = " << pi << endl;
    cout << "arr[2] = " << arr[2] << endl;
} // All variables automatically freed here

int main() {
    stackDemo();
    return 0;
}
```

**Output:**
```
x = 10
pi = 3.14
arr[2] = 3
```

**Key properties of stack memory:**
- Size must be known at compile time
- Automatically freed when the function returns
- Very fast allocation/deallocation
- Limited in size (typically 1–8 MB)

### Global and Static Variables

Variables declared outside functions or with the `static` keyword live for the entire lifetime of the program.

```cpp
#include <iostream>
using namespace std;

int globalCount = 0;  // Lives for the entire program

void increment() {
    static int callCount = 0;  // Initialized once, persists across calls
    callCount++;
    globalCount++;
    cout << "Call #" << callCount << ", global = " << globalCount << endl;
}

int main() {
    increment();
    increment();
    increment();
    return 0;
}
```

**Output:**
```
Call #1, global = 1
Call #2, global = 2
Call #3, global = 3
```

---

## Pointers

A pointer is a variable that stores the **memory address** of another variable. Instead of holding a value like `42`, a pointer holds an address like `0x7ffd1234`.

### Declaring and Initializing Pointers

```cpp
#include <iostream>
using namespace std;

int main() {
    int value = 42;
    int* ptr = &value;  // ptr holds the address of value

    cout << "value = " << value << endl;
    cout << "Address of value (&value) = " << &value << endl;
    cout << "ptr = " << ptr << endl;          // The address stored in ptr
    cout << "*ptr = " << *ptr << endl;        // The value AT that address

    return 0;
}
```

**Output:**
```
value = 42
Address of value (&value) = 0x7ffd5abc1234
ptr = 0x7ffd5abc1234
*ptr = 42
```

**Syntax breakdown:**
| Syntax | Meaning |
|--------|---------|
| `int* ptr` | Declare a pointer to an int |
| `&value` | Address-of operator: gives the address of `value` |
| `*ptr` | Dereference: gives the value stored at the address |
| `ptr = nullptr` | Set pointer to null (points nowhere) |

### Dereferencing and Address-of

You can modify the original variable through a pointer by dereferencing it.

```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 10;
    int* p = &a;

    cout << "Before: a = " << a << endl;

    *p = 99;  // Modify a through the pointer

    cout << "After:  a = " << a << endl;  // a is now 99!

    // Multiple pointers can point to the same variable
    int* q = &a;
    *q = 200;
    cout << "Through q: a = " << a << endl;

    return 0;
}
```

**Output:**
```
Before: a = 10
After:  a = 99
Through q: a = 200
```

### Pointer Arithmetic

Pointers support arithmetic. Adding 1 to a pointer moves it forward by the size of the type it points to.

```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[4] = {10, 20, 30, 40};
    int* p = arr;  // Points to arr[0]

    cout << "p    points to: " << *p << endl;     // 10
    cout << "(p+1) points to: " << *(p+1) << endl; // 20
    cout << "(p+2) points to: " << *(p+2) << endl; // 30
    cout << "(p+3) points to: " << *(p+3) << endl; // 40

    // Move the pointer forward
    p++;
    cout << "After p++: *p = " << *p << endl;  // 20

    return 0;
}
```

**Output:**
```
p    points to: 10
(p+1) points to: 20
(p+2) points to: 30
(p+3) points to: 40
After p++: *p = 20
```

---

## Dynamic Memory Allocation

Dynamic allocation happens at **runtime**. You explicitly request memory from the heap using `new`, and you must free it using `delete`.

### new and delete

```cpp
#include <iostream>
using namespace std;

int main() {
    // Allocate a single integer on the heap
    int* p = new int;
    *p = 55;

    cout << "Value at p: " << *p << endl;
    cout << "Address:    " << p << endl;

    delete p;     // Free the memory
    p = nullptr;  // Good practice: prevent dangling pointer

    // Allocate and initialize in one step
    double* d = new double(3.14);
    cout << "Double: " << *d << endl;
    delete d;
    d = nullptr;

    return 0;
}
```

**Output:**
```
Value at p: 55
Address:    0x55a3b1c2e260
Double: 3.14
```

### Dynamic Arrays

Dynamic arrays are allocated at runtime, so their size can be determined by user input or program logic.

```cpp
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;

    // Allocate array on the heap
    int* arr = new int[n];

    // Fill with values
    for (int i = 0; i < n; i++) {
        arr[i] = (i + 1) * 10;
    }

    // Print values
    cout << "Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // MUST use delete[] for arrays (not delete)
    delete[] arr;
    arr = nullptr;

    return 0;
}
```

**Output (for n=5):**
```
Enter array size: 5
Array: 10 20 30 40 50
```

---

## Static vs Dynamic: Side-by-Side Comparison

| Feature | Static (Stack) | Dynamic (Heap) |
|---------|---------------|----------------|
| **Allocation time** | Compile time | Runtime |
| **Size** | Must be known in advance | Determined at runtime |
| **Lifetime** | Function scope | Until `delete` is called |
| **Speed** | Very fast | Slower (OS involved) |
| **Memory limit** | Small (~1–8 MB) | Large (limited by RAM) |
| **Management** | Automatic | Manual (`new`/`delete`) |
| **Risk** | Stack overflow | Memory leaks, dangling pointers |

```cpp
#include <iostream>
using namespace std;

int main() {
    // --- STATIC ---
    int staticArr[5] = {1, 2, 3, 4, 5};  // Fixed size, stack

    // --- DYNAMIC ---
    int size = 5;
    int* dynamicArr = new int[size];      // Runtime size, heap
    for (int i = 0; i < size; i++)
        dynamicArr[i] = (i + 1);

    cout << "Static[2]  = " << staticArr[2] << endl;
    cout << "Dynamic[2] = " << dynamicArr[2] << endl;

    delete[] dynamicArr;  // Required!
    return 0;
}
```

**Output:**
```
Static[2]  = 3
Dynamic[2] = 3
```

---

## Common Memory Mistakes

**Mistake 1: Forgetting to delete (Memory Leak)**

**Wrong:**
```cpp
void badFunction() {
    int* p = new int(10);
    // Function ends — memory is never freed!
}
```

**Correct:**
```cpp
void goodFunction() {
    int* p = new int(10);
    // ... use p ...
    delete p;
    p = nullptr;
}
```

**Explanation:** When you allocate with `new`, the memory lives until you call `delete`. If the pointer goes out of scope without `delete`, the memory is permanently leaked.

---

**Mistake 2: Using delete Instead of delete[] for Arrays**

**Wrong:**
```cpp
int* arr = new int[10];
delete arr;   // Undefined behavior
```

**Correct:**
```cpp
int* arr = new int[10];
delete[] arr;  // Correct for arrays
```

**Explanation:** `delete` frees a single object; `delete[]` frees an entire array. Mixing them causes undefined behavior, often a crash.

---

**Mistake 3: Dangling Pointer (Using After Delete)**

**Wrong:**
```cpp
int* p = new int(5);
delete p;
cout << *p;   // Dangling pointer — undefined behavior
```

**Correct:**
```cpp
int* p = new int(5);
delete p;
p = nullptr;         // Set to null after delete
if (p != nullptr)    // Safe to check before use
    cout << *p;
```

**Explanation:** After calling `delete`, the memory is freed but the pointer still holds the old address. Always set the pointer to `nullptr` after deleting.

---

**Mistake 4: Uninitialized Pointer**

**Wrong:**
```cpp
int* p;         // Garbage value — points somewhere random
*p = 42;        // Undefined behavior — could crash or corrupt memory
```

**Correct:**
```cpp
int* p = nullptr;    // Initialize to null
p = new int;
*p = 42;
delete p;
```

**Explanation:** An uninitialized pointer contains a random address. Dereferencing it is undefined behavior and often leads to a segmentation fault.

---

**Mistake 5: Double Delete**

**Wrong:**
```cpp
int* p = new int(10);
delete p;
delete p;     // Double free — undefined behavior
```

**Correct:**
```cpp
int* p = new int(10);
delete p;
p = nullptr;
// delete p here is safe — deleting nullptr does nothing
```

**Explanation:** Deleting the same memory twice corrupts the heap and causes undefined behavior. Setting the pointer to `nullptr` after deletion prevents this.

---

## Practice Exercises

**Exercise 1 — Basic Pointer**
Write a program that declares an integer `score = 100`, creates a pointer to it, then uses the pointer to change the value to `200`. Print the result.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int score = 100;
    int* p = &score;
    *p = 200;
    cout << "score = " << score << endl;  // 200
    return 0;
}
```
</details>

---

**Exercise 2 — Dynamic Single Variable**
Allocate a `double` on the heap, store the value `9.81`, print it, then free the memory properly.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    double* g = new double(9.81);
    cout << "Gravity: " << *g << endl;
    delete g;
    g = nullptr;
    return 0;
}
```
</details>

---

**Exercise 3 — Dynamic Array**
Ask the user for a count `n`, allocate a dynamic integer array of size `n`, fill it with squares (1, 4, 9, ..., n²), print them, and free the array.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    int* arr = new int[n];
    for (int i = 0; i < n; i++)
        arr[i] = (i + 1) * (i + 1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    delete[] arr;
    arr = nullptr;
    return 0;
}
```
</details>

---

**Exercise 4 — Swap via Pointers**
Write a function `void swapInts(int* a, int* b)` that swaps the values of two integers using pointers. Test it in `main()`.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

void swapInts(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 5, y = 10;
    cout << "Before: x=" << x << " y=" << y << endl;
    swapInts(&x, &y);
    cout << "After:  x=" << x << " y=" << y << endl;
    return 0;
}
```
</details>

---

**Exercise 5 — Find Maximum via Pointer**
Write a function `int* findMax(int* arr, int size)` that returns a pointer to the largest element in a dynamic array. Print the value through the pointer.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int* findMax(int* arr, int size) {
    int* maxPtr = arr;
    for (int i = 1; i < size; i++)
        if (arr[i] > *maxPtr)
            maxPtr = &arr[i];
    return maxPtr;
}

int main() {
    int n = 5;
    int* data = new int[n]{3, 17, 8, 42, 5};
    int* m = findMax(data, n);
    cout << "Max = " << *m << endl;  // 42
    delete[] data;
    return 0;
}
```
</details>

---

## Summary

### Key Concepts
- **Static memory** is allocated at compile time on the stack; size must be fixed.
- **Dynamic memory** is allocated at runtime on the heap using `new`.
- **Pointers** store memory addresses; use `*` to dereference and `&` to get an address.
- Every `new` must have a matching `delete`; every `new[]` must have a matching `delete[]`.
- Always set pointers to `nullptr` after deleting to avoid dangling pointers.

### Important Points
1. Stack memory is automatic — no manual management needed.
2. Heap memory persists until you explicitly free it with `delete`.
3. Failing to `delete` heap memory causes a **memory leak**.
4. Using a pointer after `delete` is a **dangling pointer** — undefined behavior.
5. Allocating with `new[]` and freeing with `delete` (not `delete[]`) is undefined behavior.
6. An uninitialized pointer contains garbage — always initialize to `nullptr` or a valid address.
7. Setting a pointer to `nullptr` after `delete` makes double-delete safe.
8. Pointer arithmetic moves by the size of the pointed-to type.

### Quick Reference
```cpp
// Pointer basics
int val = 42;
int* p = &val;    // Point to val
*p = 99;          // Modify val through pointer

// Dynamic single variable
int* x = new int(10);
delete x;
x = nullptr;

// Dynamic array
int* arr = new int[n];
delete[] arr;
arr = nullptr;
```

### Next Steps
The next lecture covers **References vs Pointers**, **`const` pointers**, and **pointers to objects** — the foundation for working with classes dynamically in C++.
