#include <iostream>
using namespace std;

struct Student {
    std::string name;
    std::vector<std::string> modules;
};

void displayStudentModules(const std::vector<Student>& students) {
    for (const auto& student : students) {
        std::cout << "Student Name: " << student.name << std::endl;
        std::cout << "Modules:" << std::endl;
        for (const auto& module : student.modules) {
            std::cout << "- " << module << std::endl;
        }
        std::cout << std::endl; // Add a blank line for better readability
    }
}

int main() {
    // Sample data: List of students with their modules
    std::vector<Student> students = {
        {"Alice", {"Mathematics", "Physics", "Chemistry"}},
        {"Bob", {"Biology", "Mathematics", "English"}},
        {"Charlie", {"History", "Geography", "Mathematics"}}
    };

    // Call the function to display the student modules
    displayStudentModules(students);

    return 0;
}
