#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void display(struct Node* n)
{
    while(n != NULL)
    {
        printf("%d\t", n -> data);
        n = n -> next;
    }
}

void insertatLast(struct Node* head)
{
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));

    printf("\nEnter the value to be appended: ");
    scanf("%d", &temp -> data);
    temp -> next = NULL;

    if(head == NULL)
        head = temp;

    else {
        struct Node* p;
        p = head;
        while (p -> next != NULL)
        {
            p = p -> next;
        }
        p -> next = temp;
    }
}

void insertatBegining(struct Node* head)
{
    struct Node* temp;
    temp = (struct Node*)malloc(sizeof(struct Node));

    printf("\nEnter the data: ");
    scanf("%d", temp->data);
    temp -> next = NULL;

    if(head == NULL)
        head = temp;

    else
        temp -> next = head;
    head = temp;
}

int main()
{
    struct Node* head;
    struct Node* sec;
    struct Node* thi;

    head = (struct Node*)malloc(sizeof(struct Node));
    sec = (struct Node*)malloc(sizeof(struct Node));
    thi = (struct Node*)malloc(sizeof(struct Node));

    head -> data = 1;
    head -> next = sec;

    sec -> data = 2;
    sec -> next = thi;

    thi -> data = 3;
    thi -> next = NULL;

    display(head);
    insertatLast(head);
    display(head);
    insertatLast(head);
    display(head);
    insertatBegining(head);
    display(head);
}