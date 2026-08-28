/*
    1.  Write a function that accepts the addresses of two integers 
        and swaps their values using pointers.
*/

#include <iostream>
using namespace std;

// Swap two values using pointers
void Swap(float *a, float *b)
{
    float temp = *a;
    *a = *b;
    *b = temp;

    cout << "After Swap the values are : \n"<< "a = " << *a << " and b = " << *b;
}

int main()
{
    float a,b;
    cout << "Enter the number to swap. \n";
    cin >> a >> b;

    // Pass the addresses of a and b to the function
    Swap(&a, &b);
    return 0;
}