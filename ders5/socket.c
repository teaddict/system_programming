/*
 * =====================================================================================
 *
 *       Filename:  socket.c
 *
 *    Description:  create socket
 *
 *        Version:  1.0
 *        Created:  22/04/15 21:53:37
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  teaddict (), cyberasker@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */
#include<stdlib.h>
#include<netdb.h>
#include<string.h>
int main()
{
	int socket_fd;
	
	socket_fd=socket(AF_INET,SOCK_STREAM,0);
	if(socket_fd==-1)
	{
//	printf("error on socket creation [%s]\n",strerror(errno));
	return -1;
	}
}

