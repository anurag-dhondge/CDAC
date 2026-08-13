//  4. Write a program to perform the following operations on a square matrix. Write 
//  i) Check if the matrix is symmetric. 
//  ii) Display the trace of the matrix (sum of diagonal elements). 
//  iii) Check if the matrix is an upper triangular matrix. 

#include<stdio.h>
#include<stdbool.h>

bool CheckSymmetric(int Arr[][100], int iSize)
{
    int iCnt = 0, jCnt = 0;

    if((Arr == NULL) || (iSize <= 0))
    {
        return false;
    }

    for(iCnt = 0; iCnt < iSize; iCnt++)
    {
        for(jCnt = 0; jCnt < iSize; jCnt++)
        {
            if(Arr[iCnt][jCnt] != Arr[jCnt][iCnt])
            {
                return false;
            }
        }
    }

    return true;
}

int Trace(int Arr[][100], int iSize)
{
    int iCnt = 0, iSum = 0;

    if((Arr == NULL) || (iSize <= 0))
    {
        return -1;
    }

    for(iCnt = 0; iCnt < iSize; iCnt++)
    {
        iSum = iSum + Arr[iCnt][iCnt];
    }

    return iSum;
}

bool CheckUpperTriangular(int Arr[][100], int iSize)
{
    int iCnt = 0, jCnt = 0;

    if((Arr == NULL) || (iSize <= 0))
    {
        return false;
    }

    for(iCnt = 1; iCnt < iSize; iCnt++)
    {
        for(jCnt = 0; jCnt < iCnt; jCnt++)
        {
            if(Arr[iCnt][jCnt] != 0)
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    int Arr[100][100];
    int iSize = 0;
    int iCnt = 0, jCnt = 0;
    int iRet = 0;
    bool bRet = false;

    printf("Enter size of square matrix : \n");
    scanf("%d",&iSize);

    if((iSize <= 0) || (iSize > 100))
    {
        printf("Invalid matrix size\n");
        return -1;
    }

    printf("Enter the elements : \n");

    for(iCnt = 0; iCnt < iSize; iCnt++)
    {
        for(jCnt = 0; jCnt < iSize; jCnt++)
        {
            scanf("%d",&Arr[iCnt][jCnt]);
        }
    }

    bRet = CheckSymmetric(Arr,iSize);

    if(bRet == true)
    {
        printf("Matrix is symmetric\n");
    }
    else
    {
        printf("Matrix is not symmetric\n");
    }

    iRet = Trace(Arr,iSize);

    printf("Trace of matrix is : %d\n",iRet);

    bRet = CheckUpperTriangular(Arr,iSize);

    if(bRet == true)
    {
        printf("Matrix is upper triangular\n");
    }
    else
    {
        printf("Matrix is not upper triangular\n");
    }

    return 0;
}