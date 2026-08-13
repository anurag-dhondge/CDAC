/*
    2. Write a program to calculate sum of first 20 natural numbers using
    recursive function.
*/

#include <stdio.h>

int Sum(int n)
{
    if(n == 0)
    {
        return 0;
    }

    return n + Sum(n - 1);
}

int main()
{
    int iRet;

    iRet = Sum(20);

    printf("Sum of first 20 natural numbers is : %d\n", iRet);

    return 0;
}