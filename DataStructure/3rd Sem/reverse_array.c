/*Write a program to reverse the elements of an array without using any 
other variable.*/

#include <stdio.h>

void reverseArray(int arr[], int size)
{
	int i;
	for(i=0; i<size/2; i++)
	{
		arr[i]=arr[i]+arr[size-i-1];
		arr[size-i-1]=arr[i]-arr[size-i-1];
		arr[i]=arr[i]-arr[size-i-1];
	}
}

void main()
{
	int i, size;
	int arr[size];
	printf("Enter the size of the array: ");
	scanf("%d", &size);
	printf("Enter values of the array: \n");
	for(i=0;i<size;i++)
	{
		scanf("%d", &arr[i]);
	}
	printf("The original array: \n");
	for(i=0;i<size;i++)
	{
		printf("%d ", arr[i]);
	}
	reverseArray(arr, size);
	printf("\nThe reversed array: \n");
	for(i=0; i<size; i++)
	{
		printf("%d ", arr[i]);
	}
}
