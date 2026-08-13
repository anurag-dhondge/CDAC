//  1. Write a program that accepts numbers continuously as long as the number is positive and
//  prints the sum of the given numbers.

#include <stdio.h>

void Sum(int num, int sum)
{
    do
    {
        if(num > 0)
        {
            sum = sum + num;
        }

        else if(num < 0)
        {
            printf("Negative number is entered. \n");
        }

    } while(num > 0);

    printf("Sum = %d", sum);
}

int main()
{
    int num, sum = 0;

    printf("Enter numbers:\n");
    scanf("%d", &num);

    Sum(num, sum);

    return 0;
}