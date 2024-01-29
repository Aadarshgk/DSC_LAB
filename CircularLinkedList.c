#include<stdio.h>
#include<stdlib.h>

typedef struct node_st{
    int data;
    struct node_st* next;
    struct node_st* prev;
}node;

node* start= NULL;

void insert_at_start();
void insert_at_end();
void delete_at_start();
void delete_at_end();
void main(){}
