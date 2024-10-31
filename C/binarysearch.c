#include <stdio.h>

void BinarySearch(int a[], int n, int key) {
    int l = 0, u = n - 1, mid, flag = 0;
    
    while (l <= u) {
        mid = (l + u) / 2;
        if (a[mid] == key) {
            printf("Element found at position %d\n",mid);
            flag = 1;
            break;
        } 
        else if (a[mid] < key) {
            l = mid + 1;
        } 
        else {
            u = mid - 1;
        }
    }
    
    if (flag != 1) {
        printf("Element not found\n");
    }
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("array elements after sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\n",arr[i]);
    }
}

int main() {
    int n, key;
    
    printf("Enter the number of array elements: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    bubbleSort(a, n);
    
    printf("Enter element to be searched: ");
    scanf("%d", &key);
    
    BinarySearch(a, n, key);
    
    return 0; 
}
