//binary to decimal

#include<stdio.h>
#include<math.h>
int main()
{
    int sum=0,num,i=0,d;
    printf("Enter the binary number: ");
    scanf("%d",&num);
    while(num>0)
    {
        d= num%10;
        sum = sum + d*pow(2,i);
        num=num/10;
        i++;
    }
    printf("The decimal number after conversion is %d",sum);
}