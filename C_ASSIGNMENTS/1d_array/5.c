// 5. Write a program to accept an integer array and an integer say num
// and counts the occurrences of the num in the array.

#include<stdio.h>

int Frequency(int Arr[], int iSize, int iNo)
{
    int iCnt = 0, iCount = 0;

    if((Arr == NULL) || (iSize <= 0))
    {
        return -1;
    }

    for(iCnt = 0; iCnt < iSize; iCnt++)
    {
        if(Arr[iCnt] == iNo)
        {
            iCount++;
        }
    }

    return iCount;
}

int main()
{
    int iLength = 0, iValue = 0;
    int iCnt = 0, iRet = 0;

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

    printf("Enter the value that you want to count : \n");
    scanf("%d",&iValue);

    iRet = Frequency(Arr,iLength,iValue);

    if(iRet == -1)
    {
        printf("There is issue in the input\n");
    }
    else
    {
        printf("%d appears %d times in the array\n",iValue,iRet);
    }

    return 0;
}