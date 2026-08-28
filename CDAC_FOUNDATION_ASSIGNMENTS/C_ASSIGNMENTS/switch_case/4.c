/*
    4. Accept radius from the user and write a program having menu with the following options 
    and corresponding actions:

    Options Actions
    1. Area of Circle
    2. Circumference of Circle
    3. Volume of Sphere
*/

#include <stdio.h>

#define PI 3.14

void Area(float radius)
{
    float area = PI * radius * radius;
    printf("Area of Circle = %.2f", area);
}

void Circumference(float radius)
{
    float circumference = 2 * PI * radius;
    printf("Circumference of Circle = %.2f", circumference);
}

void Volume(float radius)
{
    float volume = (4.0 / 3.0) * PI * radius * radius * radius;
    printf("Volume of Sphere = %.2f", volume);
}

int main()
{
    float radius;
    int choice;

    printf("Enter radius: ");
    scanf("%f", &radius);

    printf("\n1. Area of Circle");
    printf("\n2. Circumference of Circle");
    printf("\n3. Volume of Sphere");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            Area(radius);
            break;

        case 2:
            Circumference(radius);
            break;

        case 3:
            Volume(radius);
            break;

        default:
            printf("Invalid choice");
    }

    return 0;
}