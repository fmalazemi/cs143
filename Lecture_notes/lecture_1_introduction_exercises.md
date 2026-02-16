
## Lecture 1 Exercises: Introduction to C++

Focus:
- Writing a simple C++ program
- Using `cout` for output
- Using `endl` and `\n`
- Compiling and running a program

---

## Exercise 1: Your First Program

Write a C++ program that prints the following line:

Welcome to C++ Programming!

<details markdown="1">
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Welcome to C++ Programming!" << endl;
    return 0;
}
```
</details>

---

## Exercise 2: Print Personal Information

Write a program that prints:
- Your name
- Your major
- Your favorite programming language

Each item must appear on a new line.

<details markdown="1">
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Name: Ahmed" << endl;
    cout << "Major: Computer Science" << endl;
    cout << "Favorite Language: C++" << endl;
    return 0;
}
```
</details>

---

## Exercise 3: Print a Simple Message

Write a program that prints the following on three lines:

Hello  
World  
C++ is fun!

<details markdown="1">
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Hello" << endl;
    cout << "World" << endl;
    cout << "C++ is fun!" << endl;
    return 0;
}
```
</details>

---

## Exercise 4: Output on One Line

Write a program that prints:

My age is 20

Use multiple items with the output operator `<<`.

<details markdown="1">
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "My age is " << 20 << endl;
    return 0;
}
```
</details>

---

## Exercise 5: Using the Newline Character

Write a program that prints three sentences using the newline character `\n` instead of `endl`.

<details markdown="1">
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Line one\n";
    cout << "Line two\n";
    cout << "Line three\n";
    return 0;
}
```
</details>

---

## Exercise 6: Print a Pattern

Write a program that prints the following pattern:

\* <br>
\** <br>
\*** <br>
\**** <br>
\***** <br>

<details markdown="1">
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "*" << endl;
    cout << "**" << endl;
    cout << "***" << endl;
    cout << "****" << endl;
    cout << "*****" << endl;
    return 0;
}
```
</details>

---

## Exercise 8: Fix the Errors

The following program contains errors. Fix them so it compiles and prints:

Hello World

```cpp
include <iostream>

int main()
{
cout << Hello World
return 0
}
```

<details markdown="1">
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Hello World" << endl;
    return 0;
}
```
</details>

---

