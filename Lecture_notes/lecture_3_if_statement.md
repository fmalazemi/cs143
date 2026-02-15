# Lecture 3: Conditional Statements in C++ 🔀

## Welcome Back!

In the previous lectures, you learned how to write basic C++ programs and work with variables. Now it's time to make your programs **smart** by teaching them how to make decisions!

**Remember from Python:** You already know how `if` statements work conceptually. Now you'll learn the C++ syntax!

---

## 📑 Table of Contents

1. [What Are Conditional Statements?](#what-are-conditional-statements)
2. [Comparison Operators](#comparison-operators)
3. [The if Statement](#the-if-statement)
4. [The if-else Statement](#the-if-else-statement)
5. [The if-else if-else Statement](#the-if-else-if-else-statement)
6. [Nested if Statements](#nested-if-statements)
7. [Logical Operators](#logical-operators)
   - [AND Operator (&&)](#and-operator-)
   - [OR Operator (\|\|)](#or-operator-)
   - [NOT Operator (!)](#not-operator-)
8. [Common Mistakes](#common-mistakes)
9. [Complete Examples](#complete-examples)
10. [Practice Exercises](#practice-exercises)
11. [Summary](#summary)

---

## What Are Conditional Statements?

Conditional statements allow your program to **make decisions** based on conditions.

**Real-world analogy:**
```
IF it's raining
    Take an umbrella
ELSE
    Wear sunglasses
```

**In programming:** Your code checks a condition and executes different code based on whether it's true or false.

### Python vs C++ Syntax

**Python:**
```python
if age >= 18:
    print("You can vote")
```

**C++:**
```cpp
if (age >= 18) {
    cout << "You can vote";
}
```

**Key differences:**
- C++ uses **parentheses** `( )` around the condition
- C++ uses **curly braces** `{ }` instead of indentation
- Don't forget the **semicolon** `;` inside the block!

---

## Comparison Operators

Before we dive into `if` statements, let's review the comparison operators:

| Operator | Meaning | Example | Result |
|----------|---------|---------|--------|
| `==` | Equal to | `5 == 5` | `true` |
| `!=` | Not equal to | `5 != 3` | `true` |
| `>` | Greater than | `7 > 3` | `true` |
| `<` | Less than | `3 < 7` | `true` |
| `>=` | Greater than or equal | `5 >= 5` | `true` |
| `<=` | Less than or equal | `4 <= 5` | `true` |

### Examples in Code

```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 10;
    int y = 20;
    
    cout << (x == y) << endl;  // 0 (false)
    cout << (x != y) << endl;  // 1 (true)
    cout << (x < y) << endl;   // 1 (true)
    cout << (x > y) << endl;   // 0 (false)
    
    return 0;
}
```

**Note:** In C++, `true` prints as `1` and `false` prints as `0`.

---

## The if Statement

The simplest form: execute code **only if** a condition is true.

### Syntax

```cpp
if (condition) {
    // Code executes if condition is true
}
```

### Example 1: Basic if

```cpp
#include <iostream>
using namespace std;

int main() {
    int age = 20;
    
    if (age >= 18) {
        cout << "You are an adult." << endl;
    }
    
    cout << "Program continues..." << endl;
    
    return 0;
}
```

**Output:**
```
You are an adult.
Program continues...
```

### Example 2: Checking User Input

```cpp
#include <iostream>
using namespace std;

int main() {
    int score;
    
    cout << "Enter your score: ";
    cin >> score;
    
    if (score >= 90) {
        cout << "Excellent! You got an A!" << endl;
    }
    
    return 0;
}
```

**Sample Run:**
```
Enter your score: 95
Excellent! You got an A!
```

### Single-Line if (Optional Braces)

If you have only **one statement**, braces are optional (but not recommended):

```cpp
if (age >= 18)
    cout << "Adult" << endl;  // OK, but harder to read

// Better style:
if (age >= 18) {
    cout << "Adult" << endl;  // Clear and maintainable
}
```

**Best Practice:** Always use braces `{ }` for clarity!

---

## The if-else Statement

Execute one block of code if condition is true, **another block** if false.

### Syntax

```cpp
if (condition) {
    // Code if condition is true
} else {
    // Code if condition is false
}
```

### Example 1: Even or Odd

```cpp
#include <iostream>
using namespace std;

int main() {
    int number;
    
    cout << "Enter a number: ";
    cin >> number;
    
    if (number % 2 == 0) {
        cout << number << " is even." << endl;
    } else {
        cout << number << " is odd." << endl;
    }
    
    return 0;
}
```

**Sample Runs:**
```
Enter a number: 8
8 is even.
```

```
Enter a number: 7
7 is odd.
```

### Example 2: Pass or Fail

```cpp
#include <iostream>
using namespace std;

int main() {
    int score;
    
    cout << "Enter your score: ";
    cin >> score;
    
    if (score >= 60) {
        cout << "You passed! 🎉" << endl;
    } else {
        cout << "You failed. Study harder!" << endl;
    }
    
    return 0;
}
```

### Example 3: Temperature Check

```cpp
#include <iostream>
using namespace std;

int main() {
    double temp;
    
    cout << "Enter temperature (°C): ";
    cin >> temp;
    
    if (temp > 30) {
        cout << "It's hot! Drink water." << endl;
    } else {
        cout << "Weather is comfortable." << endl;
    }
    
    return 0;
}
```

---

## The if-else if-else Statement

Check **multiple conditions** in sequence.

### Syntax

```cpp
if (condition1) {
    // Code if condition1 is true
} else if (condition2) {
    // Code if condition2 is true
} else if (condition3) {
    // Code if condition3 is true
} else {
    // Code if all conditions are false
}
```

**Important:** Once one condition is true, the rest are **skipped**!

### Example 1: Grade Calculator

```cpp
#include <iostream>
using namespace std;

int main() {
    int score;
    
    cout << "Enter your score (0-100): ";
    cin >> score;
    
    if (score >= 90) {
        cout << "Grade: A" << endl;
    } else if (score >= 80) {
        cout << "Grade: B" << endl;
    } else if (score >= 70) {
        cout << "Grade: C" << endl;
    } else if (score >= 60) {
        cout << "Grade: D" << endl;
    } else {
        cout << "Grade: F" << endl;
    }
    
    return 0;
}
```

**Sample Runs:**
```
Enter your score (0-100): 85
Grade: B
```

```
Enter your score (0-100): 55
Grade: F
```

### Example 2: Age Categories

```cpp
#include <iostream>
using namespace std;

int main() {
    int age;
    
    cout << "Enter your age: ";
    cin >> age;
    
    if (age < 0) {
        cout << "Invalid age!" << endl;
    } else if (age < 13) {
        cout << "You are a child." << endl;
    } else if (age < 20) {
        cout << "You are a teenager." << endl;
    } else if (age < 60) {
        cout << "You are an adult." << endl;
    } else {
        cout << "You are a senior." << endl;
    }
    
    return 0;
}
```

### Example 3: Traffic Light

```cpp
#include <iostream>
using namespace std;

int main() {
    char light;
    
    cout << "Enter traffic light (R/Y/G): ";
    cin >> light;
    
    if (light == 'R' || light == 'r') {
        cout << "STOP! 🛑" << endl;
    } else if (light == 'Y' || light == 'y') {
        cout << "SLOW DOWN! ⚠️" << endl;
    } else if (light == 'G' || light == 'g') {
        cout << "GO! ✅" << endl;
    } else {
        cout << "Invalid input!" << endl;
    }
    
    return 0;
}
```

---

## Nested if Statements

You can put `if` statements **inside** other `if` statements.

### Syntax

```cpp
if (condition1) {
    if (condition2) {
        // Code if both conditions are true
    }
}
```

### Example 1: Nested Conditions

```cpp
#include <iostream>
using namespace std;

int main() {
    int age;
    bool hasLicense;
    
    cout << "Enter your age: ";
    cin >> age;
    
    cout << "Do you have a license? (1=yes, 0=no): ";
    cin >> hasLicense;
    
    if (age >= 18) {
        if (hasLicense) {
            cout << "You can drive! 🚗" << endl;
        } else {
            cout << "You need a license first." << endl;
        }
    } else {
        cout << "You're too young to drive." << endl;
    }
    
    return 0;
}
```

### Example 2: Grade with Bonus

```cpp
#include <iostream>
using namespace std;

int main() {
    int score;
    bool bonus;
    
    cout << "Enter your score: ";
    cin >> score;
    
    cout << "Did you complete bonus? (1=yes, 0=no): ";
    cin >> bonus;
    
    if (score >= 90) {
        cout << "Grade: A" << endl;
        if (bonus) {
            cout << "Perfect! A+ 🌟" << endl;
        }
    } else {
        cout << "Grade: B or lower" << endl;
    }
    
    return 0;
}
```

### Example 3: Number Classification

```cpp
#include <iostream>
using namespace std;

int main() {
    int num;
    
    cout << "Enter a number: ";
    cin >> num;
    
    if (num > 0) {
        cout << "Positive number" << endl;
        if (num % 2 == 0) {
            cout << "And it's even!" << endl;
        } else {
            cout << "And it's odd!" << endl;
        }
    } else if (num < 0) {
        cout << "Negative number" << endl;
    } else {
        cout << "Zero" << endl;
    }
    
    return 0;
}
```

---

## Logical Operators

Combine multiple conditions using logical operators.

| Operator | Meaning | Example | Result |
|----------|---------|---------|--------|
| `&&` | AND | `(x > 5 && x < 10)` | True if both are true |
| `\|\|` | OR | `(x < 5 \|\| x > 10)` | True if at least one is true |
| `!` | NOT | `!(x == 5)` | Reverses the condition |

---

### AND Operator (`&&`)

**Both conditions must be true** for the result to be true.

**Truth Table:**

| Condition 1 | Condition 2 | Condition 1 && Condition 2 |
|-------------|-------------|--------|
| true | true | **true** |
| true | false | false |
| false | true | false |
| false | false | false |

### Example: Age Range Check

```cpp
#include <iostream>
using namespace std;

int main() {
    int age;
    
    cout << "Enter your age: ";
    cin >> age;
    
    if (age >= 13 && age <= 19) {
        cout << "You are a teenager!" << endl;
    } else {
        cout << "You are not a teenager." << endl;
    }
    
    return 0;
}
```

### Example: Valid Score

```cpp
#include <iostream>
using namespace std;

int main() {
    int score;
    
    cout << "Enter score: ";
    cin >> score;
    
    if (score >= 0 && score <= 100) {
        cout << "Valid score: " << score << endl;
    } else {
        cout << "Invalid score! Must be 0-100." << endl;
    }
    
    return 0;
}
```

---

### OR Operator (`||`)

**At least one condition must be true** for the result to be true.

**Truth Table:**

| Condition 1 | Condition 2 | Condition 1 \|\| condition 2 |
|-------------|-------------|--------|
| true | true | **true** |
| true | false | **true** |
| false | true | **true** |
| false | false | false |

### Example: Weekend Check

```cpp
#include <iostream>
using namespace std;

int main() {
    int day;
    
    cout << "Enter day (1=Mon, 7=Sun): ";
    cin >> day;
    
    if (day == 6 || day == 7) {
        cout << "It's the weekend! 🎉" << endl;
    } else {
        cout << "It's a weekday. 😴" << endl;
    }
    
    return 0;
}
```

### Example: Passing Grade

```cpp
#include <iostream>
using namespace std;

int main() {
    int score;
    
    cout << "Enter score: ";
    cin >> score;
    
    if (score >= 60 || score == -1) {  // -1 = excused
        cout << "You pass!" << endl;
    } else {
        cout << "You fail." << endl;
    }
    
    return 0;
}
```

---

### NOT Operator (`!`)

**Reverses** the boolean value.

**Truth Table:**

| Condition | ! Condition |
|-----------|--------|
| true | **false** |
| false | **true** |

### Example: Not Equal

```cpp
#include <iostream>
using namespace std;

int main() {
    int pin;
    
    cout << "Enter PIN: ";
    cin >> pin;
    
    if (!(pin == 1234)) {  // Same as: pin != 1234
        cout << "Wrong PIN!" << endl;
    } else {
        cout << "Access granted!" << endl;
    }
    
    return 0;
}
```

### Example: Not in Range

```cpp
#include <iostream>
using namespace std;

int main() {
    int age;
    
    cout << "Enter age: ";
    cin >> age;
    
    if (!(age >= 18 && age <= 65)) {
        cout << "Not in working age range." << endl;
    } else {
        cout << "Working age!" << endl;
    }
    
    return 0;
}
```

### Combining Multiple Logical Operators

```cpp
#include <iostream>
using namespace std;

int main() {
    int age;
    bool student;
    
    cout << "Enter age: ";
    cin >> age;
    
    cout << "Are you a student? (1/0): ";
    cin >> student;
    
    // Discount if: child OR senior OR student
    if (age < 12 || age > 65 || student) {
        cout << "You get a discount! 🎫" << endl;
    } else {
        cout << "Regular price." << endl;
    }
    
    return 0;
}
```

---

## Common Mistakes

### Mistake 1: Using `=` instead of `==`

```cpp
int x = 10;

if (x = 5) {  // ❌ WRONG: Assignment, not comparison!
    cout << "x is 5";
}

if (x == 5) {  // ✅ CORRECT: Comparison
    cout << "x is 5";
}
```

**What happens:** `x = 5` assigns 5 to x (always true if non-zero)!

---

### Mistake 2: Forgetting Braces

```cpp
// ❌ DANGEROUS:
if (score >= 90)
    cout << "Great job!" << endl;
    cout << "You got an A!" << endl;  // ALWAYS executes!

// ✅ CORRECT:
if (score >= 90) {
    cout << "Great job!" << endl;
    cout << "You got an A!" << endl;  // Both in the block
}
```

---

### Mistake 3: Semicolon After Condition

```cpp
if (age >= 18);  // ❌ WRONG: Semicolon creates empty block!
{
    cout << "Adult";  // Always executes!
}

if (age >= 18) {  // ✅ CORRECT: No semicolon after condition
    cout << "Adult";
}
```

---

### Mistake 4: Wrong Logical Operator

```cpp
// Want: age between 13 and 19
if (age >= 13 && age <= 19) {  // ✅ CORRECT
    cout << "Teenager";
}

if (age >= 13 || age <= 19) {  // ❌ WRONG: Always true!
    cout << "Teenager";
}
```

---

### Mistake 5: Comparing Floating Points

```cpp
double x = 0.1 + 0.2;  // Actually 0.30000000000000004

if (x == 0.3) {  // ❌ Might be false!
    cout << "Equal";
}

// ✅ Better: Check if close enough
if (abs(x - 0.3) < 0.0001) {
    cout << "Close enough!";
}
```

---

## Complete Examples

### Example 1: Login System

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string username, password;
    
    cout << "=== Login System ===" << endl;
    cout << "Username: ";
    cin >> username;
    
    cout << "Password: ";
    cin >> password;
    
    if (username == "admin" && password == "1234") {
        cout << "\n✅ Login successful!" << endl;
        cout << "Welcome, " << username << "!" << endl;
    } else if (username == "admin") {
        cout << "\n❌ Wrong password!" << endl;
    } else {
        cout << "\n❌ User not found!" << endl;
    }
    
    return 0;
}
```

---

### Example 2: BMI Calculator

```cpp
#include <iostream>
using namespace std;

int main() {
    double weight, height, bmi;
    
    cout << "Enter weight (kg): ";
    cin >> weight;
    
    cout << "Enter height (m): ";
    cin >> height;
    
    bmi = weight / (height * height);
    
    cout << "\nYour BMI: " << bmi << endl;
    
    if (bmi < 18.5) {
        cout << "Category: Underweight" << endl;
    } else if (bmi < 25) {
        cout << "Category: Normal weight ✅" << endl;
    } else if (bmi < 30) {
        cout << "Category: Overweight" << endl;
    } else {
        cout << "Category: Obese" << endl;
    }
    
    return 0;
}
```

---

### Example 3: Leap Year Checker

```cpp
#include <iostream>
using namespace std;

int main() {
    int year;
    
    cout << "Enter a year: ";
    cin >> year;
    
    bool isLeap = false;
    
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                isLeap = true;  // Divisible by 400
            }
        } else {
            isLeap = true;  // Divisible by 4 but not 100
        }
    }
    
    if (isLeap) {
        cout << year << " is a leap year! 🗓️" << endl;
    } else {
        cout << year << " is NOT a leap year." << endl;
    }
    
    return 0;
}
```

---

### Example 4: Simple Calculator

```cpp
#include <iostream>
using namespace std;

int main() {
    double num1, num2, result;
    char op;
    
    cout << "Enter first number: ";
    cin >> num1;
    
    cout << "Enter operator (+, -, *, /): ";
    cin >> op;
    
    cout << "Enter second number: ";
    cin >> num2;
    
    if (op == '+') {
        result = num1 + num2;
        cout << num1 << " + " << num2 << " = " << result << endl;
    } else if (op == '-') {
        result = num1 - num2;
        cout << num1 << " - " << num2 << " = " << result << endl;
    } else if (op == '*') {
        result = num1 * num2;
        cout << num1 << " * " << num2 << " = " << result << endl;
    } else if (op == '/') {
        if (num2 != 0) {
            result = num1 / num2;
            cout << num1 << " / " << num2 << " = " << result << endl;
        } else {
            cout << "Error: Division by zero!" << endl;
        }
    } else {
        cout << "Invalid operator!" << endl;
    }
    
    return 0;
}
```

---

## Practice Exercises

### Exercise 1: Positive, Negative, or Zero

Write a program that asks for a number and prints whether it's positive, negative, or zero.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int num;
    
    cout << "Enter a number: ";
    cin >> num;
    
    if (num > 0) {
        cout << "Positive" << endl;
    } else if (num < 0) {
        cout << "Negative" << endl;
    } else {
        cout << "Zero" << endl;
    }
    
    return 0;
}
```
</details>

---

### Exercise 2: Voting Eligibility

Create a program that checks if someone can vote based on:
- Age >= 18
- Must be a citizen (ask user)

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int age;
    bool citizen;
    
    cout << "Enter your age: ";
    cin >> age;
    
    cout << "Are you a citizen? (1=yes, 0=no): ";
    cin >> citizen;
    
    if (age >= 18 && citizen) {
        cout << "You can vote! ✅" << endl;
    } else if (age < 18) {
        cout << "Too young to vote." << endl;
    } else {
        cout << "You must be a citizen to vote." << endl;
    }
    
    return 0;
}
```
</details>

---

### Exercise 3: Maximum of Three Numbers

Write a program that finds the largest of three numbers.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    
    cout << "Enter three numbers: ";
    cin >> a >> b >> c;
    
    if (a >= b && a >= c) {
        cout << "Largest: " << a << endl;
    } else if (b >= a && b >= c) {
        cout << "Largest: " << b << endl;
    } else {
        cout << "Largest: " << c << endl;
    }
    
    return 0;
}
```
</details>

---

### Exercise 4: Temperature Converter with Validation

Create a program that:
1. Asks user to choose conversion (C to F or F to C)
2. Gets temperature value
3. Validates input
4. Performs conversion

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int choice;
    double temp, result;
    
    cout << "Temperature Converter" << endl;
    cout << "1. Celsius to Fahrenheit" << endl;
    cout << "2. Fahrenheit to Celsius" << endl;
    cout << "Choice: ";
    cin >> choice;
    
    if (choice == 1) {
        cout << "Enter temperature in Celsius: ";
        cin >> temp;
        result = (temp * 9.0 / 5.0) + 32;
        cout << temp << "°C = " << result << "°F" << endl;
    } else if (choice == 2) {
        cout << "Enter temperature in Fahrenheit: ";
        cin >> temp;
        result = (temp - 32) * 5.0 / 9.0;
        cout << temp << "°F = " << result << "°C" << endl;
    } else {
        cout << "Invalid choice!" << endl;
    }
    
    return 0;
}
```
</details>

---

## Summary

### What We Learned Today ✅

- ✓ How to use `if` statements for decision making
- ✓ Comparison operators: `==`, `!=`, `>`, `<`, `>=`, `<=`
- ✓ `if-else` for two-way decisions
- ✓ `if-else if-else` for multiple conditions
- ✓ Nested `if` statements for complex logic
- ✓ Logical operators: `&&`, `||`, `!`
- ✓ Common mistakes and how to avoid them
- ✓ Real-world examples and applications

---

## Key Takeaways 💡

1. **Always use braces** `{ }` even for single statements
2. **Use `==` for comparison**, not `=` (assignment)
3. **No semicolon** after `if` condition
4. **Combine conditions** with `&&` (AND) and `||` (OR)
5. **Think logically** - draw flow charts if needed
6. **Test edge cases** - what happens with unusual input?

---

## Next Lecture Preview 👀

In **Lecture 4**, we'll learn about:
- ✨ Loops: `while`, `for`, `do-while`
- ✨ Repetition and iteration
- ✨ Loop control: `break` and `continue`
- ✨ Nested loops
- ✨ Common loop patterns

**Get ready to make your programs repeat tasks efficiently!** 🔁

---

## Homework 📚

**Assignment 1:** Create a "Grade Calculator" that:
- Takes a score (0-100)
- Assigns letter grade (A, B, C, D, F)
- Adds + or - (e.g., B+ for 87, B- for 80)

**Assignment 2:** Create a "Triangle Validator" that:
- Takes three side lengths
- Checks if they form a valid triangle
- Determines triangle type (equilateral, isosceles, scalene)

**Assignment 3:** Create a "Quadratic Equation Solver" that:
- Takes coefficients a, b, c
- Checks if solution exists (discriminant)
- Displays roots or "No real solutions"

---

## Resources 🆘

- [cppreference.com - if statement](https://en.cppreference.com/w/cpp/language/if)
- [learncpp.com - Control Flow](https://www.learncpp.com/cpp-tutorial/introduction-to-control-flow/)

---

**Happy Coding!** 🎉
