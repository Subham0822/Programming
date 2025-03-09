#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int comparisonCount = 0;

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    int L[n1], R[n2];
    
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        comparisonCount++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Merge Sort function
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
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
void generateRandomArray(int arr[], int n, int lower, int upper) {
    srand(time(0));
    for (int i = 0; i < n; i++) {
        arr[i] = (rand() % (upper - lower + 1)) + lower;
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
                generateRandomArray(arr, n, 1, 100);
                break;
            case 4:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
                continue;
        }
        
        printf("Input Array: ");
        printArray(arr, n);
        comparisonCount = 0;
        mergeSort(arr, 0, n - 1);
        printf("Sorted Output: ");
        printArray(arr, n);
        printf("Comparisons: %d\n", comparisonCount);
    } while (choice != 4);
    
    return 0;
}