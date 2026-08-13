//  10. Write a recursive C function to calculate the GCD of two numbers.
//  Use this function in main. The GCD is calculated as:
//  gcd(a,b) = a if b = 0
//           = gcd(b, a mod b) otherwise.

#include<stdio.h>

int GCD(int a, int b)
{
    if(b == 0)
    {
        return a;
    }
    else
    {
        return GCD(b, a % b);
    }
}

int main()
{
    int a, b, result;

    printf("Enter two numbers : ");
    scanf("%d%d", &a, &b);

    result = GCD(a, b);

    printf("GCD = %d\n", result);

    return 0;
}