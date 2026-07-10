# CS143 — Binary Search on Sorted Arrays

> **Course:** CS143 Introduction to C++ · **Instructor:** Dr. Fawaz Alazemi
> **Builds on:** arrays, loops, functions, and sorting.

---

## Table of Contents

1. [The Problem](#1-the-problem)
2. [Why Halving Beats Walking](#2-why-halving-beats-walking)
3. [The Array Must Be Sorted](#3-the-array-must-be-sorted)
4. [The Idea: Three Variables, Three Cases](#4-the-idea-three-variables-three-cases)
5. [Finding the Middle](#5-finding-the-middle)
6. [Tracing a Search](#6-tracing-a-search)
7. [Binary Search With a Loop](#7-binary-search-with-a-loop)
8. [When the Target Is Absent](#8-when-the-target-is-absent)
9. [Binary Search With Recursion](#9-binary-search-with-recursion)
10. [How Python Differs](#10-how-python-differs)
11. [Common Mistakes](#11-common-mistakes)
12. [Practice Exercises](#12-practice-exercises)
13. [Summary](#13-summary)

---

## 1. The Problem

Given an array and a target value, find the **index** of the target — or report that it is not there.

**Linear search** checks every element from left to right:

```cpp
for (int i = 0; i < n; i++)
    if (arr[i] == target)
        return i;
return -1;
```

It works on **any** array, sorted or not, but it may need up to `n` checks.

**Binary search** looks at the **middle** element instead. Because the array is sorted, that single comparison tells us which half the target must be in — so the other half can be thrown away immediately.

This is why we sort: sorting once makes every later search enormously faster.

---

## 2. Why Halving Beats Walking

Each comparison in binary search removes half of what is left, so the number of steps grows very slowly.

| Array size n | Linear search (worst) | Binary search (worst) |
|--------------|-----------------------|-----------------------|
| 10 | 10 checks | **4 checks** |
| 1,000 | 1,000 checks | **10 checks** |
| 1,000,000 | 1,000,000 checks | **20 checks** |

The range shrinks like this:

```
   step  0 : ################################  1,000,000
   step  1 : ################                    500,000
   step  2 : ########                            250,000
   step  3 : ####                                125,000
   step  4 : ##                                   62,500
     ...
   step 20 : #                                         1   <- the answer
```

Doubling the size of the array adds only **one** extra step. A million items are searched in about twenty comparisons.

---

## 3. The Array Must Be Sorted

Binary search decides which half to keep by comparing the target with the middle value. If the array is not sorted, that decision is meaningless — the discarded half may well contain the target.

**Unsorted — it fails:**

```
arr = 16  2  91  5  23
search 5  ->  -1  (not found)
```

But `5` **is** in the array, at index 3. The search compared against `91`, decided to look left, and missed it entirely.

**Sorted — it works:**

```
arr = 2  5  16  23  91
search 5  ->  1  (found)
```

Sort first, then search:

```cpp
sort(arr, arr + n);
```

**Remember:** a wrong answer is worse than a slow one. If you are not certain the array is sorted, use linear search or sort it first.

---

## 4. The Idea: Three Variables, Three Cases

We keep track of the part of the array that could still contain the target.

- `low` — the first index still in play.
- `high` — the last index still in play.
- `mid` — the middle of that range.

At each step, compare `arr[mid]` with the target:

```
        low                mid                high
         |------ left ------|------ right ------|

   target == arr[mid]  ->  found, return mid
   target <  arr[mid]  ->  keep the left:   high = mid - 1
   target >  arr[mid]  ->  keep the right:  low  = mid + 1
```

Repeat while `low <= high`. If the two indices cross, the range is empty and the target is not present.

---

## 5. Finding the Middle

```cpp
int mid = low + (high - low) / 2;
```

**Why not `(low + high) / 2`?** For very large arrays, the sum `low + high` can exceed what an `int` can hold. The result then becomes a wrong (possibly negative) number. The form `low + (high - low) / 2` gives the **same** answer and never overflows.

Note also that integer division rounds **down**: with `low = 0` and `high = 9`, `mid` is `4`, not `4.5`.

---

## 6. Tracing a Search

Searching for `23` in a 10-element array:

```
index:    0    1    2    3    4    5    6    7    8    9
array:    2    5    8   12   16   23   38   56   72   91

step 1:  low=0            mid=4                    high=9
         arr[4] = 16  <  23   ->  go right, low = 5

step 2:                        low=5     mid=7     high=9
         arr[7] = 56  >  23   ->  go left, high = 6

step 3:                        low=5
                               mid=5     high=6
         arr[5] = 23  ==  23  ->  FOUND at index 5
```

Three comparisons instead of six. At each step, everything outside the `low..high` window has been permanently discarded.

---

## 7. Binary Search With a Loop

```cpp
#include <iostream>
using namespace std;

// returns the index of target, or -1 if absent
int binarySearch(int arr[], int n, int target) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {          // still a range left
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
            return mid;            // found
        else if (arr[mid] < target)
            low = mid + 1;         // keep the right half
        else
            high = mid - 1;        // keep the left half
    }
    return -1;                     // not found
}

int main() {
    int arr[10] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    cout << binarySearch(arr, 10, 23) << endl;
    return 0;
}
```

**Output:**
```
5
```

Two details matter:

- `low <= high` means the range is not yet empty.
- `mid + 1` and `mid - 1` **exclude** the element we just tested — this is what guarantees the range keeps shrinking.

---

## 8. When the Target Is Absent

```cpp
int arr[10] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};

int result = binarySearch(arr, 10, 10);   // 10 is not there

if (result == -1)
    cout << "Not found" << endl;
else
    cout << "Found at index " << result << endl;
```

**Output:**
```
Not found
```

The range shrinks to nothing:

```
low=0 high=9 mid=4   arr[4]=16 > 10
low=0 high=3 mid=1   arr[1]=5  < 10
low=2 high=3 mid=2   arr[2]=8  < 10
low=3 high=3 mid=3   arr[3]=12 > 10
low=3 high=2   ->  low > high, stop
```

After four comparisons, `high` becomes smaller than `low`. The range is empty, so the target cannot be anywhere in the array.

Returning `-1` is the usual way to say "absent", because `-1` is never a valid array index.

---

## 9. Binary Search With Recursion

The same algorithm can be written as a recursion. The shrinking range is passed along as `low` and `high`.

```cpp
int binarySearch(int arr[], int low, int high, int target) {
    // base case 1: empty range
    if (low > high)
        return -1;

    int mid = low + (high - low) / 2;

    // base case 2: found it
    if (arr[mid] == target)
        return mid;

    if (arr[mid] < target)                    // search right
        return binarySearch(arr, mid + 1, high, target);
    else                                      // search left
        return binarySearch(arr, low, mid - 1, target);
}

int main() {
    int arr[10] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    cout << binarySearch(arr, 0, 9, 23) << endl;
    return 0;
}
```

**Output:**
```
5
```

There are two base cases: `low > high` (empty range, return `-1`) and `arr[mid] == target` (success).

Note that only **one** recursive call ever runs, and no work happens after it returns. By the rule from the recursion-to-iteration lecture, that means the loop version is easily preferred in practice.

---

## 10. How Python Differs

| Goal | Python | C++ |
|------|--------|-----|
| Simple search | `x in myList` | write a loop |
| Binary search | `bisect.bisect_left` | write it, or use the STL |
| Requires sorting | yes, for bisect | yes, always |

In Python, `x in myList` is a **linear** search — simple to write but slow on large lists. Both languages provide a library binary search, and both demand a sorted sequence first.

The C++ standard library version:

```cpp
#include <algorithm>
bool found = binary_search(arr, arr + n, 23);   // true
```

---

## 11. Common Mistakes

**1. Searching an unsorted array**

**Wrong:**
```cpp
int arr[5] = {16, 2, 91, 5, 23};
binarySearch(arr, 5, 5);      // returns -1, but 5 is there
```

**Correct:**
```cpp
sort(arr, arr + 5);           // sort first
binarySearch(arr, 5, 5);      // now correct
```

**Explanation:** without order, the discarded half may contain the target.

**2. Infinite loop**

**Wrong:**
```cpp
else high = mid;              // range stops shrinking
```

**Correct:**
```cpp
else high = mid - 1;
```

**Explanation:** the tested element must be excluded, or `mid` keeps taking the same value forever.

**3. Using `low < high`**

**Wrong:**
```cpp
while (low < high) { ... }    // skips a one-element range
```

**Correct:**
```cpp
while (low <= high) { ... }
```

**Explanation:** when `low == high` there is still one element left to test.

**4. Overflow when computing `mid`**

**Wrong:**
```cpp
int mid = (low + high) / 2;   // sum may overflow
```

**Correct:**
```cpp
int mid = low + (high - low) / 2;
```

**Explanation:** the safe form gives the same value and never overflows.

**5. Starting with `high = n`**

**Wrong:**
```cpp
int high = n;                 // arr[n] does not exist
```

**Correct:**
```cpp
int high = n - 1;
```

**Explanation:** the last valid index of an `n`-element array is `n - 1`.

**6. Forgetting the not-found case**

**Wrong:**
```cpp
while (low <= high) { ... }
// function ends with no return
```

**Correct:**
```cpp
while (low <= high) { ... }
return -1;
```

**Explanation:** the caller needs a clear signal that the target is absent.

**The infinite-loop test:** after every step, the range must get **strictly smaller**.

---

## 12. Practice Exercises

Try each one before opening the solution.

**Exercise 1.** Using `{2, 5, 8, 12, 16, 23, 38, 56, 72, 91}`, trace the search for `72`. Write `low`, `mid`, and `high` at each step.

<details>
<summary>Click to see solution</summary>

```
low=0 high=9 mid=4   arr[4]=16 < 72
low=5 high=9 mid=7   arr[7]=56 < 72
low=8 high=9 mid=8   arr[8]=72  ✓
found at index 8   (3 steps)
```
</details>

**Exercise 2.** Why must the array be sorted? Answer in one sentence.

<details>
<summary>Click to see solution</summary>

Because the comparison with `arr[mid]` is what tells us which half to discard; without order, the discarded half may still contain the target.
</details>

**Exercise 3.** Write the line that computes `mid` safely, and explain why it is preferred.

<details>
<summary>Click to see solution</summary>

```cpp
int mid = low + (high - low) / 2;
```

It gives the same value as `(low + high) / 2`, but never lets the sum grow too large for an `int`, so it cannot overflow.
</details>

**Exercise 4.** What happens if you write `high = mid;` instead of `high = mid - 1;`?

<details>
<summary>Click to see solution</summary>

The range stops shrinking once `high` equals `low + 1`, so `mid` keeps taking the same value: an **infinite loop**. The element just tested must be excluded from the new range.
</details>

**Exercise 5.** Write a complete iterative `binarySearch` that returns `-1` when the target is absent.

<details>
<summary>Click to see solution</summary>

```cpp
int binarySearch(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)      return mid;
        else if (arr[mid] < target)  low  = mid + 1;
        else                         high = mid - 1;
    }
    return -1;
}
```
</details>

**Exercise 6.** An array holds 1,000,000 sorted values. What is the worst-case number of comparisons for binary search? Explain briefly.

<details>
<summary>Click to see solution</summary>

**About 20 comparisons.** Each step halves the range, and 2²⁰ is just over one million, so twenty halvings reduce the range to a single element.
</details>

---

## 13. Summary

### Key Concepts

- **Binary search** finds a value in a sorted array by repeatedly halving the range.
- The array **must be sorted**, or the answer is simply wrong.
- Each comparison discards half of what remains.

### Important Points

1. Keep `low` and `high`; test `arr[mid]`; discard half each time.
2. Compute the middle safely: `low + (high - low) / 2`.
3. Use `mid + 1` and `mid - 1` so the range always shrinks strictly.
4. Loop while `low <= high`; return `-1` once they cross.
5. A million values need only about **20** comparisons.
6. The recursive version has two base cases: empty range, and a match at `mid`.

### Quick Reference

```cpp
int binarySearch(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;   // safe middle
        if (arr[mid] == target)      return mid;      // found
        else if (arr[mid] < target)  low  = mid + 1;  // go right
        else                         high = mid - 1;  // go left
    }
    return -1;                                        // absent
}

// standard library version
#include <algorithm>
bool found = binary_search(arr, arr + n, target);
```

### The One Rule to Remember

Sort once, then search almost instantly — forever after. But never binary-search an array you have not sorted.
