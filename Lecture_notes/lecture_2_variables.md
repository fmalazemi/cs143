# Lecture 2: Variables in C++ 📦

## Welcome Back!

In Lecture 1, you learned how to write "Hello, World!" and print to the screen. Now it's time to learn about **variables** - how to store and work with data in C++!

**Remember:** C++ requires you to declare types, unlike Python where types are automatic.

---

## What Are Variables?

Variables are like labeled boxes that store values. In Python, the box can hold anything. In C++, you must specify what type of thing the box can hold!

**Python (Dynamic):**
```python
x = 5        # Box holds a number
x = "hello"  # Same box now holds text - no problem!
```

**C++ (Static):**
```cpp
int x = 5;        // Box labeled "integers only"
x = 10;           // ✅ OK: another integer
x = "hello";      // ❌ ERROR: can't put text in integer box
```

---

## Data Types in C++

C++ has several basic data types. Let's explore each one!

### 1. Integers (`int`)

Stores whole numbers (no decimals).

```cpp
#include <iostream>
using namespace std;

int main() {
    int age = 25;
    int temperature = -5;
    int score = 0;
    int year = 2024;
    
    cout << "Age: " << age << endl;
    cout << "Temperature: " << temperature << endl;
    cout << "Score: " << score << endl;
    cout << "Year: " << year << endl;
    
    return 0;
}
```

**Range:** Typically -2,147,483,648 to 2,147,483,647

---

### 2. Decimal Numbers (`double`)

Stores numbers with decimal points.

```cpp
#include <iostream>
using namespace std;

int main() {
    double pi = 3.14159;
    double price = 19.99;
    double gpa = 3.8;
    double temperature = 98.6;
    
    cout << "Pi: " << pi << endl;
    cout << "Price: $" << price << endl;
    cout << "GPA: " << gpa << endl;
    cout << "Temperature: " << temperature << "°F" << endl;
    
    return 0;
}
```

**Note:** There's also `float` for less precision, but `double` is more commonly used.

```cpp
float small = 3.14f;    // 'f' suffix for float
double big = 3.14159;   // No suffix needed
```

---

### 3. Characters (`char`)

Stores a **single character**. Use **single quotes** `'A'`, not double quotes!

```cpp
#include <iostream>
using namespace std;

int main() {
    char grade = 'A';
    char initial = 'J';
    char symbol = '$';
    char letter = 'x';
    
    cout << "Grade: " << grade << endl;
    cout << "Initial: " << initial << endl;
    cout << "Symbol: " << symbol << endl;
    cout << "Letter: " << letter << endl;
    
    return 0;
}
```

**Important:**
```cpp
char c = 'A';    // ✅ Correct: single quotes for char
char c = "A";    // ❌ ERROR: double quotes make it a string
```

---

### 4. Boolean (`bool`)

Stores `true` or `false` (lowercase!).

```cpp
#include <iostream>
using namespace std;

int main() {
    bool isStudent = true;
    bool hasLicense = false;
    bool isRaining = true;
    bool gameOver = false;
    
    cout << "Is student: " << isStudent << endl;        // Prints: 1
    cout << "Has license: " << hasLicense << endl;      // Prints: 0
    cout << "Is raining: " << isRaining << endl;        // Prints: 1
    cout << "Game over: " << gameOver << endl;          // Prints: 0
    
    return 0;
}
```

**Note:** `true` prints as `1` and `false` prints as `0`.

To print "true"/"false" as text:
```cpp
cout << boolalpha;  // Use this once
cout << "Is student: " << isStudent << endl;  // Now prints: true
```

---

### 5. Strings (`string`)

Stores text (words, sentences). Use **double quotes** `"Hello"`.

