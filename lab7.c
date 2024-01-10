#include <stdio.h>
#include<stdlib.h>
#define max 3

int queue[max],front = -1, end = -1;

void insert(int num){
    if(front==-1){
        front=end=0;
    }
    if(front == (end+1)%max){
        printf("Queue is full");
        return;
    }else{
        end= (end+1)%max;
        queue[end]=num;
    }
}

void delete(){
    if(front==-1){
        printf("Queue empty.");
        return;
    }
    if(front == end){
        front=end=-1;
    }else{
        front=(front+1)%max;
    }
}
void display(){
    int i=front;
    do{
        printf("%d",queue[i]);
        i=(i+1)%max;
    }while(i!=end);

}

void main()
{
    int choice, id;
    while (1){
        printf("1.Add caller\n2.Delete caller\n3.Display queue\n4.Exit\nEnter choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter caller id:");
                scanf("%d",&id);
                insert(id);
                break;

            case 2:
                delete();
                printf("Caller id removed from queue.");
                break;
            
            case 3:
                display();
                break;
            
            case 4:
                exit(0);
                break;
            
            default:
                printf("Invalid choice");
                break;

        }
    }
}