#include <stdio.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value)
{
    if (top < MAX - 1)
    {
        stack[++top] = value;
    }
}

int pop()
{
    if (top == -1)
    {
        return 0;
    }

    return stack[top--];
}

int main()
{
    char postfix[MAX];
    int i;
    int operand1, operand2, result;

    printf("Enter a postfix expression: ");
    scanf("%99s", postfix);

    for (i = 0; postfix[i] != '\0'; i++)
    {
        // If character is an operand, push it onto the stack
        if (isdigit(postfix[i]))
        {
            push(postfix[i] - '0');
        }
        // If character is an operator, perform the operation
        else if (postfix[i] == '+' || postfix[i] == '-' ||
                 postfix[i] == '*' || postfix[i] == '/')
        {
            operand2 = pop();
            operand1 = pop();

            switch (postfix[i])
            {
                case '+':
                    result = operand1 + operand2;
                    break;

                case '-':
                    result = operand1 - operand2;
                    break;

                case '*':
                    result = operand1 * operand2;
                    break;

                case '/':
                    if (operand2 == 0)
                    {
                        printf("Error: Division by zero.\n");
                        return 1;
                    }
                    result = operand1 / operand2;
                    break;
            }

            push(result);
        }
        else
        {
            printf("Invalid character in expression.\n");
            return 1;
        }
    }

    if (top == 0)
    {
        printf("Result = %d\n", pop());
    }
    else
    {
        printf("Invalid postfix expression.\n");
    }

    return 0;
}
