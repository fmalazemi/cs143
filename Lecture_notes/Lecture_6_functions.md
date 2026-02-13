# Lecture 6: Functions in C++

## Welcome

In previous lectures, you learned about loops and control flow. Now you will learn how to organize your code into reusable blocks called functions.

**Why functions are important:**
- Organize code into logical blocks
- Avoid repeating the same code
- Make programs easier to read and maintain
- Break complex problems into smaller pieces

---

## Table of Contents

1. [What Are Functions?](#what-are-functions)
2. [Function Basics](#function-basics)
   - [Function Syntax](#function-syntax)
   - [Calling Functions](#calling-functions)
   - [Function Prototypes](#function-prototypes)
3. [Function Parameters](#function-parameters)
4. [Return Values](#return-values)
5. [Function Examples](#function-examples)
6. [Scope and Lifetime](#scope-and-lifetime)
7. [Common Mistakes](#common-mistakes)
8. [Practice Exercises](#practice-exercises)
9. [Summary](#summary)

---

## What Are Functions?

A function is a block of code that performs a specific task. You can call (use) the function whenever you need that task performed.

**Real-world analogy:**
Think of a function like a machine in a factory. You give it input materials, it processes them, and gives you a finished product.

### Functions You Already Know

You have been using functions throughout this course:

```cpp
cout << "Hello";     // Output function
cin >> number;       // Input function
```

The `main()` function is also a function - it is where your program starts executing.

### Why Use Functions?

**Problem:** You need to calculate the area of rectangles many times in your program.

**Without functions:**
```cpp
int main() {
    // Calculate area of rectangle 1
    int length1 = 5, width1 = 3;
    int area1 = length1 * width1;
    
    // Calculate area of rectangle 2
    int length2 = 8, width2 = 4;
    int area2 = length2 * width2;
    
    // Calculate area of rectangle 3
    int length3 = 10, width3 = 6;
    int area3 = length3 * width3;
    
    // If formula changes, you must change it in 3 places!
}
```

**With functions:**
```cpp
int calculateArea(int length, int width) {
    return length * width;
}

int main() {
    int area1 = calculateArea(5, 3);
    int area2 = calculateArea(8, 4);
    int area3 = calculateArea(10, 6);
    
    // If formula changes, you only change it once!
}
```

**Benefits:**
- Code is clearer and easier to read
- If you need to change the calculation, you only change it in one place
- Less chance of making mistakes
- Can reuse the function in other programs

---

## Function Basics

### Function Syntax

```cpp
returnType functionName(parameterList) {
    // Function body
    // Code to execute
    return value;  // If returnType is not void
}
```

**Parts of a function:**

1. **Return Type** - What type of value the function returns (int, double, void, etc.)
2. **Function Name** - Descriptive name following variable naming rules
3. **Parameter List** - Input values the function needs (can be empty)
4. **Function Body** - The code enclosed in curly braces { }
5. **Return Statement** - Sends a value back to the caller (not needed for void)

### Simple Example

```cpp
#include <iostream>
using namespace std;

int add(int a, int b) {
    int sum = a + b;
    return sum;
}

int main() {
    int result = add(5, 3);
    cout << "Result: " << result << endl;  // Output: Result: 8
    return 0;
}
```

**Breaking it down:**
- `int` - Function returns an integer
- `add` - Function name (describes what it does)
- `(int a, int b)` - Takes two integer parameters
- `return sum;` - Returns the calculated sum

### Calling Functions

To use a function, you call it by name and provide the required values:

```cpp
functionName(value1, value2);
```

**Example:**
```cpp
int result = add(10, 20);  // Calls add function
cout << result;             // Output: 30
```

### Function Prototypes

A **function prototype** (also called a function declaration) tells the compiler that a function exists before you define it.

**Why do we need prototypes?**

The compiler reads your code from top to bottom. If you call a function before defining it, the compiler does not know it exists.

**Problem without prototype:**
```cpp
#include <iostream>
using namespace std;

int main() {
    int result = add(5, 3);  // Error: add not declared
    cout << result << endl;
    return 0;
}

int add(int a, int b) {  // Definition comes after use
    return a + b;
}
```

**Solution 1: Define function before main**
```cpp
#include <iostream>
using namespace std;

int add(int a, int b) {  // Definition before use
    return a + b;
}

int main() {
    int result = add(5, 3);  // Works!
    cout << result << endl;
    return 0;
}
```

**Solution 2: Use function prototype**
```cpp
#include <iostream>
using namespace std;

// Function prototype (declaration)
int add(int a, int b);

int main() {
    int result = add(5, 3);  // Works!
    cout << result << endl;
    return 0;
}

// Function definition
int add(int a, int b) {
    return a + b;
}
```

**Function prototype syntax:**
```cpp
returnType functionName(parameterTypes);
```

**Note:** You can omit parameter names in prototypes:
```cpp
int add(int, int);  // Valid prototype
```

But including names makes it clearer:
```cpp
int add(int a, int b);  // Better - shows purpose
```

### Multiple Function Prototypes

```cpp
#include <iostream>
using namespace std;

// Function prototypes
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
double divide(int a, int b);

int main() {
    cout << add(10, 5) << endl;      // 15
    cout << subtract(10, 5) << endl; // 5
    cout << multiply(10, 5) << endl; // 50
    cout << divide(10, 5) << endl;   // 2
    return 0;
}

// Function definitions
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

double divide(int a, int b) {
    return a / (double)b;
}
```

---

## Function Parameters

Parameters are variables that receive values when the function is called.

### No Parameters

A function can have no parameters if it does not need input:

```cpp
#include <iostream>
using namespace std;

void greet() {
    cout << "Hello, World!" << endl;
}

int main() {
    greet();  // Call with empty parentheses
    greet();  // Can call multiple times
    return 0;
}
```

**Output:**
```
Hello, World!
Hello, World!
```

### One Parameter

```cpp
#include <iostream>
using namespace std;

void greetPerson(string name) {
    cout << "Hello, " << name << "!" << endl;
}

int main() {
    greetPerson("Alice");
    greetPerson("Bob");
    return 0;
}
```

**Output:**
```
Hello, Alice!
Hello, Bob!
```

### Multiple Parameters

```cpp
#include <iostream>
using namespace std;

int multiply(int x, int y) {
    return x * y;
}

int main() {
    int result = multiply(4, 5);
    cout << "Result: " << result << endl;
    return 0;
}
```

**Output:**
```
Result: 20
```

### Parameter Passing

When you call a function, the values are copied to the parameters:

```cpp
int main() {
    int a = 10;
    int b = 20;
    int sum = add(a, b);  // Values of a and b are copied to function
}
```

The parameter names inside the function do not need to match the variable names outside:

```cpp
int add(int x, int y) {  // Parameters named x and y
    return x + y;
}

int main() {
    int a = 5;
    int b = 3;
    int sum = add(a, b);  // a goes to x, b goes to y
}
```

---

## Return Values

### Functions That Return Values

A function can calculate a value and return it to the caller:

```cpp
#include <iostream>
using namespace std;

int square(int number) {
    return number * number;
}

int main() {
    int result = square(5);
    cout << "Square: " << result << endl;  // Output: Square: 25
    return 0;
}
```

**How it works:**
1. Function calculates `5 * 5 = 25`
2. `return 25;` sends the value back
3. Value is assigned to `result`

### void Functions (No Return)

When a function does not return a value, use `void` as the return type:

```cpp
#include <iostream>
using namespace std;

void printMessage() {
    cout << "This function does not return anything" << endl;
    // No return statement needed
}

int main() {
    printMessage();  // Just call it, no assignment
    return 0;
}
```

**Important:** You cannot assign a void function to a variable:
```cpp
int x = printMessage();  // Error! void function has no value
```

### Different Return Types

Functions can return any data type:

**Returning int:**
```cpp
int getAge() {
    return 25;
}
```

**Returning double:**
```cpp
double calculateAverage(int a, int b) {
    return (a + b) / 2.0;
}
```

**Returning bool:**
```cpp
bool isEven(int number) {
    return (number % 2 == 0);
}
```

**Returning string:**
```cpp
string getGrade(int score) {
    if (score >= 90) return "A";
    if (score >= 80) return "B";
    if (score >= 70) return "C";
    if (score >= 60) return "D";
    return "F";
}
```

### Early Return

You can return from a function at any point:

```cpp
int findMax(int a, int b) {
    if (a > b) {
        return a;  // Return immediately if a is larger
    }
    return b;  // Otherwise return b
}
```

**Multiple return statements:**
```cpp
string checkNumber(int num) {
    if (num > 0) {
        return "Positive";
    } else if (num < 0) {
        return "Negative";
    } else {
        return "Zero";
    }
}
```

---

## Function Examples

### Example 1: Calculate Circle Area

```cpp
#include <iostream>
using namespace std;

double calculateCircleArea(double radius) {
    const double PI = 3.14159;
    return PI * radius * radius;
}

int main() {
    double r = 5.0;
    double area = calculateCircleArea(r);
    cout << "Area: " << area << endl;
    
    return 0;
}
```

**Output:**
```
Area: 78.5398
```

### Example 2: Check Prime Number

```cpp
#include <iostream>
using namespace std;

bool isPrime(int number) {
    if (number <= 1) {
        return false;
    }
    
    for (int i = 2; i < number; i++) {
        if (number % i == 0) {
            return false;  // Found a divisor, not prime
        }
    }
    
    return true;  // No divisors found, is prime
}

int main() {
    int num = 17;
    
    if (isPrime(num)) {
        cout << num << " is prime" << endl;
    } else {
        cout << num << " is not prime" << endl;
    }
    
    return 0;
}
```

**Output:**
```
17 is prime
```

### Example 3: Print Pattern

```cpp
#include <iostream>
using namespace std;

void printStars(int count) {
    for (int i = 0; i < count; i++) {
        cout << "* ";
    }
    cout << endl;
}

int main() {
    for (int i = 1; i <= 5; i++) {
        printStars(i);
    }
    
    return 0;
}
```

**Output:**
```
*
* *
* * *
* * * *
* * * * *
```

### Example 4: Temperature Converter

```cpp
#include <iostream>
using namespace std;

// Function prototypes
double celsiusToFahrenheit(double celsius);
double fahrenheitToCelsius(double fahrenheit);

int main() {
    double tempC = 25.0;
    double tempF = celsiusToFahrenheit(tempC);
    cout << tempC << "C = " << tempF << "F" << endl;
    
    double temp2F = 77.0;
    double temp2C = fahrenheitToCelsius(temp2F);
    cout << temp2F << "F = " << temp2C << "C" << endl;
    
    return 0;
}

double celsiusToFahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}
```

**Output:**
```
25C = 77F
77F = 25C
```

### Example 5: Find Maximum of Three Numbers

```cpp
#include <iostream>
using namespace std;

int findMax(int a, int b, int c) {
    int max = a;
    
    if (b > max) {
        max = b;
    }
    
    if (c > max) {
        max = c;
    }
    
    return max;
}

int main() {
    int x = 15, y = 23, z = 18;
    int maximum = findMax(x, y, z);
    
    cout << "Maximum: " << maximum << endl;
    
    return 0;
}
```

**Output:**
```
Maximum: 23
```

### Example 6: Calculate Factorial

```cpp
#include <iostream>
using namespace std;

int factorial(int n) {
    int result = 1;
    
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    
    return result;
}

int main() {
    int num = 5;
    int fact = factorial(num);
    
    cout << "Factorial of " << num << " is " << fact << endl;
    
    return 0;
}
```

**Output:**
```
Factorial of 5 is 120
```

### Example 7: Power Function

```cpp
#include <iostream>
using namespace std;

int power(int base, int exponent) {
    int result = 1;
    
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    
    return result;
}

int main() {
    int base = 2;
    int exp = 10;
    
    cout << base << "^" << exp << " = " << power(base, exp) << endl;
    
    return 0;
}
```

**Output:**
```
2^10 = 1024
```

### Example 8: Count Digits

```cpp
#include <iostream>
using namespace std;

int countDigits(int number) {
    int count = 0;
    
    if (number == 0) {
        return 1;
    }
    
    while (number > 0) {
        count++;
        number /= 10;
    }
    
    return count;
}

int main() {
    int num = 12345;
    
    cout << num << " has " << countDigits(num) << " digits" << endl;
    
    return 0;
}
```

**Output:**
```
12345 has 5 digits
```

---

## Scope and Lifetime

### Local Variables

Variables declared inside a function are **local** to that function. They only exist while the function is executing.

```cpp
#include <iostream>
using namespace std;

void testFunction() {
    int x = 10;  // Local variable
    cout << "Inside function: " << x << endl;
}

int main() {
    testFunction();
    // cout << x;  // Error! x does not exist here
    return 0;
}
```

### Variable Scope

Each function has its own scope. Variables in one function do not affect variables in another:

```cpp
#include <iostream>
using namespace std;

void functionA() {
    int x = 5;
    cout << "Function A: " << x << endl;
}

void functionB() {
    int x = 10;  // Different x, different scope
    cout << "Function B: " << x << endl;
}

int main() {
    functionA();  // Output: Function A: 5
    functionB();  // Output: Function B: 10
    return 0;
}
```

### Global Variables

Variables declared outside all functions are **global** and can be accessed from anywhere:

```cpp
#include <iostream>
using namespace std;

int globalVar = 100;  // Global variable

void showGlobal() {
    cout << "Global: " << globalVar << endl;
}

int main() {
    cout << "Main: " << globalVar << endl;
    showGlobal();
    globalVar = 200;
    showGlobal();
    return 0;
}
```

**Output:**
```
Main: 100
Global: 100
Global: 200
```

**Warning:** Avoid using global variables when possible. They make code harder to understand and debug. Use function parameters instead.

---

## Common Mistakes

### Mistake 1: Forgetting to Return a Value

**Wrong:**
```cpp
int add(int a, int b) {
    int sum = a + b;
    // Forgot return statement - undefined behavior
}
```

**Correct:**
```cpp
int add(int a, int b) {
    int sum = a + b;
    return sum;
}
```

### Mistake 2: Using void When You Need a Return

**Wrong:**
```cpp
void calculateSum(int a, int b) {
    return a + b;  // Error: void function cannot return value
}
```

**Correct:**
```cpp
int calculateSum(int a, int b) {
    return a + b;
}
```

### Mistake 3: Function Not Declared Before Use

**Wrong:**
```cpp
int main() {
    int result = add(5, 3);  // Error: add not declared
    return 0;
}

int add(int a, int b) {
    return a + b;
}
```

**Correct - Use prototype:**
```cpp
int add(int a, int b);  // Function prototype

int main() {
    int result = add(5, 3);  // Works!
    return 0;
}

int add(int a, int b) {
    return a + b;
}
```

### Mistake 4: Wrong Parameter Types

**Wrong:**
```cpp
int square(int x) {
    return x * x;
}

int main() {
    double result = square(5.5);  // Loses precision, 5.5 becomes 5
}
```

**Correct:**
```cpp
double square(double x) {
    return x * x;
}

int main() {
    double result = square(5.5);  // Correct, preserves precision
}
```

### Mistake 5: Missing Semicolon in Prototype

**Wrong:**
```cpp
int add(int a, int b)  // Missing semicolon
```

**Correct:**
```cpp
int add(int a, int b);  // Semicolon required
```

---

## Practice Exercises

### Exercise 1: Convert Minutes to Hours and Minutes

Write a function that takes total minutes and prints hours and minutes.

**Example:** 150 minutes → 2 hours and 30 minutes

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

void convertMinutes(int totalMinutes);

int main() {
    convertMinutes(150);
    convertMinutes(90);
    convertMinutes(45);
    return 0;
}

void convertMinutes(int totalMinutes) {
    int hours = totalMinutes / 60;
    int minutes = totalMinutes % 60;
    
    cout << totalMinutes << " minutes = " << hours << " hours and " 
         << minutes << " minutes" << endl;
}
```
</details>

---

### Exercise 2: Check Leap Year

Write a function that returns true if a year is a leap year, false otherwise.

A year is a leap year if:
- Divisible by 4 AND not divisible by 100
- OR divisible by 400

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

bool isLeapYear(int year);

int main() {
    int year = 2024;
    
    if (isLeapYear(year)) {
        cout << year << " is a leap year" << endl;
    } else {
        cout << year << " is not a leap year" << endl;
    }
    
    return 0;
}

bool isLeapYear(int year) {
    if (year % 400 == 0) {
        return true;
    }
    if (year % 100 == 0) {
        return false;
    }
    if (year % 4 == 0) {
        return true;
    }
    return false;
}
```
</details>

---

### Exercise 3: Greatest Common Divisor

Write a function that calculates the GCD of two numbers using the Euclidean algorithm.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int gcd(int a, int b);

int main() {
    cout << "GCD(48, 18) = " << gcd(48, 18) << endl;
    cout << "GCD(100, 35) = " << gcd(100, 35) << endl;
    return 0;
}

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
```
</details>

---

### Exercise 4: Reverse a Number

Write a function that reverses the digits of a number.

**Example:** 1234 → 4321

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int reverseNumber(int num);

int main() {
    cout << "Reverse of 1234: " << reverseNumber(1234) << endl;
    cout << "Reverse of 9876: " << reverseNumber(9876) << endl;
    return 0;
}

int reverseNumber(int num) {
    int reversed = 0;
    
    while (num > 0) {
        int digit = num % 10;
        reversed = reversed * 10 + digit;
        num /= 10;
    }
    
    return reversed;
}
```
</details>

---

### Exercise 5: Print Fibonacci Sequence

Write a function that prints the first n Fibonacci numbers.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

void printFibonacci(int n);

int main() {
    cout << "First 10 Fibonacci numbers: ";
    printFibonacci(10);
    return 0;
}

void printFibonacci(int n) {
    int first = 0, second = 1;
    
    for (int i = 0; i < n; i++) {
        cout << first << " ";
        
        int next = first + second;
        first = second;
        second = next;
    }
    cout << endl;
}
```
</details>

---

### Exercise 6: Count Vowels

Write a function that counts the number of vowels in a string.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
#include <string>
using namespace std;

int countVowels(string text);

int main() {
    string text = "Hello World";
    cout << "Vowels in '" << text << "': " << countVowels(text) << endl;
    return 0;
}

int countVowels(string text) {
    int count = 0;
    
    for (int i = 0; i < text.length(); i++) {
        char c = tolower(text[i]);
        
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            count++;
        }
    }
    
    return count;
}
```
</details>

---

### Exercise 7: Check Palindrome Number

Write a function that checks if a number is a palindrome.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

bool isPalindrome(int num);

int main() {
    cout << "12321 is palindrome: " << isPalindrome(12321) << endl;
    cout << "12345 is palindrome: " << isPalindrome(12345) << endl;
    return 0;
}

bool isPalindrome(int num) {
    int original = num;
    int reversed = 0;
    
    while (num > 0) {
        reversed = reversed * 10 + (num % 10);
        num /= 10;
    }
    
    return original == reversed;
}
```
</details>

---

### Exercise 8: Calculate Sum of Digits

Write a function that calculates the sum of all digits in a number.

**Example:** 1234 → 1+2+3+4 = 10

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int sumOfDigits(int num);

int main() {
    cout << "Sum of digits of 1234: " << sumOfDigits(1234) << endl;
    cout << "Sum of digits of 9876: " << sumOfDigits(9876) << endl;
    return 0;
}

int sumOfDigits(int num) {
    int sum = 0;
    
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    
    return sum;
}
```
</details>

---

### Exercise 9: Find Minimum of Three Numbers

Write a function that returns the minimum of three numbers.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int findMin(int a, int b, int c);

int main() {
    cout << "Minimum of 15, 23, 18: " << findMin(15, 23, 18) << endl;
    return 0;
}

int findMin(int a, int b, int c) {
    int min = a;
    
    if (b < min) {
        min = b;
    }
    
    if (c < min) {
        min = c;
    }
    
    return min;
}
```
</details>

---

### Exercise 10: Print Multiplication Table

Write a function that prints the multiplication table for a given number.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

void printMultiplicationTable(int number);

int main() {
    printMultiplicationTable(7);
    return 0;
}

void printMultiplicationTable(int number) {
    cout << "Multiplication table for " << number << endl;
    
    for (int i = 1; i <= 10; i++) {
        cout << number << " x " << i << " = " << (number * i) << endl;
    }
}
```
</details>

---

## Summary

### What We Learned Today

- **Functions** - Reusable blocks of code that perform specific tasks
- **Function syntax** - Return type, name, parameters, body
- **Function prototypes** - Declaring functions before use
- **Parameters** - Passing values to functions
- **Return values** - Getting results from functions
- **Scope** - Local vs global variables

---

## Key Takeaways

1. **Functions organize code** - Break complex programs into manageable pieces
2. **DRY principle** - Do not Repeat Yourself (use functions instead)
3. **Return type matters** - Use void if no return value
4. **Function prototypes** - Declare functions at the top if defined after main
5. **Descriptive names** - Function names should describe what they do
6. **Local scope** - Variables inside functions are isolated

---

## Next Lecture Preview

In the next lecture, we will learn about **Advanced Functions**:
- Function overloading (same name, different parameters)
- Pass by value vs pass by reference
- Default parameters
- Passing arrays to functions

---

## Homework

**Assignment 1:** Write a program with a function that calculates the area of a circle. Create another function for the circumference. Use prototypes correctly.

**Assignment 2:** Create a function that takes a number and returns true if it is a perfect number. A perfect number equals the sum of its divisors (excluding itself). Example: 6 = 1 + 2 + 3

**Assignment 3:** Write a menu-driven calculator program. Create separate functions for add, subtract, multiply, and divide. Use a loop in main to keep the calculator running until the user chooses to exit.

---

## Resources

- [cppreference.com - Functions](https://en.cppreference.com/w/cpp/language/functions)
- [learncpp.com - Functions](https://www.learncpp.com/cpp-tutorial/introduction-to-functions/)

---

**Functions are fundamental to good programming.** Master them to write clean, maintainable code.
