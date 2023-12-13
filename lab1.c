/*Design, Develop and Implement a menu driven Program in C for the
following array operations.
a) Creating an array of N Integer Elements
b) Display of array Elements with Suitable Headings
c) Inserting an Element (ELEM) at a given valid Position (POS)
d) Deleting an Element at a given valid Position (POS)
e) Exit.
Support the program with functions for each of the above operations*/

#include <stdio.h>
#include <stdlib.h>

void create(int *aptr, int l)
{
    for (int i = 0; i < l; i++)
    {
        printf("Enter element:");
        scanf("%d", (aptr + i));
    }
    printf("\n");
}

void display(int *aptr, int l)
{
    printf("Array elements:");
    for (int i = 0; i < l; i++)
    {
        printf("%d ", *(aptr + i));
    }
    printf("\n");
}

int insert(int *aptr, int n, int pos, int len)
{
    if ((pos > len - 1) || pos < 0)
    {
        printf("Invalid index.");
        return len;
    }
    else
    {

        for (int i = len - 1; i >= pos - 1; i--)
        {
            aptr[i + 1] = aptr[i];
        }
        aptr[pos - 1] = n;
        return len += 1;
    }
}

int delete(int *aptr, int pos, int len)
{
    if ((pos > len - 1) || (pos < 0))
    {
        printf("Index out of bound");
        return len;
    }
    else
    {

        for (int i = pos - 1; i < len - 1; i++)
        {
            aptr[i] = aptr[i + 1];
        }
        aptr[len] = 0;
        return len -= 1;
    }
}

void main()
{
    int a[50], x;
    int len = 0;
    int *aptr = a;
    while (1)
    {
        printf("1.CREATE\n");
        printf("2.DISPLAY\n");
        printf("3.INSERT\n");
        printf("4.DELETE\n");
        printf("5.EXIT\n");
        printf("Enter choice:");
        scanf("%d", &x);
        switch (x)
        {
        case 1:
            printf("Enter the number of terms to inserted:");
            int l;
            scanf("%d", &l);
            if (l > len)
            {
                len = l;
            }
            create(aptr, l);
            break;

        case 2:
            display(aptr, len);
            break;

        case 3:
            printf("Enter the number to inserted:");
            int n, pos;
            scanf("%d", &n);
            printf("Enter the position of the element to be inserted:");
            scanf("%d", &pos);
            len = insert(aptr, n, pos, len);
            printf("\n");
            break;

        case 4:
            printf("Enter the position of the element to be deleted: ");
            // int pos;
            scanf("%d", &pos);
            len = delete (aptr, pos, len);
            printf("\n");
            break;
        default:
            exit(0);
        }
    }
}