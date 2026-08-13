/* 
    4. Accept the basic salary of an employee and 
    compute the net salary after adding earnings and subtracting deductions.
    --> PF  is 2 % of basic  // -
    --> Tax is 3 % of basic  // -
    --> HRA is 5 % of basic  // +
    --> DA  is 8 % of basic  // +
*/

#include <stdio.h>

void Net_salary(float basic)
{
    float PF  = 0.0f;
    float Tax = 0.0f;
    float HRA = 0.0f;
    float DA  = 0.0f;
    float net_salary = 0.0f;

    PF  = (2.0f/100) * basic;
    Tax = (3.0f/100) * basic;
    HRA = (5.0f/100) * basic;
    DA  = (8.0f/100) * basic;

    net_salary = basic - PF - Tax + HRA + DA;
    printf("Net Salary is  : %.2f rupees",net_salary);
}

int main()
{
    float basicsal = 0.0f;
    printf("Basic Salary is : ");   
    scanf("%f",&basicsal);

    Net_salary(basicsal);
    return 0;
}