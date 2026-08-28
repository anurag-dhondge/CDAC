//  9. Program to Find the Size of int, float, double, and char.

#include <stdio.h>

void Size(int a,float b,double c,char d)
{
    printf("Size of int    : %zu bytes\n", sizeof(a));  //zu for sizeof()
    printf("Size of float  : %zu bytes\n", sizeof(b));
    printf("Size of double : %zu bytes\n", sizeof(c));
    printf("Size of char   : %zu byte\n", sizeof(d));
}

int main()
{
    int a = 0;
    float b = 0.0f;
    double c = 0.0; //Remember
    char d = '\0';

    return 0;
}   
