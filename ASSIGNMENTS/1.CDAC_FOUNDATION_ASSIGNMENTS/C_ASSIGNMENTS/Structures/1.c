//   Create a structure student (roll number, name, marks of 3 subjects, percentage).
//   Accept details of n students and write a menu driven program to perform the following operations.
//   Write separate functions for the different options.
//   i) Search
//   ii) Modify
//   iii) Display all student details
//   iv) Display all student having percentage > 80
//   v) Display student having maximum percentage

#include <stdio.h>
#include <string.h>

struct student
{
    int rollno;
    char name[50];
    float marks[3];
    float percentage;
};

void Accept(struct student s[], int n)
{
    int i = 0;

    for(i = 0; i < n; i++)
    {
        printf("\nEnter details of student %d\n", i + 1);

        printf("Enter Roll Number: ");
        scanf("%d", &s[i].rollno);
        while(getchar() != '\n');

        printf("Enter Name: ");
        fgets(s[i].name, sizeof(s[i].name), stdin);
        s[i].name[strcspn(s[i].name, "\n")] = '\0';

        printf("Enter marks of 3 subjects: ");
        scanf("%f %f %f",
              &s[i].marks[0],
              &s[i].marks[1],
              &s[i].marks[2]);

        s[i].percentage =
            (s[i].marks[0] + s[i].marks[1] + s[i].marks[2]) / 3;
    }
}

void Search(struct student s[], int n)
{
    int roll, i, found = 0;

    printf("\nEnter Roll Number to search: ");
    scanf("%d", &roll);

    for(i = 0; i < n; i++)
    {
        if(s[i].rollno == roll)
        {
            printf("\nStudent Found\n");
            printf("Roll Number : %d\n", s[i].rollno);
            printf("Name        : %s\n", s[i].name);
            printf("Marks       : %.2f %.2f %.2f\n",
                   s[i].marks[0],
                   s[i].marks[1],
                   s[i].marks[2]);
            printf("Percentage  : %.2f\n", s[i].percentage);

            found = 1;
            break;
        }
    }

    if(found == 0)
    {
        printf("Student not found\n");
    }
}

void Modify(struct student s[], int n)
{
    int roll, i, found = 0;

    printf("\nEnter Roll Number to modify: ");
    scanf("%d", &roll);
    while(getchar() != '\n');

    for(i = 0; i < n; i++)
    {
        if(s[i].rollno == roll)
        {
            printf("Enter New Name: ");
            fgets(s[i].name, sizeof(s[i].name), stdin);
            s[i].name[strcspn(s[i].name, "\n")] = '\0';

            printf("Enter New marks of 3 subjects: ");
            scanf("%f %f %f",
                  &s[i].marks[0],
                  &s[i].marks[1],
                  &s[i].marks[2]);

            s[i].percentage =
                (s[i].marks[0] + s[i].marks[1] + s[i].marks[2]) / 3;

            printf("Student details modified successfully\n");

            found = 1;
            break;
        }
    }

    if(found == 0)
    {
        printf("Student not found\n");
    }
}

void DisplayAll(struct student s[], int n)
{
    int i = 0;

    printf("\n----- ALL STUDENT DETAILS -----\n");

    for(i = 0; i < n; i++)
    {
        printf("\nRoll Number : %d\n", s[i].rollno);
        printf("Name        : %s\n", s[i].name);
        printf("Marks       : %.2f %.2f %.2f\n",
               s[i].marks[0],
               s[i].marks[1],
               s[i].marks[2]);
        printf("Percentage  : %.2f\n", s[i].percentage);
    }
}

void DisplayAbove80(struct student s[], int n)
{
    int i = 0;

    printf("\n----- STUDENTS HAVING PERCENTAGE > 80 -----\n");

    for(i = 0; i < n; i++)
    {
        if(s[i].percentage > 80)
        {
            printf("\nRoll Number : %d\n", s[i].rollno);
            printf("Name        : %s\n", s[i].name);
            printf("Percentage  : %.2f\n", s[i].percentage);
        }
    }
}

void Maximum(struct student s[], int n)
{
    int i, max = 0;

    for(i = 1; i < n; i++)
    {
        if(s[i].percentage > s[max].percentage)
        {
            max = i;
        }
    }

    printf("\n----- STUDENT HAVING MAXIMUM PERCENTAGE -----\n");
    printf("Roll Number : %d\n", s[max].rollno);
    printf("Name        : %s\n", s[max].name);
    printf("Percentage  : %.2f\n", s[max].percentage);
}

int main()
{
    struct student s[100];
    int n, choice = 0;

    printf("Enter number of students: ");
    scanf("%d", &n);

    Accept(s, n);

    do
    {
        printf("\n\n----- MENU -----\n");
        printf("1. Search\n");
        printf("2. Modify\n");
        printf("3. Display All\n");
        printf("4. Display percentage > 80\n");
        printf("5. Display maximum percentage\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                Search(s, n);
                break;

            case 2:
                Modify(s, n);
                break;

            case 3:
                DisplayAll(s, n);
                break;

            case 4:
                DisplayAbove80(s, n);
                break;

            case 5:
                Maximum(s, n);
                break;

            case 6:
                printf("Program terminated\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while(choice != 6);

    return 0;
}