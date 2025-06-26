#include <iostream>
#include <string>
using namespace std;

// Define structure for Student
struct Student {
    int rollNumber;
    string name;
    float marks;
};

// Function to search student by roll number
void searchStudent(Student students[], int studentCount) {
    if (studentCount == 0) {
        cout << "No students available in the system.\n";
        return;
    }

    int searchRoll;
    cout << "Enter roll number to search: ";
    cin >> searchRoll;

    bool found = false;

    for (int i = 0; i < studentCount; ++i) {
        if (students[i].rollNumber == searchRoll) {
            cout << "\nStudent Found:\n";
            cout << "Roll Number: " << students[i].rollNumber << endl;
            cout << "Name       : " << students[i].name << endl;
            cout << "Marks      : " << students[i].marks << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student with roll number " << searchRoll << " not found.\n";
    }
}

// Main function
int main() {
    // Example student data with names A, B, C
    Student students[3] = {
        {1, "A", 88.5},
        {2, "B", 75.0},
        {3, "C", 91.2},
    };

    int studentCount = 3;

    // Call the search function
    searchStudent(students, studentCount);

    return 0;
}
