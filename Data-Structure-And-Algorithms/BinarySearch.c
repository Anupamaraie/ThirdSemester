#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
int BinarySearch(int n, int arr[]);
int Sortarray(int n, int arr[]);
int main()
{
    int arr[100],sort[100],n,i;
    printf("Enter the number of elements in an array: ");
    scanf("%d",&n);
    printf("Enter the elements in array:\n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    Sortarray(n,arr);
    printf("Elements after sorting: ");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    getch();
    BinarySearch(n,arr);
    return 0;
}
int Sortarray(int n, int arr[])
{
    int i,j,temp;
    for(i =0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(arr[i]>arr[j])
            {
                temp = arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}
int BinarySearch(int n,int arr[100])
{
    int mid,l,r,key; // mid=middle, l=left, r= right
    printf("\n\nEnter the key: ");
    scanf("%d",&key);
    l=0;
    r=n-1;
    while(l<=r)
    {
        mid = floor((l+r)/2);
        if(key==arr[mid])
        {
            printf("\n\nKey found at position %d.\n",mid+1);
            exit(1);
        }
        else if (key > arr[mid])
        {
            l=mid+1;
        }
        else if (key < arr[mid])
        {
            r=mid-1;
        }
    }
    printf("\n\nKey not found!!!\n");
}