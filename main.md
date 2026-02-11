```{=html}
<!-- ====================================== -->
```
```{=html}
<!--  C++ for Python Programmers (Intro)    -->
```
```{=html}
<!-- ====================================== -->
```
# 🚀 C++ for Python Programmers

## Introduction + Variables Guide

> 📌 Designed for students who **completed Python first**\
> Goal: learn **syntax differences only**, not programming from scratch

------------------------------------------------------------------------

# 🎯 Why Learn C++ After Python?

You already know how to:

✅ Think algorithmically\
✅ Use variables\
✅ Write loops\
✅ Use conditions

So now we only learn:

👉 **How to write the SAME ideas in C++**

### Why C++?

-   ⚡ Much faster
-   🧠 More control over memory
-   🎮 Used in games, systems, robotics, cybersecurity, HPC
-   🏆 Industry + research favorite

------------------------------------------------------------------------

# 🆚 Python vs C++ (Big Picture)

  Concept       Python        C++
  ------------- ------------- -----------
  Execution     interpreted   compiled
  Speed         slower        very fast
  Types         dynamic       static
  Syntax        simple        stricter
  Performance   medium        high

💡 **Same logic --- different syntax**

------------------------------------------------------------------------

# 🧠 Mental Model Shift

## Python

``` python
x = 5
```

## C++

``` cpp
int x = 5;
```

### New rules in C++

-   Must write the **type**
-   Must end with **;**
-   Uses **{ }** blocks

More rules → more control → more speed

------------------------------------------------------------------------

# 🏗 First C++ Program

``` cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Hello World";
    return 0;
}
```

### What each part means

  Part       Purpose
  ---------- ---------------------
  #include   import library
  main()     program starts here
  cout       print
  ;          end of statement

------------------------------------------------------------------------

# 📦 Variables

## What is a variable?

A **named container** that stores data.

👉 Same concept as Python

------------------------------------------------------------------------

# 🔹 Variable Syntax

## Template

``` cpp
type name = value;
```

## Example

``` cpp
int age = 20;
```

------------------------------------------------------------------------

# 🔹 Common Data Types

  Type     Stores               Example
  -------- -------------------- ---------
  int      integers             10
  double   decimals             3.14
  float    decimals (smaller)   2.5
  char     single character     'A'
  bool     true/false           true
  string   text                 "Hello"

------------------------------------------------------------------------

# 🔹 Python → C++ Examples

## Python

``` python
age = 20
height = 175.5
name = "Ali"
```

## C++

``` cpp
int age = 20;
double height = 175.5;
string name = "Ali";
```

👉 Notice: **type must be written first**

------------------------------------------------------------------------

# 🔹 Declare Now, Assign Later

``` cpp
int x;
double y;

x = 5;
y = 3.2;
```

------------------------------------------------------------------------

# 🔹 Printing Output

## Python

``` python
print(x)
```

## C++

``` cpp
cout << x;
```

Multiple values:

``` cpp
cout << x << " " << y;
```

------------------------------------------------------------------------

# 🔹 Reading Input

## Python

``` python
x = input()
```

## C++

``` cpp
cin >> x;
```

Example:

``` cpp
int age;
cin >> age;
```

------------------------------------------------------------------------

# 🔹 Arithmetic Operators

Same as Python:

  Operator   Example
  ---------- -----------
  \+         a + b
  \-         a - b
  \*         a \* b
  /          a / b
  \%         remainder

``` cpp
int r = 10 % 3; // 1
```

------------------------------------------------------------------------

# ⚠️ Common Beginner Mistakes

## ❌ Missing type

``` cpp
x = 5;
```

## ✅ Correct

``` cpp
int x = 5;
```

------------------------------------------------------------------------

## ❌ Missing semicolon

``` cpp
int x = 5
```

## ✅ Correct

``` cpp
int x = 5;
```

------------------------------------------------------------------------

## ❌ Case sensitive

``` cpp
Age ≠ age
```

------------------------------------------------------------------------

# 🧪 Quick Practice

## Exercise 1

Create: - age - height - name\
Print them.

------------------------------------------------------------------------

## Exercise 2

Input two numbers → print their sum.

------------------------------------------------------------------------

## Exercise 3

Convert this Python code:

``` python
a = 5
b = 7
print(a + b)
```

------------------------------------------------------------------------

# ✅ Lesson Summary

After this lesson you can:

✔ Write a C++ program\
✔ Declare variables\
✔ Use data types\
✔ Print and read input\
✔ Understand differences from Python

------------------------------------------------------------------------

# ➡️ Next Lecture

# 👉 if statements (decision making)
