#include<stdio.h>
int main()
{
    int i;
    char s[] = "Abc";
    for(i=0; s[i] != '\0'; i++)
    {
        printf("%c: %d\n", s[i], s[i]);
    }
    return 0;
}