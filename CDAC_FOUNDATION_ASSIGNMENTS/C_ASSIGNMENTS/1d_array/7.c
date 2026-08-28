// 7. Write a program to accept a decimal number and convert it to binary.

#include<stdio.h>

void DisplayBinary(int iNo)
{
    int Arr[32];
    int iCnt = 0;

    if(iNo < 0)
    {
        printf("Invalid number\n");
        return;
    }

    if(iNo == 0)
    {
        printf("Binary equivalent is : 0\n");
        return;
    }

    while(iNo > 0)
    {
        Arr[iCnt] = iNo % 2;
        iNo = iNo / 2;
        iCnt++;
    }

    printf("Binary equivalent is : ");

    for(iCnt = iCnt - 1; iCnt >= 0; iCnt--)
    {
        printf("%d",Arr[iCnt]);
    }

    printf("\n");
}

int main()
{
    int iValue = 0;

    printf("Enter decimal number : \n");
    scanf("%d",&iValue);

    DisplayBinary(iValue);

    return 0;
}