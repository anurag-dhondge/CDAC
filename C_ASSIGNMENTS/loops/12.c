/*
    12. Write the program to display patterns:
    a)  ***** b) 54321 c) A B C D E  d) 1
        ****     4321      A B C D      121
        ***      321        A B C       12321
        **       21          A B        1234321
        *        1            A         123454321
*/

#include <stdio.h>

void Pattern_a()
{
    int i, j = 0;

    for(i = 5; i >= 1; i--)
    {
        for(j = 1; j <= i; j++)
        {
            printf("*");
        }

        printf("\n");
    }
}

void Pattern_b()
{
    int i, j = 0;

    for(i = 5; i >= 1; i--)
    {
        for(j = i; j >= 1; j--)
        {
            printf("%d", j);
        }

        printf("\n");
    }
}

void Pattern_c()
{
    int i, j = 0;

    for(i = 5; i >= 1; i--)
    {
        for(j = 1; j <= 5 - i; j++)
        {
            printf(" ");
        }

        for(j = 1; j <= i; j++)
        {
            printf("%c ", 'A' + j - 1);
        }

        printf("\n");
    }
}
void Pattern_d()
{
    int i, j = 0; 

    for(i = 1; i <= 5; i++)
    {
        for(j = 1; j <= i; j++)
        {
            printf("%d", j);
        }

        for(j = i - 1; j >= 1; j--)
        {
            printf("%d", j);
        }

        printf("\n");
    }
}

int main()
{
    Pattern_a();
    Pattern_b();
    Pattern_c();
    Pattern_d();

    return 0;
}