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
    int loop = 1;
    int ch;
    int new;

    do
    {
        printf("1. Insert at End\n");
        printf("2. Display\n");
        printf("3. Exit\n");
        printf("Enter your Choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1: printf("Enter the number: ");
                    scanf("%d", &new);
                    insertatEnd(new);
                    break;
            case 2: display(start);
                    break;
            case 3: printf("Program Terminated Sucsessfully!\n");
                    loop = 0;

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