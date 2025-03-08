#include <stdio.h>
#define size 5
int queue[size], front=-1, rear=-1;
void enqueue(int data){
	if(rear == size-1)
	{
		printf("Queue is full\n");
	}
	else if(front==-1 && rear==-1)
	{
		front=rear=0;
		queue[rear] = data;
	}
	else{
		queue[++rear] = data;
	}
}
void dequeue(){
	if(front==-1 && rear==-1)
	{
		printf("Queue is empty\n");
	}
	else if(front==rear)
	{
		front = rear = -1;	
	}
	else{
		printf("%d is deleted element\n", queue[front++]);
	}
}
void display(){
	if(front==-1 && rear==-1)
	{
		printf("Queue is empty\n");
	}
	else{
		int i;
		for(i=front; i<=rear; i++)
		{
			printf("%d ", queue[i]);
		}
	}
}
void main()
{
	int num, ch;
	do{
		printf("Enter your choice:\n1. Add value\n2. Delete value\n3. Display\n4. Exit\n");
		scanf("%d", &ch);
		switch(ch){
		case 1:
			printf("Enter the number: ");
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
			exit(0);
		}
	}while(1);
}
