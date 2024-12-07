#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *next;
};
struct Node *head=NULL;
void insertFrontNode()
{
	struct Node *n, *t;
	n=(struct Node*) malloc(sizeof(struct Node));
	printf("Enter data: ");
	scanf("%d", &n->data);
	n->next=head;
	if(head==NULL)
	{
		head=n;
		n->next=head;
	}
	else{
		t=head;
		do
		{
			t=t->next;
		}while(t->next!=head);
		t->next=n;
		n->next=head;
		head=n;
	}
}
void insertEndNode()
{
	struct Node *n,*t;
	n= (struct Node*) malloc(sizeof(struct Node));
	printf("Enter the data: ");
	scanf("%d",&n->data);
	n->next=head;
	if(head==NULL)
	{
		head=n;
		n->next=head;
	}
	else{
		t=head;
		do
		{
			t=t->next;
		}while(t->next!=head);
		t->next=n;
		n->next=head;
	}
}
void deleteFrontNode()
{
	struct Node *current, *t;
	if(head==NULL)
	{
		printf("List is empty\n");
	}
	else{
		current=head;
		head=current->next;
		printf("%d is deleted element\n", current->data);
		t=head;
		do{
			t=t->next;	
		}while(t->next!=current);
		free(current);
		t->next=head;
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
		do
		{
			prev=current;
			current=current->next;
		}while(current->next!=head);
		printf("%d is the deleted element\n", current->data);
		free(current);
		prev->next=head;
	}
}
void display()
{
	struct Node *n;
	if(head==NULL)
	{
		printf("List is empty\n");
	}
	else{
		n=head;
		while(n->next!=head)
		{
			printf("%d ", n->data);
			n=n->next;
		}
		printf("%d", n->data);
		printf("\n");
	}
}
void main()
{
	int ch;
	do{
		printf("Enter your preferences:\n1. Enter element from Front\n2. Enter element from End\n3. Delete element from the Front\n4. Delete element from End\n5. Display\n6. Exit\n");
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
				display();
				break;
			case 6:	
				printf("Program terminated!");
				exit(1);
			default:
				printf("Invalid Choice!!\n");
				break;
		}
	}while(1);
}
