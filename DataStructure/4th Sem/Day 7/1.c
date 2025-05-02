#include <stdio.h>
#include <limits.h>

void printOptimalParens(int s[][100], int i, int j) {
    if (i == j)
        printf("A%d", i);
    else {
        printf("(");
        printOptimalParens(s, i, s[i][j]);
        printOptimalParens(s, s[i][j] + 1, j);
        printf(")");
    }
}

void matrixChainOrder(int p[], int n) {
    int m[100][100];
    int s[100][100];

    for (int i = 1; i < n; i++)
        m[i][i] = 0;

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

    printf("\nM matrix (upper triangle including diagonal):\n");
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (j >= i)
                printf("\t%d ", m[i][j]);
            else
                printf("\t");
        }
        printf("\n");
    }

    printf("\nS matrix (upper triangle excluding diagonal):\n");
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (j > i)
                printf("\t%d ", s[i][j]);
            else
                printf("\t");
        }
        printf("\n");
    }

    printf("\nOptimal parenthesization: ");
    printOptimalParens(s, 1, n - 1);
    printf("\n");
    printf("Minimum number of multiplications is %d\n", m[1][n - 1]);
}

int main() {
    int size;
    printf("Enter the number of matrices: ");
    scanf("%d", &size);
    int arr[size+1];
    printf("Enter the dimensions of the matrices: ");
    for (int i = 0; i < size+1; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Matrix dimensions: ");
    for (int i = 0; i < size+1; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    matrixChainOrder(arr, size+1);

    return 0;
}
