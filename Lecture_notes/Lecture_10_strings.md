# Lecture 10: C++ String Objects

## Welcome

In previous lectures, you learned about arrays and multidimensional arrays. Now you will learn how to work with strings using the C++ string class - a powerful and easy way to handle text data.

**Why strings are important:**
- Store and manipulate text
- Process user input
- Handle names, messages, and sentences
- Essential for text-based applications

---

## Table of Contents

1. [Introduction to String Objects](#introduction-to-string-objects)
2. [Declaring and Initializing Strings](#declaring-and-initializing-strings)
3. [String Input and Output](#string-input-and-output)
4. [Accessing Characters](#accessing-characters)
5. [String Operators](#string-operators)
6. [String Properties](#string-properties)
7. [String Modification](#string-modification)
8. [String Searching](#string-searching)
9. [Substring Operations](#substring-operations)
10. [String Comparison](#string-comparison)
11. [String Conversion](#string-conversion)
12. [Common Mistakes](#common-mistakes)
13. [Practice Exercises](#practice-exercises)
14. [Summary](#summary)

---

## Introduction to String Objects

The C++ **string** class is part of the Standard Library and provides a convenient way to work with text.

### Including the String Library

```cpp
#include <string>
using namespace std;
```

### Why Use String Objects?

- Easy to use (no manual memory management)
- Dynamic size (grows and shrinks automatically)
- Rich set of built-in functions
- Safe (prevents common errors)
- Supports operators (+, ==, <, etc.)

---

## Declaring and Initializing Strings

### Basic Declaration

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str1;                    // Empty string
    string str2 = "Hello";          // Initialize with text
    string str3("World");           // Constructor syntax
    string str4 = str2;             // Copy from another string
    
    cout << str1 << endl;  // (empty line)
    cout << str2 << endl;  // Hello
    cout << str3 << endl;  // World
    cout << str4 << endl;  // Hello
    
    return 0;
}
```

### Special Initializations

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str1(5, 'A');            // Five A's: "AAAAA"
    string str2(10, '*');           // Ten asterisks: "**********"
    
    cout << str1 << endl;  // AAAAA
    cout << str2 << endl;  // **********
    
    return 0;
}
```

---

## String Input and Output

### Output with cout

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string message = "Hello, World!";
    
    cout << message << endl;
    
    return 0;
}
```

### Input with cin (Single Word)

**Note:** `cin` stops reading at the first whitespace (space, tab, newline).

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string name;
    
    cout << "Enter your name: ";
    cin >> name;  // Reads only first word
    
    cout << "Hello, " << name << endl;
    
    return 0;
}
```

**Sample run:**
```
Enter your name: John Doe
Hello, John
```

### Input with getline() (Full Line)

Use `getline()` to read an entire line including spaces.

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string sentence;
    
    cout << "Enter a sentence: ";
    getline(cin, sentence);
    
    cout << "You said: " << sentence << endl;
    
    return 0;
}
```

**Sample run:**
```
Enter a sentence: Hello World
You said: Hello World
```

### Mixing cin and getline()

**Problem:**
```cpp
int age;
string name;

cin >> age;          // Leaves newline in buffer
getline(cin, name);  // Reads the leftover newline as empty string
```

**Solution:**
```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    int age;
    string name;
    
    cout << "Enter age: ";
    cin >> age;
    
    cin.ignore();  // Clear the newline from buffer
    
    cout << "Enter name: ";
    getline(cin, name);
    
    cout << "Age: " << age << endl;
    cout << "Name: " << name << endl;
    
    return 0;
}
```

---

## Accessing Characters

### Using [] Operator

Access characters by index (0-based, like arrays).

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string text = "Hello";
    
    cout << text[0] << endl;  // H (first character)
    cout << text[1] << endl;  // e
    cout << text[4] << endl;  // o (last character)
    
    return 0;
}
```

### Modifying Characters

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string text = "Hello";
    
    text[0] = 'h';  // Change first character
    
    cout << text << endl;  // hello
    
    return 0;
}
```

### Using at() Function

The `at()` function provides bounds checking and throws an exception if index is out of range.

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string text = "Hello";
    
    cout << text.at(0) << endl;  // H
    cout << text.at(4) << endl;  // o
    
    // text.at(10);  // Throws out_of_range exception
    
    return 0;
}
```

### Looping Through Characters

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string text = "Hello";
    
    // Method 1: Using index
    for (int i = 0; i < text.length(); i++) {
        cout << text[i] << " ";
    }
    cout << endl;
    
    // Method 2: Range-based for loop (C++11)
    for (char c : text) {
        cout << c << " ";
    }
    cout << endl;
    
    return 0;
}
```

**Output:**
```
H e l l o
H e l l o
```

---

## String Operators

### Assignment Operator (=)

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str1 = "Hello";
    string str2;
    
    str2 = str1;  // Copy str1 to str2
    
    cout << str2 << endl;  // Hello
    
    return 0;
}
```

### Concatenation Operator (+)

Combines two strings into a new string.

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string first = "Hello";
    string second = "World";
    
    string combined = first + " " + second;
    
    cout << combined << endl;  // Hello World
    
    // Can concatenate multiple strings
    string full = first + ", " + second + "!";
    cout << full << endl;  // Hello, World!
    
    return 0;
}
```

### Append Operator (+=)

Adds to the end of an existing string.

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string text = "Hello";
    
    text += " ";
    text += "World";
    text += "!";
    
    cout << text << endl;  // Hello World!
    
    return 0;
}
```

### Comparison Operators

**Available operators:** `==`, `!=`, `<`, `>`, `<=`, `>=`

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str1 = "Apple";
    string str2 = "Banana";
    string str3 = "Apple";
    
    // Equality
    if (str1 == str3) {
        cout << "str1 and str3 are equal" << endl;
    }
    
    // Inequality
    if (str1 != str2) {
        cout << "str1 and str2 are different" << endl;
    }
    
    // Alphabetical comparison
    if (str1 < str2) {
        cout << "str1 comes before str2 alphabetically" << endl;
    }
    
    if (str2 > str1) {
        cout << "str2 comes after str1 alphabetically" << endl;
    }
    
    return 0;
}
```

**Output:**
```
str1 and str3 are equal
str1 and str2 are different
str1 comes before str2 alphabetically
str2 comes after str1 alphabetically
```

### Subscript Operator ([])

Access individual characters (already covered in [Accessing Characters](#accessing-characters)).

```cpp
string text = "Hello";
char first = text[0];      // H
char last = text[4];       // o
```

---

## String Properties

### length() and size()

Both functions return the number of characters in the string.

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string text = "Hello World";
    
    cout << "Length: " << text.length() << endl;  // 11
    cout << "Size: " << text.size() << endl;      // 11
    
    return 0;
}
```

**Note:** `length()` and `size()` are identical - use whichever you prefer.

### empty()

Checks if the string has no characters.

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str1 = "";
    string str2 = "Hello";
    
    if (str1.empty()) {
        cout << "str1 is empty" << endl;
    }
    
    if (!str2.empty()) {
        cout << "str2 is not empty" << endl;
    }
    
    return 0;
}
```

**Output:**
```
str1 is empty
str2 is not empty
```

### max_size()

Returns the maximum possible length of the string.

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string text;
    
    cout << "Maximum size: " << text.max_size() << endl;
    
    return 0;
}
```

### capacity()

Returns the current storage capacity.

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string text = "Hello";
    
    cout << "Length: " << text.length() << endl;
    cout << "Capacity: " << text.capacity() << endl;
    
    return 0;
}
```

---

## String Modification

### append()

Adds characters to the end of the string.

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string text = "Hello";
    
    text.append(" World");
    cout << text << endl;  // Hello World
    
    text.append(3, '!');
    cout << text << endl;  // Hello World!!!
    
    return 0;
}
```

### push_back()

Adds a single character to the end.

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string text = "Hello";
    
    text.push_back('!');
    cout << text << endl;  // Hello!
    
    return 0;
}
```

### pop_back()

Removes the last character.

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string text = "Hello!";
    
    text.pop_back();
    cout << text << endl;  // Hello
    
    return 0;
}
```

### insert()

Inserts characters at a specific position.

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string text = "Hello World";
    
    text.insert(6, "Beautiful ");
    
    cout << text << endl;  // Hello Beautiful World
    
    return 0;
}
```

### erase()

Removes characters from the string.

**Syntax:** `erase(position, count)`

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string text = "Hello Beautiful World";
    
    text.erase(6, 10);  // Remove 10 characters starting at position 6
    
    cout << text << endl;  // Hello World
    
    return 0;
}
```

### replace()

Replaces a portion of the string.

**Syntax:** `replace(position, count, new_string)`

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string text = "Hello World";
    
    text.replace(6, 5, "C++");  // Replace 5 chars starting at pos 6 with "C++"
    
    cout << text << endl;  // Hello C++
    
    return 0;
}
```

### clear()

Removes all characters from the string.

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string text = "Hello World";
    
    cout << "Before: " << text << endl;
    
    text.clear();
    
    cout << "After: " << text << endl;
    cout << "Empty: " << text.empty() << endl;
    
    return 0;
}
```

**Output:**
```
Before: Hello World
After: 
Empty: 1
```

### swap()

Swaps the contents of two strings.

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str1 = "Hello";
    string str2 = "World";
    
    cout << "Before: str1=" << str1 << ", str2=" << str2 << endl;
    
    str1.swap(str2);
    
    cout << "After: str1=" << str1 << ", str2=" << str2 << endl;
    
    return 0;
}
```

**Output:**
```
Before: str1=Hello, str2=World
After: str1=World, str2=Hello
```

---

## String Searching

### find()

Finds the first occurrence of a substring or character.

**Returns:** Position of first match, or `string::npos` if not found.

**Finding a substring:**
```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string text = "Hello World";
    
    size_t pos = text.find("World");
    
    if (pos != string::npos) {
        cout << "Found at position: " << pos << endl;
    } else {
        cout << "Not found" << endl;
    }
    
    return 0;
}
```

**Output:**
```
Found at position: 6
```

**Finding a character:**
```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string text = "Hello World";
    
    size_t pos = text.find('o');
    
    if (pos != string::npos) {
        cout << "Found 'o' at position: " << pos << endl;
    }
    
    return 0;
}
```

**Output:**
```
Found 'o' at position: 4
```

**Finding with starting position:**
```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string text = "Hello World";
    
    size_t pos1 = text.find('o');
    cout << "First 'o' at: " << pos1 << endl;
    
    size_t pos2 = text.find('o', pos1 + 1);  // Start searching after first 'o'
    cout << "Second 'o' at: " << pos2 << endl;
    
    return 0;
}
```

**Output:**
```
First 'o' at: 4
Second 'o' at: 7
```

### rfind()

Finds the **last** occurrence (searches from the end).

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string text = "Hello World";
    
    size_t pos = text.rfind('o');
    
    cout << "Last 'o' at position: " << pos << endl;
    
    return 0;
}
```

