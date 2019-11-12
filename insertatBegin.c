#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

typedef struct Node node;

node* start = NULL;

void insertatBegin(int new)
{
    node* temp;
    temp = (node*)malloc(sizeof(node));

    if(start == NULL)
    {
        start = temp;
        start->data = new;
        start->next = NULL;
        return;
    }

    temp->data = new;
    temp->next = start;
    start = temp;
}

int length(node* n)
{
    int count = 0;
    while(n != NULL)
    {
        count++;
        n = n->next;
    }
    return count;
}

void insertAfter(int loc, int new)
{
    int i = 1, len;
    node* temp;
    node* p;
    len = length(start);
    if(loc > len)
    {
        printf("Invalid Location!\n");
        printf("List Currntly contains %d elements only\n", len);
    }
    else
    {
        temp = (node*)malloc(sizeof(node));
        temp->data = new;
        temp->next = NULL;

        p = start;
        while(i < loc)
        {
            p = p->next;
            i++;
        }
        temp->next = p->next;
        p->next = temp;
    }
    
}

void deleteNode(int loc)
{
    node* temp;

    if(loc > length(start))
        printf("Invalid Location!\n");

    else if(loc == 1)
    {
        temp = start;
        start = temp->next;
        temp->next = NULL;
        free(temp);
    }

    else
    {
        node* p =start;
        node* q;
        int i = 1;

        while(i < (loc-1))
        {
            p = p->next;
            i++;
        }
        q = p->next;
        p->next = q->next;
        q->next = NULL;
        free(q);
    }
    
}

void display(node* n)
{
    printf("\n-----------------------------------------------------------------------------------------------------\n");
    while(n != NULL)
    {
        printf("%d\t", n->data);
        n = n->next;
    }
    printf("\n-----------------------------------------------------------------------------------------------------\n");
}


int main()
{
    int new, loc;
    int loop = 1;
    int ch;

    do
    {
        printf("\n**********OPERATIONS**********\n");
        printf("1. Insert at Begining\n");
        printf("2. Insert Ater\n");
        printf("3. Display\n");
        printf("4. Delete Node\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1: printf("Enter the number: ");
                    scanf("%d", &new);
                    insertatBegin(new);
                    break;

            case 2: printf("Enter Location after which you want to add: ");
                    scanf("%d", &loc);
                    printf("Enter the number: ");
                    scanf("%d", &new);
                    insertAfter(loc, new);
                    break;

            case 3: display(start);
                    break;

            case 4: printf("Enter location to delete node: ");
                    scanf("%d", &loc);
                    deleteNode(loc);
                    break;

            case 5: printf("\nTermination Successful\n");
                    loop = 0;
                    break;

            default: printf("\nPlease Enter a valid Choice!\n");
        }
    } while (loop);
    return 0;
}