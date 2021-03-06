#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

typedef struct Node node;

node* start = NULL;

void insertatEnd(int new);
void deletefromEnd();
void display(node* n);
int length(node* n);

int main()
{
    int new = 1;
    int ch;
    int loop = 1;

    do
    {
        printf("\n**********WELCOME TO NITTE BAKERY**********");
        printf("\n1. Place a BUN(for bakery's assistant)");
        printf("\n2. Grab a BUN(for customers)");
        printf("\n3. Show BUNS");
        printf("\n4. Exit Shop");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1: insertatEnd(new);
                    new++;
                    break;

            case 2: printf("\nHottest BUN Picked!\n");
                    deletefromEnd();
                    new--;
                    break;

            case 3: display(start);
                    printf("Length = %d\n", length(start));
                    break;

            case 4: printf("\nThank You for visiting!\nSee you again soon");
                    printf("\n*******************************************\n");
                    loop = 0;
                    break;

            default: printf("\nPlease Enter a valid Choice!");
        }
    } while (loop);
}

void insertatEnd(int new)
{
    node* temp;
    temp = (node*)malloc(sizeof(node));

    if(start == NULL)
    {
        start = temp;
        start->data = new;
        start->next = start;
        return;
    }

    node* p = (node*)malloc(sizeof(node));
    p = start;
    while(p->next != start)
        p = p->next;

    p->next = temp;
    temp->data = new;
    temp->next = start;
}

void deletefromEnd()
{
    int loc = length(start);
    int i = 1;

    node* p;
    p = start;
    node* q;

    while(i < (loc-1))
    {
        p = p->next;
        i++;
    }
    q = p->next;
    p->next = q->next;
    q->next = start;
    free(q);

}

void display(node* n)
{
    printf("\n-----------------------------------------------------------------------------------------------------\n");

    if(n == NULL)
        printf("\nNo BUN at the moment!\n");

    else
    {
        while (n->next != start)
        {
            printf("%d\t", n->data);
            n = n->next;
        }
    printf("%d\t", n->data);
    }
    printf("\n-----------------------------------------------------------------------------------------------------\n");
    return;
}

int length(node* n)
{
    int count = 1;

    if(n == NULL)
        return 0;

    while (n->next != start)
    {
        count++;
        n = n->next;
    }
    return count;
}