/*Write a program to check whether a matrix is i) identity, ii) diagonal.*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to check if a matrix is an identity matrix
bool isIdentityMatrix(int **matrix, int size) {
	int i, j;
    for ( i = 0; i < size; i++) {
        for ( j = 0; j < size; j++) {
            if (i == j && matrix[i][j] != 1) {
                return false;
            } else if (i != j && matrix[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
}

// Function to check if a matrix is a diagonal matrix
bool isDiagonalMatrix(int **matrix, int size) {
	int i, j;
    for ( i = 0; i < size; i++) {
        for ( j = 0; j < size; j++) {
            if (i != j && matrix[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int i, j, size;
    printf("Enter the size of the square matrix: ");
    scanf("%d", &size);

    // Dynamically allocate memory for the matrix
    int **matrix = (int **)malloc(size * sizeof(int *));
    for ( i = 0; i < size; i++) {
        matrix[i] = (int *)malloc(size * sizeof(int));
    }

    printf("Enter the elements of the matrix (%dx%d):\n", size, size);
    for ( i = 0; i < size; i++) {
        for ( j = 0; j < size; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Check if the matrix is an identity matrix
    if (isIdentityMatrix(matrix, size)) {
        printf("The matrix is an identity matrix.\n");
    } else {
        printf("The matrix is not an identity matrix.\n");
    }

    // Check if the matrix is a diagonal matrix
    if (isDiagonalMatrix(matrix, size)) {
        printf("The matrix is a diagonal matrix.\n");
    } else {
        printf("The matrix is not a diagonal matrix.\n");
    }

    // Free the allocated memory
    for ( i = 0; i < size; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}

