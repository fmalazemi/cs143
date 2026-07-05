# C++ Class Implementation Exercises

This handout contains practice exercises for implementing simple versions of common data structures and classes in C++.

The goal is to help you practice:

- Classes and objects
- Encapsulation
- Constructors
- Copy constructors
- Destructors
- Dynamic memory
- Deep copy vs. shallow copy
- Basic data structure behavior

For each exercise:

1. Implement the class in C++.
2. Write a `main()` function to test all member functions.
3. Make sure dynamic memory is released correctly.
4. Make sure the copy constructor performs a deep copy.
5. Do not use STL containers such as `vector`, `set`, or `map`.



---

## Exercise 1: Implement `MyString`

Write a C++ program to create a class called `MyString`.

The class should work like a simple version of the built-in C++ string class.

### Requirements

- Store the characters using `char*`.
- Do not use the built-in `string` class to store the text.
- Do not use `vector`.
- Use dynamic memory correctly.
- Test all functions in `main()`.

```cpp
class MyString {
private:
    char* text;
    int length;

public:
    // Creates an empty string.
    // text should contain only the null character '\0'.
    // length should be 0.
    MyString();

    // Creates a MyString object from a C-style string.
    // Example: MyString s("Hello");
    // Allocate enough memory for all characters plus the null character '\0'.
    MyString(const char* str);

    // Creates a new MyString object as a copy of another MyString object.
    // The copy must be a deep copy, not a shallow copy.
    MyString(const MyString& other);

    // Releases the dynamically allocated memory.
    // This prevents memory leaks.
    ~MyString();

    // Prints the string.
    // If the string is empty, print nothing.
    void print();

    // Returns the number of characters in the string.
    // The null character '\0' should not be counted.
    int size();

    // Returns true if the string has no characters.
    // Otherwise, returns false.
    bool empty();

    // Returns the character stored at the given index.
    // If the index is invalid, print an error message and return '\0'.
    char at(int index);

    // Changes the character stored at the given index.
    // If the index is invalid, print an error message and do nothing.
    void setChar(int index, char ch);

    // Compares the current object with another MyString object.
    // Returns true if both strings have the same length and same characters.
    // Otherwise, returns false.
    bool equals(const MyString& other);

    // Adds another MyString object to the end of the current string.
    // Example: "Hello" + " World" becomes "Hello World".
    // Allocate new memory, copy both strings, then release the old memory.
    void append(const MyString& other);

    // Searches for a character in the string.
    // If found, return the first index of the character.
    // If not found, return -1.
    int find(char ch);
};
```

---

## Exercise 2: Implement `MyArray`

Write a C++ program to create a class called `MyArray`.

The class should work like a simple dynamic integer array.

### Requirements

- Store the numbers using `int*`.
- Do not use `vector`.
- Do not use STL containers.
- Use dynamic memory correctly.
- Test all functions in `main()`.

```cpp
class MyArray {
private:
    int* data;
    int size;

public:
    // Creates an empty array.
    // data should be nullptr and size should be 0.
    MyArray();

    // Creates an array of size s.
    // If s is positive, allocate dynamic memory for s integers.
    // If s is 0 or negative, create an empty array.
    MyArray(int s);

    // Creates a new MyArray object as a copy of another MyArray object.
    // The copy must be a deep copy, not a shallow copy.
    MyArray(const MyArray& other);

    // Releases the dynamically allocated memory.
    // This prevents memory leaks.
    ~MyArray();

    // Prints all elements in the array.
    // If the array is empty, print a suitable message.
    void print();

    // Returns the size of the array.
    int getSize();

    // Returns true if the array has no elements.
    // Otherwise, returns false.
    bool isEmpty();

    // Returns the element stored at the given index.
    // If the index is invalid, print an error message and return -1.
    int getElement(int index);

    // Changes the value stored at the given index.
    // If the index is invalid, print an error message and do nothing.
    void setElement(int index, int value);

    // Reads values from the user and stores them in the array.
    // The number of values read should be equal to size.
    void fillArray();

    // Returns the largest value in the array.
    // If the array is empty, print an error message and return -1.
    int findMax();

    // Returns the smallest value in the array.
    // If the array is empty, print an error message and return -1.
    int findMin();

    // Searches for value in the array.
    // If found, return its first index.
    // If not found, return -1.
    int search(int value);

    // Compares the current object with another MyArray object.
    // Returns true if both arrays have the same size and same values.
    // Otherwise, returns false.
    bool equals(const MyArray& other);
};
```

---

## Exercise 3: Implement `MySet`

Write a C++ program to create a class called `MySet`.

The class should work like a simple set of integers.

A set is a collection that stores **unique values only**. This means the same value should not appear more than once.

### Requirements

