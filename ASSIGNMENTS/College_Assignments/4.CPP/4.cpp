/*

4. Distance Comparison and Addition

Create a Distance class with feet and inches as data members. Use constructors to initialize
Distance objects. Overload the '+' operator to add two Distance objects and overload the '=='
operator to compare whether two Distance objects are equal. Display the appropriate results.

*/

#include "Distance.h"

int main()
{
    Distance d1(10, 20);

    cout << "\nDistance d1------------";
    d1.display();

    Distance d2(10, 20);

    cout << "\nDistance d2------------";
    d2.display();

    Distance d3(0, 0);

    d3 = d1 + d2;

    cout << "\nAddition d3------------";
    d3.display();

    if (d1 == d2)
    {
        cout << "\nDistance is equal";
    }
    else
    {
        cout << "\nDistance is not equal";
    }

    return 0;
}