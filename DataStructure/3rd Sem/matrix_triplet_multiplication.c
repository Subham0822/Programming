#include <stdio.h>

int main() {
    int a, b, c, i, j, k, n1 = 0, n2 = 0;

    printf("Enter the number of rows and columns of the first matrix: ");
    scanf("%d%d", &a, &b);

    int mat1[a][b];
    printf("Enter the elements of the first matrix:\n");
    for (i = 0; i < a; i++) {
        for (j = 0; j < b; j++) {
            scanf("%d", &mat1[i][j]);
            if (mat1[i][j] != 0) n1++;
        }
    }

    printf("Enter the number of columns of the second matrix: ");
    scanf("%d", &c);

    int mat2[b][c];
    printf("Enter the elements of the second matrix:\n");
    for (i = 0; i < b; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &mat2[i][j]);
            if (mat2[i][j] != 0) n2++;
        }
    }

    int triplet1[n1 + 1][3], triplet2[n2 + 1][3];

    triplet1[0][0] = a;
    triplet1[0][1] = b;
    triplet1[0][2] = n1;
    k = 1;
    for (i = 0; i < a; i++) {
        for (j = 0; j < b; j++) {
            if (mat1[i][j] != 0) {
                triplet1[k][0] = i;
                triplet1[k][1] = j;
                triplet1[k++][2] = mat1[i][j];
            }
        }
    }

    triplet2[0][0] = b;
    triplet2[0][1] = c;
    triplet2[0][2] = n2;
    k = 1;
    for (i = 0; i < b; i++) {
        for (j = 0; j < c; j++) {
            if (mat2[i][j] != 0) {
                triplet2[k][0] = i;
                triplet2[k][1] = j;
                triplet2[k++][2] = mat2[i][j];
            }
        }
    }

    int result[a * c][3];
    int n3 = 0;

    for (i = 1; i <= n1; i++) {
        for (j = 1; j <= n2; j++) {
            if (triplet1[i][1] == triplet2[j][0]) {
                int row = triplet1[i][0];
                int col = triplet2[j][1];
                int value = triplet1[i][2] * triplet2[j][2];

                int found = 0;
                for (k = 1; k <= n3; k++) {
                    if (result[k][0] == row && result[k][1] == col) {
                        result[k][2] += value;
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    n3++;
                    result[n3][0] = row;
                    result[n3][1] = col;
                    result[n3][2] = value;
                }
            }
        }
    }

    printf("\nThe result triplet representation is:\n\n");
    printf("%d %d %d\n", a, c, n3);
    for (i = 1; i <= n3; i++) {
        printf("%d %d %d\n", result[i][0], result[i][1], result[i][2]);
    }

    return 0;
}
