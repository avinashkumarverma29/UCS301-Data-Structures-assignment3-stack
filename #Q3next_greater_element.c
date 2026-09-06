#include <stdio.h>

#define MAX 100

int main() {
    int arr[MAX], result[MAX], stack[MAX];
    int n, top = -1;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        result[i] = -1;
    }

    // Find Next Greater Element using a stack
    for (int i = 0; i < n; i++) {
        while (top >= 0 && arr[i] > arr[stack[top]]) {
            result[stack[top]] = arr[i];
            top--;
        }
        stack[++top] = i;
    }

    printf("Output: [");
    for (int i = 0; i < n; i++) {
        printf("%d", result[i]);
        if (i < n - 1)
            printf(", ");
    }
    printf("]\n");

    /*
    Sample Input:
    4
    1 3 2 4

    Sample Output:
    Output: [3, 4, 4, -1]

    Time Complexity: O(n)
    Space Complexity: O(n)
    */

    return 0;
}
