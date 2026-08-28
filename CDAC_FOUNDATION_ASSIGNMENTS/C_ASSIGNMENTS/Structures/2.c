//  2. Create a structure employee (id, name, salary). Accept details of n employees
//  and write a menu driven program to perform the following operations.
//  Write separate functions for the different options.
//  i) Search by name
//  ii) Search by id
//  iii) Display all
//  iv) Display all employees having salary > 25000
//  v) Display employee having maximum salary

#include <stdio.h>
#include <string.h>

struct employee
{
    int id;
    char name[50];
    float salary;
};

void Accept(struct employee e[], int n)
{
    int i;

    for(i = 0; i < n; i++)
    {
        printf("\nEnter details of employee %d\n", i + 1);

        printf("Enter ID: ");
        scanf("%d", &e[i].id);
        while(getchar() != '\n');

        printf("Enter Name: ");
        fgets(e[i].name, sizeof(e[i].name), stdin);
        e[i].name[strcspn(e[i].name, "\n")] = '\0';

        printf("Enter Salary: ");
        scanf("%f", &e[i].salary);
    }
}

void SearchByName(struct employee e[], int n)
{
    char name[50];
    int i, found = 0;

    while(getchar() != '\n');

    printf("\nEnter Name to search: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    for(i = 0; i < n; i++)
    {
        if(strcmp(e[i].name, name) == 0)
        {
            printf("\nEmployee Found\n");
            printf("ID     : %d\n", e[i].id);
            printf("Name   : %s\n", e[i].name);
            printf("Salary : %.2f\n", e[i].salary);

            found = 1;
        }
    }

    if(found == 0)
    {
        printf("Employee not found\n");
    }
}

void SearchByID(struct employee e[], int n)
{
    int id, i, found = 0;

    printf("\nEnter ID to search: ");
    scanf("%d", &id);

    for(i = 0; i < n; i++)
    {
        if(e[i].id == id)
        {
            printf("\nEmployee Found\n");
            printf("ID     : %d\n", e[i].id);
            printf("Name   : %s\n", e[i].name);
            printf("Salary : %.2f\n", e[i].salary);

            found = 1;
            break;
        }
    }

    if(found == 0)
    {
        printf("Employee not found\n");
    }
}

void DisplayAll(struct employee e[], int n)
{
    int i;

    printf("\n----- ALL EMPLOYEE DETAILS -----\n");

    for(i = 0; i < n; i++)
    {
        printf("\nID     : %d\n", e[i].id);
        printf("Name   : %s\n", e[i].name);
        printf("Salary : %.2f\n", e[i].salary);
    }
}

void SalaryAbove25000(struct employee e[], int n)
{
    int i;

    printf("\n----- EMPLOYEES HAVING SALARY > 25000 -----\n");

    for(i = 0; i < n; i++)
    {
        if(e[i].salary > 25000)
        {
            printf("\nID     : %d\n", e[i].id);
            printf("Name   : %s\n", e[i].name);
            printf("Salary : %.2f\n", e[i].salary);
        }
    }
}

void MaximumSalary(struct employee e[], int n)
{
    int i, max = 0;

    for(i = 1; i < n; i++)
    {
        if(e[i].salary > e[max].salary)
        {
            max = i;
        }
    }

    printf("\n----- EMPLOYEE HAVING MAXIMUM SALARY -----\n");
    printf("ID     : %d\n", e[max].id);
    printf("Name   : %s\n", e[max].name);
    printf("Salary : %.2f\n", e[max].salary);
}

int main()
{
    struct employee e[100];
    int n, choice;

    printf("Enter number of employees: ");
    scanf("%d", &n);

    Accept(e, n);

    do
    {
        printf("\n\n----- MENU -----\n");
        printf("1. Search by Name\n");
        printf("2. Search by ID\n");
        printf("3. Display All\n");
        printf("4. Display salary > 25000\n");
        printf("5. Display employee having maximum salary\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                SearchByName(e, n);
                break;

            case 2:
                SearchByID(e, n);
                break;

            case 3:
                DisplayAll(e, n);
                break;

            case 4:
                SalaryAbove25000(e, n);
                break;

            case 5:
                MaximumSalary(e, n);
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