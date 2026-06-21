# C++ Practice Problems — Solutions

Matches `problems.md` problem-for-problem (Problems 1–36). All solutions follow the same rules as the problem set: `std::string` is allowed for text, but no other STL containers, no explicit pointers, and no `<cmath>`.

```cpp
#include <iostream>
using namespace std;
```
is assumed at the top of every program below. Solutions that work with text also add `#include <string>`.

A few solutions include a **Note** flagging a deliberate teaching tradeoff or a bonus extension.

---

## Solution 1 — Palindrome Recursively and Iteratively

```cpp
#include <iostream>
#include <string>
using namespace std;

bool isPalindromeIterative(const string &s) {
    int left = 0;
    int right = (int)s.length() - 1;

    while (left < right) {
        if (s[left] != s[right]) {
            return false;
        }
        left++;
        right--;
    }

    return true;
}

bool isPalindromeRecursive(const string &s, int left, int right) {
    if (left >= right) {
        return true;
    }

    if (s[left] != s[right]) {
        return false;
    }

    return isPalindromeRecursive(s, left + 1, right - 1);
}

int main() {
    string s;
    cin >> s;

    if (isPalindromeIterative(s)) {
        cout << "Iterative: Palindrome" << endl;
    } else {
        cout << "Iterative: Not Palindrome" << endl;
    }

    if (isPalindromeRecursive(s, 0, (int)s.length() - 1)) {
        cout << "Recursive: Palindrome" << endl;
    } else {
        cout << "Recursive: Not Palindrome" << endl;
    }

    return 0;
}
```

---

## Solution 2 — Is Prime

```cpp
#include <iostream>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }

    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    int n;
    cin >> n;

    if (isPrime(n)) {
        cout << "Prime" << endl;
    } else {
        cout << "Not Prime" << endl;
    }

    return 0;
}
```

**Note:** you only ever need to check divisors up to `sqrt(n)` — change the loop condition to `i * i <= n` to check far fewer divisors, without needing `<cmath>`.

---

## Solution 3 — Find Remainder Without `*`, `/`, or `%` Recursively

```cpp
#include <iostream>
using namespace std;

int remainderRecursive(int a, int b) {
    if (a < b) {
        return a;
    }

    return remainderRecursive(a - b, b);
}

int main() {
    int a, b;
    cin >> a >> b;

    cout << remainderRecursive(a, b) << endl;

    return 0;
}
```

---

## Solution 4 — Check if Two Words Are Anagrams

```cpp
#include <iostream>
#include <string>
using namespace std;

bool areAnagrams(const string &a, const string &b) {
    if (a.length() != b.length()) {
        return false;
    }

    int freqA[26];
    int freqB[26];

    for (int i = 0; i < 26; i++) {
        freqA[i] = 0;
        freqB[i] = 0;
    }

    for (int i = 0; i < (int)a.length(); i++) {
        freqA[a[i] - 'a']++;
    }

    for (int i = 0; i < (int)b.length(); i++) {
        freqB[b[i] - 'a']++;
    }

    for (int j = 0; j < 26; j++) {
        if (freqA[j] != freqB[j]) {
            return false;
        }
    }

    return true;
}

int main() {
    string a, b;

    cin >> a >> b;

    if (areAnagrams(a, b)) {
        cout << "Anagrams" << endl;
    } else {
        cout << "Not Anagrams" << endl;
    }

    return 0;
}
```

---

## Solution 5 — Count Words in Text

```cpp
#include <iostream>
#include <string>
using namespace std;

bool isSpace(char c) {
    return c == ' ' || c == '\t' || c == '\n';
}

int countWords(const string &text) {
    int count = 0;
    bool insideWord = false;

    for (int i = 0; i < (int)text.length(); i++) {
        if (!isSpace(text[i]) && !insideWord) {
            count++;
            insideWord = true;
        } else if (isSpace(text[i])) {
            insideWord = false;
        }
    }

    return count;
}

int main() {
    string text;

    getline(cin, text);

    cout << countWords(text) << endl;

    return 0;
}
```

---

## Solution 6 — Check if Array Is Sorted

