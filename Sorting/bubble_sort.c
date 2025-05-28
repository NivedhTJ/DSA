#include <stdio.h>
void main()
{
    int n, temp;
    printf("Enter the num of elements: ");
    scanf("%d", &n);
    int a[n];

    printf("Enter Array Elements:");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Array before sorting: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    //Bubble sort
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    printf("\nArray after sorting: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}