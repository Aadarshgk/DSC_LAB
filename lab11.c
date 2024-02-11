#include <stdio.h>
#include <stdlib.h>

typedef struct node_st
{
    int data;
    struct node_st *next;
    struct node_st *prev;
} node;

node *start = NULL;

node *getnode()
{
    node *nn = (node *)malloc(sizeof(node));
    nn->next = nn->prev = NULL;
    return nn;
}

void insert(int key, int num)
{
    if (start == NULL)
    {
        start = getnode();
        start->data = num;
    }
    else
    {
        node *temp = start;
        while (temp->next != NULL && temp->data != key)
        {
            temp = temp->next;
        }

        if (temp == start)
        {
            node *nn = getnode();
            nn->data = num;
            nn->next = temp;
            start->prev = nn;
            start = nn;
            return;
        }
        else if (temp->next == NULL)
        {
            printf("Key not found");
            return;
        }
        else
        {
            node *nn = getnode();
            nn->data = num;
            nn->next = temp->next;
            nn->prev = temp;
            nn->next->prev = nn;
            temp->next = nn;
            return;
        }
    }
}


void delete(int num) {}

void display(){
    node* temp=start;
    while(temp!=NULL){
        printf(" %d ",temp->data);
        temp=temp->next;
    }
}

void main()
{
    insert(1,1);
    insert(1,2);
    insert(2,3);
    display();
}