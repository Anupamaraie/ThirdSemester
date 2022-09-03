//decimal to binary

#include<stdio.h>
int main()
{
    int num,arr[50],i=0;
    printf("Enter the decimal number: ");
    scanf("%d", &num);
    while(num>0)
    {
        arr[i]= num % 2;
        num=num / 2;
        i++;
    }
    printf("The binary number after conversion is ");
    for(i=i-1;i>=0;i--)
    {
        printf("%d",arr[i]);
    }
}