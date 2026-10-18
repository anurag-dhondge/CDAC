/*
3. Complex Number Addition

Create a Complex class with real and imaginary data members.
Initialize the complex numbers using appropriate constructors.
Overload the '+' operator to add two Complex objects and display
the resulting complex number.
*/

#include "Complex.h"

int main()
{
    Complex d1(10.0f, 20.0f);

    cout << "\nFirst Complex Number:";
    d1.display();

    Complex d2(10.0f, 20.0f);

    cout << "\nSecond Complex Number:";
    d2.display();

    Complex d3(0, 0);

    d3 = d1 + d2;

    cout << "\nAddition:";
    d3.display();

    return 0;
}