# Lecture: Inheritance in OOP — C++

> **Prerequisites:** Students should be familiar with classes, objects, and encapsulation.

---

## Table of Contents

1. [Introduction to Inheritance](#introduction)
2. [Basic Syntax](#basic-syntax)
3. [The "is-a" Relationship](#is-a-relationship)
4. [Types of Inheritance](#types-of-inheritance)
   - [Single Inheritance](#single-inheritance)
   - [Multi-Level Inheritance](#multi-level-inheritance)
   - [Multiple Inheritance](#multiple-inheritance)
   - [Hierarchical Inheritance](#hierarchical-inheritance)
5. [Access Specifiers in Inheritance](#access-specifiers)
6. [The `protected` Keyword](#protected-keyword)
7. [Constructor & Destructor Order](#constructor-destructor-order)
8. [Method Overriding](#method-overriding)
9. [Calling Parent Methods](#calling-parent-methods)
10. [Common Mistakes](#common-mistakes)
11. [Practice Exercises](#practice-exercises)
12. [Summary](#summary)

---

## 1. Introduction to Inheritance <a name="introduction"></a>

Inheritance is a mechanism that lets a new class **reuse, extend, and modify** the behavior of an existing class. The existing class is called the **base class** (or parent), and the new class is called the **derived class** (or child).

### Why is it important?

- ✅ Avoids code duplication (write once, reuse everywhere)
- ✅ Models real-world relationships naturally
- ✅ Makes code easier to maintain and extend
- ✅ Enables polymorphism (next lecture topic)

### Real-World Analogy 🏠

Think of a **family**:
- A **child** inherits traits from their **parent** (eye color, height)
- But the child also has **their own** unique traits
- Inheritance in C++ works the same way — a derived class inherits members from its base class but can add its own

---

## 2. Basic Syntax <a name="basic-syntax"></a>

```cpp
class BaseClass {
    // base class members
};

class DerivedClass : access_specifier BaseClass {
    // inherited + new members
};
```

### Example: Animal → Dog

```cpp
#include <iostream>
using namespace std;

class Animal {
public:
    string name;
    void eat() {
        cout << name << " is eating." << endl;
    }
};

class Dog : public Animal {
public:
    void bark() {
        cout << name << " says: Woof!" << endl;
    }
};

int main() {
    Dog myDog;
    myDog.name = "Buddy";
    myDog.eat();   // inherited from Animal
    myDog.bark();  // Dog's own method
    return 0;
}
```

**Output:**
```
Buddy is eating.
Buddy says: Woof!
```

> 🧠 **Metaphor:** `Animal` is a recipe for "any animal." `Dog` takes that recipe and adds extra steps (barking).

---

## 3. The "is-a" Relationship <a name="is-a-relationship"></a>

Use inheritance only when the derived class **is-a** type of the base class.

| Correct ✅ | Incorrect ❌ |
|-----------|------------|
| Dog **is-a** Animal | Car **is-a** Engine |
| Car **is-a** Vehicle | Wheel **is-a** Car |
| Student **is-a** Person | Teacher **is-a** Classroom |

> 🧠 **Test:** Ask yourself — "Is a [Derived] always a [Base]?" If yes, inheritance is appropriate.

---

## 4. Types of Inheritance <a name="types-of-inheritance"></a>

### 4.1 Single Inheritance <a name="single-inheritance"></a>

One derived class, one base class.

```
Animal
  └── Dog
```

```cpp
#include <iostream>
using namespace std;

class Vehicle {
public:
    int speed;
    void move() {
        cout << "Vehicle moving at " << speed << " km/h" << endl;
    }
};

class Car : public Vehicle {
public:
    string brand;
    void honk() {
        cout << brand << " says: Beep!" << endl;
    }
};

int main() {
    Car c;
    c.brand = "Toyota";
    c.speed = 120;
    c.move();
    c.honk();
    return 0;
}
```

**Output:**
```
Vehicle moving at 120 km/h
Toyota says: Beep!
```

---

### 4.2 Multi-Level Inheritance <a name="multi-level-inheritance"></a>

A chain of inheritance — grandparent → parent → child.

```
Animal → Mammal → Dog
```

> 🧠 **Metaphor:** Your grandparent passed traits to your parent, who passed them to you.

```cpp
#include <iostream>
using namespace std;

class Animal {
public:
    void breathe() { cout << "Breathing..." << endl; }
};

class Mammal : public Animal {
public:
    void feedMilk() { cout << "Feeding milk to offspring." << endl; }
};

class Dog : public Mammal {
public:
    void bark() { cout << "Woof!" << endl; }
};

int main() {
    Dog d;
    d.breathe();    // from Animal
    d.feedMilk();  // from Mammal
    d.bark();       // from Dog
    return 0;
}
```

**Output:**
```
Breathing...
Feeding milk to offspring.
Woof!
```

---

### 4.3 Multiple Inheritance <a name="multiple-inheritance"></a>

A class inherits from **more than one** base class.

```
FlyingFish : public Fish, public Bird
```

> 🧠 **Metaphor:** A smartphone is both a **camera** and a **phone** — it inherits features from both.

```cpp
#include <iostream>
using namespace std;

class Camera {
public:
    void takePhoto() { cout << "📸 Photo taken!" << endl; }
};

class Phone {
public:
    void makeCall() { cout << "📞 Calling..." << endl; }
};

class SmartPhone : public Camera, public Phone {
public:
    void browseInternet() { cout << "🌐 Browsing..." << endl; }
};

int main() {
    SmartPhone sp;
    sp.takePhoto();
    sp.makeCall();
    sp.browseInternet();
    return 0;
}
```

**Output:**
```
📸 Photo taken!
📞 Calling...
🌐 Browsing...
```

---

### 4.4 Hierarchical Inheritance <a name="hierarchical-inheritance"></a>

Multiple derived classes share one base class.

```
        Animal
       /      \
     Dog      Cat
```

```cpp
#include <iostream>
using namespace std;

class Shape {
public:
    string color;
    void display() {
        cout << "Shape color: " << color << endl;
    }
};

class Circle : public Shape {
public:
    double radius;
    double area() { return 3.14 * radius * radius; }
};

class Rectangle : public Shape {
public:
    double width, height;
    double area() { return width * height; }
};

int main() {
    Circle c;
    c.color = "Red";
    c.radius = 5;
    c.display();
    cout << "Circle area: " << c.area() << endl;

    Rectangle r;
    r.color = "Blue";
    r.width = 4;
    r.height = 6;
    r.display();
    cout << "Rectangle area: " << r.area() << endl;

    return 0;
}
```

**Output:**
```
Shape color: Red
Circle area: 78.5
Shape color: Blue
Rectangle area: 24
```

---

## 5. Access Specifiers in Inheritance <a name="access-specifiers"></a>

The access specifier used during inheritance changes how the parent's members are visible in the child.

| Base Member | `public` inheritance | `protected` inheritance | `private` inheritance |
|------------|---------------------|------------------------|----------------------|
| `public`   | `public`            | `protected`            | `private`            |
| `protected`| `protected`         | `protected`            | `private`            |
| `private`  | ❌ Not inherited    | ❌ Not inherited       | ❌ Not inherited     |

> 🔑 **Rule of thumb:** Use `public` inheritance unless you have a specific reason not to.

---

## 6. The `protected` Keyword <a name="protected-keyword"></a>

`protected` members are like family secrets — accessible within the class AND its children, but hidden from the outside world.

```cpp
#include <iostream>
using namespace std;

class BankAccount {
protected:
    double balance;  // accessible in child class

public:
    BankAccount(double b) : balance(b) {}
};

class SavingsAccount : public BankAccount {
public:
    SavingsAccount(double b) : BankAccount(b) {}

    void addInterest(double rate) {
        balance += balance * rate;  // can access protected member
        cout << "New balance: " << balance << endl;
    }
};

int main() {
    SavingsAccount sa(1000.0);
    sa.addInterest(0.05);
    // sa.balance = 5000; ❌ ERROR - protected, not accessible from outside
    return 0;
}
```

**Output:**
```
New balance: 1050
```

---

## 7. Constructor & Destructor Order <a name="constructor-destructor-order"></a>

When you create a derived object:
1. **Base constructor** runs first
2. **Derived constructor** runs second

When destroyed:
1. **Derived destructor** runs first
2. **Base destructor** runs second

> 🧠 **Metaphor:** Building a house — foundation (base) first, then walls (derived). Demolishing — walls first, then foundation.

```cpp
#include <iostream>
using namespace std;

class Base {
public:
    Base()  { cout << "Base Constructor" << endl; }
    ~Base() { cout << "Base Destructor"  << endl; }
};

class Derived : public Base {
public:
    Derived()  { cout << "Derived Constructor" << endl; }
    ~Derived() { cout << "Derived Destructor"  << endl; }
};

int main() {
    Derived d;
    return 0;
}
```

**Output:**
```
Base Constructor
Derived Constructor
Derived Destructor
Base Destructor
```

---

## 8. Method Overriding <a name="method-overriding"></a>

A derived class can **redefine** a method from the base class with the same name and parameters.

> 🧠 **Metaphor:** You inherited a recipe from your parent but you added your own twist — that's overriding!

```cpp
#include <iostream>
using namespace std;

class Animal {
public:
    void makeSound() {
        cout << "Some generic animal sound" << endl;
    }
};

class Cat : public Animal {
public:
    void makeSound() {   // Overrides Animal's makeSound
        cout << "Meow!" << endl;
    }
};

class Dog : public Animal {
public:
    void makeSound() {   // Overrides Animal's makeSound
        cout << "Woof!" << endl;
    }
};

int main() {
    Cat c;
    Dog d;
    c.makeSound();  // Meow!
    d.makeSound();  // Woof!
    return 0;
}
```

**Output:**
```
Meow!
Woof!
```

---

## 9. Calling Parent Methods <a name="calling-parent-methods"></a>

Use `BaseClass::method()` to call the parent's version of an overridden method.

```cpp
#include <iostream>
using namespace std;

class Employee {
public:
    void introduce() {
        cout << "I am an employee." << endl;
    }
};

class Manager : public Employee {
public:
    void introduce() {
        Employee::introduce();  // call parent's version
        cout << "I am also a Manager." << endl;
    }
};

int main() {
    Manager m;
    m.introduce();
    return 0;
}
```

**Output:**
```
I am an employee.
I am also a Manager.
```

---

## 10. Common Mistakes <a name="common-mistakes"></a>

### ❌ Mistake 1: Trying to access private base members

**Wrong:**
```cpp
class Animal {
private:
    int age;
};

class Dog : public Animal {
public:
    void showAge() { cout << age; }  // ERROR!
};
```

**Correct:**
```cpp
class Animal {
protected:
    int age;  // use protected
};
```

**Explanation:** Private members are not inherited. Use `protected` if child classes need access.

---

### ❌ Mistake 2: Forgetting to pass arguments to base constructor

**Wrong:**
```cpp
class Person {
public:
    Person(string name) { }
};

class Student : public Person {
public:
    Student() { }  // ERROR: no call to Person(name)
};
```

**Correct:**
```cpp
class Student : public Person {
public:
    Student(string name) : Person(name) { }  // pass to base
};
```

**Explanation:** If the base class has a parameterized constructor, you must call it explicitly using the initializer list.

---

### ❌ Mistake 3: Confusing "has-a" with "is-a"

**Wrong:**
```cpp
class Engine { };
class Car : public Engine { };  // Car IS-A Engine? No!
```

**Correct:**
```cpp
class Engine { };
class Car {
    Engine engine;  // Car HAS-A Engine
};
```

**Explanation:** Use inheritance for "is-a" relationships, and composition for "has-a" relationships.

---

### ❌ Mistake 4: Overriding with different return type unintentionally

**Wrong:**
```cpp
class Base {
public:
    int getValue() { return 42; }
};

class Derived : public Base {
public:
    double getValue() { return 3.14; }  // ERROR: different return type
};
```

**Correct:**
```cpp
class Derived : public Base {
public:
    int getValue() { return 100; }  // same return type
};
```

**Explanation:** Overriding requires the exact same function signature (name, parameters, return type).

---

### ❌ Mistake 5: Diamond problem with multiple inheritance

**Wrong:**
```cpp
class A { public: void show() { } };
class B : public A { };
class C : public A { };
class D : public B, public C { };
// D::show() is ambiguous!
```

**Correct:**
```cpp
class A { public: void show() { } };
class B : virtual public A { };
class C : virtual public A { };
class D : public B, public C { };
// Now only one copy of A exists
```

**Explanation:** Use `virtual` inheritance to resolve the diamond problem in multiple inheritance.

---

## 11. Practice Exercises <a name="practice-exercises"></a>

### Exercise 1 — Basic Inheritance
Create a `Vehicle` base class with `speed` and `fuel`. Derive a `Truck` class that adds `cargoWeight`. Display all properties.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

class Vehicle {
public:
    int speed;
    string fuel;
    void display() {
        cout << "Speed: " << speed << ", Fuel: " << fuel << endl;
    }
};

class Truck : public Vehicle {
public:
    double cargoWeight;
    void display() {
        Vehicle::display();
        cout << "Cargo Weight: " << cargoWeight << " tons" << endl;
    }
};

int main() {
    Truck t;
    t.speed = 90;
    t.fuel = "Diesel";
    t.cargoWeight = 5.5;
    t.display();
    return 0;
}
```
</details>

---

### Exercise 2 — Multi-Level Inheritance
Create `LivingThing → Plant → FloweringPlant`. Add a unique method to each level.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

class LivingThing {
public:
    void grow() { cout << "Growing..." << endl; }
};

class Plant : public LivingThing {
public:
    void photosynthesize() { cout << "Photosynthesizing..." << endl; }
};

class FloweringPlant : public Plant {
public:
    void bloom() { cout << "Blooming 🌸" << endl; }
};

int main() {
    FloweringPlant fp;
    fp.grow();
    fp.photosynthesize();
    fp.bloom();
    return 0;
}
```
</details>

---

### Exercise 3 — Access with `protected`
Create a `BankAccount` with a protected `balance`. Derive `CheckingAccount` that can deduct from balance.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

class BankAccount {
protected:
    double balance;
public:
    BankAccount(double b) : balance(b) {}
    void showBalance() { cout << "Balance: $" << balance << endl; }
};

class CheckingAccount : public BankAccount {
public:
    CheckingAccount(double b) : BankAccount(b) {}
    void deduct(double amount) {
        if (amount <= balance)
            balance -= amount;
        else
            cout << "Insufficient funds!" << endl;
    }
};

int main() {
    CheckingAccount ca(500.0);
    ca.showBalance();
    ca.deduct(200.0);
    ca.showBalance();
    ca.deduct(400.0);
    return 0;
}
```
</details>

---

### Exercise 4 — Method Overriding
Create a `Shape` class with `area()` returning 0. Override it in `Circle` and `Rectangle`.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

class Shape {
public:
    double area() { return 0; }
};

class Circle : public Shape {
    double r;
public:
    Circle(double r) : r(r) {}
    double area() { return 3.14 * r * r; }
};

class Rectangle : public Shape {
    double w, h;
public:
    Rectangle(double w, double h) : w(w), h(h) {}
    double area() { return w * h; }
};

int main() {
    Circle c(5);
    Rectangle r(4, 6);
    cout << "Circle area: " << c.area() << endl;
    cout << "Rectangle area: " << r.area() << endl;
    return 0;
}
```
</details>

---

### Exercise 5 — Constructor Chaining
Create `Person(name)` → `Student(name, id)` → `GradStudent(name, id, thesis)` using constructor chaining.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

class Person {
protected:
    string name;
public:
    Person(string n) : name(n) {}
    void display() { cout << "Name: " << name << endl; }
};

class Student : public Person {
protected:
    int id;
public:
    Student(string n, int i) : Person(n), id(i) {}
    void display() {
        Person::display();
        cout << "ID: " << id << endl;
    }
};

class GradStudent : public Student {
    string thesis;
public:
    GradStudent(string n, int i, string t) : Student(n, i), thesis(t) {}
    void display() {
        Student::display();
        cout << "Thesis: " << thesis << endl;
    }
};

int main() {
    GradStudent gs("Alice", 1001, "AI in Medicine");
    gs.display();
    return 0;
}
```
</details>

---

## 12. Summary <a name="summary"></a>

### Key Concepts

- **Base class** = parent, **Derived class** = child
- Derived classes inherit all `public` and `protected` members
- Use `public` inheritance for "is-a" relationships
- `protected` allows child classes to access members while hiding from outside
- Constructors run base-first, destructors run derived-first
- Method overriding lets derived classes redefine inherited behavior
- Use `Base::method()` to call the parent version

### Important Points

1. Always verify the "is-a" relationship before using inheritance
2. Use `protected` (not `private`) for data you want child classes to access
3. Always pass required arguments to the base constructor via initializer lists
4. Overriding requires the exact same signature (name, params, return type)
5. Multiple inheritance can cause the diamond problem — use `virtual` inheritance to fix
6. Destructors run in reverse order of constructors
7. Prefer composition ("has-a") when the "is-a" test fails
8. Inheritance promotes code reuse but can increase coupling — use judiciously

### Quick Reference

```cpp
// Class definition with inheritance
class Derived : public Base {
public:
    Derived(int x) : Base(x) { }   // call base constructor
    void method() override {        // override base method
        Base::method();             // optionally call parent's version
        // extra behavior here
    }
};
```

### Next Steps — Polymorphism & Virtual Functions

- `virtual` keyword enables runtime polymorphism
- Base class pointers pointing to derived objects
- Pure virtual functions and abstract classes
- The power of OOP: write code that works for any future class!
