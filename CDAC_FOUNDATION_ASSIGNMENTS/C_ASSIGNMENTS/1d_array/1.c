//  1. Write a program to accept n numbers in an array and display the largest and smallest number.
//  Using  these values, calculate the range of elements in the array. 

#include<stdio.h>

void Range(int Arr[], int iSize)
{
    int iCnt = 0;
    int iMax, iMin = Arr[0];

    for(iCnt = 1; iCnt < iSize; iCnt++)
    {
        if(Arr[iCnt] > iMax)
        {
            iMax = Arr[iCnt];
        }

        if(Arr[iCnt] < iMin)
        {
            iMin = Arr[iCnt];
        }
    }

    printf("Largest number is : %d\n",iMax);
    printf("Smallest number is : %d\n",iMin);
    printf("Range is : %d\n",iMax - iMin);
}

int main()
{
    int iLength = 0, iCnt = 0;

    printf("Enter number of elements : ");
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

    Range(Arr,iLength);

    return 0;
}