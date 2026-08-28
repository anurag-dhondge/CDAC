/*
    5.  Accept marks obtained by a student and 
        display the grade using the following criteria: 
        90–100: A, 75–89: B,60–74: C, 40–59: D, below 40: Fail. 
        Validate marks outside 0–100.
*/
#include <iostream>
using namespace std;

void Display_Grade(float marks)
{
    if (marks < 0 || marks > 100)
    {
        cout << "Invalid marks";
    }

    else if (marks >= 90)
    {
        cout << "The student got Grade A";
    }

    else if (marks >= 75 && marks < 90)
    {
        cout << "The student got Grade B";
    }

    else if (marks >= 60 && marks < 75)
    {
        cout << "The student got Grade C";
    }

    else if (marks >= 40 && marks < 60)
    {
        cout << "The student got Grade D";
    }

    else
    {
        cout << "Fail";
    }
}

int main()
{
    float marks;
    cout << "Enter students marks: ";
    cin >> marks;

    Display_Grade(marks);
    return 0;
}