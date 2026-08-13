//  4. Accept a lowercase character from the user and check whether the character is a vowel or consonant.
// (Hint: a, e, i, o, u are vowels)

#include <stdio.h>

void Check_Vowel(char ch)
{
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
    {
        printf("%c is : vowel.", ch);
    }

    else
    {
        printf("%c is : consonant.", ch);
    }
}

int main()
{
    char ch;

    printf("Enter a lowercase character: ");
    scanf("%c", &ch);

    Check_Vowel(ch);

    return 0;
}