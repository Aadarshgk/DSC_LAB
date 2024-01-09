#include <stdio.h>

void towerOfHanoi(int n, char A, char B, char C)
{
    if (n == 1)
    {
        printf("Move ring from %c to %c \n", A, C);
    }
    else{
        towerOfHanoi(n-1,A,C,B);
        towerOfHanoi(1,A,B,C);
        towerOfHanoi(n-1,B,A,C);
    }
}

void main()
{
    int n;
    printf("Enter the number of rings:");
    scanf("%d",&n);
    towerOfHanoi(n,'A','B','C');
}