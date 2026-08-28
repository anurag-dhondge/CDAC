/*
    3.  Write a program to accept two integers and 
        display the larger number. 
        Also handle the case when both numbers are equal.
*/
#include <iostream>
using namespace std;

void Display_Largest(int a, int b)
{
    if(a > b)
    {
        cout << "The Largest integer among two number = " << a;
    }

    else if(b > a)
    {
        cout << "The Largest integer among two number = " << b;
    }

    else if(a = b)
    {
        cout << "Both numbers are equal";
    }

    else
    {
        cout << "Invalid Input";
    }
}

int main()
{
    int a, b;
    cout << "Enter two integers: ";
    cin >> a >> b;

    Display_Largest(a, b);
    return 0;
}