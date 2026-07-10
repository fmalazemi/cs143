# CS143 — Conversions and the Math Library

> **Course:** CS143 Introduction to C++ · **Instructor:** Dr. Fawaz Alazemi
> **Builds on:** variables, types, strings, and functions.

---

## Table of Contents

1. [Numbers and Text Are Different Things](#1-numbers-and-text-are-different-things)
2. [The Conversion Map](#2-the-conversion-map)
3. [int → string](#3-int--string)
4. [string → int](#4-string--int)
5. [A char Is Really a Small Number](#5-a-char-is-really-a-small-number)
6. [The Classic Trap](#6-the-classic-trap)
7. [Digit ⇄ Character](#7-digit--character)
8. [Worked Examples with Digits](#8-worked-examples-with-digits)
9. [The Math Library](#9-the-math-library)
10. [Rounding: floor, ceil, round](#10-rounding-floor-ceil-round)
11. [Remainders: % and fmod](#11-remainders--and-fmod)
12. [The Truncation Trap](#12-the-truncation-trap)
13. [How Python Differs](#13-how-python-differs)
14. [Common Mistakes](#14-common-mistakes)
15. [Practice Exercises](#15-practice-exercises)
16. [Summary](#16-summary)

---

## 1. Numbers and Text Are Different Things

`cout` hides the difference, so it is easy to forget that `42` and `"42"` are not the same thing.

```cpp
int n = 42;        // a number: n + 1 is 43
string s = "42";   // text: s.length() is 2
```

With a number you can do arithmetic. With a string you can find its length or read `s[0]`, but arithmetic makes no sense. We often need to move between the two — when reading input, building messages, or working on digits one at a time.

---

## 2. The Conversion Map

```
                        +-----------+
                        |    int    |
                        |    42     |
                        +-----------+
                        /           \
        to_string(n)   /             \   '0' + d
                      /               \
             stoi(s)  \               /  c - '0'
                       \             /
              +-----------+     +-----------+
              |  string   |<--->|   char    |
              |   "42"    | s[i]|    '4'    |
              +-----------+     +-----------+
                     string(1, c)
```

Each arrow is one line of C++.

---

## 3. int → string

```cpp
#include <string>
using namespace std;

int n = 42;
string s = to_string(n);   // "42"

cout << s.length() << endl;   // 2
cout << s + "!" << endl;      // 42!
```

**Output:**
```
2
42!
```

- `to_string` works for `int`, `double`, `long`, and more.
- It needs `#include <string>`.
- Once the number is a string, you can join it with `+`.

There is an older way using a `stringstream`:

```cpp
#include <sstream>
stringstream ss;
ss << 42;
string s = ss.str();       // "42"
```

Prefer `to_string`. The `stringstream` form is longer and older.

---

## 4. string → int

```cpp
#include <string>
using namespace std;

string s = "123";

int n = stoi(s);            // string to int
cout << n + 1 << endl;      // 124

double d = stod("3.14");    // string to double
cout << d << endl;          // 3.14
```

**Output:**
```
124
3.14
```

| Function | Gives |
|----------|-------|
| `stoi` | `int` |
| `stod` | `double` |
| `stol` | `long` |

Note that `stoi("hello")` is an error — the text must look like a number.

### A round trip

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    int age = 20;

    // number -> text, to build a message
    string msg = "Age: " + to_string(age);
    cout << msg << endl;

    // text -> number, to do arithmetic
    string input = "15";
    int years = stoi(input);
    cout << "Next year: " << years + 1 << endl;

    return 0;
}
```

**Output:**
```
Age: 20
Next year: 16
```

Writing `"Age: " + age` without `to_string` will not compile.

---

## 5. A char Is Really a Small Number

Every character is stored as a number — its **ASCII code**. The digit characters `'0'` to `'9'` sit next to each other, in order:

```
   char:   '0'  '1'  '2'  '3'  '4'  '5'  '6'  '7'  '8'  '9'
   ascii:   48   49   50   51   52   53   54   55   56   57
```

Because they are consecutive, two simple formulas follow:

```
   character -> digit :   '5' - '0'  =  53 - 48  =  5
   digit -> character :   '0' + 5    =  48 + 5   =  '5'
```

Other useful codes: `'A'` is 65, and `'a'` is 97.

---

## 6. The Classic Trap

`char c = 5;` is **not** the character `'5'`.

**Wrong:**
```cpp
char c = 5;
cout << c;      // prints nothing visible!
```

**Correct:**
```cpp
char c = '0' + 5;
cout << c;      // prints 5
```

```
char c = 5;       ascii code 5    -> an invisible control character
char c = '0'+5;   ascii code 53   -> prints 5
```

**Rule:** to turn a digit `d` into a character, add `'0'`.

---

## 7. Digit ⇄ Character

```cpp
char d = '7';

// character -> the digit it shows
cout << d - '0' << endl;    // 7

// character -> its ASCII code
cout << (int)d << endl;     // 55
cout << (int)'A' << endl;   // 65

// a number -> the character with that code
cout << (char)66 << endl;   // B

// careful: this is arithmetic, not text
cout << '5' + 1 << endl;         // 54
cout << (char)('5' + 1) << endl; // 6
```

**Output:**
```
7
55
65
B
54
6
```

Notice that `'5' + 1` gives `54`, a number. Cast it back to `char` to see `'6'`.

Use `- '0'` for the **digit value**; use `(int)` for the **ASCII code**.

---

## 8. Worked Examples with Digits

### Summing the digits of a string

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "4729";
    int sum = 0;

    for (int i = 0; i < s.length(); i++) {
        // s[i] is a char; subtract '0' to get its value
        sum += s[i] - '0';
    }

    cout << "Sum of digits: " << sum << endl;
    return 0;
}
```

**Output:**
```
Sum of digits: 22
```

Because `4 + 7 + 2 + 9 = 22`. If you forget `- '0'`, you add the ASCII codes instead and get **214**.

### Building a string digit by digit

This is `to_string` written by hand.

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n = 407;
    string out = "";

    if (n == 0) out = "0";

    while (n > 0) {
        int digit = n % 10;              // last digit
        out = char('0' + digit) + out;   // put it in front
        n = n / 10;                      // drop it
    }

    cout << out << endl;
    return 0;
}
```

**Output:**
```
407
```

`% 10` takes the last digit and `/ 10` removes it. The digits come out backwards, so each new one is placed **in front** of the rest. In real code, just use `to_string(407)`.

---

## 9. The Math Library

```cpp
#include <cmath>   // put this at the top
```

| Function | Meaning | Example | Result |
|----------|---------|---------|--------|
| `sqrt(x)` | square root | `sqrt(16)` | `4` |
| `pow(a, b)` | a to the power b | `pow(2, 10)` | `1024` |
| `abs(x)` | absolute value | `abs(-7)` | `7` |
| `floor(x)` | round down | `floor(3.7)` | `3` |
| `ceil(x)` | round up | `ceil(3.2)` | `4` |
| `round(x)` | nearest whole | `round(3.5)` | `4` |
| `fmod(a, b)` | remainder, decimals | `fmod(10.5, 3)` | `1.5` |

Nearly all of these take and return a `double`.

### sqrt and pow

```cpp
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    cout << sqrt(16) << endl;     // 4
    cout << sqrt(2) << endl;      // 1.41421

    cout << pow(2, 10) << endl;   // 1024
    cout << pow(5, 3) << endl;    // 125

    // a fractional power is a root
    cout << pow(9, 0.5) << endl;  // 3
    return 0;
}
```

**Output:**
```
4
1.41421
1024
125
3
```

- There is no `**` operator in C++ — always use `pow`.
- `cout` shows about 6 digits by default, so `sqrt(2)` appears as `1.41421`.
- For simple squaring, `dx * dx` is faster and clearer than `pow(dx, 2)`.

### Distance between two points

```cpp
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x1 = 0, y1 = 0;
    double x2 = 3, y2 = 4;

    double dx = x2 - x1;          // 3
    double dy = y2 - y1;          // 4

    double dist = sqrt(pow(dx, 2) + pow(dy, 2));

    cout << "Distance: " << dist << endl;
    return 0;
}
```

**Output:**
```
Distance: 5
```

The classic 3-4-5 triangle.

---

## 10. Rounding: floor, ceil, round

```
   x = 3.7
       3 -------------●------- 4
       ^              3.7      ^
    floor -> 3               ceil -> 4
                round -> 4  (nearer to 4)

   x = -3.2       (careful!)
      -4 -------------●------- -3
       ^             -3.2      ^
    floor -> -4              ceil -> -3
```

| Call | Result |
|------|--------|
| `floor(3.7)` | `3` |
| `floor(-3.2)` | `-4` |
| `ceil(3.2)` | `4` |
| `ceil(-3.7)` | `-3` |
| `round(3.5)` | `4` |
| `round(3.4)` | `3` |
| `round(-3.5)` | `-4` |

**Remember:** `floor` always moves **left** on the number line and `ceil` always moves **right** — even for negative numbers. `round` goes to the nearest whole number, and away from zero on a tie.

---

## 11. Remainders: % and fmod

```cpp
#include <cmath>

cout << 10 % 3 << endl;        // 1   (int only)
cout << fmod(10, 3) << endl;   // 1
cout << fmod(10.5, 3) << endl; // 1.5

// integer division surprises beginners
cout << 10 / 3 << endl;        // 3
cout << 10.0 / 3 << endl;      // 3.33333
```

**Output:**
```
1
1
1.5
3
3.33333
```

- `%` refuses to work on a `double`.
- `10 / 3` is **3**: two ints divide to give an int.
- Make one side a `double` to keep the fraction.

---

## 12. The Truncation Trap

Assignment from `double` to `int` does **not** round. It throws the fractional part away.

**Cut, not rounded:**
```cpp
int t = 3.99;
cout << t;      // 3
```

**Round on purpose:**
```cpp
int t = round(3.99);
cout << t;      // 4
```

**Why this matters:** `sqrt` and `pow` return a `double`. If a result comes out as `4.999999` instead of `5`, storing it in an `int` silently gives `4`.

Safe habit:

```cpp
int n = (int)round(pow(a, b));
```

---

## 13. How Python Differs

| Goal | Python | C++ |
|------|--------|-----|
| int → string | `str(42)` | `to_string(42)` |
| string → int | `int("42")` | `stoi("42")` |
| char → digit | `int('7')` | `'7' - '0'` |
| ASCII code | `ord('A')` | `(int)'A'` |
| Power | `2 ** 10` | `pow(2, 10)` |
| Square root | `math.sqrt(16)` | `sqrt(16)` |

Python has no separate `char` type — a single character is just a short string. In C++ a `char` **is a number**, which is exactly why `- '0'` works.

---

## 14. Common Mistakes

**1. `char c = 5;`**

**Wrong:**
```cpp
char c = 5;       // ASCII code 5, invisible
```

**Correct:**
```cpp
char c = '0' + 5; // the character '5'
```

**Explanation:** the digit five and the character `'5'` are different numbers.

**2. Adding characters expecting text**

**Wrong:**
```cpp
cout << '4' + '2';    // 102
```

**Correct:**
```cpp
cout << string("4") + "2";   // 42
```

**Explanation:** `char` values add as numbers: `52 + 50 = 102`.

**3. Forgetting `- '0'`**

**Wrong:**
```cpp
sum += s[i];          // adds ASCII codes
```

**Correct:**
```cpp
sum += s[i] - '0';    // adds digit values
```

**Explanation:** summing `"4729"` the wrong way gives 214 instead of 22.

**4. Joining text and a number**

**Wrong:**
```cpp
string msg = "Age: " + age;    // will not compile
```

**Correct:**
```cpp
string msg = "Age: " + to_string(age);
```

**Explanation:** `+` needs a string on both sides.

**5. `int n = 3.99;`**

**Wrong:**
```cpp
int n = 3.99;         // stores 3
```

**Correct:**
```cpp
int n = round(3.99);  // stores 4
```

**Explanation:** assignment cuts the fraction; it does not round.

**6. Integer division for an average**

**Wrong:**
```cpp
double avg = 10 / 3;      // 3
```

**Correct:**
```cpp
double avg = 10.0 / 3;    // 3.33333
```

**Explanation:** two ints divide as ints before the result is stored.

**The habit:** ask "is this value a number, or the *text* of a number?"

---

## 15. Practice Exercises

Try each one before opening the solution.

**Exercise 1.** Write one line that turns the `int n = 99` into the string `"99"`.

<details>
<summary>Click to see solution</summary>

```cpp
string s = to_string(n);   // "99"
```
</details>

**Exercise 2.** Given `char c = '8';`, write the expression that gives the number `8`, and the expression that gives its ASCII code.

<details>
<summary>Click to see solution</summary>

```cpp
int value = c - '0';   // 8
int code  = (int)c;    // 56
```

Subtracting `'0'` gives the digit; casting gives the ASCII code.
</details>

**Exercise 3.** What does `cout << '3' + '4';` print, and why?

<details>
<summary>Click to see solution</summary>

```
103
```

Both are numbers: `51 + 52 = 103`. C++ adds their ASCII codes; it does not join them as text. To join them, use strings: `string("3") + "4"` gives `"34"`.
</details>

**Exercise 4.** Write a loop that counts how many digits in the string `"90210"` are even.

<details>
<summary>Click to see solution</summary>

```cpp
string s = "90210";
int count = 0;
for (int i = 0; i < s.length(); i++) {
    int d = s[i] - '0';
    if (d % 2 == 0) count++;
}
cout << count << endl;   // 3
```

The digits are 9, 0, 2, 1, 0. The even ones are 0, 2, 0 — so the answer is **3**. Remember that zero counts as even.
</details>

**Exercise 5.** What are `floor(-2.5)`, `ceil(-2.5)`, and `round(-2.5)`?

<details>
<summary>Click to see solution</summary>

```
floor(-2.5) = -3
ceil(-2.5)  = -2
round(-2.5) = -3
```

`floor` goes left, `ceil` goes right, and `round` goes away from zero on a tie.
</details>

**Exercise 6.** Explain why `int x = sqrt(26);` stores `5`, and how to get `5` on purpose.

<details>
<summary>Click to see solution</summary>

`sqrt(26)` is about `5.09902`. Assigning a `double` to an `int` **cuts** the fraction, giving `5`. To round deliberately:

```cpp
int x = round(sqrt(26));
```
</details>

---

## 16. Summary

### Key Concepts

- `to_string(n)` turns a number into text; `stoi(s)` and `stod(s)` turn text into numbers.
- A `char` **is a number** — its ASCII code. `'0'` is 48.
- `<cmath>` supplies `sqrt`, `pow`, `abs`, `floor`, `ceil`, `round`, and `fmod`.

### Important Points

1. Digit → character: `'0' + d`. Character → digit: `c - '0'`.
2. `char c = 5;` is an invisible control character, not `'5'`.
3. `'4' + '2'` is `102`, because chars add as numbers.
4. `floor` goes left, `ceil` goes right — even for negative numbers.
5. `%` works only on integers; use `fmod` for decimals.
6. Storing a `double` in an `int` **cuts** the fraction; use `round` to round.

### Quick Reference

```cpp
#include <string>
#include <cmath>

// numbers and text
string s = to_string(42);      // "42"
int    n = stoi("42");         // 42
double d = stod("3.14");       // 3.14

// digits and characters
int  digit = c - '0';          // '7' -> 7
char ch    = '0' + digit;      // 7   -> '7'
int  code  = (int)c;           // '7' -> 55

// math library
sqrt(16)        // 4
pow(2, 10)      // 1024
abs(-7)         // 7
floor(3.7)      // 3     floor(-3.2)  -> -4
ceil(3.2)       // 4     ceil(-3.7)   -> -3
round(3.5)      // 4
fmod(10.5, 3)   // 1.5
10 % 3          // 1     (integers only)

// safe conversion back to int
int r = (int)round(sqrt(26));  // 5
```

### The One Rule to Remember

Always ask: is this a number, or the *text* of a number?
