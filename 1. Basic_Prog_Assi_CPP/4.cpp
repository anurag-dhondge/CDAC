/*
    4.  Write a program to accept three numbers and 
        display the largest number using if-else statements.
*/

#include <iostream>
using namespace std;

void Check_Largest(int a, int b, int c)
{
    if (a >= b && a >= c)
    {
        cout << "The largest number among three numbers = " << a;
    }

    else if (b >= a && b >= c)
    {
        cout << "The largest number among three numbers = " << b;
    }

    else if (c >= a && c >= b)
    {
        cout << "The largest number among three numbers = " << c;
    }

    else
    {
        cout << "Invalid Input";
    }
}

int main()
{
    int a, b, c;
    cout << "Enter three numbers: ";
    cin >> a >> b >> c;

    Check_Largest(a, b, c);
    return 0;
}