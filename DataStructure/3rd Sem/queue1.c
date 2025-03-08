#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5 // Define the maximum size of the queue

typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
    int count; // Number of elements in the queue
} cQueue;

// Initialize the queue
void initialize(cQueue *q) {
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

// Check if the queue is empty
int isEmpty(cQueue *q) {
    return q->count == 0;
}

// Check if the queue is full
int isFull(cQueue *q) {
    return q->count == MAX_SIZE;
}

// Enqueue operation
void enqueue(cQueue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full! Cannot enqueue %d.\n", value);
        return;
    }
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->items[q->rear] = value;
    q->count++;
    printf("Enqueued %d\n", value);
}

// Dequeue operation
int dequeue(cQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1;
    }
    int value = q->items[q->front];
    q->front = (q->front + 1) % MAX_SIZE;
    q->count--;
    printf("Dequeued %d\n", value);
    return value;
}

// Print the queue
void printQueue(cQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue: ");
    int i;
    for (i = 0; i < q->count; i++) {
        printf("%d ", q->items[(q->front + i) % MAX_SIZE]);
    }
    printf("\n");
}

int main() {
    cQueue q;
    initialize(&q);
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Print Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                printQueue(&q);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
