#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Stack implementation
typedef struct {
    char data[MAX];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isStackFull(Stack *s) {
    return s->top == MAX - 1;
}

int isStackEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, char ch) {
    if (!isStackFull(s)) {
        s->data[++s->top] = ch;
    }
}

char pop(Stack *s) {
    if (!isStackEmpty(s)) {
        return s->data[s->top--];
    }
    return '\0'; // return null char if stack is empty
}

// Queue implementation
typedef struct {
    char data[MAX];
    int front, rear;
} Queue;

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = 0;
}

int isQueueFull(Queue *q) {
    return q->rear == MAX;
}

int isQueueEmpty(Queue *q) {
    return q->front == q->rear;
}

void enqueue(Queue *q, char ch) {
    if (!isQueueFull(q)) {
        q->data[q->rear++] = ch;
    }
}

char dequeue(Queue *q) {
    if (!isQueueEmpty(q)) {
        return q->data[q->front++];
    }
    return '\0'; // return null char if queue is empty
}

// Function to check if the string is palindrome using stack and queue
int isPalindrome(char str[]) {
    Stack s;
    Queue q;
    initStack(&s);
    initQueue(&q);
    
    // Normalize input (optional step to ignore case and non-alphanumeric characters)
    int len = strlen(str);
    int i;
    for (i = 0; i < len; i++) {
        char ch = tolower(str[i]);
        if (isalnum(ch)) {
            push(&s, ch);
            enqueue(&q, ch);
        }
    }

    // Compare characters from stack and queue
    while (!isStackEmpty(&s)) {
        if (pop(&s) != dequeue(&q)) {
            return 0;  // Not a palindrome
        }
    }

    return 1;  // Is a palindrome
}

int main() {
    char str[MAX];

    printf("Enter a string: ");
    fgets(str, MAX, stdin);
    str[strcspn(str, "\n")] = '\0'; // Remove newline character

    if (isPalindrome(str)) {
        printf("\"%s\" is a palindrome.\n", str);
    } else {
        printf("\"%s\" is not a palindrome.\n", str);
    }

    return 0;
}

