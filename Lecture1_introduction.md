# Lecture 1: Introduction to C++ - Hello World 👋

## Welcome to C++!

You've already learned programming with Python from CS101. Now we're going to learn C++, which is like Python's high-performance cousin.

**Where C++ is used?** 
- 🎮 Video games (Unreal Engine, Unity)
- 🚗 Self-driving cars
- 🚀 Rocket software (SpaceX)
- 💰 High-frequency trading
- 🖥️ Operating systems

**The Big Difference:** Python runs line by line (interpreted), but C++ needs to be compiled first. This makes C++ **10-100x faster!**

---

## Python vs C++: Quick Comparison

| Feature | Python | C++ |
|---------|--------|-----|
| **Execution** | Interpreted (runs line by line) | Compiled (faster!) |
| **Speed** | Slower | 10-100x faster |
| **Typing** | Dynamic (types can change) | Static (types fixed) |
| **Learning Curve** | Easy | More challenging |

**Don't worry!** All your programming logic (loops, if statements) transfers over. You just need to learn new syntax.

---

## Your First C++ Program! 👋

### Python Version (What You Know)
```python
print("Hello, World!")
```

One line, super simple!

### C++ Version (New!)
```cpp
#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
```

Okay, that's more lines... but don't panic! Let's break it down.

---

## Understanding Each Line

```cpp
#include <iostream>
```
**What it does:** Brings in the input/output library  
**Like Python's:** `import` statement  
**Why we need it:** To use `cout` (output) and `cin` (input)

---

```cpp
int main() {
```
**What it does:** This is where your program starts  
**Why `int`:** The function returns a number (0 = success!)  
**The `{`:** Opens the code block

---

```cpp
    std::cout << "Hello, World!" << std::endl;
```
**What it does:** Prints to the screen  
**Like Python's:** `print("Hello, World!")`

**Breaking it down:**
- `std::cout` = **c**onsole **out**put
- `<<` = "send this to cout" (output operator)
- `"Hello, World!"` = the text to print
- `std::endl` = **end line** (adds newline, like pressing Enter)
- `;` = **every statement ends with semicolon!**

---

```cpp
    return 0;
```
**What it does:** Tells the computer "we finished successfully!"  
**The `0`:** Means "no errors"

---

```cpp
}
```
**What it does:** Closes the `main()` function  
**Remember:** Every `{` needs a matching `}`

---

## The `std::` Prefix

You might be wondering: "Why do we need to write `std::` before `cout` and `endl`?"

**Answer:** They're part of the **standard library** namespace. The `std::` tells C++ where to find these functions.

### Making It Shorter with `using namespace std`

You can add this line after `#include` to avoid typing `std::` every time:

```cpp
#include <iostream>
using namespace std;  // Now we don't need std::

int main() {
    cout << "Hello, World!" << endl;  // No std:: needed!
    return 0;
}
```

**When to use it:**
- ✅ Small programs and learning
- ✅ Quick examples and homework
- ❌ Large professional projects (can cause naming conflicts)

**For this course:** We'll use `using namespace std;` to keep examples cleaner and easier to read!

---

## Let's Write More Programs!

### Printing Multiple Lines

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Hello" << endl;
    cout << "World" << endl;
    cout << "I love C++!" << endl;
    return 0;
}
```

### Printing Multiple Things in One Line

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "My age is " << 25 << endl;
    return 0;
}
```

**Cool trick:** Chain multiple items with `<<`!

```cpp
cout << "I am " << 25 << " years old and I love " << "C++" << endl;
```

### Quick Tip: `\n` vs `endl`

Both add a new line:

```cpp
cout << "Hello\n";        // Faster (just adds newline)
cout << "Hello" << endl;  // Also flushes the output buffer
```

For most cases, either works fine!

---

## How to Compile and Run 🏃

### Python (One Step)
```bash
python hello.py
```

### C++ (Two Steps)
```bash
# Step 1: Compile
g++ hello.cpp -o hello

# Step 2: Run
./hello
```

**Why two steps?**
1. ✅ Catches errors BEFORE running
2. ✅ Creates super fast machine code
3. ✅ Compile once, run many times

---

## Practice Exercise 💪

**Your Task:** Create a program that prints:
```
Welcome to C++!
My name is [Your Name]
I'm excited to learn programming!
```

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Welcome to C++!" << endl;
    cout << "My name is Alice" << endl;
    cout << "I'm excited to learn programming!" << endl;
    return 0;
}
```
</details>

---

## Common Mistakes 🚫

### Mistake 1: Forgetting Semicolons
```cpp
cout << "Hello"  // ❌ ERROR: missing semicolon
cout << "Hello"; // ✅ Correct
```

### Mistake 2: Forgetting to Include iostream
```cpp
int main() {
    cout << "Hi";  // ❌ ERROR: iostream not included
}
```

**Fix:**
```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Hi";  // ✅ Works!
}
```

### Mistake 3: Wrong Quotes
```cpp
cout << 'Hello';   // ❌ Single quotes for strings
cout << "Hello";   // ✅ Double quotes for strings
```

---

## Summary ✅

Today you learned:
- ✓ The structure of a C++ program
- ✓ How to write "Hello, World!"
- ✓ What `#include`, `main()`, and `cout` do
- ✓ Using `using namespace std;` to simplify code
- ✓ How to compile and run C++ programs
- ✓ Common mistakes to avoid

---

## Homework 📚

**Assignment 1:** Create a program that prints your:
- Name
- Favorite color
- Favorite food

**Assignment 2:** Create a program that prints a simple pattern:
```
*
**
***
****
*****
```

**Assignment 3:** Create a program that prints:
```
C++ is:
  - Fast
  - Powerful
  - Fun!
```
