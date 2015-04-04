/*
 * =====================================================================================
 *
 *       Filename:  test.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/04/15 20:29:12
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  teaddict (), cyberasker@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */
#include<stdio.h>
#include"carGui.h"

int main()
{
	Car c[3];
	int i=0;
	
	for(i=0; i<3; i++)
		getCars(&c[i]);

	printCars(&c[0],3);

return 0;
}
