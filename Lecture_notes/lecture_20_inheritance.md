# CS143 — OOP Inheritance

> **Course:** CS143 Introduction to C++ · **Instructor:** Dr. Fawaz Alazemi
> **OOP Pillar 3** · **Builds on:** Lectures 13–15 (OOP intro, encapsulation, constructors &amp; destructors).

---

## Table of Contents

1. [Introduction](#1-introduction)
2. [Declaring a Derived Class](#2-declaring-a-derived-class)
3. [Inherited vs. Own Members](#3-inherited-vs-own-members)
4. [protected — Sharing With Children](#4-protected--sharing-with-children)
5. [Calling the Parent Constructor](#5-calling-the-parent-constructor)
6. [Overriding a Parent Method](#6-overriding-a-parent-method)
7. [Calling the Parent's Version](#7-calling-the-parents-version)
8. [Multi-Level Inheritance](#8-multi-level-inheritance)
9. [Common Mistakes](#9-common-mistakes)
10. [Practice Exercises](#10-practice-exercises)
11. [Summary](#11-summary)

---

## 1. Introduction

**Inheritance** lets a new class receive the attributes and methods of an existing class for free, and then add or change whatever it needs. It is the third of the four OOP pillars, after encapsulation and abstraction.

Two names describe the relationship:

- The **parent** (or **base**) class holds the shared code.
- The **child** (or **derived**) class inherits it and adds its own details.

Without inheritance, you would copy the same data and methods into every new class — and a bug fixed in one copy stays broken in all the others. With inheritance, you write shared code **once** in the parent, and each child adds only what is different.

The guiding rule is the **is-a test**: a child class should be an *is-a* version of its parent. A `Rectangle` *is-a* `Shape`. If "a [child] is a [parent]" sounds natural, inheritance is the right tool.

```
                        +------------------------------+
                        |            Shape             |
                        |  colour, area(), describe()  |
                        +------------------------------+
                           /                        \
              inherits from                          inherits from
                         /                            \
        +--------------------------+      +----------------------+
        |        Rectangle         |      |        Circle        |
        |  width, height, area()   |      |    radius, area()    |
        +--------------------------+      +----------------------+
```

`Rectangle` and `Circle` each inherit everything in `Shape` and add their own members.

---

## 2. Declaring a Derived Class

Use a colon and the keyword `public` followed by the parent class name.

```cpp
// parent class
class Shape {
public:
    string colour;
    void describe() {
        cout << "Colour: " << colour << endl;
    }
};

// child class — inherits from Shape
class Rectangle : public Shape {
public:
    double width;
    double height;
    double area() { return width * height; }
};
```

- `class Rectangle : public Shape` means Rectangle inherits from Shape.
- The word `public` keeps the parent's public members public inside the child.
- `Rectangle` gets `colour` and `describe()` for free — no rewriting.
- `Rectangle` adds its own `width`, `height`, and `area()`.

---

## 3. Inherited vs. Own Members

A child object carries **both** sets of members: the ones it inherited and the ones it added.

```
   +-----------------------------------------+
   |            Rectangle object             |
   |  +-----------------------------------+  |
   |  |   Inherited from Shape            |  |
   |  |   colour  ·  describe()           |  |
   |  +-----------------------------------+  |
   |  +-----------------------------------+  |
   |  |   Rectangle's own                 |  |
   |  |   width  ·  height  ·  area()     |  |
   |  +-----------------------------------+  |
   +-----------------------------------------+
```

Here is a full program that uses both:

```cpp
#include <iostream>
using namespace std;

class Shape {
public:
    string colour;
    void describe() {
        cout << "Colour: " << colour << endl;
    }
};

class Rectangle : public Shape {
public:
    double width, height;
    double area() { return width * height; }
};

int main() {
    Rectangle r;
    r.colour = "blue";        // inherited from Shape
    r.width  = 5;
    r.height = 3;
    r.describe();             // inherited method
    cout << r.area() << endl; // 15
    return 0;
}
```

**Output:**
```
Colour: blue
15
```

`Rectangle` uses `colour` and `describe()` even though they are defined only in `Shape`. We wrote the colour logic once, and every shape subclass gets it.

---

## 4. protected — Sharing With Children

There are three access levels. Inheritance adds a middle case: `protected`, which is visible in child classes but hidden from outside code.

| Level | Own methods | Child class | Outside code |
|-------|:-----------:|:-----------:|:------------:|
| `public` | yes | yes | yes |
| `protected` | yes | yes | **no** |
| `private` | yes | **no** | no |

`private` members are hidden even from child classes. Use `protected` when children need direct access but outside code should not.

```cpp
class Shape {
protected:               // accessible in children
    string colour;
public:
    Shape(string c) : colour(c) { }
    void describe() {
        cout << "Colour: " << colour << endl;
    }
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(string c, double r)
        : Shape(c), radius(r) { }
    double area() {
        return 3.14159 * radius * radius;
    }
    void info() {
        // can use colour because it is protected
        cout << colour << " circle, area = " << area() << endl;
    }
};
```

If `colour` had been `private` in `Shape`, the `Circle::info()` method could not touch it.

---

## 5. Calling the Parent Constructor

When a child object is created, the **parent constructor runs first**, then the child constructor. Call the parent by name in the child's initializer list.

```
   +----------------------+   runs first   +----------------------------+
   |    Shape("blue")     | -------------> |  Rectangle("blue", 5, 3)   |
   |    sets colour       |                |  sets width, height        |
   +----------------------+                +----------------------------+

   Rectangle("blue", 5, 3) : Shape("blue") { ... }
```

A complete example:

```cpp
#include <iostream>
using namespace std;

class Shape {
protected:
    string colour;
public:
    Shape(string c) : colour(c) { }
    void describe() {
        cout << "Colour: " << colour << endl;
    }
};

class Rectangle : public Shape {
private:
    double width, height;
public:
    Rectangle(string c, double w, double h)
        : Shape(c), width(w), height(h) { }   // call parent first
    double area() { return width * height; }
    void info() {
        describe();
        cout << "Area: " << area() << endl;
    }
};

int main() {
    Rectangle r("red", 4, 5);
    r.info();
    return 0;
}
```

**Output:**
```
Colour: red
Area: 20
```

`Rectangle`'s constructor passes `"red"` up to `Shape`'s constructor, which sets `colour`. The child then handles its own `width` and `height`.

---

## 6. Overriding a Parent Method

If a child defines a method with the **same name and parameters** as one in the parent, the child's version **overrides** the parent's. Each shape can then give its own correct formula for `area()`.

```cpp
#include <iostream>
using namespace std;

class Shape {
public:
    string colour;
    Shape(string c) : colour(c) { }
    double area() { return 0; }             // base version
};

class Rectangle : public Shape {
    double w, h;
public:
    Rectangle(string c, double w, double h)
        : Shape(c), w(w), h(h) { }
    double area() { return w * h; }         // overrides Shape::area
};

class Circle : public Shape {
    double r;
public:
    Circle(string c, double r)
        : Shape(c), r(r) { }
    double area() { return 3.14159 * r * r; } // overrides Shape::area
};

int main() {
    Rectangle rect("blue", 4, 5);
    Circle    circ("red",  3);
    cout << rect.colour << " rect area = "   << rect.area() << endl;
    cout << circ.colour << " circle area = " << circ.area() << endl;
    return 0;
}
```

**Output:**
```
blue rect area = 20
red circle area = 28.2743
```

Both shapes inherit `colour` from `Shape`, but each overrides `area()` with its own formula. (This is the stepping stone to **polymorphism**, the next lecture.)

---

## 7. Calling the Parent's Version

An overriding method can still call the parent's version explicitly with `Parent::method()`. This lets the child **extend** the parent's behaviour rather than replace it entirely.

```cpp
class Shape {
public:
    string colour;
    Shape(string c) : colour(c) { }
    void describe() {
        cout << "Colour: " << colour << endl;
    }
};

class Rectangle : public Shape {
    double w, h;
public:
    Rectangle(string c, double w, double h)
        : Shape(c), w(w), h(h) { }
    void describe() {
        Shape::describe();       // call the parent version first
        cout << "Size: " << w << " x " << h << endl;
    }
};
```

**If we call `r.describe()` on a green 5×3 rectangle:**
```
Colour: green
Size: 5 x 3
```

The child adds its own line *after* reusing the parent's work.

---

## 8. Multi-Level Inheritance

A child can itself be a parent, forming a chain. Each level adds more specific detail.

```cpp
class Vehicle {
public:
    int speed;
};
class Car : public Vehicle {
public:
    string brand;
};
class ElectricCar : public Car {
public:
    int batteryKm;
};
```

The is-a relationship carries all the way down:

- An `ElectricCar` *is-a* `Car`.
- A `Car` *is-a* `Vehicle`.
- Therefore an `ElectricCar` *is-a* `Vehicle` too.

An `ElectricCar` object has `speed` (from `Vehicle`), `brand` (from `Car`), and `batteryKm` (its own). Keep chains short — three or more levels quickly become hard to follow.

---

## 9. Common Mistakes

**1. Accessing private parent data**

**Wrong:**
```cpp
class Shape { private: string colour; };
class Rectangle : public Shape {
    void show() { cout << colour; }   // ERROR: colour is private
};
```

**Correct:**
```cpp
class Shape { protected: string colour; };
class Rectangle : public Shape {
    void show() { cout << colour; }   // OK: protected
};
```

**Explanation:** a child cannot touch `private` members. Use `protected` to share with children.

**2. Forgetting to call the parent constructor**

**Wrong:**
```cpp
class Rectangle : public Shape {
public:
    Rectangle(string c) { }   // Shape has no default constructor -> error
};
```

**Correct:**
```cpp
class Rectangle : public Shape {
public:
    Rectangle(string c) : Shape(c) { }   // pass values up to the parent
};
```

**Explanation:** the parent's fields need the parent's constructor to set them.

**3. Missing `public` in the colon**

**Wrong:**
```cpp
class Rectangle : Shape { };   // defaults to private inheritance
```

**Correct:**
```cpp
class Rectangle : public Shape { };
```

**Explanation:** without `public`, inheritance defaults to private, making the parent's public members private in the child, so outside code can no longer call them.

**4. Confusing overriding with overloading**

**Wrong:**
```cpp
// thinking this overrides the parent's area()
double area(int scale) { return w * h * scale; }   // different parameters
```

**Correct:**
```cpp
double area() { return w * h; }   // same name AND parameters -> overrides
```

**Explanation:** overriding keeps the **same signature**; changing the parameters is overloading, a different thing.

**5. Using is-a when it should be has-a**

**Wrong:**
```cpp
class Car : public Engine { };   // a Car is not an Engine
```

**Correct:**
```cpp
class Car {
    Engine engine;               // a Car HAS an Engine
};
```

**Explanation:** inheritance models *is-a*. When one thing merely *contains* another, make it a member instead.

---

## 10. Practice Exercises

Try each one before opening the solution.

**Exercise 1.** Write a `Shape` class with `colour` and `describe()`. Derive a `Triangle` that adds `base` and `height` and defines `area()` as ½ × base × height.

<details>
<summary>Click to see solution</summary>

```cpp
class Shape {
public:
    string colour;
    void describe() {
        cout << "Colour: " << colour << endl;
    }
};
class Triangle : public Shape {
public:
    double base, height;
    double area() { return 0.5 * base * height; }
};
```
</details>

**Exercise 2.** Write a `Person` class with `name` and `age`. Derive an `Employee` that adds `salary`. Use constructors at both levels.

<details>
<summary>Click to see solution</summary>

```cpp
class Person {
protected:
    string name; int age;
public:
    Person(string n, int a) : name(n), age(a) { }
    void introduce() { cout << name << endl; }
};
class Employee : public Person {
    double salary;
public:
    Employee(string n, int a, double s)
        : Person(n, a), salary(s) { }
};
```
</details>

**Exercise 3.** In `Employee`, override `introduce()` so it prints the employee's name *and* salary, calling the parent version first.

<details>
<summary>Click to see solution</summary>

```cpp
class Employee : public Person {
    double salary;
public:
    Employee(string n, int a, double s)
        : Person(n, a), salary(s) { }
    void introduce() {
        Person::introduce();           // parent version first
        cout << "Salary: " << salary << endl;
    }
};
// When called on Employee("Sara", 30, 5000):
// Sara
// Salary: 5000
```
</details>

**Exercise 4.** Write a `Vehicle → Car` hierarchy. `Vehicle` has `speed`; `Car` adds `brand`. Print both from a `Car` object.

<details>
<summary>Click to see solution</summary>

```cpp
class Vehicle {
protected: int speed;
public:
    Vehicle(int s) : speed(s) { }
};
class Car : public Vehicle {
    string brand;
public:
    Car(int s, string b) : Vehicle(s), brand(b) { }
    void print() {
        cout << brand << " " << speed << endl;
    }
};
```
</details>

**Exercise 5.** Extend it: add `ElectricCar` that inherits from `Car` and adds `batteryKm`. Create one and print all three attributes.

<details>
<summary>Click to see solution</summary>

```cpp
class ElectricCar : public Car {
    int batteryKm;
public:
    ElectricCar(int s, string b, int km)
        : Car(s, b), batteryKm(km) { }
    void print() {
        Car::print();                  // prints brand and speed
        cout << "Range: " << batteryKm << " km" << endl;
    }
};
```
</details>

**Exercise 6.** Explain in one sentence why `class Rectangle : Shape` (without `public`) could cause access problems.

<details>
<summary>Click to see solution</summary>

Because leaving out `public` makes the inheritance **private** by default, which turns the parent's `public` members into private members inside `Rectangle`, so outside code can no longer call them. Always write `class Rectangle : public Shape` for normal inheritance.
</details>

---

## 11. Summary

### Key Concepts

- **Inheritance** lets a child class receive the attributes and methods of a parent class for free.
- Write `class Rectangle : public Shape` to derive `Rectangle` from `Shape`.
- A child object carries both inherited members and its own.

### Important Points

1. `protected` members are visible in child classes but hidden from outside code; `private` members are hidden even from children.
2. Call the parent constructor from the child's initializer list: `: Shape(c)`.
3. The parent constructor always runs before the child constructor.
4. A child **overrides** a parent method by defining one with the same name and parameters.
5. Call the parent's version explicitly with `Shape::describe()` to extend rather than replace it.
6. Use inheritance only when the *is-a* test holds; use a member (*has-a*) otherwise.

### Quick Reference

```cpp
class Shape {                        // parent / base
protected:
    string colour;
public:
    Shape(string c) : colour(c) { }
    double area() { return 0; }
};

class Rectangle : public Shape {     // child / derived
    double w, h;
public:
    Rectangle(string c, double w, double h)
        : Shape(c), w(w), h(h) { }   // call parent constructor
    double area() { return w * h; }  // override
};
```

### Next Steps

Overriding sets up **polymorphism** (the next lecture): treating different derived objects through a common parent type, so the same call runs each object's own version — a choice made while the program runs.
