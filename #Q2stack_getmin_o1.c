#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int top;
    int min;
} Stack;

void init(Stack *s) {
    s->top = -1;
    s->min = 0;
}

void push(Stack *s, int x) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }

    if (s->top == -1) {
        s->data[++s->top] = x;
        s->min = x;
    } else if (x >= s->min) {
        s->data[++s->top] = x;
    } else {
        // Encode the new minimum in the stack
        s->data[++s->top] = 2 * x - s->min;
        s->min = x;
    }
}

int pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }

    int value = s->data[s->top--];

    if (value < s->min) {
        int actual = s->min;
        s->min = 2 * s->min - value;
        return actual;
    }

    return value;
}

int peek(Stack *s) {
    if (s->top == -1) {
        printf("Stack is empty\n");
        return -1;
    }

    int value = s->data[s->top];

    if (value < s->min)
        return s->min;

    return value;
}

int getMin(Stack *s) {
    if (s->top == -1) {
        printf("Stack is empty\n");
        return -1;
    }

    return s->min;
}

int main() {
    Stack s;
    init(&s);

    // Input:
    // push(2), push(3), peek(), pop(), getMin(), push(1), getMin()

    push(&s, 2);
    push(&s, 3);

    printf("Peek: %d\n", peek(&s));
    printf("Pop: %d\n", pop(&s));
    printf("GetMin: %d\n", getMin(&s));

    push(&s, 1);
    printf("GetMin: %d\n", getMin(&s));

    /*
    Output:
    Peek: 3
    Pop: 3
    GetMin: 2
    GetMin: 1

    getMin() works in O(1) time and uses O(1) extra space.
    */

    return 0;
}
