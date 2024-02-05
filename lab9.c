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
    if (start == NULL)
    {
        start = nn;
    }
    else
    {
        node *temp = start;
        if(strcmp(start->data,name)>0){
            nn->next=start;
            start= nn;
            return;
        }
        while (temp->next != NULL&& strcmp(temp->next->data, name)<0)
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
    if(strcmp(start->data,name)==0){
        start=temp->next;
        free(temp);
        return;
    }
    while(temp!=NULL){
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
        printf("%s ",temp->data);
        temp=temp->next;
    }
    printf("%s ",temp->data);
}

void main()
{
    int choice;
    char name[50];
    while(1){
        printf("1.Insert name\n2.Delete name\n3.Display\n4.Exit\nEnter choice:");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter name to inserted:");
            scanf("%s",name);
            insert(name);
            break;
        case 2:
            printf("Enter name to be deleted:");
            scanf("%s",name);
            deleteKey(name);
            break;

        case 3:
            display();
            break;

        case 4:
            exit(0);
            break;

        default:
            printf("Invalid choice.");
            break;
        }
    }
}