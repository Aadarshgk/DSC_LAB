#include <stdio.h>
#include<stdlib.h>
#define max 3

struct queue
{
    int data;
};

struct queue cqueue[max];
int front = -1, end = -1;

void insert()
{
    if (front == -1)
    {
        front = end = 0;
    }

    if ((end + 1) % max == front)
    {
        printf("Queue is full");
    }
    else
    {
        end = (end + 1) % max;
    }

    printf("Enter integrer:");
    scanf("%d", cqueue[end].data);
}

void delete()
{
    if (front == end)
    {
        front = end = -1;
    }
    if (front == -1)
    {
        printf("Queue is empty");
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
            printf("%d ", cqueue[i].data);
        }
        printf("%d\n", cqueue[end].data);
    }
}

void main()
{
    int choice;
    while (1){
        printf("1.Insert\n2.Delete\3.Display\n4.Exit\nEnter choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                insert();
                break;
            
            case 2:
                delete();
                break;
            
            case 3:
                display();
                break;
            
            case 4:
                exit(0);
                break;
            
            default:
                printf("Invalid entry.");
                break;
        }
    }
}