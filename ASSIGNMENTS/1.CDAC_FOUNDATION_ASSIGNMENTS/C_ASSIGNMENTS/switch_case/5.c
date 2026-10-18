/*
    5. Write a program having menu that has three options - 
    add, subtract or multiply two fractions. 
    The two  fractions and the options are taken as input and the result is displayed as output. 
    Each fraction is read as two integers, numerator and denominator. 
*/

#include <stdio.h>

void Add(int n1, int d1, int n2, int d2)
{
    int num, den;

    num = (n1 * d2) + (n2 * d1);
    den = d1 * d2;

    printf("Addition = %d/%d", num, den);
}

void Subtract(int n1, int d1, int n2, int d2)
{
    int num, den;

    num = (n1 * d2) - (n2 * d1);
    den = d1 * d2;

    printf("Subtraction = %d/%d", num, den);
}

void Multiply(int n1, int d1, int n2, int d2)
{
    int num, den;

    num = n1 * n2;
    den = d1 * d2;

    printf("Multiplication = %d/%d", num, den);
}

int main()
{
    int n1, d1, n2, d2;
    int choice;

    printf("Enter first fraction (numerator denominator): ");
    scanf("%d %d", &n1, &d1);

    printf("Enter second fraction (numerator denominator): ");
    scanf("%d %d", &n2, &d2);

    printf("\n1. Add");
    printf("\n2. Subtract");
    printf("\n3. Multiply");

    printf("\nEnter choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            Add(n1, d1, n2, d2);
            break;

        case 2:
            Subtract(n1, d1, n2, d2);
            break;

        case 3:
            Multiply(n1, d1, n2, d2);
            break;

        default:
            printf("Invalid choice");
    }

    return 0;
}