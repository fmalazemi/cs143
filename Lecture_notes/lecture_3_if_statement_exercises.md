# CS 143 — Lecture 3 Exercises: Conditional Statements in C++

These exercises support **Lecture 3: Conditional Statements**.

> Tip: If you are publishing on **GitHub Pages**, the solution dropdowns should work correctly with the format below.

---

## Exercise 1: Positive, Negative, or Zero

Write a program that asks for a number and prints whether it is **positive**, **negative**, or **zero**.

<details markdown="1">
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int num;

    cout << "Enter a number: ";
    cin >> num;

    if (num > 0) {
        cout << "Positive" << endl;
    } else if (num < 0) {
        cout << "Negative" << endl;
    } else {
        cout << "Zero" << endl;
    }

    return 0;
}
```
</details>

---

## Exercise 2: Voting Eligibility

Create a program that checks if someone can vote based on:
- Age must be **18 or older**
- Must be a **citizen** (ask the user)

<details markdown="1">
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int age;
    bool citizen;

    cout << "Enter your age: ";
    cin >> age;

    cout << "Are you a citizen? (1=yes, 0=no): ";
    cin >> citizen;

    if (age >= 18 && citizen) {
        cout << "You can vote! ✅" << endl;
    } else if (age < 18) {
        cout << "Too young to vote." << endl;
    } else {
        cout << "You must be a citizen to vote." << endl;
    }

    return 0;
}
```
</details>

---

## Exercise 3: Maximum of Three Numbers

Write a program that reads three numbers and prints the **largest** one.

<details markdown="1">
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int a, b, c;

    cout << "Enter three numbers: ";
    cin >> a >> b >> c;

    if (a >= b && a >= c) {
        cout << "Largest: " << a << endl;
    } else if (b >= a && b >= c) {
        cout << "Largest: " << b << endl;
    } else {
        cout << "Largest: " << c << endl;
    }

    return 0;
}
```
</details>

---

## Exercise 4: Temperature Converter with Validation

Create a program that:
1. Asks the user to choose conversion (**C to F** or **F to C**)
2. Reads the temperature value
3. Validates the choice
4. Performs the conversion and prints the result

<details markdown="1">
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int choice;
    double temp, result;

    cout << "Temperature Converter" << endl;
    cout << "1. Celsius to Fahrenheit" << endl;
    cout << "2. Fahrenheit to Celsius" << endl;
    cout << "Choice: ";
    cin >> choice;

    if (choice == 1) {
        cout << "Enter temperature in Celsius: ";
        cin >> temp;
        result = (temp * 9.0 / 5.0) + 32;
        cout << temp << "°C = " << result << "°F" << endl;
    } else if (choice == 2) {
        cout << "Enter temperature in Fahrenheit: ";
        cin >> temp;
        result = (temp - 32) * 5.0 / 9.0;
        cout << temp << "°F = " << result << "°C" << endl;
    } else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
```
</details>

---

## Submission Notes (optional)

- Use clear variable names.
- Test at least **3 different inputs** for each exercise.
- Always include `return 0;` at the end of `main()`.
