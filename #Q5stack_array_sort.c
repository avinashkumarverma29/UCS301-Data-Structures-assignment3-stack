#include <stdio.h>

#define MAX 100

int canBeSorted(int A[], int N) {
    int S[MAX];
    int sorted[MAX];
    int top = -1;
    int nextExpected = 0;

    // Copy A into sorted array
    for (int i = 0; i < N; i++) {
        sorted[i] = A[i];
    }

    // Sort the copy in ascending order
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (sorted[i] > sorted[j]) {
                int temp = sorted[i];
                sorted[i] = sorted[j];
                sorted[j] = temp;
            }
        }
    }

    // Push elements into stack and pop when possible
    for (int i = 0; i < N; i++) {
        S[++top] = A[i];

        while (top >= 0 && S[top] == sorted[nextExpected]) {
            top--;
            nextExpected++;
        }
    }

    return top == -1;
}

int main() {
    int A[] = {2, 4, 1243, 4, 1342};
    int N = sizeof(A) / sizeof(A[0]);

    printf("Input: [2, 4, 1243, 4, 1342]\n");

    if (canBeSorted(A, N))
        printf("Output: Yes\n");
    else
        printf("Output: No\n");

    return 0;
}
