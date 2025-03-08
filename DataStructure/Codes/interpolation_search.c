#include<stdio.h>
#define MAX 5

void interpolationSearch(int arr[MAX], int val)
{
	int start=0, end=MAX-1, posi=-1, x;
	while(start<=end){
		x = start + ((val - arr[start])/(arr[end] - arr[start])) * (end - start);
		if(arr[x] == val)
		{
			posi = val;
			break;
		}
		else{
			if(arr[x]>val)
			{
				end=x-1;
			}
			else{
				start=x+1;
			}
		}
	}
	if(posi==-1)
	{
		printf("Element not found\n");
	}
	else{
		printf("%d found at position %d", val, x+1);
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
		printf("Enter element %d: ", i+1);
		scanf("%d",&arr[i]);
	}
	printf("Enter value to be searched: ");
	scanf("%d",&val);
	sortedArray(arr);
	for(i=0; i<MAX; i++)
	{
		printf("Element at position %d: %d\n", (i+1), arr[i]);
	}
	interpolationSearch(arr, val);
}
