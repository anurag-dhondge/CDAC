// 12. Write a C program to display Simple Interest.

#include <stdio.h>

void Simple_Interest(float P, float R, float T)
{
    float SI = 0.0f;

    SI = (P * R * T) / 100.0f;

    printf("Simple Interest : %.2f Rupees\n", SI);
}

int main()
{
    float principal = 0.0f;
    float rate = 0.0f;
    float time = 0.0f;

    printf("Enter Principal Amount (Rupees)     : ");
    scanf("%f", &principal);

    printf("Enter Rate of Interest (%% per year) : ");
    scanf("%f", &rate);

    printf("Enter Time (years)                  : ");
    scanf("%f", &time);

    Simple_Interest(principal, rate, time);

    return 0;
}