```cpp
#include <iostream>
#include <string>  // Don't forget this!
using namespace std;

int main() {
    string name = "Alice";
    string city = "New York";
    string message = "Hello, World!";
    string empty = "";
    
    cout << "Name: " << name << endl;
    cout << "City: " << city << endl;
    cout << "Message: " << message << endl;
    cout << "Empty: '" << empty << "'" << endl;
    
    return 0;
}
```

**Important:**
```cpp
string word = "Hello";   // ✅ Correct: double quotes for string
string word = 'Hello';   // ❌ ERROR: single quotes for char only
```

---

## Variable Declaration and Initialization

### Three Ways to Create Variables

**1. Declare and Initialize (Best Practice)**
```cpp
int age = 25;           // Create and give value immediately
double price = 9.99;
string name = "Bob";
```

**2. Declare First, Assign Later**
```cpp
int x;                  // Declare (has random garbage value!)
x = 10;                 // Assign value

double y;
y = 3.14;
```

**⚠️ Warning:** Uninitialized variables have random values!
```cpp
int x;                  // x has garbage value like 2847562
cout << x;              // Unpredictable output!

int x = 0;              // ✅ Always initialize!
cout << x;              // Prints: 0
```

**3. Declare Multiple Variables**
```cpp
int a = 5, b = 10, c = 15;    // Three integers at once
double x = 1.5, y = 2.5;       // Two doubles
```

---

## Complete Examples

### Example 1: Student Information

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    // Student data
    string name = "Emily Chen";
    int age = 20;
    double gpa = 3.85;
    char grade = 'A';
    bool enrolled = true;
    
    // Print student info
    cout << "=== Student Information ===" << endl;
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "GPA: " << gpa << endl;
    cout << "Grade: " << grade << endl;
    cout << "Enrolled: " << enrolled << endl;
    
    return 0;
}
```

**Output:**
```
=== Student Information ===
Name: Emily Chen
Age: 20
GPA: 3.85
Grade: A
Enrolled: 1
```

---

### Example 2: Product Information

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    // Product data
    string productName = "Wireless Mouse";
    double price = 29.99;
    int quantity = 150;
    bool inStock = true;
    char category = 'E';  // E for Electronics
    
    // Display product
    cout << "Product: " << productName << endl;
    cout << "Price: $" << price << endl;
    cout << "Quantity: " << quantity << endl;
    cout << "In Stock: " << (inStock ? "Yes" : "No") << endl;
    cout << "Category: " << category << endl;
    
    return 0;
}
```

---

### Example 3: Game Character

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    // Character stats
    string playerName = "DragonSlayer";
    int health = 100;
    int mana = 50;
    double armor = 45.5;
    bool isAlive = true;
    char rank = 'S';
    
    cout << "=== Character Stats ===" << endl;
    cout << "Player: " << playerName << endl;
    cout << "Health: " << health << " HP" << endl;
    cout << "Mana: " << mana << " MP" << endl;
    cout << "Armor: " << armor << endl;
    cout << "Rank: " << rank << endl;
    cout << "Status: " << (isAlive ? "Alive" : "Dead") << endl;
    
    return 0;
}
```

---

## Getting User Input 🎤

Use `cin >>` to read user input!

### Basic Input Example

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string name;
    int age;
    
    cout << "What's your name? ";
    cin >> name;
    
    cout << "How old are you? ";
    cin >> age;
    
    cout << "\nNice to meet you, " << name << "!" << endl;
    cout << "You are " << age << " years old." << endl;
    
    return 0;
}
```

**Sample Run:**
```
What's your name? Alice
How old are you? 25

Nice to meet you, Alice!
You are 25 years old.
```

---

### Multiple Inputs

```cpp
#include <iostream>
using namespace std;

int main() {
    int num1, num2, num3;
    
    cout << "Enter three numbers: ";
    cin >> num1 >> num2 >> num3;  // Read all three!
    
    int sum = num1 + num2 + num3;
    cout << "Sum: " << sum << endl;
    
    return 0;
}
```

**Sample Run:**
```
Enter three numbers: 10 20 30
Sum: 60
```

