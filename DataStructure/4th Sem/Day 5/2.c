#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int comparisons = 0; // Global comparison counter

// Swap function
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Standard partition function for Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; 
    int i = (low - 1);
    
    for (int j = low; j < high; j++) {
        comparisons++;
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Partition function for randomized Quick Sort
int randomizedPartition(int arr[], int low, int high) {
    int randomIndex = low + rand() % (high - low + 1);
    swap(&arr[randomIndex], &arr[high]); // Swap random element with pivot
    return partition(arr, low, high);
}

// Quick Sort function (Randomized)
void randomizedQuickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = randomizedPartition(arr, low, high);
        randomizedQuickSort(arr, low, pi - 1);
        randomizedQuickSort(arr, pi + 1, high);
    }
}

// Function to generate a random array of given size
void generateArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 1000000; // Random values between 0 and 999999
    }
}

// Function to generate a random permutation of numbers 0-9
void generateRandomPermutation(int arr[], int n) {
    for (int i = 0; i < n; i++)
        arr[i] = i; // Fill array with 0 to 9
    
    for (int i = n - 1; i > 0; i--) { // Shuffle using Fisher-Yates Algorithm
        int j = rand() % (i + 1);
        swap(&arr[i], &arr[j]);
    }
}

int main() {
    srand(time(0)); // Seed for randomness
    int sizes[] = {10000, 100000, 1000000};

    for (int i = 0; i < 3; i++) {
        int size = sizes[i];
        int* arr = (int*)malloc(size * sizeof(int));
        
        generateArray(arr, size);
        comparisons = 0;
        
        clock_t start = clock();
        randomizedQuickSort(arr, 0, size - 1);
        clock_t end = clock();
        
        printf("Size: %d | Comparisons: %d | Time: %.5f sec (Randomized Quick Sort)\n", size, comparisons, (double)(end - start) / CLOCKS_PER_SEC);
        
        free(arr);
    }

    // Generate random permutation of numbers 0-9
    int perm[10];
    generateRandomPermutation(perm, 10);
    printf("Random Permutation of 0-9: ");
    for (int i = 0; i < 10; i++)
        printf("%d ", perm[i]);
    printf("\n");

    return 0;
}
