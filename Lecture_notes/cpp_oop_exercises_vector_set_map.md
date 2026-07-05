# C++ OOP Exercise Set

## Focus

This exercise set is designed to help students practice:

- Encapsulation
- Inheritance
- Access specifiers: `public`, `private`, `protected`
- `vector`
- `set`
- `map`
- Basic programming techniques such as loops, functions, validation, searching, counting, menus, and simple statistics

The target students already know basic OOP concepts in C++, especially encapsulation, inheritance, and access specifiers.

---

# Level 1: Encapsulation and Basic Classes

## Exercise 1: Student Class

Create a class `Student`.

Each student has:

```cpp
private:
    string name;
    int id;
    double grade;
```

Requirements:

1. Create setters and getters.
2. Do not allow grade to be less than `0` or greater than `100`.
3. Add a function:

```cpp
void printInfo();
```

4. In `main()`, create three students and print their information.

Example output:

```text
Name: Ali
ID: 101
Grade: 87.5
```

---

## Exercise 2: Bank Account

Create a class `BankAccount`.

Private data:

```cpp
string ownerName;
int accountNumber;
double balance;
```

Functions:

```cpp
void deposit(double amount);
void withdraw(double amount);
double getBalance();
void printAccount();
```

Rules:

- Deposit must be positive.
- Withdraw is allowed only if the balance is enough.
- Balance should not be directly accessed from `main()`.

Add a small menu:

```text
1. Deposit
2. Withdraw
3. Show Balance
4. Exit
```

This exercise practices encapsulation, conditionals, loops, and menu design.

---

## Exercise 3: Product Class with Discount

Create a class `Product`.

Private data:

```cpp
string name;
double price;
int quantity;
```

Functions:

```cpp
double getTotalPrice();
void applyDiscount(double percent);
void printProduct();
```

Rules:

- Price and quantity cannot be negative.
- Discount must be between `0` and `100`.

In `main()`, read product information from the user and print the final price after discount.

---

# Level 2: Using `vector` with Classes

## Exercise 4: Vector of Students

Use the `Student` class from Exercise 1.

Create:

```cpp
vector<Student> students;
```

Write a program that allows the user to:

```text
1. Add student
2. Print all students
3. Search student by ID
4. Print students with grade >= 90
5. Exit
```

Required functions:

```cpp
void addStudent(vector<Student>& students);
void printAllStudents(const vector<Student>& students);
void searchById(const vector<Student>& students, int id);
void printExcellentStudents(const vector<Student>& students);
```

This exercise practices:

- OOP
- `vector`
- functions
- searching
- loops
- passing objects to functions

---

## Exercise 5: Classroom Average

Create a class `Course`.

Private data:

```cpp
string courseName;
vector<Student> students;
```

Functions:

```cpp
void addStudent(Student s);
double calculateAverage();
Student getHighestStudent();
void printCourseReport();
```

The report should print:

```text
Course: Programming 1
Number of students: 5
Average grade: 82.4
Highest student: Sara, 97
```

This exercise practices object composition: a `Course` object contains many `Student` objects.

---

## Exercise 6: Remove Failed Students

Using the same `Course` class, add a function:

```cpp
void removeFailedStudents();
```

A student fails if grade is less than `60`.

Before removing:

```text
Ali 55
Sara 90
Omar 48
Mona 77
```

After removing:

```text
Sara 90
Mona 77
```

Do not use advanced STL functions. Use loops and `erase`.

---

# Level 3: Using `set` with Classes and Data

## Exercise 7: Unique Student IDs

Create a program that stores student IDs in:

```cpp
set<int> studentIds;
```

The program should allow the user to:

```text
1. Add student ID
2. Remove student ID
3. Search for student ID
4. Print all IDs
5. Exit
```

Rules:

- Duplicate IDs should not be added.
- Print a message if the ID already exists.

Example:

```text
Enter ID: 105
ID added.

Enter ID: 105
This ID already exists.
```

---

## Exercise 8: Course Registration System

Create two classes:

```cpp
class Student
class Course
```

Each `Course` has:

```cpp
private:
    string courseCode;
    set<int> registeredStudentIds;
```

Functions:

```cpp
void registerStudent(int id);
void dropStudent(int id);
bool isRegistered(int id);
void printRegisteredStudents();
```

Rules:

- A student cannot register twice.
- Dropping a non-existing student should show an error message.

This exercise practices:

- encapsulation
- `set`
- membership checking
- basic registration logic

---

## Exercise 9: Attendance System

Create a class `Attendance`.

Private data:

```cpp
string date;
set<int> presentStudentIds;
```

Functions:

```cpp
void markPresent(int id);
void markAbsent(int id);
bool isPresent(int id);
void printPresentStudents();
int countPresent();
```

Add a menu that allows the teacher to mark attendance.

Extra task:

Ask the user for the total number of students, then calculate:

```text
Number present
Number absent
Attendance percentage
```

---

# Level 4: Using `map`

## Exercise 10: Student Grades Using `map`

Use:

```cpp
map<int, double> grades;
```

Where:

