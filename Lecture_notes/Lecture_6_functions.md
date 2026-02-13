# Lecture 6: Functions in C++

## Welcome

In previous lectures, you learned about loops and control flow. Now you will learn how to organize your code into reusable blocks called functions.

**Why functions are important:**
- Organize code into logical blocks
- Avoid repeating the same code
- Make programs easier to read and maintain
- Allow code reuse across different parts of your program

---

## Table of Contents

1. [What Are Functions?](#what-are-functions)
2. [Function Syntax](#function-syntax)
3. [Function Parameters](#function-parameters)
4. [Return Values](#return-values)
5. [Function Examples](#function-examples)
6. [Pass by Value vs Pass by Reference](#pass-by-value-vs-pass-by-reference)
7. [Function Overloading](#function-overloading)
8. [Default Parameters](#default-parameters)
9. [Common Mistakes](#common-mistakes)
10. [Practice Exercises](#practice-exercises)
11. [Summary](#summary)

---

## What Are Functions?

A function is a block of code that performs a specific task. You can call (use) the function whenever you need that task performed.

**Real-world analogy:**
Think of a function like a recipe. Instead of writing out the recipe steps every time you cook, you just refer to the recipe by name.

### Functions You Already Know

You have been using functions already:

```cpp
cout << "Hello";     // cout is a function
cin >> number;       // cin is a function
sqrt(25);           // sqrt is a function
```

### Why Use Functions?

**Without functions:**
```cpp
// Calculate area of rectangle 1
int area1 = length1 * width1;

// Calculate area of rectangle 2
int area2 = length2 * width2;

// Calculate area of rectangle 3
int area3 = length3 * width3;
```

**With functions:**
```cpp
int area1 = calculateArea(length1, width1);
int area2 = calculateArea(length2, width2);
int area3 = calculateArea(length3, width3);
```

**Benefits:**
- Code is clearer and easier to read
- If you need to change the calculation, you only change it in one place
- Less chance of making mistakes

---

## Function Syntax

### Basic Structure

```cpp
returnType functionName(parameterList) {
    // Function body
    // Code to execute
    return value;  // If returnType is not void
}
```

**Parts of a function:**
1. **Return Type** - What type of value the function returns (int, double, void, etc.)
2. **Function Name** - Descriptive name for what the function does
3. **Parameter List** - Input values the function needs (can be empty)
4. **Function Body** - The code that executes when function is called
5. **Return Statement** - Sends a value back to the caller (not needed for void)

### Simple Example

```cpp
int add(int a, int b) {
    int sum = a + b;
    return sum;
}
```

**Breaking it down:**
- `int` - Function returns an integer
- `add` - Function name
- `(int a, int b)` - Takes two integer parameters
- `return sum;` - Returns the result

### Calling a Function

```cpp
int main() {
    int result = add(5, 3);
    cout << "Result: " << result << endl;  // Output: Result: 8
    return 0;
}
```

---

## Function Parameters

Parameters are variables that hold the values passed to the function.

### No Parameters

```cpp
void greet() {
    cout << "Hello, World!" << endl;
}

// Calling the function
greet();  // Output: Hello, World!
```

### One Parameter

```cpp
void greetPerson(string name) {
    cout << "Hello, " << name << "!" << endl;
}

// Calling the function
greetPerson("Alice");  // Output: Hello, Alice!
```

### Multiple Parameters

```cpp
int multiply(int x, int y) {
    return x * y;
}

// Calling the function
int result = multiply(4, 5);
cout << result;  // Output: 20
```

### Parameter Names

The names you use for parameters inside the function do not need to match the variable names outside:

```cpp
int add(int a, int b) {
    return a + b;
}

int main() {
    int x = 10;
    int y = 20;
    int sum = add(x, y);  // x goes to a, y goes to b
}
```

---

## Return Values

### Functions That Return Values

```cpp
int square(int number) {
    return number * number;
}

int main() {
    int result = square(5);
    cout << result;  // Output: 25
}
```

### void Functions (No Return)

When a function does not return a value, use `void`:

```cpp
void printMessage() {
    cout << "This function does not return anything" << endl;
}

int main() {
    printMessage();  // Just call it, no assignment
}
```

### Returning Different Types

```cpp
double calculateAverage(int a, int b) {
    return (a + b) / 2.0;
}

bool isEven(int number) {
    return (number % 2 == 0);
}

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
        return a;
    }
    return b;
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
            return false;
        }
    }
    
    return true;
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

double celsiusToFahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

int main() {
    double tempC = 25.0;
    double tempF = celsiusToFahrenheit(tempC);
    
    cout << tempC << "C = " << tempF << "F" << endl;
    
    double temp2F = 77.0;
    double temp2C = fahrenheitToCelsius(temp2F);
    
    cout << temp2F << "F = " << temp2C << "C" << endl;
    
    return 0;
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

## Pass by Value vs Pass by Reference

### Pass by Value (Default)

When you pass a variable by value, the function gets a copy. Changes inside the function do not affect the original variable.

```cpp
#include <iostream>
using namespace std;

void changeValue(int x) {
    x = 100;  // Changes only the copy
    cout << "Inside function: " << x << endl;
}

int main() {
    int num = 10;
    changeValue(num);
    cout << "Outside function: " << num << endl;  // Still 10
    
    return 0;
}
```

**Output:**
```
Inside function: 100
Outside function: 10
```

### Pass by Reference

When you pass by reference (using `&`), the function gets the actual variable. Changes inside the function affect the original.

```cpp
#include <iostream>
using namespace std;

void changeValue(int &x) {  // Note the &
    x = 100;  // Changes the original
    cout << "Inside function: " << x << endl;
}

int main() {
    int num = 10;
    changeValue(num);
    cout << "Outside function: " << num << endl;  // Now 100
    
    return 0;
}
```

**Output:**
```
Inside function: 100
Outside function: 100
```

### When to Use Each

**Use pass by value when:**
- You do not want to modify the original variable
- You are working with small data types (int, double, char)

**Use pass by reference when:**
- You want to modify the original variable
- You want to return multiple values
- You are working with large data structures (to avoid copying)

### Swapping Two Numbers

```cpp
#include <iostream>
using namespace std;

void swap(int &a, int &b) {  // Must use references
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 5, y = 10;
    
    cout << "Before: x=" << x << " y=" << y << endl;
    swap(x, y);
    cout << "After: x=" << x << " y=" << y << endl;
    
    return 0;
}
```

**Output:**
```
Before: x=5 y=10
After: x=10 y=5
```

---

## Function Overloading

Function overloading allows you to have multiple functions with the same name but different parameters.

### Same Name, Different Parameters

```cpp
#include <iostream>
using namespace std;

int add(int a, int b) {
    return a + b;
}

double add(double a, double b) {
    return a + b;
}

int add(int a, int b, int c) {
    return a + b + c;
}

int main() {
    cout << add(5, 3) << endl;           // Calls first version
    cout << add(5.5, 3.2) << endl;       // Calls second version
    cout << add(1, 2, 3) << endl;        // Calls third version
    
    return 0;
}
```

**Output:**
```
8
8.7
6
```

### How It Works

The compiler chooses the correct function based on:
- Number of parameters
- Types of parameters

### Volume Calculator Example

```cpp
#include <iostream>
using namespace std;

// Volume of cube
double volume(double side) {
    return side * side * side;
}

// Volume of rectangular box
double volume(double length, double width, double height) {
    return length * width * height;
}

// Volume of cylinder
double volume(double radius, double height, bool isCylinder) {
    const double PI = 3.14159;
    return PI * radius * radius * height;
}

int main() {
    cout << "Cube volume: " << volume(3.0) << endl;
    cout << "Box volume: " << volume(2.0, 3.0, 4.0) << endl;
    cout << "Cylinder volume: " << volume(2.0, 5.0, true) << endl;
    
    return 0;
}
```

**Output:**
```
Cube volume: 27
Box volume: 24
Cylinder volume: 62.8318
```

---

## Default Parameters

You can give parameters default values that are used if no value is provided.

### Basic Default Parameters

```cpp
#include <iostream>
using namespace std;

void greet(string name = "Guest") {
    cout << "Hello, " << name << "!" << endl;
}

int main() {
    greet("Alice");  // Output: Hello, Alice!
    greet();         // Output: Hello, Guest!
    
    return 0;
}
```

### Multiple Default Parameters

```cpp
#include <iostream>
using namespace std;

int power(int base, int exponent = 2) {
    int result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

int main() {
    cout << power(5) << endl;      // 5^2 = 25
    cout << power(5, 3) << endl;   // 5^3 = 125
    
    return 0;
}
```

**Output:**
```
25
125
```

### Rules for Default Parameters

1. Default parameters must come at the end of the parameter list
2. Once you use a default parameter, all following parameters must also have defaults

```cpp
// Correct
void func1(int a, int b = 5, int c = 10);

// Wrong - non-default after default
void func2(int a = 5, int b);  // Error!
```

### Rectangle Area with Defaults

```cpp
#include <iostream>
using namespace std;

double rectangleArea(double length, double width = 1.0) {
    return length * width;
}

int main() {
    cout << "Area (5x3): " << rectangleArea(5, 3) << endl;
    cout << "Area (5x1): " << rectangleArea(5) << endl;  // Uses default width
    
    return 0;
}
```

**Output:**
```
Area (5x3): 15
Area (5x1): 5
```

---

## Common Mistakes

### Mistake 1: Forgetting to Return a Value

**Wrong:**
```cpp
int add(int a, int b) {
    int sum = a + b;
    // Forgot return statement
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

**Correct (Solution 1 - Define before use):**
```cpp
int add(int a, int b) {
    return a + b;
}

int main() {
    int result = add(5, 3);  // Works
    return 0;
}
```

**Correct (Solution 2 - Use function prototype):**
```cpp
int add(int a, int b);  // Function prototype

int main() {
    int result = add(5, 3);  // Works
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
    double result = square(5.5);  // Loses precision
}
```

**Correct:**
```cpp
double square(double x) {
    return x * x;
}

int main() {
    double result = square(5.5);  // Correct
}
```

### Mistake 5: Modifying Parameters Without Reference

**Wrong:**
```cpp
void increment(int x) {
    x++;  // Only changes the copy
}

int main() {
    int num = 5;
    increment(num);
    // num is still 5
}
```

**Correct:**
```cpp
void increment(int &x) {  // Use reference
    x++;
}

int main() {
    int num = 5;
    increment(num);
    // num is now 6
}
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

void convertMinutes(int totalMinutes) {
    int hours = totalMinutes / 60;
    int minutes = totalMinutes % 60;
    
    cout << totalMinutes << " minutes = " << hours << " hours and " 
         << minutes << " minutes" << endl;
}

int main() {
    convertMinutes(150);
    convertMinutes(90);
    convertMinutes(45);
    
    return 0;
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

int main() {
    int year = 2024;
    
    if (isLeapYear(year)) {
        cout << year << " is a leap year" << endl;
    } else {
        cout << year << " is not a leap year" << endl;
    }
    
    return 0;
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

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    cout << "GCD(48, 18) = " << gcd(48, 18) << endl;
    cout << "GCD(100, 35) = " << gcd(100, 35) << endl;
    
    return 0;
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

int reverseNumber(int num) {
    int reversed = 0;
    
    while (num > 0) {
        int digit = num % 10;
        reversed = reversed * 10 + digit;
        num /= 10;
    }
    
    return reversed;
}

int main() {
    cout << "Reverse of 1234: " << reverseNumber(1234) << endl;
    cout << "Reverse of 9876: " << reverseNumber(9876) << endl;
    
    return 0;
}
```
</details>

---

### Exercise 5: Calculate Mean of Array

Write a function that calculates the mean (average) of an array of numbers.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

double calculateMean(int arr[], int size) {
    int sum = 0;
    
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    
    return sum / (double)size;
}

int main() {
    int numbers[] = {10, 20, 30, 40, 50};
    int size = 5;
    
    double mean = calculateMean(numbers, size);
    cout << "Mean: " << mean << endl;
    
    return 0;
}
```
</details>

---

### Exercise 6: Print Fibonacci Sequence

Write a function that prints the first n Fibonacci numbers.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

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

int main() {
    cout << "First 10 Fibonacci numbers: ";
    printFibonacci(10);
    
    return 0;
}
```
</details>

---

### Exercise 7: Count Vowels

Write a function that counts the number of vowels in a string.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
#include <string>
using namespace std;

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

int main() {
    string text = "Hello World";
    cout << "Vowels in '" << text << "': " << countVowels(text) << endl;
    
    return 0;
}
```
</details>

---

### Exercise 8: Check Palindrome Number

Write a function that checks if a number is a palindrome.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

bool isPalindrome(int num) {
    int original = num;
    int reversed = 0;
    
    while (num > 0) {
        reversed = reversed * 10 + (num % 10);
        num /= 10;
    }
    
    return original == reversed;
}

int main() {
    cout << "12321 is palindrome: " << isPalindrome(12321) << endl;
    cout << "12345 is palindrome: " << isPalindrome(12345) << endl;
    
    return 0;
}
```
</details>

---

### Exercise 9: Find Minimum in Array

Write a function that finds the minimum value in an array.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int findMin(int arr[], int size) {
    int min = arr[0];
    
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    
    return min;
}

int main() {
    int numbers[] = {45, 12, 67, 23, 8, 91};
    int size = 6;
    
    cout << "Minimum: " << findMin(numbers, size) << endl;
    
    return 0;
}
```
</details>

---

### Exercise 10: Calculate Compound Interest

Write a function that calculates compound interest.

Formula: A = P(1 + r/n)^(nt)
- P = principal
- r = annual rate
- n = compounds per year
- t = years

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
#include <cmath>
using namespace std;

double compoundInterest(double principal, double rate, int compounds, int years) {
    double amount = principal * pow(1 + rate/compounds, compounds * years);
    return amount - principal;  // Return interest only
}

int main() {
    double p = 1000;
    double r = 0.05;  // 5%
    int n = 4;        // Quarterly
    int t = 10;       // 10 years
    
    double interest = compoundInterest(p, r, n, t);
    cout << "Compound interest: $" << interest << endl;
    
    return 0;
}
```
</details>

---

## Summary

### What We Learned Today

- **Functions** - Reusable blocks of code
- **Function syntax** - Return type, name, parameters, body
- **Parameters** - Passing values to functions
- **Return values** - Getting results from functions
- **Pass by value** - Function gets a copy
- **Pass by reference** - Function gets the original (use &)
- **Function overloading** - Same name, different parameters
- **Default parameters** - Optional parameter values

---

## Key Takeaways

1. **Functions organize code** - Break complex programs into manageable pieces
2. **DRY principle** - Do not Repeat Yourself (use functions instead)
3. **Return type matters** - Use void if no return value
4. **Pass by reference** - Use & when you want to modify the original
5. **Function prototypes** - Declare functions before use or define before main
6. **Descriptive names** - Function names should describe what they do

---

## Next Lecture Preview

In the next lecture, we will learn about:
- Arrays in detail
- Working with array elements
- Passing arrays to functions
- Multi-dimensional arrays
- Common array algorithms

---

## Homework

**Assignment 1:** Write a program with functions to calculate the area and perimeter of different shapes (circle, rectangle, triangle). Use function overloading where appropriate.

**Assignment 2:** Create a function that takes a string and returns it reversed. Then create another function that checks if a string is a palindrome using the reverse function.

**Assignment 3:** Write a program with a function that takes an array of integers and uses pass-by-reference to sort the array in ascending order using any sorting algorithm.

---

## Resources

- [cppreference.com - Functions](https://en.cppreference.com/w/cpp/language/functions)
- [cppreference.com - Function overloading](https://en.cppreference.com/w/cpp/language/overload_resolution)
- [learncpp.com - Functions](https://www.learncpp.com/cpp-tutorial/introduction-to-functions/)

---

**Functions are fundamental to good programming.** Master them to write clean, maintainable code.
