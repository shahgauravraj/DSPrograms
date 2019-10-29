#include<stdio.h>
#include<stdlib.h>
int main()
{
    int **ptr1, **ptr2, **ptr3;
    int r1, c1, r2, c2, i, j, k;
    
    printf("Enter number of rows and column of matrix 1: ");
    scanf("%d%d",&r1, &c1);
    
    printf("Enter number of rows and column of matrix 2: ");
    scanf("%d%d",&r2, &c2);
    
    if(c1 != r2)
    {
        printf("Operation cannot be performed!\n");
    }
    
    else{
        //Dynamic Memory Allocation for both the matrices.
        
        ptr1 = (int **)malloc(sizeof(int *) * r1); //Allocating memory for number of rows
        ptr2 = (int **)malloc(sizeof(int *) * r2);
        ptr3 = (int **)malloc(sizeof(int *) * r1);
        
        for(i=0;i<r1;i++)
            ptr1[i] = (int *)malloc(sizeof(int) * c1); //Allocating memory for each columnar elements
            
        for(i=0;i<r2;i++)
            ptr2[i] = (int *)malloc(sizeof(int) * c2);
            
        for(i=0;i<r1;i++)
            ptr3[i] = (int *)malloc(sizeof(int) * c2);

        printf("\nEnter %d elements of Matrix 1:\n", r1*c1);
            for(i=0;i<r1;i++)
                for(j=0;j<c1;j++)
                    {
                        scanf("%d", *(ptr1 + i) + j);
                    }
                    
        printf("\nEnter %d elements of Matrix 2:\n", r2*c2);
            for(i=0;i<r2;i++)
                for(j=0;j<c2;j++)
                    {
                        scanf("%d", *(ptr2 + i) + j);
                    }
        //Calculating product of the matrices         
        for(i=0;i<r1;i++)
        {
            for(j=0;j<c1;j++)
            {
                *(*(ptr3 + i) + j) = 0;
                for(k=0;k<c2;k++)
                {
                    *(*(ptr3 + i) + j) = *(*(ptr3 + i) + j) + *(*(ptr1 + i) + k) * *(*(ptr2 + k) + j);
                }
            }
        }
        
        printf("Sum of the matrices is:\n");
        for(i=0;i<r1;i++)
        {
            for(j=0;j<c2;j++)
            {
                printf("%d\t", *(*(ptr3 + i) + j));
            }
            printf("\n");
        }
        
    }
    
    
}