#include <stdio.h>
#define n 10

int queue[n];
int f = -1, r = -1;

int isempty() {
    if (f == -1)
        return 1;
    else 
        return 0;
}

void enqueue(int item) {
    if (isempty() == 1) {
        f = r = 0;
        queue[r] = item;
    } 
    else if (f == (r + 1) % n) {
        printf("Queue is full\n");
    }
    else {
        r = (r + 1) % n;
        queue[r] = item;
    }
}

int dequeue() {
    if (isempty() == 1) {
        printf("Queue is empty\n");
        return -1; 
    } 
    else {
        int item = queue[f];
        if (f == r) {
            f = r = -1;
        } 
        else {
            f = (f + 1) % n;
        }
        return item;
    }
}

void display() {
    if (isempty() == 1) {
        printf("The queue is empty\n");
    } 
    else {
        printf("Queue elements:\n");
        for (int i = f; i != r; i = (i + 1) % n) {
            printf("%d ", queue[i]);
        }
        printf("%d\n", queue[r]); 
    }
}

int main() {
    int choice, ele;
    do {
        printf("\n1. Enqueue \n2. Dequeue \n3. Display \n4. Quit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d", &ele);
                enqueue(ele);
                break;
            case 2:
                if (isempty() == 1)
                    printf("Queue is empty\n");
                else
                    printf("The number deleted is %d\n", dequeue());
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 4);
}
