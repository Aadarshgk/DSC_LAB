#include <stdio.h>
#include <stdlib.h>

typedef struct node_st
{
    int data;
    struct node_st *next;
} node;

node *top = NULL;

node *getnode()
{
    node *nn = (node *)malloc(sizeof(node));
    nn->next = NULL;
    return nn;
}

void push(int num)
{
    if (top == NULL)
    {
        top = getnode();
        top->data = num;
        return;
    }

    node *temp= top;
    top= getnode();
    top->data=num;
    top->next=temp;   
}

void pop(){
    if(top== NULL){
        printf("Stack underflow\n");
        return;
    }else{
        printf("Popped element: %d\n",top->data);
        node* temp= top;
        top=top->next;
        free(temp);
        return;
    }
}

void display()
{
    if (top == NULL)
    {
        printf("Stack empty\n");
        return;
    }
    else
    {
        node* temp= top;
        while(temp!=NULL){
            printf("%d\n",temp->data);
            temp=temp->next;
        }
    }
}


void main()
{
    int ch,num;
    while(1){
        printf("1.Push\n2.Pop\n3.Display\n4.Exit\nEnter choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter integer to push:");
                scanf("%d",&num);
                push(num);
                break;
            
            case 2:
                pop();
                break;
            
            case 3:
                printf("Stack:\n");
                display();
                break;
            
            case 4:
                printf("Exitting!\n");
                exit(0);
                break;
            
            default:
                printf("Invalid entry\n");
                break;
        }
    }
}