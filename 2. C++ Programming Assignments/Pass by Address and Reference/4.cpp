/*
    4. Write a function using pass by reference to
       reverse the digits of a number and
       update the original variable in main.
*/

#include <iostream>
using namespace std;

// Reverse the digits and update the original number using reference
void Reverse(int &num)
{
    int reverse = 0;
    int rem;

    while (num != 0)
    {
        rem = num % 10;
        reverse = reverse * 10 + rem;
        num = num / 10;
    }

    num = reverse;
}

int main()
{
    int num;

    cout << "Enter a number: ";
    cin >> num;

    Reverse(num);  // Pass number by reference

    cout << "After reversing: " << num;

    return 0;
}