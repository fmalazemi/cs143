# Lecture 12: Scope in C++

## Table of Contents

1. [Introduction to Scope](#introduction-to-scope)
2. [What is Scope?](#what-is-scope)
3. [Types of Scope](#types-of-scope)
   - [Local Scope](#local-scope)
   - [Global Scope](#global-scope)
   - [Block Scope](#block-scope)
   - [Function Scope](#function-scope)
4. [Variable Lifetime](#variable-lifetime)
5. [Scope Resolution](#scope-resolution)
6. [Shadowing](#shadowing)
7. [Best Practices](#best-practices)
8. [Common Mistakes](#common-mistakes)
9. [Practice Exercises](#practice-exercises)
10. [Summary](#summary)

---

## Introduction to Scope

**Scope** determines where in your program a variable can be accessed and used. It defines the visibility and lifetime of variables, controlling which parts of your code can see and modify them.

Understanding scope is crucial because:
- Prevents naming conflicts between variables
- Controls data access and encapsulation
- Manages memory efficiently
- Makes code more maintainable and bug-free

### Real-World Analogies

**Office Building Access**
- Local variables are like your personal desk items - only you can access them in your office
- Global variables are like the company bulletin board - everyone in the building can see and modify it
- Block scope is like a conference room - only people inside that room can access items there

**TV Remote Control**
- The remote works only in the room where you are (local scope)
- The main power switch affects the whole house (global scope)
- Each room has its own lights controlled locally (block scope)

**Restaurant Kitchen**
- Each chef's station has local tools (local scope)
- The main pantry is accessible to all chefs (global scope)
- Prep tables have their own workspace (block scope)

---

## What is Scope?

Scope refers to the region of code where a variable is visible and can be accessed. Once a variable goes out of scope, it can no longer be used and its memory is deallocated.

### Basic Scope Rules

1. Variables declared inside a function are **local** to that function
2. Variables declared outside all functions are **global**
3. Variables declared inside blocks `{ }` are **local** to that block
4. Inner scopes can access outer scope variables
5. Outer scopes **cannot** access inner scope variables

### Simple Example

```cpp
#include <iostream>
using namespace std;

int globalVar = 100;  // Global scope

int main() {
    int localVar = 50;  // Local to main
    
    cout << "Global: " << globalVar << endl;  // Can access
    cout << "Local: " << localVar << endl;    // Can access
    
    return 0;
}
```

**Output:**
```
Global: 100
Local: 50
```

---

## Types of Scope

### Local Scope

Variables declared inside a function have **local scope**. They exist only within that function and are destroyed when the function ends.

```cpp
#include <iostream>
using namespace std;

void myFunction() {
    int x = 10;  // Local to myFunction
    cout << "Inside function: x = " << x << endl;
}

int main() {
    myFunction();
    // cout << x;  // ERROR: x is not accessible here
    
    return 0;
}
```

**Output:**
```
Inside function: x = 10
```

#### Multiple Functions with Same Variable Names

```cpp
#include <iostream>
using namespace std;

void functionA() {
    int value = 100;
    cout << "Function A: " << value << endl;
}

void functionB() {
    int value = 200;  // Different variable, same name
    cout << "Function B: " << value << endl;
}

int main() {
    functionA();
    functionB();
    
    return 0;
}
```

**Output:**
```
Function A: 100
Function B: 200
```

**Important:** These are two completely separate variables that happen to share the same name.

#### Variable Lifetime Example

```cpp
#include <iostream>
using namespace std;

void counter() {
    int count = 0;  // Created each time function is called
    count++;
    cout << "Count: " << count << endl;
}

int main() {
    counter();  // count is 1
    counter();  // count is 1 again (new variable)
    counter();  // count is 1 again (new variable)
    
    return 0;
}
```

**Output:**
```
Count: 1
Count: 1
Count: 1
```

Each call to `counter()` creates a new `count` variable that starts at 0.

### Global Scope

Variables declared outside all functions have **global scope**. They can be accessed from any function in the program.

```cpp
#include <iostream>
using namespace std;

int globalCounter = 0;  // Global variable

void increment() {
    globalCounter++;
}

void display() {
    cout << "Global counter: " << globalCounter << endl;
}

int main() {
    display();      // 0
    increment();
    display();      // 1
    increment();
    display();      // 2
    
    return 0;
}
```

**Output:**
```
Global counter: 0
Global counter: 1
Global counter: 2
```

#### Global vs Local Variables

```cpp
#include <iostream>
using namespace std;

int x = 100;  // Global x

void printValues() {
    int x = 50;  // Local x (shadows global x)
    cout << "Local x: " << x << endl;
    cout << "Global x: " << ::x << endl;  // Access global using ::
}

int main() {
    printValues();
    cout << "Main x: " << x << endl;  // Global x
    
    return 0;
}
```

**Output:**
```
Local x: 50
Global x: 100
Main x: 100
```

### Block Scope

Variables declared inside any block `{ }` have **block scope**. They exist only within that block.

```cpp
#include <iostream>
using namespace std;

int main() {
    int outer = 10;
    
    {  // New block
        int inner = 20;
        cout << "Outer: " << outer << endl;  // Can access
        cout << "Inner: " << inner << endl;  // Can access
    }  // inner is destroyed here
    
    cout << "Outer: " << outer << endl;  // Can access
    // cout << inner;  // ERROR: inner is out of scope
    
    return 0;
}
```

**Output:**
```
Outer: 10
Inner: 20
Outer: 10
```

#### Block Scope in Loops

```cpp
#include <iostream>
using namespace std;

int main() {
    for (int i = 0; i < 3; i++) {
        int loopVar = i * 10;
        cout << "i = " << i << ", loopVar = " << loopVar << endl;
    }
    
    // cout << i;        // ERROR: i is out of scope
    // cout << loopVar;  // ERROR: loopVar is out of scope
    
    return 0;
}
```

**Output:**
```
i = 0, loopVar = 0
i = 1, loopVar = 10
i = 2, loopVar = 20
```

#### Block Scope in If Statements

```cpp
#include <iostream>
using namespace std;

int main() {
    int score = 85;
    
    if (score >= 80) {
        string grade = "A";  // Local to if block
        cout << "Grade: " << grade << endl;
    }
    
    // cout << grade;  // ERROR: grade is out of scope
    
    return 0;
}
```

**Output:**
```
Grade: A
```

### Function Scope

Function parameters have **function scope** - they act like local variables within the function.

```cpp
#include <iostream>
using namespace std;

void greet(string name) {  // name has function scope
    cout << "Hello, " << name << endl;
}

int main() {
    greet("Alice");
    greet("Bob");
    // cout << name;  // ERROR: name is not accessible here
    
    return 0;
}
```

**Output:**
```
Hello, Alice
Hello, Bob
```

#### Multiple Parameters

```cpp
#include <iostream>
using namespace std;

int calculate(int a, int b, int c) {
    // a, b, c all have function scope
    int result = a + b * c;  // result has function scope
    return result;
}

int main() {
    int answer = calculate(5, 10, 2);
    cout << "Answer: " << answer << endl;
    
    // cout << a;       // ERROR: a is out of scope
    // cout << result;  // ERROR: result is out of scope
    
    return 0;
}
```

**Output:**
```
Answer: 25
```

---

## Variable Lifetime

**Lifetime** is how long a variable exists in memory during program execution.

### Automatic Variables (Local)

Created when entering scope, destroyed when leaving scope.

```cpp
#include <iostream>
using namespace std;

void demonstrateLifetime() {
    cout << "Entering function" << endl;
    
    int x = 10;  // x is created here
    cout << "x = " << x << endl;
    
    cout << "Leaving function" << endl;
}  // x is destroyed here

int main() {
    demonstrateLifetime();
    demonstrateLifetime();  // x is created again
    
    return 0;
}
```

**Output:**
```
Entering function
x = 10
Leaving function
Entering function
x = 10
Leaving function
```

### Static Variables

Retain their value between function calls.

```cpp
#include <iostream>
using namespace std;

void counter() {
    static int count = 0;  // Initialized only once
    count++;
    cout << "Count: " << count << endl;
}

int main() {
    counter();  // count = 1
    counter();  // count = 2
    counter();  // count = 3
    
    return 0;
}
```

**Output:**
```
Count: 1
Count: 2
Count: 3
```

**Key Difference:** Static variables maintain their value across function calls.

### Global Variables

Exist for the entire program execution.

```cpp
#include <iostream>
using namespace std;

int globalVar = 100;  // Created at program start

void modify() {
    globalVar += 10;
}

int main() {
    cout << "Initial: " << globalVar << endl;
    modify();
    cout << "After modify: " << globalVar << endl;
    
    return 0;
}  // globalVar destroyed at program end
```

**Output:**
```
Initial: 100
After modify: 110
```

---

## Scope Resolution

The **scope resolution operator** `::` allows you to access global variables when they're shadowed by local variables.

### Accessing Global Variables

```cpp
#include <iostream>
using namespace std;

int value = 100;  // Global

int main() {
    int value = 50;  // Local (shadows global)
    
    cout << "Local value: " << value << endl;
    cout << "Global value: " << ::value << endl;
    
    return 0;
}
```

**Output:**
```
Local value: 50
Global value: 100
```

### Modifying Global Variables

```cpp
#include <iostream>
using namespace std;

int counter = 0;  // Global

void incrementLocal() {
    int counter = 10;  // Local
    counter++;         // Increments local
    cout << "Local: " << counter << endl;
}

void incrementGlobal() {
    ::counter++;       // Increments global using ::
    cout << "Global: " << ::counter << endl;
}

int main() {
    incrementLocal();
    incrementGlobal();
    incrementLocal();
    incrementGlobal();
    
    return 0;
}
```

**Output:**
```
Local: 11
Global: 1
Local: 11
Global: 2
```

---

## Shadowing

**Shadowing** occurs when a local variable has the same name as a variable in an outer scope, hiding the outer variable.

### Variable Shadowing Example

```cpp
#include <iostream>
using namespace std;

int x = 100;  // Global x

int main() {
    cout << "Global x: " << x << endl;
    
    {
        int x = 50;  // Shadows global x
        cout << "Block x: " << x << endl;
        
        {
            int x = 25;  // Shadows previous x
            cout << "Inner block x: " << x << endl;
        }
        
        cout << "Block x again: " << x << endl;
    }
    
    cout << "Global x again: " << x << endl;
    
    return 0;
}
```

**Output:**
```
Global x: 100
Block x: 50
Inner block x: 25
Block x again: 50
Global x again: 100
```

### Shadowing in Loops

```cpp
#include <iostream>
using namespace std;

int main() {
    int i = 999;  // Outer i
    
    cout << "Before loop: i = " << i << endl;
    
    for (int i = 0; i < 3; i++) {  // Shadows outer i
        cout << "Loop i = " << i << endl;
    }
    
    cout << "After loop: i = " << i << endl;
    
    return 0;
}
```

**Output:**
```
Before loop: i = 999
Loop i = 0
Loop i = 1
Loop i = 2
After loop: i = 999
```

### Avoiding Shadowing Problems

```cpp
#include <iostream>
using namespace std;

int total = 0;  // Global

void calculateTotal(int values[], int size) {
    int total = 0;  // Local (shadows global)
    
    for (int i = 0; i < size; i++) {
        total += values[i];  // Affects local total
    }
    
    cout << "Local total: " << total << endl;
    cout << "Global total: " << ::total << endl;
}

int main() {
    int numbers[] = {10, 20, 30};
    calculateTotal(numbers, 3);
    
    return 0;
}
```

**Output:**
```
Local total: 60
Global total: 0
```

---

## Best Practices

### 1. Minimize Global Variables

**Bad Practice:**
```cpp
int x, y, z, result;  // All global

void calculate() {
    result = x + y + z;
}

int main() {
    x = 10;
    y = 20;
    z = 30;
    calculate();
    cout << result << endl;
    return 0;
}
```

**Good Practice:**
```cpp
int calculate(int x, int y, int z) {
    return x + y + z;
}

int main() {
    int x = 10, y = 20, z = 30;
    int result = calculate(x, y, z);
    cout << result << endl;
    return 0;
}
```

### 2. Declare Variables in Narrowest Scope

**Bad Practice:**
```cpp
int main() {
    int i, j, k, sum;  // Declared too early
    
    // ... lots of code ...
    
    sum = 0;
    for (i = 0; i < 10; i++) {
        sum += i;
    }
    
    return 0;
}
```

**Good Practice:**
```cpp
int main() {
    // ... other code ...
    
    int sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += i;
    }
    
    return 0;
}
```

### 3. Avoid Shadowing

**Bad Practice:**
```cpp
int count = 0;  // Global

void process() {
    int count = 10;  // Shadows global - confusing
    count++;
}
```

**Good Practice:**
```cpp
int globalCount = 0;  // Clear name

void process() {
    int localCount = 10;  // Different name - clear
    localCount++;
}
```

### 4. Use Meaningful Names

**Bad Practice:**
```cpp
int x;  // Global x
void func() {
    int x;  // Local x - confusing
}
```

**Good Practice:**
```cpp
int totalScore;  // Global
void calculateBonus() {
    int bonusPoints;  // Local - different name
}
```

### 5. Initialize Variables at Declaration

**Bad Practice:**
```cpp
int main() {
    int x;
    
    // ... code ...
    
    x = 10;  // Initialized far from declaration
    return 0;
}
```

**Good Practice:**
```cpp
int main() {
    // ... code ...
    
    int x = 10;  // Initialized immediately
    return 0;
}
```

---

## Common Mistakes

### Mistake 1: Accessing Out-of-Scope Variables

**Wrong:**
```cpp
#include <iostream>
using namespace std;

void myFunction() {
    int localVar = 100;
}

int main() {
    cout << localVar << endl;  // ERROR: localVar not accessible
    return 0;
}
```

**Correct:**
```cpp
#include <iostream>
using namespace std;

int myFunction() {
    int localVar = 100;
    return localVar;
}

int main() {
    int value = myFunction();
    cout << value << endl;
    return 0;
}
```

**Explanation:** Variables are only accessible within their scope. Use return values or parameters to pass data between scopes.

### Mistake 2: Forgetting Variable Initialization in Narrow Scopes

**Wrong:**
```cpp
#include <iostream>
using namespace std;

int main() {
    if (true) {
        int x;  // Not initialized
        x++;    // Undefined behavior
        cout << x << endl;
    }
    return 0;
}
```

**Correct:**
```cpp
#include <iostream>
using namespace std;

int main() {
    if (true) {
        int x = 0;  // Properly initialized
        x++;
        cout << x << endl;
    }
    return 0;
}
```

**Explanation:** Always initialize variables when declaring them to avoid undefined behavior.

### Mistake 3: Unintended Shadowing

**Wrong:**
```cpp
#include <iostream>
using namespace std;

int total = 100;  // Global

void calculate() {
    int total = 0;  // Accidentally shadows global
    total = 50;     // Modifies local, not global
}

int main() {
    calculate();
    cout << total << endl;  // Still 100, not 50
    return 0;
}
```

**Correct:**
```cpp
#include <iostream>
using namespace std;

int total = 100;  // Global

void calculate() {
    total = 50;  // Modifies global
}

int main() {
    calculate();
    cout << total << endl;  // Now 50
    return 0;
}
```

**Explanation:** Be careful with variable names. Use `::` to access global variables if needed, or avoid shadowing entirely.

### Mistake 4: Assuming Variables Persist Across Function Calls

**Wrong:**
```cpp
#include <iostream>
using namespace std;

void counter() {
    int count = 0;  // Reset every call
    count++;
    cout << count << endl;
}

int main() {
    counter();  // Prints 1
    counter();  // Prints 1 (not 2)
    counter();  // Prints 1 (not 3)
    return 0;
}
```

**Correct:**
```cpp
#include <iostream>
using namespace std;

void counter() {
    static int count = 0;  // Persists across calls
    count++;
    cout << count << endl;
}

int main() {
    counter();  // Prints 1
    counter();  // Prints 2
    counter();  // Prints 3
    return 0;
}
```

**Explanation:** Use `static` keyword if you want a local variable to retain its value across function calls.

### Mistake 5: Overusing Global Variables

**Wrong:**
```cpp
#include <iostream>
using namespace std;

int a, b, c, result;  // Everything global

void add() {
    result = a + b;
}

void multiply() {
    result = result * c;
}

int main() {
    a = 5;
    b = 10;
    c = 2;
    add();
    multiply();
    cout << result << endl;
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

int multiply(int x, int y) {
    return x * y;
}

int main() {
    int a = 5, b = 10, c = 2;
    int result = add(a, b);
    result = multiply(result, c);
    cout << result << endl;
    return 0;
}
```

**Explanation:** Use parameters and return values instead of global variables for better code organization and fewer bugs.

---

## Practice Exercises

### Exercise 1: Scope Analysis

Predict the output of this program:

```cpp
#include <iostream>
using namespace std;

int x = 10;

void test() {
    int x = 20;
    cout << x << endl;
}

int main() {
    cout << x << endl;
    test();
    cout << x << endl;
    return 0;
}
```

<details>
<summary>Click to see solution</summary>

**Output:**
```
10
20
10
```

**Explanation:**
- First `cout` prints global `x` (10)
- `test()` creates local `x` (20) and prints it
- Final `cout` prints global `x` again (10)
</details>

---

### Exercise 2: Fix the Scope Error

Fix this program so it compiles and runs correctly:

```cpp
#include <iostream>
using namespace std;

void calculate() {
    int result = 100;
}

int main() {
    calculate();
    cout << result << endl;  // Error: result not in scope
    return 0;
}
```

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int calculate() {
    int result = 100;
    return result;
}

int main() {
    int result = calculate();
    cout << result << endl;
    return 0;
}
```

**Explanation:** Changed `calculate()` to return the result, then stored it in a variable in `main()`.
</details>

---

### Exercise 3: Static Counter

Write a function `getId()` that returns a unique ID number each time it's called, starting from 1.

**Expected output:**
```
ID: 1
ID: 2
ID: 3
```

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int getId() {
    static int id = 0;
    id++;
    return id;
}

int main() {
    cout << "ID: " << getId() << endl;
    cout << "ID: " << getId() << endl;
    cout << "ID: " << getId() << endl;
    
    return 0;
}
```

**Explanation:** The `static` keyword makes `id` persist across function calls, incrementing each time.
</details>

---

### Exercise 4: Scope Resolution

Write a program with a global variable `temperature` set to 25. Inside `main()`, create a local variable `temperature` set to 30. Print both values using the scope resolution operator.

**Expected output:**
```
Local temperature: 30
Global temperature: 25
```

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int temperature = 25;  // Global

int main() {
    int temperature = 30;  // Local
    
    cout << "Local temperature: " << temperature << endl;
    cout << "Global temperature: " << ::temperature << endl;
    
    return 0;
}
```

**Explanation:** The `::` operator accesses the global `temperature` variable.
</details>

---

### Exercise 5: Block Scope Challenge

What is the output of this program?

```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 10;
    
    {
        int x = 20;
        {
            int x = 30;
            cout << x << " ";
        }
        cout << x << " ";
    }
    cout << x << endl;
    
    return 0;
}
```

<details>
<summary>Click to see solution</summary>

**Output:**
```
30 20 10
```

**Explanation:**
- Innermost block prints `x = 30`
- Middle block prints `x = 20`
- Outer scope prints `x = 10`

Each scope has its own `x` variable shadowing the outer ones.
</details>

---

## Summary

### Key Concepts

- **Scope** determines where variables can be accessed
- **Local scope** - variables inside functions or blocks
- **Global scope** - variables outside all functions
- **Block scope** - variables inside `{ }` blocks
- **Lifetime** - how long a variable exists in memory
- **Shadowing** - local variables hiding outer scope variables
- **Scope resolution operator** `::` - access global variables
- **Static variables** - persist across function calls

### Important Points

1. Variables are only accessible within their scope
2. Inner scopes can access outer scope variables
3. Outer scopes cannot access inner scope variables
4. Local variables are destroyed when leaving scope
5. Global variables exist for entire program execution
6. Minimize use of global variables for better code quality
7. Declare variables in the narrowest scope possible
8. Avoid shadowing to prevent confusion
9. Use meaningful variable names to differentiate scopes
10. Initialize variables at declaration

### Quick Reference

```cpp
// Global scope
int globalVar = 100;

// Scope resolution
::globalVar  // Access global variable

// Static variable
static int count = 0;  // Persists across calls

// Local scope
void function() {
    int localVar = 50;  // Only accessible in function
}

// Block scope
{
    int blockVar = 25;  // Only accessible in block
}

// Function parameters
void func(int param) {  // param has function scope
    // ...
}
```

### Scope Rules Summary

| Scope Type | Declaration Location | Accessible From | Lifetime |
|------------|---------------------|-----------------|----------|
| Global | Outside all functions | Entire program | Program duration |
| Local | Inside function | That function only | Function execution |
| Block | Inside `{ }` | That block only | Block execution |
| Static Local | Inside function with `static` | That function only | Program duration |

### Best Practices Checklist

- ✅ Use local variables whenever possible
- ✅ Minimize global variables
- ✅ Declare variables in narrowest scope
- ✅ Initialize variables at declaration
- ✅ Use meaningful variable names
- ✅ Avoid shadowing
- ✅ Use `::` when accessing shadowed globals
- ✅ Use `static` for persistent local variables
- ✅ Pass data via parameters and return values
- ✅ Keep related data together in scope

---

## Next Steps

In the next lecture, you will learn about:
- Pointers and memory addresses
- Dynamic memory allocation
- References vs pointers
- Pointer arithmetic

---

**Understanding scope is fundamental to writing clean, maintainable C++ code. Master these concepts to avoid common bugs and write better programs!**
