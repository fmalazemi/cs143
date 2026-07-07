# C++ OOP Exercise Set — Solutions

This file contains suggested solutions for the exercise set on encapsulation, inheritance, access specifiers, `vector`, `set`, and `map`.

> Note: These are sample solutions. Students may write different correct versions.

---

# Level 1: Encapsulation and Basic Classes

## Exercise 1 Solution: Student Class

```cpp
#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int id;
    double grade;

public:
    void setName(string n) {
        name = n;
    }

    void setId(int i) {
        id = i;
    }

    void setGrade(double g) {
        if (g >= 0 && g <= 100)
            grade = g;
        else
            grade = 0;
    }

    string getName() {
        return name;
    }

    int getId() {
        return id;
    }

    double getGrade() {
        return grade;
    }

    void printInfo() {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Grade: " << grade << endl;
    }
};

int main() {
    Student s1, s2, s3;

    s1.setName("Ali");
    s1.setId(101);
    s1.setGrade(87.5);

    s2.setName("Sara");
    s2.setId(102);
    s2.setGrade(95);

    s3.setName("Omar");
    s3.setId(103);
    s3.setGrade(76);

    s1.printInfo();
    cout << endl;
    s2.printInfo();
    cout << endl;
    s3.printInfo();

    return 0;
}
```

---

## Exercise 2 Solution: Bank Account

```cpp
#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string ownerName;
    int accountNumber;
    double balance;

public:
    void setAccount(string name, int number, double initialBalance) {
        ownerName = name;
        accountNumber = number;

        if (initialBalance >= 0)
            balance = initialBalance;
        else
            balance = 0;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful.\n";
        } else {
            cout << "Deposit amount must be positive.\n";
        }
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Withdraw amount must be positive.\n";
        } else if (amount <= balance) {
            balance -= amount;
            cout << "Withdraw successful.\n";
        } else {
            cout << "Not enough balance.\n";
        }
    }

    double getBalance() {
        return balance;
    }

    void printAccount() {
        cout << "Owner: " << ownerName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main() {
    BankAccount account;
    account.setAccount("Ali", 12345, 500);

    int choice;
    double amount;

    do {
        cout << "\n1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Show Balance\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter amount: ";
            cin >> amount;
            account.deposit(amount);
        } else if (choice == 2) {
            cout << "Enter amount: ";
            cin >> amount;
            account.withdraw(amount);
        } else if (choice == 3) {
            cout << "Balance: " << account.getBalance() << endl;
        } else if (choice == 4) {
            cout << "Goodbye.\n";
        } else {
            cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    return 0;
}
```

---

## Exercise 3 Solution: Product Class with Discount

```cpp
#include <iostream>
#include <string>
using namespace std;

class Product {
private:
    string name;
    double price;
    int quantity;

public:
    void setProduct(string n, double p, int q) {
        name = n;

        if (p >= 0)
            price = p;
        else
            price = 0;

        if (q >= 0)
            quantity = q;
        else
            quantity = 0;
    }

    double getTotalPrice() {
        return price * quantity;
    }

    void applyDiscount(double percent) {
        if (percent >= 0 && percent <= 100) {
            price = price - (price * percent / 100);
        } else {
            cout << "Invalid discount.\n";
        }
    }

    void printProduct() {
        cout << "Product: " << name << endl;
        cout << "Price: " << price << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Total Price: " << getTotalPrice() << endl;
    }
};

int main() {
    Product p;
    string name;
    double price, discount;
    int quantity;

    cout << "Enter product name: ";
    cin >> name;

    cout << "Enter price: ";
    cin >> price;

    cout << "Enter quantity: ";
    cin >> quantity;

    p.setProduct(name, price, quantity);

    cout << "Enter discount percentage: ";
    cin >> discount;

    p.applyDiscount(discount);
    p.printProduct();

    return 0;
}
```

---

# Level 2: Using `vector` with Classes

## Exercise 4 Solution: Vector of Students

```cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student {
private:
    string name;
    int id;
    double grade;

public:
    void setName(string n) { name = n; }
    void setId(int i) { id = i; }

    void setGrade(double g) {
        if (g >= 0 && g <= 100)
            grade = g;
        else
            grade = 0;
    }

    string getName() const { return name; }
    int getId() const { return id; }
    double getGrade() const { return grade; }

    void printInfo() const {
        cout << "Name: " << name << ", ID: " << id << ", Grade: " << grade << endl;
    }
};

void addStudent(vector<Student>& students) {
    Student s;
    string name;
    int id;
    double grade;

    cout << "Enter name: ";
    cin >> name;
    cout << "Enter ID: ";
    cin >> id;
    cout << "Enter grade: ";
    cin >> grade;

    s.setName(name);
    s.setId(id);
    s.setGrade(grade);

    students.push_back(s);
}

void printAllStudents(const vector<Student>& students) {
    for (int i = 0; i < students.size(); i++) {
        students[i].printInfo();
    }
}

void searchById(const vector<Student>& students, int id) {
    for (int i = 0; i < students.size(); i++) {
        if (students[i].getId() == id) {
            students[i].printInfo();
            return;
        }
    }
    cout << "Student not found.\n";
}

void printExcellentStudents(const vector<Student>& students) {
    for (int i = 0; i < students.size(); i++) {
        if (students[i].getGrade() >= 90) {
            students[i].printInfo();
        }
    }
}

int main() {
    vector<Student> students;
    int choice, id;

    do {
        cout << "\n1. Add student\n";
        cout << "2. Print all students\n";
        cout << "3. Search student by ID\n";
        cout << "4. Print students with grade >= 90\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            addStudent(students);
        } else if (choice == 2) {
            printAllStudents(students);
        } else if (choice == 3) {
            cout << "Enter ID: ";
            cin >> id;
            searchById(students, id);
        } else if (choice == 4) {
            printExcellentStudents(students);
        }
    } while (choice != 5);

    return 0;
}
```

