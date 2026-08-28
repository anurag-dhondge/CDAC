/*
    17. Accept an integer and reverse its digits using a while loop.
*/

#include <iostream>
using namespace std;

void Reverse_Number(int n)
{
    int rev = 0;

    while(n != 0)
    {
        rev = rev * 10 + n % 10;
        n = n / 10;
    }

    cout << "Reverse = " << rev;
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    Reverse_Number(n);
    return 0;
}