- Store the values using `int*`.
- Do not use `set`, `vector`, or STL containers.
- Use dynamic memory correctly.
- The set should not contain duplicate values.
- Test all functions in `main()`.

```cpp
class MySet {
private:
    int* data;
    int size;
    int capacity;

public:
    // Creates an empty set.
    // data should be nullptr.
    // size should be 0.
    // capacity should be 0.
    MySet();

    // Creates an empty set with a given capacity.
    // If c is positive, allocate memory for c integers.
    // If c is 0 or negative, create an empty set.
    MySet(int c);

    // Creates a new MySet object as a copy of another MySet object.
    // The copy must be a deep copy, not a shallow copy.
    MySet(const MySet& other);

    // Releases the dynamically allocated memory.
    // This prevents memory leaks.
    ~MySet();

    // Prints all values in the set.
    // If the set is empty, print a suitable message.
    void print();

    // Returns the number of values currently stored in the set.
    int getSize();

    // Returns the maximum number of values the set can store.
    int getCapacity();

    // Returns true if the set has no values.
    // Otherwise, returns false.
    bool isEmpty();

    // Returns true if the set is full.
    // Otherwise, returns false.
    bool isFull();

    // Checks whether a value already exists in the set.
    // If the value exists, return true.
    // Otherwise, return false.
    bool contains(int value);

    // Adds a value to the set.
    // If the value already exists, do not add it again.
    // If the set is full, print an error message and do not add the value.
    void add(int value);

    // Removes a value from the set.
    // If the value exists, remove it.
    // If the value does not exist, print an error message.
    void remove(int value);

    // Returns the value at the given index.
    // If the index is invalid, print an error message and return -1.
    int getElement(int index);

    // Removes all values from the set.
    // The allocated memory may stay the same, but size should become 0.
    void clear();

    // Compares the current set with another MySet object.
    // Returns true if both sets contain the same values, regardless of order.
    // Otherwise, returns false.
    bool equals(const MySet& other);
};
```

---

## Exercise 4: Implement `MyMap`

Write a C++ program to create a class called `MyMap`.

The class should work like a simple map that stores pairs of integers.

A map stores data as **key-value pairs**. Each key should be unique, and each key should be connected to one value.

Example:

```text
key: 101   value: 90
key: 102   value: 85
key: 103   value: 77
```

### Requirements

- Store the keys using `int* keys`.
- Store the values using `int* values`.
- Do not use `map`, `vector`, or STL containers.
- Use dynamic memory correctly.
- Keys must be unique.
- Test all functions in `main()`.

```cpp
class MyMap {
private:
    int* keys;
    int* values;
    int size;
    int capacity;

public:
    // Creates an empty map.
    // keys and values should be nullptr.
    // size should be 0.
    // capacity should be 0.
    MyMap();

    // Creates an empty map with a given capacity.
    // If c is positive, allocate memory for c keys and c values.
    // If c is 0 or negative, create an empty map.
    MyMap(int c);

    // Creates a new MyMap object as a copy of another MyMap object.
    // The copy must be a deep copy, not a shallow copy.
    MyMap(const MyMap& other);

    // Releases the dynamically allocated memory.
    // This prevents memory leaks.
    ~MyMap();

    // Prints all key-value pairs in the map.
    // If the map is empty, print a suitable message.
    void print();

    // Returns the number of key-value pairs currently stored in the map.
    int getSize();

    // Returns the maximum number of key-value pairs the map can store.
    int getCapacity();

    // Returns true if the map has no key-value pairs.
    // Otherwise, returns false.
    bool isEmpty();

    // Returns true if the map is full.
    // Otherwise, returns false.
    bool isFull();

    // Checks whether a key already exists in the map.
    // If the key exists, return true.
    // Otherwise, return false.
    bool containsKey(int key);

    // Adds a new key-value pair to the map.
    // If the key already exists, update its value.
    // If the map is full, print an error message and do not add the pair.
    void put(int key, int value);

    // Returns the value connected to the given key.
    // If the key does not exist, print an error message and return -1.
    int get(int key);

    // Changes the value connected to the given key.
    // If the key exists, update its value.
    // If the key does not exist, print an error message.
    void update(int key, int newValue);

    // Removes the key-value pair with the given key.
    // If the key exists, remove both the key and its value.
    // If the key does not exist, print an error message.
    void remove(int key);

    // Returns the key stored at the given index.
    // If the index is invalid, print an error message and return -1.
    int getKeyAt(int index);

    // Returns the value stored at the given index.
    // If the index is invalid, print an error message and return -1.
    int getValueAt(int index);

    // Removes all key-value pairs from the map.
    // The allocated memory may stay the same, but size should become 0.
    void clear();

    // Compares the current map with another MyMap object.
    // Returns true if both maps contain the same keys with the same values,
    // regardless of order.
    // Otherwise, returns false.
    bool equals(const MyMap& other);
};
```

