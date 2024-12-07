
# include <stdio.h>
# include <stdlib.h>


int main()
{
    int a, b, i, j, n = 0;
    printf("Enter the number of rows and columns: ");
    scanf("%d%d", &a, &b);
    int **mat = (int **)malloc(a * sizeof(int *));
    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < a; i++)
    {
        mat[i] = (int *)malloc(b * sizeof(int));
        for (j = 0; j < b; j++)
        {
            scanf("%d", &mat[i][j]);
            if (mat[i][j] != 0)
            n++;
        }
    }
    int **triplet = (int **)malloc((n + 1) * sizeof(int *));
    for (i = 0; i < n + 1; i++)
    triplet[i] = (int *)malloc(3 * sizeof(int));
    triplet[0][0] = a;
    triplet[0][1] = b;
    triplet[0][2] = n;
    int k = 1;
    for (i = 0; i < a; i++)
    {
        for (j = 0; j < b; j++)
        {
            if (mat[i][j] != 0)
            {
                triplet[k][0] = i;
                triplet[k][1] = j;
                triplet[k++][2] = mat[i][j];
            }
        }
    }
    printf("\nThe triplet representation is:\n\n");
    for (i = 0; i < n + 1; i++)
    {
        for (j = 0; j < 3; j++)
        printf("%d ", triplet[i][j]);
        printf("\n");
    }

    //forgot the formula, not sure about this line
    print(a*b/3 < n+1 ? "Not Efficient" : "Efficient");

    return 0;
}

