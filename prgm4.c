#include<stdio.h>
#include<stdlib.h>

struct Node
{
    char ch;
    struct Node* next;
};

typedef struct Node node;

node* start = NULL;

void insertatEnd(char x);
void arrange();
void display(node* n);

int main()
{
    char ch;

    for(ch='a'; ch<='e'; ch++)
    {
        insertatEnd(ch);
    }

    for(ch='A'; ch<='E'; ch++)
    {
        insertatEnd(ch);
    }

    printf("Given Arrangement is: \n");
    display(start);
    arrange(start);
    printf("\nResult Arrangement is: \n");
    display(start);
}

void insertatEnd(char x)
{
    node* temp;
    temp = (node*)malloc(sizeof(node));

    if(start == NULL)
    {
        start = temp;
        start->ch = x;
        start->next = start;
        return;
    }

    node* p = (node*)malloc(sizeof(node));
    p = start;
    while(p->next != start)
        p = p->next;

    p->next = temp;
    temp->ch = x;
    temp->next = start;
}

void arrange()
{
    node* temp1 = start;
    node* temp2 = start;

    while(temp2->ch != 'A')
        temp2 = temp2->next;

    char t;

    do
    {
        t = temp1->ch;
        temp1->ch = temp2->ch;
        temp2->ch = t;

        temp1 = temp1->next->next;
        temp2 = temp2->next->next;
    } while (temp2->ch < 'a');
}

void display(node* n)
{
    while (n->next != start)
    {
        printf("%c\t", n->ch);
        n = n->next;
    }
    printf("%c\t", n->ch);
}
