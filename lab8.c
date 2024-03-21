// Write a C program to simulate the working of a circular Queue of
// integers. Represent circular queue element as a structure and use array
// of structures as your implementation method. Start and end of the
// circular queue must be identified by an empty array element. 

#include <stdio.h>
#include <stdlib.h>
#define max 5

int front = -1, end = -1;
struct circular
{
    int data;
} cqueue[max];

void insert(int num)
{

    if ((end + 1) % max == front)
    {
        printf("Queue full\n");
        return;
    }
    if (front == -1)
    {
        front = end = 0;
    }
    else
    {
        end = (end + 1) % max;
    }
    cqueue[end].data = num;
    return;
}

void delete()
{

    if (front == -1)
    {
        printf("Queue empty\n");
        return;
    }
    if (front == end)
    {
        front = end = -1;
        return;
    }
    else
    {
        front = (front + 1) % max;
        return;
    }
}
void display()
{
    if (front == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    else
    {
        int i;
        printf("Queue: ");
        for (i = front; i != end; i = (i + 1) % max)
        {
            printf("%d ", cqueue[i].data);
        }
        printf("%d \n", cqueue[end].data);
    }
}

void main()
{
    int choice, num;
    while (1)
    {
        printf("1.Insert\n2.Delete\n3.Display\n4.Exit\nEnter choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter num:");
            scanf("%d", &num);
            insert(num);
            break;
        case 2:
            delete();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice.\n");
            break;
        }
    }
}