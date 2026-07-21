# CS143 — Quick Sort

> **Course:** CS143 Introduction to C++ · **Instructor:** Dr. Fawaz Alazemi
> **Builds on:** arrays, loops, recursion, and merge sort.

---

## Table of Contents

1. [The Partition Problem](#1-the-partition-problem)
2. [Smaller · Pivot · Larger](#2-smaller--pivot--larger)
3. [One Value Is Finished Forever](#3-one-value-is-finished-forever)
4. [The Method: Sweep and Grow](#4-the-method-sweep-and-grow)
5. [The partition Function](#5-the-partition-function)
6. [Partitioning by Hand](#6-partitioning-by-hand)
7. [From Partition to Quick Sort](#7-from-partition-to-quick-sort)
8. [The quickSort Function](#8-the-quicksort-function)
9. [The Complete Program](#9-the-complete-program)
10. [Tracing the Calls](#10-tracing-the-calls)
11. [The Worst Case](#11-the-worst-case)
12. [Quick Sort and Merge Sort](#12-quick-sort-and-merge-sort)
13. [Common Mistakes](#13-common-mistakes)
14. [Practice Exercises](#14-practice-exercises)
15. [Summary](#15-summary)

---

## 1. The Partition Problem

Forget sorting for a moment. Solve this smaller problem first: place **one** value where it belongs.

Take the first value of the array. Call it the **pivot**. In the final sorted array, the pivot will sit at some index `p`. Our whole task is to **find that index — and move the pivot there.**

```
Given:    arr = 5  3  8  1  9  2  7
          pivot = arr[0] = 5

Wanted:   2  3  1  [5]  9  8  7
                    ^
              index 3 — correct!
```

Three values (`3`, `1`, `2`) are smaller than `5`, so `5` must end up at index **3**. Everything smaller goes to its left; everything larger goes to its right.

---

## 2. Smaller · Pivot · Larger

After partition, the array has this shape:

```
   [ all smaller than pivot ] [pivot] [ all larger than pivot ]
                                 ^
                              index p
     not sorted yet                    not sorted yet
```

The pivot is now in its **final** place. It will never move again. But notice the two sides are only *separated* — neither one is sorted.

---

## 3. One Value Is Finished Forever

This is the whole trick of quick sort, so it is worth stating plainly.

**What partition gives you:**

- The pivot is at its correct, final index.
- Everything to the left of it is smaller.
- Everything to the right of it is larger.

**What it does _not_ give you:**

- A sorted left side.
- A sorted right side.

```
   2 3 1  [5]  9 8 7
   ^^^^^        ^^^^^
   messy        messy
```

Partition solves the problem for **one** value with certainty — and that value never has to be reconsidered.

---

## 4. The Method: Sweep and Grow

We use two indices.

- `j` — walks through every value, one by one.
- `i` — marks the **end of the "smaller" region**.

**The rule.** When `arr[j] < pivot`:

1. Grow the smaller region: `i++`
2. Swap `arr[i]` with `arr[j]`

Otherwise, do nothing — just let `j` move on.

**At the very end**, swap the pivot at `arr[left]` with `arr[i]`. The pivot drops into place, and `i` is the answer.

A snapshot partway through `5 3 8 1 9 2 7`, now `5 3 1 8 9 2 7` with `i = 2`, `j = 5`:

```
   index:  0    1    2    3    4    5    6
         [ 5 ][ 3 ][ 1 ][ 8 ][ 9 ][ 2 ][ 7 ]
          pivot  \_______/  \______/  \______/
                  smaller     larger   not looked
                    ^i                  at yet
                              ^j

   next: 2 < 5, so i++ and swap
```

---

## 5. The partition Function

```cpp
// puts arr[left] in its correct place,
// and returns that place
int partition(int arr[], int left, int right) {
    int pivot = arr[left];    // the value we place
    int i = left;             // end of "smaller" region

    for (int j = left + 1; j <= right; j++) {
        if (arr[j] < pivot) {
            i++;                       // grow the region
            int temp = arr[i];         // swap arr[i], arr[j]
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // finally, drop the pivot into place
    int temp = arr[left];
    arr[left] = arr[i];
    arr[i] = temp;

    return i;                 // the pivot's correct index
}
```

- `j` starts at `left + 1` — never compare the pivot with itself.
- `i` starts **at** `left`, so the first smaller value lands at `left + 1`.
- The final swap is **outside** the loop.

**Cost:** the loop touches each value once, so partition takes about `n` steps.

---

## 6. Partitioning by Hand

Tracing `partition` on `{5, 3, 8, 1, 9, 2, 7}` with pivot `5`:

```
start:  5 3 8 1 9 2 7   i=0

j=1  3 < 5  -> i=1, swap(1,1)
     5 3 8 1 9 2 7
j=2  8 >= 5 -> nothing
j=3  1 < 5  -> i=2, swap(2,3)
     5 3 1 8 9 2 7
j=4  9 >= 5 -> nothing
j=5  2 < 5  -> i=3, swap(3,5)
     5 3 1 2 9 8 7
j=6  7 >= 5 -> nothing

place pivot: swap(0,3)
     2 3 1 5 9 8 7

returns 3
```

**Result:** the pivot `5` sits at index `3`, exactly where it belongs. The left part `2 3 1` is all below `5`; the right part `9 8 7` is all above it. Both sides are still unsorted — that is expected.

---

## 7. From Partition to Quick Sort

After partition, the pivot is finished. The two sides are still messy — but each is just a **smaller version of the same problem**.

```
   2  3  1   [5]   9  8  7
   \___ ___/        \___ ___/
       V                V
   partition it     partition it
       |                |
       v                v
   1  [2]  3   [5]   [7]  8  9    ...and so on
```

Each partition fixes one more value forever. When every piece has shrunk to a single value, there is nothing left to fix — the array is sorted.

That is recursion again: partition, then quick sort the left side, then quick sort the right side.

---

## 8. The quickSort Function

```cpp
void quickSort(int arr[], int left, int right) {
    // base case: 0 or 1 value needs no work
    if (left >= right) return;

    // place one value correctly
    int p = partition(arr, left, right);

    quickSort(arr, left, p - 1);    // sort the smaller side
    quickSort(arr, p + 1, right);   // sort the larger side
}
```

- `p` is the pivot's final index.
- We recurse on `left..p-1` and `p+1..right`.
- **Index `p` is skipped** — that value is already correct.

> **Compare with merge sort.** Merge sort does its real work (the merge) **after** the recursive calls. Quick sort does its real work (the partition) **before** them.

Call it with `quickSort(arr, 0, n - 1);`

---

## 9. The Complete Program

```cpp
#include <iostream>
using namespace std;

int partition(int arr[], int left, int right) {
    int pivot = arr[left];
    int i = left;
    for (int j = left + 1; j <= right; j++) {
        if (arr[j] < pivot) {
            i++;
            int t = arr[i]; arr[i] = arr[j]; arr[j] = t;
        }
    }
    int t = arr[left]; arr[left] = arr[i]; arr[i] = t;
    return i;
}

void quickSort(int arr[], int left, int right) {
    if (left >= right) return;
    int p = partition(arr, left, right);
    quickSort(arr, left, p - 1);
    quickSort(arr, p + 1, right);
}

int main() {
    int arr[7] = {5, 3, 8, 1, 9, 2, 7};
    quickSort(arr, 0, 6);
    for (int i = 0; i < 7; i++) cout << arr[i] << " ";
    return 0;
}
```

**Output:**
```
1 2 3 5 7 8 9
```

Each call to `partition` fixes one value; the recursion handles what remains on either side. **No extra array is needed** — quick sort rearranges the values in place.

---

## 10. Tracing the Calls

```
quickSort [5 3 8 1 9 2 7]  pivot=5
  -> [2 3 1] 5 [9 8 7]    5 fixed at index 3

  quickSort [2 3 1]  pivot=2
    -> [1] 2 [3]          2 fixed at index 1

  quickSort [9 8 7]  pivot=9
    -> [7 8] 9 []         9 fixed at index 6

    quickSort [7 8]  pivot=7
      -> [] 7 [8]         7 fixed at index 4

final: 1 2 3 5 7 8 9
```

Three things to notice:

- Each line locks exactly **one** value into place.
- Pieces of size 1 return immediately — the base case.
- A partition can be **uneven**: `[9 8 7]` gave `[7 8]` and an empty side.

Four partitions fixed four values; the other three were finished as single-value pieces.

---

## 11. The Worst Case

If `arr[0]` is always the **smallest** value, then nothing goes to its left. Each partition removes only one value, so the recursion tree becomes one long chain of depth `n` instead of `log₂(n)`.

**This is exactly what an already sorted array does.**

```
   1 2 3 4 5 6 7 8
   pivot 1 -> left side empty
   pivot 2 -> left side empty
      ... n times
```

Measured comparisons (compiled and counted):

```
n = 8, already sorted :  28 comparisons   ( = n(n-1)/2, the worst possible )
n = 7, balanced       :  11 comparisons
```

A common fix: choose the pivot from the middle, or at random, instead of always taking `arr[0]`.

---

## 12. Quick Sort and Merge Sort

| | Quick sort | Merge sort |
|--|-----------|------------|
| Average case | n × log₂(n) | n × log₂(n) |
| Worst case | **n × n** | **n × log₂(n)** |
| Extra memory | **none (in place)** | a second array |
| Work happens | before the calls | after the calls |
| Splitting | by **value** (the pivot) | by **position** (the middle) |

**The trade:** quick sort uses no extra memory and is usually faster in practice, but a bad pivot ruins it. Merge sort is slower on average but never has a bad day.

---

## 13. Common Mistakes

**1. Starting `j` at `left`**

**Wrong:**
```cpp
for (int j = left; j <= right; j++)      // compares pivot with itself
```

**Correct:**
```cpp
for (int j = left + 1; j <= right; j++)
```

**Explanation:** the pivot is `arr[left]`; comparing it with itself corrupts the count.

**2. Forgetting the final swap**

**Wrong:**
```cpp
for (...) { ... }
return i;                 // pivot never placed
```

**Correct:**
```cpp
for (...) { ... }
int t = arr[left]; arr[left] = arr[i]; arr[i] = t;
return i;
```

**Explanation:** without the swap, the pivot stays at the front and is never put where it belongs.

**3. Including the pivot in a recursive call**

**Wrong:**
```cpp
quickSort(arr, left, p);        // p should be excluded
quickSort(arr, p, right);
```

**Correct:**
```cpp
quickSort(arr, left, p - 1);
quickSort(arr, p + 1, right);
```

**Explanation:** the value at `p` is already final; keeping it means the piece never shrinks, causing infinite recursion.

**4. No base case**

**Wrong:**
```cpp
void quickSort(int arr[], int left, int right) {
    int p = partition(arr, left, right);   // never stops
    ...
}
```

**Correct:**
```cpp
if (left >= right) return;                 // must come first
```

**Explanation:** without it, the recursion never terminates.

**5. Expecting sorted halves**

**Wrong:**
```cpp
// assuming arr[left..p-1] is now sorted after one partition
```

**Correct:**
```cpp
// partition only separates smaller from larger; it does not sort
```

**Explanation:** each side still needs its own recursive quick sort.

**6. Returning the wrong index**

**Wrong:**
```cpp
return j;                 // j is out of range after the loop
```

**Correct:**
```cpp
return i;                 // i is where the pivot landed
```

**Explanation:** `i` marks the pivot's final position; `j` does not.

---

## 14. Practice Exercises

Try each one before opening the solution.

**Exercise 1.** Partition `{4, 7, 2, 9, 3}` with pivot `arr[0] = 4`. Show the array after each swap, and give the returned index.

<details>
<summary>Click to see solution</summary>

```
pivot = 4,  i = 0

j=1  7 >= 4  -> nothing
j=2  2 <  4  -> i=1, swap(1,2)
     4 2 7 9 3
j=3  9 >= 4  -> nothing
j=4  3 <  4  -> i=2, swap(2,4)
     4 2 3 9 7

swap(0,2):  3 2 4 9 7
returns 2
```

The pivot `4` lands at index `2`, with `3 2` (smaller) on its left and `9 7` (larger) on its right.
</details>

**Exercise 2.** After `partition` returns `p`, why do we **not** include index `p` in either recursive call?

<details>
<summary>Click to see solution</summary>

Because the value at `p` is already in its final, correct position. Including it would also stop the pieces from shrinking, causing infinite recursion.
</details>

**Exercise 3.** Is the left side sorted after a partition? Explain in one sentence.

<details>
<summary>Click to see solution</summary>

No — partition only guarantees that every value on the left is **smaller** than the pivot; their order among themselves is untouched.
</details>

**Exercise 4.** Write the base case of `quickSort` and explain why it is correct.

<details>
<summary>Click to see solution</summary>

```cpp
if (left >= right) return;
```

A piece holding one value (or none) is already sorted, so there is nothing to do.
</details>

**Exercise 5.** Why is an **already sorted** array the worst case when the pivot is `arr[0]`?

<details>
<summary>Click to see solution</summary>

`arr[0]` is then the **smallest** value, so nothing is smaller than it and the left side is always **empty**. Each partition removes just one value, giving depth `n` instead of `log₂(n)`. For `n = 8` sorted, that is 28 comparisons versus 11 for a balanced input.
</details>

**Exercise 6.** Quick sort needs no second array, but merge sort does. Why?

<details>
<summary>Click to see solution</summary>

Partition rearranges values by **swapping inside the array**, so it works in place. Merge must read two sorted halves while writing the combined result, so it needs copies to avoid overwriting values it has not read yet.
</details>

---

## 15. Summary

### Key Concepts

- The **partition problem**: find the correct final index of the pivot `arr[0]`, and move it there.
- **Quick sort** repeats partition on each side until every piece has one value.
- Partition works **in place** — no second array.

### Important Points

1. `j` sweeps the array; `i` marks the end of the smaller region; swap when `arr[j] < pivot`.
2. A final swap drops the pivot at `i`, and it **never moves again**.
3. Partition separates but does **not** sort the two sides.
4. Recurse on `left..p-1` and `p+1..right` — never on `p` itself.
5. Quick sort does its work **before** the recursive calls; merge sort does it **after**.
6. Average `n × log₂(n)`. Worst case `n × n` on already sorted input.

### Quick Reference

```cpp
int partition(int arr[], int left, int right) {
    int pivot = arr[left];
    int i = left;
    for (int j = left + 1; j <= right; j++) {
        if (arr[j] < pivot) {
            i++;
            int t = arr[i]; arr[i] = arr[j]; arr[j] = t;
        }
    }
    int t = arr[left]; arr[left] = arr[i]; arr[i] = t;
    return i;                                  // pivot's final index
}

void quickSort(int arr[], int left, int right) {
    if (left >= right) return;                 // base case
    int p = partition(arr, left, right);       // place one value
    quickSort(arr, left, p - 1);               // smaller side
    quickSort(arr, p + 1, right);              // larger side
}

quickSort(arr, 0, n - 1);
```

### The One Rule to Remember

Place one value with certainty — then let recursion do it again and again.
