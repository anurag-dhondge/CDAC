/*
    10. Write a C program to find power of any number using recursion.
*/

#include <stdio.h>

int Power(int base, int exponent)
{
    if(exponent == 0)
    {
        return 1;
    }

    return base * Power(base, exponent - 1);
}

int main()
{
    int base;
    int exponent;
    int iRet;

    printf("Enter base: ");
    scanf("%d", &base);

    printf("Enter exponent: ");
    scanf("%d", &exponent);

    iRet = Power(base, exponent);

    printf("Power is : %d\n", iRet);

    return 0;
}