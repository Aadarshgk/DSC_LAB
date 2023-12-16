/*STACK of Integers (Array Implementation of Stack with maximum
size MAX)
a) Push an Element on to Stack
b) Pop an Element from Stack
c) Demonstrate how Stack can be used to check Palindrome
d) Demonstrate Overflow and Underflow situations on Stack
e) Display the status of Stack
f) Exit
Support the program with appropriate functions for each of the above
operations */


#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int s[MAX], top = -1;

void push()
{
    if (top == MAX - 1)
    {
        printf("Stack overflow");
        return;
    }
    else
    {
        int n;
        printf("Enter element:");
        scanf("%d", &n);
        top += 1;
        s[top] = n;
    }
    printf("\n");
}

void pop()
{
    if (top == -1)
    {
        printf("Stack underflow.");
        return;
    }
    else
    {
        printf("The popped element is :%d", s[top]);
        s[top] == 0;
        --top;
    }
    printf("\n");
}

void palin()
{
    int floor = 0, max = top, flag = 0;
    while (floor <= top / 2)
    {
        if (s[floor] != s[max])
        {
            flag = 1;
            break;
        }
        max--;
        floor++;
    }

    if (flag == 1)
    {
        printf("It is not a palindrome\n");
    }
    else
    {
        printf("It is a palindrome\n");
    }
}

void display()
{
    if (top == -1)
    {
        printf("Stack empty");
    }
    else
    {
        for (int i = 0; i <= top; i++)
        {
            printf("| %d |\n", s[i]);
        }
        printf("=====");
        
    }

    printf("\n");
}

void peek()
{
    if (top == -1)
    {
        printf("Stack empty");
    }
    else
    {
        printf("%d\n", s[top]);
    }
    printf("\n");
}

void main()
{
    int x;
    while (1)
    {
        printf("1.PUSH\n2.POP\n3.PALINDROME\n4.DISPLAY\n5.PEEK\n6.EXIT\nENTER CHOICE:");
        scanf("%d", &x);
        switch (x)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            palin();
            break;
        case 4:
            display();
            break;
        case 5:
            peek();
            break;

        default:
            exit(0);
        }
    }
}