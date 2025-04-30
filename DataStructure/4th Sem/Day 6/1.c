#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX
#define V 5  // Number of vertices in the graph

// Structure to represent a node in the priority queue
typedef struct {
    int vertex, distance;
} MinHeapNode;

// Structure for min heap (priority queue)
typedef struct {
    MinHeapNode* nodes[V];
    int size;
} MinHeap;

// Graph representation using adjacency list
typedef struct AdjListNode {
    int dest, weight;
    struct AdjListNode* next;
} AdjListNode;

typedef struct {
    AdjListNode* head;
} AdjList;

typedef struct {
    AdjList array[V];
} Graph;

// Function to create a new adjacency list node
AdjListNode* newAdjListNode(int dest, int weight) {
    AdjListNode* newNode = (AdjListNode*)malloc(sizeof(AdjListNode));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph
Graph* createGraph() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    for (int i = 0; i < V; i++)
        graph->array[i].head = NULL;
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest, int weight) {
    AdjListNode* newNode = newAdjListNode(dest, weight);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
}

// Function to create a min heap node
MinHeapNode* newMinHeapNode(int vertex, int distance) {
    MinHeapNode* node = (MinHeapNode*)malloc(sizeof(MinHeapNode));
    node->vertex = vertex;
    node->distance = distance;
    return node;
}

// Function to initialize a min heap
MinHeap* createMinHeap() {
    MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap->size = 0;
    return minHeap;
}

// Function to swap two min heap nodes
void swapMinHeapNode(MinHeapNode** a, MinHeapNode** b) {
    MinHeapNode* temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify function to maintain min heap property
void minHeapify(MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1, right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->nodes[left]->distance < minHeap->nodes[smallest]->distance)
        smallest = left;
    if (right < minHeap->size && minHeap->nodes[right]->distance < minHeap->nodes[smallest]->distance)
        smallest = right;
    if (smallest != idx) {
        swapMinHeapNode(&minHeap->nodes[smallest], &minHeap->nodes[idx]);
        minHeapify(minHeap, smallest);
    }
}

// Function to extract the minimum node from the heap
MinHeapNode* extractMin(MinHeap* minHeap) {
    if (minHeap->size == 0) return NULL;
    MinHeapNode* root = minHeap->nodes[0];
    minHeap->nodes[0] = minHeap->nodes[minHeap->size - 1];
    minHeap->size--;
    minHeapify(minHeap, 0);
    return root;
}

// Function to decrease distance value of a vertex
void decreaseKey(MinHeap* minHeap, int vertex, int distance) {
    int i;
    for (i = 0; i < minHeap->size; i++)
        if (minHeap->nodes[i]->vertex == vertex)
            break;
    minHeap->nodes[i]->distance = distance;
    while (i && minHeap->nodes[i]->distance < minHeap->nodes[(i - 1) / 2]->distance) {
        swapMinHeapNode(&minHeap->nodes[i], &minHeap->nodes[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Function to check if a vertex is in the min heap
int isInMinHeap(MinHeap* minHeap, int vertex) {
    for (int i = 0; i < minHeap->size; i++)
        if (minHeap->nodes[i]->vertex == vertex)
            return 1;
    return 0;
}

// Dijkstra’s algorithm using priority queue
void dijkstra(Graph* graph, int src) {
    int dist[V];
    MinHeap* minHeap = createMinHeap();

    for (int v = 0; v < V; v++) {
        dist[v] = INF;
        minHeap->nodes[v] = newMinHeapNode(v, dist[v]);
        minHeap->size++;
    }

    dist[src] = 0;
    decreaseKey(minHeap, src, dist[src]);

    while (minHeap->size != 0) {
        MinHeapNode* minNode = extractMin(minHeap);
        int u = minNode->vertex;
        AdjListNode* crawl = graph->array[u].head;

        while (crawl != NULL) {
            int v = crawl->dest;
            if (isInMinHeap(minHeap, v) && dist[u] != INF && dist[u] + crawl->weight < dist[v]) {
                dist[v] = dist[u] + crawl->weight;
                decreaseKey(minHeap, v, dist[v]);
            }
            crawl = crawl->next;
        }
    }

    printf("\nVertex\tShortest Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%c\t%d\n", 's' + i, dist[i]);
}

int main() {
    Graph* graph = createGraph();
    
    // Adding edges as per given adjacency matrix
    addEdge(graph, 0, 1, 10);
    addEdge(graph, 0, 3, 5);
    addEdge(graph, 1, 2, 1);
    addEdge(graph, 1, 3, 2);
    addEdge(graph, 2, 4, 4);
    addEdge(graph, 3, 1, 3);
    addEdge(graph, 3, 2, 9);
    addEdge(graph, 3, 4, 2);
    addEdge(graph, 4, 0, 7);
    addEdge(graph, 4, 2, 6);

    printf("Dijkstra’s Algorithm for the given graph (Source: s):\n");
    dijkstra(graph, 0);

    return 0;
}