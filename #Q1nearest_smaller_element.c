#include <stdio.h>

#define MAX 100

int main() {
    int A[MAX], result[MAX], stack[MAX];
    int n, top = -1;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    // Find nearest smaller element to the left using a stack
    for (int i = 0; i < n; i++) {
        while (top >= 0 && stack[top] >= A[i]) {
            top--;
        }

        if (top == -1)
            result[i] = -1;
        else
            result[i] = stack[top];

        stack[++top] = A[i];
    }

    printf("Output: [");
    for (int i = 0; i < n; i++) {
        printf("%d", result[i]);
        if (i < n - 1)
            printf(", ");
    }
    printf("]\n");

    return 0;
}

/*
Sample Input:
5
4 5 2 10 8

Sample Output:
Output: [-1, 4, -1, 2, 2]
*/
