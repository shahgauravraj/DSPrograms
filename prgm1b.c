#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* start = NULL;

void insertatBeginning(int X);
void insertatEnd(int x);
void display(struct Node* n);

void main()
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int i;
    
    for(i=0;i<10;i++)
    {
        if((a[i] % 2) == 0)
        {
            insertatBeginning(a[i]);
        }
        else
        {
            insertatEnd(a[i]);
        }
    }
    display(start);
}

void insertatBeginning(int x) 
{
   struct Node *t;
   
   t = (struct Node*)malloc(sizeof(struct Node));
     
   if (start == NULL) {
      start = t;
      start->data = x;
      start->next = NULL;
      return;
   }
   
   t->data = x;
   t->next = start;
   start = t;
}

void display(struct Node* n)
{
    while(n != NULL)
    {
        printf("%d\t", n->data);
        n = n->next;
    }
}

void insertatEnd(int x) {
   struct Node *t, *p;
   
   t = (struct Node*)malloc(sizeof(struct Node));
   
   if (start == NULL) {
      start = t;
      start->data = x;
      start->next = NULL;
      return;
   }
   p = start;
   
   while (p->next != NULL)
      p = p->next;  
   
   p->next = t;
   t->data    = x;
   t->next    = NULL;
}