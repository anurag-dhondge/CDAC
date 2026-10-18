//  4. Write a C program to sort array using pointers.

#include<stdio.h>

void SortArray(int *ptr, int n)
{
    int i, j, temp;

    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(*(ptr + i) > *(ptr + j))
            {
                temp = *(ptr + i);
                *(ptr + i) = *(ptr + j);
                *(ptr + j) = temp;
            }
        }
    }
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

    SortArray(Arr, n);

    printf("Sorted array : \n");

    for(i = 0; i < n; i++)
    {
        printf("%d ", Arr[i]);
    }

    return 0;
}