/*
    3. Write a program to convert decimal number to binary using function.
*/

#include <stdio.h>

void DecimalToBinary(int n)
{
    int binary[32];
    int i = 0;

    if(n == 0)
    {
        printf("Binary is : 0\n");
        return;
    }

    while(n > 0)
    {
        binary[i] = n % 2;
        n = n / 2;
        i++;
    }

    printf("Binary is : ");

    i--;

    while(i >= 0)
    {
        printf("%d", binary[i]);
        i--;
    }

    printf("\n");
}

int main()
{
    int n;

    printf("Enter decimal number: ");
    scanf("%d", &n);

    DecimalToBinary(n);

    return 0;
}