```cpp
#include <iostream>
using namespace std;

bool isSorted(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
            return false;
        }
    }

    return true;
}

int main() {
    int n;
    int a[1000];

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (isSorted(a, n)) {
        cout << "Sorted" << endl;
    } else {
        cout << "Not Sorted" << endl;
    }

    return 0;
}
```

---

## Solution 7 — Find Maximum, Minimum, and Average

```cpp
#include <iostream>
using namespace std;

int main() {
    int n;
    int a[1000];

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int maxValue = a[0];
    int minValue = a[0];
    int sum = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] > maxValue) {
            maxValue = a[i];
        }

        if (a[i] < minValue) {
            minValue = a[i];
        }

        sum += a[i];
    }

    double avg = sum / 1.0 / n;

    cout << "Max = " << maxValue << endl;
    cout << "Min = " << minValue << endl;
    cout << "Avg = " << avg << endl;

    return 0;
}
```

---

## Solution 8 — Two Indices Add to X

```cpp
#include <iostream>
using namespace std;

bool twoSum(int a[], int n, int x) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] + a[j] == x) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    int n, x;
    int a[1000];

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cin >> x;

    if (twoSum(a, n, x)) {
        cout << "Found" << endl;
    } else {
        cout << "Not Found" << endl;
    }

    return 0;
}
```

**Note (bonus):** sorting the array first lets you find a pair using a two-pointer sweep instead of nested loops, at the cost of losing the original index order.

---

## Solution 9 — Three Indices Add to X

```cpp
#include <iostream>
using namespace std;

bool threeSum(int a[], int n, int x) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (a[i] + a[j] + a[k] == x) {
                    return true;
                }
            }
        }
    }

    return false;
}

int main() {
    int n, x;
    int a[1000];

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cin >> x;

    if (threeSum(a, n, x)) {
        cout << "Found" << endl;
    } else {
        cout << "Not Found" << endl;
    }

    return 0;
}
```

---

## Solution 10 — Factorial Recursively and Iteratively

```cpp
#include <iostream>
using namespace std;

long long factorialIterative(int n) {
    long long result = 1;

    for (int i = 2; i <= n; i++) {
        result = result * i;
    }

    return result;
}

long long factorialRecursive(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }

    return n * factorialRecursive(n - 1);
}

int main() {
    int n;
    cin >> n;

    cout << "Iterative = " << factorialIterative(n) << endl;
    cout << "Recursive = " << factorialRecursive(n) << endl;

    return 0;
}
```

---

## Solution 11 — Power Recursively and Iteratively

```cpp
#include <iostream>
using namespace std;

long long powerIterative(int base, int exp) {
    long long result = 1;

    for (int i = 0; i < exp; i++) {
        result = result * base;
    }

    return result;
}

long long powerRecursive(int base, int exp) {
    if (exp == 0) {
        return 1;
    }

    return base * powerRecursive(base, exp - 1);
}

int main() {
    int base, exp;
    cin >> base >> exp;

    cout << "Iterative = " << powerIterative(base, exp) << endl;
    cout << "Recursive = " << powerRecursive(base, exp) << endl;

    return 0;
}
```

**Note:** see Problem 36 for a different way to compute the same result.

---

## Solution 12 — GCD

```cpp
#include <iostream>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int main() {
    int a, b;
    cin >> a >> b;

    cout << gcd(a, b) << endl;

    return 0;
}
```

---

## Solution 13 — LCM

```cpp
#include <iostream>
using namespace std;

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long r = a % b;
        a = b;
        b = r;
    }

    return a;
}

long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}

int main() {
    long long a, b;
    cin >> a >> b;

    cout << lcm(a, b) << endl;

    return 0;
}
```

**Fixed from the original version:** the original used `int` throughout. With `a, b` up to 1,000,000, `a / gcd(a, b) * b` can land close to `10^12`, which silently overflows a 32-bit `int`. Switching `gcd`/`lcm` and the `main` variables to `long long` removes that ceiling.

---

## Solution 14 — Reverse Integer Iteratively and Recursively

