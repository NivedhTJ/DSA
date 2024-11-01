#include<stdio.h>

void print(int a[], int n)
{
    printf("SORTED ARRAY:\n");
    for(int i=0; i<n; i++)
        printf("%d \n", a[i]);
}

void Merge(int a[], int lb, int mid, int ub)
{
    int i = lb;
    int j = mid + 1;
    int k = 0;
    int b[ub - lb + 1];

    while(i <= mid && j <= ub)
    {
        if(a[i] < a[j])
        {
            b[k++] = a[i++];
        }
        else
        {
            b[k++] = a[j++];
        }
    }

    while(i <= mid)
    {
        b[k++] = a[i++];
    }

    while(j <= ub)
    {
        b[k++] = a[j++];
    }

    for(i = lb, k = 0; i <= ub; i++, k++)
    {
        a[i] = b[k];
    }
}

void MergeSort(int a[], int lb, int ub)
{
    int mid;
    if(lb < ub)
    {
        mid = (lb + ub) / 2;
        MergeSort(a, lb, mid);
        MergeSort(a, mid + 1, ub);
        Merge(a, lb, mid, ub);
    }
}

int main() {
    int n;
    printf("Enter the number of array elements: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter array elements:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    MergeSort(a, 0, n - 1);
    print(a, n);

    return 0;
}
