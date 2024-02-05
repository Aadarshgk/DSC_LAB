#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char data[50];
    struct Node *next;
} node;

node *start = NULL;

node *getnode()
{
    node *nn = (node *)malloc(sizeof(node));
    nn->next = NULL;
    return nn;
}

void insert(char *name)
{
    node *nn = getnode();
    strcpy(nn->data, name);
    start = nn;
    if (start == NULL)
    {
        start = nn;
    }
    else
    {
        node *temp = start;
        while (temp->next != NULL&& strcmp(temp->data, name)<0)
        {
            temp = temp->next;
        }
        nn->next = temp->next;
        temp->next = nn;
        return;
    }
}

void deleteKey(char *name){
    node* temp= start;
    node* prev= NULL;
    while(temp->next!=NULL){
        if(strcmp(name, temp->data)==0){
            prev->next=temp->next;
            free(temp);
            return;
        }
        prev= temp;
        temp=temp->next;
    }
    printf("Name not found in list.");
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

void main()
{
    int choice;
    char name[50];
    whiile(1){
        printf("1.Insert name\n2.Delete name")
    }
}