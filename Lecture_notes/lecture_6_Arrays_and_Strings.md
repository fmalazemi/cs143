# CS143 — Lecture 6: Arrays and Strings

**Course:** CS143 Introduction to C++
**Instructor:** Dr. Fawaz Alazemi
**Audience:** Students who completed CS101 (Python)

---

## Table of Contents

1. [Introduction](#1-introduction)
2. [Arrays: The Basics](#2-arrays-the-basics)
   - [2.1 Declaring Arrays](#21-declaring-arrays)
   - [2.2 Accessing Elements](#22-accessing-elements)
   - [2.3 How Arrays Live in Memory](#23-how-arrays-live-in-memory)
   - [2.4 Looping Through an Array](#24-looping-through-an-array)
3. [Common Array Operations](#3-common-array-operations)
4. [Strings](#4-strings)
   - [4.1 The string Type](#41-the-string-type)
   - [4.2 Reading Strings: cin vs getline](#42-reading-strings-cin-vs-getline)
   - [4.3 String Operations](#43-string-operations)
   - [4.4 Looping Over Characters](#44-looping-over-characters)
5. [Python vs. C++ Comparison](#5-python-vs-c-comparison)
6. [Common Mistakes](#6-common-mistakes)
7. [Practice Exercises](#7-practice-exercises)
8. [Summary](#8-summary)

---

## 1. Introduction

An **array** is a fixed-size group of values that share the same type and sit side by side in memory. Instead of creating five separate variables for five test scores, you create one array that holds all five. A **string** is a sequence of characters used to store text, such as a name or a sentence.

Why these topics matter:

- They let you store and process **many values** with a single name.
- They are the foundation for almost every larger program (lists of students, words in a sentence, pixels in an image).
- They make **loops** powerful: one loop can touch every value.
- They introduce the important idea of an **index** — a numbered position.

Helpful analogies for an array: a row of **mailboxes** (each with a number), a row of **parking spaces**, or an egg carton with numbered slots. You already met this idea in CS101 as a Python **list**. A C++ array is similar, with two key differences: every element must have the **same type**, and the **size is fixed** when you create it.

Use an array when you know roughly how many values you need and they are all the same type. Use a string whenever you work with text.

---

## 2. Arrays: The Basics

### 2.1 Declaring Arrays

To declare an array, you write the element **type**, the array **name**, and the **size** in square brackets. The size must be a whole number known in advance.

```cpp
#include <iostream>
using namespace std;

int main() {
    int scores[5];                       // 5 empty integer boxes
    int marks[5] = {90, 85, 70, 60, 95}; // declare and fill
    int data[] = {7, 8, 9};              // size counted for you: 3

    marks[0] = 100;                      // change the first box
    cout << marks[0] << endl;            // print the first box
    return 0;
}
```

**Output:**
```
100
```

The values inside the braces `{ }` fill the boxes in order. If you give a size but no values, the boxes start with unknown contents, so you should fill them before reading them.

### 2.2 Accessing Elements

You reach one element by writing the array name followed by an **index** inside `[ ]`. Indexing starts at **0**, exactly like Python. For an array of size 5, the valid indices are `0, 1, 2, 3, 4`.

```cpp
#include <iostream>
using namespace std;

int main() {
    int scores[5] = {90, 85, 70, 60, 95};

    cout << scores[0] << endl;   // first element
    cout << scores[2] << endl;   // third element
    cout << scores[4] << endl;   // last element (size - 1)
    return 0;
}
```

**Output:**
```
90
70
95
```

A picture of the access pattern (`scores[2]` points to the box at index 2):

```
            scores[2]
                |
                v
        +-----+-----+-----+-----+-----+
 value  | 90  | 85  | 70  | 60  | 95  |
        +-----+-----+-----+-----+-----+
 index    [0]   [1]   [2]   [3]   [4]
```

The last valid index is always **size − 1**.

### 2.3 How Arrays Live in Memory

Computer memory is a long line of numbered storage cells called **bytes**. An array's elements are stored **contiguously**, meaning side by side with no gaps. If each `int` takes 4 bytes, then the starting address of each element grows by 4.

```
 array element     scores[0] scores[1] scores[2] scores[3] scores[4]
                   +--------+--------+--------+--------+--------+
 value             |   90   |   85   |   70   |   60   |   95   |
                   +--------+--------+--------+--------+--------+
 memory address      1000     1004     1008     1012     1016
                     \____ each element is 4 bytes apart ____/

 address of scores[i] = base_address + i * sizeof(int)
                      = 1000 + i * 4
```

Because the elements are evenly spaced, the computer can calculate the location of `scores[i]` with a single multiplication and jump straight to it. This is why reading any element of an array is instant and does not require searching. The address of the first element (here `1000`) is called the **base address**.

> Note: `sizeof(int)` is **usually** 4 bytes, but this can vary by system. The principle — equal spacing — is what matters.

### 2.4 Looping Through an Array

The most common task is visiting every element with a `for` loop. Start the counter at `0` and continue while it is **less than** the size. The counter then serves as the index.

```cpp
#include <iostream>
using namespace std;

int main() {
    int scores[5] = {90, 85, 70, 60, 95};

    for (int i = 0; i < 5; i++) {
        cout << "scores[" << i << "] = " << scores[i] << endl;
    }
    return 0;
}
```

**Output:**
```
scores[0] = 90
scores[1] = 85
scores[2] = 70
scores[3] = 60
scores[4] = 95
```

Notice the condition is `i < 5`, not `i <= 5`. Using `i <= 5` would try to read `scores[5]`, which is past the end of the array.

---

## 3. Common Array Operations

This section shows three complete programs for the operations you will use most often.

**Example 1 — Sum and average.** This walks through every element, adding each value to a running total (an *accumulator*), then divides by the count.

```cpp
#include <iostream>
using namespace std;

int main() {
    int a[5] = {10, 20, 30, 40, 50};
    int sum = 0;

    for (int i = 0; i < 5; i++) {
        sum += a[i];
    }
    cout << "Sum = " << sum << endl;
    cout << "Average = " << sum / 5 << endl;
    return 0;
}
```

**Output:**
```
Sum = 150
Average = 30
```

**Example 2 — Find the largest value.** This assumes the first element is the largest, then checks every other element and updates when it finds a bigger one.

```cpp
#include <iostream>
using namespace std;

int main() {
    int a[5] = {12, 45, 7, 99, 30};
    int biggest = a[0];           // start with the first element

    for (int i = 1; i < 5; i++) { // start at 1: index 0 is the guess
        if (a[i] > biggest) {
            biggest = a[i];
        }
    }
    cout << "Largest = " << biggest << endl;
    return 0;
}
```

**Output:**
```
Largest = 99
```

**Example 3 — Print in reverse.** This counts the index **down** from the last position to zero.

```cpp
#include <iostream>
using namespace std;

int main() {
    int a[5] = {1, 2, 3, 4, 5};

    for (int i = 4; i >= 0; i--) {  // 4, 3, 2, 1, 0
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
```

**Output:**
```
5 4 3 2 1
```

---

## 4. Strings

### 4.1 The string Type

C++ provides a friendly `string` type for text. You must include the `<string>` library before you use it. A string knows its own length through `s.length()`.

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string name = "Sara";
    cout << name << endl;           // Sara
    cout << name.length() << endl;  // 4
    return 0;
}
```

**Output:**
```
Sara
4
```

Where Python uses `len(name)`, C++ uses `name.length()`. Both count the characters.

### 4.2 Reading Strings: cin vs getline

There are two common ways to read text. The operator `cin >>` reads a **single word** and stops at the first space. The function `getline` reads an **entire line**, including spaces.

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string word;
    cout << "Enter a word: ";
    cin >> word;                 // stops at the first space
    cout << "You typed: " << word << endl;

    string line;
    cout << "Enter a full line: ";
    cin.ignore();                // clear the leftover newline
    getline(cin, line);          // reads spaces too
    cout << "Line: " << line << endl;
    return 0;
}
```

**Output (input `Hello` then `Good morning`):**
```
Enter a word: Hello
You typed: Hello
Enter a full line: Good morning
Line: Good morning
```

Choose `cin >>` for a single word and `getline` when the text may contain spaces, such as a full name.

### 4.3 String Operations

You can join strings with the `+` operator (called **concatenation**) and read any character with `[ ]`, just like an array.

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string first = "Ali";
    string last  = "Hassan";

    string full = first + " " + last;   // join with +
    cout << full << endl;               // Ali Hassan
    cout << "First letter: " << full[0] << endl;
    cout << "Length: " << full.length() << endl;
    return 0;
}
```

**Output:**
```
Ali Hassan
First letter: A
Length: 10
```

A string is internally a sequence of characters, each at an index from 0:

```
 string s = "Hello"
        +---+---+---+---+---+
 char   | H | e | l | l | o |
        +---+---+---+---+---+
 index   [0] [1] [2] [3] [4]

 s[0] is 'H'    s.length() is 5    last index is 4
```

### 4.4 Looping Over Characters

To examine each character, loop from `0` to `length() - 1`. Storing the length in an `int` first keeps the loop clean.

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string word;
    cin >> word;
    int count = 0;

    int n = word.length();
    for (int i = 0; i < n; i++) {
        char ch = word[i];
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            count++;
        }
    }
    cout << "Vowels: " << count << endl;
    return 0;
}
```

**Output (input `education`):**
```
Vowels: 5
```

This program combines a loop, string indexing, and an `if` condition — the three skills from earlier lectures working together.

---

## 5. Python vs. C++ Comparison

| Task | Python | C++ |
| --- | --- | --- |
| Make a list / array | `a = [1, 2, 3]` | `int a[3] = {1, 2, 3};` |
| First element | `a[0]` | `a[0]` |
| Can it grow? | Yes (`append`) | No (fixed size) |
| Element types | mixed allowed | all the same type |
| Text length | `len(s)` | `s.length()` |
| Join text | `a + b` | `a + b` |
| Read a word | `input()` | `cin >> s;` |
| Read a full line | `input()` | `getline(cin, s);` |

The biggest mental shift for a Python programmer is that a C++ array has a **fixed size** and a **single type**, and C++ does **not** check whether your index is in range.

---

## 6. Common Mistakes

**1. Reading past the end of the array (out of range)**

**Wrong:**
```cpp
int a[5];
for (int i = 0; i <= 5; i++) {   // i reaches 5 -> out of range
    cin >> a[i];
}
```

**Correct:**
```cpp
int a[5];
for (int i = 0; i < 5; i++) {    // valid indices are 0..4
    cin >> a[i];
}
```

**Explanation:** For `int a[5]`, the only valid indices are 0 to 4. Index 5 is past the last box. C++ does not warn you; it silently reads or writes the wrong memory, which causes bugs or crashes. The last valid index is always **size − 1**.

---

**2. Forgetting the `<string>` header**

**Wrong:**
```cpp
#include <iostream>
using namespace std;
int main() {
    string name = "Sara";   // error: 'string' not declared
}
```

**Correct:**
```cpp
#include <iostream>
#include <string>
using namespace std;
int main() {
    string name = "Sara";   // works
}
```

**Explanation:** The `string` type lives in the `<string>` library. Without that include, the compiler does not recognise `string`.

---

**3. Expecting `cin >>` to read a whole line**

**Wrong:**
```cpp
string name;
cin >> name;            // input "Sara Ali" -> name is only "Sara"
```

**Correct:**
```cpp
string name;
getline(cin, name);     // input "Sara Ali" -> name is "Sara Ali"
```

**Explanation:** `cin >>` stops at the first space, so it captures only one word. Use `getline` when the text may contain spaces.

---

**4. Confusing single quotes and double quotes**

**Wrong:**
```cpp
string letter = 'A';    // 'A' is a single character, not a string
```

**Correct:**
```cpp
string letter = "A";    // "A" is a string
char  initial = 'A';    // 'A' is a char
```

**Explanation:** Double quotes `"A"` make a **string**; single quotes `'A'` make a single **char**. Using the wrong one causes a type error.

---

**5. Using `i <= length()` when looping over a string**

**Wrong:**
```cpp
int n = word.length();
for (int i = 0; i <= n; i++) {   // i reaches n -> past the last char
    cout << word[i];
}
```

**Correct:**
```cpp
int n = word.length();
for (int i = 0; i < n; i++) {    // last valid index is n - 1
    cout << word[i];
}
```

**Explanation:** Just like arrays, the last valid character index is `length() - 1`. The condition must be `i < n`, not `i <= n`.

---

## 7. Practice Exercises

Exercises increase in difficulty. Write a complete program for each one and test it.

**Exercise 1 (Array).** Read 5 integers into an array, then print them in reverse order.
*Expected behaviour:* input `1 2 3 4 5` prints `5 4 3 2 1`.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int a[5];
    for (int i = 0; i < 5; i++) cin >> a[i];
    for (int i = 4; i >= 0; i--) cout << a[i] << " ";
    cout << endl;
    return 0;
}
```
</details>

**Exercise 2 (Array).** Read 5 integers into an array and print the smallest value.
*Expected behaviour:* input `12 4 8 1 9` prints `Smallest = 1`.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int a[5];
    for (int i = 0; i < 5; i++) cin >> a[i];
    int small = a[0];
    for (int i = 1; i < 5; i++) {
        if (a[i] < small) small = a[i];
    }
    cout << "Smallest = " << small << endl;
    return 0;
}
```
</details>

**Exercise 3 (Array).** Read `n`, then `n` integers into an array, and count how many are even.
*Expected behaviour:* `n = 4` with values `2 5 8 7` prints `Even count = 2`.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[100];                      // big enough for this exercise
    for (int i = 0; i < n; i++) cin >> a[i];

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) count++;
    }
    cout << "Even count = " << count << endl;
    return 0;
}
```
</details>

**Exercise 4 (Array).** Read 5 integers and print their sum and average.
*Expected behaviour:* input `10 20 30 40 50` prints `Sum = 150` and `Average = 30`.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int a[5], sum = 0;
    for (int i = 0; i < 5; i++) {
        cin >> a[i];
        sum += a[i];
    }
    cout << "Sum = " << sum << endl;
    cout << "Average = " << sum / 5 << endl;
    return 0;
}
```
</details>

**Exercise 5 (String).** Read a word and print its length, its first character, and its last character.
*Expected behaviour:* input `code` prints `Length: 4`, `First: c`, `Last: e`.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string w;
    cin >> w;
    int n = w.length();
    cout << "Length: " << n << endl;
    cout << "First: " << w[0] << endl;
    cout << "Last: " << w[n - 1] << endl;
    return 0;
}
```
</details>

**Exercise 6 (String).** Read a word and print each character on its own line.
*Expected behaviour:* input `hi` prints `h` then `i` on separate lines.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string w;
    cin >> w;
    int n = w.length();
    for (int i = 0; i < n; i++) {
        cout << w[i] << endl;
    }
    return 0;
}
```
</details>

**Exercise 7 (String).** Read a word and count how many vowels it contains.
*Expected behaviour:* input `banana` prints `Vowels: 3`.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string w;
    cin >> w;
    int n = w.length(), count = 0;
    for (int i = 0; i < n; i++) {
        char c = w[i];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            count++;
        }
    }
    cout << "Vowels: " << count << endl;
    return 0;
}
```
</details>

---

## 8. Summary

### Key Concepts

- An **array** stores many values of one type in numbered boxes, indexed from 0.
- The **index** selects one element; the last index is **size − 1**.
- Array elements are stored **contiguously** in memory, evenly spaced by the element size.
- A **string** is a sequence of characters that behaves much like an array.
- **Loops** are the main tool for processing every element of an array or string.

### Important Points

1. Array indexing starts at **0**, exactly like Python lists.
2. An array's **size is fixed** when you create it and cannot grow.
3. Every array element must have the **same type**.
4. C++ does **not** check index range, so reading out of range is dangerous.
5. The address of element `i` is `base_address + i * sizeof(element)`.
6. Include `<string>` before using the `string` type.
7. Use `cin >>` for one word and `getline(cin, s)` for a whole line.
8. A string's characters run from index `0` to `length() - 1`.

### Quick Reference

```cpp
// ----- Arrays -----
int a[5] = {10, 20, 30, 40, 50}; // declare and fill
a[0] = 99;                       // write to one element
for (int i = 0; i < 5; i++) {    // loop over every element
    cout << a[i] << " ";
}

// ----- Strings -----
#include <string>
string s = "Hello";              // text
cout << s.length();              // number of characters
cout << s[0];                    // first character
string joined = s + " World";    // concatenation
getline(cin, s);                 // read a whole line
```

### Next Steps

The next lecture introduces **functions** — a way to package code into reusable, named blocks with parameters and return values. Functions will let you take operations like "find the largest value" and reuse them anywhere, instead of rewriting the same loop each time.
