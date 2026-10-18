// 2. Accept a character from user and display ASCII value of it.

#include<stdio.h>

ASCII(char ch)
{
    printf("ASCII Value of character is : %d",ch);
}

int main()
{
    char ch = '\0';
    printf("Enter a character value     : ");
    scanf("%c",&ch);

    ASCII(ch);

    return 0;
}