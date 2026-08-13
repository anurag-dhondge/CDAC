/*
 8. Write a C program to check whether a number is perfect number
   or not using functions.
*/

#include <stdio.h>

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
    int iRet;

    printf("Enter a number: ");
    scanf("%d", &n);

    iRet = IsPerfect(n);

    if(iRet == 1)
    {
        printf("Number is perfect number\n");
    }
    
    else
    {
        printf("Number is not perfect number\n");
    }

    return 0;
}