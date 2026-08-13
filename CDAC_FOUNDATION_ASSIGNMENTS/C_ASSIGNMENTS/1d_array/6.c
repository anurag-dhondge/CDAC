// 6. Write a program to accept n numbers from the user and store them
// in an array. Then sort the array in descending order and display it.

#include<stdio.h>

void SortDescending(int Arr[], int iSize)
{
    int iCnt = 0, iNext = 0, iTemp = 0;

    if((Arr == NULL) || (iSize <= 0))
    {
        return;
    }

    for(iCnt = 0; iCnt < iSize - 1; iCnt++)
    {
        for(iNext = iCnt + 1; iNext < iSize; iNext++)
        {
            if(Arr[iCnt] < Arr[iNext])
            {
                iTemp = Arr[iCnt];
                Arr[iCnt] = Arr[iNext];
                Arr[iNext] = iTemp;
            }
        }
    }

    printf("Array in descending order is : \n");

    for(iCnt = 0; iCnt < iSize; iCnt++)
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

    SortDescending(Arr,iLength);

    return 0;
}