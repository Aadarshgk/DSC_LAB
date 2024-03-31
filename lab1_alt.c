#include <stdio.h>
#include <stdlib.h>

int a[50], len = 0;

void create()
{
    printf("Enter the size of array: ");
    scanf("%d", &len);
    for (int i = 0; i < len; i++)
    {
        printf("Enter element:");
        scanf("%d", &a[i]);
    }
}

void display(){
    if(len==0){
        printf("Array is empty!\n");
        return;
    }
    printf("Array elements: ");
    for(int i=0;i<len;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}

void insert(){
    int n,pos;
    printf("Enter element to be inserted:");
    scanf("%d",&n);
    printf("Enter the position of the element:");
    scanf("%d",&pos);
    if(pos>len+1 ||  pos< 1){
        printf("Invalid position.");
        return;
    }else{
        for(int i=len-1;i>=pos-1;i--){
            a[i+1]=a[i];
        }
        a[pos-1]=n;
        len++;
    }
}

void delete(){
    int pos;
    printf("Enter the position to be deleted: ");
    scanf("%d",&pos);
    if(len==0){
        printf("Array empty.");
        return;
    }
    if(pos<0 || pos>len){
        printf("Invalid entry");
        return;
    }
    for(int i=pos-1;i<len-1;i++){
        a[i]=a[i+1];
    }
    a[len-1]=0;
    len--;
    return;
}

void main(){
    int choice;
    while(1){
        printf("1.CREATE\n");
        printf("2.DISPLAY\n");
        printf("3.INSERT\n");
        printf("4.DELETE\n");
        printf("5.EXIT\n");
        printf("Enter choice:");
        scanf("%d", &choice);
        switch (choice){
            case 1:
                create();
                break;
            case 2:
                display();
                break;
            case 3:
                insert();
                break;
            case 4:
                delete();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid entry");
                break;

        }
    }
}