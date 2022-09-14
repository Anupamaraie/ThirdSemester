#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *prev;
    struct node *next;
};
typedef struct node Nodetype;
Nodetype *first = NULL;
Nodetype *last = NULL;

Nodetype *getnode()
{
    Nodetype *p;
    p =(Nodetype *)malloc(sizeof(Nodetype));
    return (p);
}

void insertatbeg(int new)
{
    Nodetype *newnode, *temp;
    newnode = getnode();
    newnode->info = new;

    if(first==NULL)
    {
        first = newnode;
        last = newnode;
       newnode -> prev= newnode->next = newnode;;
    }
    else
    {
        newnode->next = first;
        first->prev = newnode;
        first = newnode;
        last->next = first;
        first->prev = last;
    }
}

void insertatend(int new)
{
    Nodetype *newnode,*temp;
    newnode = getnode();
    newnode->info = new;

    if(first==NULL)
    {
        first = newnode;
        last = newnode;
       newnode -> prev= newnode->next = newnode;;
    }
    else
    {
        last ->next = newnode;
        newnode->prev = last;
        last=newnode;
        last->next = first;
        first->prev = last;
    }
}

void deleteatbeg()
{
    Nodetype *hold;
    hold = first;
    if(first==NULL)
    {
        printf("Empty list.\n");
    }
    else if (first == last)
    {
        first = NULL;
        last = NULL;
        printf("Deleted item is %d.\n",hold->info);
        free(hold);
    }
    else
    {
       first = first->next;
       last->next =first;
       printf("Deleted item is %d.\n",hold->info);
       first ->prev = last;
        free(hold);
    }
}

void deleteatend()
{
    Nodetype *newnode,*temp;
    newnode = getnode();
    temp = first;
    if(last==NULL)
    {
        printf("Empty List.\n");
    }
    else if (first == last)
    {
        printf("Deleted item is %d.\n",temp->info);
        first = NULL;
        last = NULL;
        free(temp);
    }
    else
    {
        while(temp->next!= last)
        {
            temp = temp->next;
        }

        Nodetype *hold = temp->next;
        last = temp;
        last->next = first;
        printf("Deleted element:%d", hold->info);
        first->prev = last;
        free(hold);
    }
}

void Traverse()
{
    Nodetype *temp;
    temp = first;
    if(first == NULL)
    {
        printf("Empty list.\n");
    }
    else
    {
        printf("Elements in linked list: ");
        do
        {
            printf("%d ", temp->info);
            temp = temp->next;
        }while (temp != first);
    }
}

int main()
{
    int choice, num;
    printf("\n\n1. Insert at beginning\n2. Insert at end\n3. Delete at beginning\n4. Delete at end\n5. Traverse\n6. Exit");
    do
    {
        printf("\n\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter the number to add: ");
                scanf("%d",&num);
                insertatbeg(num);
                break;
            case 2:
                printf("Enter the number to add: ");
                scanf("%d",&num);
                insertatend(num);
                break;  
            case 3:
                deleteatbeg();
                break;
            case 4:
                deleteatend();
                break;
            case 5:
                Traverse();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice!!!!");
                break;

        }
    } while (choice != 6);
    
}