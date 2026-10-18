/*
    18. Accept an integer and determine whether it is a palindrome number.
*/

#include <iostream>
using namespace std;

void Palindrome(int n)
{
    int original = n;
    int rev = 0;

    while(n != 0)
    {
        rev = rev * 10 + n % 10;
        n /= 10;
    }

    if(original == rev)
    {
        cout << "Palindrome";
    }

    else
    {
        cout << "Not Palindrome";
    }
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    Palindrome(n);
    return 0;
}