/*
    1. Write a program to check whether character is a lowercase or not or space.
    (Use In build library function)
*/

#include <stdio.h>
#include <ctype.h>

void CheckCharacter(char ch)
{
    if(islower(ch))
    {
        printf("Character is lowercase\n");
    }

    else if(isspace(ch))
    {
        printf("Character is space\n");
    }

    else
    {
        printf("Character is neither lowercase nor space\n");
    }
}

int main()
{
    char ch;

    printf("Enter a character: ");
    scanf("%c", &ch);

    CheckCharacter(ch);

    return 0;
}