---

## Exercise 5 Solution: Classroom Average

```cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student {
private:
    string name;
    int id;
    double grade;

public:
    void setStudent(string n, int i, double g) {
        name = n;
        id = i;
        grade = (g >= 0 && g <= 100) ? g : 0;
    }

    string getName() const { return name; }
    int getId() const { return id; }
    double getGrade() const { return grade; }
};

class Course {
private:
    string courseName;
    vector<Student> students;

public:
    void setCourseName(string name) {
        courseName = name;
    }

    void addStudent(Student s) {
        students.push_back(s);
    }

    double calculateAverage() {
        if (students.size() == 0)
            return 0;

        double sum = 0;
        for (int i = 0; i < students.size(); i++) {
            sum += students[i].getGrade();
        }
        return sum / students.size();
    }

    Student getHighestStudent() {
        Student highest = students[0];
        for (int i = 1; i < students.size(); i++) {
            if (students[i].getGrade() > highest.getGrade()) {
                highest = students[i];
            }
        }
        return highest;
    }

    void printCourseReport() {
        cout << "Course: " << courseName << endl;
        cout << "Number of students: " << students.size() << endl;
        cout << "Average grade: " << calculateAverage() << endl;

        if (students.size() > 0) {
            Student highest = getHighestStudent();
            cout << "Highest student: " << highest.getName()
                 << ", " << highest.getGrade() << endl;
        }
    }
};

int main() {
    Course c;
    c.setCourseName("Programming 1");

    Student s1, s2, s3;
    s1.setStudent("Ali", 101, 80);
    s2.setStudent("Sara", 102, 97);
    s3.setStudent("Omar", 103, 70);

    c.addStudent(s1);
    c.addStudent(s2);
    c.addStudent(s3);

    c.printCourseReport();

    return 0;
}
```

---

## Exercise 6 Solution: Remove Failed Students

```cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student {
private:
    string name;
    double grade;

public:
    void setStudent(string n, double g) {
        name = n;
        grade = g;
    }

    string getName() const { return name; }
    double getGrade() const { return grade; }

    void print() const {
        cout << name << " " << grade << endl;
    }
};

class Course {
private:
    vector<Student> students;

public:
    void addStudent(Student s) {
        students.push_back(s);
    }

    void removeFailedStudents() {
        for (int i = 0; i < students.size(); i++) {
            if (students[i].getGrade() < 60) {
                students.erase(students.begin() + i);
                i--;
            }
        }
    }

    void printStudents() {
        for (int i = 0; i < students.size(); i++) {
            students[i].print();
        }
    }
};

int main() {
    Course c;
    Student s;

    s.setStudent("Ali", 55);
    c.addStudent(s);

    s.setStudent("Sara", 90);
    c.addStudent(s);

    s.setStudent("Omar", 48);
    c.addStudent(s);

    s.setStudent("Mona", 77);
    c.addStudent(s);

    cout << "Before removing:\n";
    c.printStudents();

    c.removeFailedStudents();

    cout << "\nAfter removing:\n";
    c.printStudents();

    return 0;
}
```

---

# Level 3: Using `set` with Classes and Data

## Exercise 7 Solution: Unique Student IDs

```cpp
#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> studentIds;
    int choice, id;

    do {
        cout << "\n1. Add student ID\n";
        cout << "2. Remove student ID\n";
        cout << "3. Search for student ID\n";
        cout << "4. Print all IDs\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter ID: ";
            cin >> id;

            if (studentIds.count(id) == 0) {
                studentIds.insert(id);
                cout << "ID added.\n";
            } else {
                cout << "This ID already exists.\n";
            }
        } else if (choice == 2) {
            cout << "Enter ID: ";
            cin >> id;

            if (studentIds.erase(id) > 0)
                cout << "ID removed.\n";
            else
                cout << "ID not found.\n";
        } else if (choice == 3) {
            cout << "Enter ID: ";
            cin >> id;

            if (studentIds.count(id) > 0)
                cout << "ID found.\n";
            else
                cout << "ID not found.\n";
        } else if (choice == 4) {
            for (int x : studentIds) {
                cout << x << endl;
            }
        }
    } while (choice != 5);

    return 0;
}
```

---

## Exercise 8 Solution: Course Registration System

```cpp
#include <iostream>
#include <string>
#include <set>
using namespace std;

class Student {
private:
    int id;
    string name;

public:
    void setStudent(int i, string n) {
        id = i;
        name = n;
    }

    int getId() const { return id; }
    string getName() const { return name; }
};

class Course {
private:
    string courseCode;
    set<int> registeredStudentIds;

public:
    void setCourseCode(string code) {
        courseCode = code;
    }

    void registerStudent(int id) {
        if (registeredStudentIds.count(id) > 0) {
            cout << "Student already registered.\n";
        } else {
            registeredStudentIds.insert(id);
            cout << "Student registered.\n";
        }
    }

    void dropStudent(int id) {
        if (registeredStudentIds.erase(id) > 0)
            cout << "Student dropped.\n";
        else
            cout << "Student is not registered.\n";
    }

    bool isRegistered(int id) {
        return registeredStudentIds.count(id) > 0;
    }

    void printRegisteredStudents() {
        cout << "Registered students in " << courseCode << ":\n";
        for (int id : registeredStudentIds) {
            cout << id << endl;
        }
    }
};

int main() {
    Course c;
    c.setCourseCode("CS141");

    c.registerStudent(101);
    c.registerStudent(102);
    c.registerStudent(101);

    c.printRegisteredStudents();

    c.dropStudent(103);
    c.dropStudent(101);

    c.printRegisteredStudents();

    return 0;
}
```

