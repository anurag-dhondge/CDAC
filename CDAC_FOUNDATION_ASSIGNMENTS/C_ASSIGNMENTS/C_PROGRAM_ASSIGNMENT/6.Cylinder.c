/*
    6. Accept dimensions of a cylinder and print the surface area and volume 
    (Hint: surface area = 2πr^2 + 2πrh,volume = πr^2h). 
    Define a constant variable pi=3.14.
*/

#include <stdio.h>
#define PI 3.14f

void Surface_Area(float r, float h)
{
    float area = 0.0f;

    area = 2 * PI * r * r + 2 * PI * r * h;

    printf("Surface Area of Cylinder = %.2f sq m \n", area);
}

void Volume(float r , float h)
{
    float volume = 0.0f;

    volume = PI * r * r * h;

    printf("Volume of Cylinder = %.2f cubic m \n", volume);
}

int main()
{
    float radius = 0.0f;
    float height = 0.0f;

    printf("Enter Radius of Cylinder : ");
    scanf("%f", &radius);

    printf("Enter Height of Cylinder : ");
    scanf("%f", &height);

    Surface_Area(radius , height);
    Volume(radius , height);
    return 0;
}