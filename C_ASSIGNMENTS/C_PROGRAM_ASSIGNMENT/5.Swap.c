/*
    5. Accept two numbers and swap two numbers using
    i) Third variable
    ii) By performing arithmetic operations
*/

#include <stdio.h>

void Third_Variable(float a, float b)
{
    float temp = 0.0f;

    temp = a;
    a = b;
    b = temp;

    printf("By Third Variable first number is  : %f\n",a);
    printf("By Third Variable Second number is : %f\n",b);
}

void Arithmati_Operations(float a, float b)
{
    float ans = 0.0f;

    ans = a + b;
    a = ans - a;
    b = ans - b;

    printf("By Arithmati_Operations first number is  : %f\n",a);
    printf("By Arithmati_Operations Second number is : %f\n",b);
}

int main()
{
    float first = 0.0f;
    float second = 0.0f;

    printf("Enter First Number  : ");
    scanf("%f",&first);

    printf("Enter Second Number : ");
    scanf("%f",&second);

    Third_Variable(first,second);

    Arithmati_Operations(first,second);

    return 0;
}