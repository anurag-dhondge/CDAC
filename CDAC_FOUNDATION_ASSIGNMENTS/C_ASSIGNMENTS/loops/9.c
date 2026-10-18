//  9. Write a program to Compute Quotient and Remainder of numbers.

#include <stdio.h>

void Division(int num1, int num2)
{
    int quotient, remainder = 0;

    quotient = num1 / num2;
    remainder = num1 % num2;

    printf("Quotient = %d\n", quotient);
    printf("Remainder = %d", remainder);
}

int main()
{
    int num1, num2  = 0;

    printf("Enter first number: ");
    scanf("%d", &num1);

    printf("Enter second number: ");
    scanf("%d", &num2);

    Division(num1, num2);

    return 0;
}