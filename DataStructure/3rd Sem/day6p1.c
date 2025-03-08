#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Node structure for deque
struct Node {
    char data;
    struct Node* next;
    struct Node* prev;
};

// Deque structure with front and rear pointers
struct Deque {
    struct Node* front;
    struct Node* rear;
};

// Function to create a new node
struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

// Function to initialize deque
struct Deque* createDeque() {
    struct Deque* deque = (struct Deque*)malloc(sizeof(struct Deque));
    deque->front = deque->rear = NULL;
    return deque;
}

// Function to add an element at the front of the deque
void addFront(struct Deque* deque, char data) {
    struct Node* newNode = createNode(data);
    if (deque->front == NULL) {
        deque->front = deque->rear = newNode;
    } else {
        newNode->next = deque->front;
        deque->front->prev = newNode;
        deque->front = newNode;
    }
    printf("Added %c to the front of the deque.\n", data);
}

// Function to add an element at the rear of the deque
void addRear(struct Deque* deque, char data) {
    struct Node* newNode = createNode(data);
    if (deque->rear == NULL) {
        deque->front = deque->rear = newNode;
    } else {
        newNode->prev = deque->rear;
        deque->rear->next = newNode;
        deque->rear = newNode;
    }
    printf("Added %c to the rear of the deque.\n", data);
}

// Function to remove an element from the front of the deque
char removeFront(struct Deque* deque) {
    if (deque->front == NULL) {
        printf("Deque is empty!\n");
        return '\0';
    }
    struct Node* temp = deque->front;
    char data = temp->data;
    deque->front = deque->front->next;
    if (deque->front == NULL) {
        deque->rear = NULL;
    } else {
        deque->front->prev = NULL;
    }
    free(temp);
    printf("Removed %c from the front of the deque.\n", data);
    return data;
}

// Function to remove an element from the rear of the deque
char removeRear(struct Deque* deque) {
    if (deque->rear == NULL) {
        printf("Deque is empty!\n");
        return '\0';
    }
    struct Node* temp = deque->rear;
    char data = temp->data;
    deque->rear = deque->rear->prev;
    if (deque->rear == NULL) {
        deque->front = NULL;
    } else {
        deque->rear->next = NULL;
    }
    free(temp);
    printf("Removed %c from the rear of the deque.\n", data);
    return data;
}

// Function to check if a string is a palindrome using deque
int isPalindrome(char* str) {
    int len = strlen(str);
    struct Deque* deque = createDeque();

    // Add all characters to the deque
    for (int i = 0; i < len; i++) {
        if (isalnum(str[i])) {
            addRear(deque, tolower(str[i]));  // Add lowercased alphanumeric characters
        }
    }

    // Check palindrome by comparing front and rear characters
    while (deque->front != NULL && deque->rear != NULL && deque->front != deque->rear) {
        char frontChar = removeFront(deque);
        char rearChar = removeRear(deque);
        if (frontChar != rearChar) {
            return 0;  // Not a palindrome
        }
    }
    return 1;  // Is a palindrome
}

// Menu-driven function for deque operations
void dequeMenu() {
    struct Deque* deque = createDeque();
    int choice;
    char element;

    do {
        printf("\n1. Add Front\n");
        printf("2. Add Rear\n");
        printf("3. Remove Front\n");
        printf("4. Remove Rear\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter character to add at front: ");
                scanf(" %c", &element);
                addFront(deque, element);
                break;
            case 2:
                printf("Enter character to add at rear: ");
                scanf(" %c", &element);
                addRear(deque, element);
                break;
            case 3:
                removeFront(deque);
                break;
            case 4:
                removeRear(deque);
                break;
            case 5:
                printf("Exiting deque menu.\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 5);
}

// Menu-driven function for palindrome check
void palindromeMenu() {
    char str[100];

    printf("Enter a string to check if it is a palindrome: ");
    scanf(" %[^\n]s", str);

    if (isPalindrome(str)) {
        printf("The string \"%s\" is a palindrome.\n", str);
    } else {
        printf("The string \"%s\" is not a palindrome.\n", str);
    }
}

// Main menu for both deque operations and palindrome check
int main() {
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Deque Operations\n");
        printf("2. Palindrome Check\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                dequeMenu();
                break;
            case 2:
                palindromeMenu();
                break;
            case 3:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 3);

    return 0;
}