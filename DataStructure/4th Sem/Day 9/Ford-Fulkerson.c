#include <stdio.h>
#include <limits.h>
#include <string.h>

#define MAX 100

int min(int a, int b) {
    return (a < b) ? a : b;
}

int bfs(int rGraph[MAX][MAX], int V, int s, int t, int parent[]) {
    int visited[MAX] = {0};
    int queue[MAX], front = 0, rear = 0;

    queue[rear++] = s;
    visited[s] = 1;
    parent[s] = -1;

    while (front < rear) {
        int u = queue[front++];
        for (int v = 0; v < V; v++) {
            if (!visited[v] && rGraph[u][v] > 0) {
                queue[rear++] = v;
                parent[v] = u;
                visited[v] = 1;
            }
        }
    }
    return visited[t];
}

int fordFulkerson(int graph[MAX][MAX], int V, int s, int t) {
    int u, v;
    int rGraph[MAX][MAX], parent[MAX], max_flow = 0;

    for (u = 0; u < V; u++)
        for (v = 0; v < V; v++)
            rGraph[u][v] = graph[u][v];

    while (bfs(rGraph, V, s, t, parent)) {
        int path_flow = INT_MAX;
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }
        max_flow += path_flow;
    }

    return max_flow;
}

int main() {
    int V, graph[MAX][MAX], s, t;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter the capacity matrix (%d x %d):\n", V, V);
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter source and sink (0-based index): ");
    scanf("%d %d", &s, &t);

    int max_flow = fordFulkerson(graph, V, s, t);
    printf("The maximum possible flow is %d\n", max_flow);

    return 0;
}
