#include <stdio.h>
int pos = 0;
int item;

void push(int stack[], int size)
{
    if (pos < size)
    {
        printf("Enter item : ");
        scanf("%d", &item);
        printf("%d is inserted into the stack\n\n", item);
        stack[pos] = item;
        pos = pos + 1;
    }
    else
    {
        printf("Stack Overflow\n\n");
    }
}

void pop(int stack[])
{
    if (pos != 0)
    {
        printf("%d is popped from stack\n\n", stack[pos - 1]);
        pos--;
    }
    else
    {
        printf("Stack Underflow\n\n");
    }
}

void display(int stack[])
{
    if (pos != 0)
    {
        for (int i = 0; i < pos; i++)
        {
            printf("%d", stack[i]);
        }
        printf("\n\n");
    }
    else
    {
        printf("Empty Stack\n\n");
    }
}

void peek(int stack[])
{
    if (pos != 0)
    {
        printf("%d", stack[pos - 1]);
        printf("\n\n");
    }
    else
    {
        printf("Empty stack\n\n");
    }
}

int main()
{
    int ch = 0, size;
    printf("Enter the size of the stack :");
    scanf("%d", &size);
    int stack[size];

    while (ch != 5)
    {
        printf("1.Insertion 2.Deletion 3.Display 4.Peek 5.Exit");
        printf("\nEnter choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            push(stack, size);
            break;

        case 2:
            pop(stack);
            break;

        case 3:
            display(stack);
            break;

        case 4:
            peek(stack);
            break;

        case 5:
            printf("Exiting\n");
            return 0;
            break;

        default:
            printf("Invalid choice\n");
        }
    }
}