# CS143 — Objects Through Pointers ( -> , new, delete )

> **Course:** CS143 Introduction to C++ · **Instructor:** Dr. Fawaz Alazemi
> **Builds on:** pointers, structs, classes, and constructors.

---

## Table of Contents

1. [Introduction](#1-introduction)
2. [The Dot Does Not Work on a Pointer](#2-the-dot-does-not-work-on-a-pointer)
3. [The Arrow Operator](#3-the-arrow-operator)
4. [The Arrow Is a Shorthand](#4-the-arrow-is-a-shorthand)
5. [Following a Chain of Pointers](#5-following-a-chain-of-pointers)
6. [Why Create Objects on the Heap](#6-why-create-objects-on-the-heap)
7. [Creating One Object With new](#7-creating-one-object-with-new)
8. [Passing Constructor Arguments](#8-passing-constructor-arguments)
9. [Arrays of Objects](#9-arrays-of-objects)
10. [How Python Differs](#10-how-python-differs)
11. [Common Mistakes](#11-common-mistakes)
12. [Practice Exercises](#12-practice-exercises)
13. [Summary](#13-summary)

---

## 1. Introduction

This lecture covers two closely linked ideas. First, the **arrow operator** `->`, which reaches a member of an object through a **pointer**. Second, the **`new`** and **`delete`** operators, which create and free objects on the **heap**. They belong together because `new` hands back a pointer, and the arrow is how you use that pointer.

We already have two pieces of the picture:

```cpp
struct Point {
    int x;
    int y;
};

Point p;
p.x = 3;            // the DOT reaches a member of an object we hold

Point* ptr = &p;    // a POINTER holds the address of p, not p itself
```

The dot works when we hold the object directly. The question this lecture answers is: **when we only have a pointer, how do we reach the object's members?**

---

## 2. The Dot Does Not Work on a Pointer

A pointer stores an address, not an object, so the dot cannot be used on it directly.

```cpp
Point p;
p.x = 3;

Point* ptr = &p;

ptr.x = 5;        // WRONG: ptr is a pointer, not a Point

(*ptr).x = 5;     // correct, but clumsy to write
```

To use the dot, you must first **dereference** the pointer with `*ptr` to get the object, and the parentheses in `(*ptr).x` are required. Writing this every time is awkward and easy to get wrong, so C++ provides a cleaner tool.

---

## 3. The Arrow Operator

The **`->`** operator follows a pointer to its object and then reads a member, all in one step.

```
   ptr (a pointer)                 Point object
   +--------------+   points to    +----------------+
   |    0x7ffe    | -------------> |  x : 3         |  <-- ptr->x reads this
   +--------------+                |  y : 4         |
                                   +----------------+

   ptr->x   follows the pointer, then reads member x   ->   3
```

The syntax is:

```
pointer->member
```

- **`pointer`** — a pointer to an object (for example `Point*`).
- **`->`** — a dash `-` followed by a greater-than sign `>`, with no space between them.
- **`member`** — the field or method you want to reach.

It works for both **data members** (`ptr->x`) and **methods** (`ptr->area()`).

Here is a full program:

```cpp
#include <iostream>
using namespace std;

struct Point {
    int x;
    int y;
};

int main() {
    Point p;
    p.x = 3;
    p.y = 4;

    Point* ptr = &p;         // ptr points to p

    // reach members through the pointer
    cout << ptr->x << endl;  // 3
    cout << ptr->y << endl;  // 4
    return 0;
}
```

**Output:**
```
3
4
```

The arrow also calls methods. Note that `this->member`, which you have seen inside classes, uses this same arrow — `this` is a pointer to the current object:

```cpp
class Counter {
    int count;
public:
    Counter() : count(0) { }
    void increment() { count++; }
    int get() { return count; }
};

int main() {
    Counter c;
    Counter* ptr = &c;
    ptr->increment();          // call a method through the pointer
    ptr->increment();
    cout << ptr->get() << endl; // 2
    return 0;
}
```

**Output:**
```
2
```

---

## 4. The Arrow Is a Shorthand

The arrow is exactly the same as dereferencing and then using the dot. Both reach the same member.

```
   ptr->x   ------\
                   >---->  the same member x
   (*ptr).x ------/

   ptr->x   means   (*ptr).x
```

So `ptr->x` is simply a clearer way to write `(*ptr).x`. Whenever you see an arrow, you can read it as "dereference, then take the member."

---

## 5. Following a Chain of Pointers

When an object contains a pointer to another object, you can chain arrows to follow the links. This is common in linked structures.

```cpp
#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;      // a pointer to another Node
};

int main() {
    Node a = {1, nullptr};
    Node b = {2, nullptr};
    a.next = &b;             // link a to b

    Node* p = &a;
    cout << p->value << endl;        // 1
    cout << p->next->value << endl;  // 2
    return 0;
}
```

**Output:**
```
1
2
```

Read `p->next->value` left to right: follow `next` to reach the second node, then take its `value`.

---

## 6. Why Create Objects on the Heap

So far, our objects have lived on the **stack** — they are created when we declare them and destroyed automatically at the end of their block.

```cpp
void f() {
    Box b;      // created here
}               // destroyed here, automatically
```

Sometimes we need an object to live **longer** than the function that made it, or we do not know until the program runs how many objects we will need. For these cases we use the **heap**, controlled with `new` and `delete`.

```cpp
Box* b = new Box;   // created here, on the heap
// ... it stays alive ...
delete b;           // destroyed only when WE say so
```

```
        STACK                          HEAP
   +---------------+            +------------------+
   |  b (pointer)  |            |       Box        |
   |    0x9a2      | ---------> |  width · height  |
   +---------------+  points to +------------------+

   new Box   ->  object on the heap
   delete b  ->  frees it
```

The key point: **`new` gives back a pointer**, which is exactly why we reach the object's members with the arrow operator.

---

## 7. Creating One Object With new

`new` does two things at once: it reserves memory on the heap, and it runs the object's **constructor**. `delete` does the reverse: it runs the **destructor** and frees the memory.

```cpp
#include <iostream>
using namespace std;

class Box {
    int w, h;
public:
    Box(int w, int h) : w(w), h(h) {
        cout << "Box made" << endl;   // constructor
    }
    ~Box() {
        cout << "Box gone" << endl;   // destructor
    }
    int area() { return w * h; }
};

int main() {
    Box* b = new Box(5, 3);      // "Box made"
    cout << b->area() << endl;   // 15
    delete b;                    // "Box gone"
    return 0;
}
```

**Output:**
```
Box made
15
Box gone
```

The messages make the lifecycle visible: `new` builds the object, and `delete` cleans it up. Every `new` needs exactly one matching `delete`. After `delete`, the pointer is **dangling** and must not be used.

---

## 8. Passing Constructor Arguments

You can give `new` the same arguments the constructor expects. They go in parentheses after the type name.

```cpp
class Box {
    int width, height;
public:
    Box(int w, int h) : width(w), height(h) { }
    int area() { return width * height; }
};

int main() {
    Box* b = new Box(5, 3);      // constructor runs with 5 and 3
    cout << b->area() << endl;   // 15
    delete b;                    // free it
    return 0;
}
```

**Output:**
```
15
```

`new Box(5, 3)` reserves memory and runs the two-argument constructor. Because the result is a pointer, we use `b->area()` to call the method.

---

## 9. Arrays of Objects

To create several objects at once, use `new Type[n]`. To free them, use `delete[]` — with the square brackets.

```cpp
#include <iostream>
using namespace std;

struct Point {
    int x;
    int y;
};

int main() {
    Point* pts = new Point[2];   // 2 Points on the heap

    pts[0].x = 1;  pts[0].y = 2; // pts[0] is an object -> use the dot
    pts[1].x = 3;  pts[1].y = 4;

    cout << pts[0].x << " " << pts[1].y << endl;  // 1 4

    delete[] pts;                // free the whole array
    return 0;
}
```

**Output:**
```
1 4
```

Three points to remember:

- `new Point[2]` makes two objects, each built with the **default constructor**.
- `pts` is a **pointer**, but `pts[0]` is an **object** — so you use the dot on `pts[0]`.
- Match `new[]` with `delete[]`, never with plain `delete`.

---

## 10. How Python Differs

Python has no pointers that you manage, and it frees memory for you. C++ makes both steps explicit.

| | Python | C++ |
|--|--------|-----|
| Through a pointer | — (no pointers) | `ptr->x` |
| Create an object | `b = Box()` | `Box* b = new Box;` |
| Free it | automatic | `delete b;` |

Python always uses the dot `.` because there are no pointers to worry about. C++ separates the two cases — `.` for an object you hold, `->` for a pointer to one — and asks you to free what you create. With that extra control comes responsibility: a forgotten `delete` leaks memory.

---

## 11. Common Mistakes

**1. Using the dot on a pointer**

**Wrong:**
```cpp
Point* ptr = &p;
ptr.x = 5;        // ptr is a pointer
```

**Correct:**
```cpp
ptr->x = 5;       // use the arrow on a pointer
```

**Explanation:** a pointer holds an address, so it needs `->` (or `(*ptr).x`).

**2. Using the arrow on an object**

**Wrong:**
```cpp
Point p;
p->x = 5;         // p is an object, not a pointer
```

**Correct:**
```cpp
p.x = 5;          // use the dot on an object
```

**Explanation:** the arrow is only for pointers; use the dot for objects you hold.

**3. Forgetting the parentheses in the long form**

**Wrong:**
```cpp
*ptr.x            // means *(ptr.x), which is not what we want
```

**Correct:**
```cpp
(*ptr).x          // dereference first, then take the member
```

**Explanation:** the dot binds tighter than `*`, so the parentheses are required. This is exactly the awkwardness that `->` removes.

**4. Forgetting to delete**

**Wrong:**
```cpp
Box* b = new Box(5, 3);
// ... never deleted -> memory leak
```

**Correct:**
```cpp
Box* b = new Box(5, 3);
delete b;         // free it when done
```

**Explanation:** heap objects stay until you free them; every `new` needs one `delete`.

**5. Wrong delete form for arrays**

**Wrong:**
```cpp
Box* arr = new Box[3];
delete arr;       // should be delete[]
```

**Correct:**
```cpp
Box* arr = new Box[3];
delete[] arr;     // match new[] with delete[]
```

**Explanation:** an array made with `new[]` must be freed with `delete[]`, or the extra objects are not cleaned up correctly.

**6. Using a pointer after delete**

**Wrong:**
```cpp
delete b;
cout << b->area();   // b is now dangling
```

**Correct:**
```cpp
delete b;
b = nullptr;         // do not use b again
```

**Explanation:** after `delete`, the memory is gone; touching the pointer is an error.

---

## 12. Practice Exercises

Try each one before opening the solution.

**Exercise 1.** Given `Point pt; Point* p = &pt;`, write the line that prints `pt`'s `x` using the arrow operator.

<details>
<summary>Click to see solution</summary>

```cpp
cout << p->x << endl;
```
</details>

**Exercise 2.** Rewrite the expression `(*ptr).name` using `->`.

<details>
<summary>Click to see solution</summary>

```cpp
ptr->name
```
</details>

**Exercise 3.** Create a `Box` on the heap with `new Box(4, 3)`, print its area through the pointer, then `delete` it.

<details>
<summary>Click to see solution</summary>

```cpp
Box* b = new Box(4, 3);
cout << b->area() << endl;   // 12
delete b;
```
</details>

**Exercise 4.** Create an array of 3 `Point` objects with `new[]`, set the first point's `x` to 10, print it, then free the array correctly.

<details>
<summary>Click to see solution</summary>

```cpp
Point* pts = new Point[3];
pts[0].x = 10;               // pts[0] is an object -> dot
cout << pts[0].x << endl;    // 10
delete[] pts;                // match new[]
```
</details>

**Exercise 5.** Given `struct Node { int value; Node* next; };` with two linked nodes, write the expression that reads the **second** node's value from a pointer `p` to the first.

<details>
<summary>Click to see solution</summary>

```cpp
p->next->value
```
</details>

**Exercise 6.** Find and fix the error: `Box* arr = new Box[3]; ... delete arr;`

<details>
<summary>Click to see solution</summary>

The array was created with `new[]`, so it must be freed with `delete[]`, not plain `delete`:

```cpp
Box* arr = new Box[3];
delete[] arr;    // correct
```
</details>

---

## 13. Summary

### Key Concepts

- The **`->`** operator reaches a member through a pointer.
- **`new`** creates an object on the heap and returns a pointer to it.
- **`delete`** frees one object; **`delete[]`** frees an array.

### Important Points

1. `ptr->x` is exactly the same as `(*ptr).x`, just clearer.
2. The arrow works for both data members and methods.
3. `new` runs the constructor; `delete` runs the destructor.
4. You can pass constructor arguments: `new Box(5, 3)`.
5. `arr` is a pointer, but `arr[i]` is an object — use the dot on it.
6. Every `new` needs one matching `delete` (or `delete[]`); after `delete`, do not use the pointer.

### Quick Reference

```cpp
Point* ptr = &p;
ptr->x;                 // member through a pointer  (= (*ptr).x)
ptr->method();          // method through a pointer

Box* b = new Box(5, 3); // one object on the heap
b->area();
delete b;               // free one object

Box* arr = new Box[3];  // array of objects
delete[] arr;           // free an array
```

### The One Rule to Remember

If the name on the left is a **pointer**, use `->`. If it is an **object**, use `.`. And every `new` needs one `delete`.
