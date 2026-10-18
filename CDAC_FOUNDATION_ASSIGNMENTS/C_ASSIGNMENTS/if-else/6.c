// 6. Write a C program to check whether an entered character is uppercase or lowercase alphabet.

#include <stdio.h>

void Check_Alphabet(char ch)
{
    if (ch >= 'A' && ch <= 'Z')
    {
        printf("The character %c is : Uppercase Alphabet.", ch);
    }

    else if (ch >= 'a' && ch <= 'z')
    {
        printf("The character %c is : Lowercase Alphabet.", ch);
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

    Check_Alphabet(ch);

    return 0;
}