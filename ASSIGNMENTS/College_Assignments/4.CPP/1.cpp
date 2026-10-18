/*
1. Dynamic Integer Storage

Create a class Number that dynamically allocates memory for an integer using a pointer.
Initialize the value using a constructor, implement a copy constructor to create a deep copy,
and use a destructor to release the dynamically allocated memory.
*/

#include "Number.h"

int main()
{
    int num;

    cout << "\nEnter the number: ";
    cin >> num;

    Number n1(num);

    cout << "\nNumber n1------------";
    n1.display();

    Number n2(n1);

    cout << "\nNumber n2 - Deep Copy------------";
    n2.display();

    return 0;
}