//  8. Write the program having menu to display student information with accept  
//  employee_name,emp_id,Employee salary,display employee details.

#include <stdio.h>

void EmployeeDetails(char name[], int *id, float *salary)
{
    printf("Enter Employee Name  : ");
    scanf("%s", name);

    printf("Enter Employee ID    : ");
    scanf("%d", id);

    printf("Enter Employee Salary: ");
    scanf("%f", salary);

    printf("\n--- Employee Details ---\n");
    printf("Employee Name   : %s\n", name);
    printf("Employee ID     : %d\n", *id);
    printf("Employee Salary : %.2f\n", *salary);
}

int main()
{
    char name[50];
    int id;
    float salary;
    int choice;

    printf("--- Employee Management Menu ---\n");
    printf("1. Accept and Display Employee Details\n");
    printf("2. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            EmployeeDetails(name, &id, &salary);
            break;

        case 2:
            printf("Exiting...");
            break;

        default:
            printf("Invalid choice!");
    }

    return 0;
}