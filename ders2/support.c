#include<stdio.h>
void printArray(int *arr,int size)
{
	int i;
	for(i=0; i<size; i++)
	{
		printf("%d \t ",arr[i]);
	}	
	printf("\n");
}
int maxNumber(int *arr,int size)
{
	int i;
	int max=arr[0];
	for(i=1; i<size;i++)
	{
		if(max<arr[i])
		{
		max=arr[i];
		}
	}
return max;
}
