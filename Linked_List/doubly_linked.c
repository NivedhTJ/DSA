#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
} Node;

Node *head = NULL;

//inserts element at the beginning of the list
void insert_begin()
{
    int item;
    printf("Enter item : ");
    scanf("%d", &item);

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = item;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
        head->prev = newNode;

    head = newNode;

    printf("%d is inserted at the beginning\n\n", item);
}

//inserts element at the end of the list
void insert_end()
{
    int item;
    printf("Enter item : ");
    scanf("%d", &item);

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = item;
    newNode->next = NULL;

    if (head == NULL)
    {
        newNode->prev = NULL;
        head = newNode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
    }

    printf("%d is inserted at the end\n\n", item);
}

//inserts element after a value in the list
void insert_after_value()
{
    if (head == NULL)
    {
        printf("List is empty\n\n");
        return;
    }

    int target, item;
    printf("Enter the value after which to insert : ");
    scanf("%d", &target);
    printf("Enter the item to insert : ");
    scanf("%d", &item);

    Node *temp = head;

    while (temp != NULL && temp->data != target)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("%d not found in the list\n\n", target);
        return;
    }

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = item;

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;

    printf("%d inserted after %d\n\n", item, target);
}

//deletes the head(first element) of the list
void delete_begin()
{
    if (head == NULL)
    {
        printf("List Underflow\n\n");
        return;
    }

    Node *temp = head;
    printf("%d is deleted from beginning\n\n", temp->data);
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    free(temp);
}

//deletes the last element of the list
void delete_end()
{
    if (head == NULL)
    {
        printf("List Underflow\n\n");
        return;
    }

    if (head->next == NULL)
    {
        printf("%d is deleted from end\n\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    printf("%d is deleted from end\n\n", temp->data);
    temp->prev->next = NULL;
    free(temp);
}

//deletes a specific value from a list
void delete_by_value()
{
    if (head == NULL)
    {
        printf("List Underflow\n\n");
        return;
    }

    int value;
    printf("Enter value to delete : ");
    scanf("%d", &value);

    Node *temp = head;

    if (temp->data == value)
    {
        head = temp->next;
        if (head != NULL)
            head->prev = NULL;

        free(temp);
        printf("%d is deleted from the list\n\n", value);
        return;
    }

    while (temp != NULL && temp->data != value)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("%d not found in the list\n\n", value);
        return;
    }

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    free(temp);
    printf("%d is deleted from the list\n\n", value);
}

//displays the entire lists
void display()
{
    if (head == NULL)
    {
        printf("Empty List\n\n");
        return;
    }

    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n\n");
}

int main()
{
    int ch = 0;

    while (ch != 9)
    {
        printf("1.Insert at Beginning 2.Insert at End 3.Insert After Value 4.Delete from Beginning 5.Delete from End 6.Delete by Value 7.Display 8.Exit");
        printf("\nEnter choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            insert_begin();
            break;

        case 2:
            insert_end();
            break;

        case 3:
            insert_after_value();
            break;

        case 4:
            delete_begin();
            break;

        case 5:
            delete_end();
            break;

        case 6:
            delete_by_value();
            break;

        case 7:
            display();
            break;

        case 8:
            printf("Exiting\n");
            return 0;

        default:
            printf("Invalid choice\n");
        }
    }
}
