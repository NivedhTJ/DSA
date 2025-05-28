#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *head = NULL;

void insert_front()
{
    int item;
    printf("Enter item : ");
    scanf("%d", &item);

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = item;
    newNode->next = head;
    head = newNode;

    printf("%d is inserted at the front\n\n", item);
}

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
        head = newNode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    printf("%d is inserted at the end\n\n", item);
}

void delete_front()
{
    if (head == NULL)
    {
        printf("List Underflow\n\n");
        return;
    }

    Node *temp = head;
    head = head->next;
    printf("%d is deleted from the front\n\n", temp->data);
    free(temp);
}

void delete_end()
{
    if (head == NULL)
    {
        printf("List Underflow\n\n");
        return;
    }

    if (head->next == NULL)
    {
        printf("%d is deleted from the end\n\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    Node *temp = head;
    Node *prev = NULL;

    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    printf("%d is deleted from the end\n\n", temp->data);
    free(temp);
}

void delete_by_value()
{
    int value;
    printf("Enter value to delete : ");
    scanf("%d", &value);

    if (head == NULL)
    {
        printf("List Underflow\n\n");
        return;
    }

    if (head->data == value)
    {
        Node *temp = head;
        head = head->next;
        free(temp);
        printf("%d is deleted from the list\n\n", value);
        return;
    }

    Node *curr = head->next;
    Node *prev = head;

    while (curr != NULL && curr->data != value)
    {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL)
    {
        printf("%d not found in the list\n\n", value);
    }
    else
    {
        prev->next = curr->next;
        free(curr);
        printf("%d is deleted from the list\n\n", value);
    }
}

void display()
{
    if (head == NULL)
    {
        printf("Empty List\n\n");
    }
    else
    {
        Node *temp = head;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n\n");
    }
}

int main()
{
    int ch = 0;

    while (ch != 6)
    {
        printf("1.Insert at Front 2.Insert at End 3.Delete at Front 4.Delete at End 5.Delete by Value 6.Display 7.Exit");
        printf("\nEnter choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            insert_front();
            break;

        case 2:
            insert_end();
            break;

        case 3:
            delete_front();
            break;

        case 4:
            delete_end();
            break;

        case 5:
            delete_by_value();
            break;

        case 6:
            display();
            break;

        case 7:
            printf("Exiting\n");
            return 0;

        default:
            printf("Invalid choice\n");
        }
    }
}
