//  8. Write the program to display 5 employee details with 
//  their Employee_Name, Employee_id and department.


#include <stdio.h>

void Employee_1(char name[], int id, char dept[])
{
    printf("\nEmployee 1\n");
    printf("Employee Name : %s\n", name);
    printf("Employee ID   : %d\n", id);
    printf("Department    : %s\n", dept);
}

void Employee_2(char name[], int id, char dept[])
{
    printf("\nEmployee 2\n");
    printf("Employee Name : %s\n", name);
    printf("Employee ID   : %d\n", id);
    printf("Department    : %s\n", dept);
}

void Employee_3(char name[], int id, char dept[])
{
    printf("\nEmployee 3\n");
    printf("Employee Name : %s\n", name);
    printf("Employee ID   : %d\n", id);
    printf("Department    : %s\n", dept);
}

void Employee_4(char name[], int id, char dept[])
{
    printf("\nEmployee 4\n");
    printf("Employee Name : %s\n", name);
    printf("Employee ID   : %d\n", id);
    printf("Department    : %s\n", dept);
}

void Employee_5(char name[], int id, char dept[])
{
    printf("\nEmployee 5\n");
    printf("Employee Name : %s\n", name);
    printf("Employee ID   : %d\n", id);
    printf("Department    : %s\n", dept);
}

int main()
{
    char name_1[50] = "";
    int id_1 = 0;
    char dept_1[50] = "";

    char name_2[50] = "";
    int id_2 = 0;
    char dept_2[50] = "";

    char name_3[50] = "";
    int id_3 = 0;
    char dept_3[50] = "";

    char name_4[50] = "";
    int id_4 = 0;
    char dept_4[50] = "";

    char name_5[50] = "";
    int id_5 = 0;
    char dept_5[50] = "";

    
    printf("Enter first name : ");
    scanf("%s",name_1);

    printf("Enter first id : ");
    scanf("%d",&id_1);

    printf(" Enter first department: ");
    scanf("%s",dept_1);


    printf("Enter second name : ");
    scanf("%s",name_2);

    printf("Enter second id : ");
    scanf("%d",&id_2);

    printf(" Enter second department: ");
    scanf("%s",dept_2);


    printf("Enter third name : ");
    scanf("%s",name_3);

    printf("Enter third id : ");
    scanf("%d",&id_3);

    printf(" Enter third department: ");
    scanf("%s",dept_3);


    printf("Enter fourth name : ");
    scanf("%s",name_4);

    printf("Enter fourth id : ");
    scanf("%d",&id_4);

    printf(" Enter fourth department: ");
    scanf("%s",dept_4);


    printf("Enter fifth name : ");
    scanf("%s",name_5);

    printf("Enter fifth id : ");
    scanf("%d",&id_5);

    printf(" Enter fifth department: ");
    scanf("%s",dept_5);

    Employee_1(name_1, id_1, dept_1);

    Employee_2(name_2, id_2, dept_2);
    
    Employee_3(name_3, id_3, dept_3);
    
    Employee_4(name_4, id_4, dept_4);
    
    Employee_5(name_5, id_5, dept_5);

    return 0;
}