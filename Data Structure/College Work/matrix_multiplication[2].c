/*Instead of asking for the input from user, populate MatrixA and MatrixB by 
digits 0-9. Then multiply and store result into MatrixC and display.*/

#include <stdio.h>
#include <stdlib.h>

// Function to dynamically allocate a 2D array
int** allocateMatrix(int rows, int columns) {
    int i;
	int **matrix = (int **)malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(columns * sizeof(int));
    }
    return matrix;
}

// Function to free a dynamically allocated 2D array
void freeMatrix(int **matrix, int rows) {
    int i;
	for (i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Function to multiply two matrices
void multiplyMatrices(int **MatrixA, int **MatrixB, int **MatrixC, int rowsA, int colsA, int rowsB, int colsB) {
    int i, j, k;
	for (i = 0; i < rowsA; i++) {
        for (j = 0; j < colsB; j++) {
            MatrixC[i][j] = 0;
            for (k = 0; k < colsA; k++) {
                MatrixC[i][j] += MatrixA[i][k] * MatrixB[k][j];
            }
        }
    }
}

// Function to print a matrix
void printMatrix(int **matrix, int rows, int columns) {
    int i, j;
	for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
	
	int i, j;
    int **MatrixA = allocateMatrix(3, 4);
    int **MatrixB = allocateMatrix(4, 3);
    int **MatrixC = allocateMatrix(3, 3);
    
	for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            MatrixA[i][j]=rand()%10;
        }
    }
    
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 3; j++) {
            MatrixB[i][j]=rand()%10;
        }
    }
    
    printf("Matrix A (3x4):\n");
	for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            printf("%d ", MatrixA[i][j]);
        }
        printf("\n");
    }
    
	printf("Matrix B (4x3):\n");
	for (i = 0; i < 4; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", MatrixB[i][j]);
        }
        printf("\n");
    }
    
	multiplyMatrices(MatrixA, MatrixB, MatrixC, 3, 4, 4, 3);
    
	printf("Resultant Matrix C (3x3):\n");
    printMatrix(MatrixC, 3, 3);

    freeMatrix(MatrixA, 3);
    freeMatrix(MatrixB, 4);
    freeMatrix(MatrixC, 3);

    return 0;
}