---

## Exercise 9 Solution: Attendance System

```cpp
#include <iostream>
#include <string>
#include <set>
using namespace std;

class Attendance {
private:
    string date;
    set<int> presentStudentIds;

public:
    void setDate(string d) {
        date = d;
    }

    void markPresent(int id) {
        presentStudentIds.insert(id);
        cout << "Marked present.\n";
    }

    void markAbsent(int id) {
        if (presentStudentIds.erase(id) > 0)
            cout << "Marked absent.\n";
        else
            cout << "Student was not marked present.\n";
    }

    bool isPresent(int id) {
        return presentStudentIds.count(id) > 0;
    }

    void printPresentStudents() {
        cout << "Present students on " << date << ":\n";
        for (int id : presentStudentIds) {
            cout << id << endl;
        }
    }

    int countPresent() {
        return presentStudentIds.size();
    }
};

int main() {
    Attendance attendance;
    attendance.setDate("2026-07-07");

    int totalStudents;
    cout << "Enter total number of students: ";
    cin >> totalStudents;

    int choice, id;

    do {
        cout << "\n1. Mark present\n";
        cout << "2. Mark absent\n";
        cout << "3. Check student\n";
        cout << "4. Print present students\n";
        cout << "5. Print summary\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter ID: ";
            cin >> id;
            attendance.markPresent(id);
        } else if (choice == 2) {
            cout << "Enter ID: ";
            cin >> id;
            attendance.markAbsent(id);
        } else if (choice == 3) {
            cout << "Enter ID: ";
            cin >> id;

            if (attendance.isPresent(id))
                cout << "Student is present.\n";
            else
                cout << "Student is absent.\n";
        } else if (choice == 4) {
            attendance.printPresentStudents();
        } else if (choice == 5) {
            int present = attendance.countPresent();
            int absent = totalStudents - present;
            double percentage = 0;

            if (totalStudents > 0)
                percentage = present * 100.0 / totalStudents;

            cout << "Number present: " << present << endl;
            cout << "Number absent: " << absent << endl;
            cout << "Attendance percentage: " << percentage << "%\n";
        }
    } while (choice != 6);

    return 0;
}
```

---

# Level 4: Using `map`

## Exercise 10 Solution: Student Grades Using `map`

```cpp
#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int, double> grades;
    int choice, id;
    double grade;

    do {
        cout << "\n1. Add or update grade\n";
        cout << "2. Print grade by ID\n";
        cout << "3. Print all grades\n";
        cout << "4. Print average grade\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter grade: ";
            cin >> grade;

            if (grade >= 0 && grade <= 100) {
                grades[id] = grade;
                cout << "Grade saved.\n";
            } else {
                cout << "Invalid grade.\n";
            }
        } else if (choice == 2) {
            cout << "Enter ID: ";
            cin >> id;

            if (grades.count(id) > 0)
                cout << "Grade: " << grades[id] << endl;
            else
                cout << "ID not found.\n";
        } else if (choice == 3) {
            for (auto x : grades) {
                cout << "ID: " << x.first << ", Grade: " << x.second << endl;
            }
        } else if (choice == 4) {
            double sum = 0;

            for (auto x : grades) {
                sum += x.second;
            }

            if (grades.size() > 0)
                cout << "Average: " << sum / grades.size() << endl;
            else
                cout << "No grades.\n";
        }
    } while (choice != 5);

    return 0;
}
```

---

## Exercise 11 Solution: Student Names and Grades

```cpp
#include <iostream>
#include <string>
#include <map>
using namespace std;

class GradeBook {
private:
    map<int, string> studentNames;
    map<int, double> studentGrades;

public:
    void addStudent(int id, string name) {
        if (studentNames.count(id) > 0) {
            cout << "ID already exists.\n";
        } else {
            studentNames[id] = name;
            cout << "Student added.\n";
        }
    }

    void setGrade(int id, double grade) {
        if (studentNames.count(id) == 0) {
            cout << "Student does not exist.\n";
        } else if (grade < 0 || grade > 100) {
            cout << "Invalid grade.\n";
        } else {
            studentGrades[id] = grade;
            cout << "Grade saved.\n";
        }
    }

    void printStudent(int id) {
        if (studentNames.count(id) == 0) {
            cout << "Student not found.\n";
            return;
        }

        cout << "ID: " << id << endl;
        cout << "Name: " << studentNames[id] << endl;

        if (studentGrades.count(id) > 0)
            cout << "Grade: " << studentGrades[id] << endl;
        else
            cout << "Grade: Not assigned\n";
    }

    void printAllStudents() {
        for (auto x : studentNames) {
            printStudent(x.first);
            cout << endl;
        }
    }

    double calculateAverage() {
        if (studentGrades.size() == 0)
            return 0;

        double sum = 0;
        for (auto x : studentGrades) {
            sum += x.second;
        }

        return sum / studentGrades.size();
    }
};

int main() {
    GradeBook gb;

    gb.addStudent(101, "Ali");
    gb.addStudent(102, "Sara");

    gb.setGrade(101, 89);
    gb.setGrade(102, 95);

    gb.printAllStudents();
    cout << "Average: " << gb.calculateAverage() << endl;

    return 0;
}
```

---

## Exercise 12 Solution: Count Repeated Names

