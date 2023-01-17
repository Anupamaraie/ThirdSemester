/*
 * C Program to Find Multiplication of two Binary Numbers
 */
#include <stdio.h>
 
int binaryproduct(int, int);
 
int main()
{
 
    long b1, b2, m = 0;
    int d, factor = 1;
 
    printf("Enter the binary numbers: ");
    scanf("%ld%ld", &b1,&b2);
    while (b2 != 0)
    {
        d =  b2 % 10;
        if (d == 1)
        {
            b1 = b1 * factor;
            m = binaryproduct(b1, m);
        }
        else
            b1 = b1 * factor;
        b2 = b2 / 10;
        factor = 10;
    }
    printf("Product of two binary numbers: %ld", m);
    return 0;
}
 
int binaryproduct(int b1, int b2)
{
    int i = 0, r = 0, sum[20];
    int binaryprod = 0;
 
    while (b1 != 0 || b2 != 0)
    {
        sum[i++] =(b1 % 10 + b2 % 10 + r) % 2;
        r =(b1 % 10 + b2 % 10 + r) / 2;
        b1 = b1 / 10;
        b2 = b2 / 10;
    }
    if (r != 0)
        sum[i++] = r;
    --i;
    while (i >= 0)
        binaryprod = binaryprod * 10 + sum[i--];
    return binaryprod;
}