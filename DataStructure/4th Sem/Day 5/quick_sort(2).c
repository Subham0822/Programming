#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100  // Max range for random numbers

int comparisons = 0; // Global counter for comparisons

// Swap function
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function (Last element as pivot)
int partitionLast(int arr[], int low, int high) {
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

// Partition function (First element as pivot)
int partitionFirst(int arr[], int low, int high) {
    swap(&arr[low], &arr[high]);  // Move first element to last
    return partitionLast(arr, low, high);
}

// Partition function (Random element as pivot)
int partitionRandom(int arr[], int low, int high) {
    int randomIndex = low + rand() % (high - low + 1);
    swap(&arr[randomIndex], &arr[high]);  // Swap random pivot to last
    return partitionLast(arr, low, high);
}

// Quick Sort function
void quickSort(int arr[], int low, int high, int pivotChoice) {
    if (low < high) {
        int pi;
        if (pivotChoice == 1)       // First element as pivot
            pi = partitionFirst(arr, low, high);
        else if (pivotChoice == 2)  // Last element as pivot
            pi = partitionLast(arr, low, high);
        else                        // Random element as pivot
            pi = partitionRandom(arr, low, high);

        quickSort(arr, low, pi - 1, pivotChoice);
        quickSort(arr, pi + 1, high, pivotChoice);
    }
}

// Function to take user input for the array
void inputArray(int arr[], int n, int orderChoice) {
    if (orderChoice == 1 || orderChoice == 2) {
        printf("Enter the elements:\n");
        for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]);
    } else {
        srand(time(0));
        for (int i = 0; i < n; i++)
            arr[i] = (rand() % MAX) + 1;
    }
}

// Function to print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n, choicePivot, choiceOrder;
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    while (1) {
        printf("\nChoose Pivot Position:\n");
        printf("1. First Element as Pivot\n");
        printf("2. Last Element as Pivot\n");
        printf("3. Random Element as Pivot\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choicePivot);
        
        if (choicePivot == 4) break;
        if(choicePivot < 1 || choicePivot > 3) {
            printf("Invalid choice! Try again.\n");
            continue;
        }

        while (1) {
            printf("\nChoose Input Order:\n");
            printf("1. Desired Order (Sorted)\n");
            printf("2. Completely Desired Order (Reverse Sorted)\n");
            printf("3. Random Order (1-100)\n");
            printf("4. Exit to Pivot Menu\n");
            printf("Enter your choice: ");
            scanf("%d", &choiceOrder);

            if (choiceOrder == 4) break;

            if (choiceOrder < 1 || choiceOrder > 3) {
                printf("Invalid choice! Try again.\n");
                continue;
            }

            inputArray(arr, n, choiceOrder);

            printf("\nOriginal Array:\n");
            printArray(arr, n);

            comparisons = 0; // Reset comparison counter
            clock_t start = clock();
            quickSort(arr, 0, n - 1, choicePivot);
            clock_t end = clock();

            double timeTaken = (double)(end - start) / CLOCKS_PER_SEC;

            printf("\nSorted Array:\n");
            printArray(arr, n);
            printf("Time: %.6f sec | Comparisons: %d\n", timeTaken, comparisons);
        }
    }

    printf("Exiting program...\n");
    return 0;
}
