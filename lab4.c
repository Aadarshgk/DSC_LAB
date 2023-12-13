#include<stdio.h>
#include<ctype.h>

int s[20], top=-1;

void push(char a){
}

int isEmpty(){
    return top == -1;
}
 
void main(){
    char a[20], x;
    int i=0;
    printf("Enter the expression to be converted to postfix notation:");
    scanf("%s",a);
    while(a[i]!='\0'){

        if(a[i]=='('){
            push('(');
        }
        
        else if(isalnum(a[i])){
            printf("%c",a[i]);
        }


        i++;
    }
}