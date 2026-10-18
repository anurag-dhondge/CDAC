// 8. Write a program to accept 3 numbers and compute minimum and maximum from them.

#include <stdio.h>

void Min_Max(int a, int b, int c)
{
    int min, max;

    if (a < b && a < c)
        min = a;

    else if (b < a && b < c)
        min = b;

    else
        min = c;

    if (a > b && a > c)
        max = a;

    else if (b > a && b > c)
        max = b;
    
    else
        max = c;

    printf("Minimum = %d\n", min);
    printf("Maximum = %d", max);
}

int main()
{
    int a, b, c;

    printf("Enter three numbers: ");
    scanf("%d %d %d", &a, &b, &c);

    Min_Max(a, b, c);

    return 0;
}