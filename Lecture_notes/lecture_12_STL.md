# C++ Programming — Lecture: STL Containers
## Vector, Array, Map & Set

---

## Table of Contents

1. [Introduction](#introduction)
2. [The Standard Template Library (STL)](#the-standard-template-library-stl)
3. [std::array — Fixed-Size Arrays](#stdarray--fixed-size-arrays)
   - [Declaration & Initialization](#declaration--initialization)
   - [Accessing Elements](#accessing-elements)
   - [Useful Member Functions](#useful-member-functions)
   - [Iterating Over std::array](#iterating-over-stdarray)
4. [std::vector — Dynamic Arrays](#stdvector--dynamic-arrays)
   - [Creating Vectors](#creating-vectors)
   - [Adding & Removing Elements](#adding--removing-elements)
   - [Size vs Capacity](#size-vs-capacity)
   - [Iterating Over Vectors](#iterating-over-vectors)
   - [2D Vectors](#2d-vectors)
5. [std::map — Key-Value Pairs](#stdmap--key-value-pairs)
   - [Creating & Inserting into Maps](#creating--inserting-into-maps)
   - [Accessing & Searching](#accessing--searching)
   - [Iterating Over Maps](#iterating-over-maps)
   - [Ordered vs Unordered Maps](#ordered-vs-unordered-maps)
6. [std::set — Unique Sorted Collections](#stdset--unique-sorted-collections)
   - [Creating & Inserting into Sets](#creating--inserting-into-sets)
   - [Searching in Sets](#searching-in-sets)
   - [Set Operations](#set-operations)
   - [Ordered vs Unordered Sets](#ordered-vs-unordered-sets)
7. [Comparison of Containers](#comparison-of-containers)
8. [Common Mistakes](#common-mistakes)
9. [Practice Exercises](#practice-exercises)
10. [Summary](#summary)

---

## Introduction

The **C++ Standard Template Library (STL)** provides powerful, ready-to-use container classes that store and manage collections of data. Instead of writing your own data structures from scratch, you can use containers like `vector`, `array`, `map`, and `set` to handle common tasks efficiently.

### Why Learn STL Containers?

- They save development time — no need to re-invent dynamic arrays, hash tables, or trees
- They are thoroughly tested and optimized by compiler vendors
- They use **templates**, meaning they work with any data type (`int`, `string`, custom classes, etc.)
- Understanding containers is essential for competitive programming, interviews, and real-world software

### Real-World Analogies

- **`std::array`** — A row of numbered lockers. You know exactly how many there are, and you access each by its number.
- **`std::vector`** — A stretchy backpack. You can keep adding items and it expands automatically.
- **`std::map`** — A phone book. You look up a name (key) and get a phone number (value).
- **`std::set`** — A guest list. Each name appears at most once, and the list stays sorted.

---

## The Standard Template Library (STL)

The STL is a collection of template classes and functions organized into three pillars: **containers** (store data), **iterators** (traverse data), and **algorithms** (process data). In this lecture we focus on four of the most widely used containers.

| Category | Containers Covered |
|---|---|
| Sequence | `std::array`, `std::vector` |
| Associative | `std::map`, `std::set` |

To use any STL container, you include the corresponding header:

```cpp
#include <array>    // std::array
#include <vector>   // std::vector
#include <map>      // std::map
#include <set>      // std::set
```

---

## std::array — Fixed-Size Arrays

`std::array` is a fixed-size container that wraps a plain C-style array while providing STL-compatible member functions. You must know the size at compile time.

### Declaration & Initialization

```cpp
#include <iostream>
#include <array>
using namespace std;

int main() {
    // Method 1: List initialization
    array<int, 5> nums = {10, 20, 30, 40, 50};

    // Method 2: Uniform initialization
    array<string, 3> names {"Alice", "Bob", "Charlie"};

    // Method 3: Default (zero-initialized for numeric types)
    array<double, 4> zeros{};  // {0.0, 0.0, 0.0, 0.0}

    // Method 4: Fill with a single value
    array<int, 5> fives;
    fives.fill(5);  // {5, 5, 5, 5, 5}

    for (int x : nums)  cout << x << " ";
    cout << endl;
    for (const string& n : names)  cout << n << " ";
    cout << endl;
    for (double d : zeros)  cout << d << " ";
    cout << endl;
    for (int x : fives)  cout << x << " ";
    cout << endl;

    return 0;
}
```

**Output:**
```
10 20 30 40 50 
Alice Bob Charlie 
0 0 0 0 
5 5 5 5 
```

### Accessing Elements

```cpp
#include <iostream>
#include <array>
using namespace std;

int main() {
    array<int, 5> nums = {10, 20, 30, 40, 50};

    // 1. operator[] — no bounds checking (fast)
    cout << "nums[2] = " << nums[2] << endl;

    // 2. at() — throws std::out_of_range if invalid
    cout << "nums.at(3) = " << nums.at(3) << endl;

    // 3. front() and back()
    cout << "First: " << nums.front() << endl;
    cout << "Last:  " << nums.back()  << endl;

    // 4. data() — pointer to underlying C-array
    int* ptr = nums.data();
    cout << "Via pointer: " << ptr[1] << endl;

    return 0;
}
```

**Output:**
```
nums[2] = 30
nums.at(3) = 40
First: 10
Last:  50
Via pointer: 20
```

### Useful Member Functions

```cpp
#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

int main() {
    array<int, 5> a = {5, 3, 1, 4, 2};

    cout << "Size:  " << a.size()  << endl;   // 5
    cout << "Empty: " << a.empty() << endl;   // 0 (false)

    // Sorting (uses <algorithm>)
    sort(a.begin(), a.end());
    for (int x : a) cout << x << " ";
    cout << endl;

    // Swap two arrays of the same type and size
    array<int, 5> b = {10, 20, 30, 40, 50};
    a.swap(b);
    cout << "a after swap: ";
    for (int x : a) cout << x << " ";
    cout << endl;

    return 0;
}
```

**Output:**
```
Size:  5
Empty: 0
1 2 3 4 5 
a after swap: 10 20 30 40 50 
```

### Iterating Over std::array

```cpp
#include <iostream>
#include <array>
using namespace std;

int main() {
    array<int, 4> arr = {100, 200, 300, 400};

    // Range-based for loop (preferred)
    cout << "Range-based: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    // Index-based
    cout << "Index-based: ";
    for (size_t i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;

    // Iterator-based
    cout << "Iterator:    ";
    for (auto it = arr.begin(); it != arr.end(); ++it)
        cout << *it << " ";
    cout << endl;

    return 0;
}
```

**Output:**
```
Range-based: 100 200 300 400 
Index-based: 100 200 300 400 
Iterator:    100 200 300 400 
```

---

## std::vector — Dynamic Arrays

`std::vector` is the most widely used STL container. It behaves like an array that **grows and shrinks automatically**. Elements are stored contiguously in memory, giving fast random access.

### Creating Vectors

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Empty vector
    vector<int> v1;

    // Vector with initial values
    vector<int> v2 = {10, 20, 30};

    // Vector of size 5, all elements = 0
    vector<int> v3(5);

    // Vector of size 4, all elements = 7
    vector<int> v4(4, 7);

    // Copy constructor
    vector<int> v5(v2);

    cout << "v2: ";
    for (int x : v2) cout << x << " ";
    cout << "\nv3: ";
    for (int x : v3) cout << x << " ";
    cout << "\nv4: ";
    for (int x : v4) cout << x << " ";
    cout << "\nv5: ";
    for (int x : v5) cout << x << " ";
    cout << endl;

    return 0;
}
```

**Output:**
```
v2: 10 20 30 
v3: 0 0 0 0 0 
v4: 7 7 7 7 
v5: 10 20 30 
```

### Adding & Removing Elements

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {10, 20, 30};

    // push_back — add to end
    v.push_back(40);
    v.push_back(50);

    // pop_back — remove last element
    v.pop_back();

    // insert — add at a specific position
    v.insert(v.begin() + 1, 15);  // insert 15 at index 1

    // erase — remove at a specific position
    v.erase(v.begin() + 3);       // remove element at index 3

    // emplace_back — construct in place (efficient)
    v.emplace_back(99);

    for (int x : v) cout << x << " ";
    cout << endl;

    // clear — remove all elements
    v.clear();
    cout << "After clear, size = " << v.size() << endl;

    return 0;
}
```

**Output:**
```
10 15 20 40 99 
After clear, size = 0
```

### Size vs Capacity

A vector pre-allocates memory. **Size** is how many elements are stored; **capacity** is how many it can hold before reallocating.

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v;

    for (int i = 1; i <= 10; i++) {
        v.push_back(i);
        cout << "size=" << v.size()
             << "  capacity=" << v.capacity() << endl;
    }

    // Reserve space to avoid repeated reallocations
    vector<int> v2;
    v2.reserve(100);
    cout << "\nAfter reserve(100): size=" << v2.size()
         << "  capacity=" << v2.capacity() << endl;

    // Shrink capacity to fit current size
    v2.push_back(1);
    v2.push_back(2);
    v2.shrink_to_fit();
    cout << "After shrink_to_fit: size=" << v2.size()
         << "  capacity=" << v2.capacity() << endl;

    return 0;
}
```

**Output:**
```
size=1  capacity=1
size=2  capacity=2
size=3  capacity=4
size=4  capacity=4
size=5  capacity=8
size=6  capacity=8
size=7  capacity=8
size=8  capacity=8
size=9  capacity=16
size=10  capacity=16

After reserve(100): size=0  capacity=100
After shrink_to_fit: size=2  capacity=2
```

### Iterating Over Vectors

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<string> fruits = {"Apple", "Banana", "Cherry", "Date"};

    // Range-based (preferred)
    cout << "Range-based: ";
    for (const string& f : fruits) cout << f << " ";
    cout << endl;

    // Index-based
    cout << "Index-based: ";
    for (size_t i = 0; i < fruits.size(); i++)
        cout << fruits[i] << " ";
    cout << endl;

    // Reverse iteration
    cout << "Reverse:     ";
    for (auto it = fruits.rbegin(); it != fruits.rend(); ++it)
        cout << *it << " ";
    cout << endl;

    return 0;
}
```

**Output:**
```
Range-based: Apple Banana Cherry Date 
Index-based: Apple Banana Cherry Date 
Reverse:     Date Cherry Banana Apple 
```

### 2D Vectors

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 3x4 matrix initialized to 0
    vector<vector<int>> matrix(3, vector<int>(4, 0));

    // Fill with values
    int value = 1;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 4; j++)
            matrix[i][j] = value++;

    // Print the matrix
    for (const auto& row : matrix) {
        for (int val : row)
            cout << val << "\t";
        cout << endl;
    }

    // Add a new row
    matrix.push_back({13, 14, 15, 16});
    cout << "Rows after push_back: " << matrix.size() << endl;

    return 0;
}
```

**Output:**
```
1	2	3	4	
5	6	7	8	
9	10	11	12	
Rows after push_back: 4
```

---

## std::map — Key-Value Pairs

`std::map` stores elements as **(key, value)** pairs. Keys are unique, and the map keeps them **sorted in ascending order** internally (implemented as a balanced binary search tree).

### Creating & Inserting into Maps

```cpp
#include <iostream>
#include <map>
using namespace std;

int main() {
    // Method 1: Initializer list
    map<string, int> ages = {
        {"Alice", 25},
        {"Bob", 30},
        {"Charlie", 22}
    };

    // Method 2: operator[]
    ages["Diana"] = 28;

    // Method 3: insert() with pair
    ages.insert({"Eve", 35});
    ages.insert(make_pair("Frank", 40));

    // Method 4: emplace
    ages.emplace("Grace", 27);

    for (const auto& [name, age] : ages)
        cout << name << " -> " << age << endl;

    return 0;
}
```

**Output:**
```
Alice -> 25
Bob -> 30
Charlie -> 22
Diana -> 28
Eve -> 35
Frank -> 40
Grace -> 27
```

### Accessing & Searching

```cpp
#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string, int> grades = {
        {"Math", 95},
        {"Physics", 88},
        {"Chemistry", 91}
    };

    // Access with operator[] — creates entry if key doesn't exist!
    cout << "Math: " << grades["Math"] << endl;

    // Access with at() — throws exception if key doesn't exist
    cout << "Physics: " << grades.at("Physics") << endl;

    // Check if key exists with find()
    auto it = grades.find("Biology");
    if (it != grades.end())
        cout << "Biology: " << it->second << endl;
    else
        cout << "Biology not found!" << endl;

    // Check with count() — returns 0 or 1
    if (grades.count("Chemistry"))
        cout << "Chemistry exists!" << endl;

    // contains() — C++20
    // if (grades.contains("Math")) { ... }

    // Erase by key
    grades.erase("Physics");
    cout << "After erase, size = " << grades.size() << endl;

    return 0;
}
```

**Output:**
```
Math: 95
Physics: 88
Biology not found!
Chemistry exists!
After erase, size = 2
```

### Iterating Over Maps

```cpp
#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string, double> prices = {
        {"Apple", 1.50},
        {"Banana", 0.75},
        {"Cherry", 3.00},
        {"Date", 5.25}
    };

    // Structured bindings (C++17, preferred)
    cout << "Structured bindings:" << endl;
    for (const auto& [item, price] : prices)
        cout << "  " << item << " : $" << price << endl;

    // Iterator with pair
    cout << "Iterator:" << endl;
    for (auto it = prices.begin(); it != prices.end(); ++it)
        cout << "  " << it->first << " : $" << it->second << endl;

    return 0;
}
```

**Output:**
```
Structured bindings:
  Apple : $1.5
  Banana : $0.75
  Cherry : $3
  Date : $5.25
Iterator:
  Apple : $1.5
  Banana : $0.75
  Cherry : $3
  Date : $5.25
```

### Ordered vs Unordered Maps

| Feature | `std::map` | `std::unordered_map` |
|---|---|---|
| Header | `<map>` | `<unordered_map>` |
| Order | Sorted by key | No guaranteed order |
| Lookup | O(log n) | O(1) average |
| Internal structure | Balanced BST | Hash table |
| When to use | Need sorted keys | Need fastest lookup |

```cpp
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<string, int> umap = {
        {"Zebra", 1}, {"Apple", 2}, {"Mango", 3}
    };

    for (const auto& [key, val] : umap)
        cout << key << " -> " << val << endl;
    // Output order is NOT guaranteed

    return 0;
}
```

---

## std::set — Unique Sorted Collections

`std::set` stores **unique** elements in **sorted order**. Duplicate insertions are silently ignored. Internally it uses a balanced binary search tree.

### Creating & Inserting into Sets

```cpp
#include <iostream>
#include <set>
using namespace std;

int main() {
    // Initializer list (duplicates removed automatically)
    set<int> nums = {5, 3, 8, 1, 3, 5, 7};

    // insert()
    nums.insert(4);
    nums.insert(3);  // duplicate — ignored

    // emplace()
    nums.emplace(6);

    cout << "Set contents (sorted, unique): ";
    for (int x : nums) cout << x << " ";
    cout << "\nSize: " << nums.size() << endl;

    return 0;
}
```

**Output:**
```
Set contents (sorted, unique): 1 3 4 5 6 7 8 
Size: 7
```

### Searching in Sets

```cpp
#include <iostream>
#include <set>
using namespace std;

int main() {
    set<string> colors = {"Red", "Green", "Blue", "Yellow"};

    // find() — returns iterator
    auto it = colors.find("Green");
    if (it != colors.end())
        cout << "Found: " << *it << endl;
    else
        cout << "Not found!" << endl;

    // count() — 0 or 1
    cout << "Blue exists? " << colors.count("Blue") << endl;
    cout << "Pink exists? " << colors.count("Pink") << endl;

    // erase
    colors.erase("Yellow");
    cout << "After erase: ";
    for (const string& c : colors) cout << c << " ";
    cout << endl;

    return 0;
}
```

**Output:**
```
Found: Green
Blue exists? 1
Pink exists? 0
After erase: Blue Green Red 
```

### Set Operations

You can use STL algorithms for union, intersection, and difference.

```cpp
#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>
using namespace std;

int main() {
    set<int> A = {1, 2, 3, 4, 5};
    set<int> B = {3, 4, 5, 6, 7};

    set<int> result;

    // Union
    set_union(A.begin(), A.end(), B.begin(), B.end(),
              inserter(result, result.begin()));
    cout << "Union:        ";
    for (int x : result) cout << x << " ";
    cout << endl;

    // Intersection
    result.clear();
    set_intersection(A.begin(), A.end(), B.begin(), B.end(),
                     inserter(result, result.begin()));
    cout << "Intersection: ";
    for (int x : result) cout << x << " ";
    cout << endl;

    // Difference (A - B)
    result.clear();
    set_difference(A.begin(), A.end(), B.begin(), B.end(),
                   inserter(result, result.begin()));
    cout << "Difference:   ";
    for (int x : result) cout << x << " ";
    cout << endl;

    return 0;
}
```

**Output:**
```
Union:        1 2 3 4 5 6 7 
Intersection: 3 4 5 
Difference:   1 2 
```

### Ordered vs Unordered Sets

| Feature | `std::set` | `std::unordered_set` |
|---|---|---|
| Header | `<set>` | `<unordered_set>` |
| Order | Sorted | No guaranteed order |
| Lookup | O(log n) | O(1) average |
| Internal structure | Balanced BST | Hash table |
| When to use | Need sorted order | Need fastest lookup |

```cpp
#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    unordered_set<int> us = {50, 10, 30, 20, 40};

    for (int x : us) cout << x << " ";
    cout << endl;
    // Order is NOT guaranteed

    return 0;
}
```

---

## Comparison of Containers

| Feature | `array` | `vector` | `map` | `set` |
|---|---|---|---|---|
| Size | Fixed (compile-time) | Dynamic | Dynamic | Dynamic |
| Duplicates | Allowed | Allowed | Keys unique | All unique |
| Order | Insertion order | Insertion order | Sorted by key | Sorted |
| Random access | O(1) | O(1) | O(log n) | No `[]` |
| Insert at end | N/A | O(1) amortized | O(log n) | O(log n) |
| Search | O(n) | O(n) | O(log n) by key | O(log n) |
| Header | `<array>` | `<vector>` | `<map>` | `<set>` |

### When to Use What?

- **`std::array`** — Size is known at compile time; need a lightweight, stack-allocated container.
- **`std::vector`** — Most general-purpose container; size changes at runtime.
- **`std::map`** — Need to associate keys with values; need sorted keys.
- **`std::set`** — Need a collection of unique items; need fast lookup and sorted order.

---

## Common Mistakes

### Mistake 1: Using `operator[]` on a map for lookup (creates unwanted entries)

**Wrong:**
```cpp
map<string, int> m = {{"Alice", 25}};
// This CREATES a "Bob" entry with value 0!
if (m["Bob"] == 0)
    cout << "Bob not found" << endl;
cout << "Size: " << m.size() << endl;  // 2, not 1!
```

**Correct:**
```cpp
map<string, int> m = {{"Alice", 25}};
if (m.find("Bob") == m.end())
    cout << "Bob not found" << endl;
cout << "Size: " << m.size() << endl;  // 1
```

**Explanation:** `operator[]` on a map inserts a default-constructed value if the key doesn't exist. Use `find()` or `count()` for lookup without side effects.

---

### Mistake 2: Modifying set elements in-place

**Wrong:**
```cpp
set<int> s = {10, 20, 30};
auto it = s.find(20);
*it = 25;  // COMPILATION ERROR! Set elements are const
```

**Correct:**
```cpp
set<int> s = {10, 20, 30};
s.erase(20);
s.insert(25);
// Now s = {10, 25, 30}
```

**Explanation:** Set elements are immutable because modifying them could break the sorted order. You must erase and re-insert.

---

### Mistake 3: Out-of-bounds access on vector without checking

**Wrong:**
```cpp
vector<int> v = {1, 2, 3};
cout << v[10] << endl;  // Undefined behavior — no error thrown!
```

**Correct:**
```cpp
vector<int> v = {1, 2, 3};
if (10 < v.size())
    cout << v[10] << endl;
else
    cout << "Index out of bounds!" << endl;

// Or use at() for automatic bounds checking
try {
    cout << v.at(10) << endl;
} catch (const out_of_range& e) {
    cout << "Exception: " << e.what() << endl;
}
```

**Explanation:** `operator[]` does not check bounds. Use `at()` when you need safety, or always validate the index manually.

---

### Mistake 4: Forgetting that std::array size must be a compile-time constant

**Wrong:**
```cpp
int n;
cin >> n;
array<int, n> arr;  // ERROR: n is not a compile-time constant
```

**Correct:**
```cpp
// Option 1: Use a constant
const int N = 100;
array<int, N> arr;

// Option 2: Use vector for runtime sizes
int n;
cin >> n;
vector<int> v(n);
```

**Explanation:** `std::array` requires the size as a template parameter, which must be known at compile time. Use `std::vector` for runtime-determined sizes.

---

### Mistake 5: Iterating and erasing from a container simultaneously

**Wrong:**
```cpp
vector<int> v = {1, 2, 3, 4, 5};
for (auto it = v.begin(); it != v.end(); ++it) {
    if (*it % 2 == 0)
        v.erase(it);  // Iterator invalidated!
}
```

**Correct:**
```cpp
vector<int> v = {1, 2, 3, 4, 5};
for (auto it = v.begin(); it != v.end(); ) {
    if (*it % 2 == 0)
        it = v.erase(it);  // erase returns next valid iterator
    else
        ++it;
}
// v = {1, 3, 5}
```

**Explanation:** `erase()` invalidates the current iterator. Always capture the return value of `erase()`, which points to the next valid element.

---

## Practice Exercises

### Exercise 1: Word Frequency Counter
Write a program that reads words from the user (until "STOP") and counts how many times each word appears. Print the words and their counts in alphabetical order.

**Expected Output:**
```
Enter words (type STOP to finish):
apple banana apple cherry banana apple STOP
apple -> 3
banana -> 2
cherry -> 1
```

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<string, int> freq;
    string word;

    cout << "Enter words (type STOP to finish):" << endl;
    while (cin >> word && word != "STOP") {
        freq[word]++;
    }

    for (const auto& [w, count] : freq)
        cout << w << " -> " << count << endl;

    return 0;
}
```
</details>

---

### Exercise 2: Remove Duplicates
Given a vector of integers, use a `set` to remove duplicates and print the unique values in sorted order.

**Expected Output:**
```
Original: 5 3 8 3 1 5 7 1 8
Unique:   1 3 5 7 8
```

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    vector<int> v = {5, 3, 8, 3, 1, 5, 7, 1, 8};

    cout << "Original: ";
    for (int x : v) cout << x << " ";
    cout << endl;

    set<int> unique(v.begin(), v.end());

    cout << "Unique:   ";
    for (int x : unique) cout << x << " ";
    cout << endl;

    return 0;
}
```
</details>

---

### Exercise 3: Student Gradebook
Create a `map<string, vector<int>>` to store student names and their list of grades. Add at least 3 students with 4 grades each. Calculate and display the average grade for each student.

**Expected Output:**
```
Alice: 85 90 78 92 -> Average = 86.25
Bob: 70 65 80 75 -> Average = 72.5
Charlie: 95 88 91 97 -> Average = 92.75
```

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

int main() {
    map<string, vector<int>> gradebook = {
        {"Alice", {85, 90, 78, 92}},
        {"Bob", {70, 65, 80, 75}},
        {"Charlie", {95, 88, 91, 97}}
    };

    for (const auto& [name, grades] : gradebook) {
        double sum = 0;
        cout << name << ": ";
        for (int g : grades) {
            cout << g << " ";
            sum += g;
        }
        cout << "-> Average = " << sum / grades.size() << endl;
    }

    return 0;
}
```
</details>

---

### Exercise 4: Array Rotation
Write a function that rotates a `std::array<int, 6>` to the left by `k` positions. Use a temporary vector to help.

**Expected Output:**
```
Original: 1 2 3 4 5 6
Rotated by 2: 3 4 5 6 1 2
```

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

int main() {
    array<int, 6> arr = {1, 2, 3, 4, 5, 6};
    int k = 2;

    cout << "Original: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    // Use std::rotate
    rotate(arr.begin(), arr.begin() + k, arr.end());

    cout << "Rotated by " << k << ": ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
```
</details>

---

### Exercise 5: Set Operations — Common Friends
Two users each have a set of friends. Find their common friends (intersection), all friends combined (union), and friends unique to user A (difference).

**Expected Output:**
```
Alice's friends: Bob Charlie Diana Eve
Frank's friends: Charlie Eve Grace Henry
Common friends: Charlie Eve
All friends: Bob Charlie Diana Eve Grace Henry
Only Alice's: Bob Diana
```

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>
using namespace std;

int main() {
    set<string> alice = {"Bob", "Charlie", "Diana", "Eve"};
    set<string> frank = {"Charlie", "Eve", "Grace", "Henry"};

    cout << "Alice's friends: ";
    for (const auto& f : alice) cout << f << " ";
    cout << "\nFrank's friends: ";
    for (const auto& f : frank) cout << f << " ";

    set<string> common, all, only_alice;

    set_intersection(alice.begin(), alice.end(),
                     frank.begin(), frank.end(),
                     inserter(common, common.begin()));

    set_union(alice.begin(), alice.end(),
              frank.begin(), frank.end(),
              inserter(all, all.begin()));

    set_difference(alice.begin(), alice.end(),
                   frank.begin(), frank.end(),
                   inserter(only_alice, only_alice.begin()));

    cout << "\nCommon friends: ";
    for (const auto& f : common) cout << f << " ";
    cout << "\nAll friends: ";
    for (const auto& f : all) cout << f << " ";
    cout << "\nOnly Alice's: ";
    for (const auto& f : only_alice) cout << f << " ";
    cout << endl;

    return 0;
}
```
</details>

---

## Summary

### Key Concepts

- **`std::array`** — Fixed-size, stack-allocated, compile-time size, wraps C-style arrays
- **`std::vector`** — Dynamic size, heap-allocated, most commonly used container
- **`std::map`** — Sorted key-value pairs, O(log n) operations, unique keys
- **`std::set`** — Sorted unique elements, O(log n) operations, no duplicates
- All containers support **iterators**, **range-based for loops**, and standard algorithms

### Important Points

1. Always include the correct header for each container (`<vector>`, `<map>`, `<set>`, `<array>`)
2. Use `vector` as your default container unless you have a specific reason not to
3. Never use `map::operator[]` for checking existence — use `find()` or `count()`
4. Set elements are immutable — erase and re-insert to "modify"
5. `std::array` size must be a compile-time constant; use `vector` for runtime sizes
6. Prefer `at()` over `[]` when bounds safety is important
7. When erasing during iteration, always capture the iterator returned by `erase()`
8. Use `unordered_map`/`unordered_set` when you don't need sorted order and want O(1) average lookup

### Quick Reference

```cpp
// --- array ---
array<int, 5> a = {1,2,3,4,5};
a[0];  a.at(0);  a.size();  a.fill(0);

// --- vector ---
vector<int> v = {1,2,3};
v.push_back(4);  v.pop_back();  v.size();  v.clear();
v.insert(v.begin()+1, 99);  v.erase(v.begin());

// --- map ---
map<string,int> m;
m["key"] = 42;  m.at("key");  m.find("key");
m.erase("key");  m.count("key");  m.size();

// --- set ---
set<int> s = {3,1,2};
s.insert(4);  s.erase(2);  s.find(3);  s.count(1);
```

### Next Steps

In the next lecture, we will explore **STL Algorithms and Iterators** in depth — learning how to use powerful functions like `sort`, `find`, `transform`, `accumulate`, and more across all container types.
