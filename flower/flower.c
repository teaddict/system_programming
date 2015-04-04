/*
 * =====================================================================================
 *
 *       Filename:  flower.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/04/15 14:00:21
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  teaddict (), cyberasker@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include<stdio.h>
#include"flower.h"

int main()
{
	Order order[2];

	char name[64];
	
	printf("enter tracking number, price and name:\n");
	scanf("%d %f %s",&order[0].t_number,&order[0].price,name);
	
	strncpy(order[0].name,name,64);
	printf("\n\n#################\n");
	printf("Tracking number: %d\n Price: %f\n Name: %s\n",order[0].t_number,order[0].price,order[0].name);

return 0;
}