- key = student ID
- value = grade

The program should allow:

```text
1. Add or update grade
2. Print grade by ID
3. Print all grades
4. Print average grade
5. Exit
```

Example:

```text
ID: 101, Grade: 88
ID: 102, Grade: 91
ID: 103, Grade: 76
```

This exercise practices:

- `map`
- key-value storage
- searching
- updating
- calculating average

---

## Exercise 11: Student Names and Grades

Create a class `GradeBook`.

Private data:

```cpp
map<int, string> studentNames;
map<int, double> studentGrades;
```

Functions:

```cpp
void addStudent(int id, string name);
void setGrade(int id, double grade);
void printStudent(int id);
void printAllStudents();
double calculateAverage();
```

Rules:

- You cannot set a grade for a student that does not exist.
- Grade must be between `0` and `100`.
- ID must be unique.

Example output:

```text
ID: 101
Name: Ali
Grade: 89
```

---

## Exercise 12: Count Repeated Names

Create a class `NameCounter`.

Private data:

```cpp
map<string, int> nameFrequency;
```

Functions:

```cpp
void addName(string name);
void printFrequency();
int getCount(string name);
```

Example input:

```text
Ali
Sara
Ali
Omar
Sara
Ali
```

Example output:

```text
Ali appears 3 times
Sara appears 2 times
Omar appears 1 time
```

This exercise practices:

- `map`
- counting
- strings
- loops

---

# Level 5: Inheritance and Access Specifiers

## Exercise 13: Person and Student

Create a base class `Person`.

Protected data:

```cpp
string name;
int age;
```

Functions:

```cpp
void setName(string n);
void setAge(int a);
void printPerson();
```

Create a derived class `Student`.

Private data:

```cpp
int id;
double grade;
```

Functions:

```cpp
void setId(int i);
void setGrade(double g);
void printStudent();
```

In `printStudent()`, print name, age, ID, and grade.

Question for students:

Why should `name` and `age` be `protected` instead of `private`?

---

## Exercise 14: Employee and Manager

Create a base class `Employee`.

Protected data:

```cpp
string name;
double salary;
```

Functions:

```cpp
void setEmployee(string n, double s);
void printEmployee();
```

Create a derived class `Manager`.

Private data:

```cpp
double bonus;
```

Functions:

```cpp
void setBonus(double b);
double getTotalSalary();
void printManager();
```

Example:

```text
Name: Ahmad
Salary: 900
Bonus: 200
Total Salary: 1100
```

This exercise practices inheritance and protected members.

---

## Exercise 15: Shape and Rectangle

Create a base class `Shape`.

Protected data:

```cpp
string color;
```

Functions:

```cpp
void setColor(string c);
void printColor();
```

Create a derived class `Rectangle`.

Private data:

```cpp
double width;
double height;
```

Functions:

```cpp
double getArea();
void printRectangle();
```

Example output:

```text
Color: Blue
Width: 5
Height: 3
Area: 15
```

---

# Level 6: Inheritance with `vector`

## Exercise 16: Vector of Employees

Use the following classes:

```cpp
class Employee
class Manager : public Employee
```

Create:

```cpp
vector<Manager> managers;
```

The program should allow:

```text
1. Add manager
2. Print all managers
3. Search manager by name
4. Print manager with highest total salary
5. Exit
```

This exercise practices:

- inheritance
- vectors of objects
- searching
- maximum value logic

---

## Exercise 17: Library System

Create a base class `Item`.

Protected data:

```cpp
string title;
int year;
```

Create a derived class `Book`.

Private data:

```cpp
string author;
int pages;
```

Create a class `Library`.

Private data:

```cpp
vector<Book> books;
```

Functions:

```cpp
void addBook(Book b);
void printAllBooks();
void searchByTitle(string title);
void printBooksAfterYear(int year);
```

Example menu:

```text
1. Add book
2. Print all books
3. Search by title
4. Print books after a year
5. Exit
```

This is a good mini-project exercise.

---

# Level 7: Combining `vector`, `set`, and `map`

## Exercise 18: Student Management System

Create a class `Student`.

Private data:

```cpp
int id;
string name;
int level;
```

Create a class `StudentSystem`.

Private data:

```cpp
vector<Student> students;
set<int> studentIds;
map<int, double> grades;
```

Functions:

```cpp
void addStudent(Student s);
void removeStudent(int id);
void setGrade(int id, double grade);
void printStudent(int id);
void printAllStudents();
double calculateAverageGrade();
```

Rules:

- Use `set<int>` to make sure student IDs are unique.
- Use `map<int, double>` to store grades.
- Use `vector<Student>` to store student objects.
- You cannot add two students with the same ID.
- You cannot assign a grade to a student that does not exist.

This exercise combines all required concepts.

---

## Exercise 19: Course Enrollment System

Create these classes:

```cpp
class Student
class Course
class EnrollmentSystem
```

`Student` has:

```cpp
int id;
string name;
```

`Course` has:

```cpp
string code;
string title;
set<int> studentIds;
```

`EnrollmentSystem` has:

