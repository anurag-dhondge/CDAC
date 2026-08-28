/*
    20. Accept an integer and calculate the sum of all its digits.
*/

#include <iostream>
using namespace std;

void Sum_Digits(int n)
{
    int sum = 0;

    while(n != 0)
    {
        sum = sum + (n % 10);
        n = n / 10;
    }

    cout << "Sum of digits = " << sum;
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    Sum_Digits(n);
    return 0;
}