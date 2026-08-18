// Jiya Chauhan: 92500588005
// Defination: Write a tower of Hanoi program.
#include<stdio.h>

void tower(int n,char source,char helper,char destination)
{
    if (n==1)
    {
        printf("move disk 1 from %c to %c\n",source,destination);
        return;
    }

    tower(n -1,source,destination,helper);

    printf("move disk %d from %c\n",n,source,destination);
    tower(n -1,helper,source,destination);
}

void main()
{
    int n;

    printf("Enter number of disk:");
    scanf("%d",&n);

    tower(n,'A','B','C');

}


