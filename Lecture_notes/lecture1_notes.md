# CS143 — Introduction to C++
## Lecture 1: Your First Program, and Talking to the User
**Instructor:** Dr. Fawaz Alazemi
**For:** Students who finished CS101 (Python)

---

### How to use these notes

These notes go with the Lecture 1 slides. They explain each idea in more detail, add extra worked examples, and give you more exercises to practice. Read a section, type the code yourself, run it, and only then move on. Programming is learned by doing, not by reading.

You already know how to *think* like a programmer from CS101. In this lecture, most of what is new is the **spelling and the rules** of a new language, not the ideas.

---

## 1. What you already learned in CS101

In CS101 you used Python to learn the core ideas of programming. All of these ideas exist in C++ too:

- Variables that store values.
- Decisions with `if`, `if-else`, and `if-elif-else`.
- Repetition with `while` loops and `for` loops.
- Nested conditions and nested loops.
- Calling functions to do work.
- Lists and other collections.
- Reading input from the user and printing output.
- Breaking a big problem into small steps.

C++ keeps every one of these ideas. What changes is *how you write them*. C++ asks you to be more exact: you must state the **type** of each variable, end most lines with a **semicolon** (`;`), and group code with **braces** (`{ }`) instead of indentation.

---

## 2. What is C++?

C++ is a **general-purpose programming language**. It is known for being **fast** and is used to build games, operating systems, web browsers, banking systems, and other software where speed matters.

### Compiled vs. interpreted

This is the biggest difference from Python.

| | Python | C++ |
|---|---|---|
| How code runs | An **interpreter** reads and runs your code line by line. | A **compiler** first translates *all* your code into a machine program. Then you run that program. |
| When mistakes appear | Often while the program is running. | Many mistakes are caught at **compile time**, before the program runs. |
| Speed | Slower | Usually much faster |
| Extra step before running | No | Yes — you must **compile** first |

Think of it like this. Python is like a translator standing next to you, translating each sentence as you speak. C++ is like sending a whole document to a translator, getting back a finished translation, and then reading that.

---

## 3. Writing, compiling, and running

A C++ program lives in a text file that ends with `.cpp`, for example `hello.cpp`.

The steps are:

1. **Write** your code and save it as `hello.cpp`.
2. **Compile** it. A common compiler is `g++`.
3. **Run** the program that the compiler produced.

On a Linux or Mac terminal:

```bash
g++ hello.cpp -o hello   # compile: makes a program called "hello"
./hello                  # run the program
```

On Windows, the produced file is usually `hello.exe`, and you run it by typing `hello`.

> **Tip:** If you do not have a compiler installed yet, you can use a free online C++ compiler in your web browser to practice. The code is exactly the same.

If you make a typing mistake, the compiler stops and prints an **error message** with a line number. Always read the **first** error first — later errors are often caused by the first one.

---

## 4. The anatomy of a C++ program

Here is the classic first program again. Every line has a purpose.

```cpp
#include <iostream>   // brings in input/output tools
using namespace std;  // lets us write cout instead of std::cout

int main() {          // the program starts running here
    cout << "Hello, World!" << endl;  // print one line of text
    return 0;         // tell the system: finished, no error
}
```

**Expected output:**

```
Hello, World!
```

Line by line:

- `#include <iostream>` — Loads the standard tool for input and output. Without it, `cin` and `cout` do not exist. The `#` marks it as an instruction to the compiler before the real code.
- `using namespace std;` — Lets you write short names such as `cout` instead of the longer `std::cout`. It is a convenience.
- `int main() { ... }` — Every C++ program must have a function named `main`. Running the program means running the code inside `main`'s braces. The `int` means `main` gives back a whole number when it finishes.
- `cout << "Hello, World!" << endl;` — Sends text to the screen, then a new line.
- `return 0;` — Reports success to the system. `0` means "everything went fine".
- The braces `{ }` group the statements that belong to `main`.
- The semicolon `;` ends each statement. Forgetting it is the most common beginner error.

---

## 5. Output with `cout`

