# C++ Class Implementation Solutions

This file contains complete solutions for the following class-based exercises:

1. `MyString`
2. `MyArray`
3. `MySet`
4. `MyMap`

Each solution uses dynamic memory and avoids STL containers such as `vector`, `set`, and `map`.

---

# 1. Solution: MyString

```cpp
#include <iostream>
#include <cstring>
using namespace std;

class MyString {
private:
    char* text;
    int length;

public:
    // Creates an empty string.
    MyString() {
        length = 0;
        text = new char[1];
        text[0] = '\0';
    }

    // Creates a MyString object from a C-style string.
    MyString(const char* str) {
        if (str == nullptr) {
            length = 0;
            text = new char[1];
            text[0] = '\0';
        } else {
            length = strlen(str);
            text = new char[length + 1];
            strcpy(text, str);
        }
    }

    // Copy constructor: deep copy.
    MyString(const MyString& other) {
        length = other.length;
        text = new char[length + 1];
        strcpy(text, other.text);
    }

    // Destructor.
    ~MyString() {
        delete[] text;
    }

    // Prints the string.
    void print() {
        cout << text;
    }

    // Returns the number of characters.
    int size() {
        return length;
    }

    // Checks whether the string is empty.
    bool empty() {
        return length == 0;
    }

    // Returns character at index.
    char at(int index) {
        if (index < 0 || index >= length) {
            cout << "Invalid index" << endl;
            return '\0';
        }
        return text[index];
    }

    // Changes character at index.
    void setChar(int index, char ch) {
        if (index < 0 || index >= length) {
            cout << "Invalid index" << endl;
            return;
        }
        text[index] = ch;
    }

    // Compares two MyString objects.
    bool equals(const MyString& other) {
        if (length != other.length) {
            return false;
        }

        for (int i = 0; i < length; i++) {
            if (text[i] != other.text[i]) {
                return false;
            }
        }

        return true;
    }

    // Appends another MyString to the current string.
    void append(const MyString& other) {
        int newLength = length + other.length;
        char* newText = new char[newLength + 1];

        for (int i = 0; i < length; i++) {
            newText[i] = text[i];
        }

        for (int i = 0; i < other.length; i++) {
            newText[length + i] = other.text[i];
        }

        newText[newLength] = '\0';

        delete[] text;
        text = newText;
        length = newLength;
    }

    // Finds first index of character.
    int find(char ch) {
        for (int i = 0; i < length; i++) {
            if (text[i] == ch) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    MyString s1("Hello");
    MyString s2(" World");

    cout << "s1: ";
    s1.print();
    cout << endl;

    cout << "Size of s1: " << s1.size() << endl;

    cout << "Is s1 empty? ";
    if (s1.empty()) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    cout << "Character at index 1: " << s1.at(1) << endl;

    s1.setChar(0, 'Y');
    cout << "After setChar: ";
    s1.print();
    cout << endl;

    s1.append(s2);
    cout << "After append: ";
    s1.print();
    cout << endl;

    cout << "Index of 'l': " << s1.find('l') << endl;

    MyString s3 = s1;
    cout << "s3: ";
    s3.print();
    cout << endl;

    if (s1.equals(s3)) {
        cout << "s1 and s3 are equal" << endl;
    } else {
        cout << "s1 and s3 are not equal" << endl;
    }

    return 0;
}
```

---

# 2. Solution: MyArray

```cpp
#include <iostream>
using namespace std;

class MyArray {
private:
    int* data;
    int size;

public:
    // Creates an empty array.
    MyArray() {
        data = nullptr;
        size = 0;
    }

    // Creates an array of size s.
    MyArray(int s) {
        if (s > 0) {
            size = s;
            data = new int[size];

            for (int i = 0; i < size; i++) {
                data[i] = 0;
            }
        } else {
            size = 0;
            data = nullptr;
        }
    }

    // Copy constructor: deep copy.
    MyArray(const MyArray& other) {
        size = other.size;

        if (size > 0) {
            data = new int[size];
            for (int i = 0; i < size; i++) {
                data[i] = other.data[i];
            }
        } else {
            data = nullptr;
        }
    }

    // Destructor.
    ~MyArray() {
        delete[] data;
    }

    // Prints all elements.
    void print() {
        if (size == 0) {
            cout << "Array is empty" << endl;
            return;
        }

        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    // Returns array size.
    int getSize() {
        return size;
    }

    // Checks whether array is empty.
    bool isEmpty() {
        return size == 0;
    }

    // Returns element at index.
    int getElement(int index) {
        if (index < 0 || index >= size) {
            cout << "Invalid index" << endl;
            return -1;
        }
        return data[index];
    }

    // Changes element at index.
    void setElement(int index, int value) {
        if (index < 0 || index >= size) {
            cout << "Invalid index" << endl;
            return;
        }
        data[index] = value;
    }

    // Reads values from the user.
    void fillArray() {
        for (int i = 0; i < size; i++) {
            cout << "Enter element " << i << ": ";
            cin >> data[i];
        }
    }

    // Finds maximum value.
    int findMax() {
        if (size == 0) {
            cout << "Array is empty" << endl;
            return -1;
        }

        int maxValue = data[0];
        for (int i = 1; i < size; i++) {
            if (data[i] > maxValue) {
                maxValue = data[i];
            }
        }
        return maxValue;
    }

    // Finds minimum value.
    int findMin() {
        if (size == 0) {
            cout << "Array is empty" << endl;
            return -1;
        }

        int minValue = data[0];
        for (int i = 1; i < size; i++) {
            if (data[i] < minValue) {
                minValue = data[i];
            }
        }
        return minValue;
    }

    // Searches for value.
    int search(int value) {
        for (int i = 0; i < size; i++) {
            if (data[i] == value) {
                return i;
            }
        }
        return -1;
    }

    // Compares two arrays.
    bool equals(const MyArray& other) {
        if (size != other.size) {
            return false;
        }

        for (int i = 0; i < size; i++) {
            if (data[i] != other.data[i]) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    MyArray arr(5);

    arr.setElement(0, 10);
    arr.setElement(1, 20);
    arr.setElement(2, 30);
    arr.setElement(3, 40);
    arr.setElement(4, 50);

    cout << "Array: ";
    arr.print();

    cout << "Size: " << arr.getSize() << endl;
    cout << "Element at index 2: " << arr.getElement(2) << endl;
    cout << "Max: " << arr.findMax() << endl;
    cout << "Min: " << arr.findMin() << endl;
    cout << "Index of 30: " << arr.search(30) << endl;

    MyArray arr2 = arr;

    if (arr.equals(arr2)) {
        cout << "Arrays are equal" << endl;
    } else {
        cout << "Arrays are not equal" << endl;
    }

    return 0;
}
```

