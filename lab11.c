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

void insert(int num, int key)
{
    if (start == NULL)
    {
        start = getnode();
        start->data = num;
    }
    else
    {
        node *temp = start;
        while (temp!= NULL && temp->data != key)
        {
            temp = temp->next;
        }

        if (temp == NULL)
        {
            printf("Key not found");
            return;
        }
        node *nn = getnode();
        nn->data = num;
        nn->next = temp;
        nn->prev= temp->prev;
        temp->prev=nn;

        if(nn->prev!=NULL){
            nn->prev->next=nn;
        }else{
            start=nn;
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
            }
            else
            {
                printf("Key not found\n");
                return;
            }
        }
        else
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            free(temp);
            return;
        }
    }
}

void display()
{
    if (start == NULL)
    {
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
    int choice, num, key;
    while (1)
    {
        printf("1.Insert\n2.Delete\n.3.Diplay\n4.Exit\nEnter choice:");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter number to be inserted:");
                scanf("%d",&num);
                printf("Enter key: ");
                scanf("%d",&key);
               insert(num,key);
               break;
            case 2:
                printf("Enter number to be deleted:");
                scanf("%d",&num);
                delete(num);
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid entry");
         
        }
    }
}