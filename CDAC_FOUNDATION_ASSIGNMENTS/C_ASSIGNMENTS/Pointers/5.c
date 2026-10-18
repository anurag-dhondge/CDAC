//  5. WAP to accept an array of n integers and calculate sum of odd numbers
//  and even numbers using the pointer to an array.

#include<stdio.h>

void SumOddEven(int *ptr, int n)
{
    int i;
    int oddSum = 0, evenSum = 0;

    for(i = 0; i < n; i++)
    {
        if(*ptr % 2 == 0)
        {
            evenSum = evenSum + *ptr;
        }
        else
        {
            oddSum = oddSum + *ptr;
        }

        ptr++;
    }

    printf("Sum of even numbers = %d\n", evenSum);
    printf("Sum of odd numbers = %d\n", oddSum);
}

int main()
{
    int Arr[50];
    int n, i;

    printf("Enter number of elements : ");
    scanf("%d", &n);

    printf("Enter elements : \n");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &Arr[i]);
    }

    SumOddEven(Arr, n);

    return 0;
}