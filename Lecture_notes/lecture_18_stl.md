# CS143 — Lecture 16: The Standard Template Library (STL)

> **Course:** CS143 Introduction to C++ · **Instructor:** Dr. Fawaz Alazemi
> **Builds on:** Lecture 6 (arrays) and Lecture 15 (structs).

---

## Table of Contents

1. [Introduction](#1-introduction)
2. [vector: A Resizable Array](#2-vector-a-resizable-array)
3. [array: A Fixed-Size Array](#3-array-a-fixed-size-array)
4. [set: Unique, Sorted Values](#4-set-unique-sorted-values)
5. [map: Key to Value](#5-map-key-to-value)
6. [Choosing a Container](#6-choosing-a-container)
7. [Algorithms Work on a Range](#7-algorithms-work-on-a-range)
8. [sort](#8-sort)
9. [reverse](#9-reverse)
10. [find](#10-find)
11. [Common Mistakes](#11-common-mistakes)
12. [Practice Exercises](#12-practice-exercises)
13. [Summary](#13-summary)

---

## 1. Introduction

The **Standard Template Library (STL)** is part of standard C++. It gives you ready-made tools so you do not have to build them yourself. It has two parts we will study today:

- **Containers** — ready-made ways to store collections of data (a resizable array, a set, a dictionary, and so on).
- **Algorithms** — ready-made operations that work on those collections (sorting, reversing, searching).

Each tool needs its own `#include`. We cover the containers first (Part A), then the algorithms (Part B).

```
  vector — resizable          array — fixed size (5)
  [10][20][30][＋]            [1][2][3][4][5]

  set — unique & sorted       map — key -> value
  { 1, 3, 7 }                 "Sara" -> 20 , "Ali" -> 22
```

---

## 2. vector: A Resizable Array

A **vector** is an array that can grow. It is the most useful STL container. It needs `#include <vector>`.

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v;       // empty, can grow
    v.push_back(10);     // add to the end
    v.push_back(20);
    v.push_back(30);

    cout << v[0] << endl;       // 10
    cout << v.size() << endl;   // 3
    for (int x : v) cout << x << " ";  // 10 20 30
    return 0;
}
```

**Output:**
```
10
3
10 20 30 
```

- `push_back` adds an item to the end.
- `v[i]` reads an item; `v.size()` gives the count.
- Unlike a plain array, a vector grows as needed.

*Coming from Python? A vector is like a list.*

---

## 3. array: A Fixed-Size Array

A **std::array** is a fixed-size array that knows its own length. It needs `#include <array>`.

```cpp
#include <iostream>
#include <array>
using namespace std;

int main() {
    array<int, 5> a = {1, 2, 3, 4, 5};

    cout << a[2] << endl;      // 3
    cout << a.size() << endl;  // 5
    return 0;
}
```

**Output:**
```
3
5
```

- `array<int, 5>` holds exactly 5 ints — a fixed size set at compile time.
- It knows its length with `a.size()`.
- It is safer and tidier than a plain C-style array.

Use `array` when the size never changes; use `vector` when it might grow.

---

## 4. set: Unique, Sorted Values

A **set** keeps only unique values, always in sorted order. It needs `#include <set>`.

```cpp
#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> s;
    s.insert(3);
    s.insert(1);
    s.insert(3);   // duplicate is ignored

    for (int x : s) cout << x << " ";  // 1 3
    cout << endl;
    cout << s.count(2);  // 0  (not present)
    return 0;
}
```

**Output:**
```
1 3 
0
```

- A set stores unique values, kept sorted.
- `insert` adds a value; a repeat is silently ignored.
- `count(x)` is 1 if present, 0 if not.

*Coming from Python? A set is like a set.*

---

## 5. map: Key to Value

A **map** stores key → value pairs, looked up by key. It needs `#include <map>`.

```cpp
#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string, int> age;
    age["Sara"] = 20;     // key -> value
    age["Ali"]  = 22;

    cout << age["Sara"] << endl;   // 20

    for (auto p : age)             // each pair
        cout << p.first << ": " << p.second << endl;
    return 0;
}
```

**Output:**
```
20
Ali: 22
Sara: 20
```

- A map holds key → value pairs.
- `p.first` is the key, `p.second` is the value.
- Keys are unique and kept in sorted order (which is why "Ali" prints before "Sara").

*Coming from Python? A map is like a dict.*

---

## 6. Choosing a Container

| Container | Holds | Use when… |
|-----------|-------|-----------|
| `vector` | an ordered list that can grow | you add or remove items over time |
| `array` | a fixed number of items | the size is known and never changes |
| `set` | unique values, sorted | you need no duplicates |
| `map` | key → value pairs | you look things up by a key |

Rough Python guide: `vector` ≈ list, `set` ≈ set, `map` ≈ dict.

---

## 7. Algorithms Work on a Range

STL **algorithms** live in `#include <algorithm>`. They act on a **range**, given by two markers:

- `begin()` — the first item.
- `end()` — just past the last item.

```
  begin()              end()
    v                    v
  [ 3 ][ 1 ][ 2 ]   --sort-->   [ 1 ][ 2 ][ 3 ]
```

So nearly every algorithm call looks like `algorithm(v.begin(), v.end(), ...)`. The same pattern works for vectors and arrays.

---

## 8. sort

`sort` puts the items of a range in increasing order, changing the container in place.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v = {3, 1, 2};

    sort(v.begin(), v.end());   // ascending

    for (int x : v) cout << x << " ";  // 1 2 3
    return 0;
}
```

**Output:**
```
1 2 3 
```

For largest-first order, pass an extra argument: `sort(v.begin(), v.end(), greater<int>())`.

---

## 9. reverse

`reverse` turns a range back to front, also in place.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3};

    reverse(v.begin(), v.end());

    for (int x : v) cout << x << " ";  // 3 2 1
    return 0;
}
```

**Output:**
```
3 2 1 
```

The first item becomes the last, and so on.

---

## 10. find

`find` searches a range for a value. It returns a marker (an **iterator**) to the item — or `end()` if the value is not present.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v = {10, 20, 30};

    auto it = find(v.begin(), v.end(), 20);

    if (it != v.end())
        cout << "found";
    else
        cout << "not found";
    return 0;
}
```

**Output:**
```
found
```

- `find` returns an iterator, **not** an index.
- If the value is missing, it returns `end()`.
- So compare the result with `end()` to test "found or not".

*(`auto` lets the compiler work out the type for you — handy for iterators.)*

These pieces fit together. Here we sort a vector and then search it:

```cpp
vector<int> v = {40, 10, 30, 20};
sort(v.begin(), v.end());               // 10 20 30 40
auto it = find(v.begin(), v.end(), 30);
cout << (it != v.end() ? "30 is here" : "no 30");
```

**Output:**
```
30 is here
```

---

## 11. Common Mistakes

**1. Forgetting the include**

**Wrong:**
```cpp
vector<int> v;   // ERROR if <vector> was not included
```

**Correct:**
```cpp
#include <vector>
vector<int> v;
```

**Explanation:** each tool needs its header — `<vector>`, `<set>`, `<map>`, `<algorithm>`, and so on.

**2. Forgetting begin and end**

**Wrong:**
```cpp
sort(v);                    // ERROR
```

**Correct:**
```cpp
sort(v.begin(), v.end());   // algorithms take a range
```

**Explanation:** algorithms work on a range written as `v.begin(), v.end()`.

**3. Expecting find to return an index**

**Wrong:**
```cpp
int pos = find(v.begin(), v.end(), 7);   // not a number
```

**Correct:**
```cpp
auto it = find(v.begin(), v.end(), 7);
if (it != v.end()) { /* found */ }
```

**Explanation:** `find` returns an iterator. Compare it with `end()` to know if the value was found.

**4. Using push_back on an array**

**Wrong:**
```cpp
array<int, 3> a = {1, 2, 3};
a.push_back(4);   // ERROR: array has a fixed size
```

**Correct:**
```cpp
vector<int> v = {1, 2, 3};
v.push_back(4);   // only vector grows
```

**Explanation:** `array` is fixed in size; use a `vector` when it must grow.

**5. Expecting duplicates in a set**

**Wrong:**
```cpp
set<int> s;
s.insert(4);
s.insert(4);      // the second 4 is ignored, not added twice
```

**Correct:**
```cpp
// A set keeps only unique values. If you need duplicates,
// use a vector instead.
vector<int> v = {4, 4};
```

**Explanation:** a set silently ignores repeats. Use a vector if duplicates matter.

---

## 12. Practice Exercises

Try each one before opening the solution. Exercises 1–3 use containers; 4–6 use algorithms.

**Exercise 1.** Make a `vector<int>`, add the numbers 5, 8, and 2 with `push_back`, then print them and the size.

<details>
<summary>Click to see solution</summary>

```cpp
vector<int> v;
v.push_back(5);
v.push_back(8);
v.push_back(2);
for (int x : v) cout << x << " ";  // 5 8 2
cout << endl << v.size();          // 3
```
</details>

**Exercise 2.** Make a `set<int>`, insert 4, 4, 1, and 7, then print it. What happens to the repeat?

<details>
<summary>Click to see solution</summary>

```cpp
set<int> s;
s.insert(4); s.insert(4);
s.insert(1); s.insert(7);
for (int x : s) cout << x << " ";  // 1 4 7
// the repeated 4 is ignored; values come out sorted
```
</details>

**Exercise 3.** Make a `map<string, int>` of three fruit prices, then print the price of one fruit.

<details>
<summary>Click to see solution</summary>

```cpp
map<string, int> price;
price["apple"]  = 3;
price["banana"] = 2;
price["cherry"] = 5;

cout << price["banana"];   // 2
```
</details>

**Exercise 4.** Put `{9, 3, 7, 1}` in a vector and `sort` it into increasing order; print the result.

<details>
<summary>Click to see solution</summary>

```cpp
vector<int> v = {9, 3, 7, 1};
sort(v.begin(), v.end());
for (int x : v) cout << x << " ";  // 1 3 7 9
```
</details>

**Exercise 5.** `reverse` the vector from Exercise 4 and print it.

<details>
<summary>Click to see solution</summary>

```cpp
reverse(v.begin(), v.end());
for (int x : v) cout << x << " ";  // 9 7 3 1
```
</details>

**Exercise 6.** Use `find` to check whether the value 7 is in the vector, and print "yes" or "no".

<details>
<summary>Click to see solution</summary>

```cpp
auto it = find(v.begin(), v.end(), 7);
if (it != v.end())
    cout << "yes";
else
    cout << "no";
// yes
```
</details>

---

## 13. Summary

### Key Concepts

- The **STL** provides ready-made **containers** and **algorithms** in standard C++.
- Containers store collections; algorithms operate on them.
- Each tool needs its own `#include`.

### Important Points

1. `vector` is a resizable array; `array` is a fixed-size array.
2. `set` holds unique, sorted values; `map` holds key → value pairs.
3. Algorithms in `<algorithm>` work on the range `begin()` … `end()`.
4. `sort` orders items, `reverse` flips them, `find` searches for a value.
5. `find` returns an iterator, and `end()` when the value is not present.

### Quick Reference

```cpp
#include <vector>
#include <set>
#include <map>
#include <algorithm>

vector<int> v = {3, 1, 2};
v.push_back(4);                 // grow
sort(v.begin(), v.end());       // 1 2 3 4
reverse(v.begin(), v.end());    // 4 3 2 1
auto it = find(v.begin(), v.end(), 3);   // it != v.end() if found

set<int> s = {1, 2, 2};         // {1, 2}
map<string,int> m;  m["a"] = 1; // key -> value
```

### Next Steps

The STL has many more containers (such as `stack` and `queue`) and many more algorithms. The patterns are the same: pick a container for your data, then call algorithms on its `begin()` … `end()` range.
