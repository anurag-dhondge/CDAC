//  6. Write a Program for Return maximum occurring character in the input string.

#include<stdio.h>

void MaxOccurring(char *str)
{
    int Frequency[256] = {0};
    int iCnt = 0;
    int iMax = 0;
    char cMax = '\0';

    if(str == NULL)
    {
        return;
    }

    while(*str != '\0')
    {
        Frequency[(unsigned char)*str]++;
        str++;
    }

    for(iCnt = 0; iCnt < 256; iCnt++)
    {
        if(Frequency[iCnt] > iMax)
        {
            iMax = Frequency[iCnt];
            cMax = (char)iCnt;
        }
    }

    printf("Maximum occurring character is : %c\n",cMax);
}

int main()
{
    char Arr[50];

    printf("Enter string : \n");
    scanf("%s",Arr);

    MaxOccurring(Arr);

    return 0;
}