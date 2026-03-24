# C++ Programming — Introduction to Classes

## Table of Contents

1. [Introduction](#introduction)
2. [What is a Class?](#what-is-a-class)
   - [Defining a Class](#defining-a-class)
   - [Creating Objects](#creating-objects)
3. [Access Specifiers](#access-specifiers)
   - [Public Members](#public-members)
   - [Private Members](#private-members)
4. [Member Functions](#member-functions)
   - [Defining Inside the Class](#defining-inside-the-class)
   - [Defining Outside the Class](#defining-outside-the-class)
5. [Constructors](#constructors)
   - [Default Constructors](#default-constructors)
   - [Parameterized Constructors](#parameterized-constructors)
   - [Constructor Overloading](#constructor-overloading)
6. [Destructors](#destructors)
7. [Getters and Setters](#getters-and-setters)
8. [The `this` Pointer](#the-this-pointer)
9. [Separating Interface from Implementation](#separating-interface-from-implementation)
10. [Common Mistakes](#common-mistakes)
11. [Practice Exercises](#practice-exercises)
12. [Summary](#summary)

---

## Introduction

A **class** is a user-defined data type that bundles data (attributes) and functions (methods) into a single unit. Classes are the foundation of **Object-Oriented Programming (OOP)** in C++.

### Why Are Classes Important?

- They let you model real-world entities (a student, a bank account, a car) as code.
- They keep related data and behavior together, making programs organized and maintainable.
- They enforce **encapsulation** — hiding internal details and exposing only what is necessary.
- They enable code reuse through features like inheritance and polymorphism (covered in future lectures).

### Real-World Analogies

- **Blueprint and House:** A class is like an architectural blueprint. The blueprint describes the layout (rooms, dimensions), but it is not a house itself. Each house built from that blueprint is an **object**.
- **Cookie Cutter and Cookies:** The cutter (class) defines the shape; each cookie (object) is a separate instance made from it.
- **Form Template and Filled Forms:** A blank form (class) defines what information goes where. Each completed form (object) holds unique data.

---

## What is a Class?

A **class** is a template that defines the structure and behavior of objects. It specifies what data an object holds and what operations it can perform.

### Defining a Class

You define a class using the `class` keyword, followed by the class name and a body enclosed in braces. Note the semicolon after the closing brace — this is required.

```cpp
#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    string name;
    int age;
    double gpa;
};

int main() {
    Student s;
    s.name = "Alice";
    s.age = 20;
    s.gpa = 3.85;

    cout << "Name: " << s.name << endl;
    cout << "Age: " << s.age << endl;
    cout << "GPA: " << s.gpa << endl;

    return 0;
}
```

**Output:**
```
Name: Alice
Age: 20
GPA: 3.85
```

### Creating Objects

An **object** is a variable whose type is a class. You create objects the same way you create any variable.

```cpp
#include <iostream>
#include <string>
using namespace std;

class Car {
public:
    string brand;
    int year;
};

int main() {
    Car car1;
    car1.brand = "Toyota";
    car1.year = 2022;

    Car car2;
    car2.brand = "Honda";
    car2.year = 2023;

    cout << car1.brand << " (" << car1.year << ")" << endl;
    cout << car2.brand << " (" << car2.year << ")" << endl;

    return 0;
}
```

**Output:**
```
Toyota (2022)
Honda (2023)
```

Each object has its own independent copy of the data members. Changing `car1.brand` does not affect `car2.brand`.

```cpp
#include <iostream>
#include <string>
using namespace std;

class Point {
public:
    double x;
    double y;
};

int main() {
    Point p1, p2, p3;

    p1.x = 1.0;  p1.y = 2.0;
    p2.x = 4.0;  p2.y = 6.0;
    p3.x = -3.5; p3.y = 0.0;

    cout << "p1: (" << p1.x << ", " << p1.y << ")" << endl;
    cout << "p2: (" << p2.x << ", " << p2.y << ")" << endl;
    cout << "p3: (" << p3.x << ", " << p3.y << ")" << endl;

    return 0;
}
```

**Output:**
```
p1: (1, 2)
p2: (4, 6)
p3: (-3.5, 0)
```

---

## Access Specifiers

Access specifiers control who can access the members of a class. C++ provides three access specifiers: `public`, `private`, and `protected`. In this lecture we focus on the first two.

### Public Members

Members declared under `public:` can be accessed from anywhere — inside the class, from other classes, and from `main()`.

```cpp
#include <iostream>
using namespace std;

class Circle {
public:
    double radius;

    double area() {
        return 3.14159 * radius * radius;
    }
};

int main() {
    Circle c;
    c.radius = 5.0;   // Allowed: radius is public
    cout << "Area: " << c.area() << endl;   // Allowed: area() is public

    return 0;
}
```

**Output:**
```
Area: 78.5397
```

### Private Members

Members declared under `private:` can only be accessed from inside the class. This is the **default** access level if you don't specify one.

```cpp
#include <iostream>
using namespace std;

class BankAccount {
private:
    double balance;

public:
    void setBalance(double b) {
        if (b >= 0)
            balance = b;
    }

    double getBalance() {
        return balance;
    }
};

int main() {
    BankAccount account;
    // account.balance = 1000;  // ERROR: balance is private
    account.setBalance(1000);   // OK: setBalance is public
    cout << "Balance: $" << account.getBalance() << endl;

    return 0;
}
```

**Output:**
```
Balance: $1000
```

The key idea: you cannot directly modify `balance` from outside the class. You must go through the public methods, which can validate the data.

```cpp
#include <iostream>
#include <string>
using namespace std;

class Password {
private:
    string secret;

public:
    void setPassword(string s) {
        if (s.length() >= 8)
            secret = s;
        else
            cout << "Password must be at least 8 characters!" << endl;
    }

    bool checkPassword(string attempt) {
        return attempt == secret;
    }
};

int main() {
    Password pw;
    pw.setPassword("abc");           // Too short
    pw.setPassword("mySecure123");   // OK

    cout << "Check 'hello': " << pw.checkPassword("hello") << endl;
    cout << "Check 'mySecure123': " << pw.checkPassword("mySecure123") << endl;

    return 0;
}
```

**Output:**
```
Password must be at least 8 characters!
Check 'hello': 0
Check 'mySecure123': 1
```

---

## Member Functions

**Member functions** (also called **methods**) are functions defined inside a class. They can access all members of the class, including private ones.

### Defining Inside the Class

You can write the function body directly inside the class definition.

```cpp
#include <iostream>
using namespace std;

class Rectangle {
public:
    double width;
    double height;

    double area() {
        return width * height;
    }

    double perimeter() {
        return 2 * (width + height);
    }

    void display() {
        cout << "Width: " << width
             << ", Height: " << height
             << ", Area: " << area()
             << ", Perimeter: " << perimeter() << endl;
    }
};

int main() {
    Rectangle r;
    r.width = 5.0;
    r.height = 3.0;
    r.display();

    return 0;
}
```

**Output:**
```
Width: 5, Height: 3, Area: 15, Perimeter: 16
```

### Defining Outside the Class

For larger functions, you can declare the function inside the class and define it outside using the **scope resolution operator** `::`.

```cpp
#include <iostream>
#include <string>
using namespace std;

class Employee {
public:
    string name;
    double salary;

    void display();         // Declaration only
    double annualSalary();  // Declaration only
};

// Definitions outside the class
void Employee::display() {
    cout << name << " earns $" << salary << "/month" << endl;
}

double Employee::annualSalary() {
    return salary * 12;
}

int main() {
    Employee e;
    e.name = "Bob";
    e.salary = 5000;
    e.display();
    cout << "Annual: $" << e.annualSalary() << endl;

    return 0;
}
```

**Output:**
```
Bob earns $5000/month
Annual: $60000
```

---

## Constructors

A **constructor** is a special member function that is called automatically when an object is created. It has the same name as the class and no return type.

### Default Constructors

A default constructor takes no arguments. It initializes the object's data members to default values.

```cpp
#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    string name;
    int age;
    double gpa;

    Student() {
        name = "Unknown";
        age = 0;
        gpa = 0.0;
        cout << "Student created with default values." << endl;
    }

    void display() {
        cout << name << ", Age: " << age << ", GPA: " << gpa << endl;
    }
};

int main() {
    Student s;  // Constructor called automatically
    s.display();

    return 0;
}
```

**Output:**
```
Student created with default values.
Unknown, Age: 0, GPA: 0
```

### Parameterized Constructors

A parameterized constructor accepts arguments to initialize data members with specific values.

```cpp
#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    string name;
    int age;
    double gpa;

    Student(string n, int a, double g) {
        name = n;
        age = a;
        gpa = g;
    }

    void display() {
        cout << name << ", Age: " << age << ", GPA: " << gpa << endl;
    }
};

int main() {
    Student s1("Alice", 20, 3.9);
    Student s2("Bob", 22, 3.5);

    s1.display();
    s2.display();

    return 0;
}
```

**Output:**
```
Alice, Age: 20, GPA: 3.9
Bob, Age: 22, GPA: 3.5
```

### Constructor Overloading

You can define multiple constructors with different parameter lists.

```cpp
#include <iostream>
#include <string>
using namespace std;

class Book {
public:
    string title;
    string author;
    int pages;

    Book() {
        title = "Untitled";
        author = "Unknown";
        pages = 0;
    }

    Book(string t, string a) {
        title = t;
        author = a;
        pages = 0;
    }

    Book(string t, string a, int p) {
        title = t;
        author = a;
        pages = p;
    }

    void display() {
        cout << "\"" << title << "\" by " << author
             << " (" << pages << " pages)" << endl;
    }
};

int main() {
    Book b1;
    Book b2("C++ Primer", "Lippman");
    Book b3("Clean Code", "Robert Martin", 464);

    b1.display();
    b2.display();
    b3.display();

    return 0;
}
```

**Output:**
```
"Untitled" by Unknown (0 pages)
"C++ Primer" by Lippman (0 pages)
"Clean Code" by Robert Martin (464 pages)
```

---

## Destructors

A **destructor** is a special member function called automatically when an object goes out of scope or is deleted. It has the same name as the class with a `~` prefix and takes no parameters.

```cpp
#include <iostream>
using namespace std;

class Logger {
public:
    string label;

    Logger(string l) {
        label = l;
        cout << label << " created." << endl;
    }

    ~Logger() {
        cout << label << " destroyed." << endl;
    }
};

int main() {
    Logger a("Object-A");
    Logger b("Object-B");
    cout << "--- End of main ---" << endl;

    return 0;
}
```

**Output:**
```
Object-A created.
Object-B created.
--- End of main ---
Object-B destroyed.
Object-A destroyed.
```

Notice that destructors are called in **reverse** order of construction.

---

## Getters and Setters

**Getters** and **setters** are public methods that provide controlled access to private data members. Getters retrieve values; setters modify them (often with validation).

```cpp
#include <iostream>
#include <string>
using namespace std;

class Temperature {
private:
    double celsius;

public:
    Temperature() {
        celsius = 0.0;
    }

    void setCelsius(double c) {
        if (c >= -273.15)   // Absolute zero check
            celsius = c;
        else
            cout << "Error: below absolute zero!" << endl;
    }

    double getCelsius() {
        return celsius;
    }

    double getFahrenheit() {
        return celsius * 9.0 / 5.0 + 32;
    }
};

int main() {
    Temperature t;
    t.setCelsius(100);
    cout << t.getCelsius() << " C = " << t.getFahrenheit() << " F" << endl;

    t.setCelsius(-300);  // Invalid

    return 0;
}
```

**Output:**
```
100 C = 212 F
Error: below absolute zero!
```

---

## The `this` Pointer

Every member function has a hidden pointer called `this` that points to the object on which the function was called. It is most commonly used when parameter names clash with data member names.

```cpp
#include <iostream>
#include <string>
using namespace std;

class Product {
private:
    string name;
    double price;

public:
    Product(string name, double price) {
        this->name = name;    // this->name is the member
        this->price = price;  // price (alone) is the parameter
    }

    void display() {
        cout << this->name << ": $" << this->price << endl;
    }
};

int main() {
    Product p("Laptop", 999.99);
    p.display();

    return 0;
}
```

**Output:**
```
Laptop: $999.99
```

Without `this->`, the compiler would assume you are assigning the parameter to itself, leaving the member uninitialized.

---

## Separating Interface from Implementation

In real projects you split a class across multiple files:

- **Header file (`.h`)** — contains the class declaration.
- **Source file (`.cpp`)** — contains the function definitions.

**Rectangle.h**
```cpp
#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h);
    double area();
    double perimeter();
    void display();
};

#endif
```

**Rectangle.cpp**
```cpp
#include <iostream>
#include "Rectangle.h"
using namespace std;

Rectangle::Rectangle(double w, double h) {
    width = w;
    height = h;
}

double Rectangle::area() {
    return width * height;
}

double Rectangle::perimeter() {
    return 2 * (width + height);
}

void Rectangle::display() {
    cout << "Width: " << width
         << ", Height: " << height
         << ", Area: " << area() << endl;
}
```

**main.cpp**
```cpp
#include "Rectangle.h"

int main() {
    Rectangle r(5.0, 3.0);
    r.display();
    return 0;
}
```

**Output:**
```
Width: 5, Height: 3, Area: 15
```

The `#ifndef` / `#define` / `#endif` pattern is called an **include guard**. It prevents the header from being included more than once.

---

## Common Mistakes

### Mistake 1: Forgetting the Semicolon After the Class Definition

**Wrong:**
```cpp
class Dog {
public:
    string name;
}
// ERROR: expected ';' after class definition
```

**Correct:**
```cpp
class Dog {
public:
    string name;
};  // Semicolon required!
```

**Explanation:** Unlike functions, class definitions must end with a semicolon. Omitting it produces confusing compiler errors.

---

### Mistake 2: Accessing Private Members Directly

**Wrong:**
```cpp
class Account {
private:
    double balance;
};

int main() {
    Account a;
    a.balance = 500;  // ERROR: 'balance' is private
}
```

**Correct:**
```cpp
class Account {
private:
    double balance;
public:
    void setBalance(double b) { balance = b; }
    double getBalance() { return balance; }
};

int main() {
    Account a;
    a.setBalance(500);  // OK: using public setter
}
```

**Explanation:** Private members cannot be accessed from outside the class. You must use public getter/setter methods.

---

### Mistake 3: Giving the Constructor a Return Type

**Wrong:**
```cpp
class Box {
public:
    void Box() {   // ERROR: constructor cannot have a return type
        // ...
    }
};
```

**Correct:**
```cpp
class Box {
public:
    Box() {   // No return type
        // ...
    }
};
```

**Explanation:** Constructors never have a return type — not even `void`. Adding one turns it into a regular function that happens to share the class name.

---

### Mistake 4: Using Parentheses for Default Construction

**Wrong:**
```cpp
Student s();  // Declares a FUNCTION, not an object!
```

**Correct:**
```cpp
Student s;    // Creates an object using the default constructor
```

**Explanation:** `Student s();` is interpreted as a function declaration (a function named `s` that returns a `Student`). This is known as the **Most Vexing Parse**. Omit the parentheses for default construction.

---

### Mistake 5: Shadowing Members Without `this`

**Wrong:**
```cpp
class Item {
    string name;
public:
    Item(string name) {
        name = name;  // Assigns parameter to itself!
    }
};
```

**Correct:**
```cpp
class Item {
    string name;
public:
    Item(string name) {
        this->name = name;  // Assigns parameter to member
    }
};
```

**Explanation:** When the parameter has the same name as the data member, the parameter shadows the member. Use `this->` to refer to the member explicitly.

---

## Practice Exercises

### Exercise 1: Counter Class

Create a class `Counter` with a private `count` (starts at 0) and public methods `increment()`, `decrement()` (don't go below 0), and `getCount()`. Test it in `main`.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

class Counter {
private:
    int count;

public:
    Counter() {
        count = 0;
    }

    void increment() {
        count++;
    }

    void decrement() {
        if (count > 0)
            count--;
    }

    int getCount() {
        return count;
    }
};

int main() {
    Counter c;
    c.increment();
    c.increment();
    c.increment();
    cout << "Count: " << c.getCount() << endl;  // 3
    c.decrement();
    cout << "Count: " << c.getCount() << endl;  // 2
    c.decrement();
    c.decrement();
    c.decrement();  // Should not go below 0
    cout << "Count: " << c.getCount() << endl;  // 0
    return 0;
}
```
</details>

---

### Exercise 2: Rectangle with Validation

Create a `Rectangle` class where `width` and `height` are private. The setter methods should reject negative values. Add methods `area()` and `perimeter()`.

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
    Rectangle() {
        width = 0;
        height = 0;
    }

    void setWidth(double w) {
        if (w >= 0) width = w;
        else cout << "Width cannot be negative!" << endl;
    }

    void setHeight(double h) {
        if (h >= 0) height = h;
        else cout << "Height cannot be negative!" << endl;
    }

    double getWidth() { return width; }
    double getHeight() { return height; }

    double area() { return width * height; }
    double perimeter() { return 2 * (width + height); }

    void display() {
        cout << "Rectangle " << width << "x" << height
             << " | Area: " << area()
             << " | Perimeter: " << perimeter() << endl;
    }
};

int main() {
    Rectangle r;
    r.setWidth(7);
    r.setHeight(4);
    r.display();

    r.setWidth(-3);  // Should show error
    r.display();

    return 0;
}
```
</details>

---

### Exercise 3: Student Gradebook

Create a `Student` class with `name`, `id`, and an array of 5 grades. Provide a constructor, a method `averageGrade()`, and a method `display()` that shows all info.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int id;
    double grades[5];

public:
    Student(string n, int i, double g[]) {
        name = n;
        id = i;
        for (int j = 0; j < 5; j++)
            grades[j] = g[j];
    }

    double averageGrade() {
        double sum = 0;
        for (int i = 0; i < 5; i++)
            sum += grades[i];
        return sum / 5.0;
    }

    void display() {
        cout << "Name: " << name << " | ID: " << id << endl;
        cout << "Grades: ";
        for (int i = 0; i < 5; i++)
            cout << grades[i] << " ";
        cout << endl;
        cout << "Average: " << averageGrade() << endl;
    }
};

int main() {
    double grades[] = {90, 85, 92, 88, 95};
    Student s("Alice", 1001, grades);
    s.display();
    return 0;
}
```
</details>

---

### Exercise 4: BankAccount with Deposit/Withdraw

Create a `BankAccount` class with `ownerName` and `balance`. Provide `deposit(amount)` and `withdraw(amount)` methods with proper validation. Display balance after each operation.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string ownerName;
    double balance;

public:
    BankAccount(string name, double initial) {
        ownerName = name;
        balance = (initial >= 0) ? initial : 0;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited $" << amount << ". Balance: $" << balance << endl;
        } else {
            cout << "Deposit amount must be positive!" << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrew $" << amount << ". Balance: $" << balance << endl;
        } else if (amount > balance) {
            cout << "Insufficient funds!" << endl;
        } else {
            cout << "Withdrawal amount must be positive!" << endl;
        }
    }

    void display() {
        cout << "Account: " << ownerName
             << " | Balance: $" << balance << endl;
    }
};

int main() {
    BankAccount acc("Alice", 1000);
    acc.display();
    acc.deposit(500);
    acc.withdraw(200);
    acc.withdraw(2000);  // Insufficient
    return 0;
}
```
</details>

---

### Exercise 5: Time Class

Create a `Time` class that stores hours, minutes, and seconds. Provide a method `addSeconds(int s)` that correctly handles overflow (60 seconds = 1 minute, etc.) and a `display()` method.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
    Time(int h, int m, int s) {
        hours = h;
        minutes = m;
        seconds = s;
    }

    void addSeconds(int s) {
        seconds += s;
        minutes += seconds / 60;
        seconds %= 60;
        hours += minutes / 60;
        minutes %= 60;
        hours %= 24;
    }

    void display() {
        cout << setfill('0')
             << setw(2) << hours << ":"
             << setw(2) << minutes << ":"
             << setw(2) << seconds << endl;
    }
};

int main() {
    Time t(10, 58, 45);
    t.display();            // 10:58:45
    t.addSeconds(90);
    t.display();            // 11:00:15
    t.addSeconds(3600);
    t.display();            // 12:00:15
    return 0;
}
```
</details>

---

## Summary

### Key Concepts

- A **class** defines a custom data type with data members and member functions.
- An **object** is an instance of a class.
- **Access specifiers** (`public`, `private`) control visibility.
- **Constructors** initialize objects automatically; **destructors** clean up.
- The **`this`** pointer lets a member function refer to the calling object.
- **Encapsulation** means hiding data behind public methods.

### Important Points

1. Always end a class definition with a semicolon.
2. Data members should generally be `private`; access them through public getters/setters.
3. Constructors have the same name as the class and no return type.
4. You can overload constructors to support different ways of creating objects.
5. Destructors are called automatically when objects go out of scope.
6. Use `this->` when parameter names shadow member names.
7. In larger programs, separate declarations (`.h`) from definitions (`.cpp`).
8. Use include guards (`#ifndef`) to prevent multiple inclusions.

### Quick Reference

```cpp
class ClassName {
private:
    // data members
    int value;

public:
    // Constructor
    ClassName(int v) { this->value = v; }

    // Destructor
    ~ClassName() { }

    // Getter
    int getValue() { return value; }

    // Setter
    void setValue(int v) { value = v; }
};
```

### Next Steps

In the next lecture we will explore **inheritance** — how one class can extend another, allowing you to build class hierarchies and reuse code efficiently.
