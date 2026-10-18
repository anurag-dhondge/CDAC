//  1. Write a program to accept an integer and check if it is even or odd.

#include <stdio.h>

void Check_Even_Odd(int num)
{
    if (num % 2 == 0)
    {
        printf("%d is : Even.", num);
    }
    
    else
    {
        printf("%d is : Odd.", num);
    }
}

int main()
{
    int num;

    printf("Enter an integer: ");
    scanf("%d", &num);

    Check_Even_Odd(num);

    return 0;
}