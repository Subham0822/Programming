#include <stdio.h>
#define size 5

int stack[size];
void main(){
	int element;
	printf("Enter an element: ");
	scanf("%d", &element);
	push(element);
	display();
}

void push(int data){
	int i, rem, num=data, rev=0;
	for(i=0; i<=size; i++){
		rem = num%10;
		num = num/10;
		stack[i] = rem;
	}
}

void display(){
	int i;
	for(i=0; i<size; i++){
		printf("%d\n", stack[i]);
	}
}

