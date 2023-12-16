/*Write a C program to convert and print a given valid parenthesized infix
arithmetic expression to postfix expression. The expression consists of
single character operands and binary operators + - * /. Apply the
concept of stack data structure to solve this problem*/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int s[20],top = -1;

void push(int a){
    s[++top]=a;
}

int pop(){
    return s[top--];
}



void main(){
    char a[20];
    int num,n1,n2,res;
    int i=0;
    printf("Enter the postfix notation to evaluate output:");
    scanf("%s",a);
    while(a[i]!='\0'){
        if(isdigit(a[i])){
            num= a[i] - '0';
            push(num);
        }
        else{

            n2= pop();
            n1= pop();
            switch(a[i]){
                case '+':
                    res=n1+n2;
                    break;
                
                case '-':
                    res= n1-n2;
                    break;
                
                case '*':
                    res = n1*n2;
                    break;

                case '/':
                    res = n1/n2;
                    break;

                
            }
            push(res);
        }

    i++;
    }

    printf("The result is: %d",pop());
}
