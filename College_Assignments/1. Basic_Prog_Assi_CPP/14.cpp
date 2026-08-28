/*
    14. Accept N and calculate the sum of the first N natural numbers using a loop.
*/

#include <iostream>
using namespace std;

void Sum_Natural(int n)
{
    int sum = 0;

    for(int i = 1; i <= n; i++)
        sum = sum + i;

    cout << "The sum of the first " << n <<" natural numbers = " << sum;
}

int main()
{
    int n;
    cout << "Enter Number : ";
    cin >> n;

    Sum_Natural(n);
    return 0;
}