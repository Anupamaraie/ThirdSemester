//LINKED LIST AS QUEUE
#include<stdio.h>
#include<stdlib.h>
struct Linked_Queue 
{
    int info;
    struct Linked_Queue *next;
};
typedef struct Linked_Queue Nodetype;
Nodetype *rear=0, *front=0;

Nodetype *getnode()
{
    Nodetype *p;
    p = (Nodetype *)malloc(sizeof(Nodetype));
    return(p);
}

void enqueue()
{
    Nodetype *newnode;
    newnode = getnode();
    int new;
    if(rear==0)
    {
        printf("Enter the element to enqueue: ");
        scanf("%d",&new);
            newnode->info = new;
            newnode->next = NULL;
            rear=newnode;
            front=newnode;
    }
    else
        {
        printf("Enter the element to enqueue: ");
        scanf("%d",&new);
            newnode->info = new;
            newnode->next = NULL;
            rear->next = newnode;
            rear=newnode;
        }
}


void dequeue()
{
    Nodetype *temp;
    if(front == 0)
    {
        printf("Queue empty.\n");
        return;
    }
    else if (front->next == NULL)
    {
         temp=front;
         rear=NULL;
         front = NULL;
         printf("Deleted item is %d.\n",temp->info);
         free(temp);
    }
    else
    {
        temp = front;
        printf("Deleted item is %d.\n",temp->info);
        front = front->next;
         free(temp);
    }
}

void traverse()
{
    Nodetype *temp;
    if(front==0)
    {
        printf("Queue is empty.\n");
        exit(0);
    }
    else
    {
        printf("Queue elements are: ");
        temp=front;
        while(temp!=NULL)
        {
            printf("%d ",temp->info);
            temp=temp->next;
        }

    }
}

int main()
{
    int choice,num;
    printf("\n\n\nChoose your operation:\n1.Enqueue\n2.Dequeue\n3.Traverse\n4.Exit");
    do
    {
        printf("\n\nYour option: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            traverse();
            break;
        case 4:
            exit(0);
        default:
        printf("Invalid choice.\n");
            break;
        }
    } while(choice!=6);
}
