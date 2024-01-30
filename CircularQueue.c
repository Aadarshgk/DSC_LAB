#include <stdio.h>
#include <stdlib.h>
#define max 3


int cqueue[max];
int front = -1, end = -1;

void insert(int num)
{
    if ((end + 1) % max == front)
    {
        printf("Queue is full\n");
        return;
    }

    if (front == -1)
    {
        front = end = 0;
    }else
    {
        end = (end + 1) % max;
    }

    cqueue[end] = num;
}

void delete()
{
    if (front == end)
    {
        front = end = -1;
    }
    if (front == -1)
    {
        printf("Queue is empty\n");
        return;
    }

    else
    {
        front = (front + 1) % max;
    }

    printf("Element removed successfully\n");
}

void display()
{
    if (front == -1)
    {
        printf("Queue empty");
    }
    else
    {
        printf("Queue: ");
        for (int i = front; i != end; i = (i + 1) % max)
        {
            printf("%d ", cqueue[i]);
        }
        printf("%d\n", cqueue[end]);
    }
}

void main()
{
    int choice,num;
    while (1)
    {
        printf("1.Insert\n2.Delete\n3.Display\n4.Exit\nEnter choice:");
        scanf(" %d", &choice);
        if (choice == 1)
        {
            printf("Enter integer:");
            scanf("%d",&num);
            insert(num);
        }
        else if (choice == 2)
        {
            delete ();
        }
        else if (choice == 3)
        {
            display();
        }
        else if (choice == 4)
        {
            exit(0);
        }
        else
        {
            printf("Invalid entry.");
        }
    }
}