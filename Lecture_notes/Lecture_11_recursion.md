# Lecture 11: Recursion in C++

## Table of Contents

1. [Introduction to Recursion](#introduction-to-recursion)
2. [How Recursion Works](#how-recursion-works)
3. [Basic Recursion Examples](#basic-recursion-examples)
4. [Anatomy of a Recursive Function](#anatomy-of-a-recursive-function)
5. [Classic Recursion Problems](#classic-recursion-problems)
6. [Recursion vs Iteration](#recursion-vs-iteration)
7. [Common Mistakes](#common-mistakes)
8. [Practice Exercises](#practice-exercises)
9. [Summary](#summary)

---

## Introduction to Recursion

**Recursion** is a programming technique where a function calls itself to solve a problem. It breaks down a complex problem into smaller, simpler versions of the same problem.

### What is Recursive function?

A recursive function is a function that calls itself during its execution. Each recursive call works on a smaller version of the original problem until it reaches a simple case that can be solved directly.

### Real-World Analogies

**Looking in a Mirror Between Two Mirrors**
- You see your reflection
- That reflection shows another reflection
- That shows another reflection
- This continues until the reflections become too small to see

**Russian Nesting Dolls (Matryoshka)**
- Open a doll to find a smaller doll inside
- Open that doll to find an even smaller one
- Continue until you reach the smallest doll that doesn't open

**Searching for a File in Folders**
- Open a folder
- If it contains the file, you're done
- If it contains subfolders, open each subfolder and repeat
- Continue until you find the file or run out of folders

### Why Use Recursion?

- Solves problems that have a recursive structure naturally
- Makes code cleaner and easier to understand for certain problems
- Essential for tree and graph algorithms
- Useful for divide-and-conquer strategies

---

## How Recursion Works

### The Call Stack

When a function is called, the computer stores information about that function call on the **call stack**. This includes:
- Function parameters
- Local variables
- Return address (where to continue after the function finishes)

When a function calls itself recursively, a new entry is added to the call stack for each call.

### Visual Example: Countdown

```cpp
#include <iostream>
using namespace std;

void countdown(int n) {
    if (n == 0) {
        cout << "Blastoff!" << endl;
        return;
    }
    
    cout << n << endl;
    countdown(n - 1);  // Recursive call
}

int main() {
    countdown(3);
    return 0;
}
```

**Output:**
```
3
2
1
Blastoff!
```

**How it works:**
1. `countdown(3)` is called
   - Prints 3
   - Calls `countdown(2)`
2. `countdown(2)` is called
   - Prints 2
   - Calls `countdown(1)`
3. `countdown(1)` is called
   - Prints 1
   - Calls `countdown(0)`
4. `countdown(0)` is called
   - Base case reached
   - Prints "Blastoff!"
   - Returns (no more recursive calls)

---

## Basic Recursion Examples

### Example 1: Simple Countdown

```cpp
#include <iostream>
using namespace std;

void printNumbers(int n) {
    if (n <= 0) {
        return;  // Base case: stop when n reaches 0
    }
    
    cout << n << " ";
    printNumbers(n - 1);  // Recursive call with smaller value
}

int main() {
    printNumbers(5);
    cout << endl;
    
    return 0;
}
```

**Output:**
```
5 4 3 2 1
```

### Example 2: Count Up

```cpp
#include <iostream>
using namespace std;

void countUp(int n) {
    if (n <= 0) {
        return;  // Base case
    }
    
    countUp(n - 1);  // Recursive call first
    cout << n << " ";  // Print after recursive call
}

int main() {
    countUp(5);
    cout << endl;
    
    return 0;
}
```

**Output:**
```
1 2 3 4 5
```

**Key Difference:** The recursive call happens **before** the print statement, so numbers are printed in ascending order.

### Example 3: Sum of Numbers

Calculate the sum of numbers from 1 to n.

```cpp
#include <iostream>
using namespace std;

int sum(int n) {
    if (n == 0) {
        return 0;  // Base case
    }
    
    return n + sum(n - 1);  // Recursive case
}

int main() {
    int result = sum(5);
    cout << "Sum of 1 to 5: " << result << endl;
    
    return 0;
}
```

**Output:**
```
Sum of 1 to 5: 15
```

**How it works:**
```
sum(5) = 5 + sum(4)
       = 5 + (4 + sum(3))
       = 5 + (4 + (3 + sum(2)))
       = 5 + (4 + (3 + (2 + sum(1))))
       = 5 + (4 + (3 + (2 + (1 + sum(0)))))
       = 5 + (4 + (3 + (2 + (1 + 0))))
       = 5 + (4 + (3 + (2 + 1)))
       = 5 + (4 + (3 + 3))
       = 5 + (4 + 6)
       = 5 + 10
       = 15
```

---

## Anatomy of a Recursive Function

Every recursive function must have two essential parts:

### 1. Base Case

The **base case** is the stopping condition. It defines when the recursion should end and return a value without making another recursive call.

Without a base case, the function would call itself infinitely, leading to a **stack overflow** error.

```cpp
if (n == 0) {
    return 0;  // Base case - stop recursion
}
```

### 2. Recursive Case

The **recursive case** is where the function calls itself with a modified parameter, moving toward the base case.

```cpp
return n + sum(n - 1);  // Recursive case - call with smaller n
```

### Template for Recursive Functions

```cpp
returnType functionName(parameters) {
    // Base case
    if (simple_condition) {
        return simple_value;
    }
    
    // Recursive case
    // Do some work
    // Call function with modified parameters
    return combine(work, functionName(smaller_parameters));
}
```

---

## Classic Recursion Problems

### Problem 1: Factorial

Calculate n! (n factorial) = n × (n-1) × (n-2) × ... × 2 × 1

**Mathematical definition:**
- 0! = 1 (base case)
- n! = n × (n-1)! (recursive case)

```cpp
#include <iostream>
using namespace std;

int factorial(int n) {
    // Base case
    if (n == 0 || n == 1) {
        return 1;
    }
    
    // Recursive case
    return n * factorial(n - 1);
}

int main() {
    cout << "5! = " << factorial(5) << endl;
    cout << "6! = " << factorial(6) << endl;
    
    return 0;
}
```

**Output:**
```
5! = 120
6! = 720
```

**Trace of factorial(5):**
```
factorial(5) = 5 * factorial(4)
             = 5 * (4 * factorial(3))
             = 5 * (4 * (3 * factorial(2)))
             = 5 * (4 * (3 * (2 * factorial(1))))
             = 5 * (4 * (3 * (2 * 1)))
             = 5 * (4 * (3 * 2))
             = 5 * (4 * 6)
             = 5 * 24
             = 120
```

### Problem 2: Fibonacci Sequence

The Fibonacci sequence: 0, 1, 1, 2, 3, 5, 8, 13, 21, ...

**Mathematical definition:**
- fib(0) = 0 (base case)
- fib(1) = 1 (base case)
- fib(n) = fib(n-1) + fib(n-2) (recursive case)

```cpp
#include <iostream>
using namespace std;

int fibonacci(int n) {
    // Base cases
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    
    // Recursive case
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    cout << "First 10 Fibonacci numbers:" << endl;
    for (int i = 0; i < 10; i++) {
        cout << fibonacci(i) << " ";
    }
    cout << endl;
    
    return 0;
}
```

**Output:**
```
First 10 Fibonacci numbers:
0 1 1 2 3 5 8 13 21 34
```

### Problem 3: Power Function

Calculate x^n (x raised to the power n).

```cpp
#include <iostream>
using namespace std;

int power(int x, int n) {
    // Base case
    if (n == 0) {
        return 1;
    }
    
    // Recursive case
    return x * power(x, n - 1);
}

int main() {
    cout << "2^5 = " << power(2, 5) << endl;
    cout << "3^4 = " << power(3, 4) << endl;
    
    return 0;
}
```

**Output:**
```
2^5 = 32
3^4 = 81
```

### Problem 4: Sum of Array Elements

Calculate the sum of all elements in an array using recursion.

```cpp
#include <iostream>
using namespace std;

int arraySum(int arr[], int size) {
    // Base case: empty array
    if (size == 0) {
        return 0;
    }
    
    // Recursive case: first element + sum of rest
    return arr[0] + arraySum(arr + 1, size - 1);
}

int main() {
    int numbers[] = {1, 2, 3, 4, 5};
    int size = 5;
    
    cout << "Sum: " << arraySum(numbers, size) << endl;
    
    return 0;
}
```

**Output:**
```
Sum: 15
```

### Problem 5: Reverse a String

Reverse a string using recursion.

```cpp
#include <iostream>
#include <string>
using namespace std;

string reverseString(string str) {
    // Base case: empty or single character
    if (str.length() <= 1) {
        return str;
    }
    
    // Recursive case: last char + reverse of rest
    return str[str.length() - 1] + reverseString(str.substr(0, str.length() - 1));
}

int main() {
    string text = "Hello";
    
    cout << "Original: " << text << endl;
    cout << "Reversed: " << reverseString(text) << endl;
    
    return 0;
}
```

**Output:**
```
Original: Hello
Reversed: olleH
```

### Problem 6: Greatest Common Divisor (GCD)

Find the GCD of two numbers using Euclidean algorithm.

```cpp
#include <iostream>
using namespace std;

int gcd(int a, int b) {
    // Base case
    if (b == 0) {
        return a;
    }
    
    // Recursive case
    return gcd(b, a % b);
}

int main() {
    cout << "GCD(48, 18) = " << gcd(48, 18) << endl;
    cout << "GCD(100, 35) = " << gcd(100, 35) << endl;
    
    return 0;
}
```

**Output:**
```
GCD(48, 18) = 6
GCD(100, 35) = 5
```

### Problem 7: Binary Search (Recursive)

Search for an element in a sorted array.

```cpp
#include <iostream>
using namespace std;

int binarySearch(int arr[], int left, int right, int target) {
    // Base case: not found
    if (left > right) {
        return -1;
    }
    
    int mid = left + (right - left) / 2;
    
    // Base case: found
    if (arr[mid] == target) {
        return mid;
    }
    
    // Recursive cases
    if (arr[mid] > target) {
        return binarySearch(arr, left, mid - 1, target);
    } else {
        return binarySearch(arr, mid + 1, right, target);
    }
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 45, 56, 67, 78};
    int size = 11;
    int target = 23;
    
    int index = binarySearch(arr, 0, size - 1, target);
    
    if (index != -1) {
        cout << "Found " << target << " at index " << index << endl;
    } else {
        cout << target << " not found" << endl;
    }
    
    return 0;
}
```

**Output:**
```
Found 23 at index 5
```

---

## Recursion vs Iteration

Many problems can be solved using either recursion or iteration (loops). Here's a comparison:

### Factorial: Recursive vs Iterative

**Recursive version:**
```cpp
int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}
```

**Iterative version:**
```cpp
int factorial(int n) {
    int result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}
```

### Comparison Table

| Aspect | Recursion | Iteration |
|--------|-----------|-----------|
| **Code clarity** | Often simpler and cleaner | Can be more verbose |
| **Memory usage** | Uses call stack (more memory) | Uses less memory |
| **Performance** | Slower (function call overhead) | Faster |
| **Stack overflow risk** | Yes (deep recursion) | No |
| **Best for** | Tree/graph problems, divide & conquer | Simple loops, performance-critical |

### When to Use Recursion

**Good cases for recursion:**
- Tree and graph traversal
- Divide and conquer algorithms (merge sort, quick sort)
- Problems with recursive structure (Tower of Hanoi)
- Mathematical sequences (Fibonacci, factorials)
- Backtracking problems

**Avoid recursion when:**
- Simple iteration is sufficient
- Performance is critical
- Very deep recursion is needed (risk of stack overflow)
- Memory is limited

---

## Common Mistakes

### Mistake 1: Missing Base Case

**Wrong:**
```cpp
int sum(int n) {
    return n + sum(n - 1);  // No base case - infinite recursion!
}
```

**Correct:**
```cpp
int sum(int n) {
    if (n == 0) {
        return 0;  // Base case
    }
    return n + sum(n - 1);
}
```

### Mistake 2: Base Case Never Reached

**Wrong:**
```cpp
int countdown(int n) {
    if (n == 0) {
        return;
    }
    cout << n << endl;
    countdown(n);  // Calls with same n - never reaches base case!
}
```

**Correct:**
```cpp
int countdown(int n) {
    if (n == 0) {
        return;
    }
    cout << n << endl;
    countdown(n - 1);  // Decrease n to move toward base case
}
```

### Mistake 3: Wrong Base Case Condition

**Wrong:**
```cpp
int factorial(int n) {
    if (n == 0) {
        return 0;  // Wrong! 0! = 1, not 0
    }
    return n * factorial(n - 1);
}
```

**Correct:**
```cpp
int factorial(int n) {
    if (n == 0) {
        return 1;  // Correct: 0! = 1
    }
    return n * factorial(n - 1);
}
```

### Mistake 4: Not Handling Negative Numbers

**Wrong:**
```cpp
int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);  // Problem if n < 0
}
```

**Correct:**
```cpp
int factorial(int n) {
    if (n < 0) {
        return -1;  // Error indicator
    }
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}
```

### Mistake 5: Inefficient Recursion

The recursive Fibonacci function is very inefficient because it recalculates the same values many times.

**Inefficient:**
```cpp
int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);  // Recalculates many values
}
```

For `fibonacci(5)`, it calculates `fibonacci(3)` twice, `fibonacci(2)` three times, etc.

**Better approach:** Use iteration or memoization (caching results).

---

## Practice Exercises

### Exercise 1: Print in Reverse

Write a recursive function that prints numbers from n down to 1.

**Expected output for n=5:**
```
5 4 3 2 1
```

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

void printReverse(int n) {
    if (n == 0) {
        return;
    }
    cout << n << " ";
    printReverse(n - 1);
}

int main() {
    printReverse(5);
    cout << endl;
    return 0;
}
```
</details>

---

### Exercise 2: Count Digits

Write a recursive function that counts the number of digits in a positive integer.

**Expected output:**
```
Digits in 12345: 5
Digits in 7: 1
```

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int countDigits(int n) {
    if (n < 10) {
        return 1;
    }
    return 1 + countDigits(n / 10);
}

int main() {
    cout << "Digits in 12345: " << countDigits(12345) << endl;
    cout << "Digits in 7: " << countDigits(7) << endl;
    return 0;
}
```
</details>

---

### Exercise 3: Sum of Digits

Write a recursive function that returns the sum of digits in a number.

**Expected output:**
```
Sum of digits in 123: 6
Sum of digits in 456: 15
```

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int sumDigits(int n) {
    if (n == 0) {
        return 0;
    }
    return (n % 10) + sumDigits(n / 10);
}

int main() {
    cout << "Sum of digits in 123: " << sumDigits(123) << endl;
    cout << "Sum of digits in 456: " << sumDigits(456) << endl;
    return 0;
}
```
</details>

---

### Exercise 4: Is Palindrome

Write a recursive function that checks if a string is a palindrome.

**Expected output:**
```
"racecar" is a palindrome
"hello" is not a palindrome
```

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string str, int start, int end) {
    if (start >= end) {
        return true;
    }
    if (str[start] != str[end]) {
        return false;
    }
    return isPalindrome(str, start + 1, end - 1);
}

int main() {
    string word1 = "racecar";
    string word2 = "hello";
    
    if (isPalindrome(word1, 0, word1.length() - 1)) {
        cout << "\"" << word1 << "\" is a palindrome" << endl;
    }
    
    if (!isPalindrome(word2, 0, word2.length() - 1)) {
        cout << "\"" << word2 << "\" is not a palindrome" << endl;
    }
    
    return 0;
}
```
</details>

---

### Exercise 5: Tower of Hanoi

Write a recursive solution for the Tower of Hanoi puzzle with n disks.

**Expected output for n=3:**
```
Move disk 1 from A to C
Move disk 2 from A to B
Move disk 1 from C to B
Move disk 3 from A to C
Move disk 1 from B to A
Move disk 2 from B to C
Move disk 1 from A to C
```

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

void towerOfHanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        cout << "Move disk 1 from " << from << " to " << to << endl;
        return;
    }
    
    towerOfHanoi(n - 1, from, aux, to);
    cout << "Move disk " << n << " from " << from << " to " << to << endl;
    towerOfHanoi(n - 1, aux, to, from);
}

int main() {
    int n = 3;
    towerOfHanoi(n, 'A', 'C', 'B');
    return 0;
}
```
</details>

---

## Summary

### Key Concepts

- **Recursion** - A function that calls itself
- **Base case** - The stopping condition (essential!)
- **Recursive case** - The function calling itself with modified parameters
- **Call stack** - Stores information about each function call
- Recursion breaks complex problems into simpler subproblems

### Essential Components

Every recursive function needs:
1. **Base case(s)** - When to stop recursion
2. **Recursive case** - How to reduce the problem
3. **Progress toward base case** - Parameters must change to reach the base case

### When to Use Recursion

**Good for:**
- Problems with recursive structure
- Tree and graph algorithms
- Divide and conquer approaches
- Backtracking problems

**Avoid when:**
- Simple iteration works
- Performance is critical
- Memory is limited
- Very deep recursion is needed

### Common Patterns

1. **Countdown pattern:** Process decreasing values
2. **Accumulator pattern:** Build up a result
3. **Divide and conquer:** Split problem in half
4. **Multiple recursion:** Call function multiple times (like Fibonacci)

### Important Points

1. Always have a base case to prevent infinite recursion
2. Make sure parameters move toward the base case
3. Each recursive call should work on a smaller problem
4. Be aware of stack overflow for deep recursion
5. Consider iterative alternatives for performance

### Quick Reference

```cpp
// Basic template
int recursive(int n) {
    // Base case
    if (n == base_condition) {
        return base_value;
    }
    
    // Recursive case
    return process(n, recursive(n - 1));
}

// Multiple base cases
int function(int n) {
    if (condition1) return value1;
    if (condition2) return value2;
    return recursive_expression;
}

// Multiple recursive calls
int function(int n) {
    if (base_case) return value;
    return function(n-1) + function(n-2);
}
```

---

## Next Steps

In the next lecture, you will learn about:
- Pointers and memory addresses
- Dynamic memory allocation
- Pointers and arrays
- Pointer arithmetic

---

**Practice recursion to develop recursive thinking - it's a powerful problem-solving technique!**

