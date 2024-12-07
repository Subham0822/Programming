#include <stdio.h>

void bubble_sort(int arr[],int n)
{
	int i, j, temp;
	for(i=0; i<n-1; i++)
	{
		for(j=i+1; j<n; j++)
		{
			if(arr[i]>arr[j])
			{
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
}

void main()
{
	int i, n;
	printf("Enter the number of elements you want to enter: ");
	scanf("%d",&n);
	int arr[n];
	for(i=0; i<n; i++)
	{
		printf("Enter element %d: ",i+1);
		scanf("%d",&arr[i]);
	}
	bubble_sort(arr, n);
	printf("Elements are sorted: ");
	for(i=0; i<n; i++)
	{
		printf("%d ",arr[i]);
	}
}
