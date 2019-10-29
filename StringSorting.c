//C Program to sort strings

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    char **str;
    char temp[20];
    int i, j, n;
    
    //Getting number of strings to be entered
    printf("Enter number of names to be entered: ");
    scanf("%d", &n);
    
    //Allocating memory for n number of strings
    str = (char**)malloc(sizeof(char*)*n);
    
    //Allocating memory for 20 characters of each string
    for(i=0;i<n;i++)
        str[i] = (char *)malloc(sizeof(char)*20);
        
    printf("Enter %d names:\n", n);
    for(i=0;i<n;i++)
    {
        scanf("%s", str[i]); //scanning each string
    }
    
    
    //Swapping strings if greater using Bubble Sort Method
    for(i=1;i<n;i++){
        for(j=0;j<(n-i);j++)
            if(strcmp(str[j], str[j+1])>0)
            {
                strcpy(temp, str[j]); 
                strcpy(str[j], str[j+1]); 
                strcpy(str[j+1], temp); 
            }
    }
    
    printf("After sorting:\n");
    for(i=0;i<n;i++)
    {
        printf("%s\n", str[i]);
    }
}