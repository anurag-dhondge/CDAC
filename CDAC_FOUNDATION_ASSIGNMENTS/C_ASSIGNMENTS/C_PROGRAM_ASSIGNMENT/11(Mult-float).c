//  11. Write a program Multiply two Floating Point Numbers.

#include <stdio.h>

void Multiply(float a, float b)
{
    float result = 0.0f;

    result = a * b;

    printf("Multiplication of numbers          : %.2f \n", result);
}

int main()
{
    float num1 = 0.0f;
    float num2 = 0.0f;

    printf("Enter first floating point number  : ");
    scanf("%f", &num1);

    printf("Enter second floating point number : ");
    scanf("%f", &num2);

    Multiply(num1, num2);

    return 0;
}