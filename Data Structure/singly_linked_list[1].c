#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node *next;
};
struct Node *head;
void insertFrontNode()
{
	struct Node *n;
	n=(struct Node*) malloc(sizeof(struct Node));
	printf("Enter data: ");
	scanf("%d", &n->data);
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
void insertEndNode()
{
	struct Node *n, *t;
	n=(struct Node*) malloc(sizeof(struct Node));
	printf("Enter data: ");
	scanf("%d", &n->data);
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
void deleteFrontNode()
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
void deleteEndNode()
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
void reverseList()
{
	struct Node *current=head, *prev=NULL, *next=NULL;
	while(current!=NULL)
	{
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
	}
	head=prev;
}
void main()
{
	int ch;
	do{
		printf("Enter your preferences:\n1. Enter element from the front\n2. Enter element from the end\n3. Delete element from the Front\n4. Delete element from the End\n5. Reverse the List\n6. Display\n7. Exit\n");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:
				insertFrontNode();
				break;
			case 2:
				insertEndNode();
				break;
			case 3:
				deleteFrontNode();
				break;
			case 4:
				deleteEndNode();
				break;
			case 5:
				reverseList();
				printf("List is reversed\n");
				break;
			case 6:
				display();
				break;
			case 7:
				exit(1);
			default:
				printf("Invalid Choice!!\n");
				break;
		}
	}while(1);
}
