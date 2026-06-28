# CS143 — Lecture 15: Structs &amp; How They Differ From Classes

> **Course:** CS143 Introduction to C++ · **Instructor:** Dr. Fawaz Alazemi
> **Builds on:** Lecture 14 (encapsulation &amp; access levels).

---

## Table of Contents

1. [Introduction](#1-introduction)
2. [Defining and Using a Struct](#2-defining-and-using-a-struct)
3. [Initializing a Struct](#3-initializing-a-struct)
4. [Structs Can Have Methods](#4-structs-can-have-methods)
5. [Arrays of Structs](#5-arrays-of-structs)
6. [Passing a Struct to a Function](#6-passing-a-struct-to-a-function)
7. [Struct vs. Class](#7-struct-vs-class)
8. [When to Use Which](#8-when-to-use-which)
9. [Common Mistakes](#9-common-mistakes)
10. [Practice Exercises](#10-practice-exercises)
11. [Summary](#11-summary)

---

## 1. Introduction

A **struct** (short for *structure*) groups several related values under one name. Instead of keeping many loose variables, you keep them together as a single record.

```
            struct Student
 +-----------------------------+
 |  name = "Sara"              |
 |  id   = 101                 |
 |  gpa  = 3.8                 |
 +-----------------------------+
   one name groups several related fields
```

Each value inside is called a **field** (or member). A struct lets you treat a group of fields as one unit — handy for records like a point, a date, or a student.

In C++, a struct is very close to a class. By the end of these notes you will see that there is only **one real difference** between them.

---

## 2. Defining and Using a Struct

Define the struct once (a blueprint), then create variables from it and reach the fields with a dot.

```cpp
#include <iostream>
using namespace std;

// define the struct
struct Point {
    int x;
    int y;
};

int main() {
    Point p;          // create one
    p.x = 3;          // set a field with a dot
    p.y = 5;
    cout << p.x << ", " << p.y << endl;  // 3, 5
    return 0;
}
```

**Output:**
```
3, 5
```

- `struct Point { ... };` defines the record.
- The values inside are the **fields**.
- Reach a field with a dot: `p.x`.
- Like a class, a struct definition ends with a semicolon: `};`.

---

## 3. Initializing a Struct

You can fill all the fields at once, in the order they were declared.

```cpp
struct Point {
    int x;
    int y;
};

int main() {
    Point p = {3, 5};    // x = 3, y = 5

    cout << p.x << endl;  // 3
    cout << p.y << endl;  // 5
    return 0;
}
```

**Output:**
```
3
5
```

`{3, 5}` fills the fields in declared order — `x` first, then `y`. This is a quick way to set up a simple record.

---

## 4. Structs Can Have Methods

In C++, a struct can hold **methods**, not just data. This makes it very close to a class.

```cpp
#include <iostream>
using namespace std;

struct Rectangle {
    int width;
    int height;

    int area() {              // a method inside a struct
        return width * height;
    }
};

int main() {
    Rectangle r = {4, 3};
    cout << r.area() << endl;   // 12
    return 0;
}
```

**Output:**
```
12
```

The method uses the struct's own fields directly, and we call it with a dot: `r.area()`.

*(Note: in the older C language, a struct could only hold data. C++ extended it to behave almost like a class.)*

---

## 5. Arrays of Structs

An array can hold whole structs, one record per slot.

```cpp
#include <iostream>
using namespace std;

struct Student {
    string name;
    int id;
};

int main() {
    Student list[2];
    list[0].name = "Sara"; list[0].id = 101;
    list[1].name = "Ali";  list[1].id = 102;

    for (int i = 0; i < 2; i++)
        cout << list[i].name << " " << list[i].id << endl;
    return 0;
}
```

**Output:**
```
Sara 101
Ali 102
```

Each slot is a complete `Student` record, and we reach a field with `list[i].name`.

---

## 6. Passing a Struct to a Function

A whole struct can be passed into a function as one value.

```cpp
#include <iostream>
using namespace std;

struct Rectangle {
    int width;
    int height;
};

int area(Rectangle r) {        // takes a whole struct
    return r.width * r.height;
}

int main() {
    Rectangle box = {5, 2};
    cout << area(box) << endl;   // 10
    return 0;
}
```

**Output:**
```
10
```

Inside the function, we read the struct's fields with a dot, just as we do anywhere else.

---

## 7. Struct vs. Class

This is the key point of the lecture. In C++, struct and class are almost identical. The **only** language-level difference is the **default access level**:

- A **struct**'s members are **public** by default.
- A **class**'s members are **private** by default.

```cpp
struct S { int a; };   // a is PUBLIC by default
class  C { int a; };   // a is PRIVATE by default

int main() {
    S s; s.a = 1;      // OK: public
    C c;
    // c.a = 1;        // ERROR: a is private
}
```

Everything else is the same — both can have data, methods, access labels (`public:`/`private:`), constructors, and inheritance.

| Feature | struct | class |
|---------|--------|-------|
| Default access | public | private |
| Can hold data | yes | yes |
| Can hold methods | yes | yes |
| Can use `public` / `private` | yes | yes |
| Constructors, inheritance | yes | yes |
| Usual purpose | plain data records | full objects with hidden data |

In short: everything a struct can do, a class can do. The only language difference is the default access.

---

## 8. When to Use Which

Choosing between them is a matter of **convention**, not a compiler rule.

**Use a struct when:**
- you just want to group a few related values,
- the data is simple and meant to be open,
- for example: a `Point`, a `Date`, or a `Colour`.

**Use a class when:**
- you want to **protect** the data (encapsulation),
- the object has real behaviour and rules,
- for example: a `BankAccount` or a `Student` with validation.

Because the compiler treats them the same apart from default access, you could use either — but following this convention makes your intent clear to anyone reading the code.

---

## 9. Common Mistakes

**1. Missing the semicolon after the struct**

**Wrong:**
```cpp
struct Point {
    int x;
    int y;
}                  // missing semicolon
```

**Correct:**
```cpp
struct Point {
    int x;
    int y;
};                 // a struct ends with };
```

**Explanation:** like a class, a struct definition must end with `};`.

**2. Wrong order in the initializer**

**Wrong:**
```cpp
struct Point { int x; int y; };
Point p = {5, 3};   // sets x=5, y=3 — maybe not what you meant
```

**Correct:**
```cpp
Point p = {3, 5};   // x=3, y=5, matching the declared order
```

**Explanation:** `{...}` fills fields in the order they were declared, so the order matters.

**3. Forgetting the dot**

**Wrong:**
```cpp
Point p;
px = 3;          // px is not a variable
```

**Correct:**
```cpp
Point p;
p.x = 3;         // reach a field with a dot
```

**Explanation:** access a field through its struct with a dot: `p.x`.

**4. Expecting privacy by default**

**Wrong:**
```cpp
struct Account { double balance; };
Account a;
a.balance = -9999;   // allowed: struct fields are public
```

**Correct:**
```cpp
struct Account {
private:
    double balance = 0;   // ask for privacy explicitly
public:
    void deposit(double x) { if (x > 0) balance += x; }
};
```

**Explanation:** struct fields are public unless you add `private:`. If you need protection, say so (or use a class).

**5. Thinking a struct can only hold data**

**Wrong:**
```cpp
// "structs can't have methods" — not true in C++
```

**Correct:**
```cpp
struct Rectangle {
    int w, h;
    int area() { return w * h; }   // methods are allowed
};
```

**Explanation:** in C++, a struct can have methods just like a class.

---

## 10. Practice Exercises

Try each one before opening the solution.

**Exercise 1.** Define a struct `Point` with `x` and `y`. Create one, set its values, and print them.

<details>
<summary>Click to see solution</summary>

```cpp
struct Point { int x; int y; };

int main() {
    Point p;
    p.x = 4; p.y = 7;
    cout << p.x << "," << p.y << endl;  // 4,7
}
```
</details>

**Exercise 2.** Define a struct `Book` with `title`, `author`, and `pages`. Create one and print its fields.

<details>
<summary>Click to see solution</summary>

```cpp
struct Book {
    string title;
    string author;
    int pages;
};

int main() {
    Book b = {"C++", "Alazemi", 300};
    cout << b.title << " by " << b.author
         << ", " << b.pages << " pages" << endl;
}
```
</details>

**Exercise 3.** Add an `area()` method to a struct `Circle` (use `3.14159 * radius * radius`).

<details>
<summary>Click to see solution</summary>

```cpp
struct Circle {
    double radius;
    double area() {
        return 3.14159 * radius * radius;
    }
};
```
</details>

**Exercise 4.** Make an array of three `Point` structs and print all of them with a loop.

<details>
<summary>Click to see solution</summary>

{% raw %}
```cpp
Point pts[3] = {{0,0},{1,2},{3,4}};
for (int i = 0; i < 3; i++)
    cout << pts[i].x << "," << pts[i].y << endl;
```
{% endraw %}

</details>

**Exercise 5.** Write a function that takes a `Rectangle` struct and returns its area.

<details>
<summary>Click to see solution</summary>

```cpp
struct Rectangle { int width; int height; };

int area(Rectangle r) {
    return r.width * r.height;
}

int main() {
    Rectangle box = {5, 2};
    cout << area(box) << endl;   // 10
}
```
</details>

**Exercise 6.** Given a struct and a class with the same fields, say which fields are usable from outside by default, and why.

<details>
<summary>Click to see solution</summary>

```cpp
struct S { int a; };   // a is PUBLIC by default
class  C { int a; };   // a is PRIVATE by default

int main() {
    S s; s.a = 1;      // OK
    C c;
    // c.a = 1;        // ERROR: private
}
```

The struct's field is usable from outside; the class's field is not. **Why:** struct members are public by default, while class members are private by default — the only difference between them[...]
</details>

---

## 11. Summary

### Key Concepts

- A **struct** groups related values (fields) under one name.
- Reach a field with a dot: `p.x`.
- In C++, a struct can have **methods**, almost like a class.

### Important Points

1. A struct definition ends with `};`.
2. `{a, b}` fills the fields in their declared order.
3. An array can hold whole structs (`list[i].name`).
4. A whole struct can be passed to a function as one value.
5. The **only** difference between struct and class is the default access: struct is **public**, class is **private**.
6. By convention, use a struct for plain data records and a class when you want to protect the data.

### Quick Reference

{% raw %}
```cpp
struct Point {        // struct: members public by default
    int x;
    int y;
    int sum() { return x + y; }   // methods allowed
};

Point p = {3, 5};     // fill fields in order
cout << p.x;          // read a field with a dot
cout << p.sum();      // call a method

// struct S { int a; };  -> a is public
// class  C { int a; };  -> a is private
```
{% endraw %}

### Next Steps

The next lecture covers **constructors** — special methods that set up an object's data the moment it is created, for both classes and structs.
