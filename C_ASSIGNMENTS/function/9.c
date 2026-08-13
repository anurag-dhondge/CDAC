/*
    9. Write a C program to check whether a number is prime, Armstrong
    or perfect number using functions.
*/

#include <stdio.h>

int IsPrime(int n)
{
    int i;

    if(n <= 1)
    {
        return 0;
    }

    for(i = 2; i < n; i++)
    {
        if(n % i == 0)
        {
            return 0;
        }
    }

    return 1;
}

int IsArmstrong(int n)
{
    int temp;
    int digit;
    int sum = 0;

    temp = n;

    while(temp != 0)
    {
        digit = temp % 10;
        sum = sum + digit * digit * digit;
        temp = temp / 10;
    }

    return sum == n;
}

int IsPerfect(int n)
{
    int i;
    int sum = 0;

    for(i = 1; i < n; i++)
    {
        if(n % i == 0)
        {
            sum = sum + i;
        }
    }

    return sum == n;
}

int main()
{
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    if(IsPrime(n))
    {
        printf("Number is Prime\n");
    }
    else
    {
        printf("Number is not Prime\n");
    }

    if(IsArmstrong(n))
    {
        printf("Number is Armstrong\n");
    }
    else
    {
        printf("Number is not Armstrong\n");
    }

    if(IsPerfect(n))
    {
        printf("Number is Perfect\n");
    }
    else
    {
        printf("Number is not Perfect\n");
    }

    return 0;
}