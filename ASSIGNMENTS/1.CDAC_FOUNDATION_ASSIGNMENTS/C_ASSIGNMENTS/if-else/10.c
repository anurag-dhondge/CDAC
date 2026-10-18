/*
    10. Program to display 3 students grades with 
    marks > 75 with Grade = A+ 
    marks < 75 and marks > 65 grade = A and 
    marks < 60 grade = B
*/ 

#include <stdio.h>

void Display_Grade(int marks)
{
    if (marks >= 75)
    {
        printf("Grade = A+\n");
    }

    else if (marks > 65)
    {
        printf("Grade = A\n");
    }

    else if (marks < 60)
    {
        printf("Grade = B\n");
    }
    
    else
    {
        printf("No grade specified.\n");
    }
}

int main()
{
    int marks1, marks2, marks3;

    printf("Enter marks of Student 1: ");
    scanf("%d", &marks1);

    printf("Enter marks of Student 2: ");
    scanf("%d", &marks2);

    printf("Enter marks of Student 3: ");
    scanf("%d", &marks3);

    printf("\nStudent 1: ");
    Display_Grade(marks1);

    printf("Student 2: ");
    Display_Grade(marks2);

    printf("Student 3: ");
    Display_Grade(marks3);

    return 0;
}