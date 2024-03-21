// Write a C program
// a) To construct a binary tree of integers.
// b) To traverse the tree using inorder, preorder and postorder traversal
// methods 

#include <stdio.h>
#include <stdlib.h>

typedef struct node_st
{
    int data;
    struct node_st *left;
    struct node_st *right;
} node;

node *root = NULL;

node *getnode(int num)
{
    node *nn = (node *)malloc(sizeof(node));
    nn->left = nn->right = NULL;
    nn->data = num;
    return nn;
}

node *insert(node *head, int num)
{

    if (head == NULL)
    {
        return getnode(num);
    }

    if (num < head->data)
    {
        head->left = insert(head->left, num);
    }
    else
    {
        head->right = insert(head->right, num);
    }
    return head;
}

node *search(node *head, int n){
    if(head==NULL){
        return head;
    }
    else if(n>head->data){
        return search(head->right,n);
    }
    else if(n<head->data){
        return search(head->left,n);
    }else{
        return head;
    }
}

void inorder(node *head)
{
    if (head != NULL)
    {
        inorder(head->left);
        printf(" %d ", head->data);
        inorder(head->right);
    }
}

void preorder(node *head)
{
    if (head != NULL)
    {
        printf(" %d ", head->data);
        preorder(head->left);
        preorder(head->right);
    }
}

void postorder(node *head)
{
    if (head != NULL)
    {
        postorder(head->left);
        postorder(head->right);
        printf(" %d ", head->data);
    }
}

void main()
{
    // root=insert(root,4);
    // root=insert(root,2);
    // root=insert(root,3);
    // root=insert(root,9);
    // root=insert(root,1);
    // root=insert(root,6);
    // root=insert(root,5);
    // root=insert(root,0);
    // root=insert(root,8);
    // inorder(root);
    // printf("\n");
    // preorder(root);
    // printf("\n");
    // postorder(root);
    // printf("\n");

    int choice, num;
    while (1){
        printf("1.Insert\n2.Inorder\n3.Preorder\n4.Postoreder\n5.Exit\n6.Search\nEnter choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter integer:");
                scanf("%d",&num);
                root=insert(root,num);
                break;
            case 2:
                inorder(root);
                break;
            case 3:
                preorder(root);
                break;
            case 4:
                postorder(root);
                break;

            case 5:
                exit(0);

            case 6:
                printf("Enter number to search: ");
                scanf("%d",&num);
                node *res= search(root,num);
                if(res == NULL){
                    printf("Number not found.\n");
                }else{
                    printf("Number found in the tree. %d", res->data);
                }
                break;

            default:
                printf("Invalid entry");

        }
    }
}