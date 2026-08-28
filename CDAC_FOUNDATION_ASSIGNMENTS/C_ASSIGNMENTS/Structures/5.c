//  5. Create a structure named cricket that accepts cricketer name,
//  team name, average and highest score.
//  Enter values for 5 cricketer and display it using concept of array of structure.

#include <stdio.h>
#include <string.h>

struct cricket
{
    char cricketer_name[50];
    char team_name[50];
    float average;
    int highest_score;
};

int main()
{
    struct cricket c[5];
    int i = 0;

    printf("Enter details of 5 cricketers\n");

    for(i = 0; i < 5; i++)
    {
        printf("\nEnter details of cricketer %d\n", i + 1);

        printf("Enter Cricketer Name: ");
        fgets(c[i].cricketer_name,
              sizeof(c[i].cricketer_name), stdin);
        c[i].cricketer_name[strcspn(c[i].cricketer_name, "\n")] = '\0';

        printf("Enter Team Name: ");
        fgets(c[i].team_name,
              sizeof(c[i].team_name), stdin);
        c[i].team_name[strcspn(c[i].team_name, "\n")] = '\0';

        printf("Enter Average: ");
        scanf("%f", &c[i].average);

        printf("Enter Highest Score: ");
        scanf("%d", &c[i].highest_score);

        while(getchar() != '\n');
    }

    printf("\n\n----- CRICKETER DETAILS -----\n");

    for(i = 0; i < 5; i++)
    {
        printf("\nCricketer %d\n", i + 1);

        printf("Cricketer Name : %s\n", c[i].cricketer_name);
        printf("Team Name      : %s\n", c[i].team_name);
        printf("Average        : %.2f\n", c[i].average);
        printf("Highest Score  : %d\n", c[i].highest_score);
    }

    return 0;
}