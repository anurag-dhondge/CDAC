/*
    6. Write a program to read an integer number and print the reverse
    of that number using recursion.
*/

#include <stdio.h>

void Reverse(int n)
{
    if(n == 0)
    {
        return;
    }

    printf("%d", n % 10);

    Reverse(n / 10);
}

int main()
{
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    printf("Reverse is : ");

    Reverse(n);

    printf("\n");

    return 0;
}