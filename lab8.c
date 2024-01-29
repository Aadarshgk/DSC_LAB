#include <stdio.h>
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
        printf("%d\n",cqueue[end].data);
    }
}

void main()
{
}