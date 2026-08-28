/*
    7.  Accept the number of electricity units consumed and 
        calculate the bill using slab rates of your choice. 
        Display the total bill and explain the slabs used.
*/
#include <iostream>
using namespace std;

void Total_Bill(int units)
{
    float bill;

    if (units <= 100)
    {
        bill = units * 5;
    }

    else if (units <= 200 && units > 100)
    {
        bill = units * 6;
    }

    else
    {
        bill = units * 7;
    }

    cout << "Total Bill = Rs. " << bill << "\n As slab 1 is under 100 units for 5 rs per unit, \n" <<" slab 2 is between 100 to 200 for 6 rs per unit,\n" << " and slab 3 is above 200 units for 7 rs per unit.";
}

int main()
{
    int units;
    cout << "Enter electricity units consumed: ";
    cin >> units;

    if (units < 0)
    {
        cout << "Invalid units";
    }

    else
    {
        Total_Bill(units);
    }

    return 0;
}