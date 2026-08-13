//  4. WAP to display the Inventory of items in a store/shop.
//  The inventory maintains details such as name, price, quantity
//  and manufacturing date of each item.

#include <stdio.h>
#include <string.h>

struct date
{
    int day;
    int month;
    int year;
};

struct item
{
    char name[50];
    float price;
    int quantity;
    struct date manufacturing_date;
};

int main()
{
    struct item item[100];
    int n, i = 0;

    printf("Enter number of items: ");
    scanf("%d", &n);
    while(getchar() != '\n');

    for(i = 0; i < n; i++)
    {
        printf("\nEnter details of item %d\n", i + 1);

        printf("Enter Name: ");
        fgets(item[i].name, sizeof(item[i].name), stdin);
        item[i].name[strcspn(item[i].name, "\n")] = '\0';

        printf("Enter Price: ");
        scanf("%f", &item[i].price);

        printf("Enter Quantity: ");
        scanf("%d", &item[i].quantity);

        printf("Enter Manufacturing Date (DD MM YYYY): ");
        scanf("%d %d %d",
              &item[i].manufacturing_date.day,
              &item[i].manufacturing_date.month,
              &item[i].manufacturing_date.year);

        while(getchar() != '\n');
    }

    printf("\n\n----- INVENTORY -----\n");

    for(i = 0; i < n; i++)
    {
        printf("\nItem %d\n", i + 1);

        printf("Name               : %s\n", item[i].name);
        printf("Price              : %.2f\n", item[i].price);
        printf("Quantity            : %d\n", item[i].quantity);

        printf("Manufacturing Date : %02d-%02d-%d\n",
               item[i].manufacturing_date.day,
               item[i].manufacturing_date.month,
               item[i].manufacturing_date.year);
    }

    return 0;
}