// 9. Program to display a number if it is negative.

#include <stdio.h>

void Check_Negative(int num)
{
    if (num < 0)
    {
        printf("The number is negative : %d", num);
    }

    else
    {
        printf("The number is positive : %d", num);
    }
}

int main()
{
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    Check_Negative(num);

    return 0;
}