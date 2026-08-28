/*
    3. Write a function using pass by reference to calculate the
       sum and difference of two numbers and return both results
       through reference parameters.
*/

#include <iostream>
using namespace std;

// Accept two numbers and return sum and difference through references
void Sum_Diff(float &a, float &b, float &sum, float &diff)
{
    sum = a + b;
    diff = a - b;
}

int main()
{
    float a, b, sum, diff;

    cout << "Enter two numbers: ";
    cin >> a >> b;

    Sum_Diff(a, b, sum, diff);  // Pass input and result variables by reference

    cout << "Sum of numbers is: " << sum << endl;
    cout << "Difference of numbers is: " << diff;

    return 0;
}