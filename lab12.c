#include<stdio.h>
#include<stdlib.h>

typedef struct node_st
{
    int data;
    struct node_st* left;
    struct node_st* right;
}node;

node* root= NULL;

node* getnode(int num){
    node* nn= (node*)malloc(sizeof(node));
    nn->left=nn->right=NULL;
    nn->data=num;
    return nn;
}

node* insert(node* head,int num){


    if(head==NULL){
        return getnode(num);
    }

    if(num < head->data){
        head->left= insert(head->left,num);
    }else{
        head->right=insert(head->right,num);
    }
    return head;
}

void inorder(node* head){
    if(head!=NULL){
        inorder(head->left);
        printf(" %d ", head->data);
        inorder(head->right);
    }
}

void preorder(node* head){
    if(head!=NULL){
        printf(" %d ", head->data);
        preorder(head->left);
        preorder(head->right);
    }
}

void postorder(node* head){
    if(head!=NULL){
        postorder(head->left);
        postorder(head->right);
        printf(" %d ", head->data);
    }
}

void main(){
    root=insert(root,4);
    root=insert(root,2);
    root=insert(root,3);
    root=insert(root,9);
    root=insert(root,1);
    root=insert(root,6);
    root=insert(root,5);
    root=insert(root,0);
    root=insert(root,8);
    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
}