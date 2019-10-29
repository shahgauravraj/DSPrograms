#include<stdio.h>

char stack[50];
int top = -1;

void push(char ch)
{
    stack[++top] = ch;
}

char pop()
{
    if (top == -1)
        return -1;
    else
        return stack[top--];    
}

int prec(char ch)
{
    switch(ch)
    {
        case '$':
        case '^': return 3;
                    break;
        case '*': return 2;
                    break;
    }
}