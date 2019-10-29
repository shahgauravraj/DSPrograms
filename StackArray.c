// C Program to perform stack implementation

#include<stdio.h>

int isFull();
int isEmpty();
void push(int );
void pop();
void peek();

struct stackk
{
    int stk[10];
    int top;
} s;

void main()
{
    s.top = -1;
    int ch;
    int loop = 1;
    int new;
    int i;
    
    do
    {
        printf("\n ***STACK OPERATIONS");
        printf("\n 1. PUSH");
        printf("\n 2. POP");
        printf("\n 3. PEEK");
        printf("\n 4. DISPLAY");
        printf("\n 5. EXIT");
        printf("\n ***************");
        printf("\n Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1: 
                printf("Enter item to be pushed: ");
                scanf("%d", &new);
                push(new);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                for(i=s.top;i>-1;i--)
                    {
                        printf("%d\n", s.stk[i]);
                    }
                loop = 0;
                break;
            case 5:
                printf("Termination Successful!\n");
                loop = 0;
                break;
            default:
                printf("Invalid choice\n");
        }
    } while(loop);
    
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

void push(int new)
{
    if(isFull()) printf("Stack Overflow!\n");
    else {
        s.top ++;
        s.stk[s.top] = new;
    }
}

void pop()
{
    if(isEmpty()) printf("Stack Underflow!\n");
    else {
        printf("Item popped is: %d\n", s.stk[s.top]);
        s.top --;
    }
}

void peek()
{
    printf("%d is on top of the stack.\n", s.stk[s.top]);
}