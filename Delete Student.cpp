#include <iostream>
using namespace std;

const int MAX_STUDENTS = 100;

struct Student {
    int id;
    string name;
    int age;
};

void deleteStudent(Student students[], int& studentCount, int deleteID) {
    bool found = false;

    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == deleteID) {
            found = true;

            // Shift the remaining students left
            for (int j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];
            }

            studentCount--; // Decrease count
            cout << "Student with ID " << deleteID << " has been deleted.\n";
            break;
        }
    }

    if (!found) {
        cout << "Student with ID " << deleteID << " not found.\n";
    }
}

// Simple function to display students
void displayStudents(Student students[], int studentCount) {
    if (studentCount == 0) {
        cout << "No students to display.\n";
        return;
    }

    cout << "\n--- Student List ---\n";
    for (int i = 0; i < studentCount; i++) {
        cout << "ID: " << students[i].id
             << ", Name: " << students[i].name
             << ", Age: " << students[i].age << "\n";
    }
    cout << "---------------------\n";
}

int main() {
    Student students[MAX_STUDENTS];
    int studentCount = 3; // let's add 3 students manually for now

    // Adding sample students
    students[0] = {101, "Alice", 20};
    students[1] = {102, "Bob", 21};
    students[2] = {103, "Charlie", 22};

    // Show current students
    displayStudents(students, studentCount);

    // Ask for student ID to delete
    int idToDelete;
    cout << "\nEnter ID of student to delete: ";
    cin >> idToDelete;

    deleteStudent(students, studentCount, idToDelete);

    // Show updated list
    displayStudents(students, studentCount);

    return 0;
}