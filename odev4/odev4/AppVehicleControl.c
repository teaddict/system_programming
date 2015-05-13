/*
 * =====================================================================================
 *
 *       Filename:  AppVehicleControl.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/05/15 20:10:47
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  teaddict (), cyberasker@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */
#include<stdio.h>
#include"VehicleControl.h"
#include"VehicleParser.h"
#include"VehicleClient.h"
#include<sys/socket.h>
#include<sys/types.h>
#include<errno.h>
#include<arpa/inet.h>
#include <stdbool.h>
#include<signal.h>

void signal_handler(int no)
{

        if(no ==SIGKILL)
        {
                printf("Sonlanma talebi geldi...\n");
                raise(SIGTERM);
        }
        if(no == SIGINT)
                printf("Sinyal geldi...\n");

        return;
}


int main()
{
	//SIGNAL TANIMLAMA
        signal(SIGINT, signal_handler);
        signal(SIGTERM, signal_handler);

	int client,port;
	struct sockaddr_in caddr;
	char *ip="127.0.0.1";
	port=7777;
	
	client=makeConnection(ip,port);
    printf("Client connected\n");
    int tmp=answerMessage(client,"name");
}
