//3. Secant Method

#include<stdio.h>
#include<conio.h>
#include<math.h>
#define max 30
#define E 0.0001
#define f(x) (exp(x)-x-2)
int main()
{
    int count=1;
    float x1,x2,x3,f1,f2;
    printf("Enter two initial values: ");
    scanf("%f%f",&x1,&x2);
    begin:
        f1 = f(x1);
        f2 = f(x2);
        x3 = x2-f2*(x2-x1)/(f2-f1);
        if (fabs((x3-x2)/x3)<E)
        {
            printf("The root is %f\n",x3);
            printf("No. of iteration is %d\n",count);
        }
        else
        {
            x1=x2;
            f1=f2;
            x2=x3;
            count++;
            if(count<max) goto begin;
            else
            printf("The message doesn't converge");
        }
        return 0;
}