`cout` (pronounced "see-out") sends data to the screen. The `<<` operator means "send this to `cout`". You can chain many `<<` in one line.

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "I am learning C++" << endl;   // text
    cout << "The answer is " << 42 << endl; // text + number together
    cout << 5 + 3 << endl;                  // C++ does the math first
    return 0;
}
```

**Expected output:**

```
I am learning C++
The answer is 42
8
```

Notes:
- You can mix text and numbers on one line by chaining `<<`.
- `endl` ends the line and moves to the next. You can also use `"\n"` inside text for a new line.
- **Python compare:** `print("Hi")` adds a new line for you automatically. In C++, *you* add `endl` or `"\n"` when you want one.

---

## 6. Input with `cin`

`cin` (pronounced "see-in") reads what the user types. The `>>` operator means "take from `cin` and store it". Notice the arrows point the **opposite** way from `cout`.

```cpp
#include <iostream>
using namespace std;

int main() {
    int age;                     // make a box for a whole number
    cout << "Enter your age: ";  // ask first (no endl, stay on line)
    cin >> age;                  // read the typed value into age
    cout << "Next year you will be " << age + 1 << endl;
    return 0;
}
```

**Example run** (the user types `20`):

```
Enter your age: 20
Next year you will be 21
```

Important rules:
- You must **declare the variable first**, with its type: `int age;`.
- `cin >> age` reads a value that matches the variable's type. Reading into an `int` reads a whole number.
- You can read several values at once: `cin >> a >> b;` reads two values separated by spaces or new lines.

### Reading a full line of text

`cin >> name` reads only **one word**; it stops at the first space. To read a whole line, including spaces, use `getline`:

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string fullName;
    cout << "Enter your full name: ";
    getline(cin, fullName);          // read the whole line
    cout << "Hello, " << fullName << "!" << endl;
    return 0;
}
```

**Example run** (user types `Sara Ahmad`):

```
Enter your full name: Sara Ahmad
Hello, Sara Ahmad!
```

**Python compare:** Python's `input()` always returns text and never stops at a space. C++ gives you a choice: `cin >>` for one word, `getline` for a full line.

---

## 7. A first look at variables and types

In Python you wrote `age = 20` and Python decided the type for you. In C++ you must state the type. Here are the types you will use most often at the start:

| Type | Holds | Example |
|---|---|---|
| `int` | whole numbers | `int score = 90;` |
| `double` | numbers with a decimal point | `double price = 4.5;` |
| `char` | a single character | `char grade = 'A';` |
| `bool` | true or false | `bool passed = true;` |
| `string` | text (needs `#include <string>`) | `string name = "Ali";` |

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    int students = 30;       // whole number
    double average = 87.5;   // decimal number
    char section = 'B';      // single character, single quotes
    bool isOpen = true;      // true or false
    string course = "CS143"; // text, double quotes

    cout << course << " has " << students << " students." << endl;
    cout << "Average: " << average << ", Section: " << section << endl;
    return 0;
}
```

**Expected output:**

```
CS143 has 30 students.
Average: 87.5, Section: B
```

> **Watch the quotes:** text (`string`) uses double quotes `"..."`. A single `char` uses single quotes `'...'`. They are not the same.

We will study types and arithmetic in detail in the next lecture. For now you just need them for the examples below.

---

## 8. Comments

Comments are notes for humans. The compiler ignores them.

```cpp
// This is a single-line comment.

/* This is a
   multi-line comment. */
```

**Python compare:** Python uses `#` for comments. C++ uses `//` for one line and `/* ... */` for several lines.

---

## 9. Additional worked examples

These examples build directly on the slides. For each one: read what it does, type it, run it, and check the output.

### Example A — Add two numbers

**Goal:** read two whole numbers and print their sum.

```cpp
#include <iostream>
using namespace std;

int main() {
    int a, b;                       // two boxes on one line
    cout << "Enter two numbers: ";
    cin >> a >> b;                  // read both, separated by a space
    cout << "Sum = " << a + b << endl;
    return 0;
}
```

**Example run** (user types `7 5`):

```
Enter two numbers: 7 5
Sum = 12
```

**Explanation:** `cin >> a >> b` reads two values in one statement. The math `a + b` happens before it is sent to `cout`.

---

### Example B — A simple receipt

**Goal:** read a price and a quantity, then print the total.

