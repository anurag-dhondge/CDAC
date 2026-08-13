//  5. Write a C program to input angles of a triangle and check whether triangle is valid or not.

#include <stdio.h>

void Check_Triangle(float a, float b, float c)
{
    if (a + b + c == 180)
    {
        printf("The triangle is valid.");
    }
    
    else
    {
        printf("The triangle is not valid.");
    }
}

int main()
{
    float a, b, c;

    printf("Enter three angles of the triangle: ");
    scanf("%f %f %f", &a, &b, &c);

    Check_Triangle(a, b, c);

    return 0;
}