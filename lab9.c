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

}


void delete();
void display();
void main();

