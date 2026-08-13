//  7. Write a C program to accept a character and invert the case of it.

#include <stdio.h>

void Invert_Case(char ch)
{
    if (ch >= 'A' && ch <= 'Z')
    {
        ch = ch + 32;
        printf("The inverted character is : %c", ch);
    }

    else if (ch >= 'a' && ch <= 'z')
    {
        ch = ch - 32;
        printf("The inverted character is : %c", ch);
    }
    
    else
    {
        printf("The entered character is not an alphabet.");
    }
}

int main()
{
    char ch;

    printf("Enter a character: ");
    scanf("%c", &ch);

    Invert_Case(ch);

    return 0;
}