#include <stdio.h>
#include <stdlib.h>

// Function to allocate memory for a matrix
int** allocateMatrix(int rows, int cols) {
    int** matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
    }
    return matrix;
}

// Function to free allocated memory
void freeMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Function to read matrix from file
void readMatrix(FILE* file, int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fscanf(file, "%d", &matrix[i][j]);
        }
    }
}

// Function to write matrix to file
void writeMatrix(FILE* file, int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fprintf(file, "%d ", matrix[i][j]);
        }
        fprintf(file, "\n");
    }
}

// Function to multiply two matrices
int** multiplyMatrices(int** A, int** B, int r1, int c1, int c2) {
    int** result = allocateMatrix(r1, c2);
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return result;
}

int main() {
    FILE* fileA = fopen("matrixA.txt", "r");
    FILE* fileB = fopen("matrixB.txt", "r");
    FILE* outputFile = fopen("output.txt", "w");
    
    if (fileA == NULL || fileB == NULL || outputFile == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    
    int r1, c1, r2, c2;
    fscanf(fileA, "%d %d", &r1, &c1);
    fscanf(fileB, "%d %d", &r2, &c2);
    
    if (c1 != r2) {
        fprintf(outputFile, "Matrix multiplication not possible!\n");
        fclose(fileA);
        fclose(fileB);
        fclose(outputFile);
        return 1;
    }
    
    int** A = allocateMatrix(r1, c1);
    int** B = allocateMatrix(r2, c2);
    
    readMatrix(fileA, A, r1, c1);
    readMatrix(fileB, B, r2, c2);
    
    fclose(fileA);
    fclose(fileB);
    
    int** result = multiplyMatrices(A, B, r1, c1, c2);
    
    writeMatrix(outputFile, result, r1, c2);
    fclose(outputFile);
    
    freeMatrix(A, r1);
    freeMatrix(B, r2);
    freeMatrix(result, r1);
    
    return 0;
}