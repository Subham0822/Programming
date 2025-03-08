#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node *next;
};
struct Node *head;
void addFront(int data)
{
	struct Node *n;
	n=(struct Node*) malloc(sizeof(struct Node));
	n->data = data;
	n->next=NULL;
	if(head==NULL)
	{
		head=n;
	}
	else{
		n->next=head; //pointing the new next node to the current head
		head=n; //updating head to the next node
	}
}
void addEnd(int data)
{
	struct Node *n, *t;
	n=(struct Node*) malloc(sizeof(struct Node));
	n->data = data;
	n->next=NULL;
	if(head==NULL)
	{
		head=n;
	}
	else{
		t=head;
		while(t->next!=NULL)
		{
			t=t->next;
		}
		t->next=n;
	}
}
void addPos(int data, int posi) {
    struct Node *n, *current = head;
    int i;
	n = (struct Node*) malloc(sizeof(struct Node));
	n->data = data;
    n->next = NULL;
    if (posi == 0) {
        n->next = head;
        head = n;
        return;
    }
    for (i = 0; current != NULL && i < posi - 1; i++) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Position out of range\n");
        free(n);
        return;
    }
    n->next = current->next;
    current->next = n;
}
void delFront()
{
	struct Node *current;
	if(head==NULL)
	{
		printf("List is empty\n");
	}
	else{
		current=head;
		head=head->next;
		printf("%d is deleted element\n", current->data);
		free(current);
	}
}
void delMid() {
    struct Node *slow_ptr = head;
    struct Node *fast_ptr = head;
    struct Node *prev = NULL;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    while (fast_ptr != NULL && fast_ptr->next != NULL) {
        fast_ptr = fast_ptr->next->next;
        prev = slow_ptr;
        slow_ptr = slow_ptr->next;
    }

    if (prev != NULL) {
        prev->next = slow_ptr->next;
    } else {
        head = slow_ptr->next;
    }

    printf("%d is the deleted middle element\n", slow_ptr->data);
    free(slow_ptr);
}
void delEnd()
{
	struct Node *current, *prev;
	if(head==NULL)
	{
		printf("List is empty\n");
	}
	else{
		current=head;
		while(current->next!=NULL)
		{
			prev=current;
			current=current->next;
		}
		printf("%d is the deleted element\n", current->data);
		free(current);
		if(prev!=NULL)
		{
			prev->next=NULL;
		}
		else{
			head=NULL;
		}
	}
}
void delOne(int x) {
    struct Node *current = head, *prev = NULL;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (head->data == x) {
        head = head->next;
        printf("%d is the deleted element\n", current->data);
        free(current);
        return;
    }
    while (current != NULL && current->data != x) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Element %d not found in the list\n", x);
        return;
    }
    prev->next = current->next;
    printf("%d is the deleted element\n", current->data);
    free(current);
}
void delPos(int posi) {
    struct Node *current = head, *prev = NULL;
    int i;
	if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (posi == 0) {
        head = current->next;
        printf("%d is the deleted element\n", current->data);
        free(current);
        return;
    }
    for (i = 0; current != NULL && i < posi; i++) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Position out of range\n");
        return;
    }
    prev->next = current->next;
    printf("%d is the deleted element\n", current->data);
    free(current);
}
void delEndPos(int i) {
    struct Node *main_ptr = head;
    struct Node *ref_ptr = head;
    struct Node *prev = NULL;
    int count = 0;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    while (count < i) {
        if (ref_ptr == NULL) {
            printf("Position out of range\n");
            return;
        }
        ref_ptr = ref_ptr->next;
        count++;
    }

    while (ref_ptr != NULL) {
        prev = main_ptr;
        main_ptr = main_ptr->next;
        ref_ptr = ref_ptr->next;
    }

    if (prev != NULL) {
        prev->next = main_ptr->next;
    } else {
        head = main_ptr->next;
    }

    printf("%d is the deleted element from the end\n", main_ptr->data);
    free(main_ptr);
}
void delAll(int x) {
    struct Node *current = head;
    struct Node *prev = NULL;

    while (current != NULL) {
        if (current->data == x) {
            if (prev == NULL) {
                // Deleting the head node
                head = current->next;
                printf("%d is the deleted element\n", current->data);
                free(current);
                current = head;
            } else {
                // Deleting a non-head node
                prev->next = current->next;
                printf("%d is the deleted element\n", current->data);
                free(current);
                current = prev->next;
            }
        } else {
            prev = current;
            current = current->next;
        }
    }
}
int retFront(int i) {
    struct Node *current = head;
    int count = 0;
    while (current != NULL) {
        if (count == i) {
            return current->data;
        }
        count++;
        current = current->next;
    }
    printf("Position out of range\n");
    return -1; // Error value
}
int retMid() {
    struct Node *slow_ptr = head;
    struct Node *fast_ptr = head;

    if (head != NULL) {
        while (fast_ptr != NULL && fast_ptr->next != NULL) {
            fast_ptr = fast_ptr->next->next;
            if (fast_ptr != NULL) {
                slow_ptr = slow_ptr->next;
            }
        }
        return slow_ptr->data;
    }
    printf("List is empty\n");
    return -1; // Error value
}
int retEnd(int i) {
    struct Node *main_ptr = head;
    struct Node *ref_ptr = head;
    int count = 0;
    while (count < i) {
        if (ref_ptr == NULL) {
            printf("Position out of range\n");
            return -1; // Error value
        }
        ref_ptr = ref_ptr->next;
        count++;
    }
    while (ref_ptr != NULL) {
        main_ptr = main_ptr->next;
        ref_ptr = ref_ptr->next;
    }

    return main_ptr->data;
}
void display()
{
	struct Node *t;
	if(head==NULL)
	{
		printf("List is empty\n");
	}
	else{
		t=head;
		while(t!=NULL)
		{
			printf("%d ", t->data);
			t=t->next;
		}
		printf("\n");
	}
}
void main() {
    int ch, data, posi;
    do {
        printf("Enter your preferences:\n");
        printf("1. Enter element from the front\n");
        printf("2. Enter element from the end\n");
        printf("3. Add element at ith position\n");
        printf("4. Delete element from the Front\n");
        printf("5. Delete element from the End\n");
        printf("6. Delete element from ith position\n");
        printf("7. Display\n");
        printf("8. Delete one occurrence of a value\n");
        printf("9. Delete all occurrences of a value\n");
        printf("10. Return i-th element from the front\n");
        printf("11. Return i-th element from the end\n");
        printf("12. Return the middle element\n");
        printf("13. Delete the middle element\n");
        printf("14. Delete i-th element from the end\n");
        printf("15. Exit\n");
        scanf("%d", &ch);
        switch(ch) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                addFront(data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                addEnd(data);
                break;
            case 3:
                printf("Enter data and position: ");
                scanf("%d %d", &data, &posi);
                addPos(data, posi);
                break;
            case 4:
                delFront();
                break;
            case 5:
                delEnd();
                break;
            case 6:
                printf("Enter position: ");
                scanf("%d", &posi);
                delPos(posi);
                break;
            case 7:
                display();
                break;
            case 8:
                printf("Enter the value to delete: ");
                scanf("%d", &data);
                delOne(data);
                break;
            case 9:
                printf("Enter the value to delete: ");
                scanf("%d", &data);
                delAll(data);
                break;
            case 10:
                printf("Enter position: ");
                scanf("%d", &posi);
                data = retFront(posi);
                if (data != -1) {
                    printf("Element at position %d from front is: %d\n", posi, data);
                }
                break;
            case 11:
                printf("Enter position: ");
                scanf("%d", &posi);
                data = retEnd(posi);
                if (data != -1) {
                    printf("Element at position %d from end is: %d\n", posi, data);
                }
                break;
            case 12:
                data = retMid();
                if (data != -1) {
                    printf("Middle element is: %d\n", data);
                }
                break;
            case 13:
                delMid();
                break;
            case 14:
                printf("Enter position from the end: ");
                scanf("%d", &posi);
                delEndPos(posi);
                break;
            case 15:
                exit(1);
            default:
                printf("Invalid Choice!!\n");
                break;
        }
    } while (1);
}
