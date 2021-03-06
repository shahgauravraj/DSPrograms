#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node node;

node* start = NULL;

void insertatBegin(int x);
void insertatEnd(int x);
void insertAfter(int loc, int x);
void delete(int loc);
void display(node* n);
void reverse(void);
int length(node* n);

int main()
{
    int x, loc;
    int ch;
    int loop = 1;
    
    do {
        printf("\n**********OPERATIONS**********\n");
        printf("1. Insert at begin\n2. Insert at End\n3. Delete\n4. Display\n5. Reverse List\n6. Tell Length\n7. Exit\n8. Insert After\nEnter your Choice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1:printf("Enter the data: ");
                    scanf("%d", &x);
                    printf("\n");
                    insertatBegin(x);
                    break;

            case 2:printf("Enter the data: ");
                    scanf("%d", &x);
                    printf("\n");
                    insertatEnd(x);
                    break;
                    
            case 3:printf("Enter the location to be deleted: ");
                    scanf("%d", &loc);
                    printf("\n");
                    delete(loc);
                    break;

            case 4:display(start);
                    break;

            case 5: reverse();
                    break;

            case 6: printf("Number of Elements in the list = %d\n", length(start));
                    break;

            case 7: printf("\nProgram Terminated Successfully!\n");
                    loop = 0;
                    break;
            case 8: printf("Enter the location after which you wanna insert: ");
                    scanf("%d", &loc);
                    printf("Enter the data: ");
                    scanf("%d", &x);
                    insertAfter(loc, x);
                    break;

            default:printf("Please Enter a valid Input!\n\n");
                    
        }
    } while(loop);
    return 0;
}

void insertatBegin(int x)
{
    node *temp;
    temp = (node*)malloc(sizeof(node));

    if(start == NULL)
    {
        start = temp;
        start->data = x;
        start->next = NULL;
        return;
    }

    temp->data = x;
    temp->next = start;
    start = temp;
}

void insertatEnd(int x)
{
    node *temp;
    temp = (node*)malloc(sizeof(node));

    if(start == NULL)
    {
        start = temp;
        start->data = x;
        start->next = temp;
        return;
    }

    node *p;
    p = start;

    while(p->next != NULL)
        p = p->next;

    temp->data = x;
    temp->next = NULL;
    p->next = temp;
}

void delete(int loc)
{
    int len = length(start);

    node *temp = (node*)malloc(sizeof(node));

    if(loc > len)
        printf("Invalid!\n");

    else if(loc == 1)
    {
        temp = start;
        start = temp->next;
        temp->next = NULL;
        free(temp);
    }

    else
    {
        node *p, *q;
        p = start;
        int i=1;

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
    printf("\n------------------------------------------------------------------------------------------------------\n");
    while(n != NULL)
    {
        printf("%d\t", n->data);
        n = n->next;
    }
    printf("\n------------------------------------------------------------------------------------------------------\n");
}

void reverse()
{
    node *p, *q;
    int i, j, k, len, temp;

    len = length(start);

    p = q = start;
    i = 0;
    j = len - 1;

    while(i<j)
    {
        k=0;
        while(k<j)
        {
            q = q->next;
            k++;
        }
        temp = p->data;
        p->data = q->data;
        q->data = temp;

        i++;
        j--;

        p = p->next;
        q = start;
    }
}

int length(node *n)
{
    int count = 0;
    while(n != NULL)
    {
        count++;
        n = n->next;
    }
    return count;
}

void insertAfter(int loc, int x)
{
    int len = length(start);
    int i = 1;

    node *temp = (node*)malloc(sizeof(node));

    if(loc > len)
        printf("Invalid Location!\n");

    if(start == NULL)
    {
        start = temp;
        start->data = x;
        start->next = NULL;
        return;
    }

    node *p = start;

    while(i < loc)
    {
        p = p->next;
        i++;
    }
    temp->data = x;
    temp->next = p->next;
    p->next = temp;
}