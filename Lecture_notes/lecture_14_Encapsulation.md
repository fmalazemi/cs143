# CS143 — Lecture 14: Encapsulation &amp; Access Levels

> **Course:** CS143 Introduction to C++ · **Instructor:** Dr. Fawaz Alazemi
> **Builds on:** Lecture 13 (introduction to OOP).

---

## Table of Contents

1. [Introduction](#1-introduction)
2. [Access Levels](#2-access-levels)
3. [Declaring Private and Public Members](#3-declaring-private-and-public-members)
4. [Why Hide the Data?](#4-why-hide-the-data)
5. [Getters and Setters](#5-getters-and-setters)
6. [Validation: The Real Payoff](#6-validation-the-real-payoff)
7. [Worked Examples](#7-worked-examples)
8. [Common Mistakes](#8-common-mistakes)
9. [Practice Exercises](#9-practice-exercises)
10. [Summary](#10-summary)

---

## 1. Introduction

In the previous lecture we named the four big ideas of OOP. This lecture studies the first one in detail: **encapsulation**.

**Encapsulation** means two things working together:

- **Bundle** an object's data and methods into one unit (a class), and
- **Hide** the data inside, so outside code can only use the object through its public methods.

Picture a class as a sealed capsule. The data sits protected in the core; the methods form a public shell that the outside world is allowed to use:

```
            BankAccount
 +-----------------------------------+
 |  PUBLIC — the interface           |
 |    deposit()  withdraw()  get()   |
 |   +---------------------------+   |
 |   |  PRIVATE — the data       |   |
 |   |     balance = 100         |   |
 |   +---------------------------+   |
 +-----------------------------------+
   Outside code uses the public methods;
   the private data is sealed inside.
```

Encapsulation decides **who is allowed to touch** an object's attributes and methods.

---

## 2. Access Levels

C++ gives each member of a class an **access level**, set with one of three keywords.

| Keyword | Who can use it | Typical use |
|---------|----------------|-------------|
| `public` | any code, inside or outside the class | the methods others call (the interface) |
| `private` | only the class's own methods | the data you want to protect |
| `protected` | the class and classes built from it | for inheritance (covered later) |

The common pattern that defines encapsulation is simple: **make the data `private` and the methods `public`.**

---

## 3. Declaring Private and Public Members

You place members under a `private:` or `public:` label.

```cpp
class BankAccount {
private:
    double balance = 0;     // hidden data

public:
    void deposit(double amount) {
        balance = balance + amount;
    }
    double getBalance() {
        return balance;
    }
};
```

- Everything under `private:` is hidden from outside the class.
- Everything under `public:` can be used from outside.
- In a `class`, members are **private by default** until you write `public:`.

*(We set `balance = 0` here to give it a starting value. Constructors — a cleaner way to set up data — are the topic of the next lecture.)*

---

## 4. Why Hide the Data?

If the data were public, any code could set it to a meaningless or illegal value:

```cpp
account.balance = -9999;   // anyone could break it
```

There would be no way to stop bad values, and the object could end up in an impossible state.

With the data private, every change must go through a method that can **check** the value first:

```cpp
account.deposit(50);        // a safe, checked path
// account.balance = -9999; // ERROR: balance is private
```

Encapsulation protects an object by controlling exactly **how** its data can change.

---

## 5. Getters and Setters

Because the data is private, we give outside code two kinds of controlled doorways:

- A **getter** lets outside code *read* a private value.
- A **setter** lets outside code *change* it, through a method the class controls.

```cpp
class Student {
private:
    int age = 0;

public:
    int getAge() {          // getter: read the data
        return age;
    }
    void setAge(int a) {    // setter: change the data
        age = a;
    }
};
```

The class decides what is allowed; the data itself stays private.

---

## 6. Validation: The Real Payoff

The true power of a setter is that it can **check** a value before storing it. This means the object can never hold an invalid value.

```cpp
class Student {
private:
    int age = 0;
public:
    void setAge(int a) {
        if (a >= 0 && a <= 120)   // check first
            age = a;              // only set if valid
        // otherwise ignore the bad value
    }
    int getAge() { return age; }
};
```

**Effect:**
```
setAge(20)  -> age becomes 20
setAge(-5)  -> ignored, age stays the same
```

The setter rejects an impossible age. This is the point of encapsulation: **the class guards its own data.**

---

## 7. Worked Examples

### Example 1 — A safe bank account

```cpp
#include <iostream>
using namespace std;

class BankAccount {
private:
    double balance = 0;

public:
    void deposit(double amount) {
        if (amount > 0) balance += amount;
    }
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance)
            balance -= amount;     // no overdraw
    }
    double getBalance() { return balance; }
};

int main() {
    BankAccount a;
    a.deposit(100);
    a.withdraw(30);
    cout << a.getBalance() << endl;
    return 0;
}
```

**Output:**
```
70
```

The balance is private. Deposits must be positive, and a withdrawal can never take more than is available — so the account can never reach an impossible state from outside.

### Example 2 — A validated setting

```cpp
class Thermostat {
private:
    int temp = 20;     // a safe default
public:
    void setTemp(int t) {
        if (t >= 10 && t <= 30)   // allowed range
            temp = t;
    }
    int getTemp() { return temp; }
};

int main() {
    Thermostat th;
    th.setTemp(25);  cout << th.getTemp() << endl;  // 25
    th.setTemp(99);  cout << th.getTemp() << endl;  // 25 (99 rejected)
    return 0;
}
```

**Output:**
```
25
25
```

The thermostat only accepts a temperature between 10 and 30, so the value 99 is ignored.

### Example 3 — A counter that cannot go wrong

```cpp
class Counter {
private:
    int count = 0;        // only this class can change it
public:
    void increment() { count++; }
    void reset()     { count = 0; }
    int getCount()   { return count; }
};

int main() {
    Counter c;
    c.increment();
    c.increment();
    cout << c.getCount() << endl;  // 2
    // c.count = 999;  // ERROR: count is private
    return 0;
}
```

**Output:**
```
2
```

`count` can only go up by one or reset to zero. Outside code cannot set it to a random value — the class controls every way its data can change.

---

## 8. Common Mistakes

**1. Making the data public**

**Wrong:**
```cpp
class BankAccount {
public:
    double balance = 0;   // anyone can set this to anything
};
```

**Correct:**
```cpp
class BankAccount {
private:
    double balance = 0;   // protected
public:
    void deposit(double a) { if (a > 0) balance += a; }
};
```

**Explanation:** public data gives no protection. Keep data private and change it through checked methods.

**2. Forgetting the colon after the keyword**

**Wrong:**
```cpp
class A {
private          // missing colon
    int x;
};
```

**Correct:**
```cpp
class A {
private:         // colon required
    int x = 0;
};
```

**Explanation:** the access keyword introduces a section and must be followed by a colon.

**3. Touching private data from outside**

**Wrong:**
```cpp
BankAccount a;
a.balance = 100;   // ERROR: balance is private
```

**Correct:**
```cpp
BankAccount a;
a.deposit(100);    // use the public method
```

**Explanation:** private members can only be used inside the class's own methods.

**4. A setter with no check**

**Wrong:**
```cpp
void setAge(int a) { age = a; }   // accepts anything, even -5
```

**Correct:**
```cpp
void setAge(int a) {
    if (a >= 0 && a <= 120) age = a;
}
```

**Explanation:** a setter that just assigns gives no more protection than public data. Validate the value first.

**5. Missing the semicolon after the class**

**Wrong:**
```cpp
class A {
    int x = 0;
}                  // missing semicolon
```

**Correct:**
```cpp
class A {
    int x = 0;
};                 // a class ends with };
```

**Explanation:** a class definition must end with `};`.

---

## 9. Practice Exercises

Try each one before opening the solution.

**Exercise 1.** Write a `Circle` class with a private `radius` and public `setRadius`, `getRadius`, and `area()` (use `3.14159 * radius * radius`).

<details>
<summary>Click to see solution</summary>

```cpp
class Circle {
private:
    double radius = 0;
public:
    void setRadius(double r) {
        if (r >= 0) radius = r;
    }
    double getRadius() { return radius; }
    double area() {
        return 3.14159 * radius * radius;
    }
};
```
</details>

**Exercise 2.** Write a `BankAccount` with a private `balance`; add `deposit(amount)` that rejects values that are not positive, and `getBalance()`.

<details>
<summary>Click to see solution</summary>

```cpp
class BankAccount {
private:
    double balance = 0;
public:
    void deposit(double amount) {
        if (amount > 0) balance += amount;
    }
    double getBalance() { return balance; }
};
```
</details>

**Exercise 3.** Add a `withdraw(amount)` to that account that refuses to let the balance go below 0.

<details>
<summary>Click to see solution</summary>

```cpp
void withdraw(double amount) {
    if (amount > 0 && amount <= balance)
        balance -= amount;   // never below 0
}
```
</details>

**Exercise 4.** Write a `Student` with private `name` and `gpa`; add getters and setters, where `setGpa` only accepts values from 0.0 to 4.0.

<details>
<summary>Click to see solution</summary>

```cpp
class Student {
private:
    string name;
    double gpa = 0;
public:
    void setName(string n) { name = n; }
    string getName() { return name; }
    void setGpa(double g) {
        if (g >= 0.0 && g <= 4.0) gpa = g;
    }
    double getGpa() { return gpa; }
};
```
</details>

**Exercise 5.** Write a `Counter` with a private `count` and public `increment()`, `reset()`, and `getCount()`.

<details>
<summary>Click to see solution</summary>

```cpp
class Counter {
private:
    int count = 0;
public:
    void increment() { count++; }
    void reset()     { count = 0; }
    int getCount()   { return count; }
};
```
</details>

**Exercise 6.** In a comment, explain why making `balance` public would be unsafe, then show the safe private version.

<details>
<summary>Click to see solution</summary>

```cpp
// If balance were public:
//   account.balance = -9999;   // anyone could break it.
// There would be no way to stop bad values.

// Safe version: keep it private, change it only through checked methods.
class BankAccount {
private:
    double balance = 0;      // hidden
public:
    void deposit(double a) {
        if (a > 0) balance += a;
    }
    double getBalance() { return balance; }
};
```
</details>

---

## 10. Summary

### Key Concepts

- **Encapsulation** bundles data with methods and hides the data inside the object.
- Access levels decide who may use each member: `public`, `private`, `protected`.
- The defining pattern is **private data, public methods**.

### Important Points

1. In a `class`, members are private by default until you write `public:`.
2. `public` members are usable anywhere; `private` members only inside the class.
3. `protected` is for inheritance and is covered in a later lecture.
4. **Getters** read private data; **setters** change it through a controlled method.
5. **Validation** in a setter keeps an object from ever holding an invalid value.
6. A class definition ends with `};`.

### Quick Reference

```cpp
class Account {
private:
    double balance = 0;            // hidden data
public:
    void deposit(double a) {       // public method
        if (a > 0) balance += a;   // validation
    }
    double getBalance() {          // getter
        return balance;
    }
};

Account x;
x.deposit(50);          // allowed (public)
// x.balance = 999;     // ERROR (private)
```

### Next Steps

The next lecture covers **constructors** — special methods that set up an object's data the moment it is created, replacing the in-class default values used here.
