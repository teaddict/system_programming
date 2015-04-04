/*
 * =====================================================================================
 *
 *       Filename:  flower.h
 *
 *    Description:  You are selling flowers! Write code which creates a struct type called flower order to keep
track of the number of flowers in an order (an integer), the total price (a float), and the name
of the person to deliver to (64 characters should be enough for anybody).
 *
 *        Version:  1.0
 *        Created:  04/04/15 13:58:54
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  teaddict (), cyberasker@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

typedef struct
{
	int t_number;
	float price;
	char name[64];
}Order;
