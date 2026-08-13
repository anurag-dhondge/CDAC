/*
    4. Write a program to swap two integers using call by value and
    call by reference methods of passing arguments to a function.
*/

#include <stdio.h>

void SwapByValue(int a, int b)
{
    int temp;

    temp = a;
    a = b;
    b = temp;

    printf("Inside Call By Value: a = %d, b = %d\n", a, b);
}

void SwapByReference(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int a, b;

    printf("Enter two numbers: ");
    scanf("%d%d", &a, &b);

    printf("\nBefore Call By Value: a = %d, b = %d\n", a, b);

    SwapByValue(a, b);

    printf("After Call By Value: a = %d, b = %d\n", a, b);

    SwapByReference(&a, &b);

    printf("After Call By Reference: a = %d, b = %d\n", a, b);

    return 0;
}