/*
    12. Write a program to perform the following operations using function.
    i) To find maximum and minimum between two numbers
    ii) To check whether a number is even or odd
    iii) To print Pascal triangle
*/

#include <stdio.h>

void MaxMin(int a, int b)
{
    if(a > b)
    {
        printf("Maximum is : %d\n", a);
        printf("Minimum is : %d\n", b);
    }

    else
    {
        printf("Maximum is : %d\n", b);
        printf("Minimum is : %d\n", a);
    }
}

void EvenOdd(int n)
{
    if(n % 2 == 0)
    {
        printf("%d is even\n", n);
    }
    
    else
    {
        printf("%d is odd\n", n);
    }
}

void PascalTriangle(int n)
{
    int i, j;
    int value;

    for(i = 0; i < n; i++)
    {
        value = 1;

        for(j = 0; j <= i; j++)
        {
            printf("%d ", value);

            value = value * (i - j) / (j + 1);
        }

        printf("\n");
    }
}

int main()
{
    int a, b;
    int n;

    printf("Enter two numbers: ");
    scanf("%d%d", &a, &b);

    MaxMin(a, b);

    printf("\nEnter a number: ");
    scanf("%d", &n);

    EvenOdd(n);

    printf("\nEnter number of rows for Pascal Triangle: ");
    scanf("%d", &n);

    PascalTriangle(n);

    return 0;
}