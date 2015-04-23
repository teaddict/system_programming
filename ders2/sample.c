#include<stdio.h>
#include"support.h"
#define SIZE 10
int main()
{
	int array[SIZE];
	int i;

	for(i=0; i<SIZE; i++)
	{
		scanf("%d",&array[i]);
	}

	printf("the numbers are:\n ");
	printArray(array,SIZE);
	
	printf("Max Value is %d\n",maxNumber(array,SIZE));

	return 0;
}
