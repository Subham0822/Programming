#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 9
#define MAX_EDGES V*V

struct Edge {
    int src, dest, weight;
};

struct Subset {
    int parent;
    int rank;
};

int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

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

int compareEdges(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

void kruskalMST(int graph[V][V]) {
    struct Edge* edges = (struct Edge*)malloc(MAX_EDGES * sizeof(struct Edge));
    int e = 0;

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

    qsort(edges, e, sizeof(struct Edge), compareEdges);

    struct Subset* subsets = (struct Subset*)malloc(V * sizeof(struct Subset));
    for (int i = 0; i < V; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    struct Edge* mst = (struct Edge*)malloc((V - 1) * sizeof(struct Edge));
    int mst_size = 0, total_weight = 0;

    for (int i = 0; i < e && mst_size < V - 1; i++) {
        int x = find(subsets, edges[i].src);
        int y = find(subsets, edges[i].dest);
        if (x != y) {
            mst[mst_size++] = edges[i];
            total_weight += edges[i].weight;
            Union(subsets, x, y);
        }
    }

    printf("\nEdges in the Minimum Spanning Tree:\n");
    for (int i = 0; i < mst_size; i++) {
        printf("%c - %c : %d\n", mst[i].src + 'a', mst[i].dest + 'a', mst[i].weight);
    }
    printf("\nTotal weight of MST: %d\n", total_weight);

    free(edges);
    free(subsets);
    free(mst);
}

int main() {
    int graph[V][V];

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            graph[i][j] = INT_MAX;

    int E;
    printf("Enter number of edges: ");
    scanf("%d", &E);

    printf("Enter edges in format <src> <dest> <weight> (vertices as a-i):\n");
    for (int i = 0; i < E; i++) {
        char u, v;
        int w;
        scanf(" %c %c %d", &u, &v, &w);
        int src = u - 'a';
        int dest = v - 'a';
        graph[src][dest] = graph[dest][src] = w;
    }

    printf("\nFinding Minimum Spanning Tree using Kruskal's Algorithm...\n");
    kruskalMST(graph);

    return 0;
}
