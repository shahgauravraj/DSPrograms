#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* start = NULL;

void insertatbegin(int x);
void insertatEnd(int x);
void insertAfter(int loc, int x);
void display(struct Node* n);
int length(struct Node* n);


int main()
{
    int x, loc;
    int loop = 1;
    int ch;

    do {
        printf("\n**********OPERATIONS**********\n");
        printf("1. Insert at begin\n2. Insert at End\n3. Insert After Location\n4. Display\n5. Reverse List\n6. Tell Length\n7. Delete\n8. Exit\nEnter your Choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1: printf("Enter the number: ");
                    scanf("%d", &x);
                    insertatbegin(x);
                    break;

            case 2: printf("Enter the number: ");
                    scanf("%d", &x);
                    insertatEnd(x);
                    break;

            case 3: printf("Enter the location after which you want to add a node: ");
                    scanf("%d", &loc);
                    printf("Enter the number: ");
                    scanf("%d", &x);
                    insertAfter(loc, x);
                    break;

            case 4: display(start);
                    break;

            case 6: printf("Total Number of Elements in the list = %d\n", length(start));
                    break;

            case 8: printf("Program Terminated Successfully!\n");
                    loop = 0;
                    break;

            default: printf("\nPlease Enter a valid Option!\n");
        }
    } while(loop);
    return 0;
}


void insertatbegin(int x)
{
    struct Node* temp;
    temp = (struct Node*)malloc(sizeof(struct Node));

    if(start == NULL)
    {
        temp->prev = NULL;
        temp->next = NULL;
        temp->data = x;
        start = temp;
        return;
    }
    temp->data = x;
    temp->prev = NULL;
    temp->next = start;
    start->prev = temp;
    start = temp;
}

void insertAfter(int loc, int x)
{
    struct Node* temp, *p;
    int len, i = 1;
    len = length(start);

    if(loc > len)
    {
        printf("Invalid Location index!\n");
        printf("List currently has %d nodes only\n", length(start));
    }

    else
    {
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = x;
        temp->next = NULL;
        temp->prev = NULL;

        p = start;
        while(i < loc)
        {
            p = p->next;
            i++;
        }
        temp->next = p->next;
        p->next->prev = temp;
        temp->prev = p;
        p->next = temp;
    }
    
}

void insertatEnd(int x)
{
    struct Node* temp;
    temp = (struct Node*)malloc(sizeof(struct Node));

    if(start == NULL)
    {
        start = temp;
        start->data = x;
        start->prev = NULL;
        start->next = NULL;
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
    printf("\n-----------------------------------------------------------------------------------------------------\n");
    if(n == NULL)
        printf("List Empty!!");

    else {
        while(n != NULL)
        {
        printf("%d\t", n->data);
        n = n->next;
        }
    }
    
    printf("\n-----------------------------------------------------------------------------------------------------\n");
}

int length(struct Node* n)
{
    int count = 0;
    while(n != NULL)
    {
        n = n->next;
        count++;
    }
    return count;
}