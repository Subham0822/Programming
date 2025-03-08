#include <stdio.h>

void linear_search(int arr[], int n)
{
	int i, num, flag=0;
	printf("Enter the number to be searched: ");
	scanf("%d",&num);
	for(i=0; i<n; i++)
	{
		if(arr[i]==num){
			printf("%d is present at the position %d",arr[i],(i+1));
//			flag=1;
			break;
		}
	}
	if(i==n)
	{
		printf("Element not found");
	}
//	if(flag==0)
//	{
//		printf("Element not found");
//	}

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
	linear_search(arr, n);
}
