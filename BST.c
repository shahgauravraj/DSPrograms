#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

typedef struct Node node;

node* root = NULL;

void insert(int d)
{
    node* t;
    node* par;

    t = (node*)malloc(sizeof(node));

    t->data = d;
    t->left = t->right = NULL;

    par = root;

    if(root == NULL)
    {
        root = t;
        return;
    }

    else
    {
        node* cur;
        cur = root;

        while(cur != NULL)
        {
            par = cur;

            if(t->data > cur->data) cur = cur->right;

            else cur = cur->left;
        }

        if(t->data > par->data) par->right = t;

        else par->left = t;
    }
}

void inorder(node* t)
{
    if(t->left)
        inorder(t->left);

    printf("%d\t", t->data);
    if(t->right)
        inorder(t->right);
}

void preorder(node* t)
{
    printf("%d\t", t->data);

    if(t->left)
        inorder(t->left);

    if(t->right)
        inorder(t->right);
}

void postorder(node* t)
{   
    if(t->left)
        inorder(t->left);

    if(t->right)
        inorder(t->right);

    printf("%d\t", t->data);
}

int main()
{
    int new, ch;
    int loop = 1;

    do
    {
        printf("\n**********OPERATIONS**********\n");
        printf("1. Insert Node\n");
        printf("2. Inorder Traverse\n");
        printf("3. Preorder Traverse\n");
        printf("4. Postorder Traverse\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1: printf("Enter the number: ");
                    scanf("%d", &new);
                    insert(new);
                    break;

            case 2: printf("\n-----------------------------------------------------------------------------------------------------\n");
                    inorder(root);
                    printf("\n-----------------------------------------------------------------------------------------------------\n");
                    break;

            case 3: printf("\n-----------------------------------------------------------------------------------------------------\n");
                    preorder(root);
                    printf("\n-----------------------------------------------------------------------------------------------------\n");
                    break;

            case 4: printf("\n-----------------------------------------------------------------------------------------------------\n");
                    postorder(root);
                    printf("\n-----------------------------------------------------------------------------------------------------\n");
                    break;

            case 5: printf("Program Terminated Successfully!\n");
                    loop = 0;
                    break;

            default: printf("Please Enter a valid choice!\n");
        }
    } while (loop);
}