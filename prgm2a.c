#include<stdio.h>

struct stack
{
    int stk[20];
    int top;
} s;

int isEmpty();
int isFull();
void push(int x);
void display();

void main()
{
    s.top= -1;  //Initializing(Creating) the stack

    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    int i;

    for(i=0; i<10; i+=2)
    {
        push(a[i]);
    }

    for(i=1; i<10; i+=2)
    {
        push(a[i]);
    }

    display();
}

int isFull()
{
    if(s.top >= 9) return 1;
    else return 0;
}

int isEmpty()
{
    if(s.top <= -1) return 1;
    else return 0;
}

void push(int x)
{
    if(isFull())
        printf("Stack Overflow!\n");

    else
    {
        s.top ++;
        s.stk[s.top] = x;
    }
}

void display()
{
    if(isEmpty())
        printf("Stack is Empty!\n");

    else
    {
        int i;

        for(i=0; i<= s.top; i++)
        {
            printf("%d\t", s.stk[i]);
        }
        printf("\n");
    }
}