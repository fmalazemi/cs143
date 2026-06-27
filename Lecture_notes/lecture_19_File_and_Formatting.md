# CS143 — File Input / Output &amp; String Formatting

> **Course:** CS143 Introduction to C++ · **Instructor:** Dr. Fawaz Alazemi
> **Builds on:** Lecture 1 (cin &amp; cout).

---

## Table of Contents

1. [Introduction](#1-introduction)
2. [Writing to a File](#2-writing-to-a-file)
3. [Reading From a File](#3-reading-from-a-file)
4. [Reading Line by Line](#4-reading-line-by-line)
5. [istream and ostream](#5-istream-and-ostream)
6. [Widths and Alignment](#6-widths-and-alignment)
7. [Controlling Decimal Places](#7-controlling-decimal-places)
8. [Building Strings](#8-building-strings)
9. [Common Mistakes](#9-common-mistakes)
10. [Practice Exercises](#10-practice-exercises)
11. [Summary](#11-summary)

---

## 1. Introduction

A **stream** is a flow of data. You already use two of them: `cout` sends data out to the screen, and `cin` brings data in from the keyboard.

Files use the very same idea, through the `<fstream>` header:

- `ofstream` — **o**utput **f**ile **stream** — writes to a file.
- `ifstream` — **i**nput **f**ile **stream** — reads from a file.

```
                     ofstream  <<  (write)
   Your Program  ---------------------------->  data.txt
                 <----------------------------
                     ifstream  >>  (read)
```

The best part: files use the same `<<` and `>>` operators you already know. This lecture has two parts — **Part A** is reading and writing files, and **Part B** is shaping how output looks (string formatting).

---

## 2. Writing to a File

Create an `ofstream`, give it a file name, and write to it with `<<` — exactly like `cout`.

```cpp
#include <fstream>
using namespace std;

int main() {
    ofstream out("data.txt");   // open (or create) for writing

    out << "Hello" << endl;     // write with <<
    out << 42 << endl;

    out.close();                // finish and save
    return 0;
}
```

**File `data.txt` now holds:**
```
Hello
42
```

- `ofstream out("data.txt")` opens the file, creating it if needed.
- Write with `<<`, exactly like `cout`.
- `close()` finishes and saves the file.

A loop writes many lines just as easily:

```cpp
ofstream out("scores.txt");
for (int i = 1; i <= 3; i++) {
    out << "Player " << i << ": " << i * 10 << endl;
}
out.close();
```

**File `scores.txt`:**
```
Player 1: 10
Player 2: 20
Player 3: 30
```

---

## 3. Reading From a File

Create an `ifstream`, **check that it opened**, then read with `>>` — exactly like `cin`.

```cpp
#include <fstream>
#include <iostream>
using namespace std;

int main() {
    ifstream in("data.txt");

    if (!in) {                   // did it open?
        cout << "Cannot open file";
        return 1;
    }

    string word;
    in >> word;                  // read one word
    cout << word << endl;
    in.close();
    return 0;
}
```

- `ifstream in("data.txt")` opens the file for reading.
- **Always check** it opened with `if (!in)` — a missing file is the most common error.
- Read with `>>`, exactly like `cin`.

To read many numbers, loop while the read succeeds:

```cpp
ifstream in("nums.txt");
int x;
while (in >> x) {        // stops at end of file
    cout << x << " ";
}
```

---

## 4. Reading Line by Line

Use `>>` for single words or numbers, and `getline` for whole lines (spaces included).

```cpp
#include <fstream>
#include <iostream>
using namespace std;

int main() {
    ifstream in("data.txt");
    string line;

    while (getline(in, line)) {   // one whole line each time
        cout << line << endl;
    }

    in.close();
    return 0;
}
```

The loop stops on its own at the end of the file. Here is a version that numbers each line:

```cpp
ifstream in("notes.txt");
string line;
int n = 1;
while (getline(in, line)) {
    cout << n << ": " << line << endl;
    n++;
}
in.close();
```

**If `notes.txt` has two lines:**
```
1: hello world
2: goodbye
```

---

## 5. istream and ostream

`cout` and `ofstream` are both kinds of **`ostream`** (output stream). `cin` and `ifstream` are both kinds of **`istream`** (input stream). So a function that takes an `ostream&` works for **either** the screen or a file.

```cpp
#include <fstream>
#include <iostream>
using namespace std;

// works with the screen OR a file
void writeReport(ostream& out) {
    out << "Report" << endl;
    out << "======" << endl;
}

int main() {
    writeReport(cout);          // to the screen
    ofstream f("report.txt");
    writeReport(f);             // to a file
    return 0;
}
```

You write the code once and choose the destination later — a small taste of how one interface can serve many targets.

---

## 6. Widths and Alignment

The `<iomanip>` header gives **manipulators** that control how the next value is printed. `setw(n)` sets a field width and pads the value to fit.

```
  cout << setw(10) << 42;

  [        ][        ][...8 padding...][ 4 ][ 2 ]
  |<-------------- field width = 10 -------------->|
  (the value is right-aligned by default)
```

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    cout << setw(8) << "Name" << setw(6) << "Age" << endl;
    cout << setw(8) << "Sara" << setw(6) << 20    << endl;
    cout << left << setw(8) << "Ali" << 22 << endl;
    return 0;
}
```

**Output:**
```
    Name   Age
    Sara    20
Ali     22
```

- `setw(n)` sets the width of the **next** item only.
- Values are **right**-aligned by default.
- `left` switches to left alignment (and `right` switches back).

---

## 7. Controlling Decimal Places

Use `fixed` together with `setprecision(n)` to show a number with exactly `n` decimal places.

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double pi = 3.14159265;

    cout << fixed << setprecision(2);
    cout << pi << endl;        // 3.14

    cout << setprecision(4);
    cout << pi << endl;        // 3.1416
    return 0;
}
```

**Output:**
```
3.14
3.1416
```

- `fixed` means "use plain decimal form".
- `setprecision(n)` then sets the number of decimal places.
- This is ideal for money: `fixed << setprecision(2)`.

Putting alignment and precision together makes a tidy table:

```cpp
cout << fixed << setprecision(2);
cout << left  << setw(10) << "Item"
     << right << setw(8)  << "Price" << endl;
cout << left  << setw(10) << "Apple"
     << right << setw(8)  << 1.5 << endl;
cout << left  << setw(10) << "Bread"
     << right << setw(8)  << 12.0 << endl;
```

**Output:**
```
Item         Price
Apple         1.50
Bread        12.00
```

---

## 8. Building Strings

A `stringstream` (from `<sstream>`) works like `cout`, but instead of printing it builds a **string**. Use it to assemble text from many pieces.

```cpp
#include <iostream>
#include <sstream>
using namespace std;

int main() {
    stringstream ss;
    ss << "Score: " << 95 << "/" << 100;
    string result = ss.str();        // the finished text
    cout << result << endl;          // Score: 95/100

    string s = to_string(42);        // quick number -> string
    cout << s << endl;               // 42
    return 0;
}
```

**Output:**
```
Score: 95/100
42
```

- A `stringstream` collects values with `<<`, just like `cout`.
- `ss.str()` returns the finished string.
- `to_string(n)` is a quick way to turn one number into a string.

---

## 9. Common Mistakes

**1. Not checking that the file opened**

**Wrong:**
```cpp
ifstream in("data.txt");
string w; in >> w;          // silently reads nothing if missing
```

**Correct:**
```cpp
ifstream in("data.txt");
if (!in) { cout << "Cannot open"; return 1; }
```

**Explanation:** if the file is missing, reads quietly fail. Always test `if (!in)` first.

**2. Forgetting the file header**

**Wrong:**
```cpp
ofstream out("data.txt");   // ERROR if <fstream> is missing
```

**Correct:**
```cpp
#include <fstream>
ofstream out("data.txt");
```

**Explanation:** file streams live in `<fstream>`.

**3. Mixing `>>` and `getline`**

**Wrong:**
```cpp
int n;
in >> n;             // leaves the newline behind
string line;
getline(in, line);   // reads an empty line
```

**Correct:**
```cpp
in >> n;
in.ignore();         // skip the leftover newline
getline(in, line);
```

**Explanation:** `>>` stops at whitespace and leaves the newline, which the next `getline` then reads as empty. Clear it with `in.ignore()`.

**4. Expecting `setw` to stick**

**Wrong:**
```cpp
cout << setw(10);
cout << 1 << 2 << 3;    // only the 1 is padded
```

**Correct:**
```cpp
cout << setw(10) << 1 << setw(10) << 2 << setw(10) << 3;
```

**Explanation:** `setw` affects only the **next** item, so repeat it for each value.

**5. `setprecision` without `fixed`**

**Wrong:**
```cpp
cout << setprecision(2) << 3.14159;   // prints 3.1 (2 significant digits)
```

**Correct:**
```cpp
cout << fixed << setprecision(2) << 3.14159;   // 3.14 (2 decimals)
```

**Explanation:** without `fixed`, `setprecision` counts significant digits, not decimal places.

**6. Forgetting `<iomanip>`**

**Wrong:**
```cpp
cout << setw(8) << "hi";   // ERROR if <iomanip> is missing
```

**Correct:**
```cpp
#include <iomanip>
cout << setw(8) << "hi";
```

**Explanation:** `setw`, `setprecision`, and `setfill` come from `<iomanip>`.

---

## 10. Practice Exercises

Try each one before opening the solution. Exercises 1–3 use files; 4–6 use formatting.

**Exercise 1.** Open a file `out.txt` with `ofstream` and write three lines to it.

<details>
<summary>Click to see solution</summary>

```cpp
ofstream out("out.txt");
out << "line one" << endl;
out << "line two" << endl;
out << "line three" << endl;
out.close();
```
</details>

**Exercise 2.** Open `in.txt` with `ifstream`, check it opened, then read and print it word by word.

<details>
<summary>Click to see solution</summary>

```cpp
ifstream in("in.txt");
if (!in) { cout << "Cannot open"; return 1; }
string word;
while (in >> word)
    cout << word << endl;
in.close();
```
</details>

**Exercise 3.** Read a file line by line with `getline` and print the total number of lines.

<details>
<summary>Click to see solution</summary>

```cpp
ifstream in("in.txt");
string line;
int count = 0;
while (getline(in, line))
    count++;
cout << "Lines: " << count << endl;
in.close();
```
</details>

**Exercise 4.** Print `3.14159` with exactly two decimal places.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iomanip>
cout << fixed << setprecision(2);
cout << 3.14159 << endl;   // 3.14
```
</details>

**Exercise 5.** Print two columns — a name and a price — lined up using `setw`.

<details>
<summary>Click to see solution</summary>

```cpp
cout << left  << setw(10) << "Apple"
     << right << setw(8)  << 3 << endl;
cout << left  << setw(10) << "Bread"
     << right << setw(8)  << 12 << endl;
```
</details>

**Exercise 6.** Use `stringstream` (or `to_string`) to build the text `"Score: 95/100"` and print it.

<details>
<summary>Click to see solution</summary>

```cpp
#include <sstream>
stringstream ss;
ss << "Score: " << 95 << "/" << 100;
cout << ss.str() << endl;   // Score: 95/100
```
</details>

---

## 11. Summary

### Key Concepts

- A **stream** is a flow of data; files use the same `<<` and `>>` as the console.
- `ofstream` writes to a file; `ifstream` reads from one.
- Manipulators in `<iomanip>` shape how output looks.

### Important Points

1. Always check a file opened with `if (!in)`.
2. `getline` reads whole lines; `>>` reads words or numbers and stops at whitespace.
3. `ostream&` / `istream&` let one function serve the console or a file.
4. `setw(n)` affects only the next item; `left` / `right` set alignment.
5. `fixed` with `setprecision(n)` gives exactly `n` decimal places.
6. `stringstream` and `to_string` build formatted strings.

### Quick Reference

```cpp
#include <fstream>
#include <iomanip>
#include <sstream>

ofstream out("f.txt");          // write
out << "hi" << endl; out.close();

ifstream in("f.txt");           // read
if (!in) { /* handle error */ }
string line;
while (getline(in, line)) { /* use line */ }

cout << setw(8) << "Name";              // width 8
cout << fixed << setprecision(2) << x;  // 2 decimals

stringstream ss; ss << "n=" << 5;
string s = ss.str();            // "n=5"
```

### Next Steps

A file stream also closes itself when it goes out of scope — its destructor does the work, a direct use of the lifecycle idea from the constructors and destructors lecture.
