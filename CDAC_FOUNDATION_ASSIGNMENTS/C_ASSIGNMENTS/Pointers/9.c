//  9. Write a function power, which calculates x raised to y.
//  Write another function, which calculates n! Using for loop.
//  Use these functions to calculate the sum of first n terms of the Taylor series:
//  sin(x) = x - 3! 3 x + 5! 5 x + ......

#include<stdio.h>

int Power(int x, int y)
{
    int i, result = 1;

    for(i = 1; i <= y; i++)
    {
        result = result * x;
    }

    return result;
}

int Factorial(int n)
{
    int i, result = 1;

    for(i = 1; i <= n; i++)
    {
        result = result * i;
    }

    return result;
}

int main()
{
    int x, n, i, term;
    float sum = 0;

    printf("Enter value of x : ");
    scanf("%d", &x);

    printf("Enter number of terms : ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++)
    {
        term = (2 * i) - 1;

        if(i % 2 == 1)
        {
            sum = sum + (float)Power(x, term) / Factorial(term);
        }
        else
        {
            sum = sum - (float)Power(x, term) / Factorial(term);
        }
    }

    printf("Sum of Taylor series = %f\n", sum);

    return 0;
}