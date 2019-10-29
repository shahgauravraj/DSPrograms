#include<stdio.h>
#include<stdlib.h>
int main(int argc, char* argv[])
{
    FILE *fp1, *fp2;
    char datatobeWritten[50];
    char data[50];

    printf("Please Enter the String: ");
    scanf("%[^\n]s", datatobeWritten);

    fp1 = fopen(argv[1], "w");
    printf("File 1 opened in write mode\n");
    fputs(datatobeWritten, fp1);
    fputs("\n", fp1);
    fclose(fp1);
    printf("File 1 closed\n");

    fp1 = fopen(argv[1], "r");
    printf("File 1 opened in read mode\n");
    fp2 = fopen(argv[2], "w");
    printf("File 2 opened in read mode\n");
    fscanf(fp1, "%[^\n]s", data);
    fputs(data, fp2);
    fputs("\n", fp2);

    fclose(fp1);
    printf("File 1 closed\n");
    fclose(fp2);
    printf("File 2 closed\n");

    return 0;
}