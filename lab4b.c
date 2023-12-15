#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int s[20],top = -1;

void push(int a){
    return s[++top]=a;
}

int pop(){
    return s[top--];
}



void main(){
    char a[20];
    int num;
    int i=0;
    printf("Enter the postfix notation to evaluate output:");
    scanf("%s",a);
    while(a[i]!='\0'){
        if(isdigit(a[i])){
            num= a[i] - '0';
            push(num);
        }
        else{


        }

    i++;
    }
}
