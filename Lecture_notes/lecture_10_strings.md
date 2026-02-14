# Lecture 10: Introduction to Strings in C++

## Table of Contents

1. [Introduction](#introduction)
2. [String Initialization](#string-initialization)
   - [Method 1: Direct Initialization](#method-1-direct-initialization)
   - [Method 2: Empty String](#method-2-empty-string)
   - [Method 3: Constructor Syntax](#method-3-constructor-syntax)
   - [Method 4: Copy from Another String](#method-4-copy-from-another-string)
   - [Summary of Initialization Methods](#summary-of-initialization-methods)
3. [String Operators](#string-operators)
   - [Indexing Operator []](#indexing-operator-)
   - [Concatenation Operator +](#concatenation-operator-)
   - [Append Operator +=](#append-operator-)
   - [Comparison Operators](#comparison-operators)
   - [Summary of String Operators](#summary-of-string-operators)
4. [Basic String Functions](#basic-string-functions)
   - [The find() Function](#the-find-function)
   - [String to Integer Conversion](#string-to-integer-conversion)
   - [Integer to String Conversion](#integer-to-string-conversion)
   - [Summary of Basic Functions](#summary-of-basic-functions)
5. [Common Mistakes](#common-mistakes)
6. [Practice Exercises](#practice-exercises)
7. [Summary](#summary)
8. [Quick Reference](#quick-reference)

---

## Introduction

A **string** is a sequence of characters used to represent text. In C++, we use the `string` type to store and manipulate text data such as names, messages, sentences, and any other textual information.

Strings are essential in programming because most programs need to work with text. For example, displaying messages to users, reading user input, processing names, or storing file paths all require strings.

To use strings in C++, we must include the string library:

```cpp
#include <string>
```

### Why Use Strings?

- Store text data (names, addresses, messages)
- Display information to users
- Process user input
- Work with files and data
- Create interactive programs

---

## String Initialization

There are several ways to create and initialize strings in C++.

### Method 1: Direct Initialization

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string name = "Alice";
    cout << name << endl;
    
    return 0;
}
```

**Output:**
```
Alice
```

### Method 2: Empty String

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string message;  // Creates an empty string
    message = "Hello, World!";
    cout << message << endl;
    
    return 0;
}
```

**Output:**
```
Hello, World!
```

### Method 3: Constructor Syntax

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string greeting("Good morning");
    cout << greeting << endl;
    
    return 0;
}
```

**Output:**
```
Good morning
```

### Method 4: Copy from Another String

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string original = "Hello";
    string copy = original;
    
    cout << "Original: " << original << endl;
    cout << "Copy: " << copy << endl;
    
    return 0;
}
```

**Output:**
```
Original: Hello
Copy: Hello
```

### Summary of Initialization Methods

| Method | Syntax | Example |
|--------|--------|---------|
| Direct | `string name = "text";` | `string city = "Paris";` |
| Empty | `string name;` | `string word;` |
| Constructor | `string name("text");` | `string msg("Hi");` |
| Copy | `string copy = original;` | `string s2 = s1;` |

---

## String Operators

String operators allow us to manipulate and compare strings easily.

### Indexing Operator []

You can access individual characters in a string using the indexing operator `[]`. The first character is at index 0.

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string word = "Hello";
    
    cout << "First character: " << word[0] << endl;
    cout << "Second character: " << word[1] << endl;
    cout << "Last character: " << word[4] << endl;
    
    return 0;
}
```

**Output:**
```
First character: H
Second character: e
Last character: o
```

**Important:** String indices start at 0. For a string of length 5, valid indices are 0, 1, 2, 3, 4.

#### Modifying Characters

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string word = "Hello";
    
    word[0] = 'h';  // Change first character to lowercase
    
    cout << word << endl;
    
    return 0;
}
```

**Output:**
```
hello
```

### Concatenation Operator +

The `+` operator combines two strings into a new string.

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string first = "Good";
    string second = "Morning";
    
    string greeting = first + " " + second;
    
    cout << greeting << endl;
    
    return 0;
}
```

**Output:**
```
Good Morning
```

#### Example: Building a Full Name

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string firstName = "John";
    string lastName = "Smith";
    
    string fullName = firstName + " " + lastName;
    
    cout << "Full name: " << fullName << endl;
    
    return 0;
}
```

**Output:**
```
Full name: John Smith
```

### Append Operator +=

The `+=` operator adds text to the end of an existing string.

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string message = "Hello";
    
    message += " ";
    message += "World";
    
    cout << message << endl;
    
    return 0;
}
```

**Output:**
```
Hello World
```

#### Example: Building a Sentence

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string sentence = "I";
    sentence += " love";
    sentence += " programming";
    
    cout << sentence << endl;
    
    return 0;
}
```

**Output:**
```
I love programming
```

### Comparison Operators

Strings can be compared using standard comparison operators. The comparison is done alphabetically (lexicographically).

#### Equality Operator ==

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string password = "secret123";
    string input = "secret123";
    
    if (password == input) {
        cout << "Access granted" << endl;
    } else {
        cout << "Access denied" << endl;
    }
    
    return 0;
}
```

**Output:**
```
Access granted
```

#### Inequality Operator !=

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string color1 = "red";
    string color2 = "blue";
    
    if (color1 != color2) {
        cout << "The colors are different" << endl;
    }
    
    return 0;
}
```

**Output:**
```
The colors are different
```

#### Less Than Operator <

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string word1 = "apple";
    string word2 = "banana";
    
    if (word1 < word2) {
        cout << word1 << " comes before " << word2 << " alphabetically" << endl;
    }
    
    return 0;
}
```

**Output:**
```
apple comes before banana alphabetically
```

#### Complete Comparison Example

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string name1 = "Alice";
    string name2 = "Bob";
    
    cout << "name1 == name2: " << (name1 == name2) << endl;
    cout << "name1 != name2: " << (name1 != name2) << endl;
    cout << "name1 < name2: " << (name1 < name2) << endl;
    cout << "name1 > name2: " << (name1 > name2) << endl;
    
    return 0;
}
```

**Output:**
```
name1 == name2: 0
name1 != name2: 1
name1 < name2: 1
name1 > name2: 0
```

**Note:** In C++, `true` is displayed as `1` and `false` as `0`.

### Summary of String Operators

| Operator | Purpose | Example |
|----------|---------|---------|
| `[]` | Access character at index | `word[0]` |
| `+` | Concatenate strings | `s1 + s2` |
| `+=` | Append to string | `s1 += s2` |
| `==` | Check equality | `s1 == s2` |
| `!=` | Check inequality | `s1 != s2` |
| `<` | Less than (alphabetical) | `s1 < s2` |
| `>` | Greater than (alphabetical) | `s1 > s2` |
| `<=` | Less than or equal | `s1 <= s2` |
| `>=` | Greater than or equal | `s1 >= s2` |

---

## Basic String Functions

C++ provides useful functions to work with strings.

### The find() Function

The `find()` function searches for a substring or character within a string. It returns the position where the substring is found, or a special value `string::npos` if not found.

#### Finding a Character

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string text = "Hello World";
    
    size_t position = text.find('o');
    
    cout << "Found 'o' at position: " << position << endl;
    
    return 0;
}
```

**Output:**
```
Found 'o' at position: 4
```

**Note:** Positions start at 0, so position 4 is the 5th character.

#### Finding a Substring

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string sentence = "I love programming";
    
    size_t position = sentence.find("love");
    
    if (position != string::npos) {
        cout << "Found 'love' at position: " << position << endl;
    } else {
        cout << "'love' not found" << endl;
    }
    
    return 0;
}
```

**Output:**
```
Found 'love' at position: 2
```

#### Checking if a Word Exists

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string email = "user@example.com";
    
    if (email.find("@") != string::npos) {
        cout << "Valid email format" << endl;
    } else {
        cout << "Invalid email format" << endl;
    }
    
    return 0;
}
```

**Output:**
```
Valid email format
```

### String to Integer Conversion

The `stoi()` function converts a string to an integer.

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string numberText = "42";
    
    int number = stoi(numberText);
    
    cout << "The number is: " << number << endl;
    cout << "Number + 10 = " << (number + 10) << endl;
    
    return 0;
}
```

**Output:**
```
The number is: 42
Number + 10 = 52
```

#### Practical Example: Age Calculator

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string birthYearText = "2000";
    int currentYear = 2024;
    
    int birthYear = stoi(birthYearText);
    int age = currentYear - birthYear;
    
    cout << "Your age is: " << age << endl;
    
    return 0;
}
```

**Output:**
```
Your age is: 24
```

### Integer to String Conversion

The `to_string()` function converts an integer to a string.

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    int score = 95;
    
    string scoreText = to_string(score);
    
    cout << "Your score is: " << scoreText << endl;
    
    return 0;
}
```

**Output:**
```
Your score is: 95
```

#### Practical Example: Building a Report

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string name = "Alice";
    int score = 87;
    
    string report = name + " scored " + to_string(score) + " points";
    
    cout << report << endl;
    
    return 0;
}
```

**Output:**
```
Alice scored 87 points
```

### Summary of Basic Functions

| Function | Purpose | Example |
|----------|---------|---------|
| `find(x)` | Find position of character or substring | `text.find("hello")` |
| `stoi(s)` | Convert string to integer | `stoi("123")` |
| `to_string(n)` | Convert integer to string | `to_string(42)` |

---

## Common Mistakes

### Mistake 1: Forgetting to Include the String Library

**Wrong:**
```cpp
#include <iostream>
using namespace std;

int main() {
    string name = "Alice";  // Error: string not defined
    return 0;
}
```

**Correct:**
```cpp
#include <iostream>
#include <string>  // Must include this
using namespace std;

int main() {
    string name = "Alice";
    return 0;
}
```

### Mistake 2: Accessing Invalid Index

**Wrong:**
```cpp
string word = "Hello";  // Length is 5
char ch = word[10];     // Invalid: index out of range
```

**Correct:**
```cpp
string word = "Hello";
char ch = word[4];  // Valid: last character
```

### Mistake 3: Not Checking find() Result

**Wrong:**
```cpp
string text = "Hello";
size_t pos = text.find("xyz");  // Returns string::npos
// Using pos without checking can cause errors
```

**Correct:**
```cpp
string text = "Hello";
size_t pos = text.find("xyz");

if (pos != string::npos) {
    cout << "Found at position: " << pos << endl;
} else {
    cout << "Not found" << endl;
}
```

---

## Practice Exercises

### Exercise 1: String Builder

Write a program that asks the user for their first name and last name, then creates and displays their full name.

**Expected interaction:**
```
Enter first name: John
Enter last name: Doe
Full name: John Doe
```

### Exercise 2: Password Checker

Write a program that compares a stored password with user input and displays whether access is granted or denied.

**Expected interaction:**
```
Enter password: secret123
Access granted
```

### Exercise 3: Email Validator

Write a program that checks if an email address contains the '@' symbol using the `find()` function.

**Expected interaction:**
```
Enter email: user@example.com
Valid email
```

---

## Summary

### Key Concepts

- **Strings** store text data in C++
- Must include `<string>` library to use strings
- Strings can be initialized in multiple ways
- Use `[]` to access individual characters
- Use `+` to combine strings and `+=` to append
- Comparison operators work alphabetically
- `find()` searches for characters or substrings
- `stoi()` converts string to integer
- `to_string()` converts integer to string

### Important Points

1. String indices start at 0
2. Always check `find()` result against `string::npos`
3. Strings can be compared using `==`, `!=`, `<`, `>`, etc.
4. The `+` operator creates a new string
5. The `+=` operator modifies the existing string

### Next Steps

In the next lecture, you will learn about:
- Reading full lines of text
- More string functions
- String manipulation techniques
- Working with multiple words

---

## Quick Reference

```cpp
// Initialization
string s1 = "Hello";
string s2;
string s3 = s1;

// Accessing characters
char c = s1[0];

// Concatenation
string s4 = s1 + " World";
s1 += "!";

// Comparison
if (s1 == s2) { }
if (s1 < s2) { }

// Finding
size_t pos = s1.find("ell");
if (pos != string::npos) { }

// Conversion
int num = stoi("123");
string text = to_string(456);
``
