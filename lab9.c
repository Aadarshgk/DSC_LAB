#include<stdio.h>

typedef struct node{
    int data;
    struct node* next;
}nn;

nn* start = NULL;

void insert(int num);
void delete();
void display();
void main();

