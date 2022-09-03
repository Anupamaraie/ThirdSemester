//LINKED LIST
#include<stdio.h>
#include<stdlib.h>
struct Linked_Queue 
{
    int info;
    struct Linked_Queue *next;
};
typedef struct Linked_Queue Nodetype;
Nodetype *top;

Nodetype *getnode()
{
    Nodetype *p;
    p = (Nodetype *)malloc(sizeof(Nodetype));
    p->info = 10;
    p->next = NULL;
    return(p);
}

void createEmptyList(Nodetype *top)
{
    top = NULL;
}

void insertatbeg(int new)
{
    Nodetype *newnode;
    newnode = getnode();
    newnode->info = new;
    newnode->next = top;
    top = newnode;
}

void insertatend(int new)
{
    Nodetype *newnode, *temp;
    newnode = getnode();
    newnode->info = new;
    newnode->next = NULL;
    if(top == NULL)
    {top = newnode;}
    else
    {
        temp = top;
        while(temp->next != NULL)
        temp = temp->next;

        temp->next = newnode;
    }
}

void insertatgiv(Nodetype *p, int new)
{
    Nodetype *newnode;
    newnode = getnode();
    newnode->info = new;
    if(p == NULL)
    {
        printf("VOID INSERTION.\n");
        exit(0);
    }
    else
    {
        newnode->next = p->next;
        p->next = newnode;
    }
}
void insertatpos(int new)
{
    Nodetype *newnode, *temp;
    int pos, i;
    printf("Enter position of a node at which you want to insert a new node: ");
    scanf("%d",&pos);
    if(top == NULL)
    {
        printf("Void insertion.\n");
        exit(1);
    }
    else
    {
        temp = top;
        for(i=0;i<pos-1;i++)
        {
            temp = temp->next;
        }
        newnode = getnode();
        newnode->info = new;
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void deleteatbeg()
{
    Nodetype *temp;
    if(top==NULL)
    {
        printf("Void deletion.\n");
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

void deleteatend()
{
    Nodetype *temp;
    if(top == NULL)
    {
        printf("Void deletion.\n");
        exit(1);
    }
    else if (top->next == NULL)
    {
         temp=top;
         printf("Deleted item is %d.\n",top->info);
         top = NULL;
         free(temp);
    }
    else
    {
        temp = top;
        while(temp->next->next != NULL)
        temp = temp->next;

        free(temp->next);
        temp->next =NULL;
    }
}

void deleteatany()
{
    Nodetype *temp,*p;
    int pos, i;
    if(top == NULL)
    {
        printf("Empty list.\n");
        exit(1);
    }
    else
    {
        printf("Enter the position of a node you want to delete: ");
        scanf("%d",&pos);
        temp=top;
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

void searchItem()
{
    Nodetype *temp;
    int key;
    if(top==NULL)
    {
        printf("Empty list.\n");
        exit(1);
    }
    else
    {
        printf("Enter searched item: ");
        scanf("%d",&key);
        temp = top;
        while(temp!=NULL)
        {
            if(temp->info == key)
            {
                printf("Search successful.\n");
                break;
            }
            temp = temp->next;
        }
        if (temp == NULL)
            printf("Unsuccessful search.\n");
    }
}

void countnodes()
{
    int cnt =0;
    Nodetype *temp;
    temp = top;
    while(temp!= NULL)
    {
        cnt++;
        temp = temp->next;
    }
    printf("Total nodes = %d.\n",cnt);
}
int main()
{
    int choice,num;
    printf("1. Insert at first\n2. Insert at end\n3. Insert at given position\n4. Delete at first\n5. Delete at end\n6. Delete at given position\n7. Search for key\n8. Count nodes\n9. Exit()");
    do
    {
        printf("\n\nEnter your choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to insert: ");
            scanf("%d",&num);
            insertatbeg(num);
            break;
        case 2:
            printf("Enter the element to insert: ");
            scanf("%d",&num);
            insertatend(num);
            break;
        case 3:
            printf("Enter the element to insert: ");
            scanf("%d",&num);
            insertatpos(num);
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
            searchItem();
            break;
        case 8:
            countnodes();
            break;
        case 9:
            exit(1);
        
        default:
            printf("Invalid choice!!!");
            break;
        }
    } while (choice < 10);
    
}