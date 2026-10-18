//  4. Write a program to calculate factorial of a number.
//  For e.g. factorial of 5 = 5! = 5 * 4 * 3 * 2 * 1 = 120

#include <stdio.h>

void Factorial(int num)
{
    int i, fact = 1;

    for(i = num; i >= 1; i--)
    {
        fact = fact * i;
    }

    printf("Factorial of %d = %d", num, fact);
}

int main()
{
    int num = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    Factorial(num);

    return 0;
}