```cpp
#include <iostream>
#include <string>
#include <map>
using namespace std;

class NameCounter {
private:
    map<string, int> nameFrequency;

public:
    void addName(string name) {
        nameFrequency[name]++;
    }

    void printFrequency() {
        for (auto x : nameFrequency) {
            cout << x.first << " appears " << x.second << " time";
            if (x.second > 1)
                cout << "s";
            cout << endl;
        }
    }

    int getCount(string name) {
        if (nameFrequency.count(name) > 0)
            return nameFrequency[name];
        return 0;
    }
};

int main() {
    NameCounter counter;

    counter.addName("Ali");
    counter.addName("Sara");
    counter.addName("Ali");
    counter.addName("Omar");
    counter.addName("Sara");
    counter.addName("Ali");

    counter.printFrequency();

    cout << "Ali count: " << counter.getCount("Ali") << endl;

    return 0;
}
```

---

# Level 5: Inheritance and Access Specifiers

## Exercise 13 Solution: Person and Student

```cpp
#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    void setName(string n) {
        name = n;
    }

    void setAge(int a) {
        if (a >= 0)
            age = a;
        else
            age = 0;
    }

    void printPerson() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Student : public Person {
private:
    int id;
    double grade;

public:
    void setId(int i) {
        id = i;
    }

    void setGrade(double g) {
        if (g >= 0 && g <= 100)
            grade = g;
        else
            grade = 0;
    }

    void printStudent() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "ID: " << id << endl;
        cout << "Grade: " << grade << endl;
    }
};

int main() {
    Student s;
    s.setName("Sara");
    s.setAge(19);
    s.setId(101);
    s.setGrade(92);

    s.printStudent();

    return 0;
}
```

### Answer to the question

`name` and `age` are `protected` so the derived class `Student` can directly access them. If they are `private`, only the `Person` class can access them directly.

---

## Exercise 14 Solution: Employee and Manager

```cpp
#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string name;
    double salary;

public:
    void setEmployee(string n, double s) {
        name = n;
        salary = (s >= 0) ? s : 0;
    }

    void printEmployee() {
        cout << "Name: " << name << endl;
        cout << "Salary: " << salary << endl;
    }
};

class Manager : public Employee {
private:
    double bonus;

public:
    void setBonus(double b) {
        bonus = (b >= 0) ? b : 0;
    }

    double getTotalSalary() {
        return salary + bonus;
    }

    void printManager() {
        cout << "Name: " << name << endl;
        cout << "Salary: " << salary << endl;
        cout << "Bonus: " << bonus << endl;
        cout << "Total Salary: " << getTotalSalary() << endl;
    }
};

int main() {
    Manager m;
    m.setEmployee("Ahmad", 900);
    m.setBonus(200);

    m.printManager();

    return 0;
}
```

---

## Exercise 15 Solution: Shape and Rectangle

```cpp
#include <iostream>
#include <string>
using namespace std;

class Shape {
protected:
    string color;

public:
    void setColor(string c) {
        color = c;
    }

    void printColor() {
        cout << "Color: " << color << endl;
    }
};

class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    void setRectangle(double w, double h) {
        width = (w >= 0) ? w : 0;
        height = (h >= 0) ? h : 0;
    }

    double getArea() {
        return width * height;
    }

    void printRectangle() {
        cout << "Color: " << color << endl;
        cout << "Width: " << width << endl;
        cout << "Height: " << height << endl;
        cout << "Area: " << getArea() << endl;
    }
};

int main() {
    Rectangle r;
    r.setColor("Blue");
    r.setRectangle(5, 3);
    r.printRectangle();

    return 0;
}
```

---

# Level 6: Inheritance with `vector`

## Exercise 16 Solution: Vector of Employees

```cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Employee {
protected:
    string name;
    double salary;

public:
    void setEmployee(string n, double s) {
        name = n;
        salary = (s >= 0) ? s : 0;
    }

    string getName() const {
        return name;
    }

    double getSalary() const {
        return salary;
    }
};

class Manager : public Employee {
private:
    double bonus;

public:
    void setManager(string n, double s, double b) {
        setEmployee(n, s);
        bonus = (b >= 0) ? b : 0;
    }

    double getTotalSalary() const {
        return salary + bonus;
    }

    void printManager() const {
        cout << "Name: " << name << endl;
        cout << "Salary: " << salary << endl;
        cout << "Bonus: " << bonus << endl;
        cout << "Total Salary: " << getTotalSalary() << endl;
    }
};

void addManager(vector<Manager>& managers) {
    Manager m;
    string name;
    double salary, bonus;

    cout << "Enter name: ";
    cin >> name;
    cout << "Enter salary: ";
    cin >> salary;
    cout << "Enter bonus: ";
    cin >> bonus;

    m.setManager(name, salary, bonus);
    managers.push_back(m);
}

void printAllManagers(const vector<Manager>& managers) {
    for (int i = 0; i < managers.size(); i++) {
        managers[i].printManager();
        cout << endl;
    }
}

void searchManagerByName(const vector<Manager>& managers, string name) {
    for (int i = 0; i < managers.size(); i++) {
        if (managers[i].getName() == name) {
            managers[i].printManager();
            return;
        }
    }
    cout << "Manager not found.\n";
}

void printHighestSalaryManager(const vector<Manager>& managers) {
    if (managers.size() == 0) {
        cout << "No managers.\n";
        return;
    }

    int maxIndex = 0;
    for (int i = 1; i < managers.size(); i++) {
        if (managers[i].getTotalSalary() > managers[maxIndex].getTotalSalary()) {
            maxIndex = i;
        }
    }

    managers[maxIndex].printManager();
}

int main() {
    vector<Manager> managers;
    int choice;
    string name;

    do {
        cout << "\n1. Add manager\n";
        cout << "2. Print all managers\n";
        cout << "3. Search manager by name\n";
        cout << "4. Print manager with highest total salary\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            addManager(managers);
        } else if (choice == 2) {
            printAllManagers(managers);
        } else if (choice == 3) {
            cout << "Enter name: ";
            cin >> name;
            searchManagerByName(managers, name);
        } else if (choice == 4) {
            printHighestSalaryManager(managers);
        }
    } while (choice != 5);

    return 0;
}
```

