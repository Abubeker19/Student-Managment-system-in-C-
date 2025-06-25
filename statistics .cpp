#include <iostream>

using namespace std;

// Function to calculate average
double calculateAverage(int marks[], int size) {
    double sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += marks[i];
    }
    return size == 0 ? 0 : sum / size;
}

// Function to find highest mark
int findHighest(int marks[], int size) {
    int highest = marks[0];
    for (int i = 1; i < size; ++i) {
        if (marks[i] > highest)
            highest = marks[i];
    }
    return highest;
}

// Function to find lowest mark
int findLowest(int marks[], int size) {
    int lowest = marks[0];
    for (int i = 1; i < size; ++i) {
        if (marks[i] < lowest)
            lowest = marks[i];
    }
    return lowest;
}

int main() {
    int numStudents;

    cout << "Enter number of students: ";
    cin >> numStudents;

    // Limit for safety
    if (numStudents <= 0 || numStudents > 100) {
        cout << "Invalid number of students. Please enter between 1 and 100.\n";
        return 1;
    }

    int marks[100]; // Fixed-size array

    for (int i = 0; i < numStudents; ++i) {
        cout << "Enter mark for student " << i + 1 << ": ";
        cin >> marks[i];
    }

    cout << "\n--- Class Statistics ---\n";
    cout << "Average Mark: " << calculateAverage(marks, numStudents) << endl;
    cout << "Highest Mark: " << findHighest(marks, numStudents) << endl;
    cout << "Lowest Mark: " << findLowest(marks, numStudents) << endl;

    return 0;
}