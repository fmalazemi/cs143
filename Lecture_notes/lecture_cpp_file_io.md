# C++ Programming — File Input and Output (I/O)

## Table of Contents

1. [Introduction](#introduction)
2. [File Streams Overview](#file-streams-overview)
   - 2.1 [The Three File Stream Classes](#the-three-file-stream-classes)
   - 2.2 [Including the Header](#including-the-header)
3. [Writing to Files (`ofstream`)](#writing-to-files-ofstream)
   - 3.1 [Opening a File for Writing](#opening-a-file-for-writing)
   - 3.2 [Writing Data with `<<`](#writing-data-with-)
   - 3.3 [Closing a File](#closing-a-file)
   - 3.4 [Append Mode](#append-mode)
4. [Reading from Files (`ifstream`)](#reading-from-files-ifstream)
   - 4.1 [Opening a File for Reading](#opening-a-file-for-reading)
   - 4.2 [Reading Word by Word with `>>`](#reading-word-by-word-with-)
   - 4.3 [Reading Line by Line with `getline()`](#reading-line-by-line-with-getline)
   - 4.4 [Reading Character by Character with `get()`](#reading-character-by-character-with-get)
5. [Checking File State](#checking-file-state)
   - 5.1 [`is_open()` and `fail()`](#is_open-and-fail)
   - 5.2 [End-of-File Detection](#end-of-file-detection)
6. [Reading and Writing (`fstream`)](#reading-and-writing-fstream)
7. [File Open Modes](#file-open-modes)
8. [Practical Examples](#practical-examples)
   - 8.1 [Saving Student Records](#saving-student-records)
   - 8.2 [Reading a CSV-Style File](#reading-a-csv-style-file)
   - 8.3 [Copy One File to Another](#copy-one-file-to-another)
9. [Common Mistakes](#common-mistakes)
10. [Practice Exercises](#practice-exercises)
11. [Summary](#summary)

---

## Introduction

File I/O lets your C++ programs **store data permanently** on disk and **read data back** from files. Without file I/O, every piece of information your program creates disappears the moment the program ends.

### Why is File I/O Important?

- **Persistence:** Save results, settings, or progress so they survive across program runs.
- **Data exchange:** Read input produced by other programs (CSVs, logs, configuration files).
- **Scalability:** Handle datasets far too large to type in by hand every time.
- **Professional software:** Nearly every real application reads or writes files — databases, games, web servers, editors.

### Real-World Analogies

- **Writing to a file** is like writing notes in a notebook — you open the notebook, write your text, and close it. The text stays on the page even after you walk away.
- **Reading from a file** is like reading those same notes back — you open the notebook, read from top to bottom, and close it when done.
- **Append mode** is like adding new entries to the end of a diary instead of starting a fresh page.

### When Do You Use File I/O?

You use file I/O whenever your program needs to remember data between runs, process external data files, generate reports, or log events for later review.

---

## File Streams Overview

### The Three File Stream Classes

C++ provides three classes for working with files. They live in the `<fstream>` header:

| Class       | Purpose                 | Direction     |
|-------------|-------------------------|---------------|
| `ofstream`  | **Output** file stream  | Write only    |
| `ifstream`  | **Input** file stream   | Read only     |
| `fstream`   | **General** file stream | Read & write  |

Think of each class as a special version of `cout` or `cin` that is connected to a file instead of the console.

### Including the Header

You must include `<fstream>` to use any of these classes. You will usually also need `<iostream>` for console messages and `<string>` for `getline()`.

```cpp
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
```

---

## Writing to Files (`ofstream`)

### Opening a File for Writing

You create an `ofstream` object and pass the file name. If the file does not exist, it is created automatically. If it already exists, its contents are **erased** by default.

```cpp
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream outFile("output.txt");

    if (!outFile) {
        cout << "Error: could not open file for writing." << endl;
        return 1;
    }

    outFile << "Hello, File!" << endl;
    outFile.close();

    cout << "Data written successfully." << endl;
    return 0;
}
```

**Output (console):**
```
Data written successfully.
```

**Contents of output.txt:**
```
Hello, File!
```

### Writing Data with `<<`

You use the insertion operator `<<` exactly the same way you use it with `cout`. You can write strings, integers, doubles, and expressions.

```cpp
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream outFile("data.txt");

    string name = "Alice";
    int age = 21;
    double gpa = 3.85;

    outFile << "Name: " << name << endl;
    outFile << "Age: " << age << endl;
    outFile << "GPA: " << gpa << endl;

    outFile.close();
    cout << "Student data saved." << endl;
    return 0;
}
```

**Contents of data.txt:**
```
Name: Alice
Age: 21
GPA: 3.85
```

### Closing a File

Always call `.close()` when you are done writing. This flushes any remaining data from the buffer to the disk and releases the file.

```cpp
outFile.close();
```

If you forget, the destructor will close the file when the `ofstream` goes out of scope, but it is **good practice** to close explicitly.

### Append Mode

To add data to the **end** of an existing file without erasing it, open the file with `ios::app`:

```cpp
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    // First write
    ofstream outFile("log.txt");
    outFile << "Entry 1: Program started." << endl;
    outFile.close();

    // Append
    ofstream appendFile("log.txt", ios::app);
    appendFile << "Entry 2: New data added." << endl;
    appendFile.close();

    cout << "Log updated." << endl;
    return 0;
}
```

**Contents of log.txt:**
```
Entry 1: Program started.
Entry 2: New data added.
```

---

## Reading from Files (`ifstream`)

### Opening a File for Reading

Create an `ifstream` object with the file name. Always check whether the file opened successfully before trying to read.

```cpp
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream inFile("data.txt");

    if (!inFile) {
        cout << "Error: could not open file." << endl;
        return 1;
    }

    // ... read data here ...

    inFile.close();
    return 0;
}
```

### Reading Word by Word with `>>`

The extraction operator `>>` reads one whitespace-delimited token at a time, just like `cin >>`.

```cpp
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream inFile("words.txt");

    if (!inFile) {
        cout << "Error opening file." << endl;
        return 1;
    }

    string word;
    int count = 0;

    while (inFile >> word) {
        count++;
        cout << "Word " << count << ": " << word << endl;
    }

    inFile.close();
    cout << "Total words: " << count << endl;
    return 0;
}
```

**If words.txt contains:**
```
Hello World C++ Programming
```

**Output:**
```
Word 1: Hello
Word 2: World
Word 3: C++
Word 4: Programming
Total words: 4
```

### Reading Line by Line with `getline()`

Use `getline(stream, stringVar)` to read an entire line, including spaces.

```cpp
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream inFile("poem.txt");

    if (!inFile) {
        cout << "Cannot open file." << endl;
        return 1;
    }

    string line;
    int lineNum = 1;

    while (getline(inFile, line)) {
        cout << lineNum << ": " << line << endl;
        lineNum++;
    }

    inFile.close();
    return 0;
}
```

**If poem.txt contains:**
```
Roses are red
Violets are blue
C++ is great
And so are you
```

**Output:**
```
1: Roses are red
2: Violets are blue
3: C++ is great
4: And so are you
```

### Reading Character by Character with `get()`

The `get()` member function reads one character at a time, including whitespace and newlines.

```cpp
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream inFile("sample.txt");

    if (!inFile) {
        cout << "Cannot open file." << endl;
        return 1;
    }

    char ch;
    while (inFile.get(ch)) {
        cout << ch;
    }

    inFile.close();
    return 0;
}
```

This prints the file's content exactly as it appears, character by character.

---

## Checking File State

### `is_open()` and `fail()`

Two useful methods for error checking:

```cpp
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream inFile("missing.txt");

    if (!inFile.is_open()) {
        cout << "is_open() returned false — file not found." << endl;
    }

    if (inFile.fail()) {
        cout << "fail() returned true — an error occurred." << endl;
    }

    return 0;
}
```

**Output:**
```
is_open() returned false — file not found.
fail() returned true — an error occurred.
```

### End-of-File Detection

The `eof()` function returns `true` after the stream has attempted to read past the end of the file. **Do not** use `eof()` as the loop condition; instead, let the read operation control the loop.

```cpp
// CORRECT: let >> control the loop
while (inFile >> value) {
    // process value
}

// INCORRECT: using eof() as loop condition
while (!inFile.eof()) {   // Bug! May process garbage data
    inFile >> value;
}
```

---

## Reading and Writing (`fstream`)

The `fstream` class can both read from and write to the same file. You specify the mode when opening.

```cpp
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    // Write first
    fstream file("notes.txt", ios::out);
    file << "Line A" << endl;
    file << "Line B" << endl;
    file.close();

    // Now read
    file.open("notes.txt", ios::in);
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();

    return 0;
}
```

**Output:**
```
Line A
Line B
```

---

## File Open Modes

You can combine modes using the bitwise OR operator `|`.

| Mode          | Description                        |
|---------------|------------------------------------|
| `ios::in`     | Open for reading                   |
| `ios::out`    | Open for writing (erases content)  |
| `ios::app`    | Append to end of file              |
| `ios::ate`    | Move to end of file after opening  |
| `ios::trunc`  | Erase file contents on open        |
| `ios::binary` | Open in binary mode                |

**Combining modes:**

```cpp
// Open for writing in binary mode
ofstream binFile("data.bin", ios::out | ios::binary);

// Open for reading and writing
fstream file("data.txt", ios::in | ios::out);
```

---

## Practical Examples

### Saving Student Records

```cpp
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ofstream outFile("students.txt");

    if (!outFile) {
        cout << "Error creating file." << endl;
        return 1;
    }

    int n;
    cout << "How many students? ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        string name;
        double grade;

        cout << "Name: ";
        getline(cin, name);
        cout << "Grade: ";
        cin >> grade;
        cin.ignore();

        outFile << name << "," << grade << endl;
    }

    outFile.close();
    cout << "Records saved to students.txt" << endl;
    return 0;
}
```

### Reading a CSV-Style File

```cpp
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    ifstream inFile("students.txt");

    if (!inFile) {
        cout << "Cannot open students.txt" << endl;
        return 1;
    }

    string line;
    cout << "--- Student Records ---" << endl;

    while (getline(inFile, line)) {
        stringstream ss(line);
        string name;
        double grade;

        getline(ss, name, ',');
        ss >> grade;

        cout << "Name: " << name << " | Grade: " << grade << endl;
    }

    inFile.close();
    return 0;
}
```

**If students.txt contains:**
```
Alice,95.5
Bob,88.0
Carol,92.3
```

**Output:**
```
--- Student Records ---
Name: Alice | Grade: 95.5
Name: Bob | Grade: 88
Name: Carol | Grade: 92.3
```

### Copy One File to Another

```cpp
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream src("source.txt");
    ofstream dst("copy.txt");

    if (!src || !dst) {
        cout << "Error opening files." << endl;
        return 1;
    }

    string line;
    while (getline(src, line)) {
        dst << line << endl;
    }

    src.close();
    dst.close();
    cout << "File copied successfully." << endl;
    return 0;
}
```

---

## Common Mistakes

### Mistake 1: Forgetting to Check if the File Opened

**Wrong:**
```cpp
ifstream inFile("data.txt");
string line;
while (getline(inFile, line)) {  // No check — silent failure if file missing
    cout << line << endl;
}
```

**Correct:**
```cpp
ifstream inFile("data.txt");
if (!inFile) {
    cout << "Error: cannot open data.txt" << endl;
    return 1;
}
string line;
while (getline(inFile, line)) {
    cout << line << endl;
}
```

**Explanation:** If the file does not exist or cannot be opened, reading from the stream silently fails. Always check before reading.

---

### Mistake 2: Using `eof()` as the Loop Condition

**Wrong:**
```cpp
ifstream inFile("numbers.txt");
int num;
while (!inFile.eof()) {
    inFile >> num;
    cout << num << endl;  // Last value printed twice!
}
```

**Correct:**
```cpp
ifstream inFile("numbers.txt");
int num;
while (inFile >> num) {
    cout << num << endl;
}
```

**Explanation:** `eof()` only becomes true **after** a read fails. Using it as the condition causes the loop body to execute one extra time with stale data.

---

### Mistake 3: Opening for Writing Without `ios::app` (Accidentally Erasing Data)

**Wrong:**
```cpp
ofstream outFile("log.txt");         // Erases existing content!
outFile << "New entry" << endl;
```

**Correct:**
```cpp
ofstream outFile("log.txt", ios::app);  // Appends to existing content
outFile << "New entry" << endl;
```

**Explanation:** By default, `ofstream` opens in `ios::out` mode, which truncates the file. Use `ios::app` to preserve existing data.

---

### Mistake 4: Mixing `>>` and `getline()` Without `cin.ignore()`

**Wrong:**
```cpp
int age;
string name;
cin >> age;
getline(cin, name);   // Reads the leftover '\n', name is empty!
```

**Correct:**
```cpp
int age;
string name;
cin >> age;
cin.ignore();          // Discard the leftover newline
getline(cin, name);
```

**Explanation:** The `>>` operator leaves a newline character `'\n'` in the buffer. `getline()` then reads that newline as an empty line. Call `cin.ignore()` between them.

---

### Mistake 5: Using a Closed or Out-of-Scope Stream

**Wrong:**
```cpp
ofstream outFile("data.txt");
outFile.close();
outFile << "More data" << endl;  // Stream is closed — write fails silently!
```

**Correct:**
```cpp
ofstream outFile("data.txt");
outFile << "More data" << endl;
outFile.close();                 // Close AFTER all writing is done
```

**Explanation:** Once a stream is closed, further operations on it are silently ignored. Always finish all I/O before calling `.close()`.

---

## Practice Exercises

### Exercise 1: Write Numbers to a File
Write a program that asks the user for 5 integers and saves them to a file called `numbers.txt`, one per line.

**Expected output in numbers.txt:**
```
10
25
7
42
99
```

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream outFile("numbers.txt");
    if (!outFile) {
        cout << "Error opening file." << endl;
        return 1;
    }

    for (int i = 0; i < 5; i++) {
        int num;
        cout << "Enter number " << (i + 1) << ": ";
        cin >> num;
        outFile << num << endl;
    }

    outFile.close();
    cout << "Numbers saved." << endl;
    return 0;
}
```
</details>

---

### Exercise 2: Read and Display a File
Write a program that reads `numbers.txt` and displays each number along with its line number.

**Expected output:**
```
Line 1: 10
Line 2: 25
Line 3: 7
Line 4: 42
Line 5: 99
```

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream inFile("numbers.txt");
    if (!inFile) {
        cout << "Cannot open numbers.txt" << endl;
        return 1;
    }

    int num, line = 1;
    while (inFile >> num) {
        cout << "Line " << line << ": " << num << endl;
        line++;
    }

    inFile.close();
    return 0;
}
```
</details>

---

### Exercise 3: Sum and Average from File
Read all integers from `numbers.txt`, compute the sum and average, and display them on the console.

**Expected output:**
```
Sum: 183
Average: 36.6
```

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream inFile("numbers.txt");
    if (!inFile) {
        cout << "Cannot open file." << endl;
        return 1;
    }

    int num, sum = 0, count = 0;
    while (inFile >> num) {
        sum += num;
        count++;
    }

    inFile.close();

    if (count > 0) {
        cout << "Sum: " << sum << endl;
        cout << "Average: " << (double)sum / count << endl;
    } else {
        cout << "File is empty." << endl;
    }

    return 0;
}
```
</details>

---

### Exercise 4: Append a Log Entry
Write a program that appends the current date and a user-provided message to `activity_log.txt`. Each entry should be on its own line.

**Expected content after two runs:**
```
2025-01-15: Started project
2025-01-16: Fixed bug in parser
```

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string date, message;

    cout << "Enter date (YYYY-MM-DD): ";
    cin >> date;
    cin.ignore();

    cout << "Enter message: ";
    getline(cin, message);

    ofstream logFile("activity_log.txt", ios::app);
    if (!logFile) {
        cout << "Error opening log file." << endl;
        return 1;
    }

    logFile << date << ": " << message << endl;
    logFile.close();

    cout << "Log entry added." << endl;
    return 0;
}
```
</details>

---

### Exercise 5: Word Counter
Write a program that reads a text file and counts the total number of words, lines, and characters.

**Expected output for a sample file:**
```
Lines: 4
Words: 16
Characters: 82
```

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    ifstream inFile("sample.txt");
    if (!inFile) {
        cout << "Cannot open file." << endl;
        return 1;
    }

    int lines = 0, words = 0, chars = 0;
    string line;

    while (getline(inFile, line)) {
        lines++;
        chars += line.length();

        stringstream ss(line);
        string word;
        while (ss >> word) {
            words++;
        }
    }

    inFile.close();

    cout << "Lines: " << lines << endl;
    cout << "Words: " << words << endl;
    cout << "Characters: " << chars << endl;

    return 0;
}
```
</details>

---

## Summary

### Key Concepts

- `ofstream` writes to files; `ifstream` reads from files; `fstream` does both.
- Always include `<fstream>` and check that the file opened successfully.
- Use `<<` to write and `>>` or `getline()` to read.
- `ios::app` appends without erasing; default `ios::out` erases the file.
- Let the read operation control the loop — never use `eof()` as the condition.

### Important Points

1. Files are opened via the constructor or the `.open()` method.
2. Always verify the stream state before performing I/O.
3. `>>` skips whitespace; `getline()` reads the entire line including spaces.
4. Call `cin.ignore()` when mixing `>>` and `getline()`.
5. `.close()` flushes the buffer and releases the file resource.
6. Combine open modes with `|` (e.g., `ios::out | ios::binary`).
7. `fstream` with `ios::in | ios::out` allows read-write access to the same file.

### Quick Reference

```cpp
// Write
ofstream out("file.txt");
out << "data" << endl;
out.close();

// Read line by line
ifstream in("file.txt");
string line;
while (getline(in, line)) { /* process line */ }
in.close();

// Append
ofstream app("file.txt", ios::app);
app << "new data" << endl;
app.close();
```

### Next Steps

In the next lecture, you will learn about **structs and records** — how to group related data together and store structured records in files efficiently.
