# Lecture 1: Data Structures in C++ — Stack, Queue & Linked List

## Table of Contents

1. [Introduction](#introduction)
2. [Stack](#stack)
   - [What is a Stack?](#what-is-a-stack)
   - [Stack in C++ (STL)](#stack-in-c-stl)
   - [Stack Operations](#stack-operations)
   - [Implementing a Stack from Scratch](#implementing-a-stack-from-scratch)
3. [Queue](#queue)
   - [What is a Queue?](#what-is-a-queue)
   - [Queue in C++ (STL)](#queue-in-c-stl)
   - [Queue Operations](#queue-operations)
   - [Implementing a Queue from Scratch](#implementing-a-queue-from-scratch)
4. [Linked List](#linked-list)
   - [What is a Linked List?](#what-is-a-linked-list)
   - [Singly Linked List](#singly-linked-list)
   - [Doubly Linked List](#doubly-linked-list)
   - [Linked List Operations](#linked-list-operations)
5. [Comparison Table](#comparison-table)
6. [Common Mistakes](#common-mistakes)
7. [Practice Exercises](#practice-exercises)
8. [Summary](#summary)

---

## Introduction

Data structures are foundational building blocks in computer science. A **data structure** is an organized way of storing and managing data so that you can perform operations on it efficiently. In C++, you can use built-in Standard Template Library (STL) containers or implement your own from scratch.

### Why Learn Data Structures?

- **Efficiency** — choosing the right structure can reduce time from O(n) to O(1)
- **Problem-solving** — most coding interview questions test your knowledge of data structures
- **Foundation** — algorithms like BFS, DFS, undo/redo, and scheduling all rely on them
- **Real-world use** — web servers, operating systems, and databases all use these daily

### Real-World Analogies

- **Stack** → A stack of plates: you always add to and remove from the top
- **Queue** → A line at a coffee shop: first person in line is first to be served
- **Linked List** → A treasure hunt chain: each clue (node) points to the next location

---

## Stack

### What is a Stack?

A **stack** is a linear data structure that follows the **LIFO** (Last In, First Out) principle. The last element you push onto the stack is the first one you pop off. Think of it like a stack of books — you can only take the top one.

### Stack in C++ (STL)

C++ provides `std::stack` in the `<stack>` header. It is a container adapter built on top of `std::deque` by default.

```cpp
#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top: " << s.top() << endl;   // 30
    cout << "Size: " << s.size() << endl; // 3

    s.pop();
    cout << "After pop, Top: " << s.top() << endl; // 20

    return 0;
}
```

**Output:**
```
Top: 30
Size: 3
After pop, Top: 20
```

### Stack Operations

| Operation   | Method       | Time Complexity |
|-------------|--------------|-----------------|
| Push        | `push(x)`    | O(1)            |
| Pop         | `pop()`      | O(1)            |
| Peek/Top    | `top()`      | O(1)            |
| Check empty | `empty()`    | O(1)            |
| Size        | `size()`     | O(1)            |

```cpp
#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<string> history;

    // Simulating browser back-button history
    history.push("google.com");
    history.push("youtube.com");
    history.push("github.com");

    cout << "Current page: " << history.top() << endl;
    history.pop(); // go back

    cout << "After back: " << history.top() << endl;
    cout << "Is empty: " << (history.empty() ? "yes" : "no") << endl;

    return 0;
}
```

**Output:**
```
Current page: github.com
After back: youtube.com
Is empty: no
```

### Implementing a Stack from Scratch

```cpp
#include <iostream>
using namespace std;

class Stack {
private:
    int arr[100];
    int topIndex;

public:
    Stack() : topIndex(-1) {}

    void push(int val) {
        if (topIndex >= 99) {
            cout << "Stack overflow!" << endl;
            return;
        }
        arr[++topIndex] = val;
    }

    void pop() {
        if (topIndex < 0) {
            cout << "Stack underflow!" << endl;
            return;
        }
        topIndex--;
    }

    int top() {
        return arr[topIndex];
    }

    bool empty() {
        return topIndex == -1;
    }
};

int main() {
    Stack s;
    s.push(5);
    s.push(15);
    s.push(25);

    cout << "Top: " << s.top() << endl;
    s.pop();
    cout << "After pop: " << s.top() << endl;

    return 0;
}
```

**Output:**
```
Top: 25
After pop: 15
```

---

## Queue

### What is a Queue?

A **queue** is a linear data structure that follows the **FIFO** (First In, First Out) principle. Elements are added at the **rear** and removed from the **front** — just like a line of people waiting for service.

### Queue in C++ (STL)

C++ provides `std::queue` in the `<queue>` header.

```cpp
#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);

    cout << "Front: " << q.front() << endl; // 1
    cout << "Back:  " << q.back()  << endl; // 3
    cout << "Size:  " << q.size()  << endl; // 3

    q.pop();
    cout << "After pop, Front: " << q.front() << endl; // 2

    return 0;
}
```

**Output:**
```
Front: 1
Back:  3
Size:  3
After pop, Front: 2
```

### Queue Operations

| Operation   | Method       | Time Complexity |
|-------------|--------------|-----------------|
| Enqueue     | `push(x)`    | O(1)            |
| Dequeue     | `pop()`      | O(1)            |
| Front peek  | `front()`    | O(1)            |
| Rear peek   | `back()`     | O(1)            |
| Check empty | `empty()`    | O(1)            |

```cpp
#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    queue<string> printJobs;

    printJobs.push("Report.pdf");
    printJobs.push("Resume.docx");
    printJobs.push("Photo.png");

    cout << "Processing print queue:" << endl;
    while (!printJobs.empty()) {
        cout << "Printing: " << printJobs.front() << endl;
        printJobs.pop();
    }

    return 0;
}
```

**Output:**
```
Processing print queue:
Printing: Report.pdf
Printing: Resume.docx
Printing: Photo.png
```

### Implementing a Queue from Scratch

```cpp
#include <iostream>
using namespace std;

class Queue {
private:
    int arr[100];
    int frontIdx, rearIdx, count;

public:
    Queue() : frontIdx(0), rearIdx(-1), count(0) {}

    void enqueue(int val) {
        if (count >= 100) {
            cout << "Queue full!" << endl;
            return;
        }
        arr[++rearIdx] = val;
        count++;
    }

    void dequeue() {
        if (count == 0) {
            cout << "Queue empty!" << endl;
            return;
        }
        frontIdx++;
        count--;
    }

    int front() { return arr[frontIdx]; }
    int back()  { return arr[rearIdx]; }
    bool empty() { return count == 0; }
    int size()   { return count; }
};

int main() {
    Queue q;
    q.enqueue(100);
    q.enqueue(200);
    q.enqueue(300);

    cout << "Front: " << q.front() << endl;
    q.dequeue();
    cout << "After dequeue, Front: " << q.front() << endl;

    return 0;
}
```

**Output:**
```
Front: 100
After dequeue, Front: 200
```

---

## Linked List

### What is a Linked List?

A **linked list** is a dynamic data structure made of **nodes**, where each node stores a **data value** and a **pointer** to the next node. Unlike arrays, nodes are not stored in contiguous memory — they can be anywhere in RAM, connected by pointers.

### Singly Linked List

```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void insertFront(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void insertBack(int val) {
        Node* newNode = new Node(val);
        if (!head) { head = newNode; return; }
        Node* curr = head;
        while (curr->next) curr = curr->next;
        curr->next = newNode;
    }

    void display() {
        Node* curr = head;
        while (curr) {
            cout << curr->data << " -> ";
            curr = curr->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList list;
    list.insertBack(10);
    list.insertBack(20);
    list.insertBack(30);
    list.insertFront(5);
    list.display();
    return 0;
}
```

**Output:**
```
5 -> 10 -> 20 -> 30 -> NULL
```

### Doubly Linked List

```cpp
#include <iostream>
using namespace std;

struct DNode {
    int data;
    DNode* prev;
    DNode* next;
    DNode(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    DNode* head;

public:
    DoublyLinkedList() : head(nullptr) {}

    void insertBack(int val) {
        DNode* newNode = new DNode(val);
        if (!head) { head = newNode; return; }
        DNode* curr = head;
        while (curr->next) curr = curr->next;
        curr->next = newNode;
        newNode->prev = curr;
    }

    void displayForward() {
        DNode* curr = head;
        while (curr) {
            cout << curr->data << " <-> ";
            curr = curr->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    DoublyLinkedList dll;
    dll.insertBack(1);
    dll.insertBack(2);
    dll.insertBack(3);
    dll.displayForward();
    return 0;
}
```

**Output:**
```
1 <-> 2 <-> 3 <-> NULL
```

### Linked List Operations

| Operation      | Time Complexity |
|----------------|-----------------|
| Insert at head | O(1)            |
| Insert at tail | O(n)            |
| Delete by value| O(n)            |
| Search         | O(n)            |
| Access by index| O(n)            |

```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* deleteNode(Node* head, int val) {
    if (!head) return nullptr;
    if (head->data == val) {
        Node* temp = head->next;
        delete head;
        return temp;
    }
    Node* curr = head;
    while (curr->next && curr->next->data != val)
        curr = curr->next;
    if (curr->next) {
        Node* temp = curr->next;
        curr->next = temp->next;
        delete temp;
    }
    return head;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    head = deleteNode(head, 2);

    Node* curr = head;
    while (curr) {
        cout << curr->data << " -> ";
        curr = curr->next;
    }
    cout << "NULL" << endl;
    return 0;
}
```

**Output:**
```
1 -> 3 -> NULL
```

---

## Comparison Table

| Feature          | Stack              | Queue              | Linked List          |
|------------------|--------------------|--------------------|----------------------|
| **Principle**    | LIFO               | FIFO               | Pointer-based        |
| **STL Header**   | `<stack>`          | `<queue>`          | `<list>` / custom    |
| **Insert**       | `push()` — O(1)    | `push()` — O(1)    | insertFront — O(1)   |
| **Remove**       | `pop()` — O(1)     | `pop()` — O(1)     | delete — O(n)        |
| **Access**       | `top()` — O(1)     | `front()` — O(1)   | traverse — O(n)      |
| **Memory**       | Contiguous         | Contiguous         | Dynamic nodes        |
| **Best Use**     | Undo, recursion    | Scheduling, BFS    | Dynamic insert/delete|

---

## Common Mistakes

### Mistake 1: Calling `top()` or `front()` on an Empty Container

**Wrong:**
```cpp
stack<int> s;
cout << s.top(); // Undefined behavior — stack is empty!
```

**Correct:**
```cpp
stack<int> s;
if (!s.empty()) {
    cout << s.top();
}
```

**Explanation:** Always check `empty()` before accessing `top()` or `front()`. Accessing an empty container is undefined behavior and can crash your program.

---

### Mistake 2: Forgetting to Delete Linked List Nodes (Memory Leak)

**Wrong:**
```cpp
Node* n = new Node(10);
n = new Node(20); // Original node is now lost — memory leak!
```

**Correct:**
```cpp
Node* n = new Node(10);
delete n;          // Free old memory first
n = new Node(20);  // Now safe to reassign
```

**Explanation:** Every `new` must be paired with a `delete`. Failing to do so causes memory leaks that grow over time and crash long-running programs.

---

### Mistake 3: Dereferencing a Null Pointer in Linked List Traversal

**Wrong:**
```cpp
Node* curr = head;
while (curr->next != nullptr) { // Crashes if head is nullptr!
    curr = curr->next;
}
```

**Correct:**
```cpp
Node* curr = head;
while (curr != nullptr && curr->next != nullptr) {
    curr = curr->next;
}
```

**Explanation:** Always check that the node itself is not null before accessing its members. An empty list has `head == nullptr`.

---

### Mistake 4: Not Updating the Head Pointer After Deletion

**Wrong:**
```cpp
void deleteHead(Node* head) {
    delete head; // head in caller is unchanged — dangling pointer!
}
```

**Correct:**
```cpp
Node* deleteHead(Node* head) {
    if (!head) return nullptr;
    Node* temp = head->next;
    delete head;
    return temp; // caller must reassign: head = deleteHead(head);
}
```

**Explanation:** In C++, pointers are passed by value. You must return the new head or pass it by reference/pointer-to-pointer to update the caller's variable.

---

### Mistake 5: Using `pop()` and Expecting a Return Value

**Wrong:**
```cpp
stack<int> s;
s.push(42);
int val = s.pop(); // ERROR: pop() returns void in C++ STL!
```

**Correct:**
```cpp
stack<int> s;
s.push(42);
int val = s.top(); // Read first
s.pop();           // Then remove
```

**Explanation:** Unlike some other languages, C++ STL's `pop()` for both `stack` and `queue` returns `void`. You must use `top()` (stack) or `front()` (queue) first to read, then call `pop()` to remove.

---

## Practice Exercises

### Exercise 1 — Balanced Parentheses (Easy)

Write a function that takes a string of brackets `()[]{}` and returns `true` if they are balanced using a stack.

**Expected output:**
```
"({[]})" → true
"([)]"   → false
"{{"     → false
```

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isBalanced(const string& s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else {
            if (st.empty()) return false;
            char top = st.top(); st.pop();
            if ((c == ')' && top != '(') ||
                (c == ']' && top != '[') ||
                (c == '}' && top != '{'))
                return false;
        }
    }
    return st.empty();
}

int main() {
    cout << boolalpha;
    cout << isBalanced("({[]})") << endl; // true
    cout << isBalanced("([)]")   << endl; // false
    cout << isBalanced("{{")     << endl; // false
    return 0;
}
```
</details>

---

### Exercise 2 — Reverse a Queue (Easy)

Using only a stack, reverse all elements in a queue.

**Expected:** Queue `[1, 2, 3, 4]` becomes `[4, 3, 2, 1]`

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reverseQueue(queue<int>& q) {
    stack<int> s;
    while (!q.empty()) { s.push(q.front()); q.pop(); }
    while (!s.empty()) { q.push(s.top()); s.pop(); }
}

int main() {
    queue<int> q;
    for (int i = 1; i <= 4; i++) q.push(i);
    reverseQueue(q);
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl; // 4 3 2 1
    return 0;
}
```
</details>

---

### Exercise 3 — Find the Middle of a Linked List (Medium)

Without using `size()`, find the middle node of a singly linked list using the **slow/fast pointer** technique.

**Expected:** `1 -> 2 -> 3 -> 4 -> 5` → middle is `3`

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

struct Node {
    int data; Node* next;
    Node(int v) : data(v), next(nullptr) {}
};

int findMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    cout << "Middle: " << findMiddle(head) << endl; // 3
    return 0;
}
```
</details>

---

### Exercise 4 — Implement a Stack Using Two Queues (Medium)

Implement a stack's `push` and `pop` operations using two `std::queue` objects.

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
#include <queue>
using namespace std;

class MyStack {
    queue<int> q1, q2;
public:
    void push(int val) {
        q2.push(val);
        while (!q1.empty()) { q2.push(q1.front()); q1.pop(); }
        swap(q1, q2);
    }
    int pop() {
        int val = q1.front(); q1.pop(); return val;
    }
    int top() { return q1.front(); }
    bool empty() { return q1.empty(); }
};

int main() {
    MyStack s;
    s.push(1); s.push(2); s.push(3);
    cout << s.top() << endl; // 3
    s.pop();
    cout << s.top() << endl; // 2
    return 0;
}
```
</details>

---

### Exercise 5 — Reverse a Linked List (Medium)

Write a function to reverse a singly linked list in-place.

**Expected:** `1 -> 2 -> 3 -> 4 -> 5 -> NULL` becomes `5 -> 4 -> 3 -> 2 -> 1 -> NULL`

<details>
<summary>Click to see solution</summary>

```cpp
#include <iostream>
using namespace std;

struct Node {
    int data; Node* next;
    Node(int v) : data(v), next(nullptr) {}
};

Node* reverse(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    while (curr) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void display(Node* head) {
    while (head) { cout << head->data << " -> "; head = head->next; }
    cout << "NULL" << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head = reverse(head);
    display(head); // 5 -> 4 -> 3 -> 2 -> 1 -> NULL
    return 0;
}
```
</details>

---

## Summary

### Key Concepts

- **Stack** uses LIFO — `push()` adds to top, `pop()` removes from top, `top()` peeks
- **Queue** uses FIFO — `push()` adds to rear, `pop()` removes from front, `front()` peeks
- **Linked List** uses dynamic nodes connected by pointers — no fixed size, O(1) head insertion
- C++ STL provides `std::stack` (`<stack>`) and `std::queue` (`<queue>`) out of the box
- Linked lists require manual memory management with `new` and `delete`

### Important Points

1. Always check `empty()` before calling `top()`, `front()`, or `back()`
2. `pop()` in C++ STL returns `void` — always read with `top()`/`front()` first
3. Every `new Node(...)` must eventually be paired with a `delete`
4. Passing a pointer by value does NOT update the caller's pointer — return or pass by reference
5. Stack and Queue are container adapters; Linked List is a node-based structure
6. For competitive programming, prefer `std::stack` and `std::queue` over custom implementations
7. The slow/fast pointer technique is a powerful linked list pattern worth memorizing
8. Doubly linked lists add bi-directional traversal at the cost of one extra pointer per node

### Quick Reference

```cpp
// Stack
#include <stack>
stack<int> s;
s.push(x);       // add
int v = s.top(); // peek
s.pop();         // remove

// Queue
#include <queue>
queue<int> q;
q.push(x);        // enqueue
int v = q.front(); // peek
q.pop();           // dequeue

// Linked List Node
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};
```

### Next Steps

- **Lecture 2:** Trees and Binary Search Trees — hierarchical node-based structures
- **Lecture 3:** Hash Maps and Sets — O(1) average-case lookup with `std::unordered_map`
- **Lecture 4:** Sorting Algorithms — using and understanding `std::sort`, merge sort, quicksort
