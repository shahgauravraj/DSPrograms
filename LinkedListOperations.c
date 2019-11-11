#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* start = NULL;

void insertatBegin(int x);
void insertatEnd(int x);
void delete(int loc);
void display(struct Node* n);
void reverse(void);
int length(struct Node* n);

int main()
{
    int x, loc;
    int ch;
    int loop = 1;
    
    do {
        printf("\n**********OPERATIONS**********\n");
        printf("1. Insert at begin\n2. Insert at End\n3. Delete\n4. Display\n5. Reverse List\n6. Tell Length\n7. Exit\nEnter your Choice: ");
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

            default:printf("Please Enter a valid Input!\n\n");
                    
        }
    } while(loop);
    return 0;
}

void insertatBegin(int x)
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

void insertatEnd(int x)
{
    struct Node *t, *temp;
   
   t = (struct Node*)malloc(sizeof(struct Node));
   
   if (start == NULL) {
      start = t;
      start->data = x;
      start->next = NULL;
      return;
   }
   
   temp = start;
   
   while (temp->next != NULL)
      temp = temp->next;  
   
   temp->next = t;
   t->data    = x;
   t->next    = NULL;
}

void delete(int loc)
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
        temp->next = NULL;
        free(temp);
    }
    
    else
    {
        struct Node* p = start, *q;
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

void reverse(void)
{
    struct Node *p, *q;
    int i, j, k, len, temp;

    len = length(start);

    i = 0;
    j = len - 1;
    p = q = start;

    while(i < j)
    {
        k = 0;
        while(k < j)
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