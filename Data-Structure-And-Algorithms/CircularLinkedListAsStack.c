//CIRCULAR LINKED LIST AS STACK

#include<stdio.h>
#include<stdlib.h>
struct Linked_stack 
{
    int info;
    struct Linked_stack *next;
};
typedef struct Linked_stack Nodetype;
Nodetype *last=NULL;

Nodetype *getnode()
{
    Nodetype *p;
    p = (Nodetype *)malloc(sizeof(Nodetype));
    return(p);
}

void push(int new)
{
    Nodetype *newnode;
    newnode = getnode();
    newnode->info = new;
    if(last==NULL)
    {
        last=newnode;
        last->next=last;
    }
    else
    {
        newnode->next=last->next;
        last->next = newnode;
    }
}

void pop()
{
    Nodetype *temp;
    if(last==NULL)
    {
        printf("Stack empty.\n");
    }
    else if (last->next==last) //for only one node
    {
        printf("Popped element is %d.\n",last->info);
        last = NULL;
    }
    else
    {
        temp=last->next;
        last->next = temp->next;
        printf("Deleted item is %d.\n",temp->info);
        free(temp);
    }
}

void traverse()
{
    int cnt =0;
    Nodetype *temp;
    temp = last;
    if(last == NULL)
    {
        printf("Stack Empty.\n");
    }
    else
    {
        printf("Elements in linked list: ");
        do
        {
            cnt++;
            printf("%d ",temp->info);
            temp = temp->next;
        }while(temp != last);
    }
}
int main()
{
    int choice,num;
    printf("1. Push\n2. Pop\n3. Display\n4. Exit");
    do
    {
        printf("\n\nEnter your choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to push: ");
            scanf("%d",&num);
            push(num);
            break;
        case 2:
            pop();
            break;
        case 3:
            traverse();
            break;
        case 4:
            exit(0);
            break;

        default:
            printf("Invalid choice!!!");
            break;
        }
    } while (choice < 5);
}