**Output:**
```
Last 'o' at position: 7
```

### find_first_of()

Finds the first occurrence of **any character** from a set.

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string text = "Hello World";
    string vowels = "aeiou";
    
    size_t pos = text.find_first_of(vowels);
    
    if (pos != string::npos) {
        cout << "First vowel at position: " << pos << endl;
        cout << "Character: " << text[pos] << endl;
    }
    
    return 0;
}
```

**Output:**
```
First vowel at position: 1
Character: e
```

### find_last_of()

Finds the last occurrence of any character from a set.

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string text = "Hello World";
    string vowels = "aeiou";
    
    size_t pos = text.find_last_of(vowels);
    
    if (pos != string::npos) {
        cout << "Last vowel at position: " << pos << endl;
        cout << "Character: " << text[pos] << endl;
    }
    
    return 0;
}
```

**Output:**
```
Last vowel at position: 7
Character: o
```

### find_first_not_of()

Finds the first character **not** in the given set.

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string text = "Hello World";
    string vowels = "aeiou";
    
    size_t pos = text.find_first_not_of(vowels);
    
    cout << "First non-vowel at position: " << pos << endl;
    cout << "Character: " << text[pos] << endl;
    
    return 0;
}
```

**Output:**
```
First non-vowel at position: 0
Character: H
```

### find_last_not_of()

Finds the last character **not** in the given set.

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string text = "Hello World";
    string vowels = "aeiou";
    
    size_t pos = text.find_last_not_of(vowels);
    
    cout << "Last non-vowel at position: " << pos << endl;
    cout << "Character: " << text[pos] << endl;
    
    return 0;
}
```

