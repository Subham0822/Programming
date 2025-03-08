#include <stdio.h>
#define size 5

int cqueue[size], front=-1, rear=-1;

void enqueue(int data)
{
	if(front==-1 && rear==-1)
	{
		front=rear=0;
		cqueue[rear] = data;
	}
	else if((rear+1)%size==front)
	{
		printf("Queue is full\n");
	}
	else{
		rear=(rear+1)%size;
		cqueue[rear] = data;
	}
}
void dequeue()
{
	if(front==-1 && rear==-1)
	{
		printf("Queue is empty\n");
	}
	else if(front==rear)
	{
		front=rear=-1;
	}
	else{
		printf("%d is deleted element", cqueue[front]);
		front = (front+1)%size;
	}
}
void display(){
	int i=front;
	if(front==-1 && rear==-1)
	{
		printf("Queue is empty");
	}
	else
	{
		while(i!=rear)
		{
			printf("%d",cqueue[i]);
			i=(i+1)%size;	
		}	
		printf("%d",cqueue[rear]);
	}
}
void main()
{
	int num, ch;
	do{
		printf("Enter your choice:\n1. Enter element\n2. Delete element\n3. Display\n4. Exit\n");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:
				printf("Enter your element: ");
				scanf("%d", &num);
				enqueue(num);
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(1);
				break;
			default:
				printf("Wrong Choice!");
		}
	}while(1);
}
