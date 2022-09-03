//Evaluation of prefix exp

#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<string.h>
#define max 100
char vQueue[max];
char fix[max],prefix[max];
int op1,op2;
int top = -1;
int push(char c)
{
    if(top == max-1)
        printf("Queue is full.\n");
    else
        vQueue[++top] = c;
}
int pop()
{
    if(top == -1)
    printf("Queue is empty.\n");
    else
    return (vQueue[top--]) ;
}
int intopost()
{
    int i,j,symbol;
    for(i=strlen(prefix)-1;i>=0;i--)
    {
        symbol = prefix[i];
        if (isdigit(symbol))
        push(symbol-'0');
        else
        {
            op1 = pop();
            op2 = pop();
             char ch = symbol;
            if (ch == '+')
                push(op1+op2);
            else if (ch == '-')
                push(op1-op2);
            else if (ch == '*')
                push(op1*op2);
            else if (ch == '/')
                push(op1/op2);
            else if (ch == '^')
                push(pow(op1,op2));
        }
    }
    printf("\nThe result after evaluation of given prefix expression is %d\n\n\n",vQueue[top]);
}
int main()
{
    printf("\n\n\nEnter the prefix operation: ");
    gets(prefix);
    intopost();
}

