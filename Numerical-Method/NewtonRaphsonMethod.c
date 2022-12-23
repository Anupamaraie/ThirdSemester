//2. WAP TO FIND THE ROOT OF NON LINEAR  EQN USING NEWTON RAPHSON Method

#include<stdio.h>
#include<conio.h>
#include<math.h>
#define max 20
#define E 0.0001
#define f(x) (log10(x)-cos(x))
#define f1(x) ((1/x)+sin(x))
int main()
{
	int count=1;
	float x0,x1;
	printf("enter the initial guess value:\n");
	scanf("%f",&x0);
	if(f1(x0)==0)
	printf("derivate at guess value is zero");
	else
	{
		begin:
			x1=x0-(f(x0)/f1(x0));
			if(fabs((x1-x0)/x1)<E)
			{
				printf("the root is %f",x1);
				printf("\nNo. of iterations is %d",count);
			}
			else
			{
				x0=x1;
				count++;
				if(count<max)goto begin;
				else
				printf("the process doesnt converge");
			}
	}
	return 0;
}