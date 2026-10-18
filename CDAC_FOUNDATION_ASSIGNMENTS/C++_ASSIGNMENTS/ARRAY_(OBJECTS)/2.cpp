//  2. Use a loop to ask the user to input the details of 10 students and store them in the array.

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