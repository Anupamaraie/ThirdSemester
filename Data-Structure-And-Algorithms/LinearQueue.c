//Linear Queue
#include<stdio.h>
#include<stdlib.h>
#define max 3
struct queue
{ 
    char items[max]; 
    int front; 
    int rear; 
}; 
typedef struct queue q1; 
int isfull(q1 *q) 
{ 
    if (q->rear==max-1) 
    return 1; 
    else
    return 0; 
} 
int isempty(q1 *q) 
{ 
    if(q->rear<q->front) 
    return 1; 
    else
    return 0; 
} 
int enqueue(q1 *q) 
{ 
    if(isfull(q)) 
        printf("Queue is full. Max size reached.\n"); 
    else
    { 
        int num; 
        printf("Enter the number to enqueue: "); 
        scanf("%d",&num); 
        q->items[++q->rear]=num; 
        printf("Enqueued element is %d\n",num); 
    } 
 
} 
int dequeue(q1 *q) 
{ 
    if(isempty(q)) 
        printf("Queue is empty.No data left.\n"); 
    else
        printf("Dequeued element is %d",q->items[q->front++]); 
} 
int traverse(q1 *q) 
{ 
    if(isempty(q)) 
        printf("Queue is empty.\n"); 
    else 
    { 
        printf("Elements in queue:\n"); 
        int i; 
        for(i=q->front;i<=q->rear;i++) 
        printf("%d ",q->items[i]); 
    } 
} 
int main() 
{ 
    int num,n; 
    struct queue q2; 
    q2.rear=-1; 
    q2.front = 0; 
    do
    { 
        printf("\n\n\nChoose your operation:\n1.Enqueue\n2.Dequeue\n3.Traverse\n4.Check if empty\n5.Check if full\n6.Exit\n\nYour option: "); 
        scanf("%d",&n); 
        switch(n) 
        { 
            case 1: 
                enqueue(&q2); 
                break; 
            case 2: 
                dequeue(&q2); 
                break; 
            case 3: 
                traverse(&q2); 
                break; 
            case 4: 
                if(isempty(&q2)) 
                    printf("Queue is empty. No data left\n"); 
                else
                    (printf("Queue is not empty.\n")); 
                break; 
            case 5: 
                if(isfull(&q2)) 
                    printf("Queue is full. Max size reached.\n"); 
                else
                    (printf("Queue is not full.\n")); 
                break; 
            case 6: 
                exit(0); 
            default: 
                printf("Invalid choice.\n"); 
                break; 
        }
    }while(n<7);
}