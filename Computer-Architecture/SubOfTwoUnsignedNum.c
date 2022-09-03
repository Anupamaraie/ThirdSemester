//Subtraction
#include<stdio.h>
#include<math.h>
int main()
{
    long int n1,n2;
    int num1=0,num2=0,i=0,d,j=0,diff,arr[20];
    printf("Enter two binary numbers:\n");
    scanf("%ld%ld",&n1,&n2);
    while(n1>0)
    {
        d= n1%10;
        num1 = num1 + d*pow(2,i);
        n1 = n1/10;
        i++;
    }
    while(n2>0)
    {
        d= n2%10;
        num2 = num2 + d*pow(2,j);
        n2 = n2/10;
        j++;
    }
    diff = abs(num1-num2);
    i=0;
    while(diff>0)
    {
        arr[i]= diff % 2;
        diff=diff / 2;
        i++;
    }
    printf("Difference is ");
    if((num1-num2)<0)
    printf("-");
    for(int k=i-1;k>=0;k--)
    {
        printf("%d",arr[k]);
    }
}