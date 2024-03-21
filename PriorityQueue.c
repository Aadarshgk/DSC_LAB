#include <stdio.h>
#include <stdlib.h>

typedef struct node_st
{
    int num;
    int priority;
    struct node_st *next;
} node;

node *start = NULL;

node *getnode(int n, int p)
{
    node *nn = (node *)malloc(sizeof(node));
    nn->num = n;
    nn->priority = p;
    nn->next = NULL;
    return nn;
}

void insert(int n, int p)
{
    node *nn = getnode(n, p);
    if (start == NULL || p < start->priority)
    {
        nn->next = start;
        start = nn;
    }
    else
    {
        node *temp = start;
        while (temp->next != NULL && temp->next->priority <= p)
        {
            temp = temp->next;
        }

        nn->next=temp->next;
        temp->next=nn;
        return;
    }
}


void delete(){
    if(start==NULL){
        printf("Queue underflow");
        return;
    }
    node* temp= start;
    printf("Popped element: %d\n",temp->num);
    start=start->next;
    free(temp);
    return;
}

void display()
{
    node *temp = start;
    while (temp != NULL)
    {
        printf("%d ", temp->num);
        temp = temp->next;
    }
}



void main()
{
    insert(1, 1);
    insert(2, 1);
    insert(3, 1);
    insert(4, 1);
    insert(5, 1);
    display();
    delete();
    display();
}