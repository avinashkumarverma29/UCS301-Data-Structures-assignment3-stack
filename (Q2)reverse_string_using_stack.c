#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow!\n");
        return;
    }

    stack[++top] = ch;
}

char pop()
{
    if (top == -1)
    {
        return '\0';
    }

    return stack[top--];
}

int main()
{
    char str[MAX];
    int i;

    printf("Enter a string: ");
    scanf("%99s", str);

    // Push each character into the stack
    for (i = 0; i < strlen(str); i++)
    {
        push(str[i]);
    }

    // Pop characters to reverse the string
    printf("Reversed string: ");

    while (top != -1)
    {
        printf("%c", pop());
    }

    printf("\n");

    return 0;
}