---

## Exercise 17 Solution: Library System

```cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Item {
protected:
    string title;
    int year;

public:
    void setItem(string t, int y) {
        title = t;
        year = y;
    }

    string getTitle() const { return title; }
    int getYear() const { return year; }
};

class Book : public Item {
private:
    string author;
    int pages;

public:
    void setBook(string t, int y, string a, int p) {
        setItem(t, y);
        author = a;
        pages = (p >= 0) ? p : 0;
    }

    void printBook() const {
        cout << "Title: " << title << endl;
        cout << "Year: " << year << endl;
        cout << "Author: " << author << endl;
        cout << "Pages: " << pages << endl;
    }
};

class Library {
private:
    vector<Book> books;

public:
    void addBook(Book b) {
        books.push_back(b);
    }

    void printAllBooks() {
        for (int i = 0; i < books.size(); i++) {
            books[i].printBook();
            cout << endl;
        }
    }

    void searchByTitle(string title) {
        for (int i = 0; i < books.size(); i++) {
            if (books[i].getTitle() == title) {
                books[i].printBook();
                return;
            }
        }
        cout << "Book not found.\n";
    }

    void printBooksAfterYear(int year) {
        for (int i = 0; i < books.size(); i++) {
            if (books[i].getYear() > year) {
                books[i].printBook();
                cout << endl;
            }
        }
    }
};

int main() {
    Library library;
    int choice, year, pages;
    string title, author;

    do {
        cout << "\n1. Add book\n";
        cout << "2. Print all books\n";
        cout << "3. Search by title\n";
        cout << "4. Print books after a year\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            Book b;
            cout << "Enter title: ";
            cin >> title;
            cout << "Enter year: ";
            cin >> year;
            cout << "Enter author: ";
            cin >> author;
            cout << "Enter pages: ";
            cin >> pages;

            b.setBook(title, year, author, pages);
            library.addBook(b);
        } else if (choice == 2) {
            library.printAllBooks();
        } else if (choice == 3) {
            cout << "Enter title: ";
            cin >> title;
            library.searchByTitle(title);
        } else if (choice == 4) {
            cout << "Enter year: ";
            cin >> year;
            library.printBooksAfterYear(year);
        }
    } while (choice != 5);

    return 0;
}
```

---

# Level 7: Combining `vector`, `set`, and `map`

## Exercise 18 Solution: Student Management System

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;

class Student {
private:
    int id;
    string name;
    int level;

public:
    void setStudent(int i, string n, int l) {
        id = i;
        name = n;
        level = l;
    }

    int getId() const { return id; }
    string getName() const { return name; }
    int getLevel() const { return level; }

    void print() const {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Level: " << level << endl;
    }
};

class StudentSystem {
private:
    vector<Student> students;
    set<int> studentIds;
    map<int, double> grades;

    int findStudentIndex(int id) {
        for (int i = 0; i < students.size(); i++) {
            if (students[i].getId() == id)
                return i;
        }
        return -1;
    }

public:
    void addStudent(Student s) {
        if (studentIds.count(s.getId()) > 0) {
            cout << "Student ID already exists.\n";
            return;
        }

        students.push_back(s);
        studentIds.insert(s.getId());
        cout << "Student added.\n";
    }

    void removeStudent(int id) {
        int index = findStudentIndex(id);

        if (index == -1) {
            cout << "Student not found.\n";
            return;
        }

        students.erase(students.begin() + index);
        studentIds.erase(id);
        grades.erase(id);
        cout << "Student removed.\n";
    }

    void setGrade(int id, double grade) {
        if (studentIds.count(id) == 0) {
            cout << "Student does not exist.\n";
        } else if (grade < 0 || grade > 100) {
            cout << "Invalid grade.\n";
        } else {
            grades[id] = grade;
            cout << "Grade saved.\n";
        }
    }

    void printStudent(int id) {
        int index = findStudentIndex(id);

        if (index == -1) {
            cout << "Student not found.\n";
            return;
        }

        students[index].print();

        if (grades.count(id) > 0)
            cout << "Grade: " << grades[id] << endl;
        else
            cout << "Grade: Not assigned\n";
    }

    void printAllStudents() {
        for (int i = 0; i < students.size(); i++) {
            printStudent(students[i].getId());
            cout << endl;
        }
    }

    double calculateAverageGrade() {
        if (grades.size() == 0)
            return 0;

        double sum = 0;
        for (auto x : grades) {
            sum += x.second;
        }

        return sum / grades.size();
    }
};

