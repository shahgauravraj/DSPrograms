#include<stdio.h>
#define size 10
int que[size];
int front = 0;
int rear = -1;

int Qfull(void)
{                     /* Function to Check Queue Full */
    if(rear==size-1) return 1;
    return 0;
}

int Qempty(void)
{                    /* Function to Check Queue Empty */
    if(front > rear) return 1;
    return 0;
}

void pqinsert(int x)
{
    int i;
    if(Qfull()) printf("Queue Overflow!\n");

    else
    {
        i = rear;
        ++rear;

        while(i >= 0)
        {
            if((x%2)==0)
            {
                que[i+1] = que[i];
                i--;
            }
            else break;
        }
        que[i+1] = x;
    } 
}

void display()
{
    int i;

    if(Qempty()) printf("Queue Underflow!\n");

    printf("Front ->\t");
    for(i=front;i<=rear;i++)
        printf("%d\t", que[i]);
    printf("<- Rear");
}

int main()
{
    int a[10] = {1,6,2,7,3,9,5,4,8,10};
    int i;

    for(i=0;i<10;i++)
    {
        pqinsert(a[i]);
    }
    display();
}