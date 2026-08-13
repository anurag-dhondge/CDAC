//  7. Write a function isPrime, which accepts an integer as parameter and
//  returns 1 if the number is prime and 0 otherwise. Use this function
//  in main to display the first 10 prime numbers.

#include<stdio.h>

int isPrime(int num)
{
    int i;

    if(num < 2)
    {
        return 0;
    }

    for(i = 2; i < num; i++)
    {
        if(num % i == 0)
        {
            return 0;
        }
    }

    return 1;
}

int main()
{
    int num = 2;
    int count = 0;

    printf("First 10 prime numbers are : \n");

    while(count < 10)
    {
        if(isPrime(num) == 1)
        {
            printf("%d ", num);
            count++;
        }

        num++;
    }

    return 0;
}