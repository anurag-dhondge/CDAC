//  1. Write a program to accept, display and print the sum of elements of each row and 
//  sum of elements of  each column of a matrix. 

#include<stdio.h>

void DisplayMatrix(int Arr[][100], int iRow, int iCol)
{
    int iCnt = 0, jCnt = 0;

    if((Arr == NULL) || (iRow <= 0) || (iCol <= 0))
    {
        return;
    }

    printf("Elements of matrix are : \n");

    for(iCnt = 0; iCnt < iRow; iCnt++)
    {
        for(jCnt = 0; jCnt < iCol; jCnt++)
        {
            printf("%d\t",Arr[iCnt][jCnt]);
        }

        printf("\n");
    }
}

void RowSum(int Arr[][100], int iRow, int iCol)
{
    int iCnt = 0, jCnt = 0, iSum = 0;

    if((Arr == NULL) || (iRow <= 0) || (iCol <= 0))
    {
        return;
    }

    for(iCnt = 0; iCnt < iRow; iCnt++)
    {
        iSum = 0;

        for(jCnt = 0; jCnt < iCol; jCnt++)
        {
            iSum = iSum + Arr[iCnt][jCnt];
        }

        printf("Sum of row %d = %d\n",iCnt + 1,iSum);
    }
}

void ColumnSum(int Arr[][100], int iRow, int iCol)
{
    int iCnt = 0, jCnt = 0, iSum = 0;

    if((Arr == NULL) || (iRow <= 0) || (iCol <= 0))
    {
        return;
    }

    for(jCnt = 0; jCnt < iCol; jCnt++)
    {
        iSum = 0;

        for(iCnt = 0; iCnt < iRow; iCnt++)
        {
            iSum = iSum + Arr[iCnt][jCnt];
        }

        printf("Sum of column %d = %d\n",jCnt + 1,iSum);
    }
}

int main()
{
    int iRow = 0, iCol = 0;
    int iCnt = 0, jCnt = 0;

    printf("Enter number of rows : \n");
    scanf("%d",&iRow);

    printf("Enter number of columns : \n");
    scanf("%d",&iCol);

    if((iRow <= 0) || (iCol <= 0) || (iRow > 100) || (iCol > 100))
    {
        printf("Invalid matrix size\n");
        return -1;
    }

    int Arr[100][100];

    printf("Enter the elements : \n");

    for(iCnt = 0; iCnt < iRow; iCnt++)
    {
        for(jCnt = 0; jCnt < iCol; jCnt++)
        {
            scanf("%d",&Arr[iCnt][jCnt]);
        }
    }

    DisplayMatrix(Arr,iRow,iCol);

    RowSum(Arr,iRow,iCol);

    ColumnSum(Arr,iRow,iCol);

    return 0;
}