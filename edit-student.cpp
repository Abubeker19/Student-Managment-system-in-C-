#include <iostream>
#include <string>
using namespace std;
class Student {
private:
    string name;
    int age;
    string major;

public:
    // Constructor
    Student(string n, int a,string m) : name(n), age(a), major(m) {}

    // Function to display student details
    void displayDetails() const {
        cout << "Student Details:\n";
        cout << "Name: " << name << "\n";
        cout << "Age: " << age << "\n";
        cout << "Major: " << major << "\n";
    }

    // Function to edit student details
    void editDetails() {
        cout << "Editing Student Details:\n";

        // Show current details
        cout << "Current Name: " << name << "\n";
        cout << "Enter new name (leave blank to keep current): ";
        string newName;
        getline(cin, newName);
        if (!newName.empty()) {
            name = newName;
        }

        cout << "Current Age: " << age << "\n";
        cout << "Enter new age (0 to keep current): ";
        int newAge;
        cin >> newAge;
        if (newAge != 0) {
            age = newAge;
        }
        cin.ignore();  // Ignore newline character left in the buffer

        cout << "Current Major: " << major << "\n";
        cout << "Enter new major (leave blank to keep current): ";
        string newMajor;
        getline(cin, newMajor);
        if (!newMajor.empty()) {
            major = newMajor;
        }
    }
};

int main() {
    // Create a student object with initial details
    Student student("John Doe", 20, "Computer Science");

    // Display current details
    student.displayDetails();

    // Edit student details
    student.editDetails();

    // Display updated details
    cout << "\nUpdated ";
    student.displayDetails();

    return 0;
}