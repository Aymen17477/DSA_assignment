//Balanced Parentheses
#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top=-1;            // stack top index

void push(char x)
{
    if(top==MAX-1)     // check overflow
        return;

    stack[++top]=x;    
}

char pop()
{
    if(top==-1)        // check underflow
        return '\0';

    return stack[top--];  
}

int isBalanced(char expr[])
{
    int i=0;

    while (expr[i]!='\0')   // traverse string
    {
        if (expr[i]=='(')
        {
            push(expr[i]);  // push opening bracket
        }
        else if (expr[i]==')')
        {
            if (top==-1)    
                return 0;

            char topChar=pop();

            if (topChar!='(')  // mismatch check
                return 0;
        }

        i++;
    }

    return (top==-1);   // stack empty = balanced
}

int main()
{
    char expr[MAX];

    printf("Enter Expression: ");
    scanf("%s", expr);   

    top=-1;                // reset stack

    if (isBalanced(expr))
        printf("Balanced Expression\n");
    else
        printf("Unbalanced Expression\n");

    return 0;
}