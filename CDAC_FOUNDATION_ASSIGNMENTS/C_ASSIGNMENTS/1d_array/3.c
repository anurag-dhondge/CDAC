// 3. Write a Program for deletion of an element from the specified
// location from Array.

#include<stdio.h>

void Delete(int Arr[], int iSize, int iPos)
{
    int iCnt = 0;

    if((Arr == NULL) || (iSize <= 0))
    {
        return;
    }

    if((iPos < 0) || (iPos >= iSize))
    {
        printf("Invalid position\n");
        return;
    }

    for(iCnt = iPos; iCnt < iSize - 1; iCnt++)
    {
        Arr[iCnt] = Arr[iCnt + 1];
    }

    printf("Array after deletion is : \n");

    for(iCnt = 0; iCnt < iSize - 1; iCnt++)
    {
        printf("%d\n",Arr[iCnt]);
    }
}

int main()
{
    int iLength = 0, iCnt = 0, iPos = 0;

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

    printf("Enter the position to delete : \n");
    scanf("%d",&iPos);

    Delete(Arr,iLength,iPos);

    return 0;
}