/*
    13. Write programs using for, while, and do-while loops to print numbers from 1 to N.
*/

#include <iostream>
using namespace std;

void Print_Numbers(int n)
{
    int i;

    cout << "Using for     : ";
    for(i = 1; i <= n; i++)
    {
        cout << i << " ";
    }

    cout << "\nUsing while   : ";
    i = 1;
    while(i <= n)
    {
        cout << i << " ";
        i++;
    }

    cout << "\nUsing do-while: ";
    i = 1;
    do
    {
        cout << i << " ";
        i++;
    } while(i <= n);
}

int main()
{
    int n;
    cout << "Enter number  : ";
    cin >> n;

    Print_Numbers(n);
    return 0;
}