---

# 3. Solution: MySet

```cpp
#include <iostream>
using namespace std;

class MySet {
private:
    int* data;
    int size;
    int capacity;

public:
    // Creates an empty set.
    MySet() {
        data = nullptr;
        size = 0;
        capacity = 0;
    }

    // Creates an empty set with capacity c.
    MySet(int c) {
        if (c > 0) {
            capacity = c;
            size = 0;
            data = new int[capacity];
        } else {
            capacity = 0;
            size = 0;
            data = nullptr;
        }
    }

    // Copy constructor: deep copy.
    MySet(const MySet& other) {
        size = other.size;
        capacity = other.capacity;

        if (capacity > 0) {
            data = new int[capacity];
            for (int i = 0; i < size; i++) {
                data[i] = other.data[i];
            }
        } else {
            data = nullptr;
        }
    }

    // Destructor.
    ~MySet() {
        delete[] data;
    }

    // Prints all values in the set.
    void print() {
        if (size == 0) {
            cout << "Set is empty" << endl;
            return;
        }

        cout << "{ ";
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << "}" << endl;
    }

    // Returns number of values.
    int getSize() {
        return size;
    }

    // Returns capacity.
    int getCapacity() {
        return capacity;
    }

    // Checks whether set is empty.
    bool isEmpty() {
        return size == 0;
    }

    // Checks whether set is full.
    bool isFull() {
        return size == capacity;
    }

    // Checks whether a value exists.
    bool contains(int value) {
        for (int i = 0; i < size; i++) {
            if (data[i] == value) {
                return true;
            }
        }
        return false;
    }

    // Adds a value if it does not already exist.
    void add(int value) {
        if (contains(value)) {
            cout << "Value already exists" << endl;
            return;
        }

        if (isFull()) {
            cout << "Set is full" << endl;
            return;
        }

        data[size] = value;
        size++;
    }

    // Removes a value from the set.
    void remove(int value) {
        int index = -1;

        for (int i = 0; i < size; i++) {
            if (data[i] == value) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            cout << "Value not found" << endl;
            return;
        }

        for (int i = index; i < size - 1; i++) {
            data[i] = data[i + 1];
        }

        size--;
    }

    // Returns value at index.
    int getElement(int index) {
        if (index < 0 || index >= size) {
            cout << "Invalid index" << endl;
            return -1;
        }
        return data[index];
    }

    // Removes all values.
    void clear() {
        size = 0;
    }

    // Compares two sets regardless of order.
    bool equals(const MySet& other) {
        if (size != other.size) {
            return false;
        }

        for (int i = 0; i < size; i++) {
            bool found = false;

            for (int j = 0; j < other.size; j++) {
                if (data[i] == other.data[j]) {
                    found = true;
                    break;
                }
            }

            if (!found) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    MySet s1(5);

    s1.add(10);
    s1.add(20);
    s1.add(30);
    s1.add(20); // duplicate, should not be added

    cout << "Set s1: ";
    s1.print();

    cout << "Size: " << s1.getSize() << endl;
    cout << "Capacity: " << s1.getCapacity() << endl;

    cout << "Contains 20? ";
    if (s1.contains(20)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    s1.remove(20);
    cout << "After removing 20: ";
    s1.print();

    MySet s2(5);
    s2.add(30);
    s2.add(10);

    if (s1.equals(s2)) {
        cout << "Sets are equal" << endl;
    } else {
        cout << "Sets are not equal" << endl;
    }

    s1.clear();
    cout << "After clear: ";
    s1.print();

    return 0;
}
```

