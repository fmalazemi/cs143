## CS 143 — Conditional Statements Additional Exercises

This sheet provides extra practice on:
- `if`
- `if-else`
- `if-else-if`
- nested `if`

## Notes

- Each solution uses only topics covered in early lectures.
- For best style, keep braces `{ }` even for one line.

---

## Exercise 1: Positive or Not

Read an integer `x`.  
Print `Positive` if `x > 0`. Otherwise print `Not positive`.

<details markdown="1">
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int x;
    cin >> x;

    if (x > 0) {
        cout << "Positive" << endl;
    } else {
        cout << "Not positive" << endl;
    }
    return 0;
}
```
</details>

---

## Exercise 2: Even or Odd

Read an integer `n`.  
Print `Even` if `n` is even, otherwise print `Odd`.

<details markdown="1">
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n % 2 == 0) {
        cout << "Even" << endl;
    } else {
        cout << "Odd" << endl;
    }
    return 0;
}
```
</details>

---

## Exercise 3: Larger of Two

Read two integers `a` and `b`.  
Print the larger value.

<details markdown="1">
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    if (a >= b) {
        cout << a << endl;
    } else {
        cout << b << endl;
    }
    return 0;
}
```
</details>

---

## Exercise 4: Sign of a Number

Read an integer `x`.  
Print:
- `Positive` if `x > 0`
- `Negative` if `x < 0`
- `Zero` if `x == 0`

<details markdown="1">
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int x;
    cin >> x;

    if (x > 0) {
        cout << "Positive" << endl;
    } else if (x < 0) {
        cout << "Negative" << endl;
    } else {
        cout << "Zero" << endl;
    }
    return 0;
}
```
</details>

---

## Exercise 5: Grade (A/B/C/D/F)

Read an integer score `s` (0 to 100).  
Print:
- `A` if `s >= 90`
- `B` if `s >= 80`
- `C` if `s >= 70`
- `D` if `s >= 60`
- `F` otherwise

<details markdown="1">
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int s;
    cin >> s;

    if (s >= 90) {
        cout << "A" << endl;
    } else if (s >= 80) {
        cout << "B" << endl;
    } else if (s >= 70) {
        cout << "C" << endl;
    } else if (s >= 60) {
        cout << "D" << endl;
    } else {
        cout << "F" << endl;
    }
    return 0;
}
```
</details>

---

## Exercise 6: Valid Score

Read an integer `s`.  
If `s` is between 0 and 100 (inclusive), print `Valid`. Otherwise print `Invalid`.

<details markdown="1">
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int s;
    cin >> s;

    if (s >= 0 && s <= 100) {
        cout << "Valid" << endl;
    } else {
        cout << "Invalid" << endl;
    }
    return 0;
}
```
</details>

---

## Exercise 7: Maximum of Three

Read three integers `a`, `b`, `c`.  
Print the maximum value.

<details markdown="1">
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    int mx = a;
    if (b > mx) mx = b;
    if (c > mx) mx = c;

    cout << mx << endl;
    return 0;
}
```
</details>

---

## Exercise 8: Minimum of Three (using if-else-if)

Read three integers `a`, `b`, `c`.  
Print the minimum value.

<details markdown="1">
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    if (a <= b && a <= c) {
        cout << a << endl;
    } else if (b <= a && b <= c) {
        cout << b << endl;
    } else {
        cout << c << endl;
    }
    return 0;
}
```
</details>

---

## Exercise 9: Leap Year

Read an integer `year`.  
Print `Leap` if it is a leap year, otherwise print `Not leap`.

Rules:
- divisible by 400 → leap
- divisible by 100 → not leap
- divisible by 4 → leap
- otherwise not leap

