#include<stdio.h>

int toh (int disks, char source, char temporary, char destination)
{
    if(disks == 1)
    {
        printf("\nMove disk %d From %c To %c\n", disks, source, destination);
        return 0;
    }
    toh(disks - 1, source, destination, temporary);
    printf("Move disk %d From %c to %c\n", disks, source, destination);
    toh(disks - 1, temporary, source, destination);
    return 0;
}

int main()
{
    char source = 'A', temporary = 'B', destination = 'C';
    int disks;
    printf("Enter number of disks: ");
    scanf("%d", &disks);
    printf("\nSequence of disks\n");
    toh(disks, source, temporary, destination);
    printf("\n");
    return 0;
}