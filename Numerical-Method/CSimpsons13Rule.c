#include<stdio.h>
#include<math.h>
#define f(x) sin(x)

int main()
{
    int n,i;
    float fx0,fx1,value,sum,h,u,l;
    printf("Enter the lower limit: ");
    scanf("%f",&l);
    printf("Enter the upper limit: ");
    scanf("%f",&u);
    printf("Enter the number of segments: ");
    scanf("%d",&n);
    h = (u-l)/n;
    fx0 =f(l);
    fx1=f(u);
    sum=fx0+fx1;
    for(i=1;i<=n-1;i=i+2)
    {
        sum=sum+4*f(l+i*h);
    }
    for(i=2;i<=n-2;i=i+2)
    {
        sum=sum+2*f(l+i*h);
    }
    value = (h/3)*sum;
    printf("The value of integration is %0.2f\n",value);
    return 0;
}