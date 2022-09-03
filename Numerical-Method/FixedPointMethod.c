//4. write a program to find the root of the non linear equation using fixed point method
#include<stdio.h>
#include<conio.h>
#include<math.h>

#define MAX 20
#define E 0.0001
#define g(x) (exp(x)-2)//exp(x)-x-2=0 ,x=exp(x)
int main()
{
	int count =1;
	float x0,x1,error;
	printf("Enter your initial guess value");
	scanf("%f",&x0);
	begin:
	x1= g(x0);
	error = x1-x0;
	if(fabs(error)<E)
	{
		printf("The root of your equation is : %f",x1);
		printf("\nNo of iteration is %d", count);
	}
	else
	{
		x0=x1;
		count = count +1;
		 if(count<MAX)goto begin;
		 else 
		 printf("The process  doesn't covered");
	}
}