#include <stdio.h>

void selection_sort(int arr[], int n)
{
	int i, j, min, temp;
	for(i=0; i<n-1; i++)
	{
		min=i;
		for(j=i+1; j<n; j++)
		{
			if(arr[j]<arr[min])
			{
				min=j;
			}
		}
		temp=arr[min];
		arr[min]=arr[i];
		arr[i]=temp;
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
	selection_sort(arr, n);
	printf("Elements are sorted: ");
	for(i=0; i<n; i++)
	{
		printf("%d ",arr[i]);
	}
}
