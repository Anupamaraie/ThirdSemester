//LINKED LIST AS STACK
#include<stdio.h>
#include<stdlib.h>
struct Linked_Stack 
{
    int info;
    struct Linked_Stack *next;
};
typedef struct Linked_Stack Nodetype;
Nodetype *top;

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
    if(top==0)
    {
        newnode->info=new;
        newnode->next=NULL;
        top=newnode;
    }
    else
    {
        newnode->info=new;
        newnode->next=top;
        top=newnode;
    }
}

void pop()
{
    Nodetype *temp;
    if(top==0)
    {
        printf("Stack is empty.\n");
        exit(1);
    }
    else
    {
        temp = top;
        printf("Deleted item is %d.\n",top->info);
        top = top->next;
        free(temp);
    }
}

void topel()
{
    Nodetype *temp;
    if(top==NULL)
    {
        printf("Empty stack.");
        exit(1);
    }
    else
    {
        temp=top;
        printf("Topmost element is %d.\n",temp->info);
    }
}

void display()
{
    Nodetype *temp;
    if(top==NULL)
    {
        printf("Empty stack.");
        exit(1);
    }
    else
    {
        temp=top;
        printf("Stack elements are: ");
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
    printf("1. Push element\n2. Pop element\n3. Check topmost element.\n4. Display\n5. Exit");
    do
    {
        printf("\n\nEnter your choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
                printf("Enter the number to push: ");
                scanf("%d",&choice);
                push(choice);
                break;
            case 2:
                pop();
                break;
            case 3:
                topel();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
            printf("Invalid....");
                break;
            }
    } while (choice!=5);
    return 0;
}