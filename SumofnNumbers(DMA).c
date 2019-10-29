// C Program to Dynamiclly Allocate Memory of n numbers ond calculate their sum

#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *ptr;
    int i, n, sum = 0;

    printf("Enter number of elements to be entered: ");
    scanf("%d", &n);

    ptr = (int*)malloc(n*sizeof(int));

    if(ptr == NULL)
        printf("\n\nDynamic Memory Allocation Failed!\nProgram Terminated.\n\n");
    
    else{
        printf("\nEnter %d numbers:\n", n);

        for(i = 0; i < n; i++)
        {
            scanf("%d", (ptr + i));
            sum += *(ptr + i);
        }

        printf("Sum = %d\n\n", sum);
    }
    ptr = NULL;
    free(ptr);

    return 0;
}