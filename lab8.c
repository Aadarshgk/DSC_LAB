#include<stdio.h>
#include<stdlib.h>
#define max 5

int front=-1, end=-1;
struct circular{
    int data;
}cqueue[max];

void insert(int num){

    if((end+1)%max==front){
        printf("Queue full\n");
        return;
    }
    if(front ==-1){
        front=end=0;
    }else{
        end= (end+1)%max;
    }
    cqueue[end].data =num;
    return;
}

void delete(){

    if(front==-1){
        printf("Queue empty\n");
        return;
    }
    if(front==end){
        front=end=-1;
        return;
    }else{
        front = (front+1)%max;
        return;
    }
}
void display(){
    if(front==-1){
        printf("Queue is empty\n");
        return;
    }
    else{
        int i;
        printf("Queue: ");
        for(i=front;i!=end;i=(i+1)%max){
            printf("%d ",cqueue[i].data);
        }
        printf("%d ", cqueue[end].data);
    }
}

void main(){}