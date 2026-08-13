/*
    11. Write a C program to count the total number of characters in
    an input line through keyboard using recursive function.
*/

#include <stdio.h>

int CountCharacters(char *str)
{
    if(*str == '\0' || *str == '\n')
    {
        return 0;
    }

    return 1 + CountCharacters(str + 1);
}

int main()
{
    char str[100];
    int iRet;

    printf("Enter a line: ");
    fgets(str, sizeof(str), stdin);

    iRet = CountCharacters(str);

    printf("Total number of characters is : %d\n", iRet);

    return 0;
}