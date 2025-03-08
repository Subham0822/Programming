#include <stdio.h>

#define MAX_SIZE 100

// Structure to represent a triplet
typedef struct {
    int row;
    int col;
    int value;
} Triplet;

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
    Triplet triplets1[MAX_SIZE * MAX_SIZE];
    Triplet triplets2[MAX_SIZE * MAX_SIZE];
    Triplet result[MAX_SIZE * MAX_SIZE];
    int rows, cols;
    int count1, count2, resultCount;

    // Input dimensions of matrices
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    // Input first matrix triplets
    printf("Enter the number of non-zero elements in the first matrix: ");
    scanf("%d", &count1);
    printf("Enter the triplets (row column value) for the first matrix:\n");
    for (int i = 0; i < count1; i++) {
        scanf("%d %d %d", &triplets1[i].row, &triplets1[i].col, &triplets1[i].value);
    }

    // Input second matrix triplets
    printf("Enter the number of non-zero elements in the second matrix: ");
    scanf("%d", &count2);
    printf("Enter the triplets (row column value) for the second matrix:\n");
    for (int i = 0; i < count2; i++) {
        scanf("%d %d %d", &triplets2[i].row, &triplets2[i].col, &triplets2[i].value);
    }

    // Add matrices
    resultCount = addTriplets(triplets1, count1, triplets2, count2, result);

    // Print the result
    printf("\nResulting Triplet Representation:\n");
    printTripletRepresentation(result, resultCount, rows, cols);

    return 0;
}
