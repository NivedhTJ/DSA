#include <stdio.h>

int front = -1, rear = -1;
int item;

void enqueue(int queue[], int size)
{
    if ((front == 0 && rear == size - 1) || (rear + 1) % size == front)
    {
        printf("Queue Overflow\n\n");
    }
    else
    {
        printf("Enter item : ");
        scanf("%d", &item);
        if (front == -1)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear = (rear + 1) % size;
        }
        queue[rear] = item;
        printf("%d is inserted into the queue\n\n", item);
    }
}

void dequeue(int queue[], int size)
{
    if (front == -1)
    {
        printf("Queue Underflow\n\n");
    }
    else
    {
        printf("%d is deleted from queue\n\n", queue[front]);
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % size;
        }
    }
}

void display(int queue[], int size)
{
    if (front == -1)
    {
        printf("Empty Queue\n\n");
    }
    else
    {
        int i = front;
        printf("Queue elements: ");
        while (1)
        {
            printf("%d ", queue[i]);
            if (i == rear)
                break;
            i = (i + 1) % size;
        }
        printf("\n\n");
    }
}

void peek(int queue[], int size)
{
    if (front == -1)
    {
        printf("Empty Queue\n\n");
    }
    else
    {
        printf("%d\n\n", queue[front]);
    }
}

int main()
{
    int ch = 0, size;
    printf("Enter the size of the queue : ");
    scanf("%d", &size);
    int queue[size];

    while (ch != 5)
    {
        printf("1.Insertion 2.Deletion 3.Display 4.Peek 5.Exit");
        printf("\nEnter choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            enqueue(queue, size);
            break;

        case 2:
            dequeue(queue, size);
            break;

        case 3:
            display(queue, size);
            break;

        case 4:
            peek(queue, size);
            break;

        case 5:
            printf("Exiting\n");
            return 0;

        default:
            printf("Invalid choice\n");
        }
    }
}
