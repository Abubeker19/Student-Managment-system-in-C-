#include <iostream>
using namespace std;

const int MAX_STUDENTS = 100;
const int MAX_NAME_LENGTH = 50;

struct Student {
    int rollNumber;
    char name[MAX_NAME_LENGTH];
    float marks;
};

Student students[MAX_STUDENTS];
int studentCount = 0;

// Function to collect student info and return a Student struct
Student createStudent() {
    Student s;
    
    cout << "\n Add New Student\n";
    cout << "Enter roll number: ";
    cin >> s.rollNumber;
    cin.ignore();

    cout << "Enter name: ";
    cin.getline(s.name, MAX_NAME_LENGTH);

    cout << "Enter marks: ";
    cin >> s.marks;

    return s;
}

// Function to add student to array
void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        cout << " Cannot add more students. Maximum capacity reached.\n";
        return;
    }

    students[studentCount] = createStudent();
    studentCount++;

    cout << " Student added successfully!\n";
}

int main() {
    char choice;

    do {
        addStudent();
        cout << "\nDo you want to add another student? (y/n): ";
        cin >> choice;
        cin.ignore();
    } while (choice == 'y' || choice == 'Y');

    cout << "\n Done adding students. Program ended.\n";
    return 0;
}
