#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

typedef struct Node node;

node* start = NULL;

void insertatBegin(int x)
{
    node* temp = (node*)malloc(sizeof(node));

    if(start == NULL)
    {
        start = temp;
        start->data = x;
        start->next = start;
        return;
    }
    node* p;
    p = start;

    while(p->next != start)
        p = p->next;

    temp->data = x;
    temp->next = start;
    p->next = temp;
    start = temp;
}

void insertatEnd(int x)
{
    node* temp;
    temp = (node*)malloc(sizeof(node));

    if(start == NULL)
    {
        start = temp;
        start->data = x;
        start->next = start;
        return;
    }
    node* p = start;

    while(p->next != start)
        p = p->next;

    temp->data = x;
    p->next = temp;
    temp->next = start;
}

void display(node* n)
{
    while(n->next != start)
    {
        printf("%d\t", n->data);
        n = n->next;
    }
    printf("%d\n", n->data);
}

int main()
{
    int loop = 1;
    int ch;
    int new, loc;

    do
    {
        printf("1. Insert at End\n");
        printf("2. Insert at Begining\n");
        printf("3. Display\n");
        printf("4. Delete Node\n");
        printf("5. Tell Length\n");
        printf("6. Exit\n");
        printf("Enter your Choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1: printf("Enter the number: ");
                    scanf("%d", &new);
                    insertatEnd(new);
                    break;

            case 2: printf("Enter the number: ");
                    scanf("%d", &new);
                    insertatBegin(new);
                    break;

            case 3: display(start);
                    break;

            // case 4: printf("Enter the location for deletion of node: ");
            //         scanf("%d", &loc);
            //         deleteNode(loc);
            //         break;
            
            // case 5: printf("Length of List = %d\n", length(start));
            //         break;

            case 6: printf("Program Terminated Sucsessfully!\n");
                    loop = 0;
                    break;

            default: printf("Please Enter a valid Choice!\n");
        }
    } while(loop);

return 0;
}