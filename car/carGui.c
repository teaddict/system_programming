/*
 * =====================================================================================
 *
 *       Filename:  carGui.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/04/15 20:23:32
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  teaddict (), cyberasker@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */
#include"carGui.h"

void getCars(Car *c)
{
	char tm[100];
	char tc[100];
	scanf("%d %s %s",&c->number,tm,tc);
	strcpy(c->model,tm);
	strcpy(c->color,tc);
	c++;
}

void printCars(Car *c, int n)
{
	int i=0;
	for(i=0; i<n; i++)
	{
	printf("#########################################\n");
	printf("Number:%d\nModel:%s\nColor:%s\n",c->number,c->model,c->color);
	c++;
	}
	
}

