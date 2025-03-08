#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the stack
typedef struct Node {
    char data;
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

void push(Stack* s, char item) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = item;
    newNode->next = s->top;  // Point to the current top of the stack
    s->top = newNode;  // Update the top to the new node
}

char pop(Stack* s) {
    if (isEmpty(s)) {
        return '\0';  // Return '\0' to indicate an error
    }
    Node* temp = s->top;
    char item = temp->data;
    s->top = s->top->next;  // Update the top to the next node
    free(temp);  // Free the old top node
    return item;
}

char peek(Stack* s) {
    if (isEmpty(s)) {
        return '\0';  // Return '\0' to indicate an error
    }
    return s->top->data;
}

int isBalanced(char* expression) {
    Stack s;
    initStack(&s);
    char ch;

    while ((ch = *expression++) != '\0') {
        if (ch == '(' || ch == '[' || ch == '{') {
            push(&s, ch);
        } else if (ch == ')' || ch == ']' || ch == '}') {
            if (isEmpty(&s)) {
                return 0;  // Stack is empty, so parentheses are not balanced
            }
            char top = pop(&s);
            if ((ch == ')' && top != '(') ||
                (ch == ']' && top != '[') ||
                (ch == '}' && top != '{')) {
                return 0;  // Mismatched parentheses
            }
        }
    }

    return isEmpty(&s);  // If the stack is empty, parentheses are balanced
}

int main() {
    char expression[100];
    printf("Enter an expression: ");
    scanf("%s", expression);

    if (isBalanced(expression)) {
        printf("The parentheses are balanced.\n");
    } else {
        printf("The parentheses are not balanced.\n");
    }

    return 0;
}