```cpp
vector<Student> students;
vector<Course> courses;
map<int, set<string>> studentCourses;
```

The program should allow:

```text
1. Add student
2. Add course
3. Register student in course
4. Drop student from course
5. Print students in a course
6. Print courses for a student
7. Exit
```

Rules:

- Student ID must be unique.
- Course code must be unique.
- A student cannot register twice in the same course.
- A student cannot register in a course that does not exist.
- A student cannot register if the student does not exist.

This is a stronger mini-project.

---

## Exercise 20: Simple University System

Create a small university system using OOP.

Classes:

```cpp
class Person
class Student : public Person
class Instructor : public Person
class Course
class UniversitySystem
```

Use:

```cpp
vector<Student> students;
vector<Instructor> instructors;
vector<Course> courses;
set<int> studentIds;
set<int> instructorIds;
map<string, set<int>> courseStudents;
map<string, int> courseInstructor;
```

Required features:

```text
1. Add student
2. Add instructor
3. Add course
4. Assign instructor to course
5. Register student in course
6. Print course details
7. Print all students
8. Print all instructors
9. Exit
```

This exercise is suitable as a final OOP lab or homework.

---

# Debugging Exercises

## Exercise 21: Fix the Encapsulation Error

The following code has a problem:

```cpp
class Student {
private:
    string name;
    double grade;
};

int main() {
    Student s;
    s.name = "Ali";
    s.grade = 90;
}
```

Tasks:

1. Explain why this code is wrong.
2. Fix it using setters and getters.
3. Add validation so grade must be between `0` and `100`.

---

## Exercise 22: Fix the Inheritance Error

```cpp
class Person {
private:
    string name;
};

class Student : public Person {
public:
    void printName() {
        cout << name << endl;
    }
};
```

Tasks:

1. Why does this code not work?
2. Fix it using `protected`.
3. Fix it again using a public getter instead.

Ask students to compare both solutions.

---

## Exercise 23: Duplicate ID Problem

A student wrote this code:

```cpp
vector<int> ids;

ids.push_back(101);
ids.push_back(102);
ids.push_back(101);
```

Tasks:

1. What is the problem?
2. Rewrite the code using `set<int>`.
3. Print a message when the ID already exists.

---

# Tracing Exercises

## Exercise 24: Trace the Output

```cpp
class Person {
protected:
    string name;

public:
    void setName(string n) {
        name = n;
    }
};

class Student : public Person {
private:
    int id;

public:
    void setId(int i) {
        id = i;
    }

    void print() {
        cout << name << " " << id << endl;
    }
};

int main() {
    Student s;
    s.setName("Sara");
    s.setId(105);
    s.print();
}
```

Question:

What is the output?

---

## Exercise 25: Trace the Map

```cpp
map<string, int> counter;

counter["Ali"]++;
counter["Sara"]++;
counter["Ali"]++;
counter["Omar"]++;
counter["Sara"]++;
counter["Ali"]++;

for (auto x : counter) {
    cout << x.first << " " << x.second << endl;
}
```

Questions:

1. What is stored in the map?
2. What is the output?
3. Why does `counter["Ali"]++` work even if `"Ali"` was not inserted before?

---

# Suggested Final Homework

## Final Homework: Mini Student Registration System

Create a complete program using:

- Encapsulation
- Inheritance
- `vector`
- `set`
- `map`
- Menu
- Functions
- Input validation

Classes:

```cpp
class Person
class Student : public Person
class Course
class RegistrationSystem
```

Minimum requirements:

```text
1. Add student
2. Add course
3. Register student in course
4. Drop student from course
5. Set student grade
6. Print student report
7. Print course report
8. Exit
```

Use:

```cpp
vector<Student> students;
vector<Course> courses;
set<int> studentIds;
set<string> courseCodes;
map<int, double> grades;
map<string, set<int>> courseRegistrations;
```

Example student report:

```text
Student ID: 101
Name: Ali
Age: 19
Grade: 87.5
Registered courses:
CS141
MATH101
```

Example course report:

```text
Course: CS141
Title: Introduction to Programming
Registered students:
101
104
109
```

Bonus tasks:

1. Print the student with the highest grade.
2. Print the average grade.
3. Print students with no courses.
4. Prevent duplicate registration.
5. Count how many students are registered in each course.

---

# Notes for Students

Before solving each exercise, think about:

1. What classes do I need?
2. Which data should be `private`?
3. Which data can be `protected` for inheritance?
4. Which functions should be `public`?
5. Should I use `vector`, `set`, or `map`?
6. What validation is needed?
7. What menu options are required?

---

# Suggested Progression

Students should solve the exercises in this order:

1. Exercises 1 to 3: Encapsulation basics
2. Exercises 4 to 6: Classes with `vector`
3. Exercises 7 to 9: Unique data with `set`
4. Exercises 10 to 12: Key-value storage with `map`
5. Exercises 13 to 17: Inheritance
6. Exercises 18 to 20: Mini-projects
7. Exercises 21 to 25: Debugging and tracing
8. Final Homework: Complete student registration system
