//Array Implemenetation of Stack
#include<stdio.h>
#include<stdlib.h>
#define max 10
struct stack
{ 
 int items[max]; 
 int top; 
}; 
typedef struct stack st; 
int isfull(st *s) 
{ 
    if(s->top ==max-1) 
    return 1; 
    else
    return 0; 
} 
int isempty(st *s) 
{ 
    if (s-> top == -1) 
    return 1; 
    else
    return 0; 
} 
void makeempty(st *s) 
{ s-> top = -1;} 
int top(st *s) 
{return s->items[s->top];} 
void push(st *s, int element) 
{ 
    if(isfull(s)) 
    printf("Stack is full.\n"); 
    else{ 
    s->items[++s->top]=element; 
    } 
} 
void pop(st *s) 
{ 
    if (isempty(s)) 
    printf("Stack is empty.\n"); 
    else
    printf("Deleted items is %d.\n",s->items[s->top--]); 
} 
int main() 
{ 
    int choice, num; 
    struct stack st1; 
    st1.top = -1; 
    printf("\n\n1.Push element\n2.Pop element\n3.Check topmost element\n4.Exit"); 
    do
    { 
        printf("\n\nYour Choice: ");
        scanf("%d", &choice); 
        switch(choice) 
        { 
            case 1: 
                printf("Enter element you would like to push: "); 
                scanf("%d", &num); 
                push(&st1, num); 
                break; 
            case 2: 
                pop(&st1); 
                break; 
            case 3: 
                printf("Topmost element is : %d", top(&st1)); 
                break; 
            case 4: 
                exit(0); 
            default:
                printf("Invalid choice!!!");
                break;
        } 
    } while (choice < 5); 
}