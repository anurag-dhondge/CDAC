//  3. The following structure is for a library book with the following details:
//  id, title, publisher, code (1 – Text book, 2 – Magazine, 3 – Reference book).
//  If the code is 1, store no-of-copies.
//  If code = 2, store the issue month name.
//  If code = 3, store edition number.
//  Also store the cost.
//  Write a program to accept details of n books.
//  Use switch-case to accept the code and details according to the code.

#include <stdio.h>
#include <string.h>

struct library_book
{
    int id;
    char title[80];
    char publisher[20];

    int code;

    union u
    {
        int no_of_copies;
        char month[10];
        int edition;
    } info;

    int cost;
};

int main()
{
    struct library_book b[100];
    int n, i = 0;

    printf("Enter number of books: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("\nEnter details of book %d\n", i + 1);

        printf("Enter ID: ");
        scanf("%d", &b[i].id);
        while(getchar() != '\n');

        printf("Enter Title: ");
        fgets(b[i].title, sizeof(b[i].title), stdin);
        b[i].title[strcspn(b[i].title, "\n")] = '\0';

        printf("Enter Publisher: ");
        fgets(b[i].publisher, sizeof(b[i].publisher), stdin);
        b[i].publisher[strcspn(b[i].publisher, "\n")] = '\0';

        printf("\n1. Text Book\n");
        printf("2. Magazine\n");
        printf("3. Reference Book\n");

        printf("Enter Code: ");
        scanf("%d", &b[i].code);

        switch(b[i].code)
        {
            case 1:
                printf("Enter Number of Copies: ");
                scanf("%d", &b[i].info.no_of_copies);
                break;

            case 2:
                while(getchar() != '\n');

                printf("Enter Issue Month: ");
                fgets(b[i].info.month, sizeof(b[i].info.month), stdin);
                b[i].info.month[strcspn(b[i].info.month, "\n")] = '\0';
                break;

            case 3:
                printf("Enter Edition Number: ");
                scanf("%d", &b[i].info.edition);
                break;

            default:
                printf("Invalid Code\n");
        }

        printf("Enter Cost: ");
        scanf("%d", &b[i].cost);
    }

    printf("\n\n----- LIBRARY BOOK DETAILS -----\n");

    for(i = 0; i < n; i++)
    {
        printf("\nBook %d\n", i + 1);

        printf("ID        : %d\n", b[i].id);
        printf("Title     : %s\n", b[i].title);
        printf("Publisher : %s\n", b[i].publisher);

        switch(b[i].code)
        {
            case 1:
                printf("Type      : Text Book\n");
                printf("Copies    : %d\n", b[i].info.no_of_copies);
                break;

            case 2:
                printf("Type      : Magazine\n");
                printf("Month     : %s\n", b[i].info.month);
                break;

            case 3:
                printf("Type      : Reference Book\n");
                printf("Edition   : %d\n", b[i].info.edition);
                break;
        }

        printf("Cost      : %d\n", b[i].cost);
    }

    return 0;
}