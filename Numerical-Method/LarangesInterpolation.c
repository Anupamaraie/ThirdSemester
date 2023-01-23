//6. WAP to implement Lagrange's Interpolation

#include<stdio.h>
#define max 50
int main()
{
	int degree,i=0,data[max],j=0;
	float func[max],x,p,ans;
	printf("Enter the degree of polynomial: ");
	scanf("%d",&degree);
	while (i<degree)
	{
		printf("\n\nEnter the coefficient of x%d: ",i);
		scanf("%d",&data[i]);

		printf("Enter the value of f(x%d): ",i);
		scanf("%f",&func[i]);
		i++;
	}
	printf("\n\nEnter the value of x: ");
	scanf("%f",&x);
	for(i=0;i<degree;i++)
	{
		p=1;
		for(j=0;j<degree;j++)
		{
				if(i != j)
					p= p * (x-data[j])/(data[i]-data[j]);
		}
		ans = ans + func[i]*p;
	}
	printf("%0.4f",ans);
}