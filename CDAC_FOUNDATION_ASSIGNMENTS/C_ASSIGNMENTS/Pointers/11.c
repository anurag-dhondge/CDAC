//  11. Write a recursive C function to calculate x raised to y.
//  (Do not use standard library function)

#include<stdio.h>

int Power(int x, int y)
{
    if(y == 0)
    {
        return 1;
    }
    else
    {
        return x * Power(x, y - 1);
    }
}

int main()
{
    int x, y, result;

    printf("Enter base : ");
    scanf("%d", &x);

    printf("Enter power : ");
    scanf("%d", &y);

    result = Power(x, y);

    printf("Result = %d\n", result);

    return 0;
}