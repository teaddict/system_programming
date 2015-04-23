/*
 * =====================================================================================
 *
 *       Filename:  matrix.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/24/2015 10:32:31 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include<stdio.h>


int* copyArray(int src[], int size)
{
	int dest[size],i;

	for(i=0; i<size; i++)
		dest[i]=src[i];
	
	return dest; //bu fonk içinden çıkıldıktan sonra herşey silinir.
}


void copyArrayn(int src[],int dst[],int n)
{
	int i=0;
	for(i;i<n; i++)
		dst[i]=src[i];
}

int main()
{
int val[3]={1,2,3};
	printf("val[%d %d %d]\n",val[0],val[1],val[2]);

int val2[3]={0};
	printf("val[%d %d %d]\n",val2[0],val2[1],val2[2]);

int val3[3]={};
	printf("val[%d %d %d]\n",val3[0],val3[1],val3[2]);

int val4[6]={[1 ... 3]=1};
	printf("val[%d %d %d]\n",val4[0],val4[1],val4[2]);

double grid[3][2]={
		{1,2},
		{5,7},
		{4,9} };

int i,j;

for(i=0;i<3; i++)
{

	for (j=0; j<2; j++)
		printf("[%d][%d]:%f\t",i,j,grid[i][j]);
printf("\n");
}

int *copied;
*copied=copyArray(val,3);

	printf("copied[%d %d %d]\n",copied[0],copied[1],copied[2]);

int dizi[3];
copyArrayn(val,dizi,3);

	printf("dizi[%d %d %d]\n",dizi[0],dizi[1],dizi[2]);
}
