//  3. Write a C program to copy one array to another using pointers.

#include<stdio.h>

void CopyArray(int *ptr1, int *ptr2, int n)
{
    int i;

    for(i = 0; i < n; i++)
    {
        *ptr2 = *ptr1;

        ptr1++;
        ptr2++;
    }
}

int main()
{
    int Arr1[50], Arr2[50];
    int n, i;

    printf("Enter number of elements : ");
    scanf("%d", &n);

    printf("Enter elements : \n");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &Arr1[i]);
    }

    CopyArray(Arr1, Arr2, n);

    printf("Copied array : \n");

    for(i = 0; i < n; i++)
    {
        printf("%d ", Arr2[i]);
    }

    return 0;
}