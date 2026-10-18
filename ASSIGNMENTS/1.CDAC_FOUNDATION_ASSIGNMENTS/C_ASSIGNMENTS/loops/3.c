//  3. Write a program to accept a character, an integer n and display the next n characters.

#include <stdio.h>

void NextCharacters(char ch, int n)
{
    int i = 0;

    for(i = 1; i <= n; i++)
    {
        ch = ch + 1;
        printf("%c ", ch);
    }
}

int main()
{
    char ch = '\0';
    int n = 0;

    printf("Enter a character: ");
    scanf("%c", &ch);

    printf("Enter n: ");
    scanf("%d", &n);

    NextCharacters(ch, n);

    return 0;
}