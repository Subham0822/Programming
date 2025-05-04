#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int comparisonCount = 0;
// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

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
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
        comparisonCount++;
    }
    
    while (i < n1) {
        arr[k++] = L[i++];
        comparisonCount++;
    }
    
    while (j < n2) {
        arr[k++] = R[j++];
        comparisonCount++;
    }
}

// Merge Sort function
void mergeSort(int arr[], int left, int right, int n) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, n);
        mergeSort(arr, mid + 1, right, n);
        merge(arr, left, mid, right);
        printArray(arr, n);
    }
}

// Function to take user input for an array
void inputArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

// Function to generate a random array within a given range
int generateRandomArray(FILE* file, int n) {
    srand(time(0));
    int i, j;
    int arr[n][n];
    int res[n];
    int result=0;
    comparisonCount = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            arr[i][j] = rand() % 100+1;
            fprintf(file, "%d ", arr[i][j]);
        }
        fprintf(file, "\n");
    }
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            res[j] = arr[i][j];
        }
        comparisonCount = 0;
        mergeSort(res, 0, n-1, n);
        printf("Iteration ends! \nComparisons: %d\n", comparisonCount);
        result += comparisonCount;
    }return result;
    
}

int main() {
    int n, ch, i, j, res;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    FILE* file = fopen("input.txt", "w");
    int arr[n];
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    
    while(1){
        printf("1. Desired order\n2. Reverse Order\n3. Randomly generated\n4. Exit\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 1:
            case 2:
                if(ch==1){
                    printf("Enter the elements of the array: ");
                }else{
                    printf("Enter the elements of the array in reverse order: ");
                }
                inputArray(arr, n);
                printf("Array: ");
                printArray(arr, n);
                comparisonCount = 0;
                mergeSort(arr, 0, n-1, n);
                printf("Comparisons: %d\n", comparisonCount);
                printf("Sorted Array: ");
                printArray(arr, n);
                break;
            case 3:
                res = generateRandomArray(file, n);
                printf("Total Comparisons: %d\n", res/n);
                break;
            case 4:
                fclose(file);
                exit(1);
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    
    return 0;
}