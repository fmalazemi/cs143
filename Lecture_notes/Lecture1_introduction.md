# Lecture 4: Loops in C++

## Welcome

In previous lectures, you learned how to write programs that execute once from top to bottom. Now you will learn how to make your programs repeat tasks automatically using loops.

**Remember from Python:** You already know the concept of loops. Now you will learn the C++ syntax.

---

## Table of Contents

1. [What Are Loops?](#what-are-loops)
2. [Why We Need Loops](#why-we-need-loops)
3. [The for Loop](#the-for-loop)
   - [Syntax](#for-loop-syntax)
   - [How It Works](#how-for-loop-works)
   - [Examples](#for-loop-examples)
4. [The while Loop](#the-while-loop)
   - [Syntax](#while-loop-syntax)
   - [How It Works](#how-while-loop-works)
   - [Examples](#while-loop-examples)
5. [for vs while: When to Use Each](#for-vs-while)
6. [Common Mistakes](#common-mistakes)
7. [Practice Exercises](#practice-exercises)
8. [Summary](#summary)

---

## What Are Loops?

Loops allow your program to execute the same code multiple times without writing it repeatedly.

**Real-world example:**
```
Count from 1 to 10:
Say "1"
Say "2"
Say "3"
...
Say "10"
```

This is repetitive. With loops, you write the instruction once and the computer repeats it.

### Python vs C++ Syntax

**Python:**
```python
for i in range(5):
    print(i)
```

**C++:**
```cpp
for (int i = 0; i < 5; i++) {
    cout << i << endl;
}
```

**Key differences:**
- C++ uses parentheses `( )` after `for`
- C++ uses curly braces `{ }` for the loop body
- C++ requires semicolons `;` in the for statement
- C++ loop counter starts at 0 by default

---

## Why We Need Loops

Without loops, you would need to write repetitive code:

```cpp
// Without loops - NOT recommended
cout << "1" << endl;
cout << "2" << endl;
cout << "3" << endl;
cout << "4" << endl;
cout << "5" << endl;
```

With loops, you write it once:

```cpp
// With loops - MUCH better
for (int i = 1; i <= 5; i++) {
    cout << i << endl;
}
```

**Benefits of loops:**
- Write less code
- Easy to change (change one line instead of many)
- Can handle unknown number of repetitions
- Makes code more readable

---

## The for Loop

The `for` loop is used when you know how many times you want to repeat something.

### for Loop Syntax

```cpp
for (initialization; condition; update) {
    // Code to repeat
}
```

**Parts of a for loop:**
1. **Initialization** - Runs once at the start
2. **Condition** - Checked before each iteration
3. **Update** - Runs after each iteration
4. **Body** - Code that repeats

### How for Loop Works

```cpp
for (int i = 0; i < 5; i++) {
    cout << i << endl;
}
```

**Step by step:**
1. **Initialization:** `int i = 0` - Create variable i, set to 0
2. **Condition check:** `i < 5` - Is 0 less than 5? Yes
3. **Execute body:** Print 0
4. **Update:** `i++` - Increase i to 1
5. **Condition check:** `i < 5` - Is 1 less than 5? Yes
6. **Execute body:** Print 1
7. **Update:** `i++` - Increase i to 2
8. Continue until condition is false

**Output:**
```
0
1
2
3
4
```

### for Loop Examples

#### Example 1: Count from 1 to 10

```cpp
#include <iostream>
using namespace std;

int main() {
    for (int i = 1; i <= 10; i++) {
        cout << i << endl;
    }
    
    return 0;
}
```

**Output:**
```
1
2
3
4
5
6
7
8
9
10
```

#### Example 2: Count by 2s

```cpp
#include <iostream>
using namespace std;

int main() {
    for (int i = 0; i <= 20; i = i + 2) {
        cout << i << " ";
    }
    cout << endl;
    
    return 0;
}
```

**Output:**
```
0 2 4 6 8 10 12 14 16 18 20
```

#### Example 3: Count Backwards

```cpp
#include <iostream>
using namespace std;

int main() {
    for (int i = 10; i >= 1; i--) {
        cout << i << " ";
    }
    cout << "Launch!" << endl;
    
    return 0;
}
```

**Output:**
```
10 9 8 7 6 5 4 3 2 1 Launch!
```

#### Example 4: Sum of Numbers

```cpp
#include <iostream>
using namespace std;

int main() {
    int sum = 0;
    
    for (int i = 1; i <= 100; i++) {
        sum = sum + i;
    }
    
    cout << "Sum of 1 to 100 is: " << sum << endl;
    
    return 0;
}
```

**Output:**
```
Sum of 1 to 100 is: 5050
```

#### Example 5: Multiplication Table

```cpp
#include <iostream>
using namespace std;

int main() {
    int number = 5;
    
    cout << "Multiplication table for " << number << endl;
    
    for (int i = 1; i <= 10; i++) {
        cout << number << " x " << i << " = " << (number * i) << endl;
    }
    
    return 0;
}
```

**Output:**
```
Multiplication table for 5
5 x 1 = 5
5 x 2 = 10
5 x 3 = 15
5 x 4 = 20
5 x 5 = 25
5 x 6 = 30
5 x 7 = 35
5 x 8 = 40
5 x 9 = 45
5 x 10 = 50
```

#### Example 6: Print Stars

```cpp
#include <iostream>
using namespace std;

int main() {
    for (int i = 1; i <= 5; i++) {
        cout << "* ";
    }
    cout << endl;
    
    return 0;
}
```

**Output:**
```
* * * * *
```

#### Example 7: User Input Loop

```cpp
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "How many times should I greet you? ";
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        cout << "Hello! (Greeting " << i << ")" << endl;
    }
    
    return 0;
}
```

**Sample Run:**
```
How many times should I greet you? 3
Hello! (Greeting 1)
Hello! (Greeting 2)
Hello! (Greeting 3)
```

#### Example 8: Calculate Average

```cpp
#include <iostream>
using namespace std;

int main() {
    int sum = 0;
    int count = 5;
    
    cout << "Enter " << count << " numbers:" << endl;
    
    for (int i = 1; i <= count; i++) {
        int number;
        cout << "Number " << i << ": ";
        cin >> number;
        sum = sum + number;
    }
    
    double average = sum / (double)count;
    cout << "Average: " << average << endl;
    
    return 0;
}
```

**Sample Run:**
```
Enter 5 numbers:
Number 1: 10
Number 2: 20
Number 3: 30
Number 4: 40
Number 5: 50
Average: 30
```

---

## The while Loop

The `while` loop is used when you do not know in advance how many times you need to repeat. It continues as long as a condition is true.

### while Loop Syntax

```cpp
while (condition) {
    // Code to repeat
}
```

**Parts of a while loop:**
1. **Condition** - Checked before each iteration
2. **Body** - Code that repeats

### How while Loop Works

```cpp
int i = 0;
while (i < 5) {
    cout << i << endl;
    i++;
}
```

**Step by step:**
1. **Condition check:** `i < 5` - Is 0 less than 5? Yes
2. **Execute body:** Print 0, then increase i to 1
3. **Condition check:** `i < 5` - Is 1 less than 5? Yes
4. **Execute body:** Print 1, then increase i to 2
5. Continue until condition is false

**Output:**
```
0
1
2
3
4
```

**Important:** You must update the variable inside the loop, or the loop will run forever.

### while Loop Examples

#### Example 1: Count from 1 to 10

```cpp
#include <iostream>
using namespace std;

int main() {
    int i = 1;
    
    while (i <= 10) {
        cout << i << endl;
        i++;
    }
    
    return 0;
}
```

**Output:**
```
1
2
3
4
5
6
7
8
9
10
```

#### Example 2: Sum Until Zero

```cpp
#include <iostream>
using namespace std;

int main() {
    int sum = 0;
    int number;
    
    cout << "Enter numbers (0 to stop):" << endl;
    cin >> number;
    
    while (number != 0) {
        sum = sum + number;
        cin >> number;
    }
    
    cout << "Total sum: " << sum << endl;
    
    return 0;
}
```

**Sample Run:**
```
Enter numbers (0 to stop):
5
10
15
0
Total sum: 30
```

#### Example 3: Guess the Number

```cpp
#include <iostream>
using namespace std;

int main() {
    int secret = 7;
    int guess;
    
    cout << "Guess the number (1-10): ";
    cin >> guess;
    
    while (guess != secret) {
        cout << "Wrong! Try again: ";
        cin >> guess;
    }
    
    cout << "Correct! The number was " << secret << endl;
    
    return 0;
}
```

**Sample Run:**
```
Guess the number (1-10): 3
Wrong! Try again: 5
Wrong! Try again: 7
Correct! The number was 7
```

#### Example 4: Countdown

```cpp
#include <iostream>
using namespace std;

int main() {
    int counter = 5;
    
    while (counter > 0) {
        cout << counter << "..." << endl;
        counter--;
    }
    
    cout << "Go!" << endl;
    
    return 0;
}
```

**Output:**
```
5...
4...
3...
2...
1...
Go!
```

#### Example 5: Validate Input

```cpp
#include <iostream>
using namespace std;

int main() {
    int age;
    
    cout << "Enter your age (1-120): ";
    cin >> age;
    
    while (age < 1 || age > 120) {
        cout << "Invalid age. Enter again (1-120): ";
        cin >> age;
    }
    
    cout << "Thank you. Your age is " << age << endl;
    
    return 0;
}
```

**Sample Run:**
```
Enter your age (1-120): 150
Invalid age. Enter again (1-120): -5
Invalid age. Enter again (1-120): 25
Thank you. Your age is 25
```

#### Example 6: Menu System

```cpp
#include <iostream>
using namespace std;

int main() {
    int choice = 0;
    
    while (choice != 4) {
        cout << "\nMenu:" << endl;
        cout << "1. Option A" << endl;
        cout << "2. Option B" << endl;
        cout << "3. Option C" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        
        if (choice == 1) {
            cout << "You selected Option A" << endl;
        } else if (choice == 2) {
            cout << "You selected Option B" << endl;
        } else if (choice == 3) {
            cout << "You selected Option C" << endl;
        } else if (choice == 4) {
            cout << "Goodbye!" << endl;
        } else {
            cout << "Invalid choice" << endl;
        }
    }
    
    return 0;
}
```

#### Example 7: Keep Doubling

```cpp
#include <iostream>
using namespace std;

int main() {
    int number = 1;
    
    while (number < 1000) {
        cout << number << " ";
        number = number * 2;
    }
    cout << endl;
    
    return 0;
}
```

**Output:**
```
1 2 4 8 16 32 64 128 256 512
```

#### Example 8: Count Digits

```cpp
#include <iostream>
using namespace std;

int main() {
    int number;
    int count = 0;
    
    cout << "Enter a number: ";
    cin >> number;
    
    int temp = number;
    
    while (temp > 0) {
        count++;
        temp = temp / 10;
    }
    
    cout << "Number of digits: " << count << endl;
    
    return 0;
}
```

**Sample Run:**
```
Enter a number: 12345
Number of digits: 5
```

---

## for vs while

### When to Use for Loop

Use `for` loop when:
- You know the exact number of iterations
- You are counting with a counter variable
- You need to iterate through a sequence

**Examples:**
- Print numbers 1 to 100
- Calculate sum of first N numbers
- Print multiplication table
- Process array elements (future topic)

### When to Use while Loop

Use `while` loop when:
- You do not know how many iterations are needed
- The loop continues until a condition changes
- You are waiting for user input

**Examples:**
- Input validation (until user enters valid data)
- Menu systems (until user chooses exit)
- Reading data until end marker
- Game loops (until player wins or quits)

### Converting Between for and while

Any `for` loop can be written as a `while` loop:

**for loop:**
```cpp
for (int i = 0; i < 5; i++) {
    cout << i << endl;
}
```

**Equivalent while loop:**
```cpp
int i = 0;
while (i < 5) {
    cout << i << endl;
    i++;
}
```

---

## Common Mistakes

### Mistake 1: Infinite Loop

**Wrong:**
```cpp
int i = 0;
while (i < 5) {
    cout << i << endl;
    // Forgot to update i
}
// Loop runs forever
```

**Correct:**
```cpp
int i = 0;
while (i < 5) {
    cout << i << endl;
    i++;  // Update the counter
}
```

### Mistake 2: Off-by-One Error

**Wrong:**
```cpp
// Trying to print 1 to 10, but only prints 1 to 9
for (int i = 1; i < 10; i++) {
    cout << i << " ";
}
```

**Correct:**
```cpp
// Correctly prints 1 to 10
for (int i = 1; i <= 10; i++) {
    cout << i << " ";
}
```

### Mistake 3: Semicolon After for

**Wrong:**
```cpp
for (int i = 0; i < 5; i++);  // Semicolon here
{
    cout << i << endl;  // This is not part of the loop
}
```

**Correct:**
```cpp
for (int i = 0; i < 5; i++) {  // No semicolon
    cout << i << endl;
}
```

### Mistake 4: Wrong Update

**Wrong:**
```cpp
// Trying to count down, but using i++
for (int i = 10; i >= 1; i++) {
    cout << i << " ";
}
// This is an infinite loop
```

**Correct:**
```cpp
for (int i = 10; i >= 1; i--) {
    cout << i << " ";
}
```

### Mistake 5: Forgetting Curly Braces

**Wrong:**
```cpp
for (int i = 1; i <= 5; i++)
    cout << i << " ";
    cout << "End" << endl;  // This only runs once, not in the loop
```

**Correct:**
```cpp
for (int i = 1; i <= 5; i++) {
    cout << i << " ";
    cout << "End" << endl;  // Now both lines are in the loop
}
```

---

## Practice Exercises

### Exercise 1: Print Even Numbers

Write a program that prints all even numbers from 2 to 20.

**Expected Output:**
```
2 4 6 8 10 12 14 16 18 20
```

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    for (int i = 2; i <= 20; i = i + 2) {
        cout << i << " ";
    }
    cout << endl;
    
    return 0;
}
```
</details>

---

### Exercise 2: Sum of Odd Numbers

Write a program that calculates the sum of all odd numbers from 1 to 50.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int sum = 0;
    
    for (int i = 1; i <= 50; i = i + 2) {
        sum = sum + i;
    }
    
    cout << "Sum of odd numbers from 1 to 50: " << sum << endl;
    
    return 0;
}
```
</details>

---

### Exercise 3: Factorial

Write a program that calculates the factorial of a number entered by the user.

Factorial of 5 = 5 × 4 × 3 × 2 × 1 = 120

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int n;
    int factorial = 1;
    
    cout << "Enter a number: ";
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        factorial = factorial * i;
    }
    
    cout << "Factorial of " << n << " is " << factorial << endl;
    
    return 0;
}
```
</details>

---

### Exercise 4: Power Function

Write a program that calculates base raised to power (base^power) without using built-in functions.

Example: 2^3 = 2 × 2 × 2 = 8

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int base, power;
    int result = 1;
    
    cout << "Enter base: ";
    cin >> base;
    cout << "Enter power: ";
    cin >> power;
    
    for (int i = 1; i <= power; i++) {
        result = result * base;
    }
    
    cout << base << "^" << power << " = " << result << endl;
    
    return 0;
}
```
</details>

---

### Exercise 5: Print Rectangle

Write a program that prints a rectangle of stars. Ask user for width and height.

**Example Output (width=5, height=3):**
```
*****
*****
*****
```

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int width, height;
    
    cout << "Enter width: ";
    cin >> width;
    cout << "Enter height: ";
    cin >> height;
    
    for (int i = 1; i <= height; i++) {
        for (int j = 1; j <= width; j++) {
            cout << "*";
        }
        cout << endl;
    }
    
    return 0;
}
```
</details>

---

### Exercise 6: Find Maximum

Write a program that asks the user to enter 5 numbers and finds the maximum.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int max = 0;
    int number;
    
    cout << "Enter 5 numbers:" << endl;
    
    for (int i = 1; i <= 5; i++) {
        cout << "Number " << i << ": ";
        cin >> number;
        
        if (i == 1 || number > max) {
            max = number;
        }
    }
    
    cout << "Maximum number: " << max << endl;
    
    return 0;
}
```
</details>

---

### Exercise 7: Reverse Digits

Write a program that reverses the digits of a number.

Example: Input 1234, Output 4321

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int number, reversed = 0;
    
    cout << "Enter a number: ";
    cin >> number;
    
    while (number > 0) {
        int digit = number % 10;
        reversed = reversed * 10 + digit;
        number = number / 10;
    }
    
    cout << "Reversed number: " << reversed << endl;
    
    return 0;
}
```
</details>

---

### Exercise 8: Print Triangle

Write a program that prints a triangle of stars. Ask user for the number of rows.

**Example Output (rows=5):**
```
*
**
***
****
*****
```

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int rows;
    
    cout << "Enter number of rows: ";
    cin >> rows;
    
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }
    
    return 0;
}
```
</details>

---

### Exercise 9: Prime Number Check

Write a program that checks if a number is prime.

A prime number is divisible only by 1 and itself.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int number;
    bool isPrime = true;
    
    cout << "Enter a number: ";
    cin >> number;
    
    if (number <= 1) {
        isPrime = false;
    } else {
        for (int i = 2; i < number; i++) {
            if (number % i == 0) {
                isPrime = false;
                break;
            }
        }
    }
    
    if (isPrime) {
        cout << number << " is a prime number" << endl;
    } else {
        cout << number << " is not a prime number" << endl;
    }
    
    return 0;
}
```
</details>

---

### Exercise 10: Fibonacci Sequence

Write a program that prints the first N numbers in the Fibonacci sequence.

Fibonacci: 0, 1, 1, 2, 3, 5, 8, 13, 21...
(Each number is the sum of the previous two)

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int n;
    
    cout << "How many Fibonacci numbers? ";
    cin >> n;
    
    int first = 0, second = 1;
    
    for (int i = 1; i <= n; i++) {
        cout << first << " ";
        
        int next = first + second;
        first = second;
        second = next;
    }
    cout << endl;
    
    return 0;
}
```
</details>

---

### Exercise 11: GCD Calculator

Write a program that finds the Greatest Common Divisor (GCD) of two numbers.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int a, b;
    
    cout << "Enter first number: ";
    cin >> a;
    cout << "Enter second number: ";
    cin >> b;
    
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    
    cout << "GCD: " << a << endl;
    
    return 0;
}
```
</details>

---

### Exercise 12: Number Pattern

Write a program that prints this pattern (N rows):

```
1
12
123
1234
12345
```

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int n;
    
    cout << "Enter number of rows: ";
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << j;
        }
        cout << endl;
    }
    
    return 0;
}
```
</details>

---

### Exercise 13: Sum of Digits

Write a program that calculates the sum of digits of a number.

Example: 1234 → 1+2+3+4 = 10

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int number, sum = 0;
    
    cout << "Enter a number: ";
    cin >> number;
    
    int temp = number;
    
    while (temp > 0) {
        sum = sum + (temp % 10);
        temp = temp / 10;
    }
    
    cout << "Sum of digits: " << sum << endl;
    
    return 0;
}
```
</details>

---

### Exercise 14: Perfect Number

Write a program that checks if a number is perfect.

A perfect number equals the sum of its divisors (excluding itself).
Example: 6 = 1 + 2 + 3

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int number, sum = 0;
    
    cout << "Enter a number: ";
    cin >> number;
    
    for (int i = 1; i < number; i++) {
        if (number % i == 0) {
            sum = sum + i;
        }
    }
    
    if (sum == number) {
        cout << number << " is a perfect number" << endl;
    } else {
        cout << number << " is not a perfect number" << endl;
    }
    
    return 0;
}
```
</details>

---

### Exercise 15: Palindrome Check

Write a program that checks if a number is a palindrome.

A palindrome reads the same forwards and backwards.
Example: 12321 is a palindrome

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int number, reversed = 0;
    
    cout << "Enter a number: ";
    cin >> number;
    
    int original = number;
    
    while (number > 0) {
        reversed = reversed * 10 + (number % 10);
        number = number / 10;
    }
    
    if (original == reversed) {
        cout << original << " is a palindrome" << endl;
    } else {
        cout << original << " is not a palindrome" << endl;
    }
    
    return 0;
}
```
</details>

---

## Summary

### What We Learned Today

- **for loops** - Used when you know the number of iterations
- **while loops** - Used when you do not know the number of iterations
- **Loop syntax** - How to write loops correctly
- **Common mistakes** - Infinite loops, off-by-one errors
- **Practical examples** - Many real-world applications

---

## Key Takeaways

1. **for loop structure:** `for (init; condition; update) { }`
2. **while loop structure:** `while (condition) { }`
3. **Always update** the counter in while loops
4. **Use for** when counting with numbers
5. **Use while** when waiting for a condition
6. **Test edge cases** - Make sure loops start and stop correctly

---

## Next Lecture Preview

In the next lecture, we will learn about:
- Nested loops (loops inside loops)
- The do-while loop
- Loop control statements (break and continue)
- Advanced loop patterns

---

## Homework

**Assignment 1:** Write a program that prints all numbers from 1 to 100, but:
- Print "Fizz" for multiples of 3
- Print "Buzz" for multiples of 5
- Print "FizzBuzz" for multiples of both 3 and 5

**Assignment 2:** Write a program that implements a simple calculator that keeps running until the user chooses to exit. Use a while loop.

**Assignment 3:** Write a program that prints all prime numbers between 1 and 100.

---

## Resources

- [cppreference.com - for statement](https://en.cppreference.com/w/cpp/language/for)
- [cppreference.com - while statement](https://en.cppreference.com/w/cpp/language/while)
- [learncpp.com - Loops](https://www.learncpp.com/cpp-tutorial/introduction-to-loops-and-while-statements/)

---

**Practice is essential.** Complete all exercises to master loops.
