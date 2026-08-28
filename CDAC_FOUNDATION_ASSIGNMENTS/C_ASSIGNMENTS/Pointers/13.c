//  13. Write a recursive function to calculate the nth Fibonacci number.
//  Use this function in main to display the first n Fibonacci numbers.
//  The recursive definition of nth Fibonacci number is as follows:
//  fib(n) = 0 if n = 1
//         = 1 if n = 2
//         = fib(n-2) + fib(n-1) if n > 2.

#include<stdio.h>

int Fibonacci(int n)
{
    if(n == 1)
    {
        return 0;
    }

    else if(n == 2)
    {
        return 1;
    }
    
    else
    {
        return Fibonacci(n - 2) + Fibonacci(n - 1);
    }
}

int main()
{
    int n, i;

    printf("Enter number of terms : ");
    scanf("%d", &n);

    printf("Fibonacci series : \n");

    for(i = 1; i <= n; i++)
    {
        printf("%d ", Fibonacci(i));
    }

    return 0;
}