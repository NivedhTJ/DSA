#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *front = NULL;
Node *rear = NULL;

//adds element to rear position after traversal through list
void enqueue()
{
    int item;
    printf("Enter item : ");
    scanf("%d", &item);

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = item;
    newNode->next = NULL;

    if (rear == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }

    printf("%d is inserted into the queue\n\n", item);
}

//removes element from front position
void dequeue()
{
    if (front == NULL)
    {
        printf("Queue Underflow\n\n");
    }
    else
    {
        Node *temp = front;
        printf("%d is deleted from queue\n\n", temp->data);
        front = front->next;

        if (front == NULL)
        {
            rear = NULL;
        }

        free(temp);
    }
}

//displays the queue 
void display()
{
    if (front == NULL)
    {
        printf("Empty Queue\n\n");
    }
    else
    {
        Node *temp = front;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n\n");
    }
}

//displays the front element of queue
void peek()
{
    if (front == NULL)
    {
        printf("Empty Queue\n\n");
    }
    else
    {
        printf("%d\n\n", front->data);
    }
}

int main()
{
    int ch = 0;

    while (ch != 5)
    {
        printf("1.Insertion 2.Deletion 3.Display 4.Peek 5.Exit");
        printf("\nEnter choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            enqueue();
            break;

        case 2:
            dequeue();
            break;

        case 3:
            display();
            break;

        case 4:
            peek();
            break;

        case 5:
            printf("Exiting\n");
            return 0;

        default:
            printf("Invalid choice\n");
        }
    }
}
