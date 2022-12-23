#include<stdio.h>
#include<math.h>
#define f(x) 1/(x+4)

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
    for(i=1;i<=n-1;i++)
    {
        if(i%3==0)
        sum=sum+2*f(l+i*h);
        else
        sum=sum+3*f(l+i*h);
    }
    value = ((3*h)/8)*sum;
    printf("The value of integration is %0.2f\n",value);
    return 0;
}