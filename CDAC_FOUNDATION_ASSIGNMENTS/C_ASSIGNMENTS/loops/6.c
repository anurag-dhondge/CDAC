//  6. Accept two numbers and calculate GCD of them.

#include <stdio.h>

#include <stdio.h>

void GCD(int num1, int num2)
{
    int i, gcd = 1;

    for(i = 1; i <= num1 && i <= num2; i++)
    {
        if(num1 % i == 0 && num2 % i == 0)
        {
            gcd = i; 
        }
    }

    printf("GCD = %d", gcd);
}

int main()
{
    int num1, num2;

    printf("Enter first number: ");
    scanf("%d", &num1);

    printf("Enter second number: ");
    scanf("%d", &num2);

    GCD(num1, num2);

    return 0;
}