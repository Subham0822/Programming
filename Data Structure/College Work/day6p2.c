#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <limits.h>

// Define the stack structure
struct Stack {
    int top;
    unsigned capacity;
    int* array;
};

// Function to create a stack of given capacity
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Stack is full when top is equal to last index
int isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}

// Stack is empty when top is -1
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to add an item to stack (push operation)
void push(struct Stack* stack, int item) {
    if (isFull(stack)) {
        return;
    }
    stack->array[++stack->top] = item;
}

// Function to remove an item from stack (pop operation)
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        return INT_MIN;
    }
    return stack->array[stack->top--];
}

// Function to evaluate the postfix expression
int evaluatePostfix(char* exp) {
    // Create a stack of sufficient capacity
    struct Stack* stack = createStack(strlen(exp));
    int i;

    // Scan each character in the expression
    for (i = 0; exp[i]; ++i) {
        // If the character is a number, push it onto the stack
        if (isdigit(exp[i])) {
            push(stack, exp[i] - '0'); // convert char to int
        }
        // If the character is an operator
        else {
            int val1 = pop(stack);
            int val2 = pop(stack);

            switch (exp[i]) {
                case '+':
                    push(stack, val2 + val1);
                    break;
                case '-':
                    push(stack, val2 - val1);
                    break;
                case '*':
                    push(stack, val2 * val1);
                    break;
                case '/':
                    push(stack, val2 / val1);
                    break;
            }
        }
    }

    // The result will be at the top of the stack
    return pop(stack);
}

// Main function
int main() {
    char exp[100];

    // Input the postfix expression
    printf("Enter a postfix expression: ");
    scanf("%s", exp);

    // Evaluate and print the result
    printf("The result of the postfix expression is: %d\n", evaluatePostfix(exp));

    return 0;
}