/*
    9.  Accept a number from 1 to 12 and 
        display the corresponding month name using switch-case.
*/
#include <iostream>
using namespace std;

void Month_Name(int month)
{
    switch (month)
    {
        case 1: 
            cout << "The month is January"; 
            break;
        case 2: 
            cout << "The month is February"; 
            break;
        case 3:    
            cout << "The month is March"; 
            break;
        case 4: 
            cout << "The month is April"; 
            break;
        case 5: 
            cout << "The month is May"; 
            break;
        case 6: 
            cout << "The month is June"; 
            break;
        case 7: 
            cout << "The month is July"; 
            break;
        case 8: 
            cout << "The month is August"; 
            break;
        case 9: 
            cout << "The month is September"; 
            break;
        case 10: 
            cout << "The month is October"; 
            break;
        case 11: 
            cout << "The month is November"; 
            break;
        case 12: 
            cout << "The month is December"; 
            break;
        default: 
            cout << "Invalid month";
    }
}

int main()
{
    int month;
    cout << "Enter month number: ";
    cin >> month;

    Month_Name(month);
    return 0;
}