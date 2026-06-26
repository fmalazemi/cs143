# CS143 — Lecture 13: Introduction to Object-Oriented Programming

> **Course:** CS143 Introduction to C++ · **Instructor:** Dr. Fawaz Alazemi
> **This lecture introduces the *idea* of OOP. Syntax and mechanics are covered in later lectures.**

---

## Table of Contents

1. [Introduction](#1-introduction)
2. [The Story So Far](#2-the-story-so-far)
3. [The Big Idea: Objects](#3-the-big-idea-objects)
4. [Class vs. Object](#4-class-vs-object)
5. [Attributes and Methods](#5-attributes-and-methods)
6. [A First Taste of a Class](#6-a-first-taste-of-a-class)
7. [Why Use OOP?](#7-why-use-oop)
8. [The Four Big Ideas](#8-the-four-big-ideas)
9. [Common Misconceptions](#9-common-misconceptions)
10. [Concept Exercises](#10-concept-exercises)
11. [Summary](#11-summary)

---

## 1. Introduction

**Object-Oriented Programming (OOP)** is a way of organising a program around **objects**. An object keeps its own data and the actions that work on that data together in one place.

This lecture is about the **concept** only. We will look at what objects, classes, attributes, and methods are, and why this style of programming is useful. The detailed rules — how to write classes correctly, protect data, and more — are the subject of the lectures that follow.

By the end of these notes you should be able to:

- Explain what an object is.
- Tell a class apart from an object.
- Identify the attributes (data) and methods (behaviour) of a thing.
- Say why OOP helps with larger programs.
- Name the four big ideas studied later.

---

## 2. The Story So Far

Until now, our programs have kept **data** and **functions** apart. Variables held the data, and separate functions acted on that data, with the values passed in and results passed back.

For small programs this works well — a few variables and functions are easy to follow. But as programs grow, this style becomes hard to manage:

- Many loose variables are hard to keep track of.
- It is unclear which function is meant to work with which data.
- A change in one part can quietly break another part.

OOP offers a tidier approach: keep related data and the actions on it **together**, as a single unit.

---

## 3. The Big Idea: Objects

In OOP we build programs out of **objects**. An object bundles two things:

- its own **data** (what it knows), and
- its own **behaviour** (what it can do).

```
            Dog object
 +-------------------------------+
 |  DATA (attributes)            |
 |     name = "Rex"              |
 |     age  = 3                  |
 |- - - - - - - - - - - - - - - -|
 |  BEHAVIOUR (methods)          |
 |     bark()                    |
 |     eat()                     |
 +-------------------------------+
```

Everyday things work the same way. Each one *has* properties and *can do* actions:

- A **car** has a colour, a speed, and fuel; it can drive, brake, and refuel.
- A **bank account** has an owner and a balance; it can take deposits and withdrawals.

The properties are the data; the actions are the behaviour. OOP lets us model things this way in code.

---

## 4. Class vs. Object

This is the most important distinction in OOP.

- A **class** is a *blueprint* that describes a kind of thing. It lists what every object of that kind will have and be able to do — but it is not a real thing itself.
- An **object** is one real example built from that blueprint.

```
   class Car (blueprint)            objects made from it
 +----------------------+         +------------------------+
 | has: colour, speed   |  --->   | car1 · red   · speed 0 |
 | can: drive(), brake()|         | car2 · blue  · speed 20|
 +----------------------+         | car3 · black · speed 5 |
                                  +------------------------+
```

One class can create many objects. Each object has its **own** copy of the data, so changing `car1` does not affect `car2`.

A simple way to remember it: **Dog** is a class (a kind of thing), while **Rex the dog** is an object (one real dog).

---

## 5. Attributes and Methods

An object has two kinds of members.

**Attributes — the data.**
- The values an object holds.
- They describe its current state.
- Example: a car's `colour` and `speed`.

**Methods — the behaviour.**
- The actions an object can perform.
- They often read or change the object's attributes.
- Example: a car's `drive()` and `brake()`.

Together they make an object **self-contained**: it carries its own data and knows how to act on it.

---

## 6. A First Taste of a Class

Here is what a class looks like in C++. This is only to see the *shape* — do not worry about every keyword yet.

```cpp
// a blueprint for a Car
class Car {
public:
    string colour;     // attribute (data)
    int speed;         // attribute (data)

    void drive() {     // method (behaviour)
        speed = speed + 10;
    }
};
```

And here is how we make and use an object from that blueprint:

```cpp
int main() {
    Car myCar;          // create an object from the blueprint
    myCar.colour = "red";
    myCar.speed = 0;

    myCar.drive();      // call its method

    cout << myCar.speed; // 10
    return 0;
}
```

**Output:**
```
10
```

The key points to notice:

- `class Car { ... };` defines the blueprint, with attributes and a method inside it.
- `Car myCar;` creates one object from the blueprint.
- We reach an object's parts with a dot: `myCar.speed`, `myCar.drive()`.
- Calling `myCar.drive()` changes *that object's own* data.

*(Keywords such as `public`, and how to protect data, are covered in the next lecture.)*

---

## 7. Why Use OOP?

- **Organisation:** related data and actions stay together in one place.
- **Modelling:** code mirrors real things — a `Student`, an `Account`, a `Car`.
- **Reuse:** one class can create many objects, and classes can build on other classes.
- **Safety:** an object can protect its data, allowing changes only through its own methods.
- **Teamwork:** large programs split neatly into classes that people can work on separately.

In short, OOP helps us manage **complexity** as programs grow.

---

## 8. The Four Big Ideas

OOP rests on four key ideas. We only name them here; each is studied in a later lecture.

1. **Encapsulation** — keep data and methods together, and protect the data.
2. **Abstraction** — show only what matters; hide the inner details.
3. **Inheritance** — build new classes based on existing ones.
4. **Polymorphism** — let one action behave correctly for different objects.

---

## 9. Common Misconceptions

**1. "A class and an object are the same thing."**
A class is a blueprint; an object is a real example made from it. One class can produce many objects.

**2. "All objects of a class share the same data."**
Each object has its **own** copy of the attributes. Changing one object's data does not change another's.

**3. "Methods are just ordinary functions."**
A method belongs to a class and works on a particular object's data. That connection to the object is what makes it a method rather than a free function.

**4. "OOP is only about writing classes."**
Writing classes is the tool; the real goal is to **organise** a program around objects so it is easier to understand, reuse, and extend.

**5. "I need to learn all the OOP keywords first."**
The concept comes first: data and behaviour bundled into objects. The keywords and rules make more sense once the idea is clear — which is why the details come later.

---

## 10. Concept Exercises

These ask you to *think*, not to write code. Try each before opening the answer.

**Exercise 1.** For a `BankAccount`, list two attributes and two methods.

<details>
<summary>Click to see answer</summary>

Attributes: `owner`, `balance`. Methods: `deposit()`, `withdraw()`.
</details>

**Exercise 2.** "Sara's red Toyota and Ali's blue Honda are both cars." What is the class, and what are the objects?

<details>
<summary>Click to see answer</summary>

The **class** is `Car`. The **objects** are Sara's Toyota and Ali's Honda — two real cars made from that blueprint.
</details>

**Exercise 3.** For a `Student`, give three attributes and two methods.

<details>
<summary>Click to see answer</summary>

Attributes: `name`, `id`, `gpa`. Methods: `study()`, `enrol()`. (Other reasonable answers are fine.)
</details>

**Exercise 4.** Is **Dog** a class or an object? Is **Rex the dog** a class or an object?

<details>
<summary>Click to see answer</summary>

**Dog** is a class (a kind of thing). **Rex the dog** is an object (one real dog).
</details>

**Exercise 5.** Sort these into data or behaviour: `name`, `bark()`, `age`, `eat()`.

<details>
<summary>Click to see answer</summary>

Data (attributes): `name`, `age`. Behaviour (methods): `bark()`, `eat()`.
</details>

---

## 11. Summary

### Key Concepts

- OOP organises programs around **objects** instead of loose data and functions.
- An **object** bundles its own **data** (attributes) and **behaviour** (methods).
- A **class** is the blueprint; an **object** is a real example made from it.

### Important Points

1. One class can create many objects, each with its own copy of the data.
2. Attributes describe what an object knows; methods describe what it can do.
3. We reach an object's parts with a dot (for example, `myCar.speed`).
4. OOP helps us model real things and manage complexity as programs grow.
5. The four big ideas — encapsulation, abstraction, inheritance, polymorphism — come later.

### Quick Reference (vocabulary)

| Term | Meaning |
|------|---------|
| Class | a blueprint describing a kind of thing |
| Object | one real example made from a class |
| Attribute | a piece of an object's data (its state) |
| Method | an action an object can perform |

### Next Steps

The next lecture defines classes properly: how to declare attributes and methods, and how to protect an object's data so it can only be changed in safe ways.
