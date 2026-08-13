//  5. Write a program to calculate factors of a given number.

#include <stdio.h>

void Factors(int num)
{
    int i = 0;

    printf("Factors of %d are: ", num);

    for(i = 1; i <= num; i++)
    {
        if(num % i == 0)
        {
            printf("%d ", i);
        }
    }
}

int main()
{
    int num = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    Factors(num);

    return 0;
}