# Lecture 12: Scope in C++

## Table of Contents

1. [Introduction](#introduction)
2. [What is Scope?](#what-is-scope)
   - [Why Scope Matters](#why-scope-matters)
   - [Real-World Analogies](#real-world-analogies)
3. [Types of Scope in C++](#types-of-scope-in-c)
   - [Local Scope (Block Scope)](#local-scope-block-scope)
   - [Function Scope](#function-scope)
   - [Global Scope](#global-scope)
   - [Namespace Scope](#namespace-scope)
   - [Class Scope](#class-scope)
4. [Scope Resolution Operator (::)](#scope-resolution-operator-)
5. [Variable Shadowing](#variable-shadowing)
6. [Lifetime vs. Scope](#lifetime-vs-scope)
7. [Static Variables and Scope](#static-variables-and-scope)
8. [Nested Scopes and Block Scope](#nested-scopes-and-block-scope)
9. [Scope in Loops and Conditionals](#scope-in-loops-and-conditionals)
10. [Common Mistakes](#common-mistakes)
11. [Practice Exercises](#practice-exercises)
12. [Summary](#summary)

---

## Introduction

**Scope** determines the region of a program where a variable, function, or other identifier is accessible and valid. Every name you declare in C++ exists within a specific scope, and attempting to use a name outside its scope results in a compilation error.

Understanding scope is essential for writing correct, maintainable C++ programs. It prevents naming conflicts, controls memory usage, and ensures that variables are only accessible where they are needed.

### Why Scope Matters

- **Prevents naming conflicts:** You can use the same variable name in different scopes without collision.
- **Controls variable lifetime:** Scope determines when a variable is created and destroyed.
- **Improves code readability:** Limiting where a variable is visible makes code easier to understand.
- **Enhances security:** Sensitive data can be restricted to the smallest possible region of code.

### Real-World Analogies

- **Rooms in a house:** A variable declared inside a room (function) is only visible inside that room. The hallway (global scope) is visible from every room.
- **Company departments:** An employee badge (variable) may grant access to their own department (local scope) but not to other departments. A master key (global variable) opens every door.
- **Notebooks and pages:** Writing something on a specific page (block) means it only exists on that page. Writing on the cover (global) means it is visible from anywhere in the notebook.

---

## What is Scope?

Scope is the **visibility region** of an identifier (variable, function, class, etc.). In C++, scope is primarily determined by the placement of curly braces `{}`. Every opening brace `{` begins a new scope, and every closing brace `}` ends it.

```cpp
#include <iostream>
using namespace std;

int main() {
    // This is the scope of main()
    int x = 10;
    cout << x << endl; // x is visible here

    {
        // This is a nested (inner) scope
        int y = 20;
        cout << x << endl; // x is still visible here
        cout << y << endl; // y is visible here
    }

    // cout << y << endl; // ERROR: y is NOT visible here
    return 0;
}
```

**Output:**
```
10
10
20
```

---

## Types of Scope in C++

C++ has several types of scope. Each type controls where an identifier can be accessed.

### Local Scope (Block Scope)

A variable declared inside a block `{}` has **local scope**. It exists only within that block and is destroyed when the block ends. This is the most common type of scope you will encounter.

```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 5; // local to main()

    {
        int b = 10; // local to this inner block
        cout << "Inside block: a = " << a << ", b = " << b << endl;
    }

    cout << "Outside block: a = " << a << endl;
    // cout << b; // ERROR: b is not defined here
    return 0;
}
```

**Output:**
```
Inside block: a = 5, b = 10
Outside block: a = 5
```

Variables declared in a block are **automatically destroyed** when the block ends. You cannot access them after the closing brace.

```cpp
#include <iostream>
using namespace std;

int main() {
    for (int i = 0; i < 3; i++) {
        int temp = i * 10;
        cout << "temp = " << temp << endl;
    }
    // cout << i;    // ERROR: i is not defined here
    // cout << temp; // ERROR: temp is not defined here
    return 0;
}
```

**Output:**
```
temp = 0
temp = 10
temp = 20
```

```cpp
#include <iostream>
using namespace std;

void demonstrate() {
    int localVar = 42;
    cout << "localVar inside function: " << localVar << endl;
}

int main() {
    demonstrate();
    // cout << localVar; // ERROR: localVar is not accessible here
    return 0;
}
```

**Output:**
```
localVar inside function: 42
```

### Function Scope

Function scope applies specifically to **labels** used with `goto` statements. A label declared anywhere in a function is visible throughout the entire function. In practice, you rarely use `goto` in modern C++, but it is important to know this scope exists.

```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 1;

    if (x == 1) {
        goto done; // jump to label
    }

    cout << "This will be skipped." << endl;

done: // label has function scope — visible everywhere in main()
    cout << "Reached the 'done' label." << endl;
    return 0;
}
```

**Output:**
```
Reached the 'done' label.
```

### Global Scope

A variable declared **outside** all functions and blocks has **global scope**. It is accessible from any function in the same file (and from other files if declared with `extern`). Global variables exist for the entire duration of the program.

```cpp
#include <iostream>
using namespace std;

int globalCounter = 0; // global scope

void increment() {
    globalCounter++;
    cout << "Counter in increment(): " << globalCounter << endl;
}

void display() {
    cout << "Counter in display(): " << globalCounter << endl;
}

int main() {
    cout << "Counter in main(): " << globalCounter << endl;
    increment();
    increment();
    display();
    return 0;
}
```

**Output:**
```
Counter in main(): 0
Counter in increment(): 1
Counter in increment(): 2
Counter in display(): 2
```

Global variables should be used sparingly. They create **hidden dependencies** between functions and make debugging harder. Prefer local variables and pass data through function parameters.

```cpp
#include <iostream>
using namespace std;

string appName = "MyApp"; // global variable

void printHeader() {
    cout << "=== Welcome to " << appName << " ===" << endl;
}

void printFooter() {
    cout << "=== Thank you for using " << appName << " ===" << endl;
}

int main() {
    printHeader();
    cout << "Running..." << endl;
    printFooter();
    return 0;
}
```

**Output:**
```
=== Welcome to MyApp ===
Running...
=== Thank you for using MyApp ===
```

```cpp
#include <iostream>
using namespace std;

const double PI = 3.14159265; // global constant (acceptable use)

double circleArea(double radius) {
    return PI * radius * radius;
}

double circleCircumference(double radius) {
    return 2 * PI * radius;
}

int main() {
    double r = 5.0;
    cout << "Area: " << circleArea(r) << endl;
    cout << "Circumference: " << circleCircumference(r) << endl;
    return 0;
}
```

**Output:**
```
Area: 78.5398
Circumference: 31.4159
```

### Namespace Scope

A **namespace** provides a named scope to group related identifiers and avoid naming conflicts. You use the `namespace` keyword to define one, and access its members with the `::` operator.

```cpp
#include <iostream>
using namespace std;

namespace Math {
    double PI = 3.14159;
    double square(double x) {
        return x * x;
    }
}

namespace Physics {
    double PI = 3.14159265; // no conflict with Math::PI
    double kineticEnergy(double mass, double velocity) {
        return 0.5 * mass * velocity * velocity;
    }
}

int main() {
    cout << "Math::PI = " << Math::PI << endl;
    cout << "Physics::PI = " << Physics::PI << endl;
    cout << "Square of 4 = " << Math::square(4) << endl;
    cout << "KE = " << Physics::kineticEnergy(10, 3) << endl;
    return 0;
}
```

**Output:**
```
Math::PI = 3.14159
Physics::PI = 3.14159
Square of 4 = 16
KE = 45
```

```cpp
#include <iostream>
using namespace std;

namespace Graphics {
    void draw() {
        cout << "Drawing a shape on screen." << endl;
    }
}

namespace Audio {
    void draw() { // same name, different namespace — no conflict
        cout << "Drawing audio waveform." << endl;
    }
}

int main() {
    Graphics::draw();
    Audio::draw();
    return 0;
}
```

**Output:**
```
Drawing a shape on screen.
Drawing audio waveform.
```

```cpp
#include <iostream>
using namespace std;

namespace Utils {
    int add(int a, int b) { return a + b; }
    int multiply(int a, int b) { return a * b; }
}

int main() {
    using namespace Utils; // bring entire namespace into scope
    cout << "Add: " << add(3, 4) << endl;
    cout << "Multiply: " << multiply(3, 4) << endl;
    return 0;
}
```

**Output:**
```
Add: 7
Multiply: 12
```

### Class Scope

Variables and functions declared inside a **class** have class scope. They are accessible through objects of that class (or within member functions). Access modifiers (`public`, `private`, `protected`) further control visibility within class scope.

```cpp
#include <iostream>
using namespace std;

class Student {
private:
    string name; // class scope — only accessible inside Student
    int age;

public:
    void setData(string n, int a) {
        name = n; // accessible here (same class)
        age = a;
    }

    void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main() {
    Student s;
    s.setData("Alice", 20);
    s.display();
    // cout << s.name; // ERROR: name is private
    return 0;
}
```

**Output:**
```
Name: Alice, Age: 20
```

```cpp
#include <iostream>
using namespace std;

class Rectangle {
public:
    double width;
    double height;

    double area() {
        return width * height; // width and height have class scope
    }

    double perimeter() {
        return 2 * (width + height);
    }
};

int main() {
    Rectangle r;
    r.width = 5.0;
    r.height = 3.0;
    cout << "Area: " << r.area() << endl;
    cout << "Perimeter: " << r.perimeter() << endl;
    return 0;
}
```

**Output:**
```
Area: 15
Perimeter: 16
```

```cpp
#include <iostream>
using namespace std;

class Counter {
private:
    int count;

public:
    Counter() : count(0) {}

    void increment() { count++; }
    void decrement() { count--; }
    int getCount() { return count; }
};

int main() {
    Counter c;
    c.increment();
    c.increment();
    c.increment();
    c.decrement();
    cout << "Count: " << c.getCount() << endl;
    return 0;
}
```

**Output:**
```
Count: 2
```

---

## Scope Resolution Operator (::)

The **scope resolution operator** `::` is used to specify which scope a name belongs to. It is essential when you need to disambiguate names or access global variables that are shadowed by local ones.

```cpp
#include <iostream>
using namespace std;

int value = 100; // global variable

int main() {
    int value = 50; // local variable — shadows the global one
    cout << "Local value: " << value << endl;
    cout << "Global value: " << ::value << endl; // :: accesses global
    return 0;
}
```

**Output:**
```
Local value: 50
Global value: 100
```

```cpp
#include <iostream>
using namespace std;

int x = 999;

void printX() {
    int x = 1;
    cout << "Local x: " << x << endl;
    cout << "Global x: " << ::x << endl;
}

int main() {
    printX();
    return 0;
}
```

**Output:**
```
Local x: 1
Global x: 999
```

```cpp
#include <iostream>
using namespace std;

class MyClass {
public:
    void display(); // declared inside class
};

// Defined outside class using ::
void MyClass::display() {
    cout << "MyClass::display() called" << endl;
}

int main() {
    MyClass obj;
    obj.display();
    return 0;
}
```

**Output:**
```
MyClass::display() called
```

---

## Variable Shadowing

**Variable shadowing** occurs when a variable in an inner scope has the same name as a variable in an outer scope. The inner variable "hides" or "shadows" the outer one within its scope.

```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 10; // outer x
    cout << "Outer x: " << x << endl;

    {
        int x = 20; // inner x — shadows outer x
        cout << "Inner x: " << x << endl;
    }

    cout << "Outer x again: " << x << endl; // outer x is unchanged
    return 0;
}
```

**Output:**
```
Outer x: 10
Inner x: 20
Outer x again: 10
```

```cpp
#include <iostream>
using namespace std;

int num = 100; // global

void test() {
    int num = 50; // shadows global num
    cout << "Local num: " << num << endl;

    {
        int num = 25; // shadows function-level num
        cout << "Block num: " << num << endl;
    }

    cout << "Local num again: " << num << endl;
    cout << "Global num: " << ::num << endl;
}

int main() {
    test();
    return 0;
}
```

**Output:**
```
Local num: 50
Block num: 25
Local num again: 50
Global num: 100
```

Shadowing can cause subtle bugs. Many compilers will warn you about shadowed variables if you enable warnings with `-Wshadow`.

```cpp
#include <iostream>
using namespace std;

void calculate(int value) {
    cout << "Parameter value: " << value << endl;
    for (int value = 0; value < 3; value++) { // shadows parameter!
        cout << "Loop value: " << value << endl;
    }
    cout << "Parameter value after loop: " << value << endl;
}

int main() {
    calculate(100);
    return 0;
}
```

**Output:**
```
Parameter value: 100
Loop value: 0
Loop value: 1
Loop value: 2
Parameter value after loop: 100
```

---

## Lifetime vs. Scope

**Scope** and **lifetime** are related but different concepts. Scope defines **where** a variable is accessible. Lifetime defines **how long** a variable exists in memory.

| Concept | Definition | Example |
|---------|-----------|---------|
| **Scope** | Where a variable name is visible | Inside a function, inside a block |
| **Lifetime** | How long the variable exists in memory | Until the block ends, until the program ends |

For **local variables**, scope and lifetime are identical — the variable is created when the block is entered and destroyed when the block exits. For **global variables**, the lifetime is the entire program, and the scope is the file (or files with `extern`). For **static local variables**, the lifetime extends for the entire program, but the scope is limited to the enclosing block.

```cpp
#include <iostream>
using namespace std;

void demo() {
    int localVar = 0;          // lifetime: this call only
    static int staticVar = 0;  // lifetime: entire program

    localVar++;
    staticVar++;

    cout << "localVar: " << localVar
         << ", staticVar: " << staticVar << endl;
}

int main() {
    demo(); // localVar=1, staticVar=1
    demo(); // localVar=1, staticVar=2
    demo(); // localVar=1, staticVar=3
    return 0;
}
```

**Output:**
```
localVar: 1, staticVar: 1
localVar: 1, staticVar: 2
localVar: 1, staticVar: 3
```

---

## Static Variables and Scope

A **static local variable** retains its value between function calls. It is initialized only once and exists until the program ends. However, its scope remains limited to the function where it is declared.

```cpp
#include <iostream>
using namespace std;

void countCalls() {
    static int count = 0; // initialized once, retains value
    count++;
    cout << "This function has been called " << count << " time(s)." << endl;
}

int main() {
    countCalls();
    countCalls();
    countCalls();
    // cout << count; // ERROR: count is not in scope here
    return 0;
}
```

**Output:**
```
This function has been called 1 time(s).
This function has been called 2 time(s).
This function has been called 3 time(s).
```

```cpp
#include <iostream>
using namespace std;

int generateID() {
    static int id = 1000;
    return id++;
}

int main() {
    cout << "ID: " << generateID() << endl;
    cout << "ID: " << generateID() << endl;
    cout << "ID: " << generateID() << endl;
    cout << "ID: " << generateID() << endl;
    return 0;
}
```

**Output:**
```
ID: 1000
ID: 1001
ID: 1002
ID: 1003
```

```cpp
#include <iostream>
using namespace std;

double runningAverage(double newValue) {
    static double sum = 0;
    static int count = 0;
    sum += newValue;
    count++;
    return sum / count;
}

int main() {
    cout << "Avg: " << runningAverage(10) << endl;
    cout << "Avg: " << runningAverage(20) << endl;
    cout << "Avg: " << runningAverage(30) << endl;
    cout << "Avg: " << runningAverage(40) << endl;
    return 0;
}
```

**Output:**
```
Avg: 10
Avg: 15
Avg: 20
Avg: 25
```

---

## Nested Scopes and Block Scope

C++ allows you to create **nested scopes** using braces `{}` at any point in your code. Each inner scope can access variables from outer scopes, but outer scopes cannot access variables from inner scopes.

```cpp
#include <iostream>
using namespace std;

int main() {
    int level1 = 1;

    {
        int level2 = 2;
        cout << "Level 1: " << level1 << endl; // accessible
        cout << "Level 2: " << level2 << endl; // accessible

        {
            int level3 = 3;
            cout << "Level 1: " << level1 << endl; // accessible
            cout << "Level 2: " << level2 << endl; // accessible
            cout << "Level 3: " << level3 << endl; // accessible
        }

        // cout << level3; // ERROR: not accessible
    }

    // cout << level2; // ERROR: not accessible
    return 0;
}
```

**Output:**
```
Level 1: 1
Level 2: 2
Level 1: 1
Level 2: 2
Level 3: 3
```

```cpp
#include <iostream>
using namespace std;

int main() {
    // Using blocks to limit variable scope intentionally
    {
        int temp = 42;
        cout << "Processing: " << temp << endl;
    } // temp is destroyed here

    {
        string temp = "hello"; // no conflict — different scope
        cout << "Processing: " << temp << endl;
    } // temp is destroyed here

    {
        double temp = 3.14; // no conflict — different scope
        cout << "Processing: " << temp << endl;
    }

    return 0;
}
```

**Output:**
```
Processing: 42
Processing: hello
Processing: 3.14
```

---

## Scope in Loops and Conditionals

Variables declared inside `for`, `while`, and `if` blocks follow block scope rules. The loop variable in a `for` loop is scoped to the loop itself.

```cpp
#include <iostream>
using namespace std;

int main() {
    // i is scoped to the for loop
    for (int i = 0; i < 3; i++) {
        cout << "i = " << i << endl;
    }
    // cout << i; // ERROR: i is out of scope

    // Separate loops can reuse the same name
    for (int i = 10; i < 13; i++) {
        cout << "i = " << i << endl;
    }

    return 0;
}
```

**Output:**
```
i = 0
i = 1
i = 2
i = 10
i = 11
i = 12
```

```cpp
#include <iostream>
using namespace std;

int main() {
    int score = 85;

    if (score >= 90) {
        string grade = "A";
        cout << "Grade: " << grade << endl;
    } else if (score >= 80) {
        string grade = "B"; // different scope from the "A" block
        cout << "Grade: " << grade << endl;
    } else {
        string grade = "C";
        cout << "Grade: " << grade << endl;
    }

    // cout << grade; // ERROR: grade is not accessible here
    return 0;
}
```

**Output:**
```
Grade: B
```

```cpp
#include <iostream>
using namespace std;

int main() {
    int sum = 0;
    int i = 0;

    while (i < 5) {
        int square = i * i; // local to the while block
        sum += square;
        i++;
    }

    cout << "Sum of squares: " << sum << endl;
    cout << "Final i: " << i << endl;
    // cout << square; // ERROR: square is out of scope
    return 0;
}
```

**Output:**
```
Sum of squares: 30
Final i: 5
```

---

## Common Mistakes

### Mistake 1: Using a Variable Outside Its Scope

**Wrong:**
```cpp
#include <iostream>
using namespace std;

int main() {
    if (true) {
        int x = 10;
    }
    cout << x << endl; // ERROR: x is out of scope
    return 0;
}
```

**Correct:**
```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 0; // declare outside the block
    if (true) {
        x = 10;
    }
    cout << x << endl;
    return 0;
}
```

**Explanation:** The variable `x` was declared inside the `if` block and destroyed when the block ended. To use it after the block, declare it before the block.

---

### Mistake 2: Accidentally Shadowing a Variable

**Wrong:**
```cpp
#include <iostream>
using namespace std;

int main() {
    int count = 10;
    for (int i = 0; i < 5; i++) {
        int count = i; // accidentally shadows outer count
        // now you can't access the original count here
    }
    cout << "count: " << count << endl; // still 10, not modified
    return 0;
}
```

**Correct:**
```cpp
#include <iostream>
using namespace std;

int main() {
    int count = 10;
    for (int i = 0; i < 5; i++) {
        count = i; // modifies the outer count as intended
    }
    cout << "count: " << count << endl; // now 4
    return 0;
}
```

**Explanation:** Declaring `int count` inside the loop creates a new variable that shadows the outer `count`. Remove the type declaration to modify the outer variable instead.

---

### Mistake 3: Overusing Global Variables

**Wrong:**
```cpp
#include <iostream>
using namespace std;

int result; // global — shared by all functions

void add(int a, int b) {
    result = a + b;
}

void multiply(int a, int b) {
    result = a * b; // overwrites the addition result!
}

int main() {
    add(3, 4);
    multiply(5, 6);
    cout << "Addition result: " << result << endl; // prints 30, not 7!
    return 0;
}
```

**Correct:**
```cpp
#include <iostream>
using namespace std;

int add(int a, int b) {
    return a + b;
}

int multiply(int a, int b) {
    return a * b;
}

int main() {
    int sum = add(3, 4);
    int product = multiply(5, 6);
    cout << "Addition result: " << sum << endl;     // 7
    cout << "Multiply result: " << product << endl;  // 30
    return 0;
}
```

**Explanation:** Using global variables for function results creates hidden dependencies. Return values from functions instead to keep each function independent.

---

### Mistake 4: Forgetting That Loop Variables Are Local

**Wrong:**
```cpp
#include <iostream>
using namespace std;

int main() {
    for (int i = 0; i < 5; i++) {
        // processing
    }
    cout << "Loop ran " << i << " times." << endl; // ERROR: i not in scope
    return 0;
}
```

**Correct:**
```cpp
#include <iostream>
using namespace std;

int main() {
    int i;
    for (i = 0; i < 5; i++) {
        // processing
    }
    cout << "Loop ran " << i << " times." << endl; // works: i is 5
    return 0;
}
```

**Explanation:** When you declare `i` inside the `for` statement, it is scoped to the loop. If you need `i` after the loop, declare it before the loop.

---

### Mistake 5: Returning a Reference/Pointer to a Local Variable

**Wrong:**
```cpp
#include <iostream>
using namespace std;

int* createValue() {
    int value = 42;
    return &value; // DANGER: value is destroyed when function ends!
}

int main() {
    int* ptr = createValue();
    cout << *ptr << endl; // undefined behavior!
    return 0;
}
```

**Correct:**
```cpp
#include <iostream>
using namespace std;

int* createValue() {
    int* value = new int(42); // allocated on the heap — survives function exit
    return value;
}

int main() {
    int* ptr = createValue();
    cout << *ptr << endl; // safe: memory still valid
    delete ptr;           // don't forget to free!
    return 0;
}
```

**Explanation:** Local variables are destroyed when their scope ends. Returning a pointer to a local variable creates a **dangling pointer** — the memory is no longer valid. Use dynamic allocation (`new`) or return by value instead.

---

## Practice Exercises

### Exercise 1: Predict the Output

What will the following code print? Trace through it carefully.

```cpp
#include <iostream>
using namespace std;

int x = 5;

void foo() {
    int x = 10;
    cout << x << endl;
    {
        int x = 15;
        cout << x << endl;
    }
    cout << x << endl;
}

int main() {
    cout << x << endl;
    foo();
    cout << x << endl;
    return 0;
}
```

**Expected Output:**
```
5
10
15
10
5
```

<details>
<summary>Click to see solution</summary>

```cpp
// Line-by-line trace:
// 1. main() starts, prints global x = 5
// 2. foo() is called
//    - local x = 10 is created, shadows global x
//    - prints local x = 10
//    - inner block: new x = 15 shadows foo's x
//    - prints inner x = 15
//    - inner block ends, inner x destroyed
//    - prints foo's x = 10
// 3. foo() returns, its local x destroyed
// 4. main() prints global x = 5 (unchanged)
```
</details>

---

### Exercise 2: Fix the Scope Error

The following code has a scope error. Fix it so that it compiles and prints the sum correctly.

```cpp
#include <iostream>
using namespace std;

int main() {
    for (int i = 1; i <= 10; i++) {
        int sum = 0;
        sum += i;
    }
    cout << "Sum: " << sum << endl;
    return 0;
}
```

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int sum = 0; // move declaration outside the loop
    for (int i = 1; i <= 10; i++) {
        sum += i;
    }
    cout << "Sum: " << sum << endl;
    return 0;
}
```

**Output:**
```
Sum: 55
```

Two fixes were needed: (1) move `sum` outside the loop so it persists across iterations, and (2) the original code reset `sum` to 0 on every iteration.
</details>

---

### Exercise 3: Write a Counter Using Static Variables

Write a function `getNextID()` that returns a unique integer ID starting from 1, incrementing by 1 on each call. Use a static variable. Call it 5 times from `main()` and print each ID.

**Expected Output:**
```
ID: 1
ID: 2
ID: 3
ID: 4
ID: 5
```

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int getNextID() {
    static int id = 0;
    id++;
    return id;
}

int main() {
    for (int i = 0; i < 5; i++) {
        cout << "ID: " << getNextID() << endl;
    }
    return 0;
}
```
</details>

---

### Exercise 4: Namespace Practice

Create two namespaces: `Geometry` and `Algebra`. In `Geometry`, create a function `area(double r)` that returns the area of a circle. In `Algebra`, create a function `area(double a, double b)` that returns `a * b` (area of a rectangle). Call both from `main()`.

**Expected Output:**
```
Circle area: 78.5398
Rectangle area: 20
```

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

namespace Geometry {
    const double PI = 3.14159265;
    double area(double r) {
        return PI * r * r;
    }
}

namespace Algebra {
    double area(double a, double b) {
        return a * b;
    }
}

int main() {
    cout << "Circle area: " << Geometry::area(5.0) << endl;
    cout << "Rectangle area: " << Algebra::area(4.0, 5.0) << endl;
    return 0;
}
```
</details>

---

### Exercise 5: Scope Detective

The following code compiles but has a logic bug caused by variable shadowing. Find the bug and fix it so the function correctly doubles the input value.

```cpp
#include <iostream>
using namespace std;

int doubleValue(int num) {
    int result = num * 2;
    {
        int result = 0; // bug: shadows the correct result
        cout << "Checking: " << result << endl;
    }
    return result;
}

int main() {
    cout << "Doubled: " << doubleValue(5) << endl;
    cout << "Doubled: " << doubleValue(12) << endl;
    return 0;
}
```

**Expected Output (after fix):**
```
Checking: 10
Doubled: 10
Checking: 24
Doubled: 24
```

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int doubleValue(int num) {
    int result = num * 2;
    {
        // Don't redeclare result — use the outer one
        cout << "Checking: " << result << endl;
    }
    return result;
}

int main() {
    cout << "Doubled: " << doubleValue(5) << endl;
    cout << "Doubled: " << doubleValue(12) << endl;
    return 0;
}
```

The inner block declared a new `int result = 0` which shadowed the outer `result`. Although this didn't affect the return value (which used the outer `result`), the "Checking" message printed 0 instead of the actual doubled value. Removing the inner declaration fixes the logic bug.
</details>

---

## Summary

### Key Concepts

- **Scope** is the region of code where a variable or identifier is accessible
- **Local (block) scope** limits visibility to the enclosing `{}`
- **Global scope** makes variables accessible everywhere in the file
- **Namespace scope** groups identifiers to avoid naming conflicts
- **Class scope** controls access through access modifiers
- **The scope resolution operator `::` ** accesses global or namespace members
- **Variable shadowing** occurs when an inner variable hides an outer one
- **Static variables** have local scope but program-long lifetime

### Important Points

1. Variables are destroyed when their scope ends — never access them after the closing `}`.
2. Inner scopes can access outer scope variables, but not vice versa.
3. Global variables should be avoided in favor of local variables and parameters.
4. Use namespaces to organize code and prevent naming conflicts.
5. The `::` operator lets you access global or namespace members explicitly.
6. Variable shadowing is a common source of bugs — enable `-Wshadow` to catch it.
7. Static local variables keep their value between function calls but remain locally scoped.
8. Always declare variables in the smallest scope necessary — this is a best practice.

### Quick Reference

```cpp
// Local scope
{
    int x = 10; // exists only inside these braces
}

// Global scope
int g = 100; // outside all functions

// Namespace scope
namespace NS {
    int val = 5;
}
// Access: NS::val

// Static local
void f() {
    static int count = 0; // retains value between calls
    count++;
}

// Scope resolution
int x = 1;        // global
int main() {
    int x = 2;    // local
    ::x;           // accesses global x
}
```

### Next Steps

In the next lecture, we will explore **References and Pointers** — how to create aliases to variables and directly manipulate memory addresses, building on the scope concepts learned here.