---

# 4. Solution: MyMap

```cpp
#include <iostream>
using namespace std;

class MyMap {
private:
    int* keys;
    int* values;
    int size;
    int capacity;

public:
    // Creates an empty map.
    MyMap() {
        keys = nullptr;
        values = nullptr;
        size = 0;
        capacity = 0;
    }

    // Creates an empty map with capacity c.
    MyMap(int c) {
        if (c > 0) {
            capacity = c;
            size = 0;
            keys = new int[capacity];
            values = new int[capacity];
        } else {
            capacity = 0;
            size = 0;
            keys = nullptr;
            values = nullptr;
        }
    }

    // Copy constructor: deep copy.
    MyMap(const MyMap& other) {
        size = other.size;
        capacity = other.capacity;

        if (capacity > 0) {
            keys = new int[capacity];
            values = new int[capacity];

            for (int i = 0; i < size; i++) {
                keys[i] = other.keys[i];
                values[i] = other.values[i];
            }
        } else {
            keys = nullptr;
            values = nullptr;
        }
    }

    // Destructor.
    ~MyMap() {
        delete[] keys;
        delete[] values;
    }

    // Prints all key-value pairs.
    void print() {
        if (size == 0) {
            cout << "Map is empty" << endl;
            return;
        }

        for (int i = 0; i < size; i++) {
            cout << keys[i] << " -> " << values[i] << endl;
        }
    }

    // Returns number of pairs.
    int getSize() {
        return size;
    }

    // Returns capacity.
    int getCapacity() {
        return capacity;
    }

    // Checks whether map is empty.
    bool isEmpty() {
        return size == 0;
    }

    // Checks whether map is full.
    bool isFull() {
        return size == capacity;
    }

    // Checks whether key exists.
    bool containsKey(int key) {
        for (int i = 0; i < size; i++) {
            if (keys[i] == key) {
                return true;
            }
        }
        return false;
    }

    // Adds a key-value pair or updates existing key.
    void put(int key, int value) {
        for (int i = 0; i < size; i++) {
            if (keys[i] == key) {
                values[i] = value;
                return;
            }
        }

        if (isFull()) {
            cout << "Map is full" << endl;
            return;
        }

        keys[size] = key;
        values[size] = value;
        size++;
    }

    // Returns value connected to key.
    int get(int key) {
        for (int i = 0; i < size; i++) {
            if (keys[i] == key) {
                return values[i];
            }
        }

        cout << "Key not found" << endl;
        return -1;
    }

    // Updates value connected to key.
    void update(int key, int newValue) {
        for (int i = 0; i < size; i++) {
            if (keys[i] == key) {
                values[i] = newValue;
                return;
            }
        }

        cout << "Key not found" << endl;
    }

    // Removes key-value pair.
    void remove(int key) {
        int index = -1;

        for (int i = 0; i < size; i++) {
            if (keys[i] == key) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            cout << "Key not found" << endl;
            return;
        }

        for (int i = index; i < size - 1; i++) {
            keys[i] = keys[i + 1];
            values[i] = values[i + 1];
        }

        size--;
    }

    // Returns key at index.
    int getKeyAt(int index) {
        if (index < 0 || index >= size) {
            cout << "Invalid index" << endl;
            return -1;
        }
        return keys[index];
    }

    // Returns value at index.
    int getValueAt(int index) {
        if (index < 0 || index >= size) {
            cout << "Invalid index" << endl;
            return -1;
        }
        return values[index];
    }

    // Removes all pairs.
    void clear() {
        size = 0;
    }

    // Compares two maps regardless of order.
    bool equals(const MyMap& other) {
        if (size != other.size) {
            return false;
        }

        for (int i = 0; i < size; i++) {
            bool found = false;

            for (int j = 0; j < other.size; j++) {
                if (keys[i] == other.keys[j] && values[i] == other.values[j]) {
                    found = true;
                    break;
                }
            }

            if (!found) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    MyMap grades(5);

    grades.put(101, 90);
    grades.put(102, 85);
    grades.put(103, 77);

    cout << "Map:" << endl;
    grades.print();

    cout << "Size: " << grades.getSize() << endl;
    cout << "Capacity: " << grades.getCapacity() << endl;

    cout << "Value for key 102: " << grades.get(102) << endl;

    grades.update(102, 95);
    cout << "After updating key 102:" << endl;
    grades.print();

    grades.put(103, 80); // existing key, so value is updated
    cout << "After put existing key 103:" << endl;
    grades.print();

    grades.remove(101);
    cout << "After removing key 101:" << endl;
    grades.print();

    MyMap grades2(5);
    grades2.put(103, 80);
    grades2.put(102, 95);

    if (grades.equals(grades2)) {
        cout << "Maps are equal" << endl;
    } else {
        cout << "Maps are not equal" << endl;
    }

    grades.clear();
    cout << "After clear:" << endl;
    grades.print();

    return 0;
}
```