---

### Complete Interactive Program

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    // Declare variables
    string name;
    int age;
    double height;
    char grade;
    
    // Get user input
    cout << "=== Student Registration ===" << endl;
    
    cout << "Enter your name: ";
    cin >> name;
    
    cout << "Enter your age: ";
    cin >> age;
    
    cout << "Enter your height (meters): ";
    cin >> height;
    
    cout << "Enter your grade (A-F): ";
    cin >> grade;
    
    // Display results
    cout << "\n=== Registration Complete ===" << endl;
    cout << "Name: " << name << endl;
    cout << "Age: " << age << " years" << endl;
    cout << "Height: " << height << "m" << endl;
    cout << "Grade: " << grade << endl;
    
    return 0;
}
```

---

## The Magic `auto` Keyword ✨

C++ can figure out types automatically with `auto`!

### Without `auto`
```cpp
int x = 5;
double y = 3.14;
string name = "Alice";
bool flag = true;
```

### With `auto`
```cpp
auto x = 5;              // Compiler knows: int
auto y = 3.14;           // Compiler knows: double
auto name = string("Alice");  // Compiler knows: string
auto flag = true;        // Compiler knows: bool
```

### When to Use `auto`

**✅ Good uses:**
```cpp
auto count = 0;                    // Obviously int
auto price = 19.99;                // Obviously double
auto ready = true;                 // Obviously bool
auto message = string("Hello");    // Explicitly string
```

**⚠️ Be careful:**
```cpp
auto result = 7 / 2;               // int, not double! (result = 3)
auto total = 7.0 / 2.0;            // double (total = 3.5)
```

**💡 Recommendation:** Start with explicit types while learning, then use `auto` for convenience!

---

## Complete Example with `auto`

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    // Using auto
    auto name = string("Bob");
    auto age = 30;
    auto height = 1.75;
    auto employed = true;
    
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Height: " << height << "m" << endl;
    cout << "Employed: " << employed << endl;
    
    return 0;
}
```

---

## Constants with `const`

Sometimes you want values that never change:

```cpp
#include <iostream>
using namespace std;

int main() {
    const double PI = 3.14159;
    const int DAYS_IN_WEEK = 7;
    const int MAX_PLAYERS = 4;
    
    cout << "Pi: " << PI << endl;
    cout << "Days in week: " << DAYS_IN_WEEK << endl;
    cout << "Max players: " << MAX_PLAYERS << endl;
    
    // PI = 3.14;  // ❌ ERROR: Can't change const!
    
    return 0;
}
```

**Convention:** Use UPPERCASE for constants.

---

## Type Conversion 🔄

### Automatic Conversion (Widening)
```cpp
int x = 10;
double y = x;    // int → double (safe, no data lost)
cout << y;       // Prints: 10.0
```

### Manual Conversion (Narrowing)
```cpp
double pi = 3.14159;
int rounded = static_cast<int>(pi);  // double → int
cout << rounded;  // Prints: 3 (decimal lost!)
```

### Complete Example
```cpp
#include <iostream>
using namespace std;

int main() {
    // Safe conversion
    int small = 100;
    double big = small;
    cout << "int to double: " << small << " → " << big << endl;
    
    // Lossy conversion
    double precise = 3.99;
    int truncated = static_cast<int>(precise);
    cout << "double to int: " << precise << " → " << truncated << endl;
    
    // Character to int (ASCII)
    char letter = 'A';
    int ascii = letter;
    cout << "char to int: " << letter << " → " << ascii << endl;
    
    return 0;
}
```

**Output:**
```
int to double: 100 → 100
double to int: 3.99 → 3
char to int: A → 65
```

---

## Practice Exercises 💪