**Output:**
```
Last non-vowel at position: 10
Character: d
```

---

## Substring Operations

### substr()

Extracts a portion of the string.

**Syntax:** `substr(position, length)`

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string text = "Hello World";
    
    string sub1 = text.substr(0, 5);   // "Hello" (5 chars from pos 0)
    string sub2 = text.substr(6, 5);   // "World" (5 chars from pos 6)
    string sub3 = text.substr(6);      // "World" (from pos 6 to end)
    
    cout << sub1 << endl;
    cout << sub2 << endl;
    cout << sub3 << endl;
    
    return 0;
}
```

**Output:**
```
Hello
World
World
```

### Complete Example: Extracting Words

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string sentence = "The quick brown fox";
    
    size_t pos = 0;
    size_t space;
    
    while ((space = sentence.find(' ', pos)) != string::npos) {
        string word = sentence.substr(pos, space - pos);
        cout << word << endl;
        pos = space + 1;
    }
    
    // Print last word
    cout << sentence.substr(pos) << endl;
    
    return 0;
}
```

**Output:**
```
The
quick
brown
fox
```

---

## String Comparison

### Using Operators (==, !=, <, >, <=, >=)

Already covered in [String Operators](#string-operators).

### compare() Function

Returns:
- **0** if strings are equal
- **< 0** if first string is less than second
- **> 0** if first string is greater than second

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str1 = "Apple";
    string str2 = "Banana";
    string str3 = "Apple";
    
    int result1 = str1.compare(str2);
    int result2 = str1.compare(str3);
    
    if (result1 < 0) {
        cout << "str1 < str2" << endl;
    }
    
    if (result2 == 0) {
        cout << "str1 == str3" << endl;
    }
    
    return 0;
}
```

**Output:**
```
str1 < str2
str1 == str3
```

### Case-Insensitive Comparison

```cpp
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool equalIgnoreCase(string str1, string str2) {
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    return str1 == str2;
}

