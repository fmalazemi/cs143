# CS143 — Deep Copy vs. Shallow Copy

> **Course:** CS143 Introduction to C++ · **Instructor:** Dr. Fawaz Alazemi
> **Builds on:** pointers, `new` / `delete`, constructors and destructors.

---

## Table of Contents

1. [Introduction](#1-introduction)
2. [When Does a Copy Happen](#2-when-does-a-copy-happen)
3. [The Default Copy Is Shallow](#3-the-default-copy-is-shallow)
4. [The Double-Free Problem](#4-the-double-free-problem)
5. [Deep Copy and the Copy Constructor](#5-deep-copy-and-the-copy-constructor)
6. [Deep Copy of a Dynamic Array](#6-deep-copy-of-a-dynamic-array)
7. [The Rule of Three](#7-the-rule-of-three)
8. [How Python Differs](#8-how-python-differs)
9. [Common Mistakes](#9-common-mistakes)
10. [Practice Exercises](#10-practice-exercises)
11. [Summary](#11-summary)

---

## 1. Introduction

When a class holds a **pointer** to memory it created with `new`, copying an object of that class becomes tricky. There are two ways a copy can happen:

- A **shallow copy** copies the pointer itself, so two objects share one block of memory.
- A **deep copy** allocates new memory and copies the value into it, so each object owns its own block.

Choosing the wrong one leads to surprising bugs and even crashes. Throughout this lecture we use a small class that owns memory:

```cpp
class IntBox {
    int* data;               // a pointer to heap memory
public:
    IntBox(int value) {
        data = new int(value);   // allocate one int
    }
    ~IntBox() {
        delete data;             // free it
    }
    int  get()      { return *data; }
    void set(int v) { *data = v; }
};
```

`IntBox` does not hold a value directly — it holds the **address** of a value on the heap. This "owns a pointer" pattern is exactly where copying matters.

---

## 2. When Does a Copy Happen

A copy is made whenever one object is built from another. This happens more often than you might expect:

```cpp
IntBox a(5);

IntBox b = a;    // 1. copy when created
IntBox c(a);     // 2. same thing

useBox(a);       // 3. passing by value makes a copy

// 4. returning an object by value also makes a copy
```

Because copies happen on assignment, on function calls, and on returns, the way copying works affects the whole program. The key question is: **what exactly gets copied when the object owns a pointer?**

---

## 3. The Default Copy Is Shallow

If you do not write a copy constructor, the compiler makes one for you. It copies **each member as-is**. For a pointer member, "copy the member" means **copy the address** — not the thing it points to. Both objects then point to the same block.

```
   a ── data ●─────┐
                    ▼
                 [  5  ]   <-- one shared block on the heap
                    ▲
   b ── data ●─────┘

   a and b share one block — changing one changes both
```

We can see the shared state directly:

```cpp
int main() {
    IntBox a(5);
    IntBox b = a;      // shallow copy (default)

    b.set(99);         // change b only...

    cout << a.get() << endl;   // 99  (!)
    cout << b.get() << endl;   // 99
    return 0;
}
```

**Output:**
```
99
99
```

We changed `b`, but `a` changed too. Because both share one block, editing one edits the other. This "spooky" shared state is the first sign of a shallow copy.

---

## 4. The Double-Free Problem

Shared state is surprising, but the bigger danger comes at the **end** of the program. Both destructors run, and each calls `delete data` on the **same** block.

```
   [  5  ]   ──delete (from b)──►  freed ✓   ──delete (from a)──►  ✗ crash
    alive                          (gone)                          double free
```

Freeing memory that is already freed is a serious bug, called a **double free**. It often crashes the program. So a shallow copy of a memory-owning object is not just confusing — it is unsafe.

---

## 5. Deep Copy and the Copy Constructor

A **deep copy** fixes both problems. Instead of copying the pointer, it allocates **new** memory and copies the *value* into it. The two objects then share nothing.

You control copying by writing a **copy constructor**:

```
ClassName(const ClassName& other)
```

- It has the **same name as the class** — it is a constructor.
- It receives the object being copied, `const ClassName& other`, by reference.
- Inside, you decide how the copy is made — this is where you do the deep copy.

For `IntBox`, the deep copy allocates a fresh int and copies the value:

```cpp
IntBox(const IntBox& other) {
    data = new int(*other.data);   // new memory, copy the VALUE
}
```

Now each object points to its own block:

```
   a ── data ●────►  [  5  ]

   b ── data ●────►  [  5  ]     (a separate block)

   each owns its block — safe
```

Here is the full corrected class in action:

```cpp
#include <iostream>
using namespace std;

class IntBox {
    int* data;
public:
    IntBox(int value) { data = new int(value); }

    // deep copy constructor
    IntBox(const IntBox& other) {
        data = new int(*other.data);
    }

    ~IntBox() { delete data; }
    int  get()      { return *data; }
    void set(int v) { *data = v; }
};

int main() {
    IntBox a(5);
    IntBox b = a;      // now a DEEP copy

    b.set(99);
    cout << a.get() << endl;   // 5
    cout << b.get() << endl;   // 99
    return 0;
}
```

**Output:**
```
5
99
```

The copy constructor gives `b` its own block. Changing `b` now leaves `a` untouched, and each destructor frees a different block — no double free.

---

## 6. Deep Copy of a Dynamic Array

The same idea applies when a class owns a dynamic array. The deep copy allocates a **new array** and copies each element.

```cpp
class Numbers {
    int* arr;
    int  size;
public:
    Numbers(int s) {
        size = s;
        arr = new int[size];
        for (int i = 0; i < size; i++) arr[i] = 0;
    }
    // deep copy: new array + copy each element
    Numbers(const Numbers& other) {
        size = other.size;
        arr = new int[size];
        for (int i = 0; i < size; i++)
            arr[i] = other.arr[i];
    }
    ~Numbers() { delete[] arr; }
    void set(int i, int v) { arr[i] = v; }
    int  get(int i)        { return arr[i]; }
};
```

Using it:

```cpp
Numbers a(3);
a.set(0, 10);
Numbers b = a;     // deep copy
b.set(0, 99);
cout << a.get(0) << endl;   // 10
cout << b.get(0) << endl;   // 99
```

**Output:**
```
10
99
```

The rule is the same: never just copy the pointer — allocate a new block and copy the contents.

---

## 7. The Rule of Three

If a class needs any one of the following, it usually needs **all three**. Together they keep copying and freeing correct.

1. **Destructor** — `~IntBox()` frees the memory.
2. **Copy constructor** — `IntBox(const IntBox&)` deep-copies when an object is created from another.
3. **Copy assignment** — `operator=` deep-copies on `b = a;` *after* both already exist.

The copy assignment operator, shown here for reference, frees the old memory first and guards against copying an object onto itself:

```cpp
IntBox& operator=(const IntBox& other) {
    if (this != &other) {              // avoid self-copy
        delete data;                   // free old
        data = new int(*other.data);   // deep copy
    }
    return *this;
}
```

If you write a destructor because your class owns memory, that is a strong hint you also need the other two.

---

## 8. How Python Differs

Python has the same two ideas, but hides the memory work.

| Goal | Python | C++ |
|------|--------|-----|
| Share the same object | `b = a` | shallow copy |
| Make an independent copy | `copy.deepcopy(a)` | deep copy constructor |
| Clean up memory | automatic | you write the destructor |

In Python, `b = a` makes both names refer to the **same** object — much like a shallow copy. To get an independent copy you call `copy.deepcopy(a)`. C++ has the same distinction, but you must write the deep copy yourself, and a wrong copy can crash the program, not merely surprise you.

---

## 9. Common Mistakes

**1. Trusting the default copy**

**Wrong:**
```cpp
class IntBox { int* data; /* ...no copy constructor... */ };
IntBox b = a;     // silently shallow
```

**Correct:**
```cpp
IntBox(const IntBox& other) { data = new int(*other.data); }
```

**Explanation:** when a class owns a pointer, the compiler's default copy is shallow.

**2. Copying the pointer instead of the value**

**Wrong:**
```cpp
IntBox(const IntBox& other) {
    data = other.data;      // still shallow — shared block
}
```

**Correct:**
```cpp
IntBox(const IntBox& other) {
    data = new int(*other.data);   // own block, copied value
}
```

**Explanation:** assigning the pointer copies the address; you must allocate new memory.

**3. Forgetting `new` in the copy constructor**

**Wrong:**
```cpp
IntBox(const IntBox& other) {
    *data = *other.data;    // data was never allocated
}
```

**Correct:**
```cpp
IntBox(const IntBox& other) {
    data = new int(*other.data);
}
```

**Explanation:** without a `new` block, there is nothing to copy into.

**4. Writing only the copy constructor**

**Wrong:**
```cpp
// copy constructor written, but b = a; still uses the default (shallow) assignment
```

**Correct:**
```cpp
IntBox& operator=(const IntBox& other) { /* deep copy */ return *this; }
```

**Explanation:** assignment after creation needs its own deep-copy handling (Rule of Three).

**5. Missing the self-copy check**

**Wrong:**
```cpp
IntBox& operator=(const IntBox& other) {
    delete data;                    // if other IS this, we just freed our own data
    data = new int(*other.data);    // now reading freed memory
    return *this;
}
```

**Correct:**
```cpp
IntBox& operator=(const IntBox& other) {
    if (this != &other) {
        delete data;
        data = new int(*other.data);
    }
    return *this;
}
```

**Explanation:** guard against `a = a;` before freeing the current data.

**6. Using `delete` for an array**

**Wrong:**
```cpp
~Numbers() { delete arr; }      // arr came from new[]
```

**Correct:**
```cpp
~Numbers() { delete[] arr; }
```

**Explanation:** an array made with `new[]` must be freed with `delete[]`.

**A test to remember:** if editing the copy changes the original, it was a shallow copy.

---

## 10. Practice Exercises

Try each one before opening the solution.

**Exercise 1.** A class holds a member `int* p` and writes no copy constructor. Is the default copy shallow or deep? Explain in one sentence.

<details>
<summary>Click to see solution</summary>

**Shallow.** The default copy copies the pointer's address, so both objects point to the same memory rather than to separate copies.
</details>

**Exercise 2.** Write a deep copy constructor for `IntBox` (which holds `int* data`).

<details>
<summary>Click to see solution</summary>

```cpp
IntBox(const IntBox& other) {
    data = new int(*other.data);
}
```
</details>

**Exercise 3.** Explain in one sentence why two objects that share a pointer crash at the end of the program.

<details>
<summary>Click to see solution</summary>

Both objects hold the same address, so each destructor calls `delete` on it — the memory is freed twice, which is a double free and crashes the program.
</details>

**Exercise 4.** The class `Numbers` holds `int* arr` and `int size`. Write a deep copy constructor for it.

<details>
<summary>Click to see solution</summary>

```cpp
Numbers(const Numbers& other) {
    size = other.size;
    arr = new int[size];
    for (int i = 0; i < size; i++)
        arr[i] = other.arr[i];
}
```
</details>

**Exercise 5.** In Python, does `b = a` copy a list or share it? What does `copy.deepcopy(a)` do?

<details>
<summary>Click to see solution</summary>

`b = a` **shares** the list — both names refer to the same list. `copy.deepcopy(a)` makes a fully independent copy.
</details>

**Exercise 6.** Find the bug: a copy constructor whose body is `data = other.data;`. What kind of copy is this, and how do you fix it?

<details>
<summary>Click to see solution</summary>

Writing `data = other.data;` is a **shallow** copy — it copies the address, so both objects share one block. Fix it by allocating new memory and copying the value:

```cpp
data = new int(*other.data);
```
</details>

---

## 11. Summary

### Key Concepts

- A **shallow copy** copies the pointer, so two objects **share** one block of memory.
- A **deep copy** allocates new memory and copies the value, so each object owns its own block.
- You control copying by writing a **copy constructor**.

### Important Points

1. The compiler's default copy is shallow for a pointer member.
2. Sharing causes **shared state** (editing one edits the other) and a **double free** at the end.
3. A deep copy constructor allocates with `new` and copies the value or every element.
4. The copy constructor signature is `ClassName(const ClassName& other)`.
5. The **Rule of Three**: a class with a destructor usually also needs a copy constructor and copy assignment.
6. If editing the copy changes the original, the copy was shallow.

### Quick Reference

```cpp
// shallow (default): copies the pointer -> shared block
IntBox b = a;

// deep (what we write): new block, copy the value
IntBox(const IntBox& other) {
    data = new int(*other.data);
}

// deep copy of an array
arr = new int[size];
for (int i = 0; i < size; i++) arr[i] = other.arr[i];
```

### The One Rule to Remember

When an object owns memory, copy it **deeply** — allocate new memory and copy the contents — or do not copy it at all.
