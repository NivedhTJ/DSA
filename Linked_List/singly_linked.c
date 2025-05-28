#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *head = NULL;

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

    while (ch != 4)
    {
        printf("1.Insert at End 2.Delete by Value 3.Display 4.Exit");
        printf("\nEnter choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            insert_end();
            break;

        case 2:
            delete_by_value();
            break;

        case 3:
            display();
            break;

        case 4:
            printf("Exiting\n");
            return 0;

        default:
            printf("Invalid choice\n");
        }
    }
}
