#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* start = NULL;

void insertatEnd(int x);
void display(struct Node* n);

int main()
{
    int i;
    int a[10] = {1,2,3,4,5,6,7,8,9,0};

    for(i=0; i<10; i+=2)
    {
        insertatEnd(a[i]);
    }

    for(i=1; i<10; i+=2)
    {
        insertatEnd(a[i]);
    }

    display(start);
    return 0;
}

void insertatEnd(int x)
{
    struct Node* temp;
    temp = (struct Node*)malloc(sizeof(struct Node));

    if(start == NULL)
    {
        start = temp;
        start->data = x;
        start->next = NULL;
        start->prev = NULL;
        return;
    }

    struct Node* p;
    p = (struct Node*)malloc(sizeof(struct Node));

    p = start;
    while(p->next != NULL)
    {
        p = p->next;
    }
    temp->data = x;
    p->next = temp;
    temp->prev = p;
    temp->next = NULL;
}

void display(struct Node* n)
{
    printf("\n---------------------------------------------------------------------------------------------------\n");
    if (n == NULL)
        printf("List Empty!\n");

    else
    {
        while(n != NULL)
        {
            printf("%d\t", n->data);
            n = n->next;
        }
    }
    printf("\n---------------------------------------------------------------------------------------------------\n");
}