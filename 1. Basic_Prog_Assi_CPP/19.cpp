/*
    19. Accept an integer and count the number of digits using a loop.
*/

#include <iostream>
using namespace std;

void Count_Digits(int n)
{
    int count = 0;

    do
    {
        count++;        
        n = n / 10;
    } while(n != 0);

    cout << "Number of digits = " << count;
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    Count_Digits(n);
    return 0;
}