#include<stdio.h>
int LinearSearch(int n,int arr[],int key);
int main()
{
    int arr[100],n,key,i;
    printf("\n\n\nEnter the number of elements in array: ");
    scanf("%d",&n);
    printf("Enter array elements:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the key to be searched: ");
    scanf("%d",&key);
    LinearSearch(n,arr,key);
    return 0;
}
int LinearSearch(int n, int arr[],int key)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(arr[i]==key)
        {
            printf("Key %d found at position %d\n",key,i);
            break;
        }
    }
    if(i==n)
    {
        printf("Key not found.!!!\n");
    }
}