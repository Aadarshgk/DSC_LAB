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
}

void insert_at_start(int num)
{
    node *nn = getnode();
    nn->data = num;
    if (start == NULL)
    {
        start = nn;
        nn->next = start;
        nn->prev = start;
        return;
    }

    nn->prev = start->prev;
    nn->next = start;
    start->prev->next = nn;
    start->prev = nn;
    start = nn;
}
void insert_at_end(int num)
{
    node *nn = getnode();
    nn->data = num;
    if (start == NULL)
    {
        start = nn;
        nn->next = start;
        nn->prev = start;
        return;
    }

    nn->prev = start->prev;
    start->prev->next = nn;
    nn->next = start;
    start->prev = nn;
}

void delete_at_start()
{
    if (start == NULL)
    {
        printf("List empty.\n");
        return;
    }

    if (start->next == start)
    {
        node *temp = start;
        start = NULL;
        free(temp);
        return;
    }

    node *temp = start;
    start->next->prev = start->prev;
    start->prev->next = start->next;
    start = start->next;
    free(temp);
}
void delete_at_end()
{
    if (start == NULL)
    {
        printf("List empty.\n");
        return;
    }

    if (start->prev == start)
    {
        node *temp = start;
        start = NULL;
        free(temp);
        return;
    }

    node* temp= start->prev;
    start->prev= start->prev->prev;
    start->prev->prev= start;
    free(temp);    
}
void display(){
    if(start==NULL){
        printf("List empty");
        return;
    }

    node* temp= start;
    printf("Queue: ");
    while(temp->next!=start){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("%d",temp->data);
    return;

}

void main()
{
}