//  1. To Accept the radius from user and compute the area and circumference of a circle.

#include<stdio.h>
#define PI  3.14

void Area(float r)
{
    float area = 0;
    area = PI * r * r;
    printf("Area of circle is : %.2f sq m \n",area);
}

void Circumference(float r)
{
    float circumference = 0;
    circumference = 2 * PI * r;
    printf("Circumference is  : %.2f m",circumference);
}

int main()
{
    float radius = 0.0f;
    printf("Enter a radius    : ");
    scanf("%f",&radius);

    Area(radius);
    Circumference(radius);

    return 0;
}