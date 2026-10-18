// 4. Write a program to accept an array of n elements and a number
// say key. Check whether key is present in the array or not.

#include<stdio.h>
#include<stdbool.h>

bool Search(int Arr[], int iSize, int iNo)
{
    int iCnt = 0;

    if((Arr == NULL) || (iSize <= 0))
    {
        return false;
    }

    for(iCnt = 0; iCnt < iSize; iCnt++)
    {
        if(Arr[iCnt] == iNo)
        {
            break;
        }
    }

    return (iCnt != iSize);
}

int main()
{
    int iLength = 0, iValue = 0, iCnt = 0;
    bool bRet = false;

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

    printf("Enter the value that you want to search : \n");
    scanf("%d",&iValue);

    bRet = Search(Arr,iLength,iValue);

    if(bRet == true)
    {
        printf("%d is present in the array\n",iValue);
    }
    else
    {
        printf("%d is not present in the array\n",iValue);
    }

    return 0;
}