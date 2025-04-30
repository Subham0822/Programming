#include <stdio.h>
#include <limits.h>

void matrixChainOrder(int p[], int n) {
    int m[n][n];
    int s[n][n];
    
    // Initialize m[i][i] = 0
    for (int i = 1; i < n; i++)
        m[i][i] = 0;
    
    // L is chain length
    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    
    printf("Minimum number of multiplications is %d\n", m[1][n-1]);
}

int main() {
    // Given sequence of dimensions: <13, 5, 89, 3, 34>
    int arr[] = {13, 5, 89, 3, 34};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    printf("Matrix dimensions: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    matrixChainOrder(arr, size);
    
    return 0;
}
