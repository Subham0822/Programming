#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to perform Insertion Sort and count comparisons
int insertionSort(int arr[], int n) {
    int comparisons = 0;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        // Move elements that are greater than key one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
            comparisons++; 
        }
        arr[j + 1] = key;
        if (j >= 0) comparisons++; // Count last successful comparison
    }
    return comparisons;
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to take user input for an array
void inputArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

// Function to generate a random array within a given range
void generateRandomArray(int arr[], int n) {
    srand(time(0));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100+1;
    }
}

int main() {
    int n = 10;
    int arr[10];
    int choice;
    
    do {
        printf("\nChoose an option:\n");
        printf("1. Best Case (Sorted Input)\n");
        printf("2. Worst Case (Reverse Sorted Input)\n");
        printf("3. Random Case (Randomly Generated Input)\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter 10 elements for Best Case (already sorted):\n");
                inputArray(arr, n);
                break;
            case 2:
                printf("Enter 10 elements for Worst Case (reverse sorted):\n");
                inputArray(arr, n);
                break;
            case 3:
                printf("Generating 10 random elements in range 1-100 for Random Case...\n");
                generateRandomArray(arr, n);
                break;
            case 4:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
        
        printf("Input Array: ");
        printArray(arr, n);
        int comparisons = insertionSort(arr, n);
        printf("Sorted Output: ");
        printArray(arr, n);
        printf("Comparisons: %d\n", comparisons);
    } while (choice != 4);
    
    return 0;
}
