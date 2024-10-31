#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *Llink;
    struct node *Rlink;
};

typedef struct node Node;
Node *head = NULL;
Node *temp, *ptr;
int item;

void InsertFront() {
    Node *new = (Node *)malloc(sizeof(Node));
    printf("Enter the data to insert at the front: ");
    scanf("%d", &item);
    new->data = item;
    new->Llink = NULL;
    new->Rlink = head;

    if (head != NULL) {
        head->Llink = new;
    }
    head = new;
    printf("%d is inserted at the front\n", item);
}

void InsertEnd() {
    Node *new = (Node *)malloc(sizeof(Node));
    printf("Enter the data to insert at the end: ");
    scanf("%d", &item);
    new->data = item;
    new->Llink = NULL;
    new->Rlink = NULL;

    if (head == NULL) {
        head = new;
    } else {
        ptr = head;
        while (ptr->Rlink != NULL) {
            ptr = ptr->Rlink;
        }
        ptr->Rlink = new;
        new->Llink = ptr;
    }
    printf("%d is inserted at the end\n", item);
}

void InsertSpecific(int key) {
    if (head == NULL) {
        printf("List is empty, insertion not possible\n");
        return;
    }

    ptr = head;
    while (ptr != NULL && ptr->data != key) {
        ptr = ptr->Rlink;
    }

    if (ptr != NULL) {
        Node *new = (Node *)malloc(sizeof(Node));
        printf("Enter the data to insert after %d: ", key);
        scanf("%d", &item);
        new->data = item;
        new->Llink = ptr;
        new->Rlink = ptr->Rlink;
        ptr->Rlink = new;

        if (new->Rlink != NULL) {  //insertion was not done after the last node
            new->Rlink->Llink = new;
        }

        printf("%d is inserted after %d\n", item, key);
    } else {
        printf("Element not found\n");
    }
}

void DeleteFront() {
    if (head == NULL) {
        printf("List is empty, deletion not possible\n");
        return;
    }

    temp = head;
    printf("%d is deleted from the front\n", head->data);
    head = head->Rlink;

    if (head != NULL) {
        head->Llink = NULL;
    }
    free(temp);
}

void DeleteEnd() {
    if (head == NULL) {
        printf("List is empty, deletion not possible\n");
        return;
    }

    if (head->Rlink == NULL) {
        temp = head;
        printf("%d is deleted from the end\n", head->data);
        free(temp);
        head = NULL;
    } 
    else {
        ptr = head;
        while (ptr->Rlink != NULL) {
            ptr = ptr->Rlink;
        }
        printf("%d is deleted from the end\n", ptr->data);
        ptr->Llink->Rlink = NULL;
        free(ptr);
    }
}

void DeleteSpecific(int key) {
    if (head == NULL) {
        printf("List is empty, deletion not possible\n");
        return;
    }

    ptr = head;
    while (ptr != NULL && ptr->data != key) {
        ptr = ptr->Rlink;
    }

    if (ptr == NULL) {
        printf("Key not found\n");
        return;
    }

    if (ptr->Llink == NULL) {
        head = ptr->Rlink;
        if (head != NULL) {
            head->Llink = NULL;
        }
    } 
    else {
        ptr->Llink->Rlink = ptr->Rlink;
        if (ptr->Rlink != NULL) {
            ptr->Rlink->Llink = ptr->Llink;
        }
    }
    printf("%d is deleted\n", ptr->data);
    free(ptr);
}

void Display() {
    if (head == NULL) {
        printf("List is empty\n");
    } 
    else {
        printf("List elements :\n");
        ptr = head;
        while (ptr != NULL) {
            printf("%d -> ", ptr->data);
            ptr = ptr->Rlink;
        }
        printf("NULL\n");
    }
}

int main() {
    int choice, key, count = 0;

    do {
        if (count != 0) {
            printf("\n");
        }

        printf("1. Insert at Front\n2. Insert at End\n3. Insert After Specific Element\n4. Delete from Front\n5. Delete from End\n6. Delete Specific Element\n7. Display\n8. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                InsertFront();
                count++;
                break;
            case 2:
                InsertEnd();
                count++;
                break;
            case 3:
                printf("Enter the element after which you want to insert: ");
                scanf("%d", &key);
                InsertSpecific(key);
                count++;
                break;
            case 4:
                DeleteFront();
                count++;
                break;
            case 5:
                DeleteEnd();
                count++;
                break;
            case 6:
                printf("Enter the element to delete: ");
                scanf("%d", &key);
                DeleteSpecific(key);
                count++;
                break;
            case 7:
                Display();
                count++;
                break;
            case 8:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 8);

    return 0;
}
