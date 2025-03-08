
#include <stdio.h>

int main()
{
    int a, b, i, j, n1 = 0, n2 = 0;
    printf("Enter the number of rows and columns of the matrices: ");
    scanf("%d%d", &a, &b);

    int mat1[a][b], mat2[a][b];

    printf("Enter the elements of the first matrix:\n");
    for (i = 0; i < a; i++)
    {
        for (j = 0; j < b; j++)
        {
            scanf("%d", &mat1[i][j]);
            if (mat1[i][j] != 0)
            n1++;
        }
    }
    int triplet1[n1+1][3];

    printf("Enter the elements of the second matrix:\n");
    for (i = 0; i < a; i++)
    {
        for (j = 0; j < b; j++)
        {
            scanf("%d", &mat2[i][j]);
            if (mat2[i][j] != 0)
            n2++;
        }
    }
    int triplet2[n2+1][3];
    int result[n1 + n2 + 1][3];

    triplet1[0][0] = a;
    triplet1[0][1] = b;
    triplet1[0][2] = n1;
    int k = 1;
    for (i = 0; i < a; i++)
    {
        for (j = 0; j < b; j++)
        {
            if (mat1[i][j] != 0)
            {
                triplet1[k][0] = i;
                triplet1[k][1] = j;
                triplet1[k++][2] = mat1[i][j];
            }
        }
    }

    triplet2[0][0] = a;
    triplet2[0][1] = b;
    triplet2[0][2] = n2;
    k = 1;
    for (i = 0; i < a; i++)
    {
        for (j = 0; j < b; j++)
        {
            if (mat2[i][j] != 0)
            {
                triplet2[k][0] = i;
                triplet2[k][1] = j;
                triplet2[k++][2] = mat2[i][j];
            }
        }
    }

    result[0][0] = a;
    result[0][1] = b;
    int n3 = 0;
    i = 1; j = 1; k = 1;

    while (i <= n1 && j <= n2)
    {
        if (triplet1[i][0] < triplet2[j][0] || (triplet1[i][0] == triplet2[j][0] && triplet1[i][1] < triplet2[j][1]))
        {
            result[k][0] = triplet1[i][0];
            result[k][1] = triplet1[i][1];
            result[k][2] = triplet1[i][2];
            i++;
        }
        else if (triplet1[i][0] > triplet2[j][0] || (triplet1[i][0] == triplet2[j][0] && triplet1[i][1] > triplet2[j][1]))
        {
            result[k][0] = triplet2[j][0];
            result[k][1] = triplet2[j][1];
            result[k][2] = triplet2[j][2];
            j++;
        }
        else
        {
            result[k][0] = triplet1[i][0];
            result[k][1] = triplet1[i][1];
            result[k][2] = triplet1[i][2] + triplet2[j][2];
            i++;
            j++;
        }
        k++;
        n3++;
    }

    while (i <= n1)
    {
        result[k][0] = triplet1[i][0];
        result[k][1] = triplet1[i][1];
        result[k][2] = triplet1[i][2];
        i++;
        k++;
        n3++;
    }

    while (j <= n2)
    {
        result[k][0] = triplet2[j][0];
        result[k][1] = triplet2[j][1];
        result[k][2] = triplet2[j][2];
        j++;
        k++;
        n3++;
    }

    result[0][2] = n3;

    printf("\nThe result triplet representation is:\n\n");
    for (i = 0; i <= n3; i++)
    {
        for (j = 0; j < 3; j++)
        printf("%d ", result[i][j]);
        printf("\n");
    }

    return 0;
}

