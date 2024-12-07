#include <stdio.h>

#define MAX_SIZE 100

// Structure to represent a triplet
typedef struct {
    int row;
    int col;
    int value;
} Triplet;

// Function to convert a matrix to its triplet representation
int matrixToTriplet(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, Triplet triplets[MAX_SIZE * MAX_SIZE]) {
    int count = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                triplets[count].row = i;
                triplets[count].col = j;
                triplets[count].value = matrix[i][j];
                count++;
            }
        }
    }
    return count;
}

// Function to add two matrices in triplet representation
int addTriplets(Triplet triplets1[], int count1, Triplet triplets2[], int count2, Triplet result[]) {
    int i = 0, j = 0, k = 0;
    
    while (i < count1 && j < count2) {
        if (triplets1[i].row < triplets2[j].row || 
           (triplets1[i].row == triplets2[j].row && triplets1[i].col < triplets2[j].col)) {
            result[k++] = triplets1[i++];
        } else if (triplets1[i].row > triplets2[j].row || 
                  (triplets1[i].row == triplets2[j].row && triplets1[i].col > triplets2[j].col)) {
            result[k++] = triplets2[j++];
        } else {
            // Same position, add the values
            int sum = triplets1[i].value + triplets2[j].value;
            if (sum != 0) {
                result[k].row = triplets1[i].row;
                result[k].col = triplets1[i].col;
                result[k++].value = sum;
            }
            i++;
            j++;
        }
    }

    // Copy remaining elements from triplets1
    while (i < count1) {
        result[k++] = triplets1[i++];
    }

    // Copy remaining elements from triplets2
    while (j < count2) {
        result[k++] = triplets2[j++];
    }

    return k; // Return the count of non-zero elements in the result
}

// Function to print the triplet representation
void printTripletRepresentation(Triplet triplets[], int count, int rows, int cols) {
    printf("%d\t%d\t%d\n", rows, cols, count);
    for (int i = 0; i < count; i++) {
        printf("%d\t%d\t%d\n", triplets[i].row, triplets[i].col, triplets[i].value);
    }
}

int main() {
    int matrix1[MAX_SIZE][MAX_SIZE];
    int matrix2[MAX_SIZE][MAX_SIZE];
    Triplet triplets1[MAX_SIZE * MAX_SIZE];
    Triplet triplets2[MAX_SIZE * MAX_SIZE];
    Triplet result[MAX_SIZE * MAX_SIZE];
    int rows, cols;
    int count1, count2, resultCount;

    // Input matrix dimensions
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    // Input first matrix elements
    printf("Enter the elements of the first matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    // Input second matrix elements
    printf("Enter the elements of the second matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    // Convert matrices to triplet representation
    count1 = matrixToTriplet(matrix1, rows, cols, triplets1);
    count2 = matrixToTriplet(matrix2, rows, cols, triplets2);

    // Add matrices
    resultCount = addTriplets(triplets1, count1, triplets2, count2, result);

    // Print result
    printf("\nTriplet Representation of the Sum:\n");
    printTripletRepresentation(result, resultCount, rows, cols);

    return 0;
}
