#include <stdio.h>

void swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int a[], int lb, int ub) {
	int start = lb + 1;
	int end = ub;
	int pivot = a[lb];

	while (start <= end) { 
		while (start <= ub && a[start] < pivot)
			start++;
		while (end >= lb && a[end] > pivot)
			end--;
		if (start < end)
			swap(&a[start], &a[end]);
	}
	swap(&a[lb], &a[end]);
	return end;
}

void quicksort(int a[], int lb, int ub) {
	if (lb < ub) {
		int loc = partition(a, lb, ub);
		quicksort(a, lb, loc - 1);
		quicksort(a, loc + 1, ub);
	}
}

int main() {
	int i, n;
	printf("Enter number of array elements: ");
	scanf("%d", &n);
	int a[n];
	printf("Enter array elements:\n");
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	quicksort(a, 0, n - 1);
	printf("SORTED ARRAY:\n");
	for (i = 0; i < n; i++)
		printf("%d\n", a[i]);

	return 0;
}
