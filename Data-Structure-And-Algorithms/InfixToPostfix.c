//POSTFIX

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max 100
char infix[max], postfix[max],q1[max];
int top = -1;
int push(int sym)
{
    if (top == max-1)
    {printf("q1 is full.\n");}
    else
    q1[++top] = sym;
}
int isempty()
{
    if (top == -1)
    return 1;
    else
    return 0;
}
char pop()
{

    if(top == -1)
    printf("q1 is empty.\n");
    else
    return q1[top--];
    
}

int precedence(char c)
{
    switch(c)
    {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}

int space(char ch)
{
    if (ch == ' ' || ch == '\t')
    return 1;
    else
    return 0;
}
void intopost()
{
    int i,j=0;
    char sym,next;
    for(i=0;i<strlen(infix);i++)
    {
        sym = infix[i];
        if (!space(sym))
        {
        switch(sym)
        {
            case '(':
                push(sym);
                break;
            case ')':
            while((next = pop()) !='(')
                postfix[j++]=next;
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                while(!isempty() && precedence(q1[top]) >= precedence(sym))
                    postfix[j++]= pop();
                    push(sym);
                    break;
            default:
            postfix[j++]=sym;
        }
        }
    }
    while (!isempty())
        postfix[j++] = pop();
    postfix[j]='\0';
}
void print()
{
    int i=0;
    printf("\n\nThe postfix expression is:");
    printf("%s",postfix);
}

int main()
{
    printf("\n\nEnter an infix expression: ");
    gets(infix);
    intopost();
    print();
    return 0;
}
