//  10. Accept program for Area and Perimeter Of Rectangle.

#include <stdio.h>

void Area(float length, float width)
{
    float area = 0.0f;

    area = length * width;

    printf("Area      : %.2f sqm \n", area);
}

void Perimeter(float length, float width)
{
    float perimeter = 0.0f;

    perimeter = 2.0f * (length + width);

    printf("Perimeter : %.2f m \n", perimeter);
}

int main()
{
    float length = 0.0f;
    float width = 0.0f;

    printf("Enter Length : ");
    scanf("%f", &length);

    printf("Enter Width  : ");
    scanf("%f", &width);

    Area(length, width);
    Perimeter(length, width);

    return 0;
}