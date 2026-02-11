# Lecture 1: Getting Started with C++ 🚀

## Welcome to C++!

Hey there! You've already got the basics down with Python - variables, loops, and conditionals. That's awesome! Now we're going to learn C++, which is like Python's high-performance cousin. 

Think of it this way: Python is like an automatic car (easy to drive, does a lot for you), while C++ is like a manual transmission sports car (more control, way more power, but you need to know what you're doing).

C++ is used to build:
- 🎮 Video games (Unreal Engine, Unity core)
- 🖥️ Operating systems (Windows, macOS, Linux)
- 🚗 Self-driving cars
- 🚀 SpaceX rocket software
- ⚡ High-frequency trading systems

Pretty cool, right?

---

## Python vs C++: The Main Differences

Don't worry, it's not completely different! Here's what changes:

| Python | C++ |
|--------|-----|
| Runs line by line (interpreted) | Compiles first, then runs (faster!) |
| Types are flexible: `x = 5` then `x = "hi"` works | Types are fixed: declare once, can't change |
| Automatic | You're in control |
| Great for learning & prototyping | Great for speed & performance |

**The good news:** All your programming logic (loops, conditionals, variables) transfers over! You just need to learn the new syntax.

---

## Part 1: Your First C++ Program! 👋

Let's start with the classic "Hello, World!" program.

### Python Version (What You Know)
```python
print("Hello, World!")
```

One line, super simple!

### C++ Version (New!)
```cpp
#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
```

Okay, that's more lines... but don't panic! Let's break it down piece by piece.

---

## Understanding Each Line

```cpp
#include <iostream>
```
**What it does:** Brings in the tools we need for input/output  
**Like Python's:** `import` statement  
**Why we need it:** To use `cout` (console output) and `cin` (console input)  
**Think of it as:** Importing a toolbox before starting work

---

```cpp
int main() {
```
**What it does:** This is where your program starts running  
**Why `int`:** The function will return a number (0 = success!)  
**The `{`:** Starts the code block (Python uses indentation, C++ uses braces)  
**Important:** Every C++ program MUST have a `main()` function

---

```cpp
    std::cout << "Hello, World!" << std::endl;
```
**What it does:** Prints to the screen  
**Like Python's:** `print("Hello, World!")`  
**Breaking it down:**
- `std::cout` = **c**onsole **out**put (the screen)
- `<<` = "send this to cout" (output operator)
- `"Hello, World!"` = the text to print
- `std::endl` = **end line** (like pressing Enter)
- `;` = **every statement ends with a semicolon!** (Don't forget this!)

---

```cpp
    return 0;
```
**What it does:** Tells the computer "we finished successfully!"  
**The `0`:** Means "no errors" (non-zero means something went wrong)

---

```cpp
}
```
**What it does:** Closes the `main()` function  
**Important:** Every `{` needs a matching `}`

---

## Let's Write More Programs!

### Printing Multiple Lines

**Python:**
```python
print("Hello")
print("World")
print("I love programming!")
```

**C++:**
```cpp
#include <iostream>

int main() {
    std::cout << "Hello" << std::endl;
    std::cout << "World" << std::endl;
    std::cout << "I love programming!" << std::endl;
    return 0;
}
```

### Printing Multiple Things in One Line

**Python:**
```python
age = 25
print("My age is", age)
```

**C++:**
```cpp
#include <iostream>

int main() {
    int age = 25;
    std::cout << "My age is " << age << std::endl;
    return 0;
}
```

**Cool trick:** You can chain outputs with `<<`!

```cpp
std::cout << "I am " << 25 << " years old and I love " << "C++" << std::endl;
```

### Quick Tip: `\n` vs `std::endl`

Both add a new line, but `\n` is slightly faster:

```cpp
std::cout << "Hello\n";        // Faster
std::cout << "Hello" << std::endl;  // More readable
```

For now, use whichever you prefer!

---

## How to Actually Run Your Program 🏃

### Python (One Step)
```bash
python hello.py
```
Easy! Just run it.

### C++ (Two Steps)
```bash
# Step 1: Compile (turn your code into an executable program)
g++ hello.cpp -o hello

# Step 2: Run the program
./hello
```

**What's happening?**
1. **Compile:** The compiler (`g++`) reads your C++ code and turns it into machine code (0s and 1s the computer understands)
2. **Run:** You execute the compiled program

**Why two steps?**
- ✅ Catches errors BEFORE running (safer!)
- ✅ Runs MUCH faster (10-100x faster than Python)
- ✅ You only compile once, then run many times

**Think of it like:** Baking a cake. First you prepare it (compile), then you can eat it multiple times (run).

---

## Part 2: Variables - Storing Information 📦

Remember variables from Python? C++ has them too, but with one big difference: **you must declare the type**.

### Python Way (Dynamic Typing)
```python
x = 5           # Python: "Ah, that's an integer!"
x = "hello"     # Python: "Now it's a string! No problem!"
y = 3.14        # Python: "A decimal number!"
```

Python figures out types automatically and lets them change.

### C++ Way (Static Typing)
```cpp
int x = 5;         // x is an integer FOREVER
x = 10;            // OK: still an integer
x = "hello";       // ERROR! Can't change types

double y = 3.14;   // y is a double FOREVER
```

**Once you pick a type, you're stuck with it!** This might seem annoying at first, but it helps catch bugs early and makes your program faster.

---

## Data Types You Need to Know

| Type | What it stores | Examples | Memory Size |
|------|---------------|----------|-------------|
| `int` | Whole numbers | `42`, `-10`, `0` | 4 bytes |
| `double` | Decimal numbers | `3.14`, `-0.5`, `2.0` | 8 bytes |
| `float` | Decimals (less precise) | `3.14f` | 4 bytes |
| `char` | Single character | `'A'`, `'x'`, `'5'` | 1 byte |
| `bool` | True or false | `true`, `false` | 1 byte |
| `std::string` | Text (words/sentences) | `"Hello"` | varies |

### Let's Create Some Variables!

```cpp
#include <iostream>
#include <string>  // Need this for std::string!

int main() {
    // Whole numbers
    int age = 20;
    int score = -5;
    
    // Decimal numbers
    double pi = 3.14159;
    double price = 29.99;
    
    // Single characters (use SINGLE quotes!)
    char grade = 'A';
    char initial = 'J';
    
    // True or false (lowercase!)
    bool is_student = true;
    bool likes_pizza = false;
    
    // Text strings (use DOUBLE quotes!)
    std::string name = "Alice";
    std::string message = "Hello, World!";
    
    return 0;
}
```

**Important Notes:**
- Single character? Use **single quotes**: `'A'`
- Text string? Use **double quotes**: `"Hello"`
- Booleans are **lowercase**: `true` and `false` (not `True`/`False`)

---

## Creating Variables: The Right Way

### Option 1: Declare and Initialize Together (Best!)
```cpp
int x = 5;          // Create x and give it value 5
double pi = 3.14;   // Create pi and give it value 3.14
```

### Option 2: Declare First, Assign Later
```cpp
int x;              // Create x (but it has a random value!)
x = 5;              // Now give it a value

double y;           // Create y (random value!)
y = 3.14;           // Now assign 3.14
```

**⚠️ Warning:** If you declare without initializing, the variable has a random garbage value! Always initialize your variables!

### Option 3: Declare Multiple Variables
```cpp
int a = 5, b = 10, c = 15;  // Three integers at once
double x = 1.5, y = 2.5;    // Two doubles
```

---

## Important Rules! ⚠️

### Rule 1: Declare the Type First
```cpp
x = 5;              // ❌ ERROR: What type is x?
int x = 5;          // ✅ Correct: x is an int
```

### Rule 2: Type Never Changes
```cpp
int x = 5;
x = 10;             // ✅ OK: both are integers
x = 3.14;           // ⚠️ OK but becomes 3 (loses decimal!)
x = "hello";        // ❌ ERROR: can't change to string
```

### Rule 3: Quotes Matter!
```cpp
char letter = 'A';           // ✅ Correct: single quotes
char letter = "A";           // ❌ ERROR: that's a string!

std::string word = "Hi";     // ✅ Correct: double quotes
std::string word = 'Hi';     // ❌ ERROR: that's not how this works
```

### Rule 4: Case Sensitivity
```cpp
int age = 20;
int Age = 30;       // Different variable! (capital A)
int AGE = 40;       // Another different variable!
```

C++ cares about uppercase vs lowercase!

---

## Part 3: Getting Input from the User 🎤

In Python, you used `input()`. In C++, we use `cin` (console input).

### Python Way
```python
name = input("What's your name? ")
age = int(input("How old are you? "))
print(f"Hi {name}, you're {age} years old!")
```

### C++ Way
```cpp
#include <iostream>
#include <string>

int main() {
    std::string name;
    int age;
    
    std::cout << "What's your name? ";
    std::cin >> name;
    
    std::cout << "How old are you? ";
    std::cin >> age;
    
    std::cout << "Hi " << name << ", you're " << age << " years old!" << std::endl;
    
    return 0;
}
```

**Key differences:**
- `std::cin >>` reads input (like `input()`)
- Notice the `>>` arrows point from `cin` toward the variable
- `std::cout <<` sends output (like `print()`)
- The `<<` arrows point from data toward `cout`

**Think of it like:**
- `cin >>` = data flows INTO your variable
- `cout <<` = data flows OUT to the screen

---

## Cin and Cout Examples

### Reading Different Types

```cpp
#include <iostream>
#include <string>

int main() {
    int number;
    double price;
    char grade;
    std::string word;
    
    std::cout << "Enter a number: ";
    std::cin >> number;
    
    std::cout << "Enter a price: ";
    std::cin >> price;
    
    std::cout << "Enter a grade: ";
    std::cin >> grade;
    
    std::cout << "Enter a word: ";
    std::cin >> word;
    
    std::cout << "You entered: " << number << ", " << price 
              << ", " << grade << ", " << word << std::endl;
    
    return 0;
}
```

**Magic:** `cin` automatically converts the input to the right type! If you ask for an `int`, it reads an integer. If you ask for a `double`, it reads a decimal.

### Reading Multiple Values at Once

```cpp
int a, b, c;
std::cout << "Enter three numbers: ";
std::cin >> a >> b >> c;  // Read all three!

std::cout << "Sum: " << (a + b + c) << std::endl;
```

**Input:** `5 10 15`  
**Output:** `Sum: 30`

---

## The Magic `auto` Keyword ✨

**Good news!** You don't ALWAYS have to write the type explicitly. C++ can figure it out!

### Without auto (explicit type)
```cpp
int x = 5;
double y = 3.14;
std::string name = "Alice";
```

### With auto (compiler figures it out)
```cpp
auto x = 5;              // Compiler knows: int
auto y = 3.14;           // Compiler knows: double
auto name = std::string("Alice");  // string
```

The compiler looks at the right side and says "Ah, that must be an int!" or "That's a double!"

---

## When to Use Auto

### ✅ Good Uses of Auto

```cpp
auto score = 100;              // Obviously an int
auto price = 29.99;            // Obviously a double
auto is_ready = true;          // Obviously a bool
auto message = std::string("Hi");  // Explicitly a string
```

### ⚠️ Be Careful With Auto

For strings, you need to be explicit:
```cpp
auto name = std::string("Alice");  // ✅ This works!

// OR just use explicit type:
std::string name = "Alice";        // ✅ Better for beginners
```

### 🎯 When Should You Use Auto?

**Use `auto` when:**
- The type is super obvious from the value
- You want cleaner, shorter code
- You're feeling confident!

**Use explicit types when:**
- You're learning (helps you remember the types!)
- You want your code to be crystal clear
- The type isn't obvious

**My recommendation:** Start with explicit types (`int`, `double`, etc.) until you're comfortable. Then start using `auto` for convenience!

---

## Auto Practice

```cpp
#include <iostream>
#include <string>

int main() {
    // Explicit types (clear and educational)
    int age = 20;
    double height = 5.9;
    std::string name = "Bob";
    
    // Same thing with auto
    auto age2 = 20;           // int
    auto height2 = 5.9;       // double
    auto name2 = std::string("Bob");  // string
    
    std::cout << "Age: " << age << std::endl;
    std::cout << "Height: " << height << std::endl;
    std::cout << "Name: " << name << std::endl;
    
    return 0;
}
```

Both ways work! Use whichever feels more comfortable.

---

## Constants: Values That Never Change 🔒

Sometimes you want a variable that NEVER changes (like π, or the number of days in a week).

### Python Way
```python
PI = 3.14159  # Convention: ALL CAPS (but can still be changed)
PI = 3.14     # Oops, I changed it!
```

### C++ Way
```cpp
const double PI = 3.14159;  // Cannot be changed!
PI = 3.14;                  // ❌ ERROR: Can't modify a constant!
```

The `const` keyword makes it **read-only**. Try to change it and the compiler yells at you!

### When to Use Constants

```cpp
const int DAYS_IN_WEEK = 7;
const double GRAVITY = 9.81;
const int MAX_PLAYERS = 4;
const std::string GAME_TITLE = "Super Adventure";
```

**Benefits:**
- Can't accidentally change important values
- Makes your code more readable
- Helps prevent bugs

---

## Math Operations (Just Like Python!) ➕➖✖️➗

Good news: arithmetic works almost exactly the same!

```cpp
int a = 10;
int b = 3;

int sum = a + b;        // 13 (addition)
int diff = a - b;       // 7 (subtraction)
int product = a * b;    // 30 (multiplication)
int quotient = a / b;   // 3 (integer division - careful!)
int remainder = a % b;  // 1 (modulo - the remainder)
```

### ⚠️ Watch Out: Integer Division!

```cpp
int result = 7 / 2;     // Result is 3, NOT 3.5!
```

When you divide two integers, you get an integer (decimal part is thrown away).

**To get decimals:**
```cpp
double result = 7.0 / 2.0;  // Result is 3.5 ✅
double result = 7 / 2;      // Still 3 ❌ (integers divided first)
```

### Math Shortcuts

```cpp
int x = 10;

x = x + 5;      // Long way
x += 5;         // Short way (same thing!)

x = x - 3;      // Long way
x -= 3;         // Short way

x = x * 2;      // Long way
x *= 2;         // Short way

x = x / 2;      // Long way
x /= 2;         // Short way
```

### Increment and Decrement

```cpp
int count = 5;

count = count + 1;      // Long way
count += 1;             // Medium way
count++;                // Short way! (very common)

count = count - 1;      // Long way
count -= 1;             // Medium way
count--;                // Short way!
```

You'll see `count++` and `count--` ALL THE TIME in C++!

---

## Type Conversion: Changing Types 🔄

Sometimes you need to convert one type to another.

### Automatic Conversion (Safe)
```cpp
int x = 5;
double y = x;       // int → double (no data lost)
std::cout << y;     // Prints: 5.0
```

Going from smaller to larger type is safe!

### Manual Conversion (Be Careful!)
```cpp
double pi = 3.14159;
int rounded = static_cast<int>(pi);  // Modern C++ way (best!)

std::cout << rounded;     // Prints: 3 (decimal lost!)
```

**Warning:** Converting `double` to `int` throws away the decimal part!

### Conversion Examples

```cpp
#include <iostream>

int main() {
    // Safe conversion (small → big)
    int small = 100;
    double big = small;
    std::cout << big << std::endl;  // 100.0
    
    // Lossy conversion (big → small)
    double pi = 3.14159;
    int truncated = static_cast<int>(pi);
    std::cout << truncated << std::endl;  // 3 (lost .14159!)
    
    return 0;
}
```




---

## Constants

Sometimes you want a variable that never changes:

### Python
```python
PI = 3.14159  # Convention: all caps, but can still be changed
```

### C++
```cpp
const double PI = 3.14159;  // Cannot be changed!
PI = 3.14;  // ERROR: assignment of read-only variable
```

**Use `const` for:**
- Mathematical constants
- Configuration values that shouldn't change
- Making your code safer

---

## Arithmetic Operations

All the same as Python!

```cpp
int a = 10;
int b = 3;

int sum = a + b;        // 13
int diff = a - b;       // 7
int product = a * b;    // 30
int quotient = a / b;   // 3 (integer division!)
int remainder = a % b;  // 1 (modulo)

double x = 10.0;
double y = 3.0;
double division = x / y;  // 3.333... (floating-point division)
```

**Important:** Integer division truncates!
```cpp
int result = 7 / 2;     // 2, not 3.5!
double result = 7.0 / 2.0;  // 3.5
```

---

## Let's Practice! 💪

### Problem 1: All About You
Write a program that:
1. Asks for your name, age, and favorite number
2. Prints all the information back

**Expected Output:**
```
What's your name? Alice
How old are you? 20
What's your favorite number? 7

Nice to meet you, Alice!
You are 20 years old.
Your favorite number is 7.
```

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
#include <string>

int main() {
    std::string name;
    int age;
    int favorite_number;
    
    std::cout << "What's your name? ";
    std::cin >> name;
    
    std::cout << "How old are you? ";
    std::cin >> age;
    
    std::cout << "What's your favorite number? ";
    std::cin >> favorite_number;
    
    std::cout << "\nNice to meet you, " << name << "!" << std::endl;
    std::cout << "You are " << age << " years old." << std::endl;
    std::cout << "Your favorite number is " << favorite_number << "." << std::endl;
    
    return 0;
}
```
</details>

---

### Problem 2: Simple Calculator
Write a program that:
1. Asks for two numbers
2. Calculates and prints their sum, difference, and product

**Expected Output:**
```
Enter first number: 10
Enter second number: 3

Sum: 13
Difference: 7
Product: 30
```

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>

int main() {
    int a, b;
    
    std::cout << "Enter first number: ";
    std::cin >> a;
    
    std::cout << "Enter second number: ";
    std::cin >> b;
    
    std::cout << "\nSum: " << (a + b) << std::endl;
    std::cout << "Difference: " << (a - b) << std::endl;
    std::cout << "Product: " << (a * b) << std::endl;
    
    return 0;
}
```
</details>

---

### Problem 3: Using Auto
Create variables using `auto` and print them:

```cpp
#include <iostream>
#include <string>

int main() {
    auto age = 25;
    auto height = 5.9;
    auto name = std::string("Bob");
    auto is_student = true;
    
    // Your code here: print all variables with labels
    
    return 0;
}
```

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
#include <string>

int main() {
    auto age = 25;
    auto height = 5.9;
    auto name = std::string("Bob");
    auto is_student = true;
    
    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "Height: " << height << std::endl;
    std::cout << "Is student: " << is_student << std::endl;
    
    return 0;
}
```
</details>

---

### Problem 4: Rectangle Area
Write a program that:
1. Asks for width and height of a rectangle
2. Calculates and prints the area and perimeter

**Formulas:**
- Area = width × height
- Perimeter = 2 × (width + height)

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>

int main() {
    double width, height;
    
    std::cout << "Enter width: ";
    std::cin >> width;
    
    std::cout << "Enter height: ";
    std::cin >> height;
    
    double area = width * height;
    double perimeter = 2 * (width + height);
    
    std::cout << "\nArea: " << area << std::endl;
    std::cout << "Perimeter: " << perimeter << std::endl;
    
    return 0;
}
```
</details>

---

## Common Mistakes (And How to Avoid Them!) 🚫

Everyone makes these mistakes when learning C++. Here's what to watch out for:

### Mistake 1: Forgetting Semicolons
```cpp
int x = 5  // ❌ ERROR: missing semicolon
int x = 5; // ✅ Correct
```

**Tip:** Every statement needs a semicolon at the end!

### Mistake 2: Not Declaring Types
```cpp
x = 5;      // ❌ ERROR: what type is x?
int x = 5;  // ✅ Correct: now C++ knows it's an int
```

**Tip:** Always tell C++ what type your variable is!

### Mistake 3: Wrong Quotes
```cpp
char letter = "A";      // ❌ ERROR: double quotes are for strings
char letter = 'A';      // ✅ Correct: single quotes for characters

std::string word = 'hi'; // ❌ ERROR: single quotes are for chars
std::string word = "hi"; // ✅ Correct: double quotes for strings
```

**Tip:** 
- Single character? Single quotes `'A'`
- Text string? Double quotes `"Hello"`

### Mistake 4: Case Sensitivity
```cpp
int Age = 25;
int age = 30;  // ❌ This is a DIFFERENT variable!

bool Flag = True;   // ❌ ERROR: True doesn't exist
bool flag = true;   // ✅ Correct: lowercase true/false
```

**Tip:** C++ cares about UPPERCASE vs lowercase. `Age` and `age` are different!

### Mistake 5: Forgetting Headers
```cpp
int main() {
    std::cout << "Hi";  // ❌ ERROR: iostream not included!
}
```

**Fix:**
```cpp
#include <iostream>  // ✅ Add this at the top!

int main() {
    std::cout << "Hi";  // Now it works!
}
```

**Tip:** Need `cout` or `cin`? Include `<iostream>` at the top!

### Mistake 6: Integer Division Surprise
```cpp
int result = 7 / 2;     // ❌ Result is 3, not 3.5!
double result = 7.0 / 2.0;  // ✅ Result is 3.5
```

**Tip:** When dividing integers, you get an integer. Want decimals? Use `double`!

### Mistake 7: Uninitialized Variables
```cpp
int x;              // ⚠️ x has a random garbage value!
std::cout << x;     // Might print 0, might print 2847562!

int x = 0;          // ✅ Always initialize!
std::cout << x;     // Prints 0
```

**Tip:** Always give your variables an initial value!

---

## Homework Assignments 📚

Try these on your own! They'll help reinforce what you learned today.

### Assignment 1: Personal Profile
Write a program that:
1. Declares variables for: name, age, height (in meters), GPA, and whether you're a student
2. Prints all information nicely formatted

**Challenge:** Use both explicit types and `auto` for different variables!

---

### Assignment 2: Shopping Calculator
Create a program that:
1. Asks the user for the price of an item and quantity
2. Calculates the total cost (price × quantity)
3. Calculates tax (total × 0.08)
4. Prints the subtotal, tax, and final total

**Hint:** Use `double` for prices!

---

### Assignment 3: Temperature Converter
Write a program that:
1. Asks the user for a temperature in Celsius
2. Converts it to Fahrenheit using: F = (C × 9/5) + 32
3. Prints both temperatures

**Example:**
```
Enter temperature in Celsius: 25
25°C = 77°F
```

---

### Assignment 4: Circle Properties
Create a program that:
1. Asks for the radius of a circle
2. Calculates and prints:
   - Circumference = 2 × π × radius
   - Area = π × radius²

**Hint:** Use `const double PI = 3.14159;`

---

## Quick Reference Card 📝

Keep this handy while programming!

### Basic Structure
```cpp
#include <iostream>
#include <string>

int main() {
    // Your code here
    return 0;
}
```

### Types and Variables
```cpp
int age = 20;           // Whole numbers
double pi = 3.14;       // Decimals
char grade = 'A';       // Single character
bool flag = true;       // true or false
std::string name = "Alice";  // Text

auto x = 5;             // Let compiler decide
const int MAX = 100;    // Constant (can't change)
```

### Input and Output
```cpp
std::cout << "Hello!";          // Print
std::cout << "Value: " << x;    // Print variable
std::cin >> age;                // Read input
std::cin >> a >> b >> c;        // Read multiple
```

### Math
```cpp
a + b    // Addition
a - b    // Subtraction
a * b    // Multiplication
a / b    // Division (watch out for int!)
a % b    // Remainder (modulo)

x++;     // Increment (x = x + 1)
x--;     // Decrement (x = x - 1)
x += 5;  // x = x + 5
```

### Common Errors to Avoid
- ❌ Forget semicolons
- ❌ Don't declare types
- ❌ Mix up single `'` and double `"` quotes
- ❌ Forget to include `<iostream>` or `<string>`
- ❌ Use `True/False` instead of `true/false`

---

## What We Learned Today ✅

Congratulations! In your first C++ lecture, you learned:

- ✓ The structure of a C++ program
- ✓ How to compile and run C++ code
- ✓ The difference between Python and C++
- ✓ Data types: `int`, `double`, `char`, `bool`, `string`
- ✓ How to declare and initialize variables
- ✓ The `auto` keyword for type deduction
- ✓ Getting user input with `cin`
- ✓ Printing output with `cout`
- ✓ Constants with `const`
- ✓ Basic arithmetic operations
- ✓ Type conversion
- ✓ Common mistakes to avoid

---

## Next Lecture Sneak Peek 👀

In Lecture 2, we'll learn:
- ✨ Conditional statements (if/else)
- ✨ Comparison operators (`==`, `!=`, `<`, `>`)
- ✨ Logical operators (`&&`, `||`, `!`)
- ✨ Switch statements
- ✨ Making decisions in your programs

Get ready to make your programs smarter!

---

## Resources & Help 🆘

### Compilers
- **Online:** [Compiler Explorer](https://godbolt.org/), [OnlineGDB](https://www.onlinegdb.com/), [Replit](https://replit.com/)
- **Local:** Install GCC or Visual Studio

### Documentation
- [cppreference.com](https://en.cppreference.com/) - Complete C++ reference
- [learncpp.com](https://www.learncpp.com/) - Beginner-friendly tutorials

### Practice
- [HackerRank C++](https://www.hackerrank.com/domains/cpp)
- [LeetCode](https://leetcode.com/)
- [Exercism C++](https://exercism.org/tracks/cpp)

---

## Final Thoughts 💭

C++ might seem more complicated than Python at first, but don't worry! The extra typing and rules are there to:
- ✓ Catch errors early (before running)
- ✓ Make your programs MUCH faster
- ✓ Give you more control

**Remember:** Every expert programmer was once a beginner. Take it one step at a time, practice daily, and don't be afraid to make mistakes - that's how you learn!

**Pro tip:** Type out the examples yourself instead of copy-pasting. Your fingers need to learn the syntax too! 💪

---

**Happy coding! See you in Lecture 2! 🚀**