```cpp
#include <iostream>
using namespace std;

int reverseIterative(int n) {
    int reversed = 0;

    while (n > 0) {
        int digit = n % 10;
        reversed = reversed * 10 + digit;
        n = n / 10;
    }

    return reversed;
}

int reverseRecursiveHelper(int n, int reversed) {
    if (n == 0) {
        return reversed;
    }

    int digit = n % 10;
    return reverseRecursiveHelper(n / 10, reversed * 10 + digit);
}

int reverseRecursive(int n) {
    return reverseRecursiveHelper(n, 0);
}

int main() {
    int n;
    cin >> n;

    cout << "Iterative = " << reverseIterative(n) << endl;
    cout << "Recursive = " << reverseRecursive(n) << endl;

    return 0;
}
```

**Note:** this implementation assumes `n` is non-negative (see Constraints) — both loops terminate immediately on a negative `n` and silently return 0, so negative input is out of scope rather than handled.

---

## Solution 15 — Largest Sum of Digits in Array

```cpp
#include <iostream>
using namespace std;

int digitSum(int n) {
    if (n < 0) {
        n = -n;
    }

    if (n == 0) {
        return 0;
    }

    int sum = 0;

    while (n > 0) {
        sum += n % 10;
        n = n / 10;
    }

    return sum;
}

int main() {
    int n;
    int a[1000];

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int bestNumber = a[0];
    int bestSum = digitSum(a[0]);

    for (int i = 1; i < n; i++) {
        int currentSum = digitSum(a[i]);

        if (currentSum > bestSum) {
            bestSum = currentSum;
            bestNumber = a[i];
        }
    }

    cout << bestNumber << endl;

    return 0;
}
```

---

## Solution 16 — Fibonacci Recursively and Iteratively

```cpp
#include <iostream>
using namespace std;

long long fibonacciRecursive(int n) {
    if (n == 0) {
        return 0;
    }

    if (n == 1) {
        return 1;
    }

    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

long long fibonacciIterative(int n) {
    if (n == 0) {
        return 0;
    }

    if (n == 1) {
        return 1;
    }

    long long a = 0;
    long long b = 1;
    long long c = 0;

    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }

    return b;
}

int main() {
    int n;
    cin >> n;

    cout << "Iterative = " << fibonacciIterative(n) << endl;
    cout << "Recursive = " << fibonacciRecursive(n) << endl;

    return 0;
}
```

**Fixed from the original version:** the original defined `fibonacciIterative` but never called it, and `main` only printed the recursive result — so the problem's own "print using both" requirement wasn't actually met. The problem statement and solution above are now aligned to print both.

---

# Part B — 1D Array Problems

## Solution 17 — Reverse an Array

```cpp
#include <iostream>
using namespace std;

void reverseArray(int a[], int n) {
    int left = 0;
    int right = n - 1;

    while (left < right) {
        int temp = a[left];
        a[left] = a[right];
        a[right] = temp;

        left++;
        right--;
    }
}

int main() {
    int n;
    int a[1000];

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    reverseArray(a, n);

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    cout << endl;

    return 0;
}
```

---

## Solution 18 — Shrink Array by Deleting Values

```cpp
#include <iostream>
using namespace std;

bool shouldDelete(int value, int deleteValues[], int m) {
    for (int i = 0; i < m; i++) {
        if (value == deleteValues[i]) {
            return true;
        }
    }

    return false;
}

int shrinkArray(int a[], int n, int deleteValues[], int m) {
    int newSize = 0;

    for (int i = 0; i < n; i++) {
        if (!shouldDelete(a[i], deleteValues, m)) {
            a[newSize] = a[i];
            newSize++;
        }
    }

    return newSize;
}

int main() {
    int n, m;
    int a[1000];
    int deleteValues[1000];

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cin >> m;

    for (int i = 0; i < m; i++) {
        cin >> deleteValues[i];
    }

    int newSize = shrinkArray(a, n, deleteValues, m);

    cout << "New size = " << newSize << endl;

    for (int i = 0; i < newSize; i++) {
        cout << a[i] << " ";
    }

    cout << endl;

    return 0;
}
```

---

## Solution 19 — Find the Middle Median

```cpp
#include <iostream>
using namespace std;

void sortArray(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    int a[1000];

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sortArray(a, n);

    if (n % 2 == 1) {
        cout << a[n / 2] << endl;
    } else {
        double median = (a[n / 2 - 1] + a[n / 2]) / 2.0;
        cout << median << endl;
    }

    return 0;
}
```

