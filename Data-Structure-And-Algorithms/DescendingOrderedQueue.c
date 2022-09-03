//DESCENDING ORDERED QUEUE
#include <stdio.h>
#define MAXQUEUE 5
struct cqueue
{
    int items[MAXQUEUE];
    int front;
    int rear;
};
typedef struct cqueue q2;
int isEmpty(q2 *q)
{
        if (q->front == q->rear + 1)
        return 1;
        else
        return 0;
}
int isFull(q2 *q)
{
    if (q->rear == MAXQUEUE - 1)
    return 1;
    else
    return 0;
}
void makeEmpty(q2 *q)
{
    q->front = 0;
    q->rear = -1;
}
void traverse(q2 *q)
{
    if (isEmpty(q))
    printf("q1 is empty\n");
    else
    {
    printf("Traversing queue:");
    int i;
    for (i = q->front; i <= q->rear; i++)
    {
    printf(" %d", q->items[i]);
    }
    }
}
int findmax(q2 *q, int num)
{
    for(int i = q->front;i<= q->rear;i++)
    {
        if (num>q->items[i])
        return i;
    }
    return -1;
}
void enqueue(q2 *q)
{
    int num1;
    if (isFull(q))
    printf("Queue is full.\n");
    else if(q->front == 0 && q->rear == -1)
    {
        printf("Enter element to add:");
        scanf("%d", &num1);
        q->rear++;
        q->items[q->rear]=num1;
    }
    else
    {
        printf("Enter element to add:");
        scanf("%d", &num1);

        int max = findmax(q,num1);
        q->rear++;
        if(max == -1)
        {q->items[q->rear]=num1;
        return;}
        
        for(int i = q->rear;i>=max;i--)
        {
            q->items[i+1]=q->items[i];
        }
        q->items[max]=num1;
    }
}

int dequeue(q2 *q)
{
    if(isEmpty(q))
    printf("Queue is empty.\n");
    
    else
     printf("Element removed: %d", q->items[q->front++]);
    
}
int main()
{
    struct cqueue q1;
    q1.front = 0;
    q1.rear = -1;
    int choice, num;
    printf("\n\n1.Insert element\n2.Delete element\n3.Make queue empty\n4.Check if queue is empty\n5.Check if queue is full\n6.Traverse\n7.Exit");
    do
    {
    printf("\n\nEnter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        
        enqueue(&q1);
        break;
    case 2:
       dequeue(&q1);
        break;
    case 3:
        makeEmpty(&q1);
        printf("q1 is now empty\n");
        break;
    case 4:
        if (isEmpty(&q1))
        printf("q1 is empty");
        else
        printf("q1 is not empty");
        break;
    case 5:
        if (isFull(&q1))
        printf("q1 is full");
        else
        printf("q1 is not full");
        break;
    case 6:
        traverse(&q1);
        break;
    }
    } while (choice < 7);
    return 0;
}
