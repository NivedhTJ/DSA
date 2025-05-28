#include <stdio.h>
int main()
{
    int n, i, key, first = 0, last, flag = 0, mid;

    printf("Enter num of Elements: ");
    scanf("%d", &n);
    int a[n];
    last = n - 1;

    printf("Enter array elements:");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter the element to be searched:");
    scanf("%d", &key);

    //Binary Search
    while (first <= last)
    {
        mid = (first + last) / 2;
        if (a[mid] == key)
        {
            printf("Element found at %d", mid + 1);
            flag = 1;
            break;
        }
        else if (a[mid] < key)
        {
            first = mid + 1;
        }
        else
        {
            last = mid - 1;
        }
    }

    if (flag == 0)
    {
        printf("Searched Element Not Found \n");
    }
}