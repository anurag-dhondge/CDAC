/*
    5. Write a program to find sum of digits of the number using
    Recursive Function.
*/

#include <stdio.h>

int SumOfDigits(int n)
{
    if(n == 0)
    {
        return 0;
    }

    return (n % 10) + SumOfDigits(n / 10);
}

int main()
{
    int n;
    int iRet;

    printf("Enter a number: ");
    scanf("%d", &n);

    iRet = SumOfDigits(n);

    printf("Sum of digits is : %d\n", iRet);

    return 0;
}