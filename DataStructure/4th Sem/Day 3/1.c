#include <stdio.h>

// Recursive function to solve Tower of Hanoi
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", from_rod, to_rod);
        return;
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

// Iterative Binary Search
int binarySearchIterative(int arr[], int n, int key, int *comparisons) {
    int low = 0, high = n - 1;
    *comparisons = 0;
    while (low <= high) {
        (*comparisons)++;
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

// Recursive Binary Search
int binarySearchRecursive(int arr[], int low, int high, int key, int *comparisons) {
    if (low > high)
        return -1;
    (*comparisons)++;
    int mid = low + (high - low) / 2;
    if (arr[mid] == key)
        return mid;
    else if (arr[mid] < key)
        return binarySearchRecursive(arr, mid + 1, high, key, comparisons);
    else
        return binarySearchRecursive(arr, low, mid - 1, key, comparisons);
}

int main() {
    int choice;
    do {
        printf("\nChoose an option:\n");
        printf("1. Solve Tower of Hanoi\n");
        printf("2. Perform Binary Search (Iterative)\n");
        printf("3. Perform Binary Search (Recursive)\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: {
                int n;
                printf("Enter number of disks: ");
                scanf("%d", &n);
                towerOfHanoi(n, 'A', 'C', 'B');
                break;
            }
            case 2:
            case 3: {
                int n, key, comparisons = 0;
                printf("Enter number of elements in sorted array: ");
                scanf("%d", &n);
                int arr[n];
                printf("Enter %d sorted elements: ", n);
                for (int i = 0; i < n; i++)
                    scanf("%d", &arr[i]);
                printf("Enter key to search: ");
                scanf("%d", &key);
                int result;
                if (choice == 2)
                    result = binarySearchIterative(arr, n, key, &comparisons);
                else
                    result = binarySearchRecursive(arr, 0, n - 1, key, &comparisons);
                if (result != -1)
                    printf("Key found at index %d with %d comparisons.\n", result, comparisons);
                else
                    printf("Key not found after %d comparisons.\n", comparisons);
                break;
            }
            case 4:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 4);
    
    return 0;
}