**Note:** sorting is done here with a simple bubble sort (see Problem 29 for selection sort as another straightforward option).

---

## Solution 20 — Partition Array Around X

```cpp
#include <iostream>
using namespace std;

void partitionArray(int a[], int n, int x) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        while (left <= right && a[left] <= x) {
            left++;
        }

        while (left <= right && a[right] > x) {
            right--;
        }

        if (left < right) {
            int temp = a[left];
            a[left] = a[right];
            a[right] = temp;

            left++;
            right--;
        }
    }
}

int main() {
    int n, x;
    int a[1000];

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cin >> x;

    partitionArray(a, n, x);

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    cout << endl;

    return 0;
}
```

---

## Solution 21 — Merge Two Sorted Arrays

```cpp
#include <iostream>
using namespace std;

void mergeSortedArrays(int a[], int n, int b[], int m, int result[]) {
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < n && j < m) {
        if (a[i] <= b[j]) {
            result[k] = a[i];
            i++;
        } else {
            result[k] = b[j];
            j++;
        }

        k++;
    }

    while (i < n) {
        result[k] = a[i];
        i++;
        k++;
    }

    while (j < m) {
        result[k] = b[j];
        j++;
        k++;
    }
}

int main() {
    int n, m;
    int a[1000], b[1000], result[2000];

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cin >> m;

    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    mergeSortedArrays(a, n, b, m, result);

    for (int i = 0; i < n + m; i++) {
        cout << result[i] << " ";
    }

    cout << endl;

    return 0;
}
```

---

## Solution 22 — Longest Increasing or Decreasing Sequence

```cpp
#include <iostream>
using namespace std;

int main() {
    int n;
    int a[1000];

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int longestInc = 1;
    int longestDec = 1;
    int currentInc = 1;
    int currentDec = 1;

    for (int i = 1; i < n; i++) {
        if (a[i] > a[i - 1]) {
            currentInc++;
        } else {
            currentInc = 1;
        }

        if (a[i] < a[i - 1]) {
            currentDec++;
        } else {
            currentDec = 1;
        }

        if (currentInc > longestInc) {
            longestInc = currentInc;
        }

        if (currentDec > longestDec) {
            longestDec = currentDec;
        }
    }

    cout << "Increasing = " << longestInc << endl;
    cout << "Decreasing = " << longestDec << endl;

    return 0;
}
```

---

## Solution 23 — Add Two Polynomials Using Arrays

```cpp
#include <iostream>
using namespace std;

int main() {
    int d1, d2;
    int p1[1000], p2[1000], sum[1000];

    cin >> d1;

    for (int i = 0; i <= d1; i++) {
        cin >> p1[i];
    }

    cin >> d2;

    for (int i = 0; i <= d2; i++) {
        cin >> p2[i];
    }

    int maxDegree;

    if (d1 > d2) {
        maxDegree = d1;
    } else {
        maxDegree = d2;
    }

    for (int i = 0; i <= maxDegree; i++) {
        int c1 = 0;
        int c2 = 0;

        if (i <= d1) {
            c1 = p1[i];
        }

        if (i <= d2) {
            c2 = p2[i];
        }

        sum[i] = c1 + c2;
    }

    for (int i = 0; i <= maxDegree; i++) {
        cout << sum[i] << " ";
    }

    cout << endl;

    return 0;
}
```

---

# Part C — 2D Array Problems

## Solution 24 — Swap Rows

```cpp
#include <iostream>
using namespace std;

int main() {
    int rows, cols;
    int a[100][100];

    cin >> rows >> cols;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> a[i][j];
        }
    }

    int r1, r2;
    cin >> r1 >> r2;

    for (int j = 0; j < cols; j++) {
        int temp = a[r1][j];
        a[r1][j] = a[r2][j];
        a[r2][j] = temp;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
```

---

## Solution 25 — Swap Columns

```cpp
#include <iostream>
using namespace std;

int main() {
    int rows, cols;
    int a[100][100];

    cin >> rows >> cols;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> a[i][j];
        }
    }

    int c1, c2;
    cin >> c1 >> c2;

    for (int i = 0; i < rows; i++) {
        int temp = a[i][c1];
        a[i][c1] = a[i][c2];
        a[i][c2] = temp;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
```

