//  2. Write a program to accept two integers x and n and compute x raised to n.

#include <stdio.h>

void Power(int x, int n)
{
    int i, result = 1;

    for(i = 1; i <= n; i++)
    {
        result = result * x; //x^n = x * x *... * x (n times)
    }

    printf("%d raised to %d = %d", x, n, result);
}

int main()
{
    int x, n = 0;

    printf("Enter x: ");
    scanf("%d", &x);

    printf("Enter n: ");
    scanf("%d", &n);

    Power(x, n);

    return 0;
}