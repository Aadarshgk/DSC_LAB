#include<stdio.h>
#include<stdlib.h>

typedef struct node_st{
    int data;
    struct node_st* next;
}node;

node* start= NULL;

node* getNode(){
    node* nn= (node*)malloc(sizeof(node));
    nn->next=NULL;
    return nn;
}

void insert_at_start(int num){
    node* nn= getNode();
    nn->data=num;
    if(start==NULL){
        start=nn;
        start->next=start;
        return;
    }

    node* temp= start;
    while(temp->next!=start){
        temp= temp->next;
    }
    temp->next= nn;
    nn->next=start;
    start= nn;
}

void insert_at_end(int num){
    node* nn= getNode();
    nn->data=num;    
    if(start==NULL){
        start=nn;
        start->next=start;
        return;
    }
    node* temp= start;
    while(temp->next!=start){
        temp=temp->next;
    }
    temp->next=nn;
    nn->next= start;
}
void delete_at_start(){
    if(start==NULL){
        printf("List empty.");
        return;
    }
    node* temp = start;
    while(temp->next!= start){
        temp= temp->next;
    }
    temp->next= start->next;
    node* toDelete= start;
    start=start->next;
    free(toDelete);
}
void delete_at_end(){
    
}
void main(){}
