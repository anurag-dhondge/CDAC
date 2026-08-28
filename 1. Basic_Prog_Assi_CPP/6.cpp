/*
    6.  Write a program to accept a year and 
        determine whether it is a leap year.
*/

#include <iostream>
using namespace std;

void Check_LeapYear(int year)
{
    if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
    {    
        cout << "The Year is Leap Year";
    }

    else
    {
        cout << "The Year is Not a Leap Year";
    }
}

int main()
{
    int year;
    cout << "Enter the year: ";
    cin >> year;

    Check_LeapYear(year);
    return 0;
}