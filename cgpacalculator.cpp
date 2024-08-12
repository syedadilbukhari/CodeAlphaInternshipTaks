#include <iostream>
#include <iomanip>

class Course {
public:
    std::string name;
    int creditHours;
    double gradePoint;

    Course() : name(""), creditHours(0), gradePoint(0.0) {}
    Course(std::string n, int ch, double gp) : name(n), creditHours(ch), gradePoint(gp) {}
};

class CGPACalculator {
private:
    Course* courses;
    int numberOfCourses;

public:
    CGPACalculator(int numCourses) : numberOfCourses(numCourses) {
        courses = new Course[numberOfCourses];
    }

    ~CGPACalculator() {
        delete[] courses;
    }

    void addCourse(int index, const std::string& name, int creditHours, double gradePoint) {
        if (index >= 0 && index < numberOfCourses) {
            courses[index] = Course(name, creditHours, gradePoint);
        }
    }

    double calculateCGPA() {
        double totalCredits = 0;
        double totalGradePoints = 0;

        for (int i = 0; i < numberOfCourses; ++i) {
            totalCredits += courses[i].creditHours;
            totalGradePoints += courses[i].creditHours * courses[i].gradePoint;
        }

        return totalGradePoints / totalCredits;
    }

    void displayCourseGrades() {
        std::cout << std::fixed << std::setprecision(2);
        for (int i = 0; i < numberOfCourses; ++i) {
            std::cout << "Course: " << courses[i].name << ", Credits: " << courses[i].creditHours << ", Grade Point: " << courses[i].gradePoint << std::endl;
        }
    }

    void displayCGPA() {
        std::cout << "Cumulative Grade Point Average (CGPA): " << calculateCGPA() << std::endl;
    }
};

int main() {
    int numberOfCourses;
    std::cout << "Enter the number of courses: ";
    std::cin >> numberOfCourses;

    CGPACalculator calculator(numberOfCourses);

    for (int i = 0; i < numberOfCourses; ++i) {
        std::string name;
        int creditHours;
        double gradePoint;

        std::cout << "Enter course name: ";
        std::cin >> name;
        std::cout << "Enter credit hours: ";
        std::cin >> creditHours;
        std::cout << "Enter grade point: ";
        std::cin >> gradePoint;

        calculator.addCourse(i, name, creditHours, gradePoint);
    }

    std::cout << "\nIndividual Course Grades:\n";
    calculator.displayCourseGrades();

    std::cout << "\n";
    calculator.displayCGPA();

    return 0;
}
