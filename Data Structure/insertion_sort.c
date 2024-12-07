#include <stdio.h>

void insertion_sort(int arr[],int size)
{
	int i, j, key;
	for(i=1; i<=size-1; i++)
	{
		j=i-1;
		key=arr[i];
		while(j>=0 && arr[j]>key)
		{
			arr[j+1]=arr[j];
			j=j-1;
		}
		arr[j+1]=key;
	}
}

void main()
{
	int size, i;
	printf("Enter the size of the array: ");
	scanf("%d", &size);
	int arr[size];
	for(i=0; i<size; i++)
	{
		printf("Enter %d element: ",i+1);
		scanf("%d",&arr[i]);
	}
	insertion_sort(arr, size);
	printf("Elements are sorted\n");
	for(i=0; i<size; i++)
	{
		printf("%d ",arr[i]);
	}
}
