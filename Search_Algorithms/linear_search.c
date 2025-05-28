#include <stdio.h>
void main()
{
    int key, flag = 0, n, i;

    printf("Enter the Size of Array: ");
    scanf("%d", &n);
    int a[n];

    printf("Enter Array Elements:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter the element to be searched:");
    scanf("%d", &key);

    //Linear Search
    for (i = 0; i < n; i++)
    {
        //Array elements are traversed one by one till the key is found
        if (a[i] == key)
        {
            printf("Element found at position %d", i + 1);
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        printf("Element not found");
    }
}