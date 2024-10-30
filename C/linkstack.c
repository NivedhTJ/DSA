#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node Node;
Node *top = NULL;
Node *ptr, *temp;
int item;

void Push(){
    Node *new = (Node*)malloc(sizeof(Node));
    printf("Enter data to push onto stack: ");
    scanf("%d", &item);
    new->data = item;
    new->next = top;
    top = new;
    printf("%d pushed onto stack\n", item);
}

void Pop(){
    if (top == NULL) {
        printf("Stack is empty\n");
    } else {
        temp = top;
        printf("%d popped from stack\n", top->data);
        top = top->next;
        free(temp);
    }
}

void Display(){
    if (top == NULL) {
        printf("Stack is empty\n");
    } else {
        ptr = top;
        printf("Stack elements:\n");
        while (ptr != NULL) {
            printf("%d\n", ptr->data);
            ptr = ptr->next;
        }
        
    }
}

int main() {
    int ch = 0;

    while (ch != 4) {
        printf("\nEnter selection\n1. Push\n2. Pop\n3. Display Stack\n4. Exit\n");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            Push();
            break;

        case 2:
            Pop();
            break;

        case 3:
            Display();
            break;

        case 4:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid Input\n");
        }
    }

    return 0;
}
