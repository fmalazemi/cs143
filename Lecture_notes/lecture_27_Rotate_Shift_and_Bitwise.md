# CS143 — Rotating, Shifting, and Bitwise Operations

> **Course:** CS143 Introduction to C++ · **Instructor:** Dr. Fawaz Alazemi
> **Builds on:** arrays, loops, and integer types.

---

## Table of Contents

1. [Rotation Wraps, Shift Drops](#1-rotation-wraps-shift-drops)
2. [Rotate Left by One](#2-rotate-left-by-one)
3. [Rotate Right by One](#3-rotate-right-by-one)
4. [Shifting and Filling With Zero](#4-shifting-and-filling-with-zero)
5. [Moving by k Positions](#5-moving-by-k-positions)
6. [An Integer Is a Row of Bits](#6-an-integer-is-a-row-of-bits)
7. [The Six Bitwise Operators](#7-the-six-bitwise-operators)
8. [AND, OR, XOR Column by Column](#8-and-or-xor-column-by-column)
9. [The Shift Operators](#9-the-shift-operators)
10. [Shifting Is Multiplying and Dividing by 2](#10-shifting-is-multiplying-and-dividing-by-2)
11. [Useful Bit Tricks](#11-useful-bit-tricks)
12. [One Idea, Two Places](#12-one-idea-two-places)
13. [Common Mistakes](#13-common-mistakes)
14. [Practice Exercises](#14-practice-exercises)
15. [Summary](#15-summary)

---

## 1. Rotation Wraps, Shift Drops

Both operations move every value one place along. They differ only in what happens at the **two ends**.

**Rotation** — the value that falls off one end comes back at the other. Nothing is lost.

**Shift** — the value that falls off is lost, and a `0` fills the empty place.

```
   ROTATE LEFT · the 1 comes back around
        _______________________
       |                       v
     [ 1 ][ 2 ][ 3 ][ 4 ][ 5 ]
     result:  2  3  4  5  1


   SHIFT LEFT · the 1 is lost, a 0 arrives
     <--(1)
     [ 1 ][ 2 ][ 3 ][ 4 ][ 5 ][ 0 ] <-- 0 fills
      lost
     result:  2  3  4  5  0
```

Keep this distinction in mind: the same two words describe what happens to the **bits of an integer** in Part B.

---

## 2. Rotate Left by One

Save the first value, slide everyone left, then put the saved value at the end.

```cpp
int first = arr[0];

for (int i = 0; i < n - 1; i++) {
    arr[i] = arr[i + 1];    // pull the next one back
}

arr[n - 1] = first;         // wrap it around
```

```
before: 1 2 3 4 5
after : 2 3 4 5 1
```

- **Save `first` before the loop**, or it is overwritten immediately.
- The loop stops at `n - 2`, because it reads `arr[i + 1]`.

### A complete program

```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int n = 5;

    // rotate left by one
    int first = arr[0];
    for (int i = 0; i < n - 1; i++)
        arr[i] = arr[i + 1];
    arr[n - 1] = first;

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
```

**Output:**
```
2 3 4 5 1
```

---

## 3. Rotate Right by One

Save the last value, slide everyone right, then put the saved value at the front.

```cpp
int last = arr[n - 1];

for (int i = n - 1; i > 0; i--) {
    arr[i] = arr[i - 1];    // push the previous one forward
}

arr[0] = last;              // wrap it around
```

```
before: 1 2 3 4 5
after : 5 1 2 3 4
```

**Notice the loop runs backwards.** If it ran forwards, `arr[i-1]` would already have been overwritten, and every slot would end up holding the original `arr[0]`.

> The direction of the loop is the **opposite** of the direction of the move.

---

## 4. Shifting and Filling With Zero

A shift uses the **same loop** as the rotation. Only the final line changes.

### Shift left

```cpp
// exactly the rotation, but we do NOT save the first value
for (int i = 0; i < n - 1; i++) {
    arr[i] = arr[i + 1];
}

arr[n - 1] = 0;      // fill the empty place
```

```
before: 1 2 3 4 5
after : 2 3 4 5 0
```

### Shift right

```cpp
// run backwards, drop the last value
for (int i = n - 1; i > 0; i--) {
    arr[i] = arr[i - 1];
}

arr[0] = 0;          // fill the empty place
```

```
before: 1 2 3 4 5
after : 0 1 2 3 4
```

### Rotation vs shift

|  | Rotate left | Shift left |
|--|-------------|------------|
| Save first? | yes | no |
| Last slot gets | `first` | `0` |

All four operations, starting from `1 2 3 4 5`:

| Operation | Result |
|-----------|--------|
| rotate left | `2 3 4 5 1` |
| rotate right | `5 1 2 3 4` |
| shift left | `2 3 4 5 0` |
| shift right | `0 1 2 3 4` |

> A shift is a rotation that forgets.

---

## 5. Moving by k Positions

The clearest way is a **temporary array**: compute where each value belongs, then copy back.

### Rotate left by k

```cpp
int tmp[5];
k = k % n;                       // in case k >= n

for (int i = 0; i < n; i++)
    tmp[i] = arr[(i + k) % n];   // wrap with %

for (int i = 0; i < n; i++)
    arr[i] = tmp[i];
```

### Shift left by k, filling with zero

```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int n = 5, k = 2;
    int tmp[5];

    for (int i = 0; i < n; i++) {
        if (i + k < n)
            tmp[i] = arr[i + k];   // pull from the right
        else
            tmp[i] = 0;            // past the end -> 0
    }

    for (int i = 0; i < n; i++) arr[i] = tmp[i];

    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}
```

**Output:**
```
3 4 5 0 0
```

Values `1` and `2` are gone — a shift destroys them.

With `k = 2`, all four operations give:

```
start        : 1 2 3 4 5
rotate left  : 3 4 5 1 2
rotate right : 4 5 1 2 3
shift  left  : 3 4 5 0 0
shift  right : 0 0 1 2 3
```

**The `%` is the wrap.** A rotation uses `% n`; a shift replaces the wrap with a `0`.

A simpler alternative for small `k`: repeat the by-one rotation `k` times.

---

## 6. An Integer Is a Row of Bits

Inside the computer, an `int` is stored in **binary** — a row of `0`s and `1`s. Each position stands for a power of two.

```
   place value :  128  64  32  16   8   4   2   1
          5    :    0   0   0   0   0   1   0   1
          3    :    0   0   0   0   0   0   1   1
```

Check it: for `5`, the `4` column and the `1` column hold a `1`, and `4 + 1 = 5`.

Bitwise operators work on these columns, **one column at a time**.

---

## 7. The Six Bitwise Operators

| Operator | Name | A column gives 1 when… |
|----------|------|------------------------|
| `a & b` | AND | **both** bits are 1 |
| `a \| b` | OR | **at least one** bit is 1 |
| `a ^ b` | XOR | the bits are **different** |
| `~a` | NOT | the bit was 0 (it flips every bit) |
| `a << k` | left shift | — moves bits left, `0` fills in |
| `a >> k` | right shift | — moves bits right, bits fall off |

**Careful:** `&` is not `&&`, and `|` is not `||`. The single symbols work on **bits**; the double symbols work on **true/false**.

---

## 8. AND, OR, XOR Column by Column

```
   5 =  0  0  0  0  0  1  0  1
   3 =  0  0  0  0  0  0  1  1
   ---------------------------
   & =  0  0  0  0  0  0  0  1   = 1
   | =  0  0  0  0  0  1  1  1   = 7
   ^ =  0  0  0  0  0  1  1  0   = 6
```

Each column is decided on its own — the columns never talk to each other.

```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 5;    // 0101
    int y = 3;    // 0011

    cout << (x & y) << endl;   // 1   both bits 1
    cout << (x | y) << endl;   // 7   either bit 1
    cout << (x ^ y) << endl;   // 6   bits differ
    cout << (~x)    << endl;   // -6  every bit flipped
    return 0;
}
```

**Output:**
```
1
7
6
-6
```

**Why is `~5` equal to `-6`?** Flipping every bit also flips the leftmost bit, which C++ uses to mark a number as negative.

Always put bitwise expressions in brackets — `<<` binds more tightly than `&`.

---

## 9. The Shift Operators

The bits behave exactly like the values in a shifted array: they move along, the far ones **fall off**, and `0`s fill the gaps.

### Left shift: `a << k`

```
   5 =  0  0  0  0  0  1  0  1
              every bit moves one place left
  10 =  0  0  0  0  1  0  1  0
     ^                       ^
  top bit falls off      a 0 fills in
```

`5 << 1 = 10` — the value doubled.

### Right shift: `a >> k`

```
   20 >> 2  ->  5
   0001 0100  ->  0000 0101
```

Bits move right and fall off the end.

**Same word, same meaning:** the array shift and the bit shift both lose what falls off, and both fill with `0`.

---

## 10. Shifting Is Multiplying and Dividing by 2

```cpp
cout << (5 << 1) << endl;    // 10  = 5 * 2
cout << (5 << 2) << endl;    // 20  = 5 * 4
cout << (5 << 3) << endl;    // 40  = 5 * 8

cout << (20 >> 1) << endl;   // 10  = 20 / 2
cout << (20 >> 2) << endl;   // 5   = 20 / 4

// a lost bit means a lost remainder
cout << (7 >> 1) << endl;    // 3   (7 / 2 = 3)
```

**Output:**
```
10
20
40
10
5
3
```

| Shift | Same as |
|-------|---------|
| `a << k` | a × 2ᵏ |
| `a >> k` | a ÷ 2ᵏ |

Note that `7 >> 1` is `3`: the bit that fell off the end **was** the remainder.

---

## 11. Useful Bit Tricks

```cpp
int n = 12;      // 0000 1100

// is n even? test the lowest bit
if ((n & 1) == 0) cout << "even" << endl;

// read bit number 2 (counting from 0, right to left)
cout << ((n >> 2) & 1) << endl;    // 1

// turn ON bit 1
cout << (n | (1 << 1)) << endl;    // 14

// turn OFF bit 2
cout << (n & ~(1 << 2)) << endl;   // 8

// flip bit 0
cout << (n ^ (1 << 0)) << endl;    // 13
```

**Output:**
```
even
1
14
8
13
```

**The pattern:** `1 << k` builds a **mask** — a number with a single `1` at position `k`. Then:

- `|` the mask to **set** a bit.
- `& ~` the mask to **clear** a bit.
- `^` the mask to **flip** a bit.

---

## 12. One Idea, Two Places

The array shift and the bit shift are the same operation on different data.

|  | Array of ints | Bits of an int |
|--|---------------|----------------|
| Move left | loop: `arr[i] = arr[i+1]` | `a << 1` |
| Move right | loop: `arr[i] = arr[i-1]` | `a >> 1` |
| What falls off | is lost | is lost |
| What fills in | `0` | `0` |
| Rotation exists? | yes, you write it | not built in |

**The difference:** C++ gives you `<<` and `>>` for bits as a single fast instruction. For arrays, you write the loop yourself.

There is no built-in bit *rotation* operator — a bit rotation must be built from two shifts joined with an `|`.

---

## 13. Common Mistakes

**1. Not saving the end value in a rotation**

**Wrong:**
```cpp
for (int i = 0; i < n - 1; i++) arr[i] = arr[i + 1];
arr[n - 1] = arr[0];        // arr[0] was already overwritten
```

**Correct:**
```cpp
int first = arr[0];         // save it FIRST
for (int i = 0; i < n - 1; i++) arr[i] = arr[i + 1];
arr[n - 1] = first;
```

**Explanation:** the value you need is destroyed on the first pass of the loop.

**2. Looping the wrong way for a right shift**

**Wrong:**
```cpp
for (int i = 0; i < n - 1; i++) arr[i + 1] = arr[i];   // all become arr[0]
```

**Correct:**
```cpp
for (int i = n - 1; i > 0; i--) arr[i] = arr[i - 1];
```

**Explanation:** moving right requires walking from the right end backwards.

**3. Reading past the end**

**Wrong:**
```cpp
for (int i = 0; i < n; i++) arr[i] = arr[i + 1];   // arr[n] does not exist
```

**Correct:**
```cpp
for (int i = 0; i < n - 1; i++) arr[i] = arr[i + 1];
```

**Explanation:** if the loop reads `arr[i+1]`, then `i` must stop at `n - 2`.

**4. Writing `&&` instead of `&`**

**Wrong:**
```cpp
int result = 4 && 3;    // 1  (a true/false answer)
```

**Correct:**
```cpp
int result = 4 & 3;     // 0  (bit by bit)
```

**Explanation:** `&&` asks "are both non-zero?"; `&` compares each bit column.

**5. Forgetting brackets**

**Wrong:**
```cpp
cout << x & y;          // does not do what you expect
```

**Correct:**
```cpp
cout << (x & y);
```

**Explanation:** `<<` binds more tightly than `&`, so the expression groups the wrong way.

**6. Confusing a shift with a rotation**

**Wrong:**
```cpp
// expecting the lost value to come back after a shift
```

**Correct:**
```cpp
// use a rotation if you want to keep every value
```

**Explanation:** a shift always destroys data; a rotation never does.

---

## 14. Practice Exercises

Try each one before opening the solution.

**Exercise 1.** Start with `{10, 20, 30, 40}`. Write the array after a **rotate right by 1**, and after a **shift right by 1**.

<details>
<summary>Click to see solution</summary>

```
start        : 10 20 30 40
rotate right : 40 10 20 30
shift  right :  0 10 20 30
```

The rotation brings `40` around to the front; the shift loses it.
</details>

**Exercise 2.** Write the loop that shifts an array **left** by one and puts `0` in the last slot.

<details>
<summary>Click to see solution</summary>

```cpp
for (int i = 0; i < n - 1; i++)
    arr[i] = arr[i + 1];
arr[n - 1] = 0;
```

Identical to the rotation, except nothing is saved and the last slot gets `0`.
</details>

**Exercise 3.** Why must a **right** shift loop run backwards? Explain in one sentence.

<details>
<summary>Click to see solution</summary>

Because moving forwards would overwrite `arr[i-1]` before it has been copied, so every slot would end up holding the same value.
</details>

**Exercise 4.** Compute by hand, showing the bits: `6 & 3`, `6 | 3`, and `6 ^ 3`.

<details>
<summary>Click to see solution</summary>

```
6 = 0110
3 = 0011
-------------
& = 0010  = 2
| = 0111  = 7
^ = 0101  = 5
```
</details>

**Exercise 5.** What are `3 << 2` and `24 >> 3`? Give the value and the equivalent multiplication or division.

<details>
<summary>Click to see solution</summary>

```
3 << 2  = 12   (3 × 4)
24 >> 3 = 3    (24 ÷ 8)
```
</details>

**Exercise 6.** Write one expression that tests whether the integer `n` is **odd**, using a bitwise operator.

<details>
<summary>Click to see solution</summary>

```cpp
if (n & 1) {
    // n is odd
}
```

The lowest bit is `1` exactly when the number is odd.
</details>

---

## 15. Summary

### Key Concepts

- A **rotation** wraps the end value around; a **shift** loses it and fills with `0`.
- Bitwise operators work on one **bit column** at a time.
- A bit shift and an array shift are the same idea on different data.

### Important Points

1. Rotate left: save `arr[0]`, slide left, put it at the end. Rotate right: the mirror, looping **backwards**.
2. To shift, use the same loop but store `0` in the empty slot.
3. Moving by `k`: use a temporary array; `% n` provides the wrap for a rotation.
4. `&`, `|`, `^`, `~` are **not** `&&` and `||`. Compare `4 & 3 = 0` with `4 && 3 = 1`.
5. `a << k` multiplies by 2ᵏ; `a >> k` divides by 2ᵏ. Bits that fall off are lost, and `0`s fill in.
6. `1 << k` builds a mask: use `|` to set a bit, `& ~` to clear it, `^` to flip it.

### Quick Reference

```cpp
// ---- arrays (n elements) ----
int first = arr[0];                               // ROTATE LEFT
for (int i = 0; i < n-1; i++) arr[i] = arr[i+1];
arr[n-1] = first;

int last = arr[n-1];                              // ROTATE RIGHT
for (int i = n-1; i > 0; i--) arr[i] = arr[i-1];
arr[0] = last;

for (int i = 0; i < n-1; i++) arr[i] = arr[i+1];  // SHIFT LEFT
arr[n-1] = 0;

for (int i = n-1; i > 0; i--) arr[i] = arr[i-1];  // SHIFT RIGHT
arr[0] = 0;

// ---- bits ----
5 & 3      // 1     both bits 1
5 | 3      // 7     either bit 1
5 ^ 3      // 6     bits differ
~5         // -6    every bit flipped

5 << 1     // 10    = 5 * 2
20 >> 2    // 5     = 20 / 4

n & 1              // odd?
(n >> k) & 1       // read bit k
n |  (1 << k)      // set bit k
n & ~(1 << k)      // clear bit k
n ^  (1 << k)      // flip bit k
```

### The One Rule to Remember

A shift forgets. A rotation remembers.
