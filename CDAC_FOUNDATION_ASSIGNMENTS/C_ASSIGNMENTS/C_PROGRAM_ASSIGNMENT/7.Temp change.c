/*
    7. Accept temperatures in Fahrenheit (F) and 
    print it in Celsius(C) and Kelvin (K) 
    (Hint: C = 5 / 9 (F - 32), K = C + 273.15)
*/

#include <stdio.h>

float Celsius(float F)
{
    float c = 0.0f;
    c = (5.0f / 9.0f) * (F - 32.0f);

    printf("The Celsius Temperature is    : %.2f Degree Celsius\n",c);

    return c;
}

void Kelvin(float c)
{
    float k = 0.0f;
    k = c + 273.15f;

    printf("The Kelvin Temperature is     : %.2f Kelvin\n",k);
}

int main()
{
    float fahrenheit = 0.0f;
    float celsius = 0.0f;
    
    printf("The Fahrenheit Temperature is : =>");
    scanf("%f",&fahrenheit);

    celsius = Celsius(fahrenheit);
    Kelvin(celsius);

    return 0;
}