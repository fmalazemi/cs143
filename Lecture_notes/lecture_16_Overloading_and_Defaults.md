# CS143 — Function Overloading &amp; Default Arguments

> **Course:** CS143 Introduction to C++ · **Instructor:** Dr. Fawaz Alazemi
> **Builds on:** Lecture 7 (functions) and constructors.

---

## Table of Contents

1. [Introduction](#1-introduction)
2. [Overloading by Type and Number](#2-overloading-by-type-and-number)
3. [Return Type Does Not Count](#3-return-type-does-not-count)
4. [Overloading Methods in a Class](#4-overloading-methods-in-a-class)
5. [Default Arguments](#5-default-arguments)
6. [The Trailing Rule](#6-the-trailing-rule)
7. [Overloading vs. Default Arguments](#7-overloading-vs-default-arguments)
8. [Defaults in Methods and Constructors](#8-defaults-in-methods-and-constructors)
9. [Common Mistakes](#9-common-mistakes)
10. [Practice Exercises](#10-practice-exercises)
11. [Summary](#11-summary)

---

## 1. Introduction

This lecture covers two related tools that let one clear name serve many related calls.

- **Function overloading** — give several functions the *same name*, as long as their parameters differ. The compiler picks the right one from the arguments.
- **Default arguments** — give a parameter a built-in value, used when the caller leaves it out, so one function handles several call forms.

Without overloading you would need a different name for each case:

```cpp
printInt(5);
printDouble(3.14);
printString("hi");
```

With overloading, one name does the job:

```cpp
print(5);
print(3.14);
print("hi");
```

The compiler matches each call to the version whose parameters fit, by their **number** and **types**:

```
  add(2, 3)     ---->   add(int, int)
  add(2, 3, 4)  ---->   add(int, int, int)
```

---

## 2. Overloading by Type and Number

Overloads may differ by the **type** of their parameters, the **number** of parameters, or both.

**By type:**

```cpp
#include <iostream>
using namespace std;

void print(int x)    { cout << "int: " << x << endl; }
void print(double x) { cout << "double: " << x << endl; }
void print(string x) { cout << "string: " << x << endl; }

int main() {
    print(5);        // matches print(int)
    print(3.14);     // matches print(double)
    print("hi");     // matches print(string)
    return 0;
}
```

**Output:**
```
int: 5
double: 3.14
string: hi
```

**By number:**

```cpp
int add(int a, int b)        { return a + b; }
int add(int a, int b, int c) { return a + b + c; }

int main() {
    cout << add(2, 3) << endl;      // 5
    cout << add(2, 3, 4) << endl;   // 9
    return 0;
}
```

**Output:**
```
5
9
```

The count of arguments decides which `add` runs.

---

## 3. Return Type Does Not Count

Overloads must differ in their **parameters**. The return type alone is **not** enough to tell two versions apart.

```cpp
int    f();
double f();   // ERROR: same name, same (empty) parameters
```

Think of the **signature** as the function's name plus its parameter list:

```
   int     add (int, int)
   ^^^      ^^^^^^^^^^^^^^
   return   the signature — overloads must differ here
   type
   (ignored)
```

Because both `f` versions have the same name and the same (empty) parameter list, the compiler cannot choose between them, no matter what they return.

---

## 4. Overloading Methods in a Class

Methods inside a class can be overloaded in exactly the same way as free functions.

```cpp
#include <iostream>
using namespace std;

class Calculator {
public:
    int add(int a, int b) {
        return a + b;
    }
    double add(double a, double b) {
        return a + b;
    }
};

int main() {
    Calculator c;
    cout << c.add(2, 3) << endl;       // 5
    cout << c.add(2.5, 1.5) << endl;   // 4
    return 0;
}
```

**Output:**
```
5
4
```

The integer call uses the `int` version; the decimal call uses the `double` one. (You have already seen this: having both `Box()` and `Box(int, int)` is *constructor overloading* — the same idea applied to constructors.)

---

## 5. Default Arguments

A **default argument** gives a parameter a value to use when the caller leaves it out. One function then serves several call forms.

```
  void greet(string name = "friend")

  greet()        ->  name = "friend"   (default used)
  greet("Sara")  ->  name = "Sara"     (given value used)
```

```cpp
#include <iostream>
using namespace std;

void greet(string name = "friend",
           string word = "Hello") {
    cout << word << ", " << name << "!" << endl;
}

int main() {
    greet();                 // both defaults
    greet("Sara");           // name given
    greet("Ali", "Welcome"); // both given
    return 0;
}
```

**Output:**
```
Hello, friend!
Hello, Sara!
Welcome, Ali!
```

One function handles three call styles. Any argument you leave out uses its default value.

---

## 6. The Trailing Rule

Default arguments must be the **trailing** (right-most) parameters. Once one parameter has a default, every parameter to its right must have one too.

```cpp
// OK: the default is the last parameter
void f(int a, int b = 10);

// OK: the last two have defaults
void g(int a, int b = 2, int c = 3);

// ERROR: a default cannot come before a normal parameter
void h(int a = 1, int b);   // wrong
```

The reason is simple: when you skip arguments, C++ fills them in **from the right**. If a non-default parameter sat to the right of a default one, there would be no way to know which argument you meant. Also, give a default **once** (normally in the declaration), not in two places.

---

## 7. Overloading vs. Default Arguments

|  | Overloading | Default arguments |
|--|-------------|-------------------|
| How many functions | several, one per case | just one |
| Bodies can differ | yes, fully | no, one shared body |
| Best when | cases need different code | cases differ only by a value |

**Caution — do not let them clash.** If an overload and a default argument both fit the same call, the compiler cannot choose:

```cpp
void f(int a);
void f(int a, int b = 0);
f(5);   // ERROR: ambiguous — matches both
```

---

## 8. Defaults in Methods and Constructors

A constructor with default arguments can replace several overloaded constructors.

```cpp
#include <iostream>
using namespace std;

class Box {
private:
    int w, h;
public:
    // one constructor, three ways to call it
    Box(int width = 1, int height = 1) {
        w = width;
        h = height;
    }
    int area() { return w * h; }
};

int main() {
    Box a;          // 1 x 1
    Box b(5);       // 5 x 1
    Box c(5, 3);    // 5 x 3
    cout << a.area() << " " << b.area()
         << " " << c.area();   // 1 5 15
    return 0;
}
```

**Output:**
```
1 5 15
```

A single constructor with defaults handles all three call forms. Missing arguments fall back to `1`.

---

## 9. Common Mistakes

**1. Only the return type differs**

**Wrong:**
```cpp
int    f();
double f();   // clash: same name, same parameters
```

**Correct:**
```cpp
int f();
int f(int x);   // differ by parameters
```

**Explanation:** the return type is not part of what distinguishes overloads.

**2. Identical parameter lists**

**Wrong:**
```cpp
void g(int a) { }
void g(int b) { }   // same: one int parameter
```

**Correct:**
```cpp
void g(int a) { }
void g(int a, int b) { }   // different number of parameters
```

**Explanation:** renaming a parameter does not create a new overload; the *types and number* must differ.

**3. Expecting a run-time choice**

**Wrong:**
```cpp
// believing the version is decided while the program runs
```

**Correct:**
```cpp
// the overload is chosen at COMPILE time, from the argument types
```

**Explanation:** overload resolution happens when the program is compiled, not while it runs.

**4. Default argument not on the right**

**Wrong:**
```cpp
void h(int a = 1, int b);   // default before a normal parameter
```

**Correct:**
```cpp
void h(int a, int b = 1);   // defaults must be trailing
```

**Explanation:** arguments are filled from the right, so defaults must be the right-most parameters.

**5. Giving the default twice**

**Wrong:**
```cpp
void f(int x = 5);          // declaration
void f(int x = 5) { }       // definition repeats the default
```

**Correct:**
```cpp
void f(int x = 5);          // state the default once
void f(int x) { }           // definition has no default
```

**Explanation:** a default value is written once, normally in the declaration.

**6. Overload and default clashing**

**Wrong:**
```cpp
void f(int a);
void f(int a, int b = 0);
f(5);   // ambiguous: fits both
```

**Correct:**
```cpp
void f(int a);
void f(int a, int b);   // no default that overlaps the first
```

**Explanation:** if a call could match both an overload and a defaulted version, the compiler cannot choose.

---

## 10. Practice Exercises

Try each one before opening the solution.

**Exercise 1.** Write two functions named `maxOf`: one for `(int, int)` and one for `(double, double)`. Call both.

<details>
<summary>Click to see solution</summary>

```cpp
int maxOf(int a, int b) {
    return (a > b) ? a : b;
}
double maxOf(double a, double b) {
    return (a > b) ? a : b;
}
// maxOf(3, 7) -> 7 ; maxOf(2.5, 1.1) -> 2.5
```
</details>

**Exercise 2.** Write `greet(string name = "friend")` that prints a greeting. Call it with and without an argument.

<details>
<summary>Click to see solution</summary>

```cpp
void greet(string name = "friend") {
    cout << "Hello, " << name << endl;
}
// greet();       -> Hello, friend
// greet("Sara"); -> Hello, Sara
```
</details>

**Exercise 3.** Overload `area`: `area(int side)` for a square and `area(int w, int h)` for a rectangle.

<details>
<summary>Click to see solution</summary>

```cpp
int area(int side) {       // square
    return side * side;
}
int area(int w, int h) {   // rectangle
    return w * h;
}
// area(4) -> 16 ; area(4, 3) -> 12
```
</details>

**Exercise 4.** Write `power(int base, int exp = 2)` that returns `base` to the power `exp`. Call `power(5)` and `power(2, 3)`.

<details>
<summary>Click to see solution</summary>

```cpp
int power(int base, int exp = 2) {
    int result = 1;
    for (int i = 0; i < exp; i++)
        result *= base;
    return result;
}
// power(5)    -> 25  (exp = 2)
// power(2, 3) -> 8
```
</details>

**Exercise 5.** Explain why `void h(int a = 1, int b)` is an error.

<details>
<summary>Click to see solution</summary>

A default argument must be a **trailing** parameter. In `h(int a = 1, int b)`, `b` has no default but comes after one that does. Because C++ fills missing arguments from the right, it could not work out what you meant, so this is not allowed. The fix is `h(int a, int b = 1)`.
</details>

**Exercise 6.** Write a class `Box` with a constructor `Box(int w = 1, int h = 1)`; create `Box()`, `Box(4)`, and `Box(4, 3)`.

<details>
<summary>Click to see solution</summary>

```cpp
class Box {
private:
    int w, h;
public:
    Box(int width = 1, int height = 1) {
        w = width; h = height;
    }
    int area() { return w * h; }
};

int main() {
    Box a;       // 1 x 1  -> area 1
    Box b(4);    // 4 x 1  -> area 4
    Box c(4, 3); // 4 x 3  -> area 12
}
```
</details>

---

## 11. Summary

### Key Concepts

- **Overloading:** several functions share one name, differing by the number or types of parameters.
- **Default arguments:** a parameter carries a built-in value used when the caller omits it.
- Both let one clear name serve many related calls.

### Important Points

1. The compiler picks the overload that fits the arguments, at compile time.
2. The **return type alone** cannot tell two overloads apart.
3. Methods and constructors can be overloaded just like free functions.
4. Default arguments must be the **trailing** parameters, and stated once.
5. Use overloading when cases need different code; use defaults when they differ only by a value.
6. Do not let an overload and a default argument make a call ambiguous.

### Quick Reference

```cpp
// overloading: different parameters, same name
int  add(int a, int b);
int  add(int a, int b, int c);

// default argument: trailing parameter with a value
void greet(string name = "friend");
greet();          // uses "friend"
greet("Sara");    // uses "Sara"

// one constructor with defaults replaces several
Box(int w = 1, int h = 1);
Box a;       // 1 x 1
Box b(5);    // 5 x 1
Box c(5, 3); // 5 x 3
```

### Next Steps

These are both forms of **compile-time** choosing. Later in OOP, **polymorphism** introduces a different idea: choosing the right behaviour while the program runs.
