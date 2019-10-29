#include<stdio.h>
int main()
{
    int i, j, n=0;
    int a[3][3] = {{'.','.','.'},{'.','.','.'},{'.','.','.'}};
    printf("Let the game begin:\n");
    
    for(i=0;i<3;i++){
        printf("\t");
        for(j=0;j<3;j++){
            printf("%c  ", a[i][j]);
        }
        printf("\n");
    }
    
    while(n <= 8){
        printf("Player 1: Enter the position you wanna go for: ");
        scanf("%d%d", &i, &j);
        a[i][j] = '0';
        for(i=0;i<3;i++){
            printf("\t");
            for(j=0;j<3;j++){
                printf("%c  ", a[i][j]);
            }
        printf("\n");
        }
        n++;
        printf("Player 2: Enter the position you wanna go for: ");
        scanf("%d%d", &i, &j);
        a[i][j] = 'x';
        for(i=0;i<3;i++){
            printf("\t");
            for(j=0;j<3;j++){
                printf("%c  ", a[i][j]);
            }
        printf("\n");
        }
        n++;
    
    }
}