#include <stdio.h>
#define size 100

char str[size], stack[size];
int top=-1;

void main(){
	printf("Enter a string: ");
	scanf("%c", &str);
	push(str);
	display();
}

void push(char data[size]){
	int i;
	for(i=size; i>=0; i--)
	{
		stack[i] = data[i];
	}
}


void display(){
	int i;
	for(i=0; i<size; i++)
	{
		printf("%c", stack[i]);
	}
}

