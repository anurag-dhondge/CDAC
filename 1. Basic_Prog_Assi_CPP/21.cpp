/*
    21. Accept an integer and determine whether it is a prime number using a loop.
*/

#include <iostream>
using namespace std;

void Check_Prime(int n)
{
    int count = 0;

    for(int i = 1; i <= n; i++)
    {
        if(n % i == 0)
            count++;
    }

    if(count == 2)
    {
        cout << n << " is a Prime Number";
    }

    else
    {
        cout << n << " is a Not Prime Number";
    }

}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    Check_Prime(n);
    return 0;
}