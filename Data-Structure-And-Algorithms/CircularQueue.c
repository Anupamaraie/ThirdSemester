//Circular queue
#include<stdio.h>
#include<stdlib.h>
#define max 5
struct cqueue
{
    int front,rear;
    int items[max];
};
int c=0;
typedef struct cqueue cq;
int isempty(cq *q)
{
    // if(q->rear==q->front)
    if(c==0)
    return 1;
    else
    return 0;
}
int isfull(cq *q)
{
    // if(q->front == (q->rear+1)% max)
    if(c==max)
    return 1;
    else
    return 0;
}
int enqueue(cq *q)
{
    if(isfull(q))
    {
        printf("Queue is full.\n");
    }
    else
    {
        int num;
        printf("Enter the number to enqueue: ");
        scanf("%d",&num);
        q->rear = (q->rear+1)%max;
        q->items[q->rear]=num;
        printf("Enqueued element is %d.\n",q->items[q->rear]);
        c++; //remove c if not sacrificing one cell
    }
}
int dequeue(cq *q)
{
    if(isempty(q))
    printf("Queue is empty.\n");
    else
    {
        c--; //remove c if not sacrificing one cell
        q->front = (q->front+1)%max;
        return q->items[q->front];
        
    }
}
int traverse(cq *q)
{
    if(isempty(q))
    printf("Queue is empty.\n");
    else
    {
        int i;
        printf("Traversing queue: \n");
        for( i= (q->front+1)%max ; i!= q->rear ; i=(i+1)%max)
        {
            printf("%d ",q->items[i]);
        }
        printf("%d ",q->items[q->rear]); //remove this when removing c
    }
}
int main()
{
    struct cqueue cq1;
    cq1.rear= max -1;
    cq1.front = max-1;
    int choice,num;
    do
    {
    printf("\n\n\n1. Insert\n2. Delete\n3. Isempty\n4. Isfull\n5. Traverse\n6. Exit\n\nChoose an option: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: 
            enqueue(&cq1);
            break;
        case 2:
            printf("Dequeued elements is %d.\n",dequeue(&cq1));
            break;
        case 3:
            if(isempty(&cq1))
            printf("Queue is empty.\n");
            else
            printf("Queue is not empty.\n");
            break;
        case 4:
            if(isfull(&cq1))
            printf("Queue is full.\n");
            else
            printf("Queue is not full.\n");
            break;
        case 5:
            traverse(&cq1);
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice.\n");
    }
    } while(choice<7);
    return 0;
}









