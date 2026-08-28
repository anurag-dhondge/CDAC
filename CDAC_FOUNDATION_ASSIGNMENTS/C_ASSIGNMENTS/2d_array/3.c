//  3. Write a program to add and multiply two matrices. 
//  Perform necessary checks before adding and  multiplying the matrices. 

#include<stdio.h>

void Addition(int Arr1[][100], int Arr2[][100], int iRow, int iCol)
{
    int iCnt = 0, jCnt = 0;

    if((Arr1 == NULL) || (Arr2 == NULL) || (iRow <= 0) || (iCol <= 0))
    {
        return;
    }

    printf("Addition of matrices is : \n");

    for(iCnt = 0; iCnt < iRow; iCnt++)
    {
        for(jCnt = 0; jCnt < iCol; jCnt++)
        {
            printf("%d\t",Arr1[iCnt][jCnt] + Arr2[iCnt][jCnt]);
        }

        printf("\n");
    }
}

void Multiplication(int Arr1[][100], int Arr2[][100], int Result[][100],
                    int iRow1, int iCol1, int iRow2, int iCol2)
{
    int i = 0, j = 0, k = 0;

    if((Arr1 == NULL) || (Arr2 == NULL) || (Result == NULL))
    {
        return;
    }

    if(iCol1 != iRow2)
    {
        printf("Matrix multiplication is not possible\n");
        return;
    }

    for(i = 0; i < iRow1; i++)
    {
        for(j = 0; j < iCol2; j++)
        {
            Result[i][j] = 0;

            for(k = 0; k < iCol1; k++)
            {
                Result[i][j] = Result[i][j] +
                               Arr1[i][k] * Arr2[k][j];
            }
        }
    }

    printf("Multiplication of matrices is : \n");

    for(i = 0; i < iRow1; i++)
    {
        for(j = 0; j < iCol2; j++)
        {
            printf("%d\t",Result[i][j]);
        }

        printf("\n");
    }
}

int main()
{
    int iRow1 = 0, iCol1 = 0;
    int iRow2 = 0, iCol2 = 0;
    int iCnt = 0, jCnt = 0;

    int Arr1[100][100];
    int Arr2[100][100];
    int Result[100][100];

    printf("Enter rows and columns of first matrix : \n");
    scanf("%d%d",&iRow1,&iCol1);

    printf("Enter rows and columns of second matrix : \n");
    scanf("%d%d",&iRow2,&iCol2);

    if((iRow1 <= 0) || (iCol1 <= 0) ||
       (iRow2 <= 0) || (iCol2 <= 0) ||
       (iRow1 > 100) || (iCol1 > 100) ||
       (iRow2 > 100) || (iCol2 > 100))
    {
        printf("Invalid matrix size\n");
        return -1;
    }

    printf("Enter elements of first matrix : \n");

    for(iCnt = 0; iCnt < iRow1; iCnt++)
    {
        for(jCnt = 0; jCnt < iCol1; jCnt++)
        {
            scanf("%d",&Arr1[iCnt][jCnt]);
        }
    }

    printf("Enter elements of second matrix : \n");

    for(iCnt = 0; iCnt < iRow2; iCnt++)
    {
        for(jCnt = 0; jCnt < iCol2; jCnt++)
        {
            scanf("%d",&Arr2[iCnt][jCnt]);
        }
    }

    if((iRow1 == iRow2) && (iCol1 == iCol2))
    {
        Addition(Arr1,Arr2,iRow1,iCol1);
    }
    else
    {
        printf("Matrix addition is not possible\n");
    }

    Multiplication(Arr1,Arr2,Result,
                   iRow1,iCol1,iRow2,iCol2);

    return 0;
}