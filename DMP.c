//This program counts the number of times each digit occur in a multi-digit number.

#include <stdio.h>

int main()
{
    int num, i;
    int count[10] = {0, 0, 0, 0, 0, 0, 0 ,0 ,0, 0};
    printf("Enter the number: ");
    scanf("%d", &num);
    
    while(num != 0)
    {
        printf("%d\n", (num % 10));
        for(i=0;i<10;i++)
        {
            if((num%10) == i)
            {
                count[i]++;
            }
        }
        num = num / 10;
    }
    printf("Counts are given as: \n");
    for(i=0;i<10;i++)
        printf("%d\t", count[i]);

    return 0;
}
