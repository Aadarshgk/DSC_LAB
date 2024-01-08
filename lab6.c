#include <stdio.h>

int binarySearch(int ar[], int key, int low, int high)
{
    if (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (ar[mid] == key)
        {
            return mid;
        }
        else if (key > ar[mid])
        {
            binarySearch(ar, key, mid + 1, high);
        }

        return binarySearch(ar, key, low, mid - 1);
    }

    return -1;
}

void main()
{
    int n, key;
    printf("Enter the size of array:");
    scanf("%d", &n);
    int ar[n];
    printf("Enter the elements of the sorted array:");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ar[i]);
    }
    printf("Enter the element to be searched: ");
    scanf("%d", &key);
    int result = binarySearch(ar, key, 0, n-1);

    if (result != -1){
        printf("The element is present in %d position", result+1);
    }else{
        printf("The element is not present in array.");
    }
}