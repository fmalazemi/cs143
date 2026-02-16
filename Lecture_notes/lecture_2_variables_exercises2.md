## Lecture 2: Variables and data types

These exercises provide practice on:
- Declaring variables
- Reading input with `cin`
- Printing output with `cout`
- Performing arithmetic calculations
- Writing correct math expressions

---

## Exercise 1: Square of a Number

Ask the user to enter a number. Print its square.

<details markdown="1">
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    double x;
    cout << "Enter a number: ";
    cin >> x;

    cout << "Square = " << (x * x) << endl;
    return 0;
}
```
</details>

---

## Exercise 2: Sum, Difference, Product, and Quotient

Read two numbers and print:
- Sum
- Difference
- Product
- Quotient

<details markdown="1">
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    double a, b;

    cout << "Enter two numbers: ";
    cin >> a >> b;

    cout << "Sum: " << (a + b) << endl;
    cout << "Difference: " << (a - b) << endl;
    cout << "Product: " << (a * b) << endl;

    if (b != 0) {
        cout << "Quotient: " << (a / b) << endl;
    } else {
        cout << "Quotient: undefined (division by zero)" << endl;
    }

    return 0;
}
```
</details>

---

## Exercise 3: Temperature Conversion (Celsius to Fahrenheit)

Read temperature in Celsius and convert it to Fahrenheit.

Formula:  
F = (C × 9 / 5) + 32

<details markdown="1">
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    double c, f;

    cout << "Enter temperature in Celsius: ";
    cin >> c;

    f = (c * 9.0 / 5.0) + 32.0;

    cout << c << "°C = " << f << "°F" << endl;
    return 0;
}
```
</details>

---

## Exercise 4: Rectangle Perimeter and Area

Read width and height of a rectangle. Print:
- Perimeter
- Area

<details markdown="1">
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    double width, height;

    cout << "Enter width and height: ";
    cin >> width >> height;

    double perimeter = 2 * (width + height);
    double area = width * height;

    cout << "Perimeter = " << perimeter << endl;
    cout << "Area = " << area << endl;
    return 0;
}
```
</details>

---

## Exercise 5: Circle Calculations

Read radius of a circle. Print:
- Diameter
- Circumference
- Area

Use π = 3.14159 as a constant.

<details markdown="1">
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    const double pi = 3.14159;
    double r;

    cout << "Enter radius: ";
    cin >> r;

    double diameter = 2 * r;
    double circumference = 2 * pi * r;
    double area = pi * r * r;

    cout << "Diameter = " << diameter << endl;
    cout << "Circumference = " << circumference << endl;
    cout << "Area = " << area << endl;
    return 0;
}
```
</details>

---

## Exercise 6: Average of Four intergest

Read four integers and print their average.

<details markdown="1">
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int a, b, c, d;

    cout << "Enter four numbers: ";
    cin >> a >> b >> c >> d;

    double avg = (a + b + c + d) / 4.0;

    cout << "Average = " << avg << endl;
    return 0;
}
```
</details>

---

## Exercise 7: Convert Minutes to Hours and Minutes

Read total minutes and convert into:
- hours
- remaining minutes

Example: 130 minutes → 2 hours 10 minutes

<details markdown="1">
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int minutes;

    cout << "Enter total minutes: ";
    cin >> minutes;

    int hours = minutes / 60;
    int rem = minutes % 60;

    cout << hours << " hours " << rem << " minutes" << endl;
    return 0;
}
```
</details>

---

## Exercise 8: Swap Without a Temporary Variable

Read two integers and swap their values **without** using a temporary variable.
Then print the swapped values.

<details markdown="1">
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int a, b;

    cout << "Enter two integers: ";
    cin >> a >> b;

    a = a + b;
    b = a - b;
    a = a - b;

    cout << "After swap: " << a << " " << b << endl;
    return 0;
}
```
</details>

---

## Exercise 9: Evaluate an Expression

Read integers of `a`, `b`, and `c`. Compute:

a² + b² + c²

<details markdown="1">
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int a, b, c;

    cout << "Enter a, b, and c: ";
    cin >> a >> b >> c;

    double result = a * a + b * b + c * c;

    cout << "Result = " << result << endl;
    return 0;
}
```
</details>

---

## Exercise 10: Simple Interest Calculator

Read:
- principal (P)
- rate (R)
- time (T)

Calculate simple interest:

SI = (P × R × T) / 100

<details markdown="1">
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    double p, r, t;

    cout << "Enter principal, rate, and time: ";
    cin >> p >> r >> t;

    double si = (p * r * t) / 100.0;

    cout << "Simple Interest = " << si << endl;
    return 0;
}
```
</details>

---
