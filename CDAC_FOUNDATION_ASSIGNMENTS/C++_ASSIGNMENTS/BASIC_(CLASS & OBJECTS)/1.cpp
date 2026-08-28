//  1. Write a program to create student class and
//  accept data members of it by the object and display them

#include <iostream>
using namespace std;

class Student
{
    int rollNo = 0;
    string name = "";
    float marks = 0.0f;

    public:
        void accept()
        {
            cout << "Enter Roll No: ";
            cin >> rollNo;

            cout << "Enter Name: ";
            cin >> name;

            cout << "Enter Marks: ";
            cin >> marks;
        }

        void display()
        {
            cout << "\nStudent Details";
            cout << "\nRoll No: " << rollNo;
            cout << "\nName: " << name;
            cout << "\nMarks: " << marks;
        }
};

int main()
{
    Student s;

    s.accept();
    s.display();

    return 0;
}