---

## Solution 26 — Print Matrix in Spiral Order

```cpp
#include <iostream>
using namespace std;

int main() {
    int n;
    int a[100][100];

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    int top = 0;
    int bottom = n - 1;
    int left = 0;
    int right = n - 1;

    while (top <= bottom && left <= right) {
        for (int j = left; j <= right; j++) {
            cout << a[top][j] << " ";
        }
        top++;

        for (int i = top; i <= bottom; i++) {
            cout << a[i][right] << " ";
        }
        right--;

        if (top <= bottom) {
            for (int j = right; j >= left; j--) {
                cout << a[bottom][j] << " ";
            }
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                cout << a[i][left] << " ";
            }
            left++;
        }
    }

    cout << endl;

    return 0;
}
```

---

## Solution 27 — Check if Matrix Contains Spiral Elements

```cpp
#include <iostream>
using namespace std;

int main() {
    int n;
    int a[100][100];
    int expected[10000];

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n * n; i++) {
        cin >> expected[i];
    }

    int top = 0;
    int bottom = n - 1;
    int left = 0;
    int right = n - 1;
    int index = 0;
    bool ok = true;

    while (top <= bottom && left <= right) {
        for (int j = left; j <= right; j++) {
            if (a[top][j] != expected[index]) {
                ok = false;
            }
            index++;
        }
        top++;

        for (int i = top; i <= bottom; i++) {
            if (a[i][right] != expected[index]) {
                ok = false;
            }
            index++;
        }
        right--;

        if (top <= bottom) {
            for (int j = right; j >= left; j--) {
                if (a[bottom][j] != expected[index]) {
                    ok = false;
                }
                index++;
            }
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                if (a[i][left] != expected[index]) {
                    ok = false;
                }
                index++;
            }
            left++;
        }
    }

    if (ok) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
```

---

## Solution 28 — Maze Problem (Path Exists)

```cpp
#include <iostream>
using namespace std;

bool pathExists(int maze[][100], int row, int col, int rows, int cols) {
    if (row >= rows || col >= cols) {
        return false;
    }

    if (maze[row][col] == 0) {
        return false;
    }

    if (row == rows - 1 && col == cols - 1) {
        return true;
    }

    bool goDown = pathExists(maze, row + 1, col, rows, cols);
    bool goRight = pathExists(maze, row, col + 1, rows, cols);

    return goDown || goRight;
}

int main() {
    int rows, cols;
    int maze[100][100];

    cin >> rows >> cols;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> maze[i][j];
        }
    }

    if (pathExists(maze, 0, 0, rows, cols)) {
        cout << "Path Exists" << endl;
    } else {
        cout << "No Path" << endl;
    }

    return 0;
}
```

**Note:** this checks every possible down/right path independently. Problem 35 extends this same idea to counting all paths instead of just checking whether one exists.

---

# Part D — Sorting, Searching, and More Recursion

## Solution 29 — Selection Sort

```cpp
#include <iostream>
using namespace std;

void selectionSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            int temp = a[i];
            a[i] = a[minIndex];
            a[minIndex] = temp;
        }
    }
}

int main() {
    int n;
    int a[1000];

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    selectionSort(a, n);

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    cout << endl;

    return 0;
}
```

**Note:** selection sort always scans the remaining unsorted portion to find the minimum, regardless of input order, but performs at most n swaps in total — fewer swaps than bubble sort (Solution 19) can require.

---

## Solution 30 — Binary Search (Iteratively and Recursively)

```cpp
#include <iostream>
using namespace std;

int binarySearchIterative(int a[], int n, int target) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (a[mid] == target) {
            return mid;
        } else if (a[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

int binarySearchRecursive(int a[], int low, int high, int target) {
    if (low > high) {
        return -1;
    }

    int mid = low + (high - low) / 2;

    if (a[mid] == target) {
        return mid;
    } else if (a[mid] < target) {
        return binarySearchRecursive(a, mid + 1, high, target);
    } else {
        return binarySearchRecursive(a, low, mid - 1, target);
    }
}

int main() {
    int n;
    int a[100000];

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int target;
    cin >> target;

    cout << "Iterative = " << binarySearchIterative(a, n, target) << endl;
    cout << "Recursive = " << binarySearchRecursive(a, 0, n - 1, target) << endl;

    return 0;
}
```

