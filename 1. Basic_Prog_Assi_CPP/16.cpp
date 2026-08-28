/*
    16. Accept a positive integer and calculate its factorial using a loop.
*/

#include <iostream>
using namespace std;

void Factorial(int n)
{
    int fact = 1;

    for(int i = 1; i <= n; i++)
        fact = fact * i;

    cout << "The Factorial of " << n << " number is = " << fact;
}

int main()
{
    int n;
    cout << "Enter number: ";
    cin >> n;

    Factorial(n);
    return 0;
}