int main() {
    string str1 = "Hello";
    string str2 = "HELLO";
    
    if (equalIgnoreCase(str1, str2)) {
        cout << "Strings are equal (ignoring case)" << endl;
    }
    
    return 0;
}
```

---

## String Conversion

### String to Number

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str1 = "123";
    string str2 = "45.67";
    string str3 = "999999";
    
    int num1 = stoi(str1);        // String to integer
    double num2 = stod(str2);     // String to double
    long num3 = stol(str3);       // String to long
    float num4 = stof(str2);      // String to float
    
    cout << num1 + 10 << endl;    // 133
    cout << num2 * 2 << endl;     // 91.34
    cout << num3 - 50 << endl;    // 999949
    cout << num4 + 1 << endl;     // 46.67
    
    return 0;
}
```

### Number to String

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    int num1 = 123;
    double num2 = 45.67;
    long num3 = 999999;
    
    string str1 = to_string(num1);
    string str2 = to_string(num2);
    string str3 = to_string(num3);
    
    cout << str1 << endl;         // "123"
    cout << str2 << endl;         // "45.670000"
    cout << str3 << endl;         // "999999"
    
    // Concatenate numbers as strings
    string combined = str1 + " and " + str3;
    cout << combined << endl;     // "123 and 999999"
    
    return 0;
}
```

### Character Functions

Useful for character manipulation:

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    char ch = 'a';
    
    cout << "Original: " << ch << endl;
    cout << "Uppercase: " << (char)toupper(ch) << endl;
    cout << "Is alpha: " << isalpha(ch) << endl;
    cout << "Is digit: " << isdigit(ch) << endl;
    cout << "Is lower: " << islower(ch) << endl;
    
    return 0;
}
```

---

## Common Mistakes

