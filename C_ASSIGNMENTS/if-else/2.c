// 2. Write a program to accept a number and check if it is divisible by 5 and 7.

#include <stdio.h>

void Check_Divisible(int num)
{
    if (num % 5 == 0 && num % 7 == 0)
    {
        printf("%d is divisible by both 5 and 7.", num);
    }
    
    else
    {
        printf("%d is not divisible by both 5 and 7.", num);
    }
}

int main()
{
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    Check_Divisible(num);

    return 0;
}