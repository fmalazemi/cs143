# C++ Programming — Introduction to Object-Oriented Programming (OOP)

## Table of Contents

1. [Introduction](#introduction)
   - [What is OOP?](#what-is-oop)
   - [Why OOP Matters](#why-oop-matters)
   - [The Four Pillars of OOP](#the-four-pillars-of-oop)
2. [Classes and Objects](#classes-and-objects)
   - [What is a Class?](#what-is-a-class)
   - [Metaphors for Understanding Classes](#metaphors-for-understanding-classes)
   - [What is an Object?](#what-is-an-object)
   - [Class vs Object](#class-vs-object)
   - [Defining a Class in C++](#defining-a-class-in-c)
   - [Creating Objects](#creating-objects)
3. [Encapsulation](#encapsulation)
   - [What is Encapsulation?](#what-is-encapsulation)
   - [Metaphors for Encapsulation](#metaphors-for-encapsulation)
   - [Access Specifiers](#access-specifiers)
   - [Private Data Members](#private-data-members)
   - [Getter and Setter Methods](#getter-and-setter-methods)
   - [Encapsulation with Validation](#encapsulation-with-validation)
   - [Benefits of Encapsulation](#benefits-of-encapsulation)
   - [Encapsulation vs No Encapsulation](#encapsulation-vs-no-encapsulation)
4. [Common Mistakes](#common-mistakes)
5. [Practice Exercises](#practice-exercises)
6. [Summary](#summary)

---

## Introduction

### What is OOP?

**Object-Oriented Programming (OOP)** is a programming paradigm that organizes software design around **objects** rather than functions and logic. An object is a self-contained unit that bundles data (attributes) and the operations (methods) that work on that data.

OOP allows you to model real-world entities in your code. Instead of thinking about sequences of instructions, you think about the "things" in your problem and how they interact.

### Why OOP Matters

- **Modularity**: Code is organized into independent, self-contained units (objects)
- **Reusability**: Classes can be reused across different programs
- **Maintainability**: Changes to one class don't break other parts of the code
- **Scalability**: Large programs become manageable by dividing them into smaller objects

**Real-world analogy**: Think of building a house. Without OOP, you'd write one giant instruction manual. With OOP, you have separate blueprints for electrical, plumbing, and structure — each independent but working together.

### The Four Pillars of OOP

| Pillar | Description |
|--------|-------------|
| **Encapsulation** | Bundling data and methods together, hiding internal details |
| **Abstraction** | Showing only essential features, hiding complexity |
| **Inheritance** | Creating new classes from existing ones |
| **Polymorphism** | Same interface, different behaviors |

This lecture focuses primarily on **Encapsulation** — the foundation upon which the other three pillars are built.

---

## Classes and Objects

### What is a Class?

A **class** is a user-defined data type that serves as a **blueprint** for creating objects. It defines:
- **Data members** (attributes/properties): What the object *knows*
- **Member functions** (methods): What the object *can do*

A class itself is not an object — it's the template from which objects are created.

### Metaphors for Understanding Classes

#### Metaphor 1: The Blueprint

A class is like an **architectural blueprint** for a house. The blueprint defines the layout — how many rooms, where the doors go, the dimensions. But the blueprint is not a house itself. You can build many houses from the same blueprint, and each house (object) is independent.

#### Metaphor 2: The Cookie Cutter

A class is like a **cookie cutter**. The cutter defines the shape, but it's not a cookie. You press the cutter into dough to create cookies (objects). Each cookie has the same shape but can have different decorations (different attribute values).

#### Metaphor 3: The Form Template

A class is like a **blank form** (e.g., a registration form). The form defines what information is needed (name, age, email) — but the form itself doesn't contain any actual data until someone fills it out. Each filled-in form is an object.

### What is an Object?

An **object** is a specific instance of a class. When you create an object, memory is allocated and the object gets its own copy of the data members defined by the class.

```cpp
#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    string name;
    int age;

    void introduce() {
        cout << "Hi, I'm " << name << " and I'm " << age << " years old." << endl;
    }
};

int main() {
    Student s1;          // s1 is an object of class Student
    s1.name = "Alice";
    s1.age = 20;
    s1.introduce();

    Student s2;          // s2 is another object — independent from s1
    s2.name = "Bob";
    s2.age = 22;
    s2.introduce();

    return 0;
}
```

**Output:**
```
Hi, I'm Alice and I'm 20 years old.
Hi, I'm Bob and I'm 22 years old.
```

### Class vs Object

| Class | Object |
|-------|--------|
| Blueprint / Template | Actual instance |
| Defines structure | Holds actual data |
| Created once | Can be created many times |
| No memory allocated for data | Memory allocated for data |
| Example: `Student` | Example: `s1`, `s2` |

### Defining a Class in C++

```cpp
class ClassName {
public:        // Access specifier
    // Data members (attributes)
    int attribute1;
    string attribute2;

    // Member functions (methods)
    void doSomething() {
        // function body
    }
};  // Don't forget the semicolon!
```

### Creating Objects

```cpp
#include <iostream>
#include <string>
using namespace std;

class Car {
public:
    string brand;
    string model;
    int year;

    void displayInfo() {
        cout << year << " " << brand << " " << model << endl;
    }
};

int main() {
    // Method 1: Declare then assign
    Car car1;
    car1.brand = "Toyota";
    car1.model = "Camry";
    car1.year = 2024;

    // Method 2: Using aggregate initialization (C++11)
    Car car2 = {"Honda", "Civic", 2023};

    car1.displayInfo();
    car2.displayInfo();

    return 0;
}
```

**Output:**
```
2024 Toyota Camry
2023 Honda Civic
```

---

## Encapsulation

### What is Encapsulation?

**Encapsulation** is the practice of:
1. **Bundling** data (attributes) and the methods that operate on that data into a single unit (a class)
2. **Restricting** direct access to some of the object's components (data hiding)

Encapsulation means that the internal state of an object is protected from outside interference. External code can only interact with an object through its **public interface** (public methods).

### Metaphors for Encapsulation

#### Metaphor 1: The Medicine Capsule 💊

A capsule contains multiple ingredients inside a protective shell. You don't need to know the exact chemical composition — you just take the capsule and it works. The shell **protects** the contents and ensures they work correctly together. Similarly, encapsulation bundles data inside a class and protects it with access specifiers.

#### Metaphor 2: The Car Dashboard 🚗

When you drive a car, you interact with the steering wheel, pedals, and dashboard. You don't directly manipulate the engine, transmission, or fuel injection system. The car **encapsulates** its complex internals and gives you a simple interface. If the engine design changes, your driving experience stays the same.

#### Metaphor 3: The ATM Machine 🏧

An ATM lets you withdraw money, check balance, and deposit funds. But you never directly access the bank vault or database. The ATM provides **controlled access** — you must use the proper interface (card + PIN), and the machine validates your request before executing it.

#### Metaphor 4: The Smartphone 📱

Your phone encapsulates thousands of components — CPU, memory, sensors, radios. You interact only through the touchscreen and buttons. If Apple or Samsung changes the internal chip, your experience of tapping icons remains unchanged. The internal complexity is **hidden** behind a simple interface.

### Access Specifiers

C++ provides three access specifiers to control visibility:

| Specifier | Access Level | Description |
|-----------|-------------|-------------|
| `public` | Accessible from anywhere | Open to all code |
| `private` | Accessible only within the class | Hidden from outside |
| `protected` | Accessible within class and subclasses | For inheritance |

```cpp
class BankAccount {
private:       // Hidden from outside
    double balance;
    string pin;

public:        // Accessible from outside
    string ownerName;

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    double getBalance() {
        return balance;
    }
};
```

### Private Data Members

Making data members `private` is the heart of encapsulation. It prevents external code from directly modifying internal state.

```cpp
#include <iostream>
using namespace std;

class Temperature {
private:
    double celsius;   // Internal data — hidden

public:
    void setCelsius(double c) {
        if (c >= -273.15) {   // Absolute zero check
            celsius = c;
        } else {
            cout << "Error: Temperature below absolute zero!" << endl;
        }
    }

    double getCelsius() {
        return celsius;
    }

    double getFahrenheit() {
        return (celsius * 9.0 / 5.0) + 32;
    }
};

int main() {
    Temperature temp;
    temp.setCelsius(100);
    cout << "Celsius: " << temp.getCelsius() << endl;
    cout << "Fahrenheit: " << temp.getFahrenheit() << endl;

    temp.setCelsius(-300);  // Rejected!

    return 0;
}
```

**Output:**
```
Celsius: 100
Fahrenheit: 212
Error: Temperature below absolute zero!
```

### Getter and Setter Methods

**Getters** (accessors) read private data. **Setters** (mutators) write to private data with validation.

```cpp
#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int age;
    double gpa;

public:
    // Setter with validation
    void setName(string n) {
        if (!n.empty()) {
            name = n;
        }
    }

    void setAge(int a) {
        if (a > 0 && a < 150) {
            age = a;
        }
    }

    void setGPA(double g) {
        if (g >= 0.0 && g <= 4.0) {
            gpa = g;
        }
    }

    // Getters
    string getName() { return name; }
    int getAge() { return age; }
    double getGPA() { return gpa; }

    void display() {
        cout << "Name: " << name
             << ", Age: " << age
             << ", GPA: " << gpa << endl;
    }
};

int main() {
    Student s;
    s.setName("Alice");
    s.setAge(20);
    s.setGPA(3.85);
    s.display();

    s.setGPA(5.0);   // Rejected — out of range
    s.display();      // GPA unchanged

    return 0;
}
```

**Output:**
```
Name: Alice, Age: 20, GPA: 3.85
Name: Alice, Age: 20, GPA: 3.85
```

### Encapsulation with Validation

One of the most powerful benefits of encapsulation is that setters can **validate** input before modifying data:

```cpp
#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string owner;
    double balance;

public:
    BankAccount(string name, double initial) {
        owner = name;
        balance = (initial >= 0) ? initial : 0;
    }

    bool deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited $" << amount << endl;
            return true;
        }
        cout << "Invalid deposit amount!" << endl;
        return false;
    }

    bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrew $" << amount << endl;
            return true;
        }
        cout << "Insufficient funds or invalid amount!" << endl;
        return false;
    }

    double getBalance() { return balance; }
    string getOwner() { return owner; }

    void displayAccount() {
        cout << "Account: " << owner
             << " | Balance: $" << balance << endl;
    }
};

int main() {
    BankAccount acc("Alice", 1000);
    acc.displayAccount();

    acc.deposit(500);
    acc.withdraw(200);
    acc.withdraw(5000);  // Rejected

    acc.displayAccount();

    return 0;
}
```

**Output:**
```
Account: Alice | Balance: $1000
Deposited $500
Withdrew $200
Insufficient funds or invalid amount!
Account: Alice | Balance: $1300
```

### Benefits of Encapsulation

1. **Data Protection**: Prevents accidental or malicious modification of data
2. **Validation**: Setters can validate data before storing it
3. **Flexibility**: Internal implementation can change without affecting external code
4. **Debugging**: Errors are easier to track since data changes go through methods
5. **Modularity**: Each class is a self-contained unit

### Encapsulation vs No Encapsulation

**Without Encapsulation (Bad):**

```cpp
class StudentBad {
public:
    string name;
    int age;
    double gpa;
};

int main() {
    StudentBad s;
    s.age = -5;     // No validation! Negative age accepted
    s.gpa = 99.9;   // No validation! Impossible GPA accepted
}
```

**With Encapsulation (Good):**

```cpp
class StudentGood {
private:
    string name;
    int age;
    double gpa;

public:
    void setAge(int a) {
        if (a > 0 && a < 150) age = a;
        else cout << "Invalid age!" << endl;
    }

    void setGPA(double g) {
        if (g >= 0.0 && g <= 4.0) gpa = g;
        else cout << "Invalid GPA!" << endl;
    }
};
```

---

## Common Mistakes

**Mistake 1: Forgetting the semicolon after class definition**

**Wrong:**
```cpp
class MyClass {
public:
    int x;
}   // Missing semicolon!
```

**Correct:**
```cpp
class MyClass {
public:
    int x;
};  // Semicolon required!
```

**Explanation:** In C++, a class definition must end with a semicolon. Forgetting it causes cryptic compiler errors.

---

**Mistake 2: Making all data members public**

**Wrong:**
```cpp
class BankAccount {
public:
    double balance;  // Anyone can set balance to anything!
};
```

**Correct:**
```cpp
class BankAccount {
private:
    double balance;
public:
    void deposit(double amount) {
        if (amount > 0) balance += amount;
    }
};
```

**Explanation:** Public data members defeat the purpose of encapsulation. Always make data private and provide controlled access through methods.

---

**Mistake 3: Default access in class is private, not public**

**Wrong:**
```cpp
class MyClass {
    int x;  // This is private by default!
};

int main() {
    MyClass obj;
    obj.x = 5;  // Error! x is private
}
```

**Correct:**
```cpp
class MyClass {
public:
    int x;  // Explicitly public
};
```

**Explanation:** In C++, class members are `private` by default (unlike `struct` which is `public` by default). Always specify access specifiers explicitly.

---

**Mistake 4: Trying to access private members from outside the class**

**Wrong:**
```cpp
class Student {
private:
    int age;
};

int main() {
    Student s;
    s.age = 20;  // Error! age is private
}
```

**Correct:**
```cpp
class Student {
private:
    int age;
public:
    void setAge(int a) { age = a; }
    int getAge() { return age; }
};

int main() {
    Student s;
    s.setAge(20);  // Correct! Using setter
}
```

**Explanation:** Private members can only be accessed from within the class. Use getter/setter methods to provide controlled access.

---

**Mistake 5: Writing setters without validation**

**Wrong:**
```cpp
void setAge(int a) {
    age = a;  // No validation — same as making it public!
}
```

**Correct:**
```cpp
void setAge(int a) {
    if (a > 0 && a < 150) {
        age = a;
    } else {
        cout << "Invalid age!" << endl;
    }
}
```

**Explanation:** Setters without validation provide no benefit over public data members. Always validate input in setters.

---

## Practice Exercises

### Exercise 1: Rectangle Class
Create a `Rectangle` class with private `width` and `height`. Provide setters that reject negative values, getters, and methods `area()` and `perimeter()`.

**Expected Output:**
```
Width: 5, Height: 3
Area: 15
Perimeter: 16
Invalid width!
```

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

class Rectangle {
private:
    double width;
    double height;

public:
    void setWidth(double w) {
        if (w > 0) width = w;
        else cout << "Invalid width!" << endl;
    }

    void setHeight(double h) {
        if (h > 0) height = h;
        else cout << "Invalid height!" << endl;
    }

    double getWidth() { return width; }
    double getHeight() { return height; }

    double area() { return width * height; }
    double perimeter() { return 2 * (width + height); }

    void display() {
        cout << "Width: " << width << ", Height: " << height << endl;
        cout << "Area: " << area() << endl;
        cout << "Perimeter: " << perimeter() << endl;
    }
};

int main() {
    Rectangle r;
    r.setWidth(5);
    r.setHeight(3);
    r.display();

    r.setWidth(-2);  // Rejected

    return 0;
}
```
</details>

### Exercise 2: Password Manager
Create a `UserAccount` class with a private password. The setter must enforce: minimum 8 characters. Provide a `checkPassword(string)` method that returns `true` or `false`.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
#include <string>
using namespace std;

class UserAccount {
private:
    string username;
    string password;

public:
    void setUsername(string u) { username = u; }

    bool setPassword(string p) {
        if (p.length() >= 8) {
            password = p;
            return true;
        }
        cout << "Password must be at least 8 characters!" << endl;
        return false;
    }

    bool checkPassword(string p) {
        return password == p;
    }

    string getUsername() { return username; }
};

int main() {
    UserAccount acc;
    acc.setUsername("alice");
    acc.setPassword("short");      // Rejected
    acc.setPassword("securePass123");

    cout << "Login: " << (acc.checkPassword("securePass123") ? "Success" : "Failed") << endl;
    cout << "Login: " << (acc.checkPassword("wrong") ? "Success" : "Failed") << endl;

    return 0;
}
```
</details>

### Exercise 3: Grade Book
Create a `GradeBook` class that stores a student's name and up to 5 grades (private array). Provide `addGrade(double)` (must be 0–100), `getAverage()`, and `getHighest()`.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
#include <string>
using namespace std;

class GradeBook {
private:
    string studentName;
    double grades[5];
    int count;

public:
    GradeBook(string name) {
        studentName = name;
        count = 0;
        for (int i = 0; i < 5; i++) grades[i] = 0;
    }

    bool addGrade(double g) {
        if (count < 5 && g >= 0 && g <= 100) {
            grades[count++] = g;
            return true;
        }
        cout << "Cannot add grade!" << endl;
        return false;
    }

    double getAverage() {
        if (count == 0) return 0;
        double sum = 0;
        for (int i = 0; i < count; i++) sum += grades[i];
        return sum / count;
    }

    double getHighest() {
        if (count == 0) return 0;
        double max = grades[0];
        for (int i = 1; i < count; i++)
            if (grades[i] > max) max = grades[i];
        return max;
    }

    void display() {
        cout << "Student: " << studentName << endl;
        cout << "Average: " << getAverage() << endl;
        cout << "Highest: " << getHighest() << endl;
    }
};

int main() {
    GradeBook gb("Alice");
    gb.addGrade(85);
    gb.addGrade(92);
    gb.addGrade(78);
    gb.display();
    return 0;
}
```
</details>

### Exercise 4: Time Class
Create a `Time` class with private `hours`, `minutes`, `seconds`. Setters must validate ranges (0–23, 0–59, 0–59). Add a `display()` method showing time in HH:MM:SS format.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

class Time {
private:
    int hours, minutes, seconds;

public:
    Time() : hours(0), minutes(0), seconds(0) {}

    void setHours(int h) {
        if (h >= 0 && h <= 23) hours = h;
        else cout << "Invalid hours!" << endl;
    }

    void setMinutes(int m) {
        if (m >= 0 && m <= 59) minutes = m;
        else cout << "Invalid minutes!" << endl;
    }

    void setSeconds(int s) {
        if (s >= 0 && s <= 59) seconds = s;
        else cout << "Invalid seconds!" << endl;
    }

    void display() {
        cout << setfill('0') << setw(2) << hours << ":"
             << setw(2) << minutes << ":"
             << setw(2) << seconds << endl;
    }
};

int main() {
    Time t;
    t.setHours(14);
    t.setMinutes(30);
    t.setSeconds(45);
    t.display();

    t.setHours(25);  // Rejected
    t.display();

    return 0;
}
```
</details>

### Exercise 5: Inventory Item
Create an `InventoryItem` class with private `name`, `quantity`, and `price`. Add methods `restock(int)`, `sell(int)` (cannot sell more than available), and `getValue()` returning quantity × price.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
#include <string>
using namespace std;

class InventoryItem {
private:
    string name;
    int quantity;
    double price;

public:
    InventoryItem(string n, int q, double p) {
        name = n;
        quantity = (q >= 0) ? q : 0;
        price = (p >= 0) ? p : 0;
    }

    void restock(int amount) {
        if (amount > 0) {
            quantity += amount;
            cout << "Restocked " << amount << " units." << endl;
        }
    }

    bool sell(int amount) {
        if (amount > 0 && amount <= quantity) {
            quantity -= amount;
            cout << "Sold " << amount << " units." << endl;
            return true;
        }
        cout << "Cannot sell " << amount << " units!" << endl;
        return false;
    }

    double getValue() { return quantity * price; }

    void display() {
        cout << name << " | Qty: " << quantity
             << " | Price: $" << price
             << " | Value: $" << getValue() << endl;
    }
};

int main() {
    InventoryItem item("Laptop", 10, 999.99);
    item.display();
    item.sell(3);
    item.restock(5);
    item.sell(20);   // Rejected
    item.display();
    return 0;
}
```
</details>

---

## Summary

### Key Concepts

- **OOP** organizes code around objects that bundle data and behavior
- A **class** is a blueprint; an **object** is an instance of a class
- **Encapsulation** bundles data + methods and restricts direct access
- **Access specifiers** (`public`, `private`, `protected`) control visibility
- **Getters** read private data; **Setters** write with validation
- Encapsulation enables **data protection**, **validation**, and **flexibility**

### Important Points

1. Always make data members `private` unless there's a specific reason not to
2. Provide `public` getters and setters for controlled access
3. Always validate input in setter methods
4. Class members are `private` by default in C++ (unlike `struct`)
5. Don't forget the semicolon after the closing brace of a class
6. Each object has its own copy of data members
7. Encapsulation is the foundation for the other OOP pillars
8. Think of a class as a blueprint and objects as the buildings made from it

### Quick Reference

```cpp
class MyClass {
private:
    int data;           // Hidden data

public:
    // Setter with validation
    void setData(int d) {
        if (d > 0) data = d;
    }

    // Getter
    int getData() {
        return data;
    }
};
```

### Next Steps

In the next lecture, we'll explore **Constructors and Destructors** — special methods that initialize and clean up objects automatically.
