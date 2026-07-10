# CS143 — Solving the Maze Problem

> **Course:** CS143 Introduction to C++ · **Instructor:** Dr. Fawaz Alazemi
> **Builds on:** 2D arrays, functions, and recursion.

---

## Table of Contents

1. [The Problem](#1-the-problem)
2. [The Idea: Backtracking](#2-the-idea-backtracking)
3. [Four Directions From One Cell](#3-four-directions-from-one-cell)
4. [A Dead End, Undone](#4-a-dead-end-undone)
5. [The Base Cases](#5-the-base-cases)
6. [The Recursive Solver](#6-the-recursive-solver)
7. [The Complete Program](#7-the-complete-program)
8. [Tracing the Calls](#8-tracing-the-calls)
9. [Why Mark and Unmark](#9-why-mark-and-unmark)
10. [When There Is No Path](#10-when-there-is-no-path)
11. [Common Mistakes](#11-common-mistakes)
12. [Practice Exercises](#12-practice-exercises)
13. [Summary](#13-summary)

---

## 1. The Problem

Given a grid of open cells and walls, find a path from the **top-left** corner to the **bottom-right** corner. You may move only up, down, left, or right — never diagonally.

We store the maze in a 2D array, where `1` means the cell is **open** and `0` means it is a **wall**:

```cpp
int maze[5][5] = {
    {1, 1, 1, 0, 0},
    {1, 0, 1, 0, 0},
    {0, 0, 1, 1, 1},
    {0, 0, 0, 0, 1},
    {0, 0, 0, 0, 1}
};
```

Drawn as a picture (`#` is a wall, `.` is open):

```
        col:  0   1   2   3   4
      row 0:  S   .   .   #   #
      row 1:  .   #   .   #   #
      row 2:  #   #   .   .   .
      row 3:  #   #   #   #   .
      row 4:  #   #   #   #   E

      S = start (0,0)      E = end (4,4)
```

We want a second grid, `solution`, in which the cells of a path from `(0,0)` to `(4,4)` are marked with `1`.

---

## 2. The Idea: Backtracking

Imagine walking through a real maze with a piece of chalk. At each open cell you mark your path. If you reach a dead end, you rub out the mark and step back to try a different direction.

That is **backtracking**: *try a direction; if it leads nowhere, undo the move and try another.*

At every cell, the solver asks four questions:

1. Am I outside the maze? → give up on this cell.
2. Is this a wall? → give up on this cell.
3. Have I been here already? → give up on this cell.
4. Am I at the end? → **success!**

Otherwise, it **marks** the cell and tries **down**, **right**, **up**, **left** in turn. If all four fail, it **unmarks** the cell and reports failure to whoever called it. That unmarking is the backtracking step.

---

## 3. Four Directions From One Cell

From a cell at `(row, col)`, the four neighbours are found by changing one index by one:

```
                    (r-1, c)
                        ▲
                        │ up
                        │
      (r, c-1) ◄──── (r, c) ────► (r, c+1)
                 left   │   right
                        │ down
                        ▼
                    (r+1, c)
```

| Direction | Call |
|-----------|------|
| down | `solve(r + 1, c)` |
| right | `solve(r, c + 1)` |
| up | `solve(r - 1, c)` |
| left | `solve(r, c - 1)` |

We will always try them in this order: **down, right, up, left**. A different order still finds a path, but possibly a different one.

---

## 4. A Dead End, Undone

In our maze, the very first move is a dead end — which makes it a perfect example.

From the start `(0,0)`, the solver first tries **down** into `(1,0)`. That cell is open, so it gets marked. But from `(1,0)`:

- **down** → `(2,0)` is a wall
- **right** → `(1,1)` is a wall
- **up** → `(0,0)` is already visited
- **left** → outside the maze

All four fail, so `(1,0)` is **unmarked** and the solver returns to `(0,0)`, which then tries **right** instead.

```
  1. mark (1,0)        2. all four fail       3. unmark, go right
     S  .                 S  .                   S  ✓
     ✓  #                 ✗  #                   .  #
     #  #                 #  #                   #  #
```

Backtracking is simply *removing a mark that led nowhere*.

---

## 5. The Base Cases

Every recursive function needs base cases. Ours has four — three failures and one success.

| Condition | Meaning | Return |
|-----------|---------|--------|
| `r < 0 \|\| r >= N \|\| c < 0 \|\| c >= N` | stepped outside the maze | `false` |
| `maze[r][c] == 0` | this cell is a wall | `false` |
| `solution[r][c] == 1` | already on our path | `false` |
| `r == N-1 && c == N-1` | we reached the end | `true` |

The third check is what stops the solver from walking in circles forever.

---

## 6. The Recursive Solver

```cpp
bool solve(int r, int c) {
    // 1. outside the maze?
    if (r < 0 || r >= N || c < 0 || c >= N)
        return false;
    // 2. a wall?
    if (maze[r][c] == 0)     return false;
    // 3. already visited?
    if (solution[r][c] == 1) return false;

    solution[r][c] = 1;          // mark this cell

    // 4. reached the end?
    if (r == N - 1 && c == N - 1)
        return true;

    // try the four directions
    if (solve(r + 1, c)) return true;   // down
    if (solve(r, c + 1)) return true;   // right
    if (solve(r - 1, c)) return true;   // up
    if (solve(r, c - 1)) return true;   // left

    solution[r][c] = 0;          // BACKTRACK
    return false;
}
```

Reading it in order:

- The three **failure** checks come first, before we touch anything.
- We **mark** the cell before exploring further.
- If any direction returns `true`, we stop immediately and pass `true` up the chain.
- If **all four** fail, we **unmark** the cell and return `false`.

That last line — `solution[r][c] = 0;` — is the whole idea of backtracking, in one statement.

---

## 7. The Complete Program

```cpp
#include <iostream>
using namespace std;

const int N = 5;

int maze[N][N] = {
    {1, 1, 1, 0, 0},
    {1, 0, 1, 0, 0},
    {0, 0, 1, 1, 1},
    {0, 0, 0, 0, 1},
    {0, 0, 0, 0, 1}
};
int solution[N][N] = {0};   // all zeros

bool solve(int r, int c) {
    if (r < 0 || r >= N || c < 0 || c >= N) return false;
    if (maze[r][c] == 0)      return false;
    if (solution[r][c] == 1)  return false;

    solution[r][c] = 1;
    if (r == N - 1 && c == N - 1) return true;

    if (solve(r + 1, c)) return true;
    if (solve(r, c + 1)) return true;
    if (solve(r - 1, c)) return true;
    if (solve(r, c - 1)) return true;

    solution[r][c] = 0;      // backtrack
    return false;
}

int main() {
    if (solve(0, 0)) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                cout << solution[i][j] << " ";
            cout << endl;
        }
    } else {
        cout << "No solution" << endl;
    }
    return 0;
}
```

**Output:**
```
1 1 1 0 0
0 0 1 0 0
0 0 1 1 1
0 0 0 0 1
0 0 0 0 1
```

The `1`s show the path found. Notice that cell `(1,0)` prints as `0` even though the maze has an open cell there — it was tried, it failed, and it was **unmarked**.

---

## 8. Tracing the Calls

```
solve(0,0)  mark
  solve(1,0)  mark            (down)
    all four directions fail
    UNMARK (1,0)              <-- backtrack
  solve(0,1)  mark            (right)
    solve(0,2)  mark
      solve(1,2)  mark
        solve(2,2)  mark
          solve(2,3)  mark
            solve(2,4)  mark
              solve(3,4)  mark
                solve(4,4)  END -> true
```

Three things to notice:

- `(1,0)` is marked, explored, and then unmarked — the only backtrack in this maze.
- Once `solve(4,4)` returns `true`, every call above it returns `true` immediately, without unmarking anything.
- The path therefore survives in the `solution` grid. **Success travels back up the chain of calls.**

---

## 9. Why Mark and Unmark

**Without marking**, the solver moves right, then left, then right, then left… forever. It revisits the same cells endlessly until the program runs out of memory and crashes. The check `solution[r][c] == 1` prevents this.

**Without unmarking**, dead ends would stay marked and appear in the final answer, as though they were part of the path. Our `(1,0)` would wrongly show up as a `1`.

So, in one line:

> **Mark** to avoid loops. **Unmark** to erase wrong turns.

---

## 10. When There Is No Path

If we seal off the exit by making `(3,4)` a wall, no path can reach `(4,4)`:

```cpp
int maze[N][N] = {
    {1, 1, 1, 0, 0},
    {1, 0, 1, 0, 0},
    {0, 0, 1, 1, 1},
    {0, 0, 0, 0, 0},   // (3,4) is now a wall
    {0, 0, 0, 0, 1}
};
```

**Output:**
```
No solution
```

The solver explores every reachable cell, backtracks out of each one, and finally `solve(0, 0)` itself returns `false`. Because every cell is unmarked on the way out, the `solution` grid ends up all zeros again — exactly as it started.

---

## 11. Common Mistakes

**1. Forgetting the bounds check**

**Wrong:**
```cpp
if (maze[r][c] == 0) return false;   // r might be -1
```

**Correct:**
```cpp
if (r < 0 || r >= N || c < 0 || c >= N) return false;
if (maze[r][c] == 0) return false;
```

**Explanation:** always test `r` and `c` **before** using them to index the array.

**2. No visited check**

**Wrong:**
```cpp
// no test for solution[r][c] == 1
```

**Correct:**
```cpp
if (solution[r][c] == 1) return false;
```

**Explanation:** without it, the solver bounces between two open cells forever — infinite recursion and a stack overflow.

**3. Forgetting to unmark**

**Wrong:**
```cpp
// ...all four directions failed...
return false;                 // cell left marked
```

**Correct:**
```cpp
solution[r][c] = 0;           // erase the dead end
return false;
```

**Explanation:** dead ends would otherwise appear in the final answer.

**4. Unmarking after success**

**Wrong:**
```cpp
if (solve(r + 1, c)) { solution[r][c] = 0; return true; }
```

**Correct:**
```cpp
if (solve(r + 1, c)) return true;
// unmark only after ALL four fail
```

**Explanation:** unmarking a successful cell erases the very path you found.

**5. Ignoring the return value**

**Wrong:**
```cpp
solve(r + 1, c);      // the answer is thrown away
```

**Correct:**
```cpp
if (solve(r + 1, c)) return true;
```

**Explanation:** the recursive call reports whether it found the exit; you must act on it.

**6. Checking the end before marking**

**Wrong:**
```cpp
if (r == N-1 && c == N-1) return true;   // end cell never marked
solution[r][c] = 1;
```

**Correct:**
```cpp
solution[r][c] = 1;
if (r == N-1 && c == N-1) return true;
```

**Explanation:** the exit belongs on the path, so mark it before returning.

**Order matters:** bounds → wall → visited → mark → end check → explore → unmark.

---

## 12. Practice Exercises

Try each one before opening the solution.

**Exercise 1.** Write the three **failure** base cases of `solve(r, c)` in C++.

<details>
<summary>Click to see solution</summary>

```cpp
if (r < 0 || r >= N || c < 0 || c >= N)
    return false;                       // outside
if (maze[r][c] == 0)     return false;  // wall
if (solution[r][c] == 1) return false;  // visited
```
</details>

**Exercise 2.** Explain in one sentence why the line `solution[r][c] = 0;` appears at the **end** of the function.

<details>
<summary>Click to see solution</summary>

Because we only reach that line when **all four** directions have failed, which means this cell is part of a dead end and must be erased from the path.
</details>

**Exercise 3.** What happens if you remove the check `if (solution[r][c] == 1) return false;`?

<details>
<summary>Click to see solution</summary>

The solver would move back and forth between two open cells forever — infinite recursion, ending in a stack overflow crash.
</details>

**Exercise 4.** Change the solver to try the directions in the order **right, down, left, up**. Write the four calls.

<details>
<summary>Click to see solution</summary>

```cpp
if (solve(r, c + 1)) return true;   // right
if (solve(r + 1, c)) return true;   // down
if (solve(r, c - 1)) return true;   // left
if (solve(r - 1, c)) return true;   // up
```

A different order may find a different valid path.
</details>

**Exercise 5.** Modify the program to also **count** how many cells are on the final path.

<details>
<summary>Click to see solution</summary>

```cpp
int count = 0;
for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
        if (solution[i][j] == 1) count++;
cout << "Path length: " << count << endl;
```

For the maze in these notes, the answer is 9.
</details>

**Exercise 6.** Given the maze below, is there a path from `(0,0)` to `(2,2)`? Explain.

```
1 0 0
1 0 0
1 1 1
```

<details>
<summary>Click to see solution</summary>

**Yes.** Go down from `(0,0)` to `(1,0)` and `(2,0)`, then right along the bottom row to `(2,1)` and `(2,2)`.
</details>

---

## 13. Summary

### Key Concepts

- A maze is a **2D array**: `1` is open, `0` is a wall.
- **Backtracking** means: try a direction, and if it fails, undo the move and try another.
- The solver is a recursive function returning `bool` — did this cell lead to the exit?

### Important Points

1. Three failure base cases (outside, wall, visited) and one success case (the end).
2. Check the bounds **before** indexing the array.
3. **Mark** a cell before exploring, to avoid walking in circles.
4. **Unmark** it only when all four directions fail, to erase dead ends.
5. Success returns `true` all the way up the chain of calls, so the path survives.
6. If no path exists, every cell is unmarked and the program reports `No solution`.

### Quick Reference

```cpp
bool solve(int r, int c) {
    if (r < 0 || r >= N || c < 0 || c >= N) return false;  // outside
    if (maze[r][c] == 0)     return false;                 // wall
    if (solution[r][c] == 1) return false;                 // visited

    solution[r][c] = 1;                                    // mark
    if (r == N-1 && c == N-1) return true;                 // success

    if (solve(r+1, c)) return true;                        // down
    if (solve(r, c+1)) return true;                        // right
    if (solve(r-1, c)) return true;                        // up
    if (solve(r, c-1)) return true;                        // left

    solution[r][c] = 0;                                    // backtrack
    return false;
}
```

### The One Rule to Remember

Mark the cell on the way in, and unmark it on the way out **only if every direction failed**. That one pair of lines turns "try everything" into backtracking.