### Exercise 1: Personal Profile
Create a program that stores and displays:
- Your name (string)
- Your age (int)
- Your height in meters (double)
- Your favorite letter (char)
- Whether you like programming (bool)

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string name = "Alice";
    int age = 20;
    double height = 1.65;
    char favLetter = 'A';
    bool likesProgramming = true;
    
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Height: " << height << "m" << endl;
    cout << "Favorite Letter: " << favLetter << endl;
    cout << "Likes Programming: " << likesProgramming << endl;
    
    return 0;
}
```
</details>

---

### Exercise 2: Calculator Input
Create a program that:
1. Asks for two numbers
2. Calculates their sum, difference, and product
3. Displays the results

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    double num1, num2;
    
    cout << "Enter first number: ";
    cin >> num1;
    
    cout << "Enter second number: ";
    cin >> num2;
    
    cout << "\nResults:" << endl;
    cout << "Sum: " << (num1 + num2) << endl;
    cout << "Difference: " << (num1 - num2) << endl;
    cout << "Product: " << (num1 * num2) << endl;
    
    return 0;
}
```
</details>

---

### Exercise 3: Recipe Ingredients
Create a program that uses constants for a recipe:

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    const int EGGS = 3;
    const double FLOUR = 2.5;  // cups
    const double SUGAR = 1.0;  // cups
    const bool NEEDS_BAKING = true;
    
    cout << "=== Cake Recipe ===" << endl;
    cout << "Eggs: " << EGGS << endl;
    cout << "Flour: " << FLOUR << " cups" << endl;
    cout << "Sugar: " << SUGAR << " cups" << endl;
    cout << "Needs baking: " << NEEDS_BAKING << endl;
    
    return 0;
}
```
</details>

---

## Common Mistakes 🚫

### 1. Forgetting to Declare Type
```cpp
x = 5;        // ❌ ERROR: What type?
int x = 5;    // ✅ Correct
```

### 2. Trying to Change Type
```cpp
int x = 5;
x = "hello";  // ❌ ERROR: Can't change type
```

### 3. Wrong Quotes
```cpp
char c = "A";     // ❌ ERROR: double quotes for char
char c = 'A';     // ✅ Correct

string s = 'hi';  // ❌ ERROR: single quotes for string
string s = "hi";  // ✅ Correct
```

### 4. Uninitialized Variables
```cpp
int x;           // ❌ Has garbage value!
cout << x;       // Unpredictable

int x = 0;       // ✅ Always initialize
```

### 5. Case Sensitivity
```cpp
bool Flag = True;    // ❌ ERROR: Use lowercase
bool flag = true;    // ✅ Correct
```

---

## Summary ✅

Today you learned:
- ✓ Basic data types: `int`, `double`, `char`, `bool`, `string`
- ✓ How to declare and initialize variables
- ✓ Getting user input with `cin`
- ✓ The `auto` keyword
- ✓ Constants with `const`
- ✓ Type conversion
- ✓ Common mistakes to avoid

---

## Homework 📚

**Assignment 1:** Create a "Book Information" program that stores and displays:
- Title (string)
- Author (string)
- Pages (int)
- Price (double)
- Rating (char: A-F)
- Available (bool)

**Assignment 2:** Create an interactive program that asks for:
- Product name
- Quantity
- Price per unit
- Then calculates and displays the total cost

**Assignment 3:** Create a "Temperature Converter" that:
- Asks for temperature in Celsius (double)
- Converts to Fahrenheit: F = C × 9/5 + 32
- Displays both temperatures

---

## Next Lecture Preview 👀

In **Lecture 3**, we'll learn:
- ✨ Arithmetic operations
- ✨ Comparison operators
- ✨ If/else statements
- ✨ Making decisions in your programs

**Get ready to make your programs smart!** 🧠

---

## Resources 🆘

- [cppreference.com - Variables](https://en.cppreference.com/w/cpp/language/declarations)
- [learncpp.com - Variables](https://www.learncpp.com/cpp-tutorial/variable-assignment-and-initialization/)

---

**Happy Coding!** 🎉
