#include <stdio.h>
#include <stdlib.h>

// O(n) iterative method
int powerLinear(int X, int n) {
    int result = 1;
    for (int i = 0; i < n; i++) {
        result *= X;
    }
    return result;
}

// O(log n) iterative method
int powerLog(int X, int n) {
    int result = 1;
    while (n > 0) {
        if (n % 2 == 1) {  // If n is odd, multiply X with result
            result *= X;
        }
        X *= X;  // Square the base
        n /= 2;  // Reduce exponent by half
    }
    return result;
}

int main() {
    FILE *inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    
    int X, n, choice;
    fscanf(inputFile, "%d %d", &X, &n);
    fclose(inputFile);
    
    while(1) {
        printf("Choose method:\n1. O(n) Linear Method\n2. O(log n) Logarithmic Method\n3. Exit\nEnter choice: ");
        scanf("%d", &choice);
        
        int result;
        switch (choice) {
            case 1:
                result = powerLinear(X, n);
                printf("%d^%d = %d (Linear Method)\n", X, n, result);
                break;
            case 2:
                result = powerLog(X, n);
                printf("%d^%d = %d (Logarithmic Method)\n", X, n, result);
                break;
            case 3:
                exit(1);
            default:
                printf("Invalid choice!\n");
        }   
    }
    return 0;
}