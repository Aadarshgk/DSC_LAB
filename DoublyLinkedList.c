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

void delete_at_start(){
    if(start==NULL){
        printf("List is empty.");
        return;
    }
    node* toDelete= start;
    start= start->next;
    free(toDelete);
    start->prev=NULL;
}
void delete_at_end(){
    if(start==NULL){
        printf("List is empty.");
        return;
    }
    node* temp= start;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->prev->next= NULL;
    free(temp);
}
void delete_after(int Key){
    node* temp=start;
    while(temp->next!=NULL){
        if(temp->data==Key){
            if(temp==start){
                delete_at_start();
                return;
            }else if(temp->next==NULL){
                delete_at_end();
                return;
            }else{
                temp->prev->next=temp->next;
                temp->next->prev=temp->prev;
                free(temp);
                return;
            }
        }
        temp=temp->next;
    }
    printf("Key not found.");
    return;
}

void display(){
    if(start==NULL){
        printf("List is empty\n");
        return;
    }
    node* temp= start;
    printf("List: ");
    while(temp->next!=NULL){
        printf("%d ", temp->data);
        temp=temp->next;
    }
    return;
}

void main(){}