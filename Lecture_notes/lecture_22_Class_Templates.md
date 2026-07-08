# CS143 — Class Templates

> **Course:** CS143 Introduction to C++ · **Instructor:** Dr. Fawaz Alazemi
> **Builds on:** classes, and the STL (`vector`, `map`).

---

## Table of Contents

1. [Introduction](#1-introduction)
2. [The Idea: A Blank for the Type](#2-the-idea-a-blank-for-the-type)
3. [Writing a Class Template](#3-writing-a-class-template)
4. [Using a Template](#4-using-a-template)
5. [Defining Members Outside the Class](#5-defining-members-outside-the-class)
6. [Several Type Parameters](#6-several-type-parameters)
7. [The STL Is Built From Templates](#7-the-stl-is-built-from-templates)
8. [A Generic Stack](#8-a-generic-stack)
9. [How Python Differs](#9-how-python-differs)
10. [Common Mistakes](#10-common-mistakes)
11. [Practice Exercises](#11-practice-exercises)
12. [Summary](#12-summary)

---

## 1. Introduction

Suppose you need a small class that holds one value. If you write a separate class for each type, you end up repeating almost the same code again and again:

```cpp
class IntBox {
    int value;
public:
    IntBox(int v) : value(v) { }
    int get() { return value; }
};

class DoubleBox {           // almost identical...
    double value;
public:
    DoubleBox(double v) : value(v) { }
    double get() { return value; }
};
// ...and a StringBox, and a CharBox, and...
```

These classes differ in only **one type**. Copying the whole class for each type is repetitive and error-prone — fix a bug in one and you must fix it in all the copies. A **class template** lets you write the class **once** and let the type vary.

---

## 2. The Idea: A Blank for the Type

A class template uses a placeholder type — usually called `T` — instead of a fixed type. You fill in the real type later.

```cpp
template <typename T>
class Box {
    T value;              // T stands in for a real type
public:
    Box(T v) : value(v) { }
    T get() { return value; }
};
```

When you use `Box<int>`, the compiler makes a version of the class with `T` replaced by `int`. One definition now serves `int`, `double`, `string`, and any other type:

```
                 template<typename T>
                 class Box { T value; }
                 /          |          \
           Box<int>    Box<double>    Box<string>
          int value;  double value;  string value;

   the compiler stamps out one version per type you use
```

---

## 3. Writing a Class Template

The syntax has two parts: the template line, then the class.

```cpp
template <typename T>
class Box { ... };
```

- `template <typename T>` goes right before the class.
- `T` is a name you choose — it stands for whatever type is used.
- Inside the class, use `T` wherever you would normally write a type.
- `typename` and `class` mean the same thing here, so `template <class T>` also works.

When you write `Box<int>`, every `T` in the template is replaced by `int`:

```
   class Box {          Box<int>      class Box<int> {
       T value;        --------->         int value;
       Box(T v);                          Box(int v);
       T get();                           int get();
   };                                  };

   every T in the template is replaced by int
```

---

## 4. Using a Template

To create an object, name the real type in **angle brackets**. That type replaces `T` everywhere for this object.

```cpp
Box<int>    a(5);        // a Box that holds an int
Box<string> b("hi");     // a Box that holds a string
Box<double> c(3.14);     // a Box that holds a double

cout << a.get() << endl;   // 5
cout << b.get() << endl;   // hi
```

Note that `Box<int>` and `Box<string>` are **different types** — you cannot assign one to the other. You have seen these angle brackets before, in `vector<int>`.

Here is a complete program:

```cpp
#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Box {
    T value;
public:
    Box(T v) : value(v) { }
    T get() { return value; }
    void set(T v) { value = v; }
};

int main() {
    Box<int>    a(5);
    Box<string> b("hello");

    cout << a.get() << endl;   // 5
    cout << b.get() << endl;   // hello
    return 0;
}
```

**Output:**
```
5
hello
```

The single `Box` template serves both an `int` and a `string`; the compiler builds the right version for each.

---

## 5. Defining Members Outside the Class

You can define a template's methods outside the class, but the syntax is more verbose: every definition repeats the template line, and the class name becomes `Box<T>`.

```cpp
template <typename T>
class Box {
    T value;
public:
    Box(T v);
    T get();
};

// each outside definition repeats the template line
template <typename T>
Box<T>::Box(T v) : value(v) { }

template <typename T>
T Box<T>::get() {
    return value;
}
```

For beginners, defining members **inside** the class is simpler and is used in the rest of these notes. One practical point: template definitions usually live entirely in a header file, because the compiler needs to see the full template wherever it is used.

---

## 6. Several Type Parameters

A template can take more than one type parameter. List each one, separated by commas.

```cpp
template <typename K, typename V>
class Pair {
    K key;
    V value;
public:
    Pair(K k, V v) : key(k), value(v) { }
    K getKey()   { return key; }
    V getValue() { return value; }
};
```

Create one by naming both types:

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    Pair<string, int> p("age", 30);
    cout << p.getKey() << ": " << p.getValue() << endl;   // age: 30
    return 0;
}
```

**Output:**
```
age: 30
```

Here `K` is `string` and `V` is `int`. This is exactly the idea behind `map<string, int>`.

---

## 7. The STL Is Built From Templates

Every STL container is a class template. The angle brackets you have been writing are template type arguments.

| You write | What it means |
|-----------|---------------|
| `vector<int>` | the `vector` template with `T = int` |
| `vector<string>` | the same template with `T = string` |
| `map<string, int>` | a template with two type parameters |

The takeaway: you have used templates all along — now you can write your own.

---

## 8. A Generic Stack

Putting it together, here is a small container that works for any type. It stores its items in a `vector<T>`, a template you already know.

```cpp
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Stack {
    vector<T> items;
public:
    void push(T x) { items.push_back(x); }
    T    top()     { return items.back(); }
    void pop()     { items.pop_back(); }
    bool empty()   { return items.empty(); }
};

int main() {
    Stack<int> s;
    s.push(1);
    s.push(2);
    cout << s.top() << endl;   // 2
    s.pop();
    cout << s.top() << endl;   // 1
    return 0;
}
```

**Output:**
```
2
1
```

`Stack<T>` works for any type. Change `Stack<int>` to `Stack<string>` and it stores words instead — with no other changes.

---

## 9. How Python Differs

| Goal | Python | C++ |
|------|--------|-----|
| Hold any type | works automatically | use a template |
| Name the type | not needed | `Box<int>` |
| Type checking | at run time | at compile time |

Python is **dynamically typed**, so a container or function already accepts any type — no templates are needed. C++ is **statically typed**: templates give that same flexibility while the compiler still checks types for you. In other words, templates bring Python-like flexibility without giving up compile-time safety.

---

## 10. Common Mistakes

**1. Forgetting the type in angle brackets**

**Wrong:**
```cpp
Box a(5);          // which type?
```

**Correct:**
```cpp
Box<int> a(5);
```

**Explanation:** a template becomes a real class only when you name a type in `< >`.

**2. Missing the template line on outside members**

**Wrong:**
```cpp
T Box<T>::get() { return value; }         // no template line
```

**Correct:**
```cpp
template <typename T>
T Box<T>::get() { return value; }
```

**Explanation:** each member defined outside the class needs its own `template <typename T>` line.

**3. Mixing different versions**

**Wrong:**
```cpp
Box<int> a(5);
Box<double> b = a;     // Box<int> and Box<double> are different types
```

**Correct:**
```cpp
Box<int> a(5);
Box<int> b = a;
```

**Explanation:** each type argument produces a distinct type.

**4. Using an operation the type does not support**

**Wrong:**
```cpp
// a method uses  a < b  but T is a type with no < defined
```

**Correct:**
```cpp
// only use < with a T that supports it (like int or string)
```

**Explanation:** the template's code must be valid for whatever type is supplied.

**5. Splitting a template across a .cpp file**

**Wrong:**
```cpp
// template declared in a header, defined in a separate .cpp -> linker errors
```

**Correct:**
```cpp
// keep the full template definition in the header
```

**Explanation:** the compiler must see the whole template where it is used.

**6. Confusing `<<` with `< >`**

**Wrong:**
```cpp
Box<<int>> a(5);   // << is the shift/stream operator, not a type
```

**Correct:**
```cpp
Box<int> a(5);     // angle brackets name a type
```

**Explanation:** the angle brackets around a type are not the stream operator.

---

## 11. Practice Exercises

Try each one before opening the solution.

**Exercise 1.** Write a class template `Box<T>` with a constructor, `get()`, and `set()`.

<details>
<summary>Click to see solution</summary>

```cpp
template <typename T>
class Box {
    T value;
public:
    Box(T v) : value(v) { }
    T get() { return value; }
    void set(T v) { value = v; }
};
```
</details>

**Exercise 2.** Create a `Box<double>` holding `3.14` and print its value.

<details>
<summary>Click to see solution</summary>

```cpp
Box<double> b(3.14);
cout << b.get() << endl;   // 3.14
```
</details>

**Exercise 3.** Write a template `Pair<A, B>` that stores two values, with `getFirst()` and `getSecond()`.

<details>
<summary>Click to see solution</summary>

```cpp
template <typename A, typename B>
class Pair {
    A first;
    B second;
public:
    Pair(A a, B b) : first(a), second(b) { }
    A getFirst()  { return first; }
    B getSecond() { return second; }
};
```
</details>

**Exercise 4.** Given `template <typename T> class Stack` with a `vector<T> items;` member, write a `push(T)` method.

<details>
<summary>Click to see solution</summary>

```cpp
void push(T x) {
    items.push_back(x);
}
```
</details>

**Exercise 5.** Explain what `vector<string>` means in template terms.

<details>
<summary>Click to see solution</summary>

`vector` is a class template, and `string` is the type argument. So `vector<string>` is the vector template built with `T = string` — a vector that stores strings.
</details>

**Exercise 6.** Find and fix the error: `Box b(5);` where `Box` is a template.

<details>
<summary>Click to see solution</summary>

A template needs a type in angle brackets. `Box b(5);` does not say which type, so it will not compile. Fix it by naming the type:

```cpp
Box<int> b(5);
```
</details>

---

## 12. Summary

### Key Concepts

- A **class template** writes one class that works for any type, using a placeholder `T`.
- You create real classes by naming a type in angle brackets, such as `Box<int>`.
- The STL containers are all class templates.

### Important Points

1. Put `template <typename T>` before the class; use `T` as a type inside.
2. `typename` and `class` are interchangeable in the template line.
3. `Box<int>` and `Box<string>` are different, unrelated types.
4. A template can take several type parameters, like `Pair<K, V>`.
5. Members defined outside the class each need their own template line, and templates usually live in headers.
6. A template becomes a real class only when you name a type in `< >`.

### Quick Reference

```cpp
// one type parameter
template <typename T>
class Box {
    T value;
public:
    Box(T v) : value(v) { }
    T get() { return value; }
};

Box<int>    a(5);
Box<string> b("hi");

// two type parameters
template <typename K, typename V>
class Pair {
    K key; V value;
public:
    Pair(K k, V v) : key(k), value(v) { }
};

Pair<string, int> p("age", 30);
```

### The One Rule to Remember

Write the class once with a placeholder type; it becomes a real class only when you name a type in `< >`.
