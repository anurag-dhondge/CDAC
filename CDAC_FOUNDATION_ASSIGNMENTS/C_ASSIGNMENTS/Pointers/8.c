//  8. For the following standard functions, write corresponding user defined
//  functions and write a menu driven program to use them.
//  strcat, strcmp, strrev, strupr.

#include<stdio.h>

void MyStrcat(char str1[], char str2[])
{
    int i = 0, j = 0;

    while(str1[i] != '\0')
    {
        i++;
    }

    while(str2[j] != '\0')
    {
        str1[i] = str2[j];
        i++;
        j++;
    }

    str1[i] = '\0';
}

int MyStrcmp(char str1[], char str2[])
{
    int i = 0;

    while(str1[i] != '\0' && str2[i] != '\0')
    {
        if(str1[i] != str2[i])
        {
            return str1[i] - str2[i];
        }

        i++;
    }

    return str1[i] - str2[i];
}

void MyStrrev(char str[])
{
    int i = 0, j = 0;
    char temp;

    while(str[j] != '\0')
    {
        j++;
    }

    j--;

    while(i < j)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;

        i++;
        j--;
    }
}

void MyStrupr(char str[])
{
    int i = 0;

    while(str[i] != '\0')
    {
        if(str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = str[i] - 32;
        }

        i++;
    }
}

int main()
{
    char str1[100], str2[100];
    int choice, result;

    printf("Enter first string : ");
    scanf("%s", str1);

    printf("Enter second string : ");
    scanf("%s", str2);

    printf("\n1. strcat");
    printf("\n2. strcmp");
    printf("\n3. strrev");
    printf("\n4. strupr");

    printf("\nEnter your choice : ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            MyStrcat(str1, str2);
            printf("Concatenated string = %s\n", str1);
            break;

        case 2:
            result = MyStrcmp(str1, str2);

            if(result == 0)
            {
                printf("Strings are equal\n");
            }
            else if(result > 0)
            {
                printf("First string is greater\n");
            }
            else
            {
                printf("Second string is greater\n");
            }

            break;

        case 3:
            MyStrrev(str1);
            printf("Reversed string = %s\n", str1);
            break;

        case 4:
            MyStrupr(str1);
            printf("Uppercase string = %s\n", str1);
            break;

        default:
            printf("Invalid choice\n");
    }

    return 0;
}