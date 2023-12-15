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
}
