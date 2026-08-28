/*
    2.  Write a function that accepts two integers using pass by reference 
        and swaps their values.
*/

#include <iostream>
using namespace std;

// Swap two values using pass by reference
void Swap(float &a, float &b)
{
    float temp = a;
    a = b;
    b = temp;

    cout << "After Swap the values are : \n"<< "a = " << a << " and b = " << b <<" using pass by reference ";
}

int main()
{
    float a,b;
    cout << "Enter the number to swap. \n";
    cin >> a >> b;

    // Pass a and b by reference
    Swap(a, b);
    return 0;
}