#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int comparisons = 0; // Global variable to count comparisons

// Partition function for Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choosing the last element as pivot
    int i = (low - 1);
    
    for (int j = low; j < high; j++) {
        comparisons++;
        if (arr[j] < pivot) {
            i++;
            // Swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    
    // Swap arr[i+1] and pivot
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    
    return (i + 1);
}

// Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to generate a random array of given size
void generateArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 1000000; // Random numbers between 0 - 999999
    }
}

int main() {
    srand(time(0)); // Seed for random numbers
    int sizes[] = {10000, 100000, 1000000};

    for (int i = 0; i < 3; i++) {
        int size = sizes[i];
        int* arr = (int*)malloc(size * sizeof(int));
        
        generateArray(arr, size);
        comparisons = 0;
        
        clock_t start = clock();
        quickSort(arr, 0, size - 1);
        clock_t end = clock();
        
        printf("Size: %d | Comparisons: %d | Time: %.5f sec\n", size, comparisons, (double)(end - start) / CLOCKS_PER_SEC);
        
        free(arr);
    }
    return 0;
}
