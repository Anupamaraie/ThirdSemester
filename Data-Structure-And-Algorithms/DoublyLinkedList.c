#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *prev;
    struct node *next;
};
typedef struct node Nodetype;
Nodetype *head = NULL;

Nodetype *getnode()
{
    Nodetype *p;
    p = (Nodetype *)malloc(sizeof(Nodetype));
    return (p);
}

void insertatbeg(int new)
{
    Nodetype *newnode;
    newnode = getnode();
    newnode->info = new;
    newnode -> prev=NULL;
    if(head==NULL)
    {
        newnode->next = NULL;
        head=newnode;
    }
    else
    {
    newnode ->next = head;
    head->prev = newnode;
    head=newnode;
    }
}

void insertatend(int new)
{
    Nodetype *newnode,*temp;
    newnode = getnode();
    newnode->info = new;
    newnode->next = NULL;
    if(head==NULL)
    {
        newnode->prev = NULL;
        head = newnode;
    }
    else
    {
        temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
    }
}

void deleteatbeg()
{
    Nodetype *hold;
    if(head==NULL)
    {
        printf("Empty list.\n");
    }
    else
    {
        hold = head;
        head->prev = NULL;
        head = head->next;
        printf("Deleted item is %d.\n",hold->info);
        free(hold);
    }
}

void deleteatend()
{
    Nodetype *newnode,*temp,*hold;
    newnode = getnode();
    if(head==NULL)
    {
        printf("Empty List.\n");
    }
    else if (head->next == NULL)
    {
        hold = head;
        printf("Deleted item is %d.\n",hold->info);
        head = NULL;
        free(hold);
    }
    else
    {
        temp = head;
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        hold = temp->next;
         printf("Deleted item is %d.\n",hold->info);
        temp->next = NULL;
        free(hold);
    }
}
void insertatany(int new)
{
    Nodetype *newnode,*temp;
    newnode = getnode();
    int pos,i;
    if (head==NULL)
    {
        printf("Void insertion.\n");
        exit(1);
    }
    else
    {
        temp = head;
        printf("Enter the position to add: ");
        scanf("%d",&pos);
        for(i=0;i<pos-1;i++)
        {
            temp = temp->next;
        }
        newnode->info = new;
        newnode->next = temp->next;
        temp->next = newnode;
    }
}
void deleteatany()
{
    Nodetype *temp,*p;
    int pos, i;
    if(head == NULL)
    {
        printf("Empty list.\n");
        exit(1);
    }
    else
    {
        printf("Enter the position of a node you want to delete: ");
        scanf("%d",&pos);
        temp=head;
        for(i=1;i<pos-1;i++)
        {
            temp = temp->next;
        }
        p = temp->next;
        printf("Deleted item is %d\n",p->info);
        temp->next = p->next;
        free(p);
    }
}

void Traverse()
{
    Nodetype *newnode;
    newnode  = head;
    printf("Elements in linked list: ");
    while (newnode != NULL)
    {
        printf("%d ", newnode->info);
        newnode = newnode->next;
    }
}

int main()
{
    int choice, num;
    printf("\n\n1. Insert at beginning\n2. Insert at end\n3. Insert at any position\n4. Delete at beginning\n5. Delete at end\n6. Delete at any position\n7. Traverse\n8. Exit");
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
                printf("Enter the number to add: ");
                scanf("%d",&num);
                insertatany(num);
                break;    
            case 4:
                deleteatbeg();
                break;
            case 5:
                deleteatend();
                break;
            case 6:
                deleteatany();
                break;
            case 7:
                Traverse();
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice!!!!");
                break;

        }
    } while (choice != 8);
    
}