#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int weight, value;
} Item;

int cmp(const void *a, const void *b) {
    double r1 = ((Item*)a)->value / (double)((Item*)a)->weight;
    double r2 = ((Item*)b)->value / (double)((Item*)b)->weight;
    return r2 - r1 > 0 ? 1 : -1;
}

int knapsack01(Item items[], int n, int W) {
    int dp[n+1][W+1];
    for (int i = 0; i <= n; i++)
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (items[i-1].weight <= w)
                dp[i][w] = (items[i-1].value + dp[i-1][w - items[i-1].weight] > dp[i-1][w]) ? 
                           (items[i-1].value + dp[i-1][w - items[i-1].weight]) : dp[i-1][w];
            else
                dp[i][w] = dp[i-1][w];
        }
    return dp[n][W];
}

double knapsackFractional(Item items[], int n, int W) {
    qsort(items, n, sizeof(Item), cmp);
    double totalValue = 0.0;
    for (int i = 0; i < n && W > 0; i++) {
        if (items[i].weight <= W) {
            totalValue += items[i].value;
            W -= items[i].weight;
        } else {
            totalValue += items[i].value * ((double)W / items[i].weight);
            break;
        }
    }
    return totalValue;
}

int main() {
    int n, W;

    printf("Enter number of items: ");
    scanf("%d", &n);
    
    Item items[n];
    printf("Enter weight and value of each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d - Weight: ", i+1);
        scanf("%d", &items[i].weight);
        printf("Item %d - Value: ", i+1);
        scanf("%d", &items[i].value);
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &W);

    printf("0/1 Knapsack Max Value = %d\n", knapsack01(items, n, W));
    printf("Fractional Knapsack Max Value = %.2f\n", knapsackFractional(items, n, W));

    return 0;
}