### Mistake 1: Accessing Out of Bounds

**Wrong:**
```cpp
string text = "Hello";
cout << text[10];  // Undefined behavior - no error but unpredictable
```

**Correct:**
```cpp
string text = "Hello";
if (10 < text.length()) {
    cout << text[10];
}
// Or use at() which throws exception
try {
    cout << text.at(10);
} catch (out_of_range& e) {
    cout << "Index out of range" << endl;
}
```

### Mistake 2: Not Checking find() Result

**Wrong:**
```cpp
string text = "Hello";
size_t pos = text.find("XYZ");
cout << text.substr(pos);  // Error if not found!
```

**Correct:**
```cpp
string text = "Hello";
size_t pos = text.find("XYZ");
if (pos != string::npos) {
    cout << text.substr(pos);
} else {
    cout << "Not found" << endl;
}
```

### Mistake 3: Forgetting cin.ignore()

**Wrong:**
```cpp
int age;
string name;
cin >> age;
getline(cin, name);  // Gets empty line
```

**Correct:**
```cpp
int age;
string name;
cin >> age;
cin.ignore();        // Clear newline
getline(cin, name);
```

### Mistake 4: Modifying String During Iteration

**Wrong:**
```cpp
string text = "Hello";
for (int i = 0; i < text.length(); i++) {
    text += "!";  // Modifying while iterating - infinite loop!
}
```

**Correct:**
```cpp
string text = "Hello";
int len = text.length();  // Store length first
for (int i = 0; i < len; i++) {
    text += "!";
}
```

### Mistake 5: Using + with nullptr

**Wrong:**
```cpp
string text = "Hello";
text = text + NULL;  // Error!
```

**Correct:**
```cpp
string text = "Hello";
text = text + "";  // Empty string
```

---

## Practice Exercises

### Exercise 1: Count Vowels and Consonants

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

### Exercise 2: Reverse a String

Write a function that reverses a string.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
#include <string>
using namespace std;

string reverseString(string str) {
    int start = 0;
    int end = str.length() - 1;
    
    while (start < end) {
        swap(str[start], str[end]);
        start++;
        end--;
    }
    
    return str;
}

int main() {
    string text;
    
    cout << "Enter a string: ";
    getline(cin, text);
    
    string reversed = reverseString(text);
    
    cout << "Reversed: " << reversed << endl;
    
    return 0;
}
```
</details>

---

### Exercise 3: Check Palindrome

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

### Exercise 4: Count Word Occurrences

Write a program that counts how many times a word appears in a sentence.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string sentence, word;
    int count = 0;
    
    cout << "Enter a sentence: ";
    getline(cin, sentence);
    
    cout << "Enter word to search: ";
    cin >> word;
    
    size_t pos = 0;
    while ((pos = sentence.find(word, pos)) != string::npos) {
        count++;
        pos += word.length();
    }
    
    cout << "'" << word << "' appears " << count << " times" << endl;
    
    return 0;
}
```
</details>

---

### Exercise 5: Remove All Spaces

Write a function that removes all spaces from a string.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
#include <string>
using namespace std;

string removeSpaces(string str) {
    string result = "";
    
    for (int i = 0; i < str.length(); i++) {
        if (str[i] != ' ') {
            result += str[i];
        }
    }
    
    return result;
}

int main() {
    string text;
    
    cout << "Enter a string: ";
    getline(cin, text);
    
    string noSpaces = removeSpaces(text);
    
    cout << "Without spaces: " << noSpaces << endl;
    
    return 0;
}
```
</details>

---

### Exercise 6: Replace All Occurrences

Write a program that replaces all occurrences of a substring.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
#include <string>
using namespace std;

string replaceAll(string str, string find, string replace) {
    size_t pos = 0;
    
    while ((pos = str.find(find, pos)) != string::npos) {
        str.replace(pos, find.length(), replace);
        pos += replace.length();
    }
    
    return str;
}

int main() {
    string text, find, replace;
    
    cout << "Enter text: ";
    getline(cin, text);
    
    cout << "Find: ";
    getline(cin, find);
    
    cout << "Replace with: ";
    getline(cin, replace);
    
    string result = replaceAll(text, find, replace);
    
    cout << "Result: " << result << endl;
    
    return 0;
}
```
</details>

