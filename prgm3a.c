#include<stdio.h>
int main()
{
    int n;
    int i, j;
    char s[20] = "Gandhi";
    char temp;

    for(n=0; s[n] != '\0'; n++);
    printf("%d\n", n);

    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-i-1; j++)
        {
            if(s[i] >= s[i+1])
            {
                temp = s[i];
                s[i] = s[i+1];
                s[i+1] = temp;
            }
        }
    }

    for(i=0; s[i] != '\0'; i++)
    {
        printf(" %c, %d\t", s[i], s[i]);
    }
return 0;
}