int main() {
    StudentSystem system;
    Student s;

    s.setStudent(101, "Ali", 1);
    system.addStudent(s);

    s.setStudent(102, "Sara", 2);
    system.addStudent(s);

    system.setGrade(101, 88);
    system.setGrade(102, 95);

    system.printAllStudents();
    cout << "Average grade: " << system.calculateAverageGrade() << endl;

    return 0;
}
```

---

## Exercise 19 Solution: Course Enrollment System

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;

class Student {
private:
    int id;
    string name;

public:
    void setStudent(int i, string n) {
        id = i;
        name = n;
    }

    int getId() const { return id; }
    string getName() const { return name; }
};

class Course {
private:
    string code;
    string title;
    set<int> studentIds;

public:
    void setCourse(string c, string t) {
        code = c;
        title = t;
    }

    string getCode() const { return code; }
    string getTitle() const { return title; }

    void addStudent(int id) {
        studentIds.insert(id);
    }

    void removeStudent(int id) {
        studentIds.erase(id);
    }

    bool hasStudent(int id) const {
        return studentIds.count(id) > 0;
    }

    void printStudents() const {
        cout << "Students in " << code << " - " << title << ":\n";
        for (int id : studentIds) {
            cout << id << endl;
        }
    }
};

class EnrollmentSystem {
private:
    vector<Student> students;
    vector<Course> courses;
    map<int, set<string>> studentCourses;

    int findStudentIndex(int id) {
        for (int i = 0; i < students.size(); i++) {
            if (students[i].getId() == id)
                return i;
        }
        return -1;
    }

    int findCourseIndex(string code) {
        for (int i = 0; i < courses.size(); i++) {
            if (courses[i].getCode() == code)
                return i;
        }
        return -1;
    }

public:
    void addStudent(int id, string name) {
        if (findStudentIndex(id) != -1) {
            cout << "Student ID already exists.\n";
            return;
        }

        Student s;
        s.setStudent(id, name);
        students.push_back(s);
        cout << "Student added.\n";
    }

    void addCourse(string code, string title) {
        if (findCourseIndex(code) != -1) {
            cout << "Course code already exists.\n";
            return;
        }

        Course c;
        c.setCourse(code, title);
        courses.push_back(c);
        cout << "Course added.\n";
    }

    void registerStudentInCourse(int id, string code) {
        int studentIndex = findStudentIndex(id);
        int courseIndex = findCourseIndex(code);

        if (studentIndex == -1) {
            cout << "Student does not exist.\n";
            return;
        }

        if (courseIndex == -1) {
            cout << "Course does not exist.\n";
            return;
        }

        if (courses[courseIndex].hasStudent(id)) {
            cout << "Student already registered in this course.\n";
            return;
        }

        courses[courseIndex].addStudent(id);
        studentCourses[id].insert(code);
        cout << "Registration successful.\n";
    }

    void dropStudentFromCourse(int id, string code) {
        int courseIndex = findCourseIndex(code);

        if (findStudentIndex(id) == -1 || courseIndex == -1) {
            cout << "Invalid student or course.\n";
            return;
        }

        courses[courseIndex].removeStudent(id);
        studentCourses[id].erase(code);
        cout << "Student dropped from course.\n";
    }

    void printStudentsInCourse(string code) {
        int index = findCourseIndex(code);

        if (index == -1) {
            cout << "Course not found.\n";
            return;
        }

        courses[index].printStudents();
    }

    void printCoursesForStudent(int id) {
        if (findStudentIndex(id) == -1) {
            cout << "Student not found.\n";
            return;
        }

        cout << "Courses for student " << id << ":\n";
        for (string code : studentCourses[id]) {
            cout << code << endl;
        }
    }
};

int main() {
    EnrollmentSystem system;

    system.addStudent(101, "Ali");
    system.addStudent(102, "Sara");

    system.addCourse("CS141", "Programming 1");
    system.addCourse("MATH101", "Calculus");

    system.registerStudentInCourse(101, "CS141");
    system.registerStudentInCourse(101, "MATH101");
    system.registerStudentInCourse(102, "CS141");

    system.printStudentsInCourse("CS141");
    system.printCoursesForStudent(101);

    return 0;
}
```

---

## Exercise 20 Solution: Simple University System

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;

class Person {
protected:
    int id;
    string name;

public:
    void setPerson(int i, string n) {
        id = i;
        name = n;
    }

    int getId() const { return id; }
    string getName() const { return name; }
};

class Student : public Person {
private:
    int level;

public:
    void setStudent(int i, string n, int l) {
        setPerson(i, n);
        level = l;
    }

    void print() const {
        cout << "Student ID: " << id << ", Name: " << name << ", Level: " << level << endl;
    }
};

class Instructor : public Person {
private:
    string department;

public:
    void setInstructor(int i, string n, string d) {
        setPerson(i, n);
        department = d;
    }

    void print() const {
        cout << "Instructor ID: " << id << ", Name: " << name
             << ", Department: " << department << endl;
    }
};

class Course {
private:
    string code;
    string title;

public:
    void setCourse(string c, string t) {
        code = c;
        title = t;
    }

    string getCode() const { return code; }
    string getTitle() const { return title; }

    void print() const {
        cout << "Course: " << code << " - " << title << endl;
    }
};

class UniversitySystem {
private:
    vector<Student> students;
    vector<Instructor> instructors;
    vector<Course> courses;
    set<int> studentIds;
    set<int> instructorIds;
    map<string, set<int>> courseStudents;
    map<string, int> courseInstructor;

    bool courseExists(string code) {
        for (int i = 0; i < courses.size(); i++) {
            if (courses[i].getCode() == code)
                return true;
        }
        return false;
    }

public:
    void addStudent(Student s) {
        if (studentIds.count(s.getId()) > 0) {
            cout << "Student ID already exists.\n";
            return;
        }

        students.push_back(s);
        studentIds.insert(s.getId());
    }

    void addInstructor(Instructor ins) {
        if (instructorIds.count(ins.getId()) > 0) {
            cout << "Instructor ID already exists.\n";
            return;
        }

        instructors.push_back(ins);
        instructorIds.insert(ins.getId());
    }

    void addCourse(Course c) {
        if (courseExists(c.getCode())) {
            cout << "Course already exists.\n";
            return;
        }

        courses.push_back(c);
    }

    void assignInstructorToCourse(int instructorId, string courseCode) {
        if (instructorIds.count(instructorId) == 0) {
            cout << "Instructor does not exist.\n";
            return;
        }

        if (!courseExists(courseCode)) {
            cout << "Course does not exist.\n";
            return;
        }

        courseInstructor[courseCode] = instructorId;
    }

