#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch)
{
    if (top < MAX - 1)
    {
        stack[++top] = ch;
    }
}

char pop()
{
    if (top == -1)
    {
        return '\0';
    }

    return stack[top--];
}

char peek()
{
    if (top == -1)
    {
        return '\0';
    }

    return stack[top];
}

int precedence(char ch)
{
    if (ch == '^')
        return 3;
    if (ch == '*' || ch == '/')
        return 2;
    if (ch == '+' || ch == '-')
        return 1;

    return 0;
}

int main()
{
    char infix[MAX], postfix[MAX];
    int i, j = 0;
    char ch;

    printf("Enter an infix expression: ");
    fgets(infix, MAX, stdin);

    for (i = 0; infix[i] != '\0'; i++)
    {
        ch = infix[i];

        if (ch == '\n')
            break;

        // If operand, add it directly to postfix
        if (isalnum(ch))
        {
            postfix[j++] = ch;
        }
        // If opening parenthesis, push it
        else if (ch == '(')
        {
            push(ch);
        }
        // If closing parenthesis, pop until opening parenthesis
        else if (ch == ')')
        {
            while (top != -1 && peek() != '(')
            {
                postfix[j++] = pop();
            }

            if (top != -1 && peek() == '(')
            {
                pop();
            }
        }
        // If operator, pop operators with higher or equal precedence
        else if (ch == '+' || ch == '-' || ch == '*' ||
                 ch == '/' || ch == '^')
        {
            while (top != -1 && peek() != '(' &&
                   precedence(peek()) >= precedence(ch))
            {
                postfix[j++] = pop();
            }

            push(ch);
        }
    }

    // Pop remaining operators
    while (top != -1)
    {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
