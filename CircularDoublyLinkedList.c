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
        nn->next=start;
        nn->prev=start;
        return;
    }
    
    nn->prev= start->prev;
    nn->next=start;
    start->prev->next=nn;
    start->prev=nn;
    start=nn;
}
void insert_at_end(int num){
    node* nn= getnode();
    nn->data= num;
    if(start==NULL){
        start= nn;
        nn->next=start;
        nn->prev=start;
        return;
    }

    nn->prev=start->prev;
    start->prev->next= nn;
    nn->next=start;
    start->prev=nn;        
}

void delete_at_start();
void delete_at_end();

void display();

void main(){

}