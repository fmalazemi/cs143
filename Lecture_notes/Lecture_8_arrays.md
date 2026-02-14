# Lecture 8: Arrays, Vectors, and Strings in C++

## Welcome

In previous lectures, you learned about functions and how to pass individual values. Now you will learn how to work with collections of data using arrays, vectors, and strings.

**Why collections are important:**
- Store multiple related values together
- Process large amounts of data efficiently
- Work with text and sequences
- Build more complex programs

---

## Table of Contents

1. [Introduction to Arrays](#introduction-to-arrays)
2. [One-Dimensional Arrays](#one-dimensional-arrays)
3. [Array Operations](#array-operations)
4. [Multidimensional Arrays](#multidimensional-arrays)
5. [Introduction to Vectors](#introduction-to-vectors)
6. [Strings as Character Arrays](#strings-as-character-arrays)
7. [String Class](#string-class)
8. [Common Mistakes](#common-mistakes)
9. [Practice Exercises](#practice-exercises)
10. [Summary](#summary)

---

## Introduction to Arrays

An **array** is a collection of elements of the same type stored in consecutive memory locations.

**Real-world analogy:**
Think of an array like a row of mailboxes. Each mailbox has a number (index) and can store one item.

### Why Use Arrays?

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

**Benefits:**
- Store multiple values under one name
- Access elements using index
- Process data using loops
- Pass collections to functions

---

## One-Dimensional Arrays

### Array Declaration

```cpp
dataType arrayName[size];
```

**Examples:**
```cpp
int numbers[5];        // Array of 5 integers
double prices[10];     // Array of 10 doubles
char letters[26];      // Array of 26 characters
```

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
int numbers[] = {10, 20, 30, 40, 50};  // Size is 5
```

### Accessing Array Elements

Arrays use **zero-based indexing** - the first element is at index 0.

```cpp
int numbers[5] = {10, 20, 30, 40, 50};

cout << numbers[0];  // Output: 10 (first element)
cout << numbers[1];  // Output: 20 (second element)
cout << numbers[4];  // Output: 50 (last element)
```

**Index range:** For an array of size n, valid indices are 0 to n-1.

### Modifying Array Elements

```cpp
int numbers[5] = {10, 20, 30, 40, 50};

numbers[0] = 100;   // Change first element
numbers[2] = 300;   // Change third element

// Array is now: {100, 20, 300, 40, 50}
```

### Looping Through Arrays

**Using for loop:**
```cpp
#include <iostream>
using namespace std;

int main() {
    int numbers[5] = {10, 20, 30, 40, 50};
    
    for (int i = 0; i < 5; i++) {
        cout << numbers[i] << " ";
    }
    
    return 0;
}
```

**Output:**
```
10 20 30 40 50
```

---

## Array Operations

### Finding Maximum Element

```cpp
#include <iostream>
using namespace std;

int main() {
    int numbers[6] = {45, 12, 67, 23, 91, 8};
    int max = numbers[0];
    
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

### Calculating Sum and Average

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
    int index = -1;
    
    for (int i = 0; i < 5; i++) {
        if (numbers[i] == target) {
            index = i;
            break;
        }
    }
    
    if (index != -1) {
        cout << "Found at index " << index << endl;
    } else {
        cout << "Not found" << endl;
    }
    
    return 0;
}
```

**Output:**
```
Found at index 2
```

### Reversing an Array

```cpp
#include <iostream>
using namespace std;

int main() {
    int numbers[5] = {1, 2, 3, 4, 5};
    int start = 0;
    int end = 4;
    
    while (start < end) {
        // Swap elements
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

You cannot copy arrays using assignment operator. You must copy element by element.

**Wrong:**
```cpp
int arr1[5] = {1, 2, 3, 4, 5};
int arr2[5];
arr2 = arr1;  // Error! Cannot assign arrays
```

**Correct:**
```cpp
int arr1[5] = {1, 2, 3, 4, 5};
int arr2[5];

for (int i = 0; i < 5; i++) {
    arr2[i] = arr1[i];
}
```

---

## Multidimensional Arrays

A **multidimensional array** is an array of arrays. The most common is a two-dimensional array (like a table or matrix).

### Two-Dimensional Arrays

**Declaration:**
```cpp
dataType arrayName[rows][columns];
```

**Example:**
```cpp
int matrix[3][4];  // 3 rows, 4 columns (12 elements total)
```

### Initializing 2D Arrays

**Method 1: Row by row**
```cpp
int matrix[3][4] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12}
};
```

**Method 2: Flat initialization**
```cpp
int matrix[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
```

**Method 3: Partial initialization**
```cpp
int matrix[3][4] = {
    {1, 2},
    {5, 6},
    {9, 10}
};
// Uninitialized elements become 0
```

### Accessing 2D Array Elements

```cpp
int matrix[3][4] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12}
};

cout << matrix[0][0];  // Output: 1  (row 0, column 0)
cout << matrix[1][2];  // Output: 7  (row 1, column 2)
cout << matrix[2][3];  // Output: 12 (row 2, column 3)
```

### Looping Through 2D Arrays

**Nested loops:**
```cpp
#include <iostream>
using namespace std;

int main() {
    int matrix[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    
    for (int i = 0; i < 3; i++) {        // Rows
        for (int j = 0; j < 4; j++) {    // Columns
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
```

**Output:**
```
1 2 3 4
5 6 7 8
9 10 11 12
```

### 2D Array Example: Student Grades

```cpp
#include <iostream>
using namespace std;

int main() {
    // 3 students, 4 subjects
    int grades[3][4] = {
        {85, 90, 78, 92},  // Student 0
        {88, 76, 95, 89},  // Student 1
        {92, 88, 84, 90}   // Student 2
    };
    
    // Calculate average for each student
    for (int i = 0; i < 3; i++) {
        int sum = 0;
        for (int j = 0; j < 4; j++) {
            sum += grades[i][j];
        }
        double average = sum / 4.0;
        cout << "Student " << i << " average: " << average << endl;
    }
    
    return 0;
}
```

**Output:**
```
Student 0 average: 86.25
Student 1 average: 87
Student 2 average: 88.5
```

### Three-Dimensional Arrays

You can create arrays with more than two dimensions.

```cpp
int cube[3][4][5];  // 3 layers, 4 rows, 5 columns

// Accessing element
cube[0][2][3] = 100;

// Looping through 3D array
for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
        for (int k = 0; k < 5; k++) {
            cout << cube[i][j][k] << " ";
        }
    }
}
```

---

## Introduction to Vectors

A **vector** is a dynamic array from the C++ Standard Library. Unlike arrays, vectors can grow and shrink in size.

### Why Use Vectors?

**Arrays:**
- Fixed size (must know size at compile time)
- Cannot resize
- Manual memory management

**Vectors:**
- Dynamic size (can grow and shrink)
- Built-in functions for common operations
- Automatic memory management

### Including Vector Library

```cpp
#include <vector>
using namespace std;
```

### Declaring Vectors

```cpp
vector<int> numbers;           // Empty vector of integers
vector<double> prices(10);     // Vector of 10 doubles (default 0)
vector<string> names(5, "");   // Vector of 5 empty strings
```

### Initializing Vectors

```cpp
vector<int> numbers = {10, 20, 30, 40, 50};
vector<double> prices = {9.99, 19.99, 29.99};
vector<string> names = {"Alice", "Bob", "Charlie"};
```

### Accessing Vector Elements

**Using index (like arrays):**
```cpp
vector<int> numbers = {10, 20, 30, 40, 50};

cout << numbers[0];  // Output: 10
cout << numbers[2];  // Output: 30
```

**Using at() method (with bounds checking):**
```cpp
cout << numbers.at(0);  // Output: 10
// numbers.at(10);      // Throws error if out of bounds
```

### Common Vector Operations

**Get size:**
```cpp
vector<int> numbers = {10, 20, 30, 40, 50};
cout << numbers.size();  // Output: 5
```

**Add elements (push_back):**
```cpp
vector<int> numbers;
numbers.push_back(10);
numbers.push_back(20);
numbers.push_back(30);
// Vector is now: {10, 20, 30}
```

**Remove last element (pop_back):**
```cpp
vector<int> numbers = {10, 20, 30, 40, 50};
numbers.pop_back();
// Vector is now: {10, 20, 30, 40}
```

**Check if empty:**
```cpp
vector<int> numbers;
if (numbers.empty()) {
    cout << "Vector is empty" << endl;
}
```

**Clear all elements:**
```cpp
vector<int> numbers = {10, 20, 30, 40, 50};
numbers.clear();
// Vector is now empty
```

### Looping Through Vectors

**Using traditional for loop:**
```cpp
vector<int> numbers = {10, 20, 30, 40, 50};

for (int i = 0; i < numbers.size(); i++) {
    cout << numbers[i] << " ";
}
```

**Using range-based for loop (C++11):**
```cpp
vector<int> numbers = {10, 20, 30, 40, 50};

for (int num : numbers) {
    cout << num << " ";
}
```

### Vector Example: Dynamic Input

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> numbers;
    int input;
    
    cout << "Enter numbers (0 to stop):" << endl;
    
    while (true) {
        cin >> input;
        if (input == 0) break;
        numbers.push_back(input);
    }
    
    cout << "You entered " << numbers.size() << " numbers:" << endl;
    for (int num : numbers) {
        cout << num << " ";
    }
    
    return 0;
}
```

**Sample Run:**
```
Enter numbers (0 to stop):
15
23
8
42
0
You entered 4 numbers:
15 23 8 42
```

### Two-Dimensional Vectors

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Create 3x4 matrix
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    
    // Access elements
    cout << matrix[1][2] << endl;  // Output: 7
    
    // Loop through
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
```

---

## Strings as Character Arrays

In C++, you can represent strings as arrays of characters.

### Character Arrays

```cpp
char name[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
// Note: Must include null terminator '\0'
```

**Easier initialization:**
```cpp
char name[6] = "Hello";  // Automatically adds '\0'
```

### Null Terminator

The null terminator `'\0'` marks the end of the string. Without it, functions do not know where the string ends.

```cpp
char str1[6] = "Hello";     // Correct: "Hello\0"
char str2[5] = {'H', 'i'};  // Requires manual null terminator
```

### Reading Character Arrays

```cpp
#include <iostream>
using namespace std;

int main() {
    char name[50];
    
    cout << "Enter your name: ";
    cin >> name;  // Reads until whitespace
    
    cout << "Hello, " << name << endl;
    
    return 0;
}
```

### Reading Full Lines

```cpp
#include <iostream>
using namespace std;

int main() {
    char sentence[100];
    
    cout << "Enter a sentence: ";
    cin.getline(sentence, 100);  // Reads entire line
    
    cout << "You said: " << sentence << endl;
    
    return 0;
}
```

### String Length

```cpp
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char text[20] = "Hello";
    
    int length = strlen(text);  // From <cstring>
    cout << "Length: " << length << endl;  // Output: 5
    
    return 0;
}
```

### String Copying

```cpp
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char source[20] = "Hello";
    char destination[20];
    
    strcpy(destination, source);  // Copy source to destination
    cout << destination << endl;  // Output: Hello
    
    return 0;
}
```

### String Concatenation

```cpp
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char str1[20] = "Hello ";
    char str2[20] = "World";
    
    strcat(str1, str2);  // Append str2 to str1
    cout << str1 << endl;  // Output: Hello World
    
    return 0;
}
```

### String Comparison

```cpp
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char str1[20] = "Hello";
    char str2[20] = "Hello";
    char str3[20] = "World";
    
    if (strcmp(str1, str2) == 0) {
        cout << "str1 and str2 are equal" << endl;
    }
    
    if (strcmp(str1, str3) != 0) {
        cout << "str1 and str3 are different" << endl;
    }
    
    return 0;
}
```

---

## String Class

C++ provides a `string` class that is much easier to use than character arrays.

### Including String Library

```cpp
#include <string>
using namespace std;
```

### Declaring and Initializing Strings

```cpp
string name;                    // Empty string
string greeting = "Hello";      // Initialize with value
string message("Welcome");      // Constructor syntax
```

### String Input and Output

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string name;
    
    cout << "Enter your name: ";
    cin >> name;  // Reads until whitespace
    
    cout << "Hello, " << name << endl;
    
    return 0;
}
```

**Reading full line:**
```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string sentence;
    
    cout << "Enter a sentence: ";
    getline(cin, sentence);  // Reads entire line
    
    cout << "You said: " << sentence << endl;
    
    return 0;
}
```

### String Operations

**Get length:**
```cpp
string text = "Hello World";
cout << text.length() << endl;  // Output: 11
cout << text.size() << endl;    // Output: 11 (same as length)
```

**Concatenation:**
```cpp
string first = "Hello";
string second = "World";
string combined = first + " " + second;
cout << combined << endl;  // Output: Hello World
```

**Append:**
```cpp
string text = "Hello";
text += " World";
cout << text << endl;  // Output: Hello World
```

**Access characters:**
```cpp
string text = "Hello";
cout << text[0] << endl;     // Output: H
cout << text.at(1) << endl;  // Output: e
```

**Modify characters:**
```cpp
string text = "Hello";
text[0] = 'h';
cout << text << endl;  // Output: hello
```

**Substring:**
```cpp
string text = "Hello World";
string sub = text.substr(0, 5);  // Start at 0, length 5
cout << sub << endl;  // Output: Hello
```

**Find:**
```cpp
string text = "Hello World";
int pos = text.find("World");
if (pos != string::npos) {
    cout << "Found at position " << pos << endl;  // Output: Found at position 6
}
```

**Replace:**
```cpp
string text = "Hello World";
text.replace(6, 5, "C++");  // Replace starting at 6, length 5
cout << text << endl;  // Output: Hello C++
```

**Insert:**
```cpp
string text = "Hello World";
text.insert(6, "Beautiful ");
cout << text << endl;  // Output: Hello Beautiful World
```

**Erase:**
```cpp
string text = "Hello World";
text.erase(5, 6);  // Erase starting at 5, length 6
cout << text << endl;  // Output: Hello
```

**Clear:**
```cpp
string text = "Hello";
text.clear();
if (text.empty()) {
    cout << "String is empty" << endl;
}
```

**Compare:**
```cpp
string str1 = "Apple";
string str2 = "Banana";

if (str1 == str2) {
    cout << "Equal" << endl;
} else {
    cout << "Not equal" << endl;
}

if (str1 < str2) {
    cout << "str1 comes before str2" << endl;
}
```

### String Example: Word Counter

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string text;
    
    cout << "Enter a sentence: ";
    getline(cin, text);
    
    int words = 1;  // At least one word if not empty
    
    if (text.empty()) {
        words = 0;
    } else {
        for (int i = 0; i < text.length(); i++) {
            if (text[i] == ' ') {
                words++;
            }
        }
    }
    
    cout << "Number of words: " << words << endl;
    
    return 0;
}
```

### String to Number Conversion

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string numStr = "123";
    
    int num = stoi(numStr);     // String to integer
    double d = stod("3.14");    // String to double
    long l = stol("123456");    // String to long
    
    cout << num + 10 << endl;   // Output: 133
    cout << d * 2 << endl;      // Output: 6.28
    
    return 0;
}
```

### Number to String Conversion

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    int num = 123;
    double d = 3.14;
    
    string str1 = to_string(num);
    string str2 = to_string(d);
    
    cout << "String: " << str1 << endl;  // Output: String: 123
    cout << "String: " << str2 << endl;  // Output: String: 3.140000
    
    return 0;
}
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

### Mistake 2: Forgetting Null Terminator

**Wrong:**
```cpp
char name[5] = {'H', 'e', 'l', 'l', 'o'};
cout << name;  // Undefined behavior - no null terminator
```

**Correct:**
```cpp
char name[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
// Or simply:
char name[6] = "Hello";
```

### Mistake 3: Comparing Arrays with ==

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

**For strings, use strcmp or string class:**
```cpp
string str1 = "Hello";
string str2 = "Hello";
if (str1 == str2) {  // Correct with string class
    cout << "Equal" << endl;
}
```

### Mistake 4: Not Initializing Arrays

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

### Mistake 5: Using size() with Regular Arrays

**Wrong:**
```cpp
int numbers[5] = {10, 20, 30, 40, 50};
for (int i = 0; i < numbers.size(); i++) {  // Error!
    cout << numbers[i];
}
```

**Correct:**
```cpp
int numbers[5] = {10, 20, 30, 40, 50};
for (int i = 0; i < 5; i++) {  // Use actual size
    cout << numbers[i];
}

// Or use vector:
vector<int> numbers = {10, 20, 30, 40, 50};
for (int i = 0; i < numbers.size(); i++) {  // Works!
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
</details>

---

### Exercise 2: Matrix Addition

Write a program that adds two 2D matrices.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int matrix1[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int matrix2[2][3] = {{7, 8, 9}, {10, 11, 12}};
    int result[2][3];
    
    // Add matrices
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    
    // Display result
    cout << "Result:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
```
</details>

---

### Exercise 3: Remove Duplicates from Vector

Write a function that removes duplicate values from a vector.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
#include <vector>
using namespace std;

vector<int> removeDuplicates(vector<int> vec) {
    vector<int> result;
    
    for (int i = 0; i < vec.size(); i++) {
        bool found = false;
        for (int j = 0; j < result.size(); j++) {
            if (vec[i] == result[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            result.push_back(vec[i]);
        }
    }
    
    return result;
}

int main() {
    vector<int> numbers = {1, 2, 3, 2, 4, 1, 5, 3};
    vector<int> unique = removeDuplicates(numbers);
    
    cout << "Unique elements: ";
    for (int num : unique) {
        cout << num << " ";
    }
    
    return 0;
}
```
</details>

---

### Exercise 4: Count Vowels and Consonants

Write a program that counts vowels and consonants in a string.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string text;
    int vowels = 0, consonants = 0;
    
    cout << "Enter text: ";
    getline(cin, text);
    
    for (int i = 0; i < text.length(); i++) {
        char c = tolower(text[i]);
        
        if (isalpha(c)) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                vowels++;
            } else {
                consonants++;
            }
        }
    }
    
    cout << "Vowels: " << vowels << endl;
    cout << "Consonants: " << consonants << endl;
    
    return 0;
}
```
</details>

---

### Exercise 5: Transpose Matrix

Write a program that transposes a matrix (swap rows and columns).

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int matrix[3][2] = {{1, 2}, {3, 4}, {5, 6}};
    int transpose[2][3];
    
    // Transpose
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }
    
    // Display
    cout << "Original:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << "\nTranspose:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << transpose[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
```
</details>

---

### Exercise 6: Palindrome Checker

Write a function that checks if a string is a palindrome.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string str) {
    int start = 0;
    int end = str.length() - 1;
    
    while (start < end) {
        if (tolower(str[start]) != tolower(str[end])) {
            return false;
        }
        start++;
        end--;
    }
    
    return true;
}

int main() {
    string text;
    
    cout << "Enter a word: ";
    cin >> text;
    
    if (isPalindrome(text)) {
        cout << text << " is a palindrome" << endl;
    } else {
        cout << text << " is not a palindrome" << endl;
    }
    
    return 0;
}
```
</details>

---

### Exercise 7: Merge Two Sorted Vectors

Write a function that merges two sorted vectors into one sorted vector.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
#include <vector>
using namespace std;

vector<int> mergeSorted(vector<int> vec1, vector<int> vec2) {
    vector<int> result;
    int i = 0, j = 0;
    
    while (i < vec1.size() && j < vec2.size()) {
        if (vec1[i] < vec2[j]) {
            result.push_back(vec1[i]);
            i++;
        } else {
            result.push_back(vec2[j]);
            j++;
        }
    }
    
    // Add remaining elements
    while (i < vec1.size()) {
        result.push_back(vec1[i]);
        i++;
    }
    
    while (j < vec2.size()) {
        result.push_back(vec2[j]);
        j++;
    }
    
    return result;
}

int main() {
    vector<int> vec1 = {1, 3, 5, 7};
    vector<int> vec2 = {2, 4, 6, 8};
    
    vector<int> merged = mergeSorted(vec1, vec2);
    
    cout << "Merged: ";
    for (int num : merged) {
        cout << num << " ";
    }
    
    return 0;
}
```
</details>

---

### Exercise 8: Reverse Words in String

Write a program that reverses the order of words in a string.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string sentence;
    vector<string> words;
    
    cout << "Enter a sentence: ";
    getline(cin, sentence);
    
    // Extract words
    string word = "";
    for (int i = 0; i < sentence.length(); i++) {
        if (sentence[i] == ' ') {
            if (!word.empty()) {
                words.push_back(word);
                word = "";
            }
        } else {
            word += sentence[i];
        }
    }
    if (!word.empty()) {
        words.push_back(word);
    }
    
    // Print in reverse
    cout << "Reversed: ";
    for (int i = words.size() - 1; i >= 0; i--) {
        cout << words[i];
        if (i > 0) cout << " ";
    }
    cout << endl;
    
    return 0;
}
```
</details>

---

## Summary

### What We Learned Today

- **Arrays** - Fixed-size collections of same-type elements
- **Array operations** - Searching, sorting, reversing, finding max/min
- **Multidimensional arrays** - 2D and 3D arrays for matrices and tables
- **Vectors** - Dynamic arrays that can grow and shrink
- **Character arrays** - C-style strings with null terminator
- **String class** - Modern C++ strings with powerful operations

---

## Key Takeaways

1. **Arrays use zero-based indexing** - First element is at index 0
2. **Arrays are fixed size** - Cannot change size after declaration
3. **Vectors are dynamic** - Can grow and shrink as needed
4. **Null terminator is required** - For C-style strings (character arrays)
5. **String class is easier** - Use string class instead of char arrays when possible
6. **Bounds checking** - Always ensure index is within valid range
7. **2D arrays need nested loops** - One loop for rows, one for columns

---

## Next Lecture Preview

In the next lecture, we will learn about:
- Pointers and memory addresses
- Dynamic memory allocation
- Relationship between arrays and pointers
- Pointer arithmetic

---

## Homework

**Assignment 1:** Write a program that reads 10 integers into an array, then finds and displays all pairs of numbers that sum to a target value entered by the user.

**Assignment 2:** Create a grade management system using a 2D array. Store grades for 5 students across 4 subjects. Calculate and display each student's average, each subject's average, and the overall class average.

**Assignment 3:** Write a program using vectors that reads student names and scores. Allow the user to add, remove, search, and sort students by score. Display the top 3 students.

---

## Resources

- [cppreference.com - Arrays](https://en.cppreference.com/w/cpp/language/array)
- [cppreference.com - Vectors](https://en.cppreference.com/w/cpp/container/vector)
- [cppreference.com - Strings](https://en.cppreference.com/w/cpp/string/basic_string)
- [learncpp.com - Arrays](https://www.learncpp.com/cpp-tutorial/introduction-to-arrays/)

---

**Master arrays, vectors, and strings to work effectively with collections of data.**
