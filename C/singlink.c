#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node Node;
Node *head = NULL;
Node *ptr, *temp, *prev, *curr;
int item;

void InsertFront(){
    Node *new = (Node*)malloc(sizeof(Node));
    printf("Enter data of node ");
    scanf("%d", &item);
    new->data = item;
    new->next = head;
    head = new;
}

void InsertEnd(){
    Node *new = (Node*)malloc(sizeof(Node));
    printf("Enter data of node ");
    scanf("%d", &item);
    new->data = item;
    new->next = NULL;
    if (head == NULL) {
        head = new;
    } else {
        ptr = head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = new;
    }
}

void InsertSpecific(int key){
    Node *new = (Node*)malloc(sizeof(Node));
    printf("Enter data of node ");
    scanf("%d", &item);
    new->data = item;
    new->next = NULL;
    if (head == NULL) {
        printf("Insertion not possible as list is empty");
    } else {
        prev = head;
        ptr = head;  // Initialize ptr
        while (ptr->data != key && ptr->next != NULL) {
            ptr = ptr->next;
        }
        if (ptr->data == key) {
            new->next = ptr->next;
            ptr->next = new;
        } else {
            printf("Element not found");
        }
    }
}

void DeleteFront(){
    if (head == NULL) {
        printf("List is empty");
    } else {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void DeleteEnd(){
    if (head == NULL) {
        printf("List is empty");
    } else if (head->next == NULL) { // Special case: only one node
        free(head);
        head = NULL;
    } else {
        prev = head;
        curr = head->next;
        while (curr->next != NULL) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = NULL;
        free(curr);
    }
}

void DeleteSpecific(int key){
    if (head == NULL) {
        printf("List is empty");
    } else if (head->data == key) { 
        temp = head;
        head = head->next;
        free(temp);
    } else {
        prev = head;
        curr = head->next;
        while (curr != NULL && curr->data != key) {
            prev = curr;
            curr = curr->next;
        }
        if (curr != NULL && curr->data == key) {
            prev->next = curr->next;
            free(curr);
        } else {
            printf("Element not found");
        }
    }
}

void main() {
    int ch = 0, key;

    while (ch != 8) {
        printf("\nEnter selection\n1. Insert at front\n2. Insert at end\n3. Insert at specific node\n4. Delete at front\n5. Delete at end\n6. Delete at specific node\n7. Display\n8. Exit\n");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            InsertFront();
            break;

        case 2:
            InsertEnd();
            break;

        case 3:
            printf("Enter key: ");
            scanf("%d", &key);
            InsertSpecific(key);
            break;

        case 4:
            DeleteFront();
            break;

        case 5:
            DeleteEnd();
            break;

        case 6:
            printf("Enter key: ");
            scanf("%d", &key);
            DeleteSpecific(key);
            break;

        case 7:
            if (head == NULL) {
                printf("List is Empty");
            } else {
                ptr = head;
                while (ptr != NULL) {
                    printf("%d -> ", ptr->data);
                    ptr = ptr->next;
                }
                printf("NULL\n");
            }
            break;

        case 8:
            printf("Exiting...");
            break;

        default:
            printf("Invalid Input");
        }
    }
}
