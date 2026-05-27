#include <iostream>
using namespace std;

int main()
{
    int courses;
    char grade;
    float creditHours;
    float gradePoint;
    float totalCredits = 0;
    float totalGradePoints = 0;
    
    
    float gpa, cgpa;

    cout << "Enter number of courses: ";
    cin >> courses;

    char grades[courses];

    for (int i = 0; i < courses; i++)
    {
        cout << endl;
        cout << "Course " << i + 1 << endl;

        cout << "Enter grade (A, B, C, D, F): ";
        cin >> grade;

        cout << "Enter credit hours: ";
        cin >> creditHours;

        grades[i] = grade;

        if (grade == 'A')
        {
            gradePoint = 4.0;
        }
        else if (grade == 'B')
        {
            gradePoint = 3.0;
        }
        else if (grade == 'C')
        {
            gradePoint = 2.0;
        }
        else if (grade == 'D')
        {
            gradePoint = 1.0;
        }
        else
        {
            gradePoint = 0.0;
        }

        totalGradePoints = totalGradePoints + (gradePoint*creditHours);
        totalCredits = totalCredits+creditHours;
    }
    gpa = totalGradePoints / totalCredits;
    cgpa = gpa;
    cout << endl;
    cout << "Result" << endl;

    for (int i = 0; i < courses; i++)
    {
        cout << "Course " << i + 1 << " Grade=" << grades[i] << endl;
    }

    cout << endl;
    cout << "Semester GPA: " << gpa << endl;
    cout << "Final CGPA: " << cgpa << endl;

    return 0;
}
