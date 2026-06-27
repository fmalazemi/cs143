# CS143 — Lecture 15: Constructors &amp; Destructors

> **Course:** CS143 Introduction to C++ · **Instructor:** Dr. Fawaz Alazemi
> **Builds on:** Lecture 14 (encapsulation &amp; access levels).

---

## Table of Contents

1. [Introduction](#1-introduction)
2. [Writing a Constructor](#2-writing-a-constructor)
3. [The Default Constructor](#3-the-default-constructor)
4. [Several Constructors](#4-several-constructors)
5. [What Is a Destructor?](#5-what-is-a-destructor)
6. [The Object Lifecycle](#6-the-object-lifecycle)
7. [Destructors and Memory](#7-destructors-and-memory)
8. [Common Mistakes](#8-common-mistakes)
9. [Practice Exercises](#9-practice-exercises)
10. [Summary](#10-summary)

---

## 1. Introduction

In the encapsulation lecture we gave attributes starting values by hand or with in-class defaults. That works, but it is risky: after creating an object you must remember to set every field, and forgetting one leaves the object half-ready.

```cpp
Student s;
s.setName("Sara");
s.setId(101);        // easy to forget one of these!
```

A **constructor** solves this. It is a special method that runs **automatically** when an object is created, setting it up in one step:

```cpp
Student s("Sara", 101);   // fully ready immediately
```

A constructor copies the given values into the object's attributes the moment it is born:

```
  Student s("Sara", 101)

   "Sara" ---------+          Student object
                   +----->   +---------------------+
   101 ------------+         |  name = "Sara"      |
                             |  id   = 101         |
                             +---------------------+
   the constructor copies the arguments into the attributes
```

There is also a matching method, the **destructor**, that runs automatically when an object is destroyed — useful for cleaning up. This lecture covers both.

---

## 2. Writing a Constructor

A constructor has the **same name as the class** and **no return type** (not even `void`).

```cpp
#include <iostream>
using namespace std;

class Point {
private:
    int x, y;

public:
    // constructor: same name as the class, no return type
    Point(int a, int b) {
        x = a;
        y = b;
    }
    void print() { cout << x << "," << y; }
};

int main() {
    Point p(3, 5);   // the constructor runs here
    p.print();        // 3,5
    return 0;
}
```

**Output:**
```
3,5
```

When you write `Point p(3, 5);`, C++ runs the constructor and passes `3` and `5` into it.

*A cleaner form, the **initializer list**, sets the fields directly:*
```cpp
Point(int a, int b) : x(a), y(b) { }
```

Here is the same idea with private data and a `print` method:

```cpp
class Student {
private:
    string name;
    int id;
public:
    Student(string n, int i) {   // constructor
        name = n;
        id = i;
    }
    void print() {
        cout << name << " " << id << endl;
    }
};

int main() {
    Student s("Sara", 101);
    s.print();   // Sara 101
}
```

**Output:**
```
Sara 101
```

---

## 3. The Default Constructor

A **default constructor** takes no arguments. It gives an object sensible starting values.

```cpp
class Point {
private:
    int x, y;
public:
    Point() {        // default: no arguments
        x = 0;
        y = 0;
    }
    void print() { cout << x << "," << y; }
};

int main() {
    Point p;     // no parentheses, no values
    p.print();   // 0,0
}
```

**Output:**
```
0,0
```

Create the object with just `Point p;` — no values. If you write **no** constructor at all, C++ supplies a simple empty default constructor for you.

---

## 4. Several Constructors

A class can have **more than one** constructor, as long as they differ by their parameters. C++ picks the one that matches how you create the object. (This is the same idea as overloaded functions.)

```cpp
class Box {
private:
    int w, h;
public:
    Box() {              // default
        w = 1; h = 1;
    }
    Box(int a, int b) {  // parameterized
        w = a; h = b;
    }
    int area() { return w * h; }
};

int main() {
    Box b1;          // uses Box()
    Box b2(4, 3);    // uses Box(int, int)
    cout << b1.area() << " " << b2.area();  // 1 12
    return 0;
}
```

**Output:**
```
1 12
```

---

## 5. What Is a Destructor?

A **destructor** runs automatically when an object is destroyed. Its name is the class name with a `~` in front. It takes **no arguments** and has **no return type**, and there is only **one** per class.

```cpp
class Demo {
public:
    Demo() {           // constructor
        cout << "created" << endl;
    }
    ~Demo() {          // destructor (note the ~)
        cout << "destroyed" << endl;
    }
};
```

Its job is to clean up anything the object set up.

---

## 6. The Object Lifecycle

The constructor runs at the **start** of an object's life; the destructor runs at the **end**, when the object goes out of scope.

```
   Constructor            object is used …            Destructor
   (at creation) --------------------------------->  (out of scope)
```

You can watch both run:

```cpp
#include <iostream>
using namespace std;

class Demo {
public:
    Demo()  { cout << "created" << endl; }
    ~Demo() { cout << "destroyed" << endl; }
};

int main() {
    Demo d;                     // constructor runs
    cout << "using d" << endl;
    return 0;
}   // d goes out of scope -> destructor runs
```

**Output:**
```
created
using d
destroyed
```

"created" prints when `d` is made, and "destroyed" prints automatically when `main` ends and `d` goes out of scope. (When there are several objects, they are destroyed in the reverse of the order they were created.)

---

## 7. Destructors and Memory

Recall dynamic memory: every `new` needs a `delete`. If an object reserves memory with `new`, its **destructor** is the perfect place to free it — so the cleanup happens automatically and you cannot forget it.

```cpp
#include <iostream>
using namespace std;

class IntArray {
private:
    int *data;
    int size;
public:
    IntArray(int n) {          // constructor: reserve
        size = n;
        data = new int[n];
    }
    ~IntArray() {              // destructor: free
        delete[] data;
        cout << "freed" << endl;
    }
    void set(int i, int v) { data[i] = v; }
    int  get(int i) { return data[i]; }
};

int main() {
    IntArray a(3);
    a.set(0, 10);
    cout << a.get(0) << endl;   // 10
    return 0;
}   // destructor frees the memory here
```

**Output:**
```
10
freed
```

The constructor reserves the array with `new[]`; the destructor frees it with `delete[]` automatically when the object ends. There is no way to leak the memory, because you never have to remember the `delete` yourself.

---

## 8. Common Mistakes

**1. Giving the constructor a return type**

**Wrong:**
```cpp
class Point {
public:
    void Point(int a) { }   // a constructor has NO return type
};
```

**Correct:**
```cpp
class Point {
public:
    Point(int a) { }        // no return type, not even void
};
```

**Explanation:** writing a return type turns it into an ordinary method, not a constructor.

**2. Wrong constructor name**

**Wrong:**
```cpp
class Point {
public:
    Pnt(int a) { }   // name must match the class
};
```

**Correct:**
```cpp
class Point {
public:
    Point(int a) { }
};
```

**Explanation:** the constructor's name must be exactly the class name.

**3. Forgetting the `~` on a destructor**

**Wrong:**
```cpp
class Demo {
public:
    Demo() { }       // this is the constructor again, not a destructor
};
```

**Correct:**
```cpp
class Demo {
public:
    ~Demo() { }      // a destructor starts with ~
};
```

**Explanation:** a destructor is written `~ClassName()`.

**4. Putting arguments on a destructor**

**Wrong:**
```cpp
~Demo(int n) { }   // a destructor takes no arguments
```

**Correct:**
```cpp
~Demo() { }
```

**Explanation:** a destructor never takes parameters and there is only one per class.

**5. `new` in the constructor without `delete` in the destructor**

**Wrong:**
```cpp
class Buffer {
    int *data;
public:
    Buffer(int n) { data = new int[n]; }
    // no destructor -> memory leak
};
```

**Correct:**
```cpp
class Buffer {
    int *data;
public:
    Buffer(int n) { data = new int[n]; }
    ~Buffer() { delete[] data; }
};
```

**Explanation:** if a constructor reserves memory, the destructor must free it.

---

## 9. Practice Exercises

Try each one before opening the solution.

**Exercise 1.** Write a `Point` class with a constructor `Point(int x, int y)` that sets the fields. Create one and print it.

<details>
<summary>Click to see solution</summary>

```cpp
class Point {
private:
    int x, y;
public:
    Point(int a, int b) { x = a; y = b; }
    void print() { cout << x << "," << y << endl; }
};

int main() {
    Point p(3, 5);
    p.print();   // 3,5
}
```
</details>

**Exercise 2.** Add a default constructor `Point()` that sets both fields to 0.

<details>
<summary>Click to see solution</summary>

```cpp
class Point {
private:
    int x, y;
public:
    Point() { x = 0; y = 0; }
    Point(int a, int b) { x = a; y = b; }
    void print() { cout << x << "," << y << endl; }
};

int main() {
    Point q;       q.print();   // 0,0
    Point p(3, 5); p.print();   // 3,5
}
```
</details>

**Exercise 3.** Write a `Student` class with private `name` and `id`, a constructor, and a `print()` method.

<details>
<summary>Click to see solution</summary>

```cpp
class Student {
private:
    string name;
    int id;
public:
    Student(string n, int i) { name = n; id = i; }
    void print() { cout << name << " " << id << endl; }
};
```
</details>

**Exercise 4.** Write a `Rectangle` class with a constructor `(width, height)` and an `area()` method.

<details>
<summary>Click to see solution</summary>

```cpp
class Rectangle {
private:
    int w, h;
public:
    Rectangle(int a, int b) { w = a; h = b; }
    int area() { return w * h; }
};
```
</details>

**Exercise 5.** Write a class whose constructor and destructor each print a message, and show the order of the output.

<details>
<summary>Click to see solution</summary>

```cpp
class Note {
public:
    Note()  { cout << "made" << endl; }
    ~Note() { cout << "gone" << endl; }
};

int main() {
    Note n;
    cout << "between" << endl;
}
// Output:
// made
// between
// gone
```
</details>

**Exercise 6.** Write a class that reserves an `int` array with `new[]` in its constructor and frees it with `delete[]` in its destructor.

<details>
<summary>Click to see solution</summary>

```cpp
class Buffer {
private:
    int *data;
public:
    Buffer(int n) { data = new int[n]; }   // reserve
    ~Buffer()     { delete[] data; }        // free
};
```
</details>

---

## 10. Summary

### Key Concepts

- A **constructor** runs automatically when an object is created and sets up its data.
- A **destructor** runs automatically when an object is destroyed and cleans up after it.
- You never call either by hand — C++ runs them at the right time.

### Important Points

1. A constructor has the class's name and **no return type**.
2. A **default constructor** takes no arguments; a class can have several constructors.
3. A **destructor** is written `~ClassName()`, takes no arguments, and there is one per class.
4. The constructor runs at the start of the object's life; the destructor at the end (out of scope).
5. If the constructor reserves memory with `new`, the destructor should free it with `delete`.

### Quick Reference

```cpp
class Account {
private:
    int *log;
public:
    Account() { log = new int[10]; }    // default constructor
    Account(int n) { log = new int[n]; } // another constructor
    ~Account() { delete[] log; }         // destructor: cleanup
};

Account a;        // calls Account()
Account b(50);    // calls Account(int)
// destructors run automatically when a and b go out of scope
```

### Next Steps

With constructors and destructors in hand, the OOP path continues to the remaining big ideas: **inheritance** (building new classes from existing ones) and **polymorphism**.
