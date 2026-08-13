//  12. Write a recursive function to calculate the sum of digits of a number till you get a single digit number.
//  Example: 961 -> 16 -> 5. (Note: Do not use a loop)

#include<stdio.h>

int SumDigits(int num)
{
    if(num < 10)
    {
        return num;
    }
    else
    {
        return SumDigits((num / 10) + (num % 10));
    }
}

int main()
{
    int num, result;

    printf("Enter a number : ");
    scanf("%d", &num);

    result = SumDigits(num);

    printf("Single digit sum = %d\n", result);

    return 0;
}