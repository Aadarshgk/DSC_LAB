#include<stdio.h>
#include<ctype.h>

char s[20];
int top=-1;

void push(char a){
    s[++top];
}

char pop(){
    if(top==-1){
        return -1;
    }

    return s[top--];
}

int priority(char a){
    if(a=='(' || a==')'){
        return 0;
    }else if(a=='+' || a=='-'){
        return 1;
    }else if(a=='*' || a=='/'){
        return 2;
    }
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
            push(a[i]);
        }
        
        else if(isalnum(a[i])){
            printf("%c",a[i]);
        }

        else if(a[i]==')'){
            while((x=pop())!='('){
                printf("%c",pop());
            }
        }

        else{
            if(!isEmpty() && priority(a[i])>=priority(a[i])){
                printf("%c",pop());
            }
            push(a[i]);
        }
        i++;
    }
}