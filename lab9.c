#include<stdio.h>

typedef struct node_st{
    int data;
    struct node* next;
}node;

node* start = NULL;

node* getnode(){
    node* temp= (node*)malloc(sizeof(node));
    temp->next= NULL;
    return temp;   
}

void insert_at_start(int num){
    node* nn = getnode();
    nn->data= num;
    nn->next=  start;
    start = nn;
}

void insert_at_end(int num){
    node* nn= getnode();
    nn->data=num;
    node* temp=start;
    while(temp->next!=NULL){
        temp= temp->next;
    }
    temp->next= nn;
}

void insert_after(int key, int num){
    node* nn= getnode();
    nn->data= num;
    node* temp = start;
    while(temp->data!= key){
        temp= temp->next;
        if(temp->next== NULL){
            printf("Key not found.\n")
        }
    }
    nn->next= temp->next;
    temp->next= nn;
}

void delete();
void display();
void main();

