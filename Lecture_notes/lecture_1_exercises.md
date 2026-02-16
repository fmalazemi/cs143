# CS 143 --- Lecture 1 Exercises: Introduction to C++

Practice writing simple C++ programs, compiling, and printing output.

------------------------------------------------------------------------

## Exercise 1: Your First Program

Write a C++ program that prints:

Welcome to C++ Programming!

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
    cout << "Welcome to C++ Programming!" << endl;
    return 0;
}
```

```{=html}
</details>
```

------------------------------------------------------------------------

## Exercise 2: Print Personal Information

Write a program that prints:

-   Your name\
-   Your major\
-   Your favorite programming language

Each item should appear on a new line.

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
    cout << "Name: Ahmed" << endl;
    cout << "Major: Computer Science" << endl;
    cout << "Favorite Language: C++" << endl;
    return 0;
}
```

```{=html}
</details>
```

------------------------------------------------------------------------

## Exercise 3: Multiple Output Lines

Write a program that prints the following pattern:

Hello\
World\
C++ is fun!

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
    cout << "Hello" << endl;
    cout << "World" << endl;
    cout << "C++ is fun!" << endl;
    return 0;
}
```

```{=html}
</details>
```

------------------------------------------------------------------------

## Exercise 4: Printing in One Line

Write a program that prints:

My age is 20

Use multiple items with the output operator `<<`.

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
    cout << "My age is " << 20 << endl;
    return 0;
}
```

```{=html}
</details>
```

------------------------------------------------------------------------

## Exercise 5: Using New Line Character

Write a program that prints three sentences using the newline character
`\n` instead of `endl`.

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
    cout << "Line one\n";
    cout << "Line two\n";
    cout << "Line three\n";
    return 0;
}
```

```{=html}
</details>
```

------------------------------------------------------------------------

## Exercise 6: Simple Pattern

Write a program that prints the following pattern:

-   ** *** *\*\*\*

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
    cout << "*" << endl;
    cout << "**" << endl;
    cout << "***" << endl;
    cout << "****" << endl;
    return 0;
}
```

```{=html}
</details>
```

------------------------------------------------------------------------

## Exercise 7: Compile and Run

Create a file named:

hello.cpp

Compile it using:

g++ hello.cpp -o hello

Then run:

./hello

Explain what each command does.

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
Explanation:

-   g++ hello.cpp → compiles the source code
-   -o hello → creates executable named hello
-   ./hello → runs the program

```{=html}
</details>
```

------------------------------------------------------------------------

## Exercise 8: Fix the Errors

The following program contains errors. Fix them.

``` cpp
include <iostream>

int main() 
{
cout << Hello World
return 0
}
```

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
    cout << "Hello World";
    return 0;
}
```

```{=html}
</details>
```

------------------------------------------------------------------------
