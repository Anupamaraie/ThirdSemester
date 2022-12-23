#include<stdio.h>
#include<math.h>
#include<conio.h>
#define f(x) exp(x)

int main()
{
    float l,u;
    int n,i;
    float h,fx0,fx1,sum,value;
    printf("Enter the lower limit: ");
    scanf("%f",&l);
    printf("Enter the upper limit: ");
    scanf("%f",&u);
    printf("Enter the number of segments: ");
    scanf("%d",&n);
    h = (u-l)/n;
    fx0 = f(l);
    fx1= f(u);
    sum = fx0+fx1;
    for(i=1;i<=n-1;i++)
    {
        sum=sum+2*f(l+i*h);
    }
    value = (h/2)*sum;
    printf("Value of integration is %0.2f\n",value);
    return 0;

}