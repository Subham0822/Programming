#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10  // Number of elements per row

int comparisons = 0; // Global variable to count comparisons

// Swap function
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to generate a random permutation of numbers 0-9
void generatePermutation(int arr[]) {
    for (int i = 0; i < N; i++)
        arr[i] = i;  // Fill array with 0 to 9
    for (int i = N - 1; i > 0; i--) {  // Fisher-Yates Shuffle Algorithm
        int j = rand() % (i + 1);
        swap(&arr[i], &arr[j]);
    }
}

// Function to write 10 unique permutations to permute.txt
void writePermutationsToFile() {
    FILE *file = fopen("permute.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    srand(time(0));

    for (int i = 0; i < N; i++) {
        int arr[N];
        generatePermutation(arr);
        for (int j = 0; j < N; j++)
            fprintf(file, "%d ", arr[j]);
        fprintf(file, "\n");
    }
    fclose(file);
}

// Partition function for Randomized Quick Sort
int randomizedPartition(int arr[], int low, int high) {
    int randomIndex = low + rand() % (high - low + 1);
    swap(&arr[randomIndex], &arr[high]); // Swap random pivot with last element

    int pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        comparisons++;
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Randomized Quick Sort function
void randomizedQuickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = randomizedPartition(arr, low, high);
        randomizedQuickSort(arr, low, pi - 1);
        randomizedQuickSort(arr, pi + 1, high);
    }
}

int main() {
    writePermutationsToFile(); // Generate and write permutations

    FILE *file = fopen("permute.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    int arr[N][N];
    double totalTime = 0;
    int totalComparisons = 0;

    // Reading permutations from file
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            fscanf(file, "%d", &arr[i][j]);
    fclose(file);

    printf("\nSorting each row using Randomized Quick Sort:\n");

    // Sorting each row and calculating time and comparisons
    for (int i = 0; i < N; i++) {
        comparisons = 0;
        clock_t start = clock();
        randomizedQuickSort(arr[i], 0, N - 1);
        clock_t end = clock();

        double timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
        totalTime += timeTaken;
        totalComparisons += comparisons;

        printf("\nSorted Row %d: ", i + 1);
        for (int j = 0; j < N; j++)
            printf("%d ", arr[i][j]);
        printf("\nTime: %.6f sec | Comparisons: %d\n", timeTaken, comparisons);
    }

    // Calculate the average time and comparisons
    printf("\nFinal Results:\n");
    printf("Average Time: %.6f sec\n", totalTime / N);
    printf("Average Comparisons: %d\n", totalComparisons / N);

    return 0;
}
