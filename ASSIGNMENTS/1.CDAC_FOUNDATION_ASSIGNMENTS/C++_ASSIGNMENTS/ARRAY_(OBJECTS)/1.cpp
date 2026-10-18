/*
    1. Create a C++ program that demonstrates the use of arrays of objects. 
    The program should simulate a simple student management system
    a. Create a class Student with the following attributes:
    - name (string), rollNumber (integer), marks (integer array of size 5)
    b. Implement the following member functions in the Student class:
    - getDetails(): Asks the user to input the student's details(name, roll number, and marks)
    - displayDetails(): Displays the student's details
    c. Create an array of Student objects with a size of 10.
*/

#include <iostream>
using namespace std;

class Student
{
    string name;
    int rollNumber;
    int marks[5];

    public:
        void getDetails()
        {
            cout << "\nEnter Name: ";
            cin >> name;

            cout << "Enter Roll Number: ";
            cin >> rollNumber;

            cout << "Enter marks of 5 subjects:\n";

            for (int i = 0; i < 5; i++)
            {
                cout << "Subject " << i + 1 << ": ";
                cin >> marks[i];
            }
        }

        void displayDetails()
        {
            cout << "\nName: " << name;
            cout << "\nRoll Number: " << rollNumber;
            cout << "\nMarks: ";

            for (int i = 0; i < 5; i++)
            {
                cout << marks[i] << " ";
            }

            cout << "\n";
        }
};

int main()
{
    Student students[10];

    cout << "Enter details of 10 students:\n";

    for (int i = 0; i < 10; i++)
    {
        cout << "\nStudent " << i + 1 << "\n";
        students[i].getDetails();
    }

    cout << "\n\n----- Student Details -----\n";

    for (int i = 0; i < 10; i++)
    {
        cout << "\nStudent " << i + 1 << "\n";
        students[i].displayDetails();
    }

    return 0;
}