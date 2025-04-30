#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 9  // Number of vertices (a to i)
#define MAX_EDGES V*V

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Structure to represent a subset for union-find
struct Subset {
    int parent;
    int rank;
};

// Function to find the parent of a node (with path compression)
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Function to perform union of two sets (with rank)
void Union(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Compare function for qsort
int compareEdges(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

// Function to construct and print MST using Kruskal's algorithm
void kruskalMST(int graph[V][V]) {
    struct Edge* edges = (struct Edge*)malloc(MAX_EDGES * sizeof(struct Edge));
    int e = 0;

    // Create edges array from adjacency matrix
    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {
            if (graph[i][j] != INT_MAX) {
                edges[e].src = i;
                edges[e].dest = j;
                edges[e].weight = graph[i][j];
                e++;
            }
        }
    }

    // Sort edges in ascending order of weight
    qsort(edges, e, sizeof(struct Edge), compareEdges);

    // Allocate memory for subsets
    struct Subset* subsets = (struct Subset*)malloc(V * sizeof(struct Subset));

    // Create V subsets with single elements
    for (int i = 0; i < V; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    // Variables to store MST
    struct Edge* mst = (struct Edge*)malloc((V-1) * sizeof(struct Edge));
    int mst_size = 0;
    int total_weight = 0;

    // Process edges one by one
    for (int i = 0; i < e && mst_size < V-1; i++) {
        int x = find(subsets, edges[i].src);
        int y = find(subsets, edges[i].dest);

        if (x != y) {
            mst[mst_size++] = edges[i];
            total_weight += edges[i].weight;
            Union(subsets, x, y);
        }
    }

    // Print the MST
    printf("\nEdges in the Minimum Spanning Tree:\n");
    for (int i = 0; i < mst_size; i++) {
        printf("%c - %c : %d\n", 
               mst[i].src + 'a', 
               mst[i].dest + 'a', 
               mst[i].weight);
    }
    printf("\nTotal weight of MST: %d\n", total_weight);

    // Free allocated memory
    free(edges);
    free(subsets);
    free(mst);
}

int main() {
    // Initialize the graph with INT_MAX representing infinity
    int graph[V][V];
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            graph[i][j] = INT_MAX;

    // Fill the graph according to the given matrix
    // Vertex indices: a=0, b=1, c=2, d=3, e=4, f=5, g=6, h=7, i=8
    graph[0][1] = graph[1][0] = 4;    // a-b
    graph[1][2] = graph[2][1] = 8;    // b-c
    graph[2][3] = graph[3][2] = 7;    // c-d
    graph[3][4] = graph[4][3] = 9;    // d-e
    graph[4][5] = graph[5][4] = 10;   // e-f
    graph[5][6] = graph[6][5] = 2;    // f-g
    graph[6][7] = graph[7][6] = 1;    // g-h
    graph[7][8] = graph[8][7] = 7;    // h-i
    graph[0][7] = graph[7][0] = 8;    // a-h
    graph[1][7] = graph[7][1] = 11;   // b-h
    graph[2][5] = graph[5][2] = 4;    // c-f
    graph[2][8] = graph[8][2] = 2;    // c-i
    graph[3][5] = graph[5][3] = 14;   // d-f
    graph[6][8] = graph[8][6] = 6;    // g-i

    printf("Finding Minimum Spanning Tree using Kruskal's Algorithm...\n");
    kruskalMST(graph);

    return 0;
}