    void registerStudentInCourse(int studentId, string courseCode) {
        if (studentIds.count(studentId) == 0) {
            cout << "Student does not exist.\n";
            return;
        }

        if (!courseExists(courseCode)) {
            cout << "Course does not exist.\n";
            return;
        }

        courseStudents[courseCode].insert(studentId);
    }

    void printCourseDetails(string courseCode) {
        cout << "Course code: " << courseCode << endl;

        if (courseInstructor.count(courseCode) > 0)
            cout << "Instructor ID: " << courseInstructor[courseCode] << endl;
        else
            cout << "Instructor: Not assigned\n";

        cout << "Registered students:\n";
        for (int id : courseStudents[courseCode]) {
            cout << id << endl;
        }
    }

    void printAllStudents() {
        for (int i = 0; i < students.size(); i++) {
            students[i].print();
        }
    }

    void printAllInstructors() {
        for (int i = 0; i < instructors.size(); i++) {
            instructors[i].print();
        }
    }
};

int main() {
    UniversitySystem system;

    Student s;
    s.setStudent(101, "Ali", 1);
    system.addStudent(s);

    Instructor ins;
    ins.setInstructor(201, "DrAhmed", "CS");
    system.addInstructor(ins);

    Course c;
    c.setCourse("CS141", "Programming 1");
    system.addCourse(c);

    system.assignInstructorToCourse(201, "CS141");
    system.registerStudentInCourse(101, "CS141");

    system.printCourseDetails("CS141");
    system.printAllStudents();
    system.printAllInstructors();

    return 0;
}
```

---

# Debugging Exercises

## Exercise 21 Solution: Fix the Encapsulation Error

### What is wrong?

`name` and `grade` are private. They cannot be accessed directly from `main()`.

### Fixed code

```cpp
#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    double grade;

public:
    void setName(string n) {
        name = n;
    }

    void setGrade(double g) {
        if (g >= 0 && g <= 100)
            grade = g;
        else
            grade = 0;
    }

    string getName() {
        return name;
    }

    double getGrade() {
        return grade;
    }
};

int main() {
    Student s;
    s.setName("Ali");
    s.setGrade(90);

    cout << s.getName() << endl;
    cout << s.getGrade() << endl;

    return 0;
}
```

---

## Exercise 22 Solution: Fix the Inheritance Error

### Why does this code not work?

The variable `name` is private inside `Person`. A derived class cannot directly access private data members of the base class.

### Solution 1: Using `protected`

```cpp
#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;

public:
    void setName(string n) {
        name = n;
    }
};

class Student : public Person {
public:
    void printName() {
        cout << name << endl;
    }
};

int main() {
    Student s;
    s.setName("Ali");
    s.printName();

    return 0;
}
```

### Solution 2: Using a public getter

```cpp
#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string name;

public:
    void setName(string n) {
        name = n;
    }

    string getName() {
        return name;
    }
};

class Student : public Person {
public:
    void printName() {
        cout << getName() << endl;
    }
};

