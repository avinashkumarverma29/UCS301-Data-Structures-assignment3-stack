#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

int isEmpty()
{
    return top == -1;
}

int isFull()
{
    return top == MAX - 1;
}

void push()
{
    int value;

    if (isFull())
    {
        printf("Stack Overflow! Stack is full.\n");
        return;
    }

    printf("Enter element to push: ");
    scanf("%d", &value);

    stack[++top] = value;
    printf("%d pushed into the stack.\n", value);
}

void pop()
{
    if (isEmpty())
    {
        printf("Stack Underflow! Stack is empty.\n");
        return;
    }

    printf("%d popped from the stack.\n", stack[top--]);
}

void peek()
{
    if (isEmpty())
    {
        printf("Stack is empty.\n");
        return;
    }

    printf("Top element is: %d\n", stack[top]);
}

void display()
{
    int i;

    if (isEmpty())
    {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack elements are:\n");

    for (i = top; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }
}

int main()
{
    int choice;

    do
    {
        printf("\n===== STACK MENU =====\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Is Empty\n");
        printf("4. Is Full\n");
        printf("5. Display\n");
        printf("6. Peek\n");
        printf("7. Exit\n");
        printf("======================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                if (isEmpty())
                    printf("Stack is Empty.\n");
                else
                    printf("Stack is Not Empty.\n");
                break;

            case 4:
                if (isFull())
                    printf("Stack is Full.\n");
                else
                    printf("Stack is Not Full.\n");
                break;

            case 5:
                display();
                break;

            case 6:
                peek();
                break;

            case 7:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 7);

    return 0;
}
