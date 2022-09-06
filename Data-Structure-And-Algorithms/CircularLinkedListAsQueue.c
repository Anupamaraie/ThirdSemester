// CIRCULAR LINKED LIST AS QUEUE

#include <stdio.h>
#include <stdlib.h>
struct Linked_Queue
{
    int info;
    struct Linked_Queue *next;
};
typedef struct Linked_Queue Nodetype;
Nodetype *pq = NULL;

Nodetype *getnode()
{
    Nodetype *p;
    p = (Nodetype *)malloc(sizeof(Nodetype));
    return (p);
}

void enqueue(int new)
{
    Nodetype *newnode;
    newnode = getnode();
    newnode->info = new;
    if (pq == NULL)
    {
        pq = newnode;
        pq->next = pq;
    }
    else
    {
        newnode->next = pq->next;
        pq->next = newnode;
        pq = newnode;
    }
}

void dequeue()
{
    Nodetype *temp;
    if (pq == NULL)
    {
        printf("Queue Empty.\n");
    }
    else if (pq->next == pq) //only for one node
    {
        printf("Dequeued element is %d.\n",pq->info);
        pq = NULL;
    }
    else
    {
        temp = pq->next;
        pq->next = temp->next;
        printf("Dequeued element is %d.\n", temp->info);
        free(temp);
    }
}

int main()
{
    int choice, num;
    printf("1.Enqueue\n2.Dequeue\n3.Exit");
    do
    {
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to enqueue: ");
            scanf("%d", &num);
            enqueue(num);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            exit(1);

        default:
            printf("Invalid choice!!!");
            break;
        }
    } while (choice < 4);
}
