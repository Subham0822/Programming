#include <stdio.h>
#include <stdlib.h>

struct Node{
	struct Node *prev;
	int data;
	struct Node *next;
};

struct Node *head=NULL;

void insertFront()
{
	struct Node *n, *t;
	n=(struct Node*)malloc(sizeof(struct Node));
	n->next=NULL;
	n->prev=NULL;
	printf("Enter your data: ");
	scanf("%d",&n->data);
	
	if(head==NULL)
	{
		head=n;
	}
	else{
		n->next=head;
		head->prev=n;
		head=n;
	}
}

void insertEnd()
{
	struct Node *n, *t;
	n=(struct Node*)malloc(sizeof(struct Node));
	printf("Enter data: ");
	scanf("%d",&n->data);
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
		n->prev=t;
	}
}

void deleteFront()
{
	struct Node *n, *t;
	if(head==NULL)
	{
		printf("List is empty\n");
	}
	else{
		t=head;
		head=t->next;
		if(head!=NULL)
		head->prev=NULL;
		printf("%d is the deleted element\n",t->data);
		free(t);
	}
}

void deleteEnd()
{
	struct Node *t;
	if(head==NULL)
	{
		printf("List is empty\n");	
	}
	else{
		t=head;
		if (t->next == NULL) {
            printf("%d is the deleted element\n", t->data);
            free(t);
            head = NULL;
        } else {
            while (t->next != NULL) {
                t = t->next;
            }
            printf("%d is the deleted element\n", t->data);
            t->prev->next = NULL;
            free(t);
	    }
	}
}

void display()
{
	struct Node *t;
	if(head==NULL)
	printf("List is empty");
	else{
		t=head;
		while(t!=NULL)
		{
			printf("%d ",t->data);
			t=t->next;
		}
		printf("\n");
	}
}

void main()
{
	int ch;
	while(1){
		printf("Enter your preferences:\n1. Enter element from the Front\n2. Enter element from the End\n3. Delete element from the Front\n4. Delete element from the End\n5. Display\n6. Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				insertFront();
				break;
			case 2:
				insertEnd();
				break;
			case 3:
				deleteFront();
				break;
			case 4:
				deleteEnd();
				break;
			case 5:
				display();
				break;
			case 6:
				exit(1);
				break;
			default:
				printf("Invalid Input!!\n");
		}
	}
}
