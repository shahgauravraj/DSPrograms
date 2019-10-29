#include<stdio.h>

struct stack{
    int stk[10];
    int top;
} s;

int isFull(void)
{
    if(s.top >= 9) return 1;
    else return 0;
}

void push(int new)
{
    if(isFull()) 
        printf("Stack Overflow!\n");

    else {
        s.top++;
        s.stk[s.top] = new;
    }
}

void display(void)
{
    int i;
    for(i=9;i>-1;i--)
    {
        printf("%d\t", s.stk[i]);
    }
    printf("\n");
}

int main()
{
    //struct stack s;
    s.top = -1;

    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int i;

    for(i=0;i<10;i++)
    {
        if((a[i] % 2) != 0){
            push(a[i]);
        }
    }

    for(i=0;i<10;i++)
    {
        if((a[i] % 2) == 0){
            push(a[i]);
        }
    }

    display();

    return 0;
}