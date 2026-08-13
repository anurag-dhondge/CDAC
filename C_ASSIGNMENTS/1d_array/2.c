// 2. Write a program to store n numbers in array and display them in reverse order.

#include<stdio.h>

void Reverse(int Arr[], int iSize)
{
    int iCnt = 0;

    if((Arr == NULL) || (iSize <= 0))
    {
        return;
    }

    printf("Elements in reverse order are : \n");

    for(iCnt = iSize - 1; iCnt >= 0; iCnt--)
    {
        printf("%d\n",Arr[iCnt]);
    }
}

int main()
{
    int iLength = 0, iCnt = 0;

    printf("Enter number of elements : \n");
    scanf("%d",&iLength);

    if(iLength <= 0)
    {
        printf("Invalid number of elements\n");
        return -1;
    }

    int Arr[iLength];

    printf("Enter the elements : \n");

    for(iCnt = 0; iCnt < iLength; iCnt++)
    {
        printf("Enter number %d : ",iCnt + 1);
        scanf("%d",&Arr[iCnt]);
    }

    Reverse(Arr,iLength);

    return 0;
}