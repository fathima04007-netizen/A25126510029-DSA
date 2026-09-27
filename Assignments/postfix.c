#include <stdio.h>
#include <ctype.h>
char stack[100];
int top=-1;
void push(char x)
{
    stack[++top]=x;
}
char pop()
{
    return stack[top--];
}
int priority(char x)
{
    if(x=='+' || x=='-')
        return 1;
    if(x=='*' || x=='/' || x=='%')
        return 2;
    if(x=='^')
        return 3;
    return 0;
}
int main()
{
    char exp[100],ch;
    int i;
    printf("Enter expression: ");
    scanf("%s",exp);
    for(i=0;exp[i]!='\0';i++)
    {
        ch=exp[i];
        if(isalnum(ch))
        {
            printf("%c",ch);
        }
        else if(ch=='(')
        {
            push(ch);
        }
        else if(ch==')')
        {
            while(stack[top]!='(')
                printf("%c",pop());
            pop();
        }
        else
        {
            while(top!=-1 && priority(stack[top])>=priority(ch))
                printf("%c",pop());
            push(ch);
        }
    }
    while(top!=-1)
        printf("%c",pop());
    return 0;
}