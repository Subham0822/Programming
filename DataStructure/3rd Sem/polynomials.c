#include <stdio.h>
#include <stdlib.h>

void addPolynomials(int **coefficients, int *exponents, int numTerms, int *resultSize, int **result) {
    // Determine the maximum degree of the resulting polynomial
    int maxSize = 0;
    for (int i = 0; i < numTerms; i++) {
        if (exponents[i] > maxSize) {
            maxSize = exponents[i];
        }
    }

    // Initialize result array to zero
    *result = (int *)calloc(maxSize + 1, sizeof(int));

    // Add the coefficients of the polynomial to the result
    for (int i = 0; i < numTerms; i++) {
        (*result)[exponents[i]] += coefficients[i];
    }

    *resultSize = maxSize + 1;
}

int main() {
    int numPolynomials;

    // Ask user for the number of polynomials
    printf("Enter the number of polynomials: ");
    scanf("%d", &numPolynomials);

    // Prepare to store polynomial terms
    int *totalExponents = NULL;
    int *totalCoefficients = NULL;
    int totalTerms = 0;

    // Input each polynomial
    for (int i = 0; i < numPolynomials; i++) {
        int numTerms;
        printf("Enter the number of terms for polynomial %d: ", i + 1);
        scanf("%d", &numTerms);

        int *exponents = (int *)malloc(numTerms * sizeof(int));
        int *coefficients = (int *)malloc(numTerms * sizeof(int));

        printf("Enter the exponents and coefficients for polynomial %d:\n", i + 1);
        for (int j = 0; j < numTerms; j++) {
            printf("Exponent of term %d: ", j + 1);
            scanf("%d", &exponents[j]);
            printf("Coefficient of term %d: ", j + 1);
            scanf("%d", &coefficients[j]);
        }

        // Append the current polynomial terms to the total arrays
        totalTerms += numTerms;
        totalExponents = (int *)realloc(totalExponents, totalTerms * sizeof(int));
        totalCoefficients = (int *)realloc(totalCoefficients, totalTerms * sizeof(int));

        for (int j = 0; j < numTerms; j++) {
            totalExponents[totalTerms - numTerms + j] = exponents[j];
            totalCoefficients[totalTerms - numTerms + j] = coefficients[j];
        }

        free(exponents);
        free(coefficients);
    }

    int *result;
    int resultSize;

    // Add the polynomials
    addPolynomials(totalCoefficients, totalExponents, totalTerms, &resultSize, &result);

    // Print the result
    printf("Resulting polynomial:\n");
    for (int i = 0; i < resultSize; i++) {
        if (result[i] != 0) {
            if (i == 0) {
                printf("%d", result[i]);
            } else {
                printf(" + %dx^%d", result[i], i);
            }
        }
    }
    printf("\n");

    // Free allocated memory
    free(totalExponents);
    free(totalCoefficients);
    free(result);

    return 0;
}
