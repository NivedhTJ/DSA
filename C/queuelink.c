#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node Node;
Node *front = NULL; 
Node *rear = NULL;  
Node *temp, *ptr;
int item;

void Enqueue() {
    Node *new = (Node *)malloc(sizeof(Node));
    printf("Enter the value to enqueue: ");
    scanf("%d", &item);
    new->data = item;
    new->next = NULL;
    
    if (rear == NULL) {  // If the queue is empty
        front = rear = new;
    } else {
        rear->next = new;
        rear = new;
    }
    printf("%d is enqueued into the queue\n", item);
}

void Dequeue() {
    if (front == NULL) {
        printf("Queue underflow\n");
    } else {
        temp = front;
        printf("%d is dequeued from the queue\n", front->data);
        front = front->next;
        free(temp);
    }
}

void Display() {
    if (front == NULL) {
        printf("Queue is empty\n");
    } else {
        ptr = front;
        printf("The queue elements are:\n");
        while (ptr != NULL) {
            printf("%d -> ", ptr->data);
            ptr = ptr->next;
        }
    }
}

int main() {
    int choice, count = 0;

    do {
        if (count != 0) {
            printf("\n");  
        }

        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                Enqueue();
                count++;
                break;
            case 2:
                Dequeue();
                count++;
                break;
            case 3:
                Display();
                count++;
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 4);

    return 0;
}
