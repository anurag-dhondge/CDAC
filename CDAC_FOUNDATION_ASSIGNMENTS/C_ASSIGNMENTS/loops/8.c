//  8. Write a program to print all prime numbers between 1 to n.

#include <stdio.h>

void PrimeNumbers(int n)
{
    int i, j, count = 0;

    printf("Prime numbers between 1 and %d are: ", n);

    for(i = 2; i <= n; i++)
    {
        count = 0;

        for(j = 1; j <= i; j++)
        {
            if(i % j == 0)
            {
                count++;
            }
        }

        if(count == 2) // 1 and itself
        {
            printf("%d ", i);
        }
    }
}

int main()
{
    int n = 0;

    printf("Enter n: ");
    scanf("%d", &n);

    PrimeNumbers(n);

    return 0;
}