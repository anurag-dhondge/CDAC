/*
    7. Write a C program to check number is palindrome or not using
    functions.
*/

#include <stdio.h>

int Reverse(int n)
{
    int rev = 0;

    while(n != 0)
    {
        rev = rev * 10 + n % 10;
        n = n / 10;
    }

    return rev;
}

int main()
{
    int n;
    int iRet;

    printf("Enter a number: ");
    scanf("%d", &n);

    iRet = Reverse(n);

    if(n == iRet)
    {
        printf("Number is palindrome\n");
    }
    else
    {
        printf("Number is not palindrome\n");
    }

    return 0;
}