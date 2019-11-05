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
void insertatBegin(int x);
void display(struct Node* n);
void deleteNode(int loc);
int length(struct Node* n);

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

            case 4: printf("Enter the location for deletion of node: ");
                    scanf("%d", &loc);
                    deleteNode(loc);
                    break;
            
            case 5: printf("Length of List = %d\n", length(start));
                    break;

            case 6: printf("Program Terminated Sucsessfully!\n");
                    loop = 0;
                    break;

            default: printf("Please Enter a valid Choice!\n");
        }
    } while(loop);

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

void insertatBegin(int x)
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

    temp->data = x;
    temp->next = start;
    start->prev = temp;
    start = temp;
}

void display(struct Node* n)
{
    if(n == NULL)
    {
        printf("List Empty!\n");
        return;
    }
    printf("\n-----------------------------------------------------------------------------------------------------\n");

    while(n != NULL)
    {
        printf("%d\t", n->data);
        n = n->next;
    }
    printf("\n-----------------------------------------------------------------------------------------------------\n");

}

void deleteNode(int loc)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    
    if(loc > length(start))  //check if the given location is greater than the length of the list
    {
        printf("Invalid\n");
    }

    else if(loc == 1)
    {
        temp = start;
        start = temp->next;
        temp->next->prev = start;
        temp->next = NULL;
        free(temp);
    }

    else if (loc < length(start))
    {
        struct Node* p;
        struct Node* q;
        q = (struct Node*)malloc(sizeof(struct Node));
        int i = 1;

        p = start;
        while(i < (loc-1))
        {
            p = p->next;
            i++;
        }

        q = p->next;
        p->next = q->next;
        q->next->prev = p->next;
        q->next = NULL;
        free(q);
    }

    else
    {
        struct Node* p;
        struct Node* q;
        q = (struct Node*)malloc(sizeof(struct Node));
        int i = 1;

        p = start;
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

int length(struct Node* n)
{
    int count = 0;

    while(n != NULL)
    {
        count++;
        n = n->next;
    }

    return count;
}