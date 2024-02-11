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

void delete(int key)
{
    if (start == NULL)
    {
        printf("List empty\n");
        return;
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
            start = start->next;
            free(temp);
            return;
        }
        else if (temp->next == NULL)
        {
            if (temp->data == key)
            {
                temp->prev->next = NULL;
                free(temp);
                return;
            }else{
                printf("Key not found\n");
                return;
            }
        }
        else {
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            free(temp);
            return;
        }
    }
}

void display()
{
    if(start== NULL){
        printf("List empty!\n");
        return;
    }
    node *temp = start;
    while (temp != NULL)
    {
        printf(" %d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void main()
{
}