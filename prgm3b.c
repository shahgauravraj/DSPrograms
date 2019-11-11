#include<stdio.h>
#include<stdlib.h>

struct Node
{
    char ch;
    struct Node* next;
};

typedef struct Node node;

node* start = NULL;

void insertatEnd(char x)
{
    node* temp = (node*)malloc(sizeof(node));

    if(start == NULL)
    {
        start = temp;
        start->ch = x;
        start->next = NULL;
        return;
    }

    node* p = (node*)malloc(sizeof(node));
    p = start;

    while(p->next != NULL)
        p = p->next;

    temp->ch = x;
    p->next = temp;
    temp->next = NULL;
}

void display(node* n)
{
    while (n != NULL)
    {
        printf("%c: %d\t", n->ch, n->ch);
        n = n->next;
    }
}

void arrange()
{
    node *p, *q;
    char temp;

    for(p=start; p!=NULL; p=p->next)
    {
        for(q=p->next; q!=NULL; q = q->next)
        {
            if(p->ch > q->ch)
            {
                temp = p->ch;
                p->ch = q->ch;
                q->ch = temp;
            }
        }
    }
    
}

int main()
{
    char a[] = "Gandhi";
    int i, len;

    for(len=0; a[len] != '\0'; len++);

    for(i=0; i<len; i++)
    {
        insertatEnd(a[i]);
    }
    printf("Before:\n");
    display(start);
    arrange();
    printf("\nPriority Queue:\n");
    display(start);
}