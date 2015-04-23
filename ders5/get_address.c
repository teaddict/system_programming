/*
 * =====================================================================================
 *
 *       Filename:  get_address.c
 *
 *    Description:  socket programming
 *
 *        Version:  1.0
 *        Created:  22/04/15 21:03:01
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  teaddict (), cyberasker@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include<stdlib.h>
#include<arpa/inet.h>

int main(int argc, char **argv)
{
	struct sockaddr_in v4,sa; //IPv4
	struct sockaddr_in6 sa6;  //IPv6

	//IPv4 string to sockaddr_in
	inet_aton("192.12.0.1",&(v4.sin_addr));
	inet_pton(AF_INET,"192.12.0.1",&(v4.sin_addr));

	//IPv6 string to sockaddr_in6
	inet_pton(AF_INET6,"2001:db8:63b3:1::3940",&(sa6.sin6_addr));
return 0;
}

