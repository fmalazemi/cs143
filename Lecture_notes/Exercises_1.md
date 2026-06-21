# C++ Practice Problems: Recursion, Loops, Arrays, and 2D Arrays

**Rules for all solutions**

- Use C++.
- `std::string` is allowed for text. Do not use other STL containers such as `vector`, `map`, `set`, etc.
- Do not use explicit pointers.
- Do not use `<cmath>`.
- Use basic arrays, loops, functions, recursion, and `std::string` for text.
- Unless stated otherwise, assume input values are valid and within the stated constraints.

Each problem lists a **Difficulty** (Easy / Medium / Hard) and **Constraints** so you know the input bounds before you size your arrays. Solutions live in the companion file `solutions.md` — try each problem yourself first, then check the hint if you're stuck, and only then look at the solution.

---

## Table of Contents

**Part A — Basic Recursion and Loops**
[1](#problem-1--palindrome-recursively-and-iteratively) · [2](#problem-2--is-prime) · [3](#problem-3--find-remainder-without----or--recursively) · [4](#problem-4--check-if-two-words-are-anagrams) · [5](#problem-5--count-words-in-text) · [6](#problem-6--check-if-array-is-sorted) · [7](#problem-7--find-maximum-minimum-and-average) · [8](#problem-8--two-indices-add-to-x) · [9](#problem-9--three-indices-add-to-x) · [10](#problem-10--factorial-recursively-and-iteratively) · [11](#problem-11--power-recursively-and-iteratively) · [12](#problem-12--gcd) · [13](#problem-13--lcm) · [14](#problem-14--reverse-integer-iteratively-and-recursively) · [15](#problem-15--largest-sum-of-digits-in-array) · [16](#problem-16--fibonacci-recursively-and-iteratively)

**Part B — 1D Array Problems**
[17](#problem-17--reverse-an-array) · [18](#problem-18--shrink-array-by-deleting-values) · [19](#problem-19--find-the-middle-median) · [20](#problem-20--partition-array-around-x) · [21](#problem-21--merge-two-sorted-arrays) · [22](#problem-22--longest-increasing-or-decreasing-sequence) · [23](#problem-23--add-two-polynomials-using-arrays)

**Part C — 2D Array Problems**
[24](#problem-24--swap-rows) · [25](#problem-25--swap-columns) · [26](#problem-26--print-matrix-in-spiral-order) · [27](#problem-27--check-if-matrix-contains-spiral-elements) · [28](#problem-28--maze-problem-path-exists)

**Part D — Sorting, Searching, and More Recursion**
[29](#problem-29--selection-sort) · [30](#problem-30--binary-search-iteratively-and-recursively) · [31](#problem-31--matrix-transpose) · [32](#problem-32--matrix-multiplication) · [33](#problem-33--rotate-matrix-90-degrees) · [34](#problem-34--pascals-triangle) · [35](#problem-35--count-paths-in-a-maze) · [36](#problem-36--fast-exponentiation)

---

# Part A — Basic Recursion and Loops

## Problem 1 — Palindrome Recursively and Iteratively

**Difficulty:** Easy

Write two functions to check whether a text is a palindrome.

A palindrome reads the same forward and backward.

For simplicity, assume the text contains no spaces.

### Constraints

- The word length is between 1 and 200 characters.
- All characters are lowercase English letters.

### Input

A word.

### Output

Print whether the word is a palindrome using:

1. Iterative solution
2. Recursive solution

### Sample Input

```text
level
```

### Sample Output

```text
Iterative: Palindrome
Recursive: Palindrome
```

💡 **Hint:** For the iterative version, use two indices that start at opposite ends and move toward each other. For the recursive version, the same two indices become parameters — the base case is when they meet or cross.

---

## Problem 2 — Is Prime

**Difficulty:** Easy

Write a program that checks whether an integer `n` is prime.

A number is prime if it is greater than 1 and has no divisors other than 1 and itself.

### Constraints

- 1 ≤ n ≤ 1,000,000

### Input

One integer `n`.

### Output

Print `Prime` or `Not Prime`.

### Sample Input

```text
17
```

### Sample Output

```text
Prime
```

💡 **Hint:** You only need to check divisors up to `n / 2` (or, for a faster solution, up to the square root of `n`).

---

## Problem 3 — Find Remainder Without `*`, `/`, or `%` Recursively

**Difficulty:** Medium

Write a recursive function that finds the remainder of `a` divided by `b`.

You are not allowed to use:

```text
*
/
%
```

inside the remainder function.

### Constraints

- 1 ≤ a, b ≤ 10,000

### Input

Two positive integers `a` and `b`.

### Output

Print the remainder.

### Sample Input

```text
17 5
```

### Sample Output

```text
2
```

💡 **Hint:** Repeated subtraction is multiplication and division in disguise — keep subtracting `b` from `a` until what's left is smaller than `b`.

---

## Problem 4 — Check if Two Words Are Anagrams

**Difficulty:** Easy

Two words are anagrams if they contain the same letters with the same frequencies, but possibly in different order.

Assume all letters are lowercase English letters.

### Constraints

- Each word has length between 1 and 200.

### Input

Two words.

### Output

Print `Anagrams` or `Not Anagrams`.

### Sample Input

```text
listen
silent
```

### Sample Output

```text
Anagrams
```

💡 **Hint:** A 26-element frequency array (one slot per letter) is simpler and just as effective as sorting the letters.

---

## Problem 5 — Count Words in Text

**Difficulty:** Easy

Write a program that counts how many words are in a line of text.

A word is a sequence of non-space characters.

### Constraints

- The line has at most 1000 characters.

### Input

One line of text.

### Output

Print the number of words.

### Sample Input

```text
Cplusplus is fun
```

### Sample Output

```text
3
```

💡 **Hint:** Track a boolean "currently inside a word" flag as you scan character by character; increment your counter only on the transition from space to non-space.

---

## Problem 6 — Check if Array Is Sorted

**Difficulty:** Easy

Write a program that checks whether an integer array is sorted in non-decreasing order.

### Constraints

- 1 ≤ n ≤ 1000
- -1,000,000 ≤ each element ≤ 1,000,000

### Input

The first line contains `n`.

The second line contains `n` integers.

### Output

Print `Sorted` or `Not Sorted`.

### Sample Input

```text
5
1 2 2 4 8
```

### Sample Output

```text
Sorted
```

💡 **Hint:** You only ever need to compare each element to the one right after it — one pass is enough.

---

## Problem 7 — Find Maximum, Minimum, and Average

**Difficulty:** Easy

Given an array of integers, find:

1. Maximum value
2. Minimum value
3. Average value

### Constraints

- 1 ≤ n ≤ 1000 (n is always at least 1)
- -1,000,000 ≤ each element ≤ 1,000,000

### Input

The first line contains `n`.

The second line contains `n` integers.

### Output

Print maximum, minimum, and average.

### Sample Input

```text
5
3 10 2 8 7
```

### Sample Output

```text
Max = 10
Min = 2
Avg = 6
```

💡 **Hint:** Seed `max` and `min` with `a[0]` before the loop instead of an arbitrary constant like 0 — that way negative-only arrays still work correctly.

---

## Problem 8 — Two Indices Add to X

**Difficulty:** Easy

Given an array `A` and a target value `X`, check if there exist two different indices `i` and `j` such that:

```text
A[i] + A[j] = X
```

### Constraints

- 2 ≤ n ≤ 1000
- -1,000,000 ≤ each element, X ≤ 1,000,000

### Input

The first line contains `n`.

The second line contains `n` integers.

The third line contains `X`.

### Output

Print `Found` or `Not Found`.

### Sample Input

```text
5
1 4 7 2 9
11
```

### Sample Output

```text
Found
```

💡 **Hint:** The brute-force double loop (checking every pair) works fine at this size. As a bonus, think about how sorting first could help you solve it in one pass with two pointers.

---

## Problem 9 — Three Indices Add to X

**Difficulty:** Medium

Given an array `A` and a target value `X`, check if there exist three different indices `i`, `j`, and `k` such that:

```text
A[i] + A[j] + A[k] = X
```

### Constraints

- 3 ≤ n ≤ 500
- -1,000,000 ≤ each element, X ≤ 1,000,000

### Input

The first line contains `n`.

The second line contains `n` integers.

The third line contains `X`.

### Output

Print `Found` or `Not Found`.

### Sample Input

```text
6
1 4 7 2 9 3
14
```

### Sample Output

```text
Found
```

💡 **Hint:** Check every triple of indices `(i, j, k)` with three nested loops to see if they sum to `X`.

---

## Problem 10 — Factorial Recursively and Iteratively

**Difficulty:** Easy

Write two functions to calculate `n!`.

```text
n! = n * (n - 1) * ... * 1
```

Also:

```text
0! = 1
```

### Constraints

- 0 ≤ n ≤ 20 (so the result fits in a `long long`)

### Input

One integer `n`.

### Output

Print factorial using:

1. Iterative solution
2. Recursive solution

### Sample Input

```text
5
```

### Sample Output

```text
Iterative = 120
Recursive = 120
```

💡 **Hint:** Use `long long` for the result — factorials grow fast, and even `13!` overflows a 32-bit `int`.

---

## Problem 11 — Power Recursively and Iteratively

**Difficulty:** Easy

Write two functions to calculate:

```text
base^exp
```

where `exp` is a non-negative integer.

Do not use `<cmath>`.

### Constraints

- -100 ≤ base ≤ 100
- 0 ≤ exp ≤ 30

### Input

Two integers: `base` and `exp`.

### Output

Print the result using:

1. Iterative solution
2. Recursive solution

### Sample Input

```text
2 5
```

### Sample Output

```text
Iterative = 32
Recursive = 32
```

💡 **Hint:** `exp` is guaranteed non-negative, so your base case is simply `exp == 0`, which returns 1.

---

## Problem 12 — GCD

**Difficulty:** Easy

Write a program that finds the greatest common divisor of two positive integers.

The GCD is the largest number that divides both numbers.

### Constraints

- 1 ≤ a, b ≤ 1,000,000,000

### Input

Two positive integers.

### Output

Print the GCD.

### Sample Input

```text
24 18
```

### Sample Output

```text
6
```

💡 **Hint:** The Euclidean algorithm (`gcd(a, b) = gcd(b, a % b)`) solves this in very few steps even for large numbers.

---

## Problem 13 — LCM

**Difficulty:** Easy

Write a program that finds the least common multiple of two positive integers.

The LCM is the smallest positive number divisible by both numbers.

### Constraints

- 1 ≤ a, b ≤ 1,000,000

### Input

Two positive integers.

### Output

Print the LCM.

### Sample Input

```text
6 8
```

### Sample Output

```text
24
```

💡 **Hint:** `lcm(a, b) = a / gcd(a, b) * b`. Watch the order of operations — dividing first keeps intermediate values smaller and avoids overflow.

---

## Problem 14 — Reverse Integer Iteratively and Recursively

**Difficulty:** Easy

Write two functions to reverse the digits of an integer.

### Constraints

- 0 ≤ n ≤ 1,000,000,000 (n is non-negative)

### Input

One integer.

### Output

Print the reversed number using:

1. Iterative solution
2. Recursive solution

### Sample Input

```text
12345
```

### Sample Output

```text
Iterative = 54321
Recursive = 54321
```

💡 **Hint:** Peel off the last digit with `n % 10`, append it to your running result (`result * 10 + digit`), then strip it from `n` with `n / 10`.

---

## Problem 15 — Largest Sum of Digits in Array

**Difficulty:** Medium

Given an array of integers `A`, print the integer that has the largest sum of digits.

If more than one number has the same largest digit sum, print the first one.

### Constraints

- 1 ≤ n ≤ 1000
- 0 ≤ each element ≤ 1,000,000,000

### Input

The first line contains `n`.

The second line contains `n` integers.

### Output

Print the integer with the largest sum of digits.

### Sample Input

```text
5
51 99 123 77 400
```

### Sample Output

```text
99
```

Explanation:

```text
51  -> 6
99  -> 18
123 -> 6
77  -> 14
400 -> 4
```

💡 **Hint:** Write a small helper `digitSum(int n)` first, then scan the array once, tracking the best number and best sum seen so far.

---

## Problem 16 — Fibonacci Recursively and Iteratively

**Difficulty:** Easy

Write two functions that compute the `n`th Fibonacci number.

Use this definition:

```text
fib(0) = 0
fib(1) = 1
fib(n) = fib(n - 1) + fib(n - 2)
```

### Constraints

- 0 ≤ n ≤ 40

### Input

One integer `n`.

### Output

Print `fib(n)` using:

1. Iterative solution
2. Recursive solution

### Sample Input

```text
7
```

### Sample Output

```text
Iterative = 13
Recursive = 13
```

💡 **Hint:** The iterative version just needs two running variables (`prev`, `curr`) updated in a loop — no array required.

---

# Part B — 1D Array Problems

## Problem 17 — Reverse an Array

**Difficulty:** Easy

Reverse the elements of an array in place.

### Constraints

- 1 ≤ n ≤ 1000

### Input

The first line contains `n`.

The second line contains `n` integers.

### Output

Print the reversed array.

### Sample Input

```text
5
1 2 3 4 5
```

### Sample Output

```text
5 4 3 2 1
```

💡 **Hint:** Same two-pointer idea as Problem 1 — swap the ends and move inward.

---

## Problem 18 — Shrink Array by Deleting Values

**Difficulty:** Medium

Given an array and a list of values to delete, remove all occurrences of those values from the array.

### Constraints

- 1 ≤ n ≤ 1000
- 1 ≤ m ≤ 1000

### Input

The first line contains `n`.

The second line contains `n` integers.

The third line contains `m`.

The fourth line contains `m` integers representing the values to delete.

### Output

Print the new size.

Print the remaining array.

### Sample Input

```text
8
1 2 3 2 4 5 3 6
2
2 3
```

### Sample Output

```text
New size = 4
1 4 5 6
```

💡 **Hint:** Use a "write pointer": walk through the array once, and whenever you find a value that should be kept, write it to the next free slot.

---

## Problem 19 — Find the Middle Median

**Difficulty:** Medium

Given an array, sort it and print the middle value.

If the size is even, print the average of the two middle values.

### Constraints

- 1 ≤ n ≤ 1000

### Input

The first line contains `n`.

The second line contains `n` integers.

### Output

Print the median.

### Sample Input

```text
5
7 2 9 1 4
```

### Sample Output

```text
4
```

💡 **Hint:** Sort the array first (a simple sort like bubble or selection sort works fine here), then the median is just one or two lookups by index.

---

## Problem 20 — Partition Array Around X

**Difficulty:** Medium

Given an array and a value `X`, rearrange the array so that:

- All elements less than or equal to `X` come first.
- All elements greater than `X` come later.

The order inside each part does not need to stay the same.

### Constraints

- 1 ≤ n ≤ 1000

### Input

The first line contains `n`.

The second line contains `n` integers.

The third line contains `X`.

### Output

Print the partitioned array.

### Sample Input

```text
7
8 3 5 1 9 2 6
5
```

### Sample Output

```text
3 5 1 2 9 8 6
```

💡 **Hint:** This is the same partition step used in quicksort — two pointers closing in from opposite ends, swapping when the left pointer finds something too big and the right pointer finds something small enough.

---

## Problem 21 — Merge Two Sorted Arrays

**Difficulty:** Medium

Given two sorted arrays, merge them into one sorted array.

### Constraints

- 0 ≤ n, m ≤ 1000

### Input

The first line contains `n`.

The second line contains `n` sorted integers.

The third line contains `m`.

The fourth line contains `m` sorted integers.

### Output

Print the merged sorted array.

### Sample Input

```text
4
1 3 5 8
3
2 4 7
```

### Sample Output

```text
1 2 3 4 5 7 8
```

💡 **Hint:** Walk both arrays with one index each, always copying the smaller of the two current elements into the result, then mop up whichever array still has leftovers.

---

## Problem 22 — Longest Increasing or Decreasing Sequence

**Difficulty:** Medium

Given an array, find the length of the longest consecutive increasing sequence and the longest consecutive decreasing sequence.

Consecutive means the elements are next to each other in the array.

### Constraints

- 1 ≤ n ≤ 1000

### Input

The first line contains `n`.

The second line contains `n` integers.

### Output

Print the longest increasing length and the longest decreasing length.

### Sample Input

```text
8
1 2 3 2 1 0 5 6
```

### Sample Output

```text
Increasing = 3
Decreasing = 4
```

💡 **Hint:** Keep a running streak counter for each direction; reset it to 1 whenever the trend breaks, and track the best value seen so far.

---

## Problem 23 — Add Two Polynomials Using Arrays

**Difficulty:** Medium

Two arrays represent two polynomials.

For example:

```text
A = [3, 2, 5]
```

represents:

```text
3 + 2x + 5x^2
```

Given two polynomial arrays, add them and print the result coefficients.

### Constraints

- 0 ≤ d1, d2 ≤ 500

### Input

The first line contains degree `d1`.

The second line contains `d1 + 1` coefficients.

The third line contains degree `d2`.

The fourth line contains `d2 + 1` coefficients.

### Output

Print the coefficients of the sum polynomial.

### Sample Input

```text
2
3 2 5
3
1 4 0 7
```

### Sample Output

```text
4 6 5 7
```

💡 **Hint:** Pad the shorter polynomial with zero coefficients (conceptually) so you can add term-by-term up to the larger degree.

---

# Part C — 2D Array Problems

## Problem 24 — Swap Rows

**Difficulty:** Easy

Given a 2D array, swap two rows.

### Constraints

- 1 ≤ rows, cols ≤ 100

### Input

The first line contains `rows` and `cols`.

Then enter the matrix.

Then enter row numbers `r1` and `r2`.

### Output

Print the matrix after swapping the rows.

### Sample Input

```text
3 3
1 2 3
4 5 6
7 8 9
0 2
```

### Sample Output

```text
7 8 9
4 5 6
1 2 3
```

💡 **Hint:** Swap one column at a time across the two rows — no temporary row array needed.

---

## Problem 25 — Swap Columns

**Difficulty:** Easy

Given a 2D array, swap two columns.

### Constraints

- 1 ≤ rows, cols ≤ 100

### Input

The first line contains `rows` and `cols`.

Then enter the matrix.

Then enter column numbers `c1` and `c2`.

### Output

Print the matrix after swapping the columns.

### Sample Input

```text
3 3
1 2 3
4 5 6
7 8 9
0 2
```

### Sample Output

```text
3 2 1
6 5 4
9 8 7
```

💡 **Hint:** Mirror image of Problem 24 — loop over rows instead of columns.

---

## Problem 26 — Print Matrix in Spiral Order

**Difficulty:** Medium

Given an `N x N` matrix, print its elements in spiral order.

### Constraints

- 1 ≤ N ≤ 100

### Input

The first line contains `N`.

Then enter the matrix.

### Output

Print the elements in spiral order.

### Sample Input

```text
3
1 2 3
4 5 6
7 8 9
```

### Sample Output

```text
1 2 3 6 9 8 7 4 5
```

💡 **Hint:** Maintain four boundaries — `top`, `bottom`, `left`, `right` — and shrink them inward one side at a time (right, then down, then left, then up), checking the boundaries still make sense before each side.

---

## Problem 27 — Check if Matrix Contains Spiral Elements

**Difficulty:** Medium

Given an `N x N` matrix and an array of `N * N` integers, check whether the array is equal to the spiral order of the matrix.

### Constraints

- 1 ≤ N ≤ 100

### Input

The first line contains `N`.

Then enter the matrix.

Then enter `N * N` integers representing the expected spiral order.

### Output

Print `Yes` or `No`.

### Sample Input

```text
3
1 2 3
4 5 6
7 8 9
1 2 3 6 9 8 7 4 5
```

### Sample Output

```text
Yes
```

💡 **Hint:** Reuse the spiral traversal from Problem 26, but instead of printing, compare each visited element to the next expected value.

---

## Problem 28 — Maze Problem (Path Exists)

**Difficulty:** Medium

Given a maze represented by a 2D array:

- `0` means blocked cell.
- `1` means open cell.

Start from the top-left cell `(0, 0)` and try to reach the bottom-right cell `(rows - 1, cols - 1)`.

You can move:

- Down
- Right

### Constraints

- 1 ≤ rows, cols ≤ 100

### Input

The first line contains `rows` and `cols`.

Then enter the maze.

### Output

Print `Path Exists` or `No Path`.

### Sample Input

```text
4 4
1 1 0 0
0 1 1 0
0 0 1 1
0 0 0 1
```

### Sample Output

```text
Path Exists
```

💡 **Hint:** A cell has a path to the goal if it's open *and* (it IS the goal, or a path exists going down, or a path exists going right). That's the recursive case directly.

---

# Part D — Sorting, Searching, and More Recursion

## Problem 29 — Selection Sort

**Difficulty:** Easy

Write a function that sorts an array of integers in ascending order using selection sort: repeatedly find the minimum of the unsorted portion and move it to the front of that portion.

### Constraints

- 1 ≤ n ≤ 1000

### Input

The first line contains `n`.

The second line contains `n` integers.

### Output

Print the sorted array.

### Sample Input

```text
6
5 2 9 1 5 6
```

### Sample Output

```text
1 2 5 5 6 9
```

💡 **Hint:** For each position `i` from left to right, find the index of the smallest element in `a[i..n-1]` and swap it into position `i`.

---

## Problem 30 — Binary Search (Iteratively and Recursively)

**Difficulty:** Medium

Given a sorted array and a target value, write two functions that return the index of the target, or `-1` if it isn't present.

### Constraints

- 1 ≤ n ≤ 100,000
- The array is sorted in non-decreasing order.

### Input

The first line contains `n`.

The second line contains `n` sorted integers.

The third line contains the target value.

### Output

Print the index using:

1. Iterative solution
2. Recursive solution

### Sample Input

```text
6
1 3 5 7 9 11
7
```

### Sample Output

```text
Iterative = 3
Recursive = 3
```

💡 **Hint:** Keep `low` and `high` bounds. Compare the target to the middle element; if it doesn't match, discard the half of the array that can't contain it.

---

## Problem 31 — Matrix Transpose

**Difficulty:** Easy

Given an `rows x cols` matrix, print its transpose (rows become columns and vice versa).

### Constraints

- 1 ≤ rows, cols ≤ 100

### Input

The first line contains `rows` and `cols`.

Then enter the matrix.

### Output

Print the transposed matrix (`cols x rows`).

### Sample Input

```text
2 3
1 2 3
4 5 6
```

### Sample Output

```text
1 4
2 5
3 6
```

💡 **Hint:** The transposed element at `[j][i]` is simply the original element at `[i][j]`. Write into a separate result array — transposing "in place" only works neatly for square matrices.

---

## Problem 32 — Matrix Multiplication

**Difficulty:** Medium

Given an `n x m` matrix `A` and an `m x p` matrix `B`, compute their product `C = A x B`, an `n x p` matrix.

### Constraints

- 1 ≤ n, m, p ≤ 100

### Input

The first line contains `n`, `m`, and `p`.

Then enter matrix `A` (`n` rows of `m` integers).

Then enter matrix `B` (`m` rows of `p` integers).

### Output

Print the resulting `n x p` matrix.

### Sample Input

```text
2 3 2
1 2 3
4 5 6
7 8
9 10
11 12
```

### Sample Output

```text
58 64
139 154
```

💡 **Hint:** `C[i][j]` is the sum, over `k`, of `A[i][k] * B[k][j]` — three nested loops total.

---

## Problem 33 — Rotate Matrix 90 Degrees

**Difficulty:** Medium

Given an `N x N` matrix, rotate it 90 degrees clockwise, in place.

### Constraints

- 1 ≤ N ≤ 100

### Input

The first line contains `N`.

Then enter the matrix.

### Output

Print the rotated matrix.

### Sample Input

```text
3
1 2 3
4 5 6
7 8 9
```

### Sample Output

```text
7 4 1
8 5 2
9 6 3
```

💡 **Hint:** A 90° clockwise rotation can be done as two simpler steps: transpose the matrix, then reverse each row.

---

## Problem 34 — Pascal's Triangle

**Difficulty:** Medium

Print the first `n` rows of Pascal's Triangle. Each entry is the sum of the two entries above it; the edges of every row are 1.

### Constraints

- 1 ≤ n ≤ 30

### Input

One integer `n`.

### Output

Print `n` rows, each row's values separated by spaces.

### Sample Input

```text
5
```

### Sample Output

```text
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
```

💡 **Hint:** Build it directly with a 2D array: `triangle[row][0] = triangle[row][row] = 1`, and `triangle[row][k] = triangle[row-1][k-1] + triangle[row-1][k]` for everything in between. As a bonus, try writing a purely recursive function `C(row, k)` that computes a single entry without storing the whole triangle.

---

## Problem 35 — Count Paths in a Maze

**Difficulty:** Hard

This extends Problem 28. Given the same kind of maze (`0` = blocked, `1` = open), instead of just checking whether a path exists from `(0, 0)` to `(rows - 1, cols - 1)`, count **how many distinct paths** exist, moving only down or right.

### Constraints

- 1 ≤ rows, cols ≤ 20 (kept small because the path count can grow quickly)

### Input

The first line contains `rows` and `cols`.

Then enter the maze.

### Output

Print the number of distinct paths.

### Sample Input

```text
3 3
1 1 1
1 1 1
1 1 1
```

### Sample Output

```text
6
```

💡 **Hint:** Same recursive shape as Problem 28, but instead of returning a boolean with `||`, return `pathsFrom(down) + pathsFrom(right)`. The base case (reaching the goal) returns 1 instead of `true`.

---

## Problem 36 — Fast Exponentiation

**Difficulty:** Hard

Problem 11 computed `base^exp` with a loop that multiplies `exp` times. Here, write a recursive function that computes the same result much faster using the identity:

```text
base^exp = (base^(exp/2))^2            if exp is even
base^exp = base * (base^(exp/2))^2     if exp is odd     (integer division)
```

### Constraints

- -100 ≤ base ≤ 100
- 0 ≤ exp ≤ 1,000,000,000

### Input

Two integers: `base` and `exp`.

### Output

Print `base^exp`.

### Sample Input

```text
2 10
```

### Sample Output

```text
1024
```

💡 **Hint:** Compute the half-power once, store it in a variable, then square that variable — don't call the recursive function twice for the same half.
