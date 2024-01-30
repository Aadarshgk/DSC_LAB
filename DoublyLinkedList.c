#include<stdio.h>
#include<stdlib.h>

typedef struct node_st{
    int data;
    struct node_st* next;
    struct node_st* prev;
}node;

node* start= NULL;

node*getnode(){
    node* nn= (node* )malloc(sizeof(node));
    nn->next=nn->prev= NULL;
}

void insert_at_start(int num){
    node* nn= getnode();
    nn->data=num;
    if(start==NULL){
        start= nn;
    }else{
        nn->next= start;
        start->prev= nn;
        start=nn;
        return;
    }
}

void insert_at_end(int num){
    node* nn= getnode();
    nn->data=num;
    node* temp=start;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next= nn;
    nn->prev= temp;
}

void insert_after(int key,int num){
    node* temp=start;
    while(temp->next!=NULL){
        if(temp->data== key){
            node* nn= getnode();
            nn->data= num;
            nn->prev=temp;
            nn->next=temp->next;
            temp->next= nn;
            return;
        }
        temp= temp->next;
    }
    printf("Key not found.\n");
    return;
}

void delete_at_start();
void delete_at_end();
void delete_after();

void display();

void main(){}