int main() {
    Student s;
    s.setName("Ali");
    s.printName();

    return 0;
}
```

### Comparison

Using `protected` allows the derived class to access the variable directly. Using a public getter keeps the data more protected and is usually better for encapsulation.

---

## Exercise 23 Solution: Duplicate ID Problem

### What is the problem?

A `vector<int>` allows duplicate values, so the same ID can be inserted more than once.

### Fixed code using `set<int>`

```cpp
#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> ids;
    int id;

    for (int i = 0; i < 3; i++) {
        cout << "Enter ID: ";
        cin >> id;

        if (ids.count(id) > 0) {
            cout << "This ID already exists.\n";
        } else {
            ids.insert(id);
            cout << "ID added.\n";
        }
    }

    cout << "All IDs:\n";
    for (int x : ids) {
        cout << x << endl;
    }

    return 0;
}
```

---

# Tracing Exercises

## Exercise 24 Solution: Trace the Output

### Output

```text
Sara 105
```

### Explanation

The object `s` stores the name `Sara` in the inherited `name` variable from `Person`. It also stores `105` in the private `id` variable inside `Student`. The `print()` function prints both values.

---

## Exercise 25 Solution: Trace the Map

### What is stored in the map?

The map stores names as keys and the number of times each name appears as values.

```text
Ali  -> 3
Omar -> 1
Sara -> 2
```

### Output

```text
Ali 3
Omar 1
Sara 2
```

### Why does `counter["Ali"]++` work?

If the key does not exist, `map` automatically creates it with the default value `0`. Then `++` increases it by `1`.

---

# Suggested Final Homework Solution

## Mini Student Registration System

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    void setPerson(string n, int a) {
        name = n;
        age = (a >= 0) ? a : 0;
    }

    string getName() const { return name; }
    int getAge() const { return age; }
};

class Student : public Person {
private:
    int id;

public:
    void setStudent(int i, string n, int a) {
        id = i;
        setPerson(n, a);
    }

    int getId() const {
        return id;
    }

    void printBasicInfo() const {
        cout << "Student ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Course {
private:
    string code;
    string title;

public:
    void setCourse(string c, string t) {
        code = c;
        title = t;
    }

    string getCode() const {
        return code;
    }

    string getTitle() const {
        return title;
    }

    void printCourse() const {
        cout << "Course: " << code << endl;
        cout << "Title: " << title << endl;
    }
};

class RegistrationSystem {
private:
    vector<Student> students;
    vector<Course> courses;
    set<int> studentIds;
    set<string> courseCodes;
    map<int, double> grades;
    map<string, set<int>> courseRegistrations;

    int findStudentIndex(int id) {
        for (int i = 0; i < students.size(); i++) {
            if (students[i].getId() == id)
                return i;
        }
        return -1;
    }

    int findCourseIndex(string code) {
        for (int i = 0; i < courses.size(); i++) {
            if (courses[i].getCode() == code)
                return i;
        }
        return -1;
    }

public:
    void addStudent() {
        int id, age;
        string name;

        cout << "Enter student ID: ";
        cin >> id;

        if (studentIds.count(id) > 0) {
            cout << "Student ID already exists.\n";
            return;
        }

        cout << "Enter name: ";
        cin >> name;
        cout << "Enter age: ";
        cin >> age;

        Student s;
        s.setStudent(id, name, age);

        students.push_back(s);
        studentIds.insert(id);

        cout << "Student added.\n";
    }

    void addCourse() {
        string code, title;

        cout << "Enter course code: ";
        cin >> code;

        if (courseCodes.count(code) > 0) {
            cout << "Course code already exists.\n";
            return;
        }

        cout << "Enter course title: ";
        cin >> title;

        Course c;
        c.setCourse(code, title);

        courses.push_back(c);
        courseCodes.insert(code);

        cout << "Course added.\n";
    }

    void registerStudentInCourse() {
        int id;
        string code;

        cout << "Enter student ID: ";
        cin >> id;
        cout << "Enter course code: ";
        cin >> code;

        if (studentIds.count(id) == 0) {
            cout << "Student does not exist.\n";
            return;
        }

        if (courseCodes.count(code) == 0) {
            cout << "Course does not exist.\n";
            return;
        }

        if (courseRegistrations[code].count(id) > 0) {
            cout << "Student already registered in this course.\n";
            return;
        }

        courseRegistrations[code].insert(id);
        cout << "Registration successful.\n";
    }

    void dropStudentFromCourse() {
        int id;
        string code;

        cout << "Enter student ID: ";
        cin >> id;
        cout << "Enter course code: ";
        cin >> code;

        if (courseRegistrations[code].erase(id) > 0)
            cout << "Student dropped.\n";
        else
            cout << "Registration not found.\n";
    }

    void setStudentGrade() {
        int id;
        double grade;

        cout << "Enter student ID: ";
        cin >> id;

        if (studentIds.count(id) == 0) {
            cout << "Student does not exist.\n";
            return;
        }

        cout << "Enter grade: ";
        cin >> grade;

        if (grade < 0 || grade > 100) {
            cout << "Invalid grade.\n";
            return;
        }

        grades[id] = grade;
        cout << "Grade saved.\n";
    }

    void printStudentReport() {
        int id;
        cout << "Enter student ID: ";
        cin >> id;

        int index = findStudentIndex(id);
        if (index == -1) {
            cout << "Student not found.\n";
            return;
        }

        students[index].printBasicInfo();

        if (grades.count(id) > 0)
            cout << "Grade: " << grades[id] << endl;
        else
            cout << "Grade: Not assigned\n";

        cout << "Registered courses:\n";
        for (auto x : courseRegistrations) {
            string code = x.first;
            set<int> ids = x.second;

            if (ids.count(id) > 0) {
                cout << code << endl;
            }
        }
    }

    void printCourseReport() {
        string code;
        cout << "Enter course code: ";
        cin >> code;

        int index = findCourseIndex(code);
        if (index == -1) {
            cout << "Course not found.\n";
            return;
        }

        courses[index].printCourse();

        cout << "Registered students:\n";
        for (int id : courseRegistrations[code]) {
            cout << id << endl;
        }
    }

    void printHighestGradeStudent() {
        if (grades.size() == 0) {
            cout << "No grades.\n";
            return;
        }

        int bestId = grades.begin()->first;
        double bestGrade = grades.begin()->second;

        for (auto x : grades) {
            if (x.second > bestGrade) {
                bestId = x.first;
                bestGrade = x.second;
            }
        }

        cout << "Highest grade student ID: " << bestId << endl;
        cout << "Highest grade: " << bestGrade << endl;
    }

    void printAverageGrade() {
        if (grades.size() == 0) {
            cout << "No grades.\n";
            return;
        }

        double sum = 0;
        for (auto x : grades) {
            sum += x.second;
        }

        cout << "Average grade: " << sum / grades.size() << endl;
    }

    void printStudentsWithNoCourses() {
        for (int id : studentIds) {
            bool found = false;

            for (auto x : courseRegistrations) {
                if (x.second.count(id) > 0) {
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << id << endl;
            }
        }
    }

    void printCourseCounts() {
        for (auto x : courseRegistrations) {
            cout << x.first << ": " << x.second.size() << " students" << endl;
        }
    }
};

int main() {
    RegistrationSystem system;
    int choice;

    do {
        cout << "\n1. Add student\n";
        cout << "2. Add course\n";
        cout << "3. Register student in course\n";
        cout << "4. Drop student from course\n";
        cout << "5. Set student grade\n";
        cout << "6. Print student report\n";
        cout << "7. Print course report\n";
        cout << "8. Print highest grade student\n";
        cout << "9. Print average grade\n";
        cout << "10. Print students with no courses\n";
        cout << "11. Count students in each course\n";
        cout << "12. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
            system.addStudent();
        else if (choice == 2)
            system.addCourse();
        else if (choice == 3)
            system.registerStudentInCourse();
        else if (choice == 4)
            system.dropStudentFromCourse();
        else if (choice == 5)
            system.setStudentGrade();
        else if (choice == 6)
            system.printStudentReport();
        else if (choice == 7)
            system.printCourseReport();
        else if (choice == 8)
            system.printHighestGradeStudent();
        else if (choice == 9)
            system.printAverageGrade();
        else if (choice == 10)
            system.printStudentsWithNoCourses();
        else if (choice == 11)
            system.printCourseCounts();
        else if (choice == 12)
            cout << "Goodbye.\n";
        else
            cout << "Invalid choice.\n";

    } while (choice != 12);

    return 0;
}
```