<details markdown="1">
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int year;
    cin >> year;

    bool leap = false;

    if (year % 400 == 0) {
        leap = true;
    } else if (year % 100 == 0) {
        leap = false;
    } else if (year % 4 == 0) {
        leap = true;
    } else {
        leap = false;
    }

    if (leap) cout << "Leap" << endl;
    else cout << "Not leap" << endl;

    return 0;
}
```
</details>

---

## Exercise 10: Simple Login (nested if)

Read a username and password (no spaces).  
Valid login is:
- username: `admin`
- password: `1234`

Print:
- `Welcome` if both correct
- `Wrong password` if username correct but password wrong
- `User not found` otherwise

<details markdown="1">
<summary>Click to see solution</summary>

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string user, pass;
    cin >> user >> pass;

    if (user == "admin") {
        if (pass == "1234") {
            cout << "Welcome" << endl;
        } else {
            cout << "Wrong password" << endl;
        }
    } else {
        cout << "User not found" << endl;
    }
    return 0;
}
```
</details>

---

## Exercise 11: Ticket Price

Read an integer `age`.  
Print ticket price:
- age < 12 → `2`
- 12 to 59 → `5`
- age >= 60 → `3`

<details markdown="1">
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int age;
    cin >> age;

    if (age < 12) {
        cout << 2 << endl;
    } else if (age < 60) {
        cout << 5 << endl;
    } else {
        cout << 3 << endl;
    }
    return 0;
}
```
</details>

---

## Exercise 12: Triangle Validity (nested if)

Read three integers `a`, `b`, `c` (side lengths).  
Print `Valid` if they can form a triangle, otherwise print `Invalid`.

Triangle rule:
- a + b > c
- a + c > b
- b + c > a

<details markdown="1">
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    if (a + b > c) {
        if (a + c > b) {
            if (b + c > a) {
                cout << "Valid" << endl;
            } else {
                cout << "Invalid" << endl;
            }
        } else {
            cout << "Invalid" << endl;
        }
    } else {
        cout << "Invalid" << endl;
    }

    return 0;
}
```
</details>

---

## Exercise 13: Triangle Type (after validity)

Read three integers `a`, `b`, `c` (side lengths).

1) If not valid triangle → print `Invalid`  
2) Else print:
- `Equilateral` if all equal
- `Isosceles` if exactly two equal
- `Scalene` otherwise

<details markdown="1">
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    bool valid = (a + b > c) && (a + c > b) && (b + c > a);

    if (!valid) {
        cout << "Invalid" << endl;
    } else if (a == b && b == c) {
        cout << "Equilateral" << endl;
    } else if (a == b || a == c || b == c) {
        cout << "Isosceles" << endl;
    } else {
        cout << "Scalene" << endl;
    }

    return 0;
}
```
</details>

---

## Exercise 14: Calculator (if-else-if)

Read:
- `a` (double)
- `op` (char): one of `+ - * /`
- `b` (double)

Print the result.  
If operator is invalid print `Invalid operator`.  
If division by zero print `Division by zero`.

<details markdown="1">
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    double a, b;
    char op;
    cin >> a >> op >> b;

    if (op == '+') {
        cout << (a + b) << endl;
    } else if (op == '-') {
        cout << (a - b) << endl;
    } else if (op == '*') {
        cout << (a * b) << endl;
    } else if (op == '/') {
        if (b == 0) {
            cout << "Division by zero" << endl;
        } else {
            cout << (a / b) << endl;
        }
    } else {
        cout << "Invalid operator" << endl;
    }

    return 0;
}
```
</details>

---

## Exercise 15: Number Range Category

Read an integer `x`.  
Print:
- `Small` if 0 to 9
- `Medium` if 10 to 99
- `Large` if 100 or more
- `Negative` if x < 0

<details markdown="1">
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int x;
    cin >> x;

    if (x < 0) {
        cout << "Negative" << endl;
    } else if (x <= 9) {
        cout << "Small" << endl;
    } else if (x <= 99) {
        cout << "Medium" << endl;
    } else {
        cout << "Large" << endl;
    }

    return 0;
}
```
</details>

---


