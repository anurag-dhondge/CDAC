/*
    3. Accept two numbers in variables x and y from the user and perform the following operations
    
    Options-Actions
    1. Equality Check if x is equal to y
    2. Less Than Check if x is less than y
    3. Quotient and Remainder Divide x by y and display the quotient and remainder
    4. Range : Accept a number and check if it lies between x and y (both inclusive)
    5. Swap : Interchange x and y
*/

#include <stdio.h>

void Equality(int x, int y)
{
    if(x == y)
        printf("x is equal to y\n");
    else
        printf("x is not equal to y\n");
}

void LessThan(int x, int y)
{
    if(x < y)
        printf("x is less than y\n");
    else
        printf("x is not less than y\n");
}

void Quotient_Remainder(int x, int y)
{
    if(y != 0)
    {
        printf("Quotient = %d\n", x / y);
        printf("Remainder = %d\n", x % y);
    }
    else
    {
        printf("Division by zero is not possible\n");
    }
}

void Range(int x, int y)
{
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if((num >= x && num <= y) || (num >= y && num <= x))
        printf("%d lies between %d and %d\n", num, x, y);
    else
        printf("%d does not lie between %d and %d\n", num, x, y);
}

void Swap(int *x, int *y)
{
    int temp;

    temp = *x;
    *x = *y;
    *y = temp;

    printf("After swapping: x = %d, y = %d\n", *x, *y);
}

int main()
{
    int x, y, choice;

    printf("Enter x: ");
    scanf("%d", &x);

    printf("Enter y: ");
    scanf("%d", &y);

    printf("1. Equality\n");
    printf("2. Less Than\n");
    printf("3. Quotient and Remainder\n");
    printf("4. Range\n");
    printf("5. Swap\n");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            Equality(x, y);
            break;

        case 2:
            LessThan(x, y);
            break;

        case 3:
            Quotient_Remainder(x, y);
            break;

        case 4:
            Range(x, y);
            break;

        case 5:
            Swap(&x, &y);
            break;

        default:
            printf("Invalid choice\n");
    }

    return 0;
}