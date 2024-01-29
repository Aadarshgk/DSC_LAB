#include <stdio.h>
#include<stdlib.h>

typedef struct node_st
{
    int data;
    struct node *next;
} node;

node *start = NULL;

node *getnode()
{
    node *temp = (node *)malloc(sizeof(node));
    temp->next = NULL;
    return temp;
}

void insert_at_start(int num)
{
    node *nn = getnode();
    nn->data = num;
    nn->next = start;
    start = nn;
}

void insert_at_end(int num)
{
    node *nn = getnode();
    nn->data = num;
    node *temp = start;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = nn;
}

void insert_after(int key, int num)
{
    node *nn = getnode();
    nn->data = num;
    node *temp = start;
    while (temp->data != key)
    {
        temp = temp->next;
        if (temp->next == NULL)
        {
            printf("Key not found.\n");
            return;
        }
    }
    nn->next = temp->next;
    temp->next = nn;
}

void delete_at_start()
{
    if (start != NULL)
    {
        node *temp = start;
        start = start->next;
        free(temp);
    }
    else
    {
        printf("List empty");
    }
};

void delete_at_end()
{
    if (start == NULL)
    {
        printf("list empty.");
        return;
    }

    node *temp = start;
    node *prev = NULL;
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == start)
    {
        start = NULL;
        free(temp);
    }
    free(temp);
    prev->next = NULL;
}

void delete_node(int key)
{
    node* temp= start;
    node* prev= NULL;
    if (start == NULL)
    {
        printf("list empty.");
        return;
    }

    while(temp->next!=NULL){
        if(temp->data==key){
            prev->next= temp->next;
            free(temp);
            return;
        }
        prev=temp;
        temp=temp->next;
    }
    printf("Key not found.\n");    
}

void display(){
    if(start== NULL){
        printf("List empty\n");
        return;
    }
    
    printf("List: ");
    node* temp= start;
    while(temp->next!=NULL){
        printf("%d",temp->data);
        temp=temp->next;
    }
}
void main(){
    int choice;
    while(1){

    }
}
