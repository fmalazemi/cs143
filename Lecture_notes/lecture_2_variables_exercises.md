## CS 143 --- Lecture 2 Exercises: Variables, `cout`, and `cin`

Practice: - Declaring variables - Reading input using `cin` - Printing
output using `cout` - Using basic data types

------------------------------------------------------------------------

## Exercise 1: Store and Print a Number

Declare an integer variable named `age`, assign it any value, and print
it.

```{=html}
<details>
```
```{=html}
<summary>
```
Click to see solution
```{=html}
</summary>
```
``` cpp
#include <iostream>
using namespace std;

int main() {
    int age = 20;
    cout << "Age: " << age << endl;
    return 0;
}
```

```{=html}
</details>
```

------------------------------------------------------------------------

## Exercise 2: Read and Print an Integer

Ask the user to enter a number, then print it.

```{=html}
<details>
```
```{=html}
<summary>
```
Click to see solution
```{=html}
</summary>
```
``` cpp
#include <iostream>
using namespace std;

int main() {
    int number;

    cout << "Enter a number: ";
    cin >> number;

    cout << "You entered: " << number << endl;
    return 0;
}
```

```{=html}
</details>
```

------------------------------------------------------------------------

## Exercise 3: Read Name and Age

Ask the user to enter: - their name - their age

Print a message like:

Hello Ahmed, you are 20 years old.

```{=html}
<details>
```
```{=html}
<summary>
```
Click to see solution
```{=html}
</summary>
```
``` cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string name;
    int age;

    cout << "Enter your name: ";
    cin >> name;

    cout << "Enter your age: ";
    cin >> age;

    cout << "Hello " << name << ", you are " << age << " years old." << endl;

    return 0;
}
```

```{=html}
</details>
```

------------------------------------------------------------------------

## Exercise 4: Sum of Two Numbers

Ask the user to enter two integers and print their sum.

```{=html}
<details>
```
```{=html}
<summary>
```
Click to see solution
```{=html}
</summary>
```
``` cpp
#include <iostream>
using namespace std;

int main() {
    int a, b;

    cout << "Enter two numbers: ";
    cin >> a >> b;

    cout << "Sum = " << a + b << endl;

    return 0;
}
```

```{=html}
</details>
```

------------------------------------------------------------------------

## Exercise 5: Multiply Two Decimal Numbers

Read two decimal numbers (`double`) and print their product.

```{=html}
<details>
```
```{=html}
<summary>
```
Click to see solution
```{=html}
</summary>
```
``` cpp
#include <iostream>
using namespace std;

int main() {
    double x, y;

    cout << "Enter two decimal numbers: ";
    cin >> x >> y;

    cout << "Product = " << x * y << endl;

    return 0;
}
```

```{=html}
</details>
```

------------------------------------------------------------------------

## Exercise 6: Character Input

Ask the user to enter a single character and print it.

```{=html}
<details>
```
```{=html}
<summary>
```
Click to see solution
```{=html}
</summary>
```
``` cpp
#include <iostream>
using namespace std;

int main() {
    char ch;

    cout << "Enter a character: ";
    cin >> ch;

    cout << "You entered: " << ch << endl;

    return 0;
}
```

```{=html}
</details>
```

------------------------------------------------------------------------

## Exercise 7: Boolean Variable

Create a boolean variable that represents whether a student passed an
exam. Print its value.

```{=html}
<details>
```
```{=html}
<summary>
```
Click to see solution
```{=html}
</summary>
```
``` cpp
#include <iostream>
using namespace std;

int main() {
    bool passed = true;

    cout << "Passed: " << passed << endl;

    return 0;
}
```

```{=html}
</details>
```

------------------------------------------------------------------------

## Exercise 8: Rectangle Area

Ask the user to enter width and height of a rectangle. Print the area.

```{=html}
<details>
```
```{=html}
<summary>
```
Click to see solution
```{=html}
</summary>
```
``` cpp
#include <iostream>
using namespace std;

int main() {
    double width, height;

    cout << "Enter width and height: ";
    cin >> width >> height;

    cout << "Area = " << width * height << endl;

    return 0;
}
```

```{=html}
</details>
```

------------------------------------------------------------------------

## Exercise 9: Swap Two Variables

Read two integers and swap their values. Print them after swapping.

```{=html}
<details>
```
```{=html}
<summary>
```
Click to see solution
```{=html}
</summary>
```
``` cpp
#include <iostream>
using namespace std;

int main() {
    int a, b, temp;

    cout << "Enter two numbers: ";
    cin >> a >> b;

    temp = a;
    a = b;
    b = temp;

    cout << "After swap: " << a << " " << b << endl;

    return 0;
}
```

```{=html}
</details>
```

------------------------------------------------------------------------

## Exercise 10: Average of Three Numbers

Read three numbers and print their average.

```{=html}
<details>
```
```{=html}
<summary>
```
Click to see solution
```{=html}
</summary>
```
``` cpp
#include <iostream>
using namespace std;

int main() {
    double a, b, c;

    cout << "Enter three numbers: ";
    cin >> a >> b >> c;

    cout << "Average = " << (a + b + c) / 3 << endl;

    return 0;
}
```

```{=html}
</details>
```

------------------------------------------------------------------------

## Submission Notes

-   Use correct data types.
-   Always prompt the user before input.
-   Test multiple inputs.
-   Include `return 0;` in `main()`.
