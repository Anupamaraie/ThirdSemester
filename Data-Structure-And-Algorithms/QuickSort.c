//QUICK SORT

#include<stdio.h>
#include<conio.h>
#define s 100

int partition(int arr[s], int l, int r)
{
    int x=l;
    int y=r;
    int p=arr[l],temp;
    while(x<y)
    {
        while(arr[x]<=p)
            x++;
        while(arr[y]>p)
            y--;
        if(x<y)
        {
            temp=arr[x];
            arr[x]=arr[y];
            arr[y]=temp;
        }
    }
    arr[l]=arr[y];
    arr[y]=p;
    return y;
}

void quicksort(int arr[s], int l, int r)
{
    int p;
    if(l<r)
    {
         p=partition(arr,l,r);
        quicksort(arr,l,p-1);
        quicksort (arr,p+1,r);
    }
}
int main()
{
    int arr[s],n,i,l,r;
    printf("Enter the number of array: ");
    scanf("%d",&n);
    l=0;
    r=n-1;
    printf("Enter the elements in array: ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("Elements before sorting: ");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\nElements after sorting: ");
    quicksort(arr,l,r);
    for(i=0;i<n;i++)
     printf("%d ",arr[i]);
     return 0;
}