---

### Exercise 7: Extract Email Username

Write a program that extracts the username from an email (part before @).

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string email;
    
    cout << "Enter email: ";
    cin >> email;
    
    size_t pos = email.find('@');
    
    if (pos != string::npos) {
        string username = email.substr(0, pos);
        cout << "Username: " << username << endl;
    } else {
        cout << "Invalid email" << endl;
    }
    
    return 0;
}
```
</details>

---

### Exercise 8: Convert to Title Case

Write a function that converts a string to title case.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
#include <string>
using namespace std;

string toTitleCase(string str) {
    bool newWord = true;
    
    for (int i = 0; i < str.length(); i++) {
        if (newWord && isalpha(str[i])) {
            str[i] = toupper(str[i]);
            newWord = false;
        } else if (!isalpha(str[i])) {
            newWord = true;
        } else {
            str[i] = tolower(str[i]);
        }
    }
    
    return str;
}

int main() {
    string text;
    
    cout << "Enter text: ";
    getline(cin, text);
    
    string titleCase = toTitleCase(text);
    
    cout << "Title case: " << titleCase << endl;
    
    return 0;
}
```
</details>

---

## Summary

### What We Learned Today

- **String class** - C++ object for handling text
- **Declaration** - Multiple ways to initialize strings
- **Input/Output** - cin, cout, getline()
- **Accessing characters** - Using [] and at()
- **Operators** - =, +, +=, ==, !=, <, >, <=, >=, []
- **Properties** - length(), size(), empty(), capacity()
- **Modification** - append(), insert(), erase(), replace(), clear()
- **Searching** - find(), rfind(), find_first_of(), find_last_of()
- **Substrings** - substr()
- **Comparison** - Operators and compare() function
- **Conversion** - stoi(), stod(), to_string()

---

## Key Takeaways

1. **Use C++ string class** - Easier and safer than arrays
2. **String concatenation** - Use + or += operators
3. **Finding substrings** - Use find() function, check for string::npos
4. **Extracting substrings** - Use substr() function
5. **Character access** - Use [] for speed, at() for safety
6. **String comparison** - Use == or compare() function
7. **Conversion** - stoi() for string to int, to_string() for int to string
8. **Input full lines** - Use getline() instead of cin
9. **Always check bounds** - Verify length before accessing
10. **Check find results** - Always compare with string::npos

---

## Quick Reference

### Common String Operations

| Operation | Syntax | Example |
|-----------|--------|---------|
| Length | `s.length()` or `s.size()` | `int len = text.length();` |
| Access char | `s[i]` or `s.at(i)` | `char c = text[0];` |
| Concatenate | `s1 + s2` or `s += "x"` | `str = str1 + str2;` |
| Compare | `s1 == s2` or `s1.compare(s2)` | `if (str1 == str2)` |
| Find | `s.find("sub")` | `pos = text.find("Hello");` |
| Substring | `s.substr(pos, len)` | `sub = text.substr(0, 5);` |
| Replace | `s.replace(pos, len, "new")` | `text.replace(0, 5, "Hi");` |
| Insert | `s.insert(pos, "text")` | `text.insert(5, "!");` |
| Erase | `s.erase(pos, len)` | `text.erase(0, 3);` |
| Clear | `s.clear()` | `text.clear();` |

---

## Next Lecture Preview

In the next lecture, we will learn about:
- Pointers and memory addresses
- Dynamic memory allocation
- Pointers and arrays
- Pointer arithmetic

---

## Homework

**Assignment 1:** Write a program that reads a sentence and counts the number of words.

**Assignment 2:** Create a function that checks if two strings are anagrams (same characters, different order).

**Assignment 3:** Write a program that validates a password: at least 8 characters, one uppercase, one lowercase, one digit, one special character.

---

## Resources

- [cppreference.com - std::string](https://en.cppreference.com/w/cpp/string/basic_string)
- [C++ String Reference](http://www.cplusplus.com/reference/string/string/)

---

**Master C++ strings to handle text data effectively in your programs.**
