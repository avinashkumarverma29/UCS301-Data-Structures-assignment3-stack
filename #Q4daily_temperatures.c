#include <stdio.h>

#define MAX 100

int main() {
    int temperatures[] = {73, 74, 75, 71, 69, 72, 76, 73};
    int n = sizeof(temperatures) / sizeof(temperatures[0]);

    int answer[MAX] = {0};
    int stack[MAX];
    int top = -1;

    for (int i = 0; i < n; i++) {
        while (top >= 0 && temperatures[i] > temperatures[stack[top]]) {
            int previousDay = stack[top--];
            answer[previousDay] = i - previousDay;
        }

        stack[++top] = i;
    }

    printf("Input: [");
    for (int i = 0; i < n; i++) {
        printf("%d", temperatures[i]);
        if (i < n - 1)
            printf(", ");
    }
    printf("]\n");

    printf("Output: [");
    for (int i = 0; i < n; i++) {
        printf("%d", answer[i]);
        if (i < n - 1)
            printf(", ");
    }
    printf("]\n");

    return 0;
}
