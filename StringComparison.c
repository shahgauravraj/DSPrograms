#include<stdio.h>

int strcomp(char *s1, char *s2)
{
    while(*s1 != '\0' || *s2 != '\0')
    {
        if (*s1 != *s2)
            return(*s1 - *s2);
        s1++;
        s2++;

    }
}

void strconcat(char *s1, char *s2)
{
    while(*s1 != '\0')
        s1++;
    while(*s2 != '\0')
    {
        *s1 = *s2;
        s1++;
        s2++;
    }
    //*s1 = '\0';
    //printf("After Concatenation: %s\n", s1);
}

int main()
{
    char s1[50], s2[50];
    int result;

    printf("Enter string 1: ");
    scanf("%s", s1);
    printf("Enter string 2: ");
    scanf("%s", s2);

    result = strcomp(s1, s2);

    if(result > 0)
        printf("%s is greater than %s\n", s1, s2);
    else if(result < 0)
        printf("%s is greater than %s\n", s2, s1);
    else
        printf("Equal Strings!\n");

    strconcat(s1, s2);
    printf("After Concatenation: %s\n", s1);
    return 0;
}