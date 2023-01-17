//Addition

#include<stdio.h>
int main()
{
    int num1,num2,sum[50],i=0,car = 0;
    printf("Enter two binary numbers:\n");
    scanf("%d%d",&num1,&num2);

    while(num1 != 0 || num2 != 0)
    {
        sum[i++] = (num1 % 10 + num2%10 + car)%2;
        car = (num1%10+num2%10+car)/2;
        num1 = num1/10;
        num2 = num2/10;
    }
    if(car != 0)
        sum[i++] = car;
    i--;
    printf("Sum = ");
    while(i>=0)
    {
        printf("%d",sum[i]);
        i--;
    }
}