**Note:** `mid = low + (high - low) / 2` is used instead of `(low + high) / 2` — this avoids a potential integer overflow when `low + high` is large, which is a good habit to have regardless of input size.

---

## Solution 31 — Matrix Transpose

```cpp
#include <iostream>
using namespace std;

int main() {
    int rows, cols;
    int a[100][100];
    int result[100][100];

    cin >> rows >> cols;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = a[i][j];
        }
    }

    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
```

**Note:** a separate `result` array is used because, unlike a square matrix, a non-square matrix can't be transposed cleanly in place.

---

## Solution 32 — Matrix Multiplication

```cpp
#include <iostream>
using namespace std;

int main() {
    int n, m, p;
    int a[100][100], b[100][100], c[100][100];

    cin >> n >> m >> p;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            cin >> b[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            int sum = 0;

            for (int k = 0; k < m; k++) {
                sum += a[i][k] * b[k][j];
            }

            c[i][j] = sum;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
```

---

## Solution 33 — Rotate Matrix 90 Degrees

```cpp
#include <iostream>
using namespace std;

int main() {
    int n;
    int a[100][100];

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    // Step 1: transpose in place
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int temp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp;
        }
    }

    // Step 2: reverse each row
    for (int i = 0; i < n; i++) {
        int left = 0;
        int right = n - 1;

        while (left < right) {
            int temp = a[i][left];
            a[i][left] = a[i][right];
            a[i][right] = temp;

            left++;
            right--;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
```

**Note:** the in-place transpose only works because the matrix is square (compare with Solution 31, which needs a separate array for non-square matrices).

---

## Solution 34 — Pascal's Triangle

```cpp
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int triangle[30][30];

    for (int row = 0; row < n; row++) {
        triangle[row][0] = 1;
        triangle[row][row] = 1;

        for (int k = 1; k < row; k++) {
            triangle[row][k] = triangle[row - 1][k - 1] + triangle[row - 1][k];
        }

        for (int k = 0; k <= row; k++) {
            cout << triangle[row][k] << " ";
        }
        cout << endl;
    }

    return 0;
}
```

**Bonus (pure recursion, no storage):**

```cpp
int choose(int row, int k) {
    if (k == 0 || k == row) {
        return 1;
    }
    return choose(row - 1, k - 1) + choose(row - 1, k);
}
```

This computes a single entry without building the array, but it recomputes many of the same sub-entries repeatedly — the same pattern seen in Solution 16's recursive Fibonacci.

---

## Solution 35 — Count Paths in a Maze

```cpp
#include <iostream>
using namespace std;

int countPaths(int maze[][20], int row, int col, int rows, int cols) {
    if (row >= rows || col >= cols) {
        return 0;
    }

    if (maze[row][col] == 0) {
        return 0;
    }

    if (row == rows - 1 && col == cols - 1) {
        return 1;
    }

    int down = countPaths(maze, row + 1, col, rows, cols);
    int right = countPaths(maze, row, col + 1, rows, cols);

    return down + right;
}

int main() {
    int rows, cols;
    int maze[20][20];

    cin >> rows >> cols;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> maze[i][j];
        }
    }

    cout << countPaths(maze, 0, 0, rows, cols) << endl;

    return 0;
}
```

**Note:** as a follow-up exercise, try storing each computed `(row, col)` result in a 2D array so the same sub-paths aren't recomputed — this turns it into a dynamic-programming solution.

---

## Solution 36 — Fast Exponentiation

```cpp
#include <iostream>
using namespace std;

long long fastPower(long long base, int exp) {
    if (exp == 0) {
        return 1;
    }

    long long half = fastPower(base, exp / 2);
    long long halfSquared = half * half;

    if (exp % 2 == 0) {
        return halfSquared;
    } else {
        return base * halfSquared;
    }
}

int main() {
    long long base;
    int exp;

    cin >> base >> exp;

    cout << fastPower(base, exp) << endl;

    return 0;
}
```

**Note:** each recursive call halves `exp`. Computing `half` once and squaring it (rather than calling `fastPower` twice) avoids doing the same work twice for no reason.
