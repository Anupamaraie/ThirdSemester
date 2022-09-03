//Ascending Unordered Queue
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
    return 0; 
} 
int isFull(q2 *q) 
{ 
    if (q->rear == MAXQUEUE - 1) 
    return 1; 
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
    printf("Queue is empty\n"); 
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
void enqueue(q2 *q, int item) 
{ 
    if (!isFull(q)) 
    q->items[++q->rear] = item; 
    else
    printf("Queue is Full.\n"); 
} 
int dequeue(q2 *q) 
{ 
    int i, temp = 0, x; 
    x = q->items[q->front]; 
    if (!isEmpty(q)) 
    { 
    for (i = q->front; i <= q->rear; i++) 
    { 
        if (x > q->items[i]) 
        { 
            temp = i; 
            x = q->items[i]; 
        } 
    } 
    for (i = temp; i <= q->rear; i++) 
    { 
            q->items[i] = q->items[i++]; 
    } 
        q->rear--; 
        return x; 
    } 
    else
        printf("Queue is empty\n"); 
    return 0; 
} 
int main() 
{ 
    struct cqueue q1; 
    q1.front = 0; 
    q1.rear = -1; 
    int choice, num; 
    do
    { 
        printf("\n\n1.Insert element\n2.Delete element\n3.Make queue empty\n4.Check if queue is empty\n5.Check if queue is full\n6.Traverse\n7.Exit\n\n Your Choice: "); 
        scanf("%d", &choice); 
        switch (choice) 
        { 
        case 1: 
            printf("Enter element to add:"); 
            scanf("%d", &num); 
            enqueue(&q1, num); 
            break; 
        case 2: 
            printf("Element removed:%d", dequeue(&q1)); 
            break; 
        case 3: 
            makeEmpty(&q1); 
            printf("Queue is now empty\n"); 
            break; 
        case 4: 
            if (isEmpty(&q1)) 
                printf("Queue is empty"); 
            else
                printf("Queue is not empty"); 
            break; 
        case 5: 
            if (isFull(&q1)) 
                printf("Queue is full"); 
            else
                printf("Queue is not full"); 
            break; 
        case 6: 
            traverse(&q1); 
            break; 
        default:
            printf("Invalid Choice!!");
            break;
    } 
    } while (choice < 7); 
    return 0; 
}