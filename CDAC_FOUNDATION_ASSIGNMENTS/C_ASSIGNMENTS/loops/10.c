//  10. Write a program to check Whether a Number is Palindrome or Not.

#include <stdio.h>

void Palindrome(int num)
{
    int original, reverse, rem = 0;

    original = num;

    while(num > 0)
    {
        rem = num % 10;
        reverse = reverse * 10 + rem;
        num = num / 10;
    }

    if(original == reverse)
    {
        printf("Number is Palindrome.");
    }
    
    else
    {
        printf("Number is not Palindrome.");
    }
}

int main()
{
    int num = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    Palindrome(num);

    return 0;
}