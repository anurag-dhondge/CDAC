/*  2.  Write a program to accept an integer and 
        check whether the number is even or odd.
*/

#include <iostream>
using namespace std;

void Check_EvenOdd(int no)
{
    if(no % 2 == 0)
    {
        cout << "The number is Even";
    }

    else
    { 
        cout << "The number is Odd"; 
    }

}

int main()
{
    int num;
    cout << "Enter number: ";
    cin >> num;

    if(num >= 0)
    {
        Check_EvenOdd(num);
    }

    else
    {
        cout << "Invalid Input";
    }

    return 0;
}