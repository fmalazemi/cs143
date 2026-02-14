# Lecture 8: Introduction to Arrays in C++

## Welcome

In previous lectures, you learned about functions and how to work with individual variables. Now you will learn how to work with collections of data using arrays.

**Why arrays are important:**
- Store multiple related values together
- Process large amounts of data efficiently
- Organize data in a structured way
- Essential for real-world programming

---

## Table of Contents

1. [What Are Arrays?](#what-are-arrays)
2. [Array Declaration and Initialization](#array-declaration-and-initialization)
3. [Accessing Array Elements](#accessing-array-elements)
4. [Modifying Array Elements](#modifying-array-elements)
5. [Looping Through Arrays](#looping-through-arrays)
6. [Array Operations](#array-operations)
7. [Arrays and Functions](#arrays-and-functions)
8. [Common Mistakes](#common-mistakes)
9. [Practice Exercises](#practice-exercises)
10. [Summary](#summary)

---

## What Are Arrays?

An **array** is a collection of elements of the same type stored in consecutive memory locations.

**Real-world analogy:**
Think of an array like a row of mailboxes in an apartment building. Each mailbox has a number (index) and can store one item.

### The Problem Arrays Solve

**Without arrays:**
```cpp
int student1Grade = 85;
int student2Grade = 90;
int student3Grade = 78;
int student4Grade = 92;
int student5Grade = 88;
// What if you have 100 students?
```

**With arrays:**
```cpp
int grades[5] = {85, 90, 78, 92, 88};
// Easy to manage any number of students
```

### Benefits of Arrays

- Store multiple values under one name
- Access elements using an index number
- Process data efficiently using loops
- Pass collections to functions
- Organize related data together

---

## Array Declaration and Initialization

### Array Declaration

The basic syntax to declare an array:

```cpp
dataType arrayName[size];
```

**Examples:**
```cpp
int numbers[5];        // Array of 5 integers
double prices[10];     // Array of 10 doubles
char letters[26];      // Array of 26 characters
```

**Important:** The size must be a constant value known at compile time.

### Array Initialization

**Method 1: Initialize all elements**
```cpp
int numbers[5] = {10, 20, 30, 40, 50};
```

**Method 2: Partial initialization (rest become 0)**
```cpp
int numbers[5] = {10, 20};  // {10, 20, 0, 0, 0}
```

**Method 3: Initialize all to zero**
```cpp
int numbers[5] = {0};  // {0, 0, 0, 0, 0}
```

**Method 4: Let compiler determine size**
```cpp
int numbers[] = {10, 20, 30, 40, 50};  // Size is automatically 5
```

### Complete Example

```cpp
#include <iostream>
using namespace std;

int main() {
    int scores[5] = {85, 90, 78, 92, 88};
    
    cout << "First score: " << scores[0] << endl;
    cout << "Last score: " << scores[4] << endl;
    
    return 0;
}
```

**Output:**
```
First score: 85
Last score: 88
```

---

## Accessing Array Elements

Arrays use **zero-based indexing** - the first element is at index 0.

### Index Range

For an array of size n, valid indices are **0 to n-1**.

```cpp
int numbers[5] = {10, 20, 30, 40, 50};

// Index:        0   1   2   3   4
// Values:      10  20  30  40  50
```

### Accessing Elements

```cpp
#include <iostream>
using namespace std;

int main() {
    int numbers[5] = {10, 20, 30, 40, 50};
    
    cout << numbers[0] << endl;  // Output: 10 (first element)
    cout << numbers[1] << endl;  // Output: 20 (second element)
    cout << numbers[2] << endl;  // Output: 30 (third element)
    cout << numbers[4] << endl;  // Output: 50 (last element)
    
    return 0;
}
```

### Important Notes

- First element is at index **0**, not 1
- Last element is at index **size - 1**
- Accessing index beyond the array size causes undefined behavior

---

## Modifying Array Elements

You can change the value of any element using its index.

```cpp
#include <iostream>
using namespace std;

int main() {
    int numbers[5] = {10, 20, 30, 40, 50};
    
    cout << "Before: " << numbers[0] << endl;
    
    numbers[0] = 100;   // Change first element
    numbers[2] = 300;   // Change third element
    
    cout << "After: " << numbers[0] << endl;
    
    // Array is now: {100, 20, 300, 40, 50}
    
    return 0;
}
```

**Output:**
```
Before: 10
After: 100
```

### Reading Input into Arrays

```cpp
#include <iostream>
using namespace std;

int main() {
    int numbers[5];
    
    cout << "Enter 5 numbers:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Number " << (i + 1) << ": ";
        cin >> numbers[i];
    }
    
    cout << "You entered: ";
    for (int i = 0; i < 5; i++) {
        cout << numbers[i] << " ";
    }
    
    return 0;
}
```

---

## Looping Through Arrays

Loops are essential for processing arrays efficiently.

### Using For Loop

```cpp
#include <iostream>
using namespace std;

int main() {
    int numbers[5] = {10, 20, 30, 40, 50};
    
    // Print all elements
    for (int i = 0; i < 5; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;
    
    return 0;
}
```

**Output:**
```
10 20 30 40 50
```

### Loop Pattern

```cpp
for (int i = 0; i < arraySize; i++) {
    // Access: numbers[i]
}
```

**Key points:**
- Start at index 0
- Continue while i < size (not i <= size)
- Increment by 1

### Processing All Elements

```cpp
#include <iostream>
using namespace std;

int main() {
    int numbers[5] = {10, 20, 30, 40, 50};
    
    // Double each element
    for (int i = 0; i < 5; i++) {
        numbers[i] = numbers[i] * 2;
    }
    
    // Print doubled values
    for (int i = 0; i < 5; i++) {
        cout << numbers[i] << " ";
    }
    
    return 0;
}
```

**Output:**
```
20 40 60 80 100
```

---

## Array Operations

### Finding the Maximum Element

```cpp
#include <iostream>
using namespace std;

int main() {
    int numbers[6] = {45, 12, 67, 23, 91, 8};
    int max = numbers[0];  // Assume first element is max
    
    for (int i = 1; i < 6; i++) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
    }
    
    cout << "Maximum: " << max << endl;
    
    return 0;
}
```

**Output:**
```
Maximum: 91
```

### Finding the Minimum Element

```cpp
#include <iostream>
using namespace std;

int main() {
    int numbers[6] = {45, 12, 67, 23, 91, 8};
    int min = numbers[0];  // Assume first element is min
    
    for (int i = 1; i < 6; i++) {
        if (numbers[i] < min) {
            min = numbers[i];
        }
    }
    
    cout << "Minimum: " << min << endl;
    
    return 0;
}
```

**Output:**
```
Minimum: 8
```

### Calculating Sum

```cpp
#include <iostream>
using namespace std;

int main() {
    int numbers[5] = {10, 20, 30, 40, 50};
    int sum = 0;
    
    for (int i = 0; i < 5; i++) {
        sum += numbers[i];
    }
    
    cout << "Sum: " << sum << endl;
    
    return 0;
}
```

**Output:**
```
Sum: 150
```

### Calculating Average

```cpp
#include <iostream>
using namespace std;

int main() {
    int numbers[5] = {10, 20, 30, 40, 50};
    int sum = 0;
    
    for (int i = 0; i < 5; i++) {
        sum += numbers[i];
    }
    
    double average = sum / 5.0;
    
    cout << "Sum: " << sum << endl;
    cout << "Average: " << average << endl;
    
    return 0;
}
```

**Output:**
```
Sum: 150
Average: 30
```

### Searching for an Element

```cpp
#include <iostream>
using namespace std;

int main() {
    int numbers[5] = {10, 25, 30, 45, 50};
    int target = 30;
    int index = -1;  // -1 means not found
    
    for (int i = 0; i < 5; i++) {
        if (numbers[i] == target) {
            index = i;
            break;  // Stop searching once found
        }
    }
    
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
Found 30 at index 2
```

### Counting Elements

```cpp
#include <iostream>
using namespace std;

int main() {
    int numbers[8] = {5, 3, 5, 7, 5, 2, 5, 9};
    int target = 5;
    int count = 0;
    
    for (int i = 0; i < 8; i++) {
        if (numbers[i] == target) {
            count++;
        }
    }
    
    cout << target << " appears " << count << " times" << endl;
    
    return 0;
}
```

**Output:**
```
5 appears 4 times
```

### Reversing an Array

```cpp
#include <iostream>
using namespace std;

int main() {
    int numbers[5] = {1, 2, 3, 4, 5};
    int start = 0;
    int end = 4;
    
    // Swap elements from both ends
    while (start < end) {
        int temp = numbers[start];
        numbers[start] = numbers[end];
        numbers[end] = temp;
        
        start++;
        end--;
    }
    
    cout << "Reversed: ";
    for (int i = 0; i < 5; i++) {
        cout << numbers[i] << " ";
    }
    
    return 0;
}
```

**Output:**
```
Reversed: 5 4 3 2 1
```

### Copying Arrays

You cannot copy arrays using the assignment operator. You must copy element by element.

**Wrong:**
```cpp
int arr1[5] = {1, 2, 3, 4, 5};
int arr2[5];
arr2 = arr1;  // Error! Cannot assign arrays
```

**Correct:**
```cpp
#include <iostream>
using namespace std;

int main() {
    int arr1[5] = {1, 2, 3, 4, 5};
    int arr2[5];
    
    // Copy element by element
    for (int i = 0; i < 5; i++) {
        arr2[i] = arr1[i];
    }
    
    cout << "Copied array: ";
    for (int i = 0; i < 5; i++) {
        cout << arr2[i] << " ";
    }
    
    return 0;
}
```

**Output:**
```
Copied array: 1 2 3 4 5
```

---

## Arrays and Functions

### Passing Arrays to Functions

Arrays are automatically passed by reference to functions.

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
    int numbers[5] = {10, 20, 30, 40, 50};
    
    printArray(numbers, 5);
    
    return 0;
}
```

**Output:**
```
10 20 30 40 50
```

**Important notes:**
- You must pass the size separately
- Changes to array inside function affect the original array
- The size is not included in the array parameter

### Modifying Arrays in Functions

```cpp
#include <iostream>
using namespace std;

void doubleValues(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] *= 2;
    }
}

int main() {
    int numbers[5] = {1, 2, 3, 4, 5};
    
    cout << "Before: ";
    for (int i = 0; i < 5; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;
    
    doubleValues(numbers, 5);
    
    cout << "After: ";
    for (int i = 0; i < 5; i++) {
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

### Returning Values from Array Functions

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
    int numbers[5] = {10, 20, 30, 40, 50};
    
    int total = sumArray(numbers, 5);
    cout << "Sum: " << total << endl;
    
    return 0;
}
```

**Output:**
```
Sum: 150
```

### Finding Max with Function

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
    int numbers[6] = {45, 12, 67, 23, 91, 8};
    
    int maximum = findMax(numbers, 6);
    cout << "Maximum: " << maximum << endl;
    
    return 0;
}
```

**Output:**
```
Maximum: 91
```

---

## Common Mistakes

### Mistake 1: Array Index Out of Bounds

**Wrong:**
```cpp
int numbers[5] = {10, 20, 30, 40, 50};
cout << numbers[5];  // Error! Valid indices: 0-4
```

**Correct:**
```cpp
int numbers[5] = {10, 20, 30, 40, 50};
cout << numbers[4];  // Correct: Last element
```

### Mistake 2: Not Initializing Arrays

**Wrong:**
```cpp
int numbers[5];
for (int i = 0; i < 5; i++) {
    cout << numbers[i];  // Garbage values
}
```

**Correct:**
```cpp
int numbers[5] = {0};  // Initialize all to 0
```

### Mistake 3: Using = to Compare or Copy

**Wrong:**
```cpp
int arr1[5] = {1, 2, 3, 4, 5};
int arr2[5] = {1, 2, 3, 4, 5};
if (arr1 == arr2) { }  // Compares addresses, not content
```

**Correct:**
```cpp
bool equal = true;
for (int i = 0; i < 5; i++) {
    if (arr1[i] != arr2[i]) {
        equal = false;
        break;
    }
}
```

### Mistake 4: Forgetting Array Size in Functions

**Wrong:**
```cpp
void printArray(int arr[]) {
    // How many elements to print?
}
```

**Correct:**
```cpp
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}
```

### Mistake 5: Off-by-One Errors

**Wrong:**
```cpp
int numbers[5] = {10, 20, 30, 40, 50};
for (int i = 0; i <= 5; i++) {  // Goes to index 5!
    cout << numbers[i];
}
```

**Correct:**
```cpp
int numbers[5] = {10, 20, 30, 40, 50};
for (int i = 0; i < 5; i++) {  // Stops at index 4
    cout << numbers[i];
}
```

---

## Practice Exercises

### Exercise 1: Find Second Largest

Write a program that finds the second largest element in an array.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int numbers[] = {45, 12, 67, 23, 91, 8, 34};
    int size = 7;
    
    int max = numbers[0];
    int secondMax = numbers[0];
    
    for (int i = 1; i < size; i++) {
        if (numbers[i] > max) {
            secondMax = max;
            max = numbers[i];
        } else if (numbers[i] > secondMax && numbers[i] != max) {
            secondMax = numbers[i];
        }
    }
    
    cout << "Second largest: " << secondMax << endl;
    
    return 0;
}
```

**Output:**
```
Second largest: 67
```
</details>

---

### Exercise 2: Count Even Numbers

Write a program that counts how many even numbers are in an array.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int numbers[] = {12, 15, 18, 21, 24, 27, 30};
    int size = 7;
    int count = 0;
    
    for (int i = 0; i < size; i++) {
        if (numbers[i] % 2 == 0) {
            count++;
        }
    }
    
    cout << "Even numbers: " << count << endl;
    
    return 0;
}
```

**Output:**
```
Even numbers: 4
```
</details>

---

### Exercise 3: Find All Occurrences

Write a program that finds all positions (indices) where a specific value appears in an array.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int numbers[] = {5, 3, 5, 7, 5, 2, 9, 5};
    int size = 8;
    int target = 5;
    
    cout << "Positions where " << target << " appears: ";
    
    for (int i = 0; i < size; i++) {
        if (numbers[i] == target) {
            cout << i << " ";
        }
    }
    cout << endl;
    
    return 0;
}
```

**Output:**
```
Positions where 5 appears: 0 2 4 7
```
</details>

---

### Exercise 4: Shift Array Left

Write a function that shifts all elements of an array one position to the left (first element goes to the end).

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

void shiftLeft(int arr[], int size) {
    int first = arr[0];
    
    for (int i = 0; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    
    arr[size - 1] = first;
}

int main() {
    int numbers[] = {1, 2, 3, 4, 5};
    int size = 5;
    
    cout << "Before: ";
    for (int i = 0; i < size; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;
    
    shiftLeft(numbers, size);
    
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
After: 2 3 4 5 1
```
</details>

---

### Exercise 5: Check if Array is Sorted

Write a function that checks if an array is sorted in ascending order.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

bool isSorted(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {1, 3, 2, 4, 5};
    
    if (isSorted(arr1, 5)) {
        cout << "Array 1 is sorted" << endl;
    }
    
    if (!isSorted(arr2, 5)) {
        cout << "Array 2 is not sorted" << endl;
    }
    
    return 0;
}
```

**Output:**
```
Array 1 is sorted
Array 2 is not sorted
```
</details>

---

### Exercise 6: Remove Element

Write a function that removes an element at a given index by shifting all elements after it to the left.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int removeElement(int arr[], int size, int index) {
    if (index < 0 || index >= size) {
        return size;  // Invalid index
    }
    
    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    
    return size - 1;  // New size
}

int main() {
    int numbers[] = {10, 20, 30, 40, 50};
    int size = 5;
    
    cout << "Before: ";
    for (int i = 0; i < size; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;
    
    size = removeElement(numbers, size, 2);  // Remove index 2
    
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
Before: 10 20 30 40 50
After: 10 20 40 50
```
</details>

---

### Exercise 7: Merge Two Arrays

Write a function that merges two sorted arrays into a third sorted array.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

void mergeArrays(int arr1[], int size1, int arr2[], int size2, int result[]) {
    int i = 0, j = 0, k = 0;
    
    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            result[k++] = arr1[i++];
        } else {
            result[k++] = arr2[j++];
        }
    }
    
    while (i < size1) {
        result[k++] = arr1[i++];
    }
    
    while (j < size2) {
        result[k++] = arr2[j++];
    }
}

int main() {
    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {2, 4, 6, 8};
    int result[8];
    
    mergeArrays(arr1, 4, arr2, 4, result);
    
    cout << "Merged: ";
    for (int i = 0; i < 8; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    
    return 0;
}
```

**Output:**
```
Merged: 1 2 3 4 5 6 7 8
```
</details>

---

### Exercise 8: Find Missing Number

Write a program that finds the missing number in an array containing numbers from 1 to n with one number missing.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int numbers[] = {1, 2, 3, 5, 6, 7, 8, 9, 10};
    int size = 9;
    int n = 10;  // Should contain numbers 1 to 10
    
    // Sum of 1 to n: n * (n + 1) / 2
    int expectedSum = n * (n + 1) / 2;
    
    int actualSum = 0;
    for (int i = 0; i < size; i++) {
        actualSum += numbers[i];
    }
    
    int missing = expectedSum - actualSum;
    
    cout << "Missing number: " << missing << endl;
    
    return 0;
}
```

**Output:**
```
Missing number: 4
```
</details>

---

## Summary

### What We Learned Today

- **Arrays** - Collections of elements of the same type
- **Declaration** - `dataType arrayName[size];`
- **Zero-based indexing** - First element is at index 0
- **Initialization** - Multiple ways to initialize arrays
- **Accessing elements** - Using index: `array[index]`
- **Looping** - Using for loops to process all elements
- **Common operations** - Sum, average, max, min, search, reverse
- **Arrays and functions** - Must pass size separately
- **Array modification** - Elements can be changed, entire array cannot be assigned

---

## Key Takeaways

1. **Arrays store multiple values** - All of the same type
2. **Zero-based indexing** - First element is index 0, last is size-1
3. **Fixed size** - Cannot change size after declaration
4. **Use loops** - Process arrays efficiently with for loops
5. **Pass size to functions** - Arrays don't carry size information
6. **Cannot use = operator** - Must copy or compare element by element
7. **Watch array bounds** - Accessing beyond size causes errors

---

## Next Lecture Preview

In the next lecture, we will learn about:
- Character arrays and strings
- C-style string operations
- The C++ string class
- String manipulation

---

## Homework

**Assignment 1:** Write a program that reads 10 numbers into an array, then finds and displays all prime numbers in the array.

**Assignment 2:** Create a function that rotates an array to the right by n positions. For example, rotating {1, 2, 3, 4, 5} right by 2 gives {4, 5, 1, 2, 3}.

**Assignment 3:** Write a program that reads two arrays of the same size and checks if one is a rotation of the other. For example, {1, 2, 3, 4, 5} and {3, 4, 5, 1, 2} are rotations of each other.

---

## Resources

- [cppreference.com - Arrays](https://en.cppreference.com/w/cpp/language/array)
- [learncpp.com - Arrays](https://www.learncpp.com/cpp-tutorial/introduction-to-arrays/)

---

**Practice with arrays to build a strong foundation for more advanced topics.**
