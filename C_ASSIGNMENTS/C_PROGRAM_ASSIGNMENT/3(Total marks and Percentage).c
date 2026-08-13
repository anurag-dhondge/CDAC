//  3. Accept marks of 5 subjects (out of 100) of a student and 
//  display total marks and compute the percentage also.

#include<stdio.h>

void Total_Marks(float a, float b, float c, float d, float e)
{
    float sum = 0;
    sum = a + b + c + d + e;
    printf("Total_Marks = %.2f",sum);
}

void Percentage(float a, float b, float c, float d, float e)
{
    float sum = 0;
    sum = a + b + c + d + e;
    float percentage = 0.0f;
    percentage = (sum / 500.0) * 100;
    printf("Percentage = %.2f %%",percentage);

}
int main()
{
    int A,B,C,D,E = 0;

    printf("Enter Subject 1 Marks : ");
    scanf("%f",&A);
    printf("Enter Subject 2 Marks : ");
    scanf("%f",&B);
    printf("Enter Subject 3 Marks : ");
    scanf("%f",&C);
    printf("Enter Subject 4 Marks : ");
    scanf("%f",&D);
    printf("Enter Subject 5 Marks : ");
    scanf("%f",&E);
    
    Total_Marks(A,B,C,D,E);
    Percentage(A,B,C,D,E);

    return 0;
}