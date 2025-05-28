#include <stdio.h>

int front = -1, rear = -1;
int item;

//adds an element to rear of queue
void enqueue(int queue[], int size)
{
    if (rear == size - 1)
    {
        printf("Queue Overflow\n\n");
    }
    else
    {
        printf("Enter item : ");
        scanf("%d", &item);
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = item;
        printf("%d is inserted into the queue\n\n", item);
    }
}

//deletes the rear element from queue
void dequeue(int queue[])
{
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow\n\n");
    }
    else
    {
        printf("%d is deleted from queue\n\n", queue[front]);
        front++;
    }
}

//displays the entire queue
void display(int queue[])
{
    if (front == -1 || front > rear)
    {
        printf("Empty Queue\n\n");
    }
    else
    {
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n\n");
    }
}

//returns the front element of the queue
void peek(int queue[])
{
    if (front == -1 || front > rear)
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
            dequeue(queue);
            break;

        case 3:
            display(queue);
            break;

        case 4:
            peek(queue);
            break;

        case 5:
            printf("Exiting\n");
            return 0;

        default:
            printf("Invalid choice\n");
        }
    }
}
