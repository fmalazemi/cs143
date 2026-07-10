# CS143 — Basic Sorting Algorithms

> **Course:** CS143 Introduction to C++ · **Instructor:** Dr. Fawaz Alazemi
> **Builds on:** arrays, loops, and nested loops.

---

## Table of Contents

1. [What Is Sorting](#1-what-is-sorting)
2. [Bubble Sort](#2-bubble-sort)
3. [Selection Sort](#3-selection-sort)
4. [Insertion Sort](#4-insertion-sort)
5. [Comparing the Three](#5-comparing-the-three)
6. [Common Mistakes](#6-common-mistakes)
7. [Practice Exercises](#7-practice-exercises)
8. [Summary](#8-summary)

---

## 1. What Is Sorting

**Sorting** means rearranging the items of an array so they are in order — usually smallest to largest.

```
Before:   5   1   4   2
After:    1   2   4   5
```

All three algorithms in this lecture use the same two tools you already know: **comparing** two values, and **swapping** them. Swapping needs a temporary variable, or one of the values is lost:

```cpp
int temp = arr[i];
arr[i] = arr[j];
arr[j] = temp;
```

Each algorithm is a different strategy for deciding *what* to compare and *when* to swap. Learn the one-sentence idea behind each before you read its code.

---

## 2. Bubble Sort

**The idea:** walk along the array, compare each item with its neighbour, and swap them if they are out of order. Repeat.

It is called *bubble* sort because after each pass, the largest remaining value has moved — bubbled — all the way to the right end, where it stays.

### Trace: one pass over `5 1 4 2`

```
start:        [5] [1]  4   2      5 > 1  ->  swap
then:          1  [5] [4]  2      5 > 4  ->  swap
then:          1   4  [5] [2]     5 > 2  ->  swap
after pass 1:  1   4   2  (5)     largest is in place
```

After pass 1 the last item is correct; after pass 2 the last two are correct, and so on.

### The code

```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[4] = {5, 1, 4, 2};
    int n = 4;

    // each pass fixes one more value at the end
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {   // out of order?
                int temp = arr[j];       // swap them
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}
```

**Output:**
```
1 2 4 5
```

The inner loop compares neighbours and swaps. The `- i` in `n - 1 - i` skips the values already parked at the end. Two nested loops means about n × n comparisons.

---

## 3. Selection Sort

**The idea:** look through the unsorted part, find the **smallest** value, and swap it into the first unsorted position.

The difference from bubble sort: bubble swaps many times per pass, while selection searches first and then makes **one** swap per pass. The array grows sorted from the **left**.

### Trace on `5 1 4 2`

```
start:    5  [1]  4   2       min = 1  ->  swap with position 0
pass 2:  (1)  5   4  [2]      min = 2  ->  swap with position 1
pass 3:  (1) (2)  4  [5]      min = 4  ->  already in place
done:    (1) (2) (4) (5)      sorted
```

The values in parentheses are finished; the sorted region grows from the left.

### The code

```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[4] = {5, 1, 4, 2};
    int n = 4;

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;              // assume i is smallest

        // search the rest for something smaller
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {           // one swap per pass
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }

    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}
```

**Output:**
```
1 2 4 5
```

The inner loop **finds** the smallest value's position; the swap happens once, after the search. Note that we track `minIndex`, not the minimum value — we need the position in order to swap.

---

## 4. Insertion Sort

**The idea:** treat the left part of the array as already sorted. Take the next value (the **key**), slide larger values one step right to open a gap, and drop the key into the gap.

This is exactly how most people sort playing cards in their hand: pick up the next card and push it back until it sits in the right spot. Insertion sort **shifts** values rather than swapping pairs.

### Trace on `5 1 4 2`

```
start:   (5) [1]  4   2       key = 1  ->  goes before 5
then:    (1) (5) [4]  2       key = 4  ->  goes before 5
then:    (1) (4) (5) [2]      key = 2  ->  goes after 1
done:    (1) (2) (4) (5)      sorted
```

Parentheses mark the sorted part; brackets mark the key being inserted.

### The code

```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[4] = {5, 1, 4, 2};
    int n = 4;

    for (int i = 1; i < n; i++) {
        int key = arr[i];       // the value to place
        int j = i - 1;

        // slide bigger values one step right
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;       // drop it in the gap
    }

    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}
```

**Output:**
```
1 2 4 5
```

The `while` loop shifts larger values right until it finds the gap, then places `key`. The outer loop starts at `i = 1` because a single item on its own is already sorted.

---

## 5. Comparing the Three

| Algorithm | Core idea | Swaps | Best case | Worst case |
|-----------|-----------|-------|-----------|------------|
| Bubble | swap neighbours | many | n | n × n |
| Selection | find the smallest | one per pass | n × n | n × n |
| Insertion | insert into sorted part | shifts | n | n × n |

- All three are **slow** for large arrays — roughly n × n work.
- **Insertion sort** is the fastest of the three on data that is already nearly sorted, because its `while` loop stops immediately on each item.
- **Selection sort** makes the fewest swaps, which helps when swapping is expensive.
- **Selection sort** has no best case: it always searches the whole remaining array.

For real work, do not write your own — use the STL:

```cpp
#include <algorithm>
sort(v.begin(), v.end());
```

These three are worth learning by hand because they teach how loops, comparisons, and swaps work together.

---

## 6. Common Mistakes

**1. Reading past the end of the array**

**Wrong:**
```cpp
for (int j = 0; j < n; j++)
    if (arr[j] > arr[j + 1])   // arr[n] does not exist
```

**Correct:**
```cpp
for (int j = 0; j < n - 1 - i; j++)
    if (arr[j] > arr[j + 1])
```

**Explanation:** bubble sort looks at `arr[j+1]`, so `j` must stop one position early.

**2. Losing a value during a swap**

**Wrong:**
```cpp
arr[i] = arr[j];
arr[j] = arr[i];    // arr[i] was already overwritten
```

**Correct:**
```cpp
int temp = arr[i];
arr[i] = arr[j];
arr[j] = temp;
```

**Explanation:** without `temp`, the first assignment destroys the value you still need.

**3. Starting insertion sort at `i = 0`**

**Wrong:**
```cpp
for (int i = 0; i < n; i++) { int key = arr[i]; ... }
```

**Correct:**
```cpp
for (int i = 1; i < n; i++) { int key = arr[i]; ... }
```

**Explanation:** the first item alone is already a sorted list of one, so insertion begins at the second.

**4. Swapping inside the search in selection sort**

**Wrong:**
```cpp
for (int j = i + 1; j < n; j++)
    if (arr[j] < arr[i]) { /* swap here */ }   // many swaps
```

**Correct:**
```cpp
for (int j = i + 1; j < n; j++)
    if (arr[j] < arr[minIndex]) minIndex = j;  // just remember
// swap once, after the loop
```

**Explanation:** selection sort's advantage is making exactly one swap per pass.

**5. Forgetting `j >= 0` in insertion sort**

**Wrong:**
```cpp
while (arr[j] > key) { ... j--; }     // runs past the left end
```

**Correct:**
```cpp
while (j >= 0 && arr[j] > key) { ... j--; }
```

**Explanation:** the guard must come first, or the program reads `arr[-1]`.

**6. Tracking the value instead of the index**

**Wrong:**
```cpp
int minValue = arr[i];
// ...later: how do we know where minValue is?
```

**Correct:**
```cpp
int minIndex = i;
```

**Explanation:** a swap needs a **position**, so remember the index.

**Advice:** trace each algorithm on paper with four numbers before you trust your code.

---

## 7. Practice Exercises

Try each one before opening the solution.

**Exercise 1.** Trace **bubble sort** by hand on `{3, 2, 1}`. Write the array after each pass.

<details>
<summary>Click to see solution</summary>

```
start:   3 2 1
pass 1:  2 1 3
pass 2:  1 2 3
```

Pass 1 swaps (3,2) then (3,1), pushing 3 to the end.
</details>

**Exercise 2.** Write the C++ swap of `arr[i]` and `arr[j]` using a `temp` variable.

<details>
<summary>Click to see solution</summary>

```cpp
int temp = arr[i];
arr[i] = arr[j];
arr[j] = temp;
```
</details>

**Exercise 3.** In **selection sort**, why do we store `minIndex` rather than the smallest value itself?

<details>
<summary>Click to see solution</summary>

Because we must **swap positions**. Knowing the value alone does not tell us where it is, so we remember its **index**.
</details>

**Exercise 4.** Trace **insertion sort** on `{4, 3, 5}`. What is the key at each step?

<details>
<summary>Click to see solution</summary>

```
key = 3:  3 4 5     (3 slides before 4)
key = 5:  3 4 5     (5 is already larger, so it stays)
```
</details>

**Exercise 5.** Write a complete **selection sort** for an array of 5 integers and print the result.

<details>
<summary>Click to see solution</summary>

```cpp
int arr[5] = {9, 3, 7, 1, 5};
int n = 5;
for (int i = 0; i < n - 1; i++) {
    int minIndex = i;
    for (int j = i + 1; j < n; j++)
        if (arr[j] < arr[minIndex]) minIndex = j;
    int temp = arr[i];
    arr[i] = arr[minIndex];
    arr[minIndex] = temp;
}
for (int i = 0; i < n; i++) cout << arr[i] << " ";
// prints: 1 3 5 7 9
```
</details>

**Exercise 6.** Which algorithm is fastest on an array that is **already sorted**? Explain in one sentence.

<details>
<summary>Click to see solution</summary>

**Insertion sort.** Its `while` loop stops immediately on every item, so it makes just one pass over the array.
</details>

---

## 8. Summary

### Key Concepts

- **Sorting** rearranges an array into order, using only comparisons and swaps.
- **Bubble sort:** swap neighbours; the largest value bubbles to the right each pass.
- **Selection sort:** find the smallest remaining value; one swap per pass.
- **Insertion sort:** slide each new value back into the sorted left part.

### Important Points

1. All three use **nested loops** and take about **n × n** steps.
2. Bubble sort's inner loop must stop at `n - 1 - i` to avoid reading past the end.
3. Selection sort remembers `minIndex`, and swaps once after the search.
4. Insertion sort starts at `i = 1` and guards its `while` loop with `j >= 0`.
5. Insertion sort wins on nearly-sorted data; selection sort makes the fewest swaps.
6. For real work, use `sort(v.begin(), v.end())` from `<algorithm>`.

### Quick Reference

```cpp
// bubble: swap neighbours
for (int i = 0; i < n - 1; i++)
    for (int j = 0; j < n - 1 - i; j++)
        if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);

// selection: find the smallest, swap once
for (int i = 0; i < n - 1; i++) {
    int minIndex = i;
    for (int j = i + 1; j < n; j++)
        if (arr[j] < arr[minIndex]) minIndex = j;
    swap(arr[i], arr[minIndex]);
}

// insertion: slide the key into place
for (int i = 1; i < n; i++) {
    int key = arr[i], j = i - 1;
    while (j >= 0 && arr[j] > key) { arr[j + 1] = arr[j]; j--; }
    arr[j + 1] = key;
}
```

### The One Rule to Remember

Learn the one-sentence idea first — *swap neighbours*, *find the smallest*, *insert into the sorted part* — and the code follows from it.
