//  2. Write a program to Create employee class with the data members and 
//  appropriate member function for getting data and 
//  displaying data by simple default member function

#include <iostream>
using namespace std;

class Employee
{
    int empId = 0;
    string name = "";
    float salary = 0.0f;

    public:
        void getData()
        {
            cout << "Enter Employee ID: ";
            cin >> empId;

            cout << "Enter Employee Name: ";
            cin >> name;

            cout << "Enter Salary: ";
            cin >> salary;
        }

        void displayData()
        {
            cout << "\nEmployee Details";
            cout << "\nEmployee ID: " << empId;
            cout << "\nName: " << name;
            cout << "\nSalary: " << salary;
        }
};

int main()
{
    Employee e;

    e.getData();
    e.displayData();

    return 0;
}