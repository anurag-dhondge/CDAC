//  5. Write a program to find transpose of matrix. 

#include<stdio.h>

void Transpose(int Arr[][100], int iRow, int iCol)
{
    int iCnt = 0, jCnt = 0;

    if((Arr == NULL) || (iRow <= 0) || (iCol <= 0))
    {
        return;
    }

    printf("Transpose of matrix is : \n");

    for(iCnt = 0; iCnt < iCol; iCnt++)
    {
        for(jCnt = 0; jCnt < iRow; jCnt++)
        {
            printf("%d\t",Arr[jCnt][iCnt]);
        }

        printf("\n");
    }
}

int main()
{
    int Arr[100][100];
    int iRow = 0, iCol = 0;
    int iCnt = 0, jCnt = 0;

    printf("Enter number of rows : \n");
    scanf("%d",&iRow);

    printf("Enter number of columns : \n");
    scanf("%d",&iCol);

    if((iRow <= 0) || (iCol <= 0) ||
       (iRow > 100) || (iCol > 100))
    {
        printf("Invalid matrix size\n");
        return -1;
    }

    printf("Enter the elements : \n");

    for(iCnt = 0; iCnt < iRow; iCnt++)
    {
        for(jCnt = 0; jCnt < iCol; jCnt++)
        {
            scanf("%d",&Arr[iCnt][jCnt]);
        }
    }

    Transpose(Arr,iRow,iCol);

    return 0;
}