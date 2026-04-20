# Lecture 7: Constructors and Destructors

## Table of Contents

1. [Introduction](#introduction)
2. [Constructors](#constructors)
   - [Default Constructor](#default-constructor)
   - [Parameterized Constructor](#parameterized-constructor)
   - [Constructor Overloading](#constructor-overloading)
   - [Constructor Initialization List](#constructor-initialization-list)
3. [Copy Constructor](#copy-constructor)
4. [Destructors](#destructors)
5. [Constructor and Destructor Execution Order](#constructor-and-destructor-execution-order)
6. [Common Mistakes](#common-mistakes)
7. [Practice Exercises](#practice-exercises)
8. [Summary](#summary)

---

## Introduction

A **constructor** is a special member function automatically called when an object is created. A **destructor** is a special member function automatically called when an object is destroyed. Together, they manage an object's **lifetime**.

**Why are they important?**
- They ensure objects always start in a valid, predictable state.
- They prevent resource leaks (memory, file handles, etc.).
- They enforce class invariants without relying on the caller.
- They are fundamental to C++'s *RAII* (Resource Acquisition Is Initialization) idiom.

**Real-world analogies:**
- A constructor is like a factory that assembles a product before shipping it — the customer always gets something ready to use.
- A destructor is like a recycling process that runs when you're done — it cleans up automatically so you don't have to remember.
- Think of hotel check-in (constructor) and check-out (destructor) — the room is prepared for you and cleaned after you leave.

---

## Constructors

A constructor has the **same name as the class** and **no return type** (not even `void`). It runs automatically when you create an object.

### Default Constructor

A default constructor takes **no parameters**. If you define no constructor at all, the compiler generates one for you; once you define any constructor, the compiler no longer generates it.

```cpp
#include <iostream>
using namespace std;

class Box {
public:
    double length;
    double width;
    double height;

    // Default constructor
    Box() {
        length = 1.0;
        width  = 1.0;
        height = 1.0;
        cout << "Box created with default size 1x1x1\n";
    }

    double volume() {
        return length * width * height;
    }
};

int main() {
    Box b;   // default constructor called automatically
    cout << "Volume: " << b.volume() << "\n";
    return 0;
}
```

**Output:**
```
Box created with default size 1x1x1
Volume: 1
```

---

### Parameterized Constructor

A parameterized constructor accepts arguments so each object can be initialized with different values.

```cpp
#include <iostream>
using namespace std;

class Box {
public:
    double length, width, height;

    // Parameterized constructor
    Box(double l, double w, double h) {
        length = l;
        width  = w;
        height = h;
        cout << "Box created: " << l << " x " << w << " x " << h << "\n";
    }

    double volume() { return length * width * height; }
};

int main() {
    Box b1(2.0, 3.0, 4.0);
    Box b2(5.0, 5.0, 5.0);
    cout << "b1 volume: " << b1.volume() << "\n";
    cout << "b2 volume: " << b2.volume() << "\n";
    return 0;
}
```

**Output:**
```
Box created: 2 x 3 x 4
Box created: 5 x 5 x 5
b1 volume: 24
b2 volume: 125
```

---

### Constructor Overloading

You can define **multiple constructors** with different parameter lists. The compiler selects the correct one based on the arguments you provide.

```cpp
#include <iostream>
using namespace std;

class Student {
public:
    string name;
    int    age;
    double gpa;

    // Default constructor
    Student() {
        name = "Unknown";
        age  = 0;
        gpa  = 0.0;
    }

    // Name only
    Student(string n) {
        name = n;
        age  = 0;
        gpa  = 0.0;
    }

    // Full constructor
    Student(string n, int a, double g) {
        name = n;
        age  = a;
        gpa  = g;
    }

    void print() {
        cout << name << " | age: " << age << " | GPA: " << gpa << "\n";
    }
};

int main() {
    Student s1;
    Student s2("Alice");
    Student s3("Bob", 20, 3.8);
    s1.print();
    s2.print();
    s3.print();
    return 0;
}
```

**Output:**
```
Unknown | age: 0 | GPA: 0
Alice | age: 0 | GPA: 0
Bob | age: 20 | GPA: 3.8
```

---

### Constructor Initialization List

An **initialization list** initializes members *before* the constructor body runs. It is required for `const` members, reference members, and base-class sub-objects, and is generally more efficient.

```cpp
#include <iostream>
using namespace std;

class Point {
public:
    const int x;  // const — must be initialized in list
    const int y;

    // Initialization list after the colon
    Point(int xVal, int yVal) : x(xVal), y(yVal) {
        cout << "Point(" << x << ", " << y << ") created\n";
    }
};

int main() {
    Point p1(3, 4);
    Point p2(0, 0);
    cout << "p1: (" << p1.x << ", " << p1.y << ")\n";
    cout << "p2: (" << p2.x << ", " << p2.y << ")\n";
    return 0;
}
```

**Output:**
```
Point(3, 4) created
Point(0, 0) created
p1: (3, 4)
p2: (0, 0)
```

---

## Copy Constructor

A **copy constructor** creates a new object as a copy of an existing one. Its signature is always `ClassName(const ClassName& other)`.

If you do not define one, the compiler provides a shallow copy; for classes that own heap memory you must write your own **deep copy**.

```cpp
#include <iostream>
using namespace std;

class Rectangle {
public:
    double width, height;

    Rectangle(double w, double h) : width(w), height(h) {}

    // Copy constructor
    Rectangle(const Rectangle& other) {
        width  = other.width;
        height = other.height;
        cout << "Copy constructor called\n";
    }

    double area() { return width * height; }
};

int main() {
    Rectangle r1(4.0, 5.0);
    Rectangle r2 = r1;        // copy constructor
    Rectangle r3(r1);         // copy constructor (explicit)

    cout << "r1 area: " << r1.area() << "\n";
    cout << "r2 area: " << r2.area() << "\n";

    r2.width = 10.0;           // does NOT affect r1 (independent copy)
    cout << "After modifying r2:\n";
    cout << "r1 area: " << r1.area() << "\n";
    cout << "r2 area: " << r2.area() << "\n";
    return 0;
}
```

**Output:**
```
Copy constructor called
Copy constructor called
r1 area: 20
r2 area: 20
After modifying r2:
r1 area: 20
r2 area: 50
```

---

## Destructors

A **destructor** is called automatically when an object goes out of scope or is explicitly deleted. It has the same name as the class preceded by a `~`, takes no parameters, and returns nothing.

```cpp
#include <iostream>
using namespace std;

class FileManager {
public:
    string filename;

    FileManager(string name) : filename(name) {
        cout << "Opening file: " << filename << "\n";
    }

    // Destructor
    ~FileManager() {
        cout << "Closing file: " << filename << "\n";
        // In real code you would close the file handle here
    }

    void write(string data) {
        cout << "Writing \"" << data << "\" to " << filename << "\n";
    }
};

int main() {
    cout << "--- entering block ---\n";
    {
        FileManager f("data.txt");
        f.write("Hello, World!");
    }  // destructor called here as f goes out of scope
    cout << "--- after block ---\n";
    return 0;
}
```

**Output:**
```
--- entering block ---
Opening file: data.txt
Writing "Hello, World!" to data.txt
Closing file: data.txt
--- after block ---
```

---

## Constructor and Destructor Execution Order

Constructors run in **creation order**; destructors run in **reverse order** (LIFO — last in, first out).

```cpp
#include <iostream>
using namespace std;

class Device {
public:
    string name;

    Device(string n) : name(n) {
        cout << "Constructing: " << name << "\n";
    }

    ~Device() {
        cout << "Destroying:   " << name << "\n";
    }
};

int main() {
    Device d1("Keyboard");
    Device d2("Monitor");
    Device d3("Speaker");
    cout << "--- all devices active ---\n";
    return 0;
    // d3 destroyed first, then d2, then d1
}
```

**Output:**
```
Constructing: Keyboard
Constructing: Monitor
Constructing: Speaker
--- all devices active ---
Destroying:   Speaker
Destroying:   Monitor
Destroying:   Keyboard
```

---

## Common Mistakes

### Mistake 1 — Forgetting to initialize all members

**Wrong:**
```cpp
class Circle {
public:
    double radius;
    Circle() {}           // radius is uninitialized — undefined behavior!
};
```

**Correct:**
```cpp
class Circle {
public:
    double radius;
    Circle() : radius(0.0) {}  // always initialize every member
};
```

**Explanation:** Uninitialized members have garbage values. Always initialize all members in the constructor.

---

### Mistake 2 — Giving the constructor a return type

**Wrong:**
```cpp
void Box() {   // compiler error: constructors have no return type
    length = 1.0;
}
```

**Correct:**
```cpp
Box() {        // no return type at all, not even void
    length = 1.0;
}
```

**Explanation:** Constructors and destructors must never have a return type.

---

### Mistake 3 — Using assignment instead of initialization list for `const` members

**Wrong:**
```cpp
class Point {
    const int x;
    Point(int val) { x = val; }   // compile error: x is const
};
```

**Correct:**
```cpp
class Point {
    const int x;
    Point(int val) : x(val) {}    // initialization list required
};
```

**Explanation:** `const` (and reference) members must be initialized in the initialization list, not assigned in the body.

---

### Mistake 4 — Calling the destructor explicitly (almost never correct)

**Wrong:**
```cpp
Box b(2, 3, 4);
b.~Box();   // destructor called now; called again when b goes out of scope → double destroy
```

**Correct:**
```cpp
Box b(2, 3, 4);
// Just let it go out of scope; the destructor runs automatically.
```

**Explanation:** Explicitly calling a destructor causes it to run twice, leading to undefined behavior.

---

### Mistake 5 — Shallow copy of heap-allocated memory

**Wrong:**
```cpp
class Buffer {
public:
    int* data;
    Buffer(int n) { data = new int[n]; }
    ~Buffer()     { delete[] data; }
    // No copy constructor → compiler generates shallow copy
    // Two objects share the same pointer → double delete!
};
```

**Correct:**
```cpp
class Buffer {
public:
    int* data;
    int  size;
    Buffer(int n) : size(n) { data = new int[n]; }
    Buffer(const Buffer& other) : size(other.size) {
        data = new int[size];
        for (int i = 0; i < size; i++) data[i] = other.data[i];
    }
    ~Buffer() { delete[] data; }
};
```

**Explanation:** When a class owns heap memory, always define a copy constructor (and assignment operator) that performs a deep copy.

---

## Practice Exercises

### Exercise 1 — BankAccount class
Create a `BankAccount` class with an `owner` (string) and `balance` (double). Write a default constructor (balance = 0) and a parameterized constructor. Add a `deposit(double)` method and a destructor that prints a closing message.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

class BankAccount {
public:
    string owner;
    double balance;

    BankAccount() : owner("Anonymous"), balance(0.0) {
        cout << "Account created for " << owner << "\n";
    }

    BankAccount(string o, double b) : owner(o), balance(b) {
        cout << "Account created for " << owner << " with $" << b << "\n";
    }

    void deposit(double amount) { balance += amount; }

    ~BankAccount() {
        cout << "Closing account for " << owner << ". Final balance: $" << balance << "\n";
    }
};

int main() {
    BankAccount a1;
    BankAccount a2("Alice", 500.0);
    a2.deposit(200.0);
    return 0;
}
```
</details>

---

### Exercise 2 — Constructor overloading
Create a `Temperature` class that stores a value in Celsius. Provide three constructors: default (0°C), one that takes Celsius, and one that takes Fahrenheit (convert to Celsius on entry). Add a `printCelsius()` method.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

class Temperature {
public:
    double celsius;

    Temperature() : celsius(0.0) {}
    Temperature(double c) : celsius(c) {}
    Temperature(double f, bool isFahrenheit) {
        celsius = (f - 32.0) * 5.0 / 9.0;
    }

    void printCelsius() {
        cout << celsius << " °C\n";
    }
};

int main() {
    Temperature t1;
    Temperature t2(100.0);
    Temperature t3(212.0, true);  // 212 F = 100 C

    t1.printCelsius();
    t2.printCelsius();
    t3.printCelsius();
    return 0;
}
```
</details>

---

### Exercise 3 — Destructor order
Create three simple classes `Alpha`, `Beta`, `Gamma`, each printing their name in the constructor and destructor. Instantiate one of each in `main` and observe the destruction order.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

struct Alpha { Alpha() { cout << "Alpha born\n"; } ~Alpha() { cout << "Alpha gone\n"; } };
struct Beta  { Beta()  { cout << "Beta born\n";  } ~Beta()  { cout << "Beta gone\n";  } };
struct Gamma { Gamma() { cout << "Gamma born\n"; } ~Gamma() { cout << "Gamma gone\n"; } };

int main() {
    Alpha a;
    Beta  b;
    Gamma g;
    cout << "All alive\n";
    return 0;
}
// Output:
// Alpha born  Beta born  Gamma born
// All alive
// Gamma gone  Beta gone  Alpha gone
```
</details>

---

### Exercise 4 — Initialization list practice
Create a `Person` class with `const string name` and `const int birthYear`. Use an initialization list in the constructor. Add a `getAge(int currentYear)` method.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

class Person {
public:
    const string name;
    const int    birthYear;

    Person(string n, int y) : name(n), birthYear(y) {}

    int getAge(int currentYear) { return currentYear - birthYear; }
};

int main() {
    Person p("Toni", 1990);
    cout << p.name << " is " << p.getAge(2025) << " years old.\n";
    return 0;
}
```
</details>

---

### Exercise 5 — Copy constructor
Create a `Matrix1x2` class (two doubles). Write a copy constructor. Verify that modifying the copy does NOT affect the original.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

class Matrix1x2 {
public:
    double a, b;

    Matrix1x2(double x, double y) : a(x), b(y) {}

    Matrix1x2(const Matrix1x2& other) : a(other.a), b(other.b) {
        cout << "Copy constructor called\n";
    }

    void print() { cout << "[" << a << ", " << b << "]\n"; }
};

int main() {
    Matrix1x2 m1(1.0, 2.0);
    Matrix1x2 m2 = m1;
    m2.a = 99.0;
    cout << "m1: "; m1.print();
    cout << "m2: "; m2.print();
    return 0;
}
```
</details>

---

## Summary

### Key Concepts

- A **constructor** initializes an object when it is created.
- A **destructor** cleans up an object when it is destroyed.
- **Overloading** allows multiple constructors with different parameters.
- **Initialization lists** are the preferred way to initialize members.
- **Copy constructors** control how objects are duplicated.
- **Destruction order** is always the reverse of construction order.

### Important Points

1. Constructors and destructors have the **same name** as the class (destructor adds `~`).
2. Neither has a return type — not even `void`.
3. If you define no constructor, the compiler generates a default one; once you define any constructor, the default is no longer auto-generated.
4. The destructor is called **automatically** — you almost never call it manually.
5. Use initialization lists for `const` members, references, and efficiency.
6. If your class owns heap memory, define a **copy constructor** (and likely `operator=` and destructor — the Rule of Three).
7. Objects are destroyed in **reverse order** of construction.
8. Destructors of local objects run when execution leaves their enclosing scope.

### Quick Reference

```cpp
class MyClass {
public:
    int value;

    MyClass()           : value(0)   {}          // default constructor
    MyClass(int v)      : value(v)   {}          // parameterized constructor
    MyClass(const MyClass& o) : value(o.value) {} // copy constructor
    ~MyClass() { /* cleanup */ }                  // destructor
};
```

### Next Steps

Next lecture we will explore **operator overloading** — defining how `+`, `-`, `==`, and other operators behave on custom objects, building directly on the constructors you learned today.
