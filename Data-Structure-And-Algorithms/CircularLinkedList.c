//CIRCULAR LINKED LIST
#include<stdio.h>
#include<stdlib.h>
struct Linked_Queue 
{
    int info;
    struct Linked_Queue *next;
};
typedef struct Linked_Queue Nodetype;
Nodetype *first=NULL;
Nodetype *last=NULL;


Nodetype *getnode()
{
    Nodetype *p;
    p = (Nodetype *)malloc(sizeof(Nodetype));
    return(p);
}

void insertatbeg(int new)
{
    Nodetype *newnode;
    newnode = getnode();
    newnode->info = new;
    if(first==NULL)
    {
        newnode->next=newnode;
        first=newnode;
        last = newnode;
    }
    else
    {
        newnode->next=first;
        first = newnode;
        last->next=newnode;
    }
}

void insertatend(int new)
{
    Nodetype *newnode, *temp;
    newnode = getnode();
    newnode->info = new;
    if(first == NULL)
    {first = newnode;
    last = newnode;
    newnode->next=newnode;}
    else
    {
        last->next = newnode;
        last=newnode;
        newnode->next = first;
    }
}

void insertatpos(int new)
{
    Nodetype *newnode, *temp;
    int pos, i;
    printf("Enter position of a node at which you want to insert a new node: ");
    scanf("%d",&pos);
    if(first == NULL)
    {
        printf("Void insertion.\n");
        exit(1);
    }
    else
    {
        temp = first;
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
    temp=first;
    if(first==NULL)
    {
        printf("Void deletion.\n");
    }
    else
    {
        first = first->next;
        printf("Deleted item is %d.\n",temp->info);
        last->next = first;
        free(temp);
    }
}

void deleteatend()
{
    Nodetype *temp;
    temp = last;
    if(last == NULL)
    {
        printf("Void deletion.\n");
        exit(1);
    }
    else
    {
        while(temp->next->next!=first)
        temp = temp->next;

        Nodetype *hold = temp->next;
        last = temp;
        last->next = first;
        printf("Deleted element:%d", hold->info);
        free(hold);

    }
}

void deleteatany()
{
    Nodetype *temp,*p;
    int pos, i;
    if(first == NULL)
    {
        printf("Empty list.\n");
        exit(1);
    }
    else
    {
        printf("Enter the position of a node you want to delete: ");
        scanf("%d",&pos);
        temp=first;
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
    int key,count=1,ok=0;
    if(first==NULL)
    {
        printf("Empty list.\n");
        exit(1);
    }
    else
    {
        printf("Enter searched item: ");
        scanf("%d",&key);
        temp = first;
        do
        {
            
            if(temp->info == key)
            {
                printf("Key found at position %d.\n",count);
                break;
                ok=1;
            }
            temp = temp->next;
            count++;
        }while(temp!=first);

        if (temp==first)
        printf("Key not found.\n");
    }
}

void countnodes()
{
    int cnt =0;
    Nodetype *temp;
    temp = first;
    printf("Elements in linked list: ");
    do
    {
        cnt++;
        printf("%d ",temp->info);
        temp = temp->next;
    }while(temp != first);
   
}
int main()
{
    int choice,num;
    printf("1. Insert at first\n2. Insert at end\n3. Insert at given position\n4. Delete at first\n5. Delete at end\n6. Delete at given position\n7. Search for key\n8. Traverse\n9. Exit()");
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
