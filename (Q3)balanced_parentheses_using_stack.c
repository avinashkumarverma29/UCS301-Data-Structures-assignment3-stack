#include <stdio.h>
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

int isMatchingPair(char open, char close)
{
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

int isBalanced(char expression[])
{
    int i;
    char ch;

    for (i = 0; expression[i] != '\0'; i++)
    {
        ch = expression[i];

        if (ch == '(' || ch == '{' || ch == '[')
        {
            push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (top == -1)
            {
                return 0;
            }

            if (!isMatchingPair(pop(), ch))
            {
                return 0;
            }
        }
    }

    return top == -1;
}

int main()
{
    char expression[MAX];

    printf("Enter an expression: ");
    fgets(expression, MAX, stdin);

    if (isBalanced(expression))
    {
        printf("The expression has balanced parentheses.\n");
    }
    else
    {
        printf("The expression does not have balanced parentheses.\n");
    }

    return 0;
}
