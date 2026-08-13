/*
    3. Write a program, which accepts annual basic salary of an employee and 
    calculates and displays the Income tax as per the following rules.
    
    Basic: < 1,50,000 Tax = 0
    1,50,000 to 3,00,000 Tax = 20%
    > 3,00,000 Tax = 30%
*/

#include <stdio.h>

void Income_Tax(float b)
{
    float tax = 0.0f;

    if (b < 150000)
    {
        tax = 0.0f;
    }

    else if (b <= 300000)
    {
        tax = b * 20 / 100;
    }
    
    else
    {
        tax = b * 30 / 100;
    }

    printf("Income Tax = %.2f", tax);
}

int main()
{
    float basic;

    printf("Enter Annual Basic Salary : ");
    scanf("%f", &basic);

    Income_Tax(basic);

    return 0;
}