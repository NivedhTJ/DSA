#include<stdio.h>

void print(int a[], int n) {
	printf("SORTED ARRAY:\n");
	for(int i = 0; i < n; i++)
		printf("%d \n", a[i]);
}

void Insertion(int a[], int n) {
	int temp, j;
	for(int i = 1; i < n; i++) {
		temp = a[i];
		j = i - 1;
		while(j >= 0 && a[j] > temp) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = temp;
	}
	print(a, n);
}

int main() {
	int n;
	printf("Enter number of array elements: ");
	scanf("%d", &n);
	int a[n];
	printf("Enter array elements:\n");
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	Insertion(a, n);
	return 0;
}
