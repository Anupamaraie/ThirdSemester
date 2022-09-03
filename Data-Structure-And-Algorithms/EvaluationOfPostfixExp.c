//Evaluation of postfix exp

#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<string.h>
#define max 100
char vQueue[max];
char postfix[max];
int op1,op2;
int top = -1;
int push(char c)
{
    if(top == max-1)
        printf("q1 is full.\n");
    else
        vQueue[++top] = c;
}
int pop()
{
    if(top == -1)
    printf("q1 is empty.\n");
    else
    return (vQueue[top--]) ;
}
int intopost()
{
    int i,j,symbol;
    for(i=0;i<strlen(postfix);i++)
    {
        symbol = postfix[i];
        if (isdigit(symbol))
        push(symbol-'0');
        else
        {
            op1 = pop();
            op2 = pop();
             char ch = symbol;
            if (ch == '+')
                push(op2+op1);
            else if (ch == '-')
                push(op2-op1);
            else if (ch == '*')
                push(op2*op1);
            else if (ch == '/')
                push(op2/op1);
            else if (ch == '^')
                push(pow(op2,op1));
        }
    }
    printf("\nThe result after evaluation of given postfix expression is %d\n\n\n",vQueue[top]);
}
int main()
{
    printf("\n\n\nEnter the postfix operation: ");
    gets(postfix);
    intopost();
}