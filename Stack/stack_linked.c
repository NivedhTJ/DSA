#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *top = NULL;

//element pushed(inserted) to top of the stack as per FIFO
void push()
{
    int item;
    printf("Enter item : ");
    scanf("%d", &item);

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = item;
    newNode->next = top;
    top = newNode;

    printf("%d is inserted into the stack\n\n", item);
}

//elements popped(deleted)from the top of the stack as per FIFO
void pop()
{
    if (top == NULL)
    {
        printf("Stack Underflow\n\n");
    }
    else
    {
        Node *temp = top;
        printf("%d is popped from stack\n\n", top->data);
        top = top->next;
        free(temp);
    }
}

//functions to display stack through traversal of linked list
void display()
{
    if (top == NULL)
    {
        printf("Empty Stack\n\n");
    }
    else
    {
        Node *temp = top;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n\n");
    }
}

//displays the topmost element of stack
void peek()
{
    if (top == NULL)
    {
        printf("Empty Stack\n\n");
    }
    else
    {
        printf("%d\n\n", top->data);
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
            push();
            break;

        case 2:
            pop();
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