```cpp
#include <iostream>
using namespace std;

int main() {
    double price;
    int quantity;
    cout << "Price of one item: ";
    cin >> price;
    cout << "How many: ";
    cin >> quantity;
    cout << "Total = " << price * quantity << endl;
    return 0;
}
```

**Example run** (user types `2.5` then `4`):

```
Price of one item: 2.5
How many: 4
Total = 10
```

**Explanation:** Here we mix two types — a `double` for the price and an `int` for the quantity. C++ handles the multiplication and gives a decimal result.

---

### Example C — Swap-free average

**Goal:** read three test scores and print the average.

```cpp
#include <iostream>
using namespace std;

int main() {
    double s1, s2, s3;
    cout << "Enter three scores: ";
    cin >> s1 >> s2 >> s3;
    double average = (s1 + s2 + s3) / 3;   // brackets first, then divide
    cout << "Average = " << average << endl;
    return 0;
}
```

**Example run** (user types `80 90 100`):

```
Enter three scores: 80 90 100
Average = 90
```

**Explanation:** The brackets force the addition to happen before the division, just like in mathematics.

---

### Example D — Greeting with a full name

**Goal:** read a full name (with a space) and greet the user.

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string name;
    cout << "Enter your full name: ";
    getline(cin, name);            // read the whole line
    cout << "Welcome to CS143, " << name << "." << endl;
    return 0;
}
```

**Example run** (user types `Fatima Al-Sabah`):

```
Enter your full name: Fatima Al-Sabah
Welcome to CS143, Fatima Al-Sabah.
```

**Explanation:** Because the name has a space, we use `getline` instead of `cin >>`, which would stop at the first space.

---

### Example E — Rectangle area and perimeter

**Goal:** read width and height, print both area and perimeter.

```cpp
#include <iostream>
using namespace std;

int main() {
    double width, height;
    cout << "Width: ";
    cin >> width;
    cout << "Height: ";
    cin >> height;
    cout << "Area = " << width * height << endl;
    cout << "Perimeter = " << 2 * (width + height) << endl;
    return 0;
}
```

**Example run** (user types `5` then `3`):

```
Width: 5
Height: 3
Area = 15
Perimeter = 16
```

**Explanation:** One program can read several inputs and print several results. Each `cout` line prints one result.

---

## 10. Common mistakes (with the errors you will see)

| Mistake | Wrong code | Fix |
|---|---|---|
| Missing semicolon | `cout << "Hi"` | `cout << "Hi";` |
| Wrong arrow direction | `cin << age;` | `cin >> age;` |
| Forgot the include | uses `cout` with no `#include <iostream>` | add `#include <iostream>` |
| No type on a variable | `age = 20;` | `int age = 20;` |
| Wrong capital letters | `Cout << "Hi";` | `cout << "Hi";` |
| Python-style printing | `print("Hi")` | `cout << "Hi" << endl;` |
| Using `string` without its header | `string name;` with no `#include <string>` | add `#include <string>` |
| Single vs double quotes | `char c = "A";` | `char c = 'A';` |

A few common compiler messages and what they usually mean:

- *"expected ';' before ..."* → You forgot a semicolon on the line above.
- *"'cout' was not declared in this scope"* → You forgot `#include <iostream>` or `using namespace std;`.
- *"expected '}' at end of input"* → You opened a brace `{` but never closed it.

---

## 11. Python ↔ C++ quick reference

| Task | Python | C++ |
|---|---|---|
| Print text | `print("Hi")` | `cout << "Hi" << endl;` |
| Print text + value | `print("Age", age)` | `cout << "Age " << age << endl;` |
| Read one word/number | `x = input()` | `cin >> x;` |
| Read a whole line | `x = input()` | `getline(cin, x);` |
| Whole number variable | `n = 5` | `int n = 5;` |
| Decimal variable | `p = 4.5` | `double p = 4.5;` |
| Text variable | `s = "hi"` | `string s = "hi";` |
| One-line comment | `# note` | `// note` |
| Group code | indentation | `{ braces }` |
| End of statement | new line | `;` |

---

## 12. Practice exercises

Write a complete C++ program for each task. Save, compile, run, and test with your own input. Solutions are at the end — try first, then check.

**Set 1 — Output only**
1. Print three lines: your name, your major, and your favourite food.
2. Print a small box made of stars, exactly like this:
   ```
   ****
   *  *
   ****
   ```
