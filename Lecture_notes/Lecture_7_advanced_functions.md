# Lecture 7: Advanced Functions in C++

## Welcome

In the previous lecture, you learned the basics of functions including syntax, parameters, return values, and prototypes. Now you will learn advanced function techniques that give you more power and flexibility.

**Topics covered today:**
- Function overloading
- Pass by value vs pass by reference
- Default parameters
- Passing arrays to functions

---

## Table of Contents

1. [Function Overloading](#function-overloading)
2. [Pass by Value vs Pass by Reference](#pass-by-value-vs-pass-by-reference)
3. [Default Parameters](#default-parameters)
4. [Passing Arrays to Functions](#passing-arrays-to-functions)
5. [Practice Exercises](#practice-exercises)
6. [Summary](#summary)

---

## Function Overloading

**Function overloading** allows you to have multiple functions with the same name but different parameters.

The compiler chooses the correct function based on:
- Number of parameters
- Types of parameters

### Same Name, Different Number of Parameters

```cpp
#include <iostream>
using namespace std;

// Function prototypes
int add(int a, int b);
int add(int a, int b, int c);

int main() {
    cout << add(5, 3) << endl;        // Calls first version: 8
    cout << add(5, 3, 2) << endl;     // Calls second version: 10
    return 0;
}

int add(int a, int b) {
    return a + b;
}

int add(int a, int b, int c) {
    return a + b + c;
}
```

**Output:**
```
8
10
```

### Same Name, Different Parameter Types

```cpp
#include <iostream>
using namespace std;

// Function prototypes
int add(int a, int b);
double add(double a, double b);

int main() {
    cout << add(5, 3) << endl;           // Calls int version: 8
    cout << add(5.5, 3.2) << endl;       // Calls double version: 8.7
    return 0;
}

int add(int a, int b) {
    return a + b;
}

double add(double a, double b) {
    return a + b;
}
```

**Output:**
```
8
8.7
```

### Volume Calculator Example

```cpp
#include <iostream>
using namespace std;

// Function prototypes
double volume(double side);
double volume(double length, double width, double height);
double volume(double radius, double height);

int main() {
    cout << "Cube volume: " << volume(3.0) << endl;
    cout << "Box volume: " << volume(2.0, 3.0, 4.0) << endl;
    cout << "Cylinder volume: " << volume(2.0, 5.0) << endl;
    return 0;
}

// Volume of cube
double volume(double side) {
    return side * side * side;
}

// Volume of rectangular box
double volume(double length, double width, double height) {
    return length * width * height;
}

// Volume of cylinder
double volume(double radius, double height) {
    const double PI = 3.14159;
    return PI * radius * radius * height;
}
```

**Output:**
```
Cube volume: 27
Box volume: 24
Cylinder volume: 62.8318
```

### Rules for Function Overloading

**Valid overloading:**
```cpp
int func(int a);
int func(int a, int b);
int func(double a);
```

**Invalid overloading (only return type differs):**
```cpp
int func(int a);
double func(int a);  // Error! Cannot overload on return type only
```

**Why overloading is useful:**
- Same logical operation, different data types
- More intuitive code (one name instead of addInt, addDouble, etc.)
- Easier to remember and use

---

## Pass by Value vs Pass by Reference

### Pass by Value (Default)

When you pass a variable by value, the function gets a **copy**. Changes inside the function do NOT affect the original variable.

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

**What happens:**
1. `num` (value 10) is passed to function
2. A copy of `num` is created as parameter `x`
3. `x` is changed to 100 inside the function
4. Original `num` remains unchanged

### Pass by Reference

When you pass by reference (using `&`), the function gets the **actual variable**. Changes inside the function DO affect the original.

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

**What happens:**
1. `num` is passed by reference to function
2. `x` is an alias (another name) for `num`
3. Changes to `x` directly affect `num`
4. Original `num` is modified

### When to Use Each

**Use pass by value when:**
- You do NOT want to modify the original variable
- You are working with small data types (int, double, char)
- The function only needs to read the value

**Use pass by reference when:**
- You WANT to modify the original variable
- You want to return multiple values
- You are working with large data structures (to avoid copying)

### Example: Swapping Two Numbers

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

### Example: Returning Multiple Values

```cpp
#include <iostream>
using namespace std;

void getMinMax(int a, int b, int c, int &min, int &max) {
    min = a;
    max = a;
    
    if (b < min) min = b;
    if (c < min) min = c;
    
    if (b > max) max = b;
    if (c > max) max = c;
}

int main() {
    int minimum, maximum;
    getMinMax(15, 23, 8, minimum, maximum);
    
    cout << "Min: " << minimum << endl;
    cout << "Max: " << maximum << endl;
    
    return 0;
}
```

**Output:**
```
Min: 8
Max: 23
```

### Example: Increment Function

**This does NOT work (pass by value):**
```cpp
void increment(int x) {
    x++;  // Only changes the copy
}

int main() {
    int num = 5;
    increment(num);
    cout << num;  // Still 5
}
```

**This WORKS (pass by reference):**
```cpp
void increment(int &x) {  // Use reference
    x++;
}

int main() {
    int num = 5;
    increment(num);
    cout << num;  // Now 6
}
```

### Const References

You can use `const` with references to prevent modification while avoiding copying:

```cpp
void printLargeData(const string &text) {
    // text cannot be modified
    // But no copy is made (efficient for large strings)
    cout << text << endl;
}
```

**Why use const reference:**
- Avoid copying large data (efficient)
- Prevent accidental modification (safe)

---

## Default Parameters

**Default parameters** allow you to give parameters default values that are used if no value is provided when calling the function.

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

1. **Default parameters must come at the end** of the parameter list

**Correct:**
```cpp
void func(int a, int b = 5, int c = 10);
```

**Wrong:**
```cpp
void func(int a = 5, int b);  // Error! Non-default after default
```

2. **Once you use a default parameter, all following parameters must also have defaults**

**Correct:**
```cpp
void func(int a, int b = 5, int c = 10);
```

**Wrong:**
```cpp
void func(int a, int b = 5, int c);  // Error! c must have default
```

3. **Default values are specified in the prototype (or definition if no prototype)**

```cpp
// In prototype
void func(int a, int b = 5);

// In definition (don't repeat defaults)
void func(int a, int b) {
    // Implementation
}
```

### Example: Rectangle Area with Defaults

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

### Example: Print Line Function

```cpp
#include <iostream>
using namespace std;

void printLine(char symbol = '-', int length = 40) {
    for (int i = 0; i < length; i++) {
        cout << symbol;
    }
    cout << endl;
}

int main() {
    printLine();          // Uses both defaults: ---- (40 times)
    printLine('*');       // Uses default length: **** (40 times)
    printLine('=', 20);   // Uses no defaults: ==== (20 times)
    
    return 0;
}
```

---

## Passing Arrays to Functions

Arrays are always passed by reference automatically. You cannot pass an array by value.

### Passing an Array

```cpp
#include <iostream>
using namespace std;

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int numbers[] = {10, 20, 30, 40, 50};
    int size = 5;
    
    printArray(numbers, size);
    
    return 0;
}
```

**Output:**
```
10 20 30 40 50
```

**Important notes:**
- You must pass the size separately
- Arrays decay to pointers when passed to functions
- Changes to array inside function affect the original array

### Modifying Array Elements

```cpp
#include <iostream>
using namespace std;

void doubleValues(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] *= 2;  // Modifies original array
    }
}

int main() {
    int numbers[] = {1, 2, 3, 4, 5};
    int size = 5;
    
    cout << "Before: ";
    for (int i = 0; i < size; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;
    
    doubleValues(numbers, size);
    
    cout << "After: ";
    for (int i = 0; i < size; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;
    
    return 0;
}
```

**Output:**
```
Before: 1 2 3 4 5
After: 2 4 6 8 10
```

### Example: Calculate Array Sum

```cpp
#include <iostream>
using namespace std;

int sumArray(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int numbers[] = {10, 20, 30, 40, 50};
    int size = 5;
    
    int total = sumArray(numbers, size);
    cout << "Sum: " << total << endl;
    
    return 0;
}
```

**Output:**
```
Sum: 150
```

### Example: Find Maximum in Array

```cpp
#include <iostream>
using namespace std;

int findMax(int arr[], int size) {
    int max = arr[0];
    
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    
    return max;
}

int main() {
    int numbers[] = {45, 12, 67, 23, 91, 8};
    int size = 6;
    
    cout << "Maximum: " << findMax(numbers, size) << endl;
    
    return 0;
}
```

**Output:**
```
Maximum: 91
```

### Example: Reverse Array

```cpp
#include <iostream>
using namespace std;

void reverseArray(int arr[], int size) {
    int start = 0;
    int end = size - 1;
    
    while (start < end) {
        // Swap elements
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        
        start++;
        end--;
    }
}

int main() {
    int numbers[] = {1, 2, 3, 4, 5};
    int size = 5;
    
    cout << "Before: ";
    for (int i = 0; i < size; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;
    
    reverseArray(numbers, size);
    
    cout << "After: ";
    for (int i = 0; i < size; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;
    
    return 0;
}
```

**Output:**
```
Before: 1 2 3 4 5
After: 5 4 3 2 1
```

---

## Practice Exercises

### Exercise 1: Overloaded Max Function

Create overloaded `max` functions that work with 2 or 3 parameters.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int max(int a, int b);
int max(int a, int b, int c);

int main() {
    cout << "Max(10, 20): " << max(10, 20) << endl;
    cout << "Max(10, 20, 15): " << max(10, 20, 15) << endl;
    return 0;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int max(int a, int b, int c) {
    int maximum = a;
    if (b > maximum) maximum = b;
    if (c > maximum) maximum = c;
    return maximum;
}
```
</details>

---

### Exercise 2: Swap Using References

Write a function that swaps two double values using pass by reference.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

void swap(double &a, double &b);

int main() {
    double x = 3.14, y = 2.71;
    
    cout << "Before: x=" << x << " y=" << y << endl;
    swap(x, y);
    cout << "After: x=" << x << " y=" << y << endl;
    
    return 0;
}

void swap(double &a, double &b) {
    double temp = a;
    a = b;
    b = temp;
}
```
</details>

---

### Exercise 3: Function with Default Parameters

Create a function `displayBox` that prints a box of a given character and size, with defaults.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

void displayBox(int width = 5, int height = 3, char symbol = '*');

int main() {
    displayBox();           // Use all defaults
    displayBox(7);          // Custom width
    displayBox(6, 4);       // Custom width and height
    displayBox(8, 3, '#');  // All custom
    
    return 0;
}

void displayBox(int width, int height, char symbol) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cout << symbol;
        }
        cout << endl;
    }
    cout << endl;
}
```
</details>

---

### Exercise 4: Calculate Average of Array

Write a function that calculates the average of an array of doubles.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

double calculateAverage(double arr[], int size);

int main() {
    double grades[] = {85.5, 90.0, 78.5, 92.0, 88.5};
    int size = 5;
    
    double avg = calculateAverage(grades, size);
    cout << "Average: " << avg << endl;
    
    return 0;
}

double calculateAverage(double arr[], int size) {
    double sum = 0;
    
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    
    return sum / size;
}
```
</details>

---

### Exercise 5: Sort Array

Write a function that sorts an array in ascending order (use any simple sorting algorithm).

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

void sortArray(int arr[], int size);
void printArray(int arr[], int size);

int main() {
    int numbers[] = {64, 34, 25, 12, 22, 11, 90};
    int size = 7;
    
    cout << "Before sorting: ";
    printArray(numbers, size);
    
    sortArray(numbers, size);
    
    cout << "After sorting: ";
    printArray(numbers, size);
    
    return 0;
}

void sortArray(int arr[], int size) {
    // Bubble sort
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
```
</details>

---

### Exercise 6: Find Element in Array

Write a function that searches for an element in an array and returns its index (or -1 if not found).

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int findElement(int arr[], int size, int target);

int main() {
    int numbers[] = {10, 25, 30, 45, 50};
    int size = 5;
    
    int index = findElement(numbers, size, 30);
    if (index != -1) {
        cout << "Found at index " << index << endl;
    } else {
        cout << "Not found" << endl;
    }
    
    return 0;
}

int findElement(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;  // Not found
}
```
</details>

---

### Exercise 7: Update Array by Reference

Write a function that adds a constant value to all elements of an array.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

void addToAll(int arr[], int size, int value);

int main() {
    int numbers[] = {1, 2, 3, 4, 5};
    int size = 5;
    
    cout << "Before: ";
    for (int i = 0; i < size; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;
    
    addToAll(numbers, size, 10);
    
    cout << "After: ";
    for (int i = 0; i < size; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;
    
    return 0;
}

void addToAll(int arr[], int size, int value) {
    for (int i = 0; i < size; i++) {
        arr[i] += value;
    }
}
```
</details>

---

### Exercise 8: Count Occurrences

Write a function that counts how many times a specific value appears in an array.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int countOccurrences(int arr[], int size, int value);

int main() {
    int numbers[] = {5, 3, 5, 7, 5, 2, 5, 9};
    int size = 8;
    
    int count = countOccurrences(numbers, size, 5);
    cout << "5 appears " << count << " times" << endl;
    
    return 0;
}

int countOccurrences(int arr[], int size, int value) {
    int count = 0;
    
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            count++;
        }
    }
    
    return count;
}
```
</details>

---

## Summary

### What We Learned Today

- **Function overloading** - Same name, different parameters
- **Pass by value** - Function gets a copy
- **Pass by reference** - Function gets the original (use &)
- **Default parameters** - Optional parameter values
- **Passing arrays** - Arrays always passed by reference

---

## Key Takeaways

1. **Function overloading** - Provides flexibility for different data types
2. **Use & for references** - Modify original variables or avoid copying
3. **Default parameters** - Must come at end of parameter list
4. **Arrays and functions** - Always need to pass size separately
5. **Const references** - Efficient and safe for large data

---

## Next Lecture Preview

In the next lecture, we will learn about:
- Recursion
- Recursive vs iterative solutions
- Base cases and recursive cases
- Common recursive algorithms

---

## Homework

**Assignment 1:** Create an overloaded `area` function that calculates area for circles (1 parameter: radius), rectangles (2 parameters: length, width), and triangles (2 parameters: base, height).

**Assignment 2:** Write a function that takes an array and its size by reference, then removes all duplicate values. The size should be updated to reflect the new array length.

**Assignment 3:** Create a function with default parameters that generates a password. Parameters: length (default 8), include numbers (default true), include symbols (default false).

---

## Resources

- [cppreference.com - Function overloading](https://en.cppreference.com/w/cpp/language/overload_resolution)
- [cppreference.com - References](https://en.cppreference.com/w/cpp/language/reference)
- [learncpp.com - Function overloading](https://www.learncpp.com/cpp-tutorial/function-overload-differentiation/)
- [learncpp.com - Pass by reference](https://www.learncpp.com/cpp-tutorial/pass-by-lvalue-reference/)

---

**Master these advanced techniques to write more powerful and flexible functions.**
