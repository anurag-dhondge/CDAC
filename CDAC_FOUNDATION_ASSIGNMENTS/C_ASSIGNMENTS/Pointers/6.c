//  6. Write a function isEven, which accepts an integer as parameter and
//  returns 1 if the number is even, and 0 otherwise. Use this function
//  in main to accept n numbers and check if they are even or odd.

#include<stdio.h>

int isEven(int num)
{
    if(num % 2 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int n, num, i;

    printf("Enter number of elements : ");
    scanf("%d", &n);

    printf("Enter numbers : \n");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &num);

        if(isEven(num) == 1)
        {
            printf("%d is Even\n", num);
        }
        else
        {
            printf("%d is Odd\n", num);
        }
    }

    return 0;
}