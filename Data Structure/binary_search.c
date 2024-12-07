#include<stdio.h>
#define MAX 5

void binary_search(int arr[MAX], int val)
{
	int start=0, end=MAX-1, mid, pos=-1;
	while(start<=end)
	{
		mid = (start+end)/2;
		if(arr[mid]==val)
		{
			pos=arr[mid];
			break;
		}
		else if(arr[mid]>val)
		{
			end=mid-1;
		}
		else{
			start=mid+1;
		}
	}
	if(pos==-1)
	{
		printf("Element not found\n");
	}
	else{
		printf("%d is found at position %d", pos, (mid+1));
	}
}

int sortedArray(int arr[MAX])
{
	int i, j, key;
	for(i=1; i<=MAX-1; i++)
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
	int i, val;
	int arr[MAX];
	printf("Enter elements of the matrix\n");
	for(i=0; i<MAX; i++)
	{
		printf("Enter %d element: ", (i+1));
		scanf("%d",&arr[i]);
	}
	printf("Enter the value to be searched: ");
	scanf("%d",&val);
	sortedArray(arr);
	for(i=0; i<MAX; i++)
	{
		printf("Element at position %d: %d\n", (i+1), arr[i]);
	}
	binary_search(arr, val);
}
