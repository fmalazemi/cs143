# CS143 — Merge Sort

> **Course:** CS143 Introduction to C++ · **Instructor:** Dr. Fawaz Alazemi
> **Builds on:** arrays, loops, recursion, and basic sorting.

---

## Table of Contents

1. [The Merging Problem](#1-the-merging-problem)
2. [Two Pointers, Take the Smaller](#2-two-pointers-take-the-smaller)
3. [The Merge Code](#3-the-merge-code)
4. [Merging Two Sorted Arrays](#4-merging-two-sorted-arrays)
5. [The Insight: Sorting Is Repeated Merging](#5-the-insight-sorting-is-repeated-merging)
6. [Divide and Conquer](#6-divide-and-conquer)
7. [The mergeSort Function](#7-the-mergesort-function)
8. [Merging Two Halves of One Array](#8-merging-two-halves-of-one-array)
9. [The Complete Program](#9-the-complete-program)
10. [Tracing the Calls](#10-tracing-the-calls)
11. [Why Merge Sort Is Fast](#11-why-merge-sort-is-fast)
12. [Compared With the Simple Sorts](#12-compared-with-the-simple-sorts)
13. [Common Mistakes](#13-common-mistakes)
14. [Practice Exercises](#14-practice-exercises)
15. [Summary](#15-summary)

---

## 1. The Merging Problem

Forget sorting for a moment. Solve this smaller problem first.

You are given **two arrays that are already sorted**. Produce a single sorted array containing all their values.

```
Input:    A = 1  4  7  9
          B = 2  3  8

Output:   C = 1  2  3  4  7  8  9
```

The important word is **already**. Because each array is sorted, the smallest value that has not been used yet must be sitting at the **front** of one of them. That single observation is the whole algorithm.

---

## 2. Two Pointers, Take the Smaller

1. Put a pointer `i` at the start of `A`, and `j` at the start of `B`.
2. Compare `A[i]` with `B[j]`.
3. Copy the **smaller** one into `C`.
4. Advance **only that** pointer.
5. Repeat until one array runs out.

**Why it works:** each array is sorted, so `A[i]` is the smallest unused value of `A`, and `B[j]` is the smallest unused value of `B`. The smaller of those two must therefore be the smallest value remaining **overall**.

A snapshot in the middle of the work, after `1` and `2` have been copied:

```
        used
        vvv
   A =  [1]  4   7   9
             ^
             i          compare 4 and 3
                        3 is smaller -> copy it
   B =  [2]  3   8      then advance j only
             ^
             j

   C =   1   2   3   _   _   _   _
                     ^
                     k
```

**Cost:** every value is copied exactly once, so merging takes about `nA + nB` steps.

---

## 3. The Merge Code

```cpp
int i = 0, j = 0, k = 0;

// while BOTH arrays still have values
while (i < nA && j < nB) {
    if (A[i] <= B[j])
        C[k++] = A[i++];   // take from A
    else
        C[k++] = B[j++];   // take from B
}

// one array is empty — copy whatever is left
while (i < nA) C[k++] = A[i++];
while (j < nB) C[k++] = B[j++];
```

**Why two extra loops?** The main loop stops as soon as **one** array runs out. The other may still hold values — and they are already sorted, so we just copy them across. Only **one** of the two leftover loops ever runs.

Using `<=` rather than `<` keeps equal values in their original relative order.

---

## 4. Merging Two Sorted Arrays

```cpp
#include <iostream>
using namespace std;

int main() {
    int A[4] = {1, 4, 7, 9};
    int B[3] = {2, 3, 8};
    int nA = 4, nB = 3;
    int C[7];

    int i = 0, j = 0, k = 0;
    while (i < nA && j < nB) {
        if (A[i] <= B[j]) C[k++] = A[i++];
        else              C[k++] = B[j++];
    }
    while (i < nA) C[k++] = A[i++];   // leftovers
    while (j < nB) C[k++] = B[j++];

    for (int x = 0; x < 7; x++) cout << C[x] << " ";
    return 0;
}
```

**Output:**
```
1 2 3 4 7 8 9
```

What happened, step by step:

```
1 vs 2 -> take 1
4 vs 2 -> take 2
4 vs 3 -> take 3
4 vs 8 -> take 4
7 vs 8 -> take 7
9 vs 8 -> take 8
B is empty -> copy 9
```

Six comparisons, then one leftover. Notice that `B` emptied first, so the final `9` was copied by the leftover loop — this is exactly why that loop exists.

---

## 5. The Insight: Sorting Is Repeated Merging

We can merge two **sorted** arrays quickly. So imagine cutting an unsorted array in half:

```
   unsorted:   5  2  8  1

   left half:  5  2          right half:  8  1
     | somehow sort            | somehow sort
     v                         v
               2  5                       1  8

   merge them  ->   1  2  5  8
```

**But how do we sort each half?** The same way — cut it in half, sort *those* halves, and merge.

That is recursion. And a half of a half of a half eventually holds just **one value**, which is already sorted.

---

## 6. Divide and Conquer

The algorithm has three steps:

1. **Divide:** cut the array in half at `mid`.
2. **Conquer:** call `mergeSort` on each half.
3. **Combine:** merge the two sorted halves.

The **base case** is a piece holding one value, or none — it is already sorted, so stop:

```cpp
if (left >= right) return;
```

Here is the whole process on `{5, 2, 8, 1}`:

```
   SPLIT (no sorting happens here)
                [5  2  8  1]
                /          \
            [5  2]        [8  1]
            /    \        /    \
          [5]   [2]     [8]   [1]

   MERGE (all the sorting happens here)
          [5]   [2]     [8]   [1]
            \    /        \    /
            [2  5]        [1  8]
                \          /
                [1  2  5  8]
```

> The splitting does no sorting at all. **All the sorting happens on the way back up, inside `merge`.**

---

## 7. The mergeSort Function

```cpp
void mergeSort(int arr[], int left, int right) {
    // base case: 0 or 1 value is already sorted
    if (left >= right) return;

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);        // sort left half
    mergeSort(arr, mid + 1, right);   // sort right half

    merge(arr, left, mid, right);     // combine them
}
```

- `left` and `right` mark the piece we are currently sorting.
- `mid` splits it into `left..mid` and `mid+1..right`.
- Both recursive calls must finish **before** `merge` runs.

It is only four lines, because all the real work lives in `merge` — which we already wrote in Part A. Call it with `mergeSort(arr, 0, n - 1);`

---

## 8. Merging Two Halves of One Array

```cpp
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;      // size of left half
    int n2 = right - mid;         // size of right half

    int L[100], R[100];           // temporary copies
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;   // k writes back into arr

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else              arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}
```

This is Part A's merge, with two changes:

- The two halves live inside **one** array, so we first **copy them out** into `L` and `R`.
- The result is written **back** into `arr`, starting at index `left`.

The copies are essential. Writing into `arr` immediately would destroy values in the left half that we still have to read.

---

## 9. The Complete Program

```cpp
#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1, n2 = right - mid;
    int L[100], R[100];
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else              arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main() {
    int arr[7] = {38, 27, 43, 3, 9, 82, 10};
    mergeSort(arr, 0, 6);
    for (int i = 0; i < 7; i++) cout << arr[i] << " ";
    return 0;
}
```

**Output:**
```
3 9 10 27 38 43 82
```

Two short functions sort an array of any size.

---

## 10. Tracing the Calls

```
split [38 27 43 3 9 82 10]
  split [38 27 43 3]
    split [38 27]
    merged -> [27 38]
    split [43 3]
    merged -> [3 43]
  merged -> [3 27 38 43]
  split [9 82 10]
    split [9 82]
    merged -> [9 82]
  merged -> [9 10 82]
merged -> [3 9 10 27 38 43 82]
```

Three things to notice:

- Every **split** in a branch happens before any merge in that branch.
- The left half is fully sorted before the right half is even touched.
- The **last** merge joins a sorted half of four values with a sorted half of three.

**Odd sizes are fine.** `[9 82 10]` splits into `[9 82]` and `[10]`. A single value needs no sorting, so it returns immediately.

---

## 11. Why Merge Sort Is Fast

Each level of the tree merges every value exactly once — that is `n` work. The number of levels is simply how many times you can halve `n`.

```
   level 0 : [################################]        n work
   level 1 : [###############][###############]        n work
   level 2 : [######][######][######][#######]         n work
   level 3 : [##][##][##][##][##][##][##][###]         n work

   log2(n) levels  x  n work per level  =  n x log2(n)
```

Every level holds the same total number of values, so every level costs the same. Multiply the two and you get `n × log₂(n)`.

---

## 12. Compared With the Simple Sorts

| Algorithm | Worst case | Extra memory | Idea |
|-----------|------------|--------------|------|
| Bubble | n × n | none | swap neighbours |
| Selection | n × n | none | find the smallest |
| Insertion | n × n | none | insert into sorted part |
| **Merge** | **n × log₂(n)** | a second array | split, sort, merge |

For one million values:

```
bubble sort : about 1,000,000,000,000 steps
merge sort  : about        20,000,000 steps
```

Merge sort trades a little extra memory for an enormous gain in speed.

---

## 13. Common Mistakes

**1. Forgetting the leftover loops**

**Wrong:**
```cpp
while (i < n1 && j < n2) { ... }
// nothing after
```

**Correct:**
```cpp
while (i < n1 && j < n2) { ... }
while (i < n1) arr[k++] = L[i++];
while (j < n2) arr[k++] = R[j++];
```

**Explanation:** the tail of the longer half would be silently dropped.

**2. Advancing both pointers**

**Wrong:**
```cpp
if (L[i] <= R[j]) arr[k++] = L[i];
i++; j++;                          // both move
```

**Correct:**
```cpp
if (L[i] <= R[j]) arr[k++] = L[i++];
else              arr[k++] = R[j++];
```

**Explanation:** only the pointer you copied from moves forward.

**3. No base case**

**Wrong:**
```cpp
void mergeSort(int arr[], int left, int right) {
    int mid = left + (right - left) / 2;   // never stops
    ...
}
```

**Correct:**
```cpp
if (left >= right) return;                 // must come first
```

**Explanation:** without it, the recursion never terminates.

**4. Wrong halves**

**Wrong:**
```cpp
mergeSort(arr, left, mid);
mergeSort(arr, mid, right);      // overlaps!
```

**Correct:**
```cpp
mergeSort(arr, left, mid);
mergeSort(arr, mid + 1, right);
```

**Explanation:** with `mid..right`, a two-element piece never shrinks and the program crashes with a stack overflow.

**5. Merging before both calls return**

**Wrong:**
```cpp
mergeSort(arr, left, mid);
merge(arr, left, mid, right);    // right half not sorted yet
mergeSort(arr, mid + 1, right);
```

**Correct:**
```cpp
mergeSort(arr, left, mid);
mergeSort(arr, mid + 1, right);
merge(arr, left, mid, right);
```

**Explanation:** `merge` assumes **both** halves are already sorted.

**6. Writing into `arr` while still reading it**

**Wrong:**
```cpp
// merge directly from arr into arr, with no copies
```

**Correct:**
```cpp
for (int i = 0; i < n1; i++) L[i] = arr[left + i];
for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];
```

**Explanation:** the first write to `arr[left]` would overwrite a value not yet read.

---

## 14. Practice Exercises

Try each one before opening the solution.

**Exercise 1.** Merge `A = {2, 5, 6}` and `B = {1, 3, 9}` by hand. Write the order in which values are copied.

<details>
<summary>Click to see solution</summary>

```
2 vs 1 -> take 1
2 vs 3 -> take 2
5 vs 3 -> take 3
5 vs 9 -> take 5
6 vs 9 -> take 6
A is empty -> copy 9 from B

result: 1 2 3 5 6 9
```
</details>

**Exercise 2.** Why does the merge need **two** leftover loops, and why does only one ever run?

<details>
<summary>Click to see solution</summary>

The main loop ends as soon as **one** array is exhausted. We do not know in advance which one, so we write a loop for each. The other array still holds sorted values that must be copied. Only one loop actually runs, because only one array can have values left.
</details>

**Exercise 3.** What is the base case of `mergeSort`, and why is it correct?

<details>
<summary>Click to see solution</summary>

```cpp
if (left >= right) return;
```

A piece holding one value (or none) is **already sorted**, so there is nothing to do.
</details>

**Exercise 4.** Draw the split tree for `{4, 1, 3, 2}`, then write the result of each merge.

<details>
<summary>Click to see solution</summary>

```
split : [4 1 3 2]
        [4 1]   [3 2]
        [4][1] [3][2]

merge : [1 4]   [2 3]
        [1 2 3 4]
```
</details>

**Exercise 5.** In `merge`, why must we copy the halves into `L` and `R` before writing into `arr`?

<details>
<summary>Click to see solution</summary>

Because `merge` writes its output back into `arr` starting at index `left`. Without the copies, the very first write would overwrite a value in the left half that has not been read yet.
</details>

**Exercise 6.** An array holds 1,000,000 values. Roughly how many **levels** of splitting are there? Explain.

<details>
<summary>Click to see solution</summary>

**About 20.** Each level halves the size of every piece, and 2²⁰ is just over one million, so twenty halvings reduce the pieces to a single value each.
</details>

---

## 15. Summary

### Key Concepts

- **Merging** joins two sorted arrays with two pointers: compare the fronts, take the smaller, advance that pointer.
- **Merge sort** solves the sorting problem by splitting, recursing, and merging.
- Splitting does no sorting — all the sorting happens inside `merge`, on the way back up.

### Important Points

1. After the main merge loop, copy the **leftovers** from whichever array still has values.
2. Only the pointer you copied from advances.
3. The base case is `left >= right`: one value is already sorted.
4. Split into `left..mid` and `mid+1..right` — never `mid..right`.
5. `merge` runs **after** both recursive calls return.
6. Cost: `log₂(n)` levels × `n` work = `n × log₂(n)`, far faster than `n × n`.

### Quick Reference

```cpp
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1, n2 = right - mid;
    int L[100], R[100];
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else              arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];   // leftovers
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int left, int right) {
    if (left >= right) return;                // base case
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);                // sort left
    mergeSort(arr, mid + 1, right);           // sort right
    merge(arr, left, mid, right);             // combine
}

mergeSort(arr, 0, n - 1);
```

### The One Rule to Remember

Solve the small problem first — then sorting is just merging, applied again and again.
