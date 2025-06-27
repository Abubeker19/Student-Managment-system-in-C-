#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Struct to represent a student with basic info and modules
struct Student {
    int rollNumber;
    string name;
    int age;
    string major;
    float marks;
    vector<string> modules;

    // Display student details
    void display() const {
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Major: " << major << endl;
        cout << "Marks: " << marks << endl;

        cout << "Modules: ";
        for (const auto& mod : modules) {
            cout << mod << " ";
        }
        cout << "\n------------------------\n";
    }

    // Edit details
    void edit() {
        string input;
        int inputAge;

        cout << "Editing student: " << name << endl;

        cout << "Enter new name (or press Enter to keep): ";
        cin.ignore();
        getline(cin, input);
        if (!input.empty()) name = input;

        cout << "Enter new age (or 0 to keep): ";
        cin >> inputAge;
        if (inputAge != 0) age = inputAge;

        cin.ignore();
        cout << "Enter new major (or press Enter to keep): ";
        getline(cin, input);
        if (!input.empty()) major = input;

        cout << "Enter new marks (or -1 to keep): ";
        float newMarks;
        cin >> newMarks;
        if (newMarks >= 0) marks = newMarks;

        modules.clear();
        int moduleCount;
        cout << "How many modules? ";
        cin >> moduleCount;
        cin.ignore();

        for (int i = 0; i < moduleCount; ++i) {
            string mod;
            cout << "Enter module " << i + 1 << ": ";
            getline(cin, mod);
            modules.push_back(mod);
        }
    }
};

// Calculates the average of marks
double calculateAverage(const vector<Student>& students) {
    if (students.empty()) return 0;
    float sum = 0;
    for (const auto& s : students) sum += s.marks;
    return sum / students.size();
}

// Returns the highest mark
float findHighest(const vector<Student>& students) {
    float high = students[0].marks;
    for (const auto& s : students)
        if (s.marks > high) high = s.marks;
    return high;
}

// Returns the lowest mark
float findLowest(const vector<Student>& students) {
    float low = students[0].marks;
    for (const auto& s : students)
        if (s.marks < low) low = s.marks;
    return low;
}

int main() {
    vector<Student> students;
    char choice;

    // Add students loop
    do {
        Student s;
        cout << "\n--- Add New Student ---\n";
        cout << "Roll Number: ";
        cin >> s.rollNumber;
        cin.ignore();

        cout << "Name: ";
        getline(cin, s.name);

        cout << "Age: ";
        cin >> s.age;
        cin.ignore();

        cout << "Major: ";
        getline(cin, s.major);

        cout << "Marks: ";
        cin >> s.marks;
        cin.ignore();

        int moduleCount;
        cout << "Number of modules: ";
        cin >> moduleCount;
        cin.ignore();

        for (int i = 0; i < moduleCount; ++i) {
            string mod;
            cout << "Enter module " << i + 1 << ": ";
            getline(cin, mod);
            s.modules.push_back(mod);
        }

        students.push_back(s);

        cout << "Add another student? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    // Edit or skip editing
    cout << "\nDo you want to edit a student's details? (y/n): ";
    cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        int roll;
        cout << "Enter roll number of student to edit: ";
        cin >> roll;

        for (auto& s : students) {
            if (s.rollNumber == roll) {
                s.edit();
                break;
            }
        }
    }

    // Display all students
    cout << "\n--- All Students ---\n";
    for (const auto& s : students) {
        s.display();
    }

    // Statistics
    if (!students.empty()) {
        cout << "--- Statistics ---\n";
        cout << "Average Marks: " << calculateAverage(students) << endl;
        cout << "Highest Marks: " << findHighest(students) << endl;
        cout << "Lowest Marks: " << findLowest(students) << endl;
    }

    return 0;
}
