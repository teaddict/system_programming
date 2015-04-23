/*
 * =====================================================================================
 *
 *       Filename:  client.c
 *
 *    Description:  client 
 *
 *        Version:  1.0
 *        Created:  22/04/15 22:59:17
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  teaddict (), cyberasker@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include<stdio.h>
#include<stdlib.h>
#include<netdb.h>
#include <errno.h>
#include <string.h>   

int client_operation(void)
{
	int socket_fd;
	uint32_t value;
	struct sockaddr_in caddr; //client address
	char *ip="127.0.0.1";

	caddr.sin_family=AF_INET;
	caddr.sin_port=htons(16453);
	if(inet_aton(ip,&caddr.sin_addr)==0)
	{
	return -1;
	}

	socket_fd=socket(PF_INET,SOCK_STREAM,0);
	if(socket_fd==-1)
	{
	printf("Error on socket connect [%s]\n",strerror(errno));
	return -1;
	}	
	
	if(connect(socket_fd,(const struct sockaddr *)&caddr,sizeof(struct sockaddr))==-1)
	{
	printf("Error on socket connect [%s]\n",strerror(errno));
	return -1;
	}
	
	value = htonl(1);
	if(write(socket_fd,&value,sizeof(value)) !=sizeof(value) )
	{
	printf("Error writing network data [%s]\n",strerror(errno));
	return -1;
	
	}
	
	printf("sent a value of [%d]\n",ntohl(value));

	if(read(socket_fd,&value,sizeof(value))!=sizeof(value))
	{
	printf("Error writing network data [%s]\n",strerror(errno));
	return -1;	
	}
	
	value=ntohl(value);
	printf("received a value of [%d]\n",value);
	
	close(socket_fd);
	return 0;	
}