3. Print the result of `15 * 4` and `100 - 37` on two separate lines.

**Set 2 — Input and output**
4. Ask the user for their first name, then print `Welcome, <name>!`.
5. Read two whole numbers and print their sum and their product.
6. Read a circle's radius (`double`) and print its area using `3.14159 * radius * radius`.
7. Read a temperature in Celsius (`double`) and print it in Fahrenheit using `c * 9 / 5 + 32`.

**Set 3 — A little harder**
8. Read three numbers and print their average (use brackets so division happens last).
9. Read the user's full name with `getline`, then greet them by the full name.
10. Read a number of seconds (`int`) and print how many whole minutes and leftover seconds it is. (Hint: minutes = `total / 60`, leftover = `total % 60`, where `%` gives the remainder.)

---

## 13. Exercise answers

> Try the exercises yourself before reading these.

**1 — Three facts**
```cpp
#include <iostream>
using namespace std;
int main() {
    cout << "Ali" << endl;
    cout << "Computer Science" << endl;
    cout << "Machboos" << endl;
}
```

**2 — Star box**
```cpp
#include <iostream>
using namespace std;
int main() {
    cout << "****" << endl;
    cout << "*  *" << endl;
    cout << "****" << endl;
}
```

**3 — Two calculations**
```cpp
#include <iostream>
using namespace std;
int main() {
    cout << 15 * 4 << endl;    // 60
    cout << 100 - 37 << endl;  // 63
}
```

**4 — Welcome message**
```cpp
#include <iostream>
#include <string>
using namespace std;
int main() {
    string name;
    cin >> name;
    cout << "Welcome, " << name << "!" << endl;
}
```

**5 — Sum and product**
```cpp
#include <iostream>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    cout << "Sum: " << a + b << endl;
    cout << "Product: " << a * b << endl;
}
```
Input `3 4` → `Sum: 7` then `Product: 12`.

**6 — Circle area**
```cpp
#include <iostream>
using namespace std;
int main() {
    double radius;
    cin >> radius;
    cout << "Area: " << 3.14159 * radius * radius << endl;
}
```
Input `2` → `Area: 12.5664`.

**7 — Celsius to Fahrenheit**
```cpp
#include <iostream>
using namespace std;
int main() {
    double c;
    cin >> c;
    cout << c << " C = " << c * 9 / 5 + 32 << " F" << endl;
}
```
Input `25` → `25 C = 77 F`.

**8 — Average of three**
```cpp
#include <iostream>
using namespace std;
int main() {
    double a, b, c;
    cin >> a >> b >> c;
    cout << "Average: " << (a + b + c) / 3 << endl;
}
```
Input `80 90 100` → `Average: 90`.

**9 — Full-name greeting**
```cpp
#include <iostream>
#include <string>
using namespace std;
int main() {
    string name;
    getline(cin, name);
    cout << "Hello, " << name << "!" << endl;
}
```
Input `Sara Ahmad` → `Hello, Sara Ahmad!`.

**10 — Seconds to minutes**
```cpp
#include <iostream>
using namespace std;
int main() {
    int total;
    cin >> total;
    cout << total / 60 << " minutes and "
         << total % 60 << " seconds" << endl;
}
```
Input `130` → `2 minutes and 10 seconds`.

---

## 14. Summary

- C++ is a **compiled** language: write → compile → run.
- Every program starts in `int main() { ... }`.
- Each statement ends with `;`, and code blocks use braces `{ }`.
- `cout <<` sends output to the screen; `endl` (or `"\n"`) ends a line.
- `cin >>` reads one word or number; `getline(cin, x)` reads a whole line.
- Every variable needs a **type**: `int`, `double`, `char`, `bool`, `string`.
- `string` and `getline` need `#include <string>`.

### Mini glossary

| Term | Meaning |
|---|---|
| Compiler | A tool that turns your C++ code into a runnable program. |
| Statement | A single instruction, ending with `;`. |
| `main` | The function where every C++ program starts. |
| `#include` | An instruction that loads extra tools before your code. |
| `cout` / `cin` | The standard objects for output and input. |
| Type | The kind of value a variable holds (`int`, `double`, ...). |

**Next lecture:** variables, data types, and arithmetic in C++ — in detail.
