#include<stdio.h>
#include<conio.h>
#define s 100
void insertion(int[],int);
int main()
{
    int arr[s],n,i;
    printf("Enter the number of array: ");
    scanf("%d",&n);
    printf("Enter the elements in array: ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("Elements before sorting: ");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\nElements after sorting: ");
    insertion(arr,n);
    for(i=0;i<n;i++)
     printf("%d ",arr[i]);
     return 0;
}
void insertion(int arr[s],int n)
{
    int i,j,temp;
    for(i=0;i<n;i++)
    {
        temp = arr[i];
        j=i-1;
        while((temp<arr[j])&& j>=0)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}
