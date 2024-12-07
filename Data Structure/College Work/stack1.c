#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the stack
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define a stack structure
typedef struct {
    Node* top;
} Stack;

void initStack(Stack* s) {
    s->top = NULL;  // Initialize the top of the stack to NULL (indicating an empty stack)
}

int isEmpty(Stack* s) {
    return s->top == NULL;
}

void push(Stack* s, int item) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = item;
    newNode->next = s->top;  // Point to the current top of the stack
    s->top = newNode;  // Update the top to the new node
    printf("Pushed %d\n", item);
}

int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1;  // Return -1 to indicate an error
    }
    Node* temp = s->top;
    int item = temp->data;
    s->top = s->top->next;  // Update the top to the next node
    free(temp);  // Free the old top node
    return item;
}

int peek(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;  // Return -1 to indicate an error
    }
    return s->top->data;
}

void display(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return;
    }
    Node* current = s->top;
    printf("Stack contents:\n");
    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
}

int main() {
    Stack s;
    int choice, item;
    initStack(&s);

    do {
        printf("\nStack Operations Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the item to push: ");
                scanf("%d", &item);
                push(&s, item);
                break;
            case 2:
                item = pop(&s);
                if (item != -1) {
                    printf("Popped item: %d\n", item);
                }
                break;
            case 3:
                item = peek(&s);
                if (item != -1) {
                    printf("Top item: %d\n", item);
                }
                break;
            case 4:
                display(&s);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

