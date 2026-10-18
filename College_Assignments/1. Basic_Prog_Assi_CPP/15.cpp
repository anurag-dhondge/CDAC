/*
    15. Accept a number and print its multiplication table from 1 to 10 using a loop.
*/

#include <iostream>
using namespace std;

void Table(int n)
{
    for(int i = 1; i <= 10; i++)
    {
        cout << n << " * " << i << " = " << n * i << endl;
    }
}

int main()
{
    int n;
    cout << "Enter number: ";
    cin >> n;

    Table(n);
    return 0;
}