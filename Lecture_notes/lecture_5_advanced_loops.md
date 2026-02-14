# Lecture 5: Advanced Loops in C++

## Welcome

In the previous lecture, you learned about for loops and while loops. Now you will learn advanced loop techniques that give you more control over program flow.

**Topics covered today:**
- Nested loops (loops inside loops)
- The do-while loop
- Loop control statements (break and continue)
- Advanced loop patterns

---

## Table of Contents

1. [Nested Loops](#nested-loops)
   - [What Are Nested Loops?](#what-are-nested-loops)
   - [Nested for Loops](#nested-for-loops)
   - [Examples](#nested-loop-examples)
2. [The do-while Loop](#the-do-while-loop)
   - [Syntax](#do-while-syntax)
   - [do-while vs while](#do-while-vs-while)
   - [Examples](#do-while-examples)
3. [The break Statement](#the-break-statement)
   - [How break Works](#how-break-works)
   - [Examples](#break-examples)
4. [The continue Statement](#the-continue-statement)
   - [How continue Works](#how-continue-works)
   - [Examples](#continue-examples)
5. [Practice Exercises](#practice-exercises)
6. [Summary](#summary)

---

## Nested Loops

### What Are Nested Loops?

A nested loop is a loop inside another loop. The inner loop completes all its iterations for each iteration of the outer loop.

**Structure:**
```cpp
for (outer loop) {
    for (inner loop) {
        // Code here runs for every combination
    }
}
```

**How it works:**
- Outer loop runs once
- Inner loop runs completely
- Outer loop runs again
- Inner loop runs completely again
- This continues until outer loop finishes

### Nested for Loops

**Basic syntax:**
```cpp
for (int i = 1; i <= 3; i++) {
    for (int j = 1; j <= 2; j++) {
        cout << "i=" << i << " j=" << j << endl;
    }
}
```

**Output:**
```
i=1 j=1
i=1 j=2
i=2 j=1
i=2 j=2
i=3 j=1
i=3 j=2
```

**Explanation:**
- When i=1, j goes from 1 to 2
- When i=2, j goes from 1 to 2 again
- When i=3, j goes from 1 to 2 again

### Nested Loop Examples

#### Example 1: Multiplication Table

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Multiplication Table (1-10):" << endl;
    
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            cout << i * j << "\t";
        }
        cout << endl;
    }
    
    return 0;
}
```

**Output:**
```
1    2    3    4    5    6    7    8    9    10
2    4    6    8    10   12   14   16   18   20
3    6    9    12   15   18   21   24   27   30
...
```

#### Example 2: Rectangle of Stars

```cpp
#include <iostream>
using namespace std;

int main() {
    int rows = 5;
    int cols = 8;
    
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= cols; j++) {
            cout << "* ";
        }
        cout << endl;
    }
    
    return 0;
}
```

**Output:**
```
* * * * * * * *
* * * * * * * *
* * * * * * * *
* * * * * * * *
* * * * * * * *
```

#### Example 3: Right Triangle Pattern

```cpp
#include <iostream>
using namespace std;

int main() {
    int rows = 5;
    
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
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

#### Example 4: Inverted Triangle

```cpp
#include <iostream>
using namespace std;

int main() {
    int rows = 5;
    
    for (int i = rows; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
    
    return 0;
}
```

**Output:**
```
* * * * *
* * * *
* * *
* *
*
```

#### Example 5: Number Pattern

```cpp
#include <iostream>
using namespace std;

int main() {
    int rows = 5;
    
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }
        cout << endl;
    }
    
    return 0;
}
```

**Output:**
```
1
1 2
1 2 3
1 2 3 4
1 2 3 4 5
```

#### Example 6: Pyramid Pattern

```cpp
#include <iostream>
using namespace std;

int main() {
    int rows = 5;
    
    for (int i = 1; i <= rows; i++) {
        // Print spaces
        for (int j = 1; j <= rows - i; j++) {
            cout << "  ";
        }
        // Print stars
        for (int k = 1; k <= 2 * i - 1; k++) {
            cout << "* ";
        }
        cout << endl;
    }
    
    return 0;
}
```

**Output:**
```
        *
      * * *
    * * * * *
  * * * * * * *
* * * * * * * * *
```

#### Example 7: Nested Loop with User Input

```cpp
#include <iostream>
using namespace std;

int main() {
    int students, assignments;
    
    cout << "Enter number of students: ";
    cin >> students;
    cout << "Enter number of assignments: ";
    cin >> assignments;
    
    for (int i = 1; i <= students; i++) {
        cout << "Student " << i << " grades:" << endl;
        int total = 0;
        
        for (int j = 1; j <= assignments; j++) {
            int grade;
            cout << "  Assignment " << j << ": ";
            cin >> grade;
            total += grade;
        }
        
        double average = total / (double)assignments;
        cout << "  Average: " << average << endl << endl;
    }
    
    return 0;
}
```

**Sample Run:**
```
Enter number of students: 2
Enter number of assignments: 3
Student 1 grades:
  Assignment 1: 80
  Assignment 2: 90
  Assignment 3: 85
  Average: 85

Student 2 grades:
  Assignment 1: 75
  Assignment 2: 88
  Assignment 3: 92
  Average: 85
```

#### Example 8: Find Prime Numbers in Range

```cpp
#include <iostream>
using namespace std;

int main() {
    int start, end;
    
    cout << "Enter range (start end): ";
    cin >> start >> end;
    
    cout << "Prime numbers between " << start << " and " << end << ":" << endl;
    
    for (int num = start; num <= end; num++) {
        if (num < 2) continue;
        
        bool isPrime = true;
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                isPrime = false;
                break;
            }
        }
        
        if (isPrime) {
            cout << num << " ";
        }
    }
    cout << endl;
    
    return 0;
}
```

**Sample Run:**
```
Enter range (start end): 10 30
Prime numbers between 10 and 30:
11 13 17 19 23 29
```

---

## The do-while Loop

### do-while Syntax

The do-while loop is similar to the while loop, but it always executes at least once because the condition is checked after the loop body.

**Syntax:**
```cpp
do {
    // Code to execute
} while (condition);
```

**Important:** Notice the semicolon after the condition.

### How do-while Works

```cpp
int i = 0;
do {
    cout << i << endl;
    i++;
} while (i < 5);
```

**Execution:**
1. Execute the code block (print 0, i becomes 1)
2. Check condition: i < 5? Yes
3. Execute the code block (print 1, i becomes 2)
4. Check condition: i < 5? Yes
5. Continue until condition is false

**Output:**
```
0
1
2
3
4
```

### do-while vs while

**Key difference:** do-while executes at least once, while might not execute at all.

**Example showing the difference:**

```cpp
// while loop
int x = 10;
while (x < 5) {
    cout << "This will not print" << endl;
}
// Loop body never executes

// do-while loop
int y = 10;
do {
    cout << "This will print once" << endl;
} while (y < 5);
// Loop body executes once, then stops
```

### do-while Examples

#### Example 1: Menu System

```cpp
#include <iostream>
using namespace std;

int main() {
    int choice;
    
    do {
        cout << "\n=== Menu ===" << endl;
        cout << "1. Option A" << endl;
        cout << "2. Option B" << endl;
        cout << "3. Option C" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                cout << "You selected Option A" << endl;
                break;
            case 2:
                cout << "You selected Option B" << endl;
                break;
            case 3:
                cout << "You selected Option C" << endl;
                break;
            case 4:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    } while (choice != 4);
    
    return 0;
}
```

#### Example 2: Input Validation

```cpp
#include <iostream>
using namespace std;

int main() {
    int age;
    
    do {
        cout << "Enter your age (1-120): ";
        cin >> age;
        
        if (age < 1 || age > 120) {
            cout << "Invalid age. Try again." << endl;
        }
    } while (age < 1 || age > 120);
    
    cout << "Thank you. Your age is " << age << endl;
    
    return 0;
}
```

#### Example 3: Guessing Game

```cpp
#include <iostream>
using namespace std;

int main() {
    int secret = 42;
    int guess;
    int attempts = 0;
    
    cout << "Guess the number (1-100):" << endl;
    
    do {
        cout << "Enter guess: ";
        cin >> guess;
        attempts++;
        
        if (guess < secret) {
            cout << "Too low!" << endl;
        } else if (guess > secret) {
            cout << "Too high!" << endl;
        }
    } while (guess != secret);
    
    cout << "Correct! You guessed it in " << attempts << " attempts." << endl;
    
    return 0;
}
```

#### Example 4: ATM Simulation

```cpp
#include <iostream>
using namespace std;

int main() {
    double balance = 1000.00;
    int choice;
    
    do {
        cout << "\n=== ATM ===" << endl;
        cout << "1. Check Balance" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. Exit" << endl;
        cout << "Choice: ";
        cin >> choice;
        
        if (choice == 1) {
            cout << "Balance: $" << balance << endl;
        } else if (choice == 2) {
            double amount;
            cout << "Deposit amount: $";
            cin >> amount;
            if (amount > 0) {
                balance += amount;
                cout << "Deposited $" << amount << endl;
            }
        } else if (choice == 3) {
            double amount;
            cout << "Withdraw amount: $";
            cin >> amount;
            if (amount > 0 && amount <= balance) {
                balance -= amount;
                cout << "Withdrew $" << amount << endl;
            } else {
                cout << "Invalid amount" << endl;
            }
        }
    } while (choice != 4);
    
    cout << "Thank you for using ATM" << endl;
    
    return 0;
}
```

#### Example 5: Play Again Loop

```cpp
#include <iostream>
using namespace std;

int main() {
    char playAgain;
    
    do {
        cout << "\n=== Simple Game ===" << endl;
        cout << "Playing the game..." << endl;
        cout << "You won!" << endl;
        
        cout << "Play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');
    
    cout << "Thanks for playing!" << endl;
    
    return 0;
}
```

---

## The break Statement

### How break Works

The `break` statement immediately exits the loop, regardless of the loop condition.

**Syntax:**
```cpp
while (condition) {
    if (some_condition) {
        break;  // Exit loop immediately
    }
}
```

**When to use break:**
- Exit a loop early when a condition is met
- Search loops (stop when item is found)
- Error handling (exit on invalid input)

### break Examples

#### Example 1: Search for a Number

```cpp
#include <iostream>
using namespace std;

int main() {
    int numbers[] = {5, 12, 7, 23, 9, 15, 3};
    int target = 23;
    bool found = false;
    
    for (int i = 0; i < 7; i++) {
        if (numbers[i] == target) {
            cout << "Found " << target << " at position " << i << endl;
            found = true;
            break;  // Stop searching
        }
    }
    
    if (!found) {
        cout << target << " not found" << endl;
    }
    
    return 0;
}
```

**Output:**
```
Found 23 at position 3
```

#### Example 2: Exit on Negative Number

```cpp
#include <iostream>
using namespace std;

int main() {
    int number;
    int sum = 0;
    
    cout << "Enter numbers (negative to stop):" << endl;
    
    while (true) {  // Infinite loop
        cin >> number;
        
        if (number < 0) {
            break;  // Exit loop
        }
        
        sum += number;
    }
    
    cout << "Sum: " << sum << endl;
    
    return 0;
}
```

**Sample Run:**
```
Enter numbers (negative to stop):
5
10
15
-1
Sum: 30
```

#### Example 3: Find First Divisor

```cpp
#include <iostream>
using namespace std;

int main() {
    int number;
    
    cout << "Enter a number: ";
    cin >> number;
    
    cout << "First divisor (other than 1): ";
    
    for (int i = 2; i <= number; i++) {
        if (number % i == 0) {
            cout << i << endl;
            break;  // Found first divisor, stop
        }
    }
    
    return 0;
}
```

#### Example 4: Password Attempts

```cpp
#include <iostream>
using namespace std;

int main() {
    string correctPassword = "secret123";
    string password;
    int maxAttempts = 3;
    
    for (int i = 1; i <= maxAttempts; i++) {
        cout << "Enter password (Attempt " << i << "): ";
        cin >> password;
        
        if (password == correctPassword) {
            cout << "Access granted!" << endl;
            break;
        } else {
            cout << "Wrong password!" << endl;
            
            if (i == maxAttempts) {
                cout << "Account locked!" << endl;
            }
        }
    }
    
    return 0;
}
```

#### Example 5: Break in Nested Loops

```cpp
#include <iostream>
using namespace std;

int main() {
    bool found = false;
    
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            cout << "i=" << i << " j=" << j << endl;
            
            if (i * j == 6) {
                cout << "Found i*j = 6!" << endl;
                found = true;
                break;  // Exits inner loop only
            }
        }
        
        if (found) {
            break;  // Exits outer loop
        }
    }
    
    return 0;
}
```

**Note:** `break` only exits the innermost loop. To exit multiple loops, use a flag variable.

---

## The continue Statement

### How continue Works

The `continue` statement skips the rest of the current iteration and moves to the next iteration.

**Syntax:**
```cpp
for (int i = 0; i < 10; i++) {
    if (some_condition) {
        continue;  // Skip rest of this iteration
    }
    // This code is skipped when continue executes
}
```

**When to use continue:**
- Skip certain values in a loop
- Filter data
- Skip processing for special cases

### continue Examples

#### Example 1: Skip Even Numbers

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Odd numbers from 1 to 10:" << endl;
    
    for (int i = 1; i <= 10; i++) {
        if (i % 2 == 0) {
            continue;  // Skip even numbers
        }
        cout << i << " ";
    }
    cout << endl;
    
    return 0;
}
```

**Output:**
```
Odd numbers from 1 to 10:
1 3 5 7 9
```

#### Example 2: Skip Multiples of 3

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Numbers 1-20 (skip multiples of 3):" << endl;
    
    for (int i = 1; i <= 20; i++) {
        if (i % 3 == 0) {
            continue;  // Skip multiples of 3
        }
        cout << i << " ";
    }
    cout << endl;
    
    return 0;
}
```

**Output:**
```
Numbers 1-20 (skip multiples of 3):
1 2 4 5 7 8 10 11 13 14 16 17 19 20
```

#### Example 3: Skip Negative Numbers in Sum

```cpp
#include <iostream>
using namespace std;

int main() {
    int numbers[] = {5, -3, 10, -7, 8, 2, -1, 15};
    int sum = 0;
    
    for (int i = 0; i < 8; i++) {
        if (numbers[i] < 0) {
            continue;  // Skip negative numbers
        }
        sum += numbers[i];
    }
    
    cout << "Sum of positive numbers: " << sum << endl;
    
    return 0;
}
```

**Output:**
```
Sum of positive numbers: 40
```

#### Example 4: Process Valid Grades Only

```cpp
#include <iostream>
using namespace std;

int main() {
    int count = 0;
    int total = 0;
    
    cout << "Enter 5 grades (0-100, -1 to skip):" << endl;
    
    for (int i = 1; i <= 5; i++) {
        int grade;
        cout << "Grade " << i << ": ";
        cin >> grade;
        
        if (grade == -1) {
            continue;  // Skip this grade
        }
        
        if (grade < 0 || grade > 100) {
            cout << "Invalid grade, skipping..." << endl;
            continue;
        }
        
        total += grade;
        count++;
    }
    
    if (count > 0) {
        cout << "Average: " << total / (double)count << endl;
    }
    
    return 0;
}
```

#### Example 5: FizzBuzz with continue

```cpp
#include <iostream>
using namespace std;

int main() {
    for (int i = 1; i <= 30; i++) {
        if (i % 15 == 0) {
            cout << "FizzBuzz ";
            continue;
        }
        if (i % 3 == 0) {
            cout << "Fizz ";
            continue;
        }
        if (i % 5 == 0) {
            cout << "Buzz ";
            continue;
        }
        cout << i << " ";
    }
    cout << endl;
    
    return 0;
}
```

---

## Practice Exercises

### Exercise 1: Square Pattern

Write a program that prints a square pattern of given size.

**Example Output (size=4):**
```
* * * *
* * * *
* * * *
* * * *
```

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int size;
    
    cout << "Enter size: ";
    cin >> size;
    
    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= size; j++) {
            cout << "* ";
        }
        cout << endl;
    }
    
    return 0;
}
```
</details>

---

### Exercise 2: Hollow Rectangle

Write a program that prints a hollow rectangle.

**Example Output (rows=4, cols=6):**
```
* * * * * *
*         *
*         *
* * * * * *
```

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int rows, cols;
    
    cout << "Enter rows and cols: ";
    cin >> rows >> cols;
    
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= cols; j++) {
            if (i == 1 || i == rows || j == 1 || j == cols) {
                cout << "* ";
            } else {
                cout << "  ";
            }
        }
        cout << endl;
    }
    
    return 0;
}
```
</details>

---

### Exercise 3: Pascal's Triangle

Write a program that prints Pascal's triangle up to n rows.

**Example Output (n=5):**
```
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
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
    
    for (int i = 0; i < rows; i++) {
        int number = 1;
        for (int j = 0; j <= i; j++) {
            cout << number << " ";
            number = number * (i - j) / (j + 1);
        }
        cout << endl;
    }
    
    return 0;
}
```
</details>

---

### Exercise 4: Sum Until "STOP"

Write a program that keeps reading numbers and summing them until the user types "STOP".
Use a do-while loop.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    int sum = 0;
    
    do {
        cout << "Enter number (or STOP): ";
        cin >> input;
        
        if (input != "STOP") {
            sum += stoi(input);
        }
    } while (input != "STOP");
    
    cout << "Total sum: " << sum << endl;
    
    return 0;
}
```
</details>

---

### Exercise 5: Find All Divisors

Write a program that finds all divisors of a number. Use continue to skip non-divisors.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int number;
    
    cout << "Enter a number: ";
    cin >> number;
    
    cout << "Divisors of " << number << ": ";
    
    for (int i = 1; i <= number; i++) {
        if (number % i != 0) {
            continue;  // Skip non-divisors
        }
        cout << i << " ";
    }
    cout << endl;
    
    return 0;
}
```
</details>

---

### Exercise 6: Diamond Pattern

Write a program that prints a diamond pattern.

**Example Output (size=5):**
```
    *
   ***
  *****
 *******
*********
 *******
  *****
   ***
    *
```

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int n;
    
    cout << "Enter size: ";
    cin >> n;
    
    // Upper half
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i; j++) {
            cout << " ";
        }
        for (int k = 1; k <= 2 * i - 1; k++) {
            cout << "*";
        }
        cout << endl;
    }
    
    // Lower half
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 1; j <= n - i; j++) {
            cout << " ";
        }
        for (int k = 1; k <= 2 * i - 1; k++) {
            cout << "*";
        }
        cout << endl;
    }
    
    return 0;
}
```
</details>

---

### Exercise 7: Prime Factorization

Write a program that finds the prime factorization of a number.

**Example:** 60 = 2 × 2 × 3 × 5

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int number;
    
    cout << "Enter a number: ";
    cin >> number;
    
    cout << "Prime factors of " << number << ": ";
    
    for (int i = 2; i <= number; i++) {
        while (number % i == 0) {
            cout << i << " ";
            number = number / i;
        }
    }
    cout << endl;
    
    return 0;
}
```
</details>

---

### Exercise 8: Number Guessing with Limited Attempts

Create a number guessing game where the user has maximum 5 attempts. Use break to exit early if guessed correctly.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int secret = 73;
    int guess;
    int maxAttempts = 5;
    bool won = false;
    
    cout << "Guess the number (1-100):" << endl;
    
    for (int i = 1; i <= maxAttempts; i++) {
        cout << "Attempt " << i << ": ";
        cin >> guess;
        
        if (guess == secret) {
            cout << "Correct! You won!" << endl;
            won = true;
            break;
        } else if (guess < secret) {
            cout << "Too low!" << endl;
        } else {
            cout << "Too high!" << endl;
        }
    }
    
    if (!won) {
        cout << "Game over! The number was " << secret << endl;
    }
    
    return 0;
}
```
</details>

---

### Exercise 9: Skip Vowels

Write a program that prints a string but skips all vowels. Use continue.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string text;
    
    cout << "Enter text: ";
    getline(cin, text);
    
    cout << "Text without vowels: ";
    
    for (int i = 0; i < text.length(); i++) {
        char c = tolower(text[i]);
        
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            continue;  // Skip vowels
        }
        
        cout << text[i];
    }
    cout << endl;
    
    return 0;
}
```
</details>

---

### Exercise 10: Multiplication Table Grid

Write a program that prints a multiplication table grid from 1x1 to 10x10.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    cout << "Multiplication Table Grid:" << endl;
    
    // Header row
    cout << "   ";
    for (int i = 1; i <= 10; i++) {
        cout << setw(4) << i;
    }
    cout << endl;
    
    // Separator
    cout << "   ";
    for (int i = 1; i <= 10; i++) {
        cout << "----";
    }
    cout << endl;
    
    // Table rows
    for (int i = 1; i <= 10; i++) {
        cout << setw(2) << i << "|";
        for (int j = 1; j <= 10; j++) {
            cout << setw(4) << i * j;
        }
        cout << endl;
    }
    
    return 0;
}
```
</details>

---

## Summary

### What We Learned Today

- **Nested loops** - Loops inside loops for patterns and tables
- **do-while loop** - Executes at least once, condition checked at end
- **break statement** - Exit loop immediately
- **continue statement** - Skip to next iteration
- **Loop patterns** - Triangles, pyramids, and complex shapes
- **Practical applications** - Menus, validation, games

---

## Key Takeaways

1. **Nested loops:** Outer loop controls rows, inner loop controls columns
2. **do-while:** Use when you need guaranteed first execution
3. **break:** Use to exit loops early (search, error conditions)
4. **continue:** Use to skip specific iterations (filtering)
5. **Loop control:** Combine break and continue for powerful control flow
6. **Patterns:** Most patterns use nested loops with careful index control

---

## Next Lecture Preview

In the next lecture, we will learn about:
- Arrays (storing multiple values)
- Working with array elements
- Array algorithms and operations
- Multi-dimensional arrays

---

## Homework

**Assignment 1:** Write a program that prints a hollow diamond pattern using nested loops.

**Assignment 2:** Create a simple calculator program using a do-while loop that keeps running until the user chooses to exit.

**Assignment 3:** Write a program that finds all Armstrong numbers between 1 and 1000. An Armstrong number is equal to the sum of its digits raised to the power of the number of digits. Example: 153 = 1³ + 5³ + 3³

---

## Resources

- [cppreference.com - do-while statement](https://en.cppreference.com/w/cpp/language/do)
- [cppreference.com - break statement](https://en.cppreference.com/w/cpp/language/break)
- [cppreference.com - continue statement](https://en.cppreference.com/w/cpp/language/continue)
- [learncpp.com - Loop control](https://www.learncpp.com/)

---

**Master these loop techniques through practice.** They are essential for solving complex programming problems.
