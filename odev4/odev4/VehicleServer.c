/*
 * =====================================================================================
 *
 *       Filename:  VehicleServer.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/05/15 00:39:49
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  teaddict (), cyberasker@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include"VehicleServer.h"

/*Bu fonksiyonda, soket yaratma ve bind
işlemi yapılır ve sunucu soketin
numarası
serverSocket ile
döndürülür.*/


int initializeConnection(int *serverSocket, int port)
{
	struct sockaddr_in saddr;
	
	saddr.sin_family=AF_INET;
	saddr.sin_port=htons(port);
	saddr.sin_addr.s_addr=htonl(INADDR_ANY);

	*serverSocket=socket(PF_INET,SOCK_STREAM,0);
	if(*serverSocket==-1)
	{
		printf("error on socket creation [%s]\n",strerror(errno));
		return false;
	}
	if(bind(*serverSocket,(struct sockaddr *)&saddr,sizeof(struct sockaddr))==-1)
	{	
		printf("error on binding [%s]\n",strerror(errno));
		return false;
	}
	return true;
}



int makeConnection(int *serverSocket)
{
	struct sockaddr_in caddr;
	uint32_t inet_len;
	int client;
	
	if(listen(*serverSocket,5)==-1)
	{	
		printf("error on listening [%s]\n",strerror(errno));
		return (-1);
	}
	
	inet_len = sizeof(caddr);
	if((client=accept(*serverSocket,(struct sockaddr *)&caddr,&inet_len))==-1)
	{	
		printf("error on socket accepting [%s]\n",strerror(errno));
		close(*serverSocket);
		return (-1);
	}
	
	printf  ("Server new client connection [%s/%d]\n        ",inet_ntoa(caddr.sin_addr),caddr.sin_port);
	return client;
}



int answerMessage(int clientSocket,Vehicle *vehicle)
{
	char msg[100];
	char answer[100];
	
	if(read(clientSocket, &msg, sizeof(msg))!=sizeof(msg))
	{
			printf("Error reading data [%s]\n",strerror(errno));
			close(clientSocket);		
			return (-1);
	}
	
	printf("message: %s \n",msg);
	
	if(strncmp(msg,"name",4)==0)
	{
		strncpy(answer,vehicle->name,100);
		
		if(write(clientSocket, &answer, sizeof(answer))!=sizeof(answer))
		{
			printf("Error writing data [%s]\n",strerror(errno));
			return (-1);	
		}
		
		return true;
	}
	
	if(strncmp(msg,"temp",4)==0)
	{
		int temp[3];
		temp[0]=vehicle->Temp.motor;
		temp[1]=vehicle->Temp.indoor;
		temp[2]=vehicle->Temp.outdoor;
		
		if(write(clientSocket, &temp, sizeof(temp))!=sizeof(temp))
		{
			printf("Error writing data [%s]\n",strerror(errno));
			return (-1);	
		}
		return true;
	}

	if(strncmp(msg,"door",4)==0)
	{
		int door[4];
		door[0]=vehicle->Door.frontLeft;
		door[1]=vehicle->Door.frontRight;
		door[2]=vehicle->Door.rearLeft;
		door[3]=vehicle->Door.rearRight;
		
		if(write(clientSocket, &door, sizeof(door))!=sizeof(door))
		{
			printf("Error writing data [%s]\n",strerror(errno));
			return (-1);	
		}
		return true;
	}

	if(strncmp(msg,"speed",5)==0)
	{
		int speed= vehicle->speed;	
		if(write(clientSocket, &speed, sizeof(speed))!=sizeof(speed))
		{
			printf("Error writing data [%s]\n",strerror(errno));
			return (-1);	
		}
		return true;
	}

	if(strncmp(msg,"wheelpress",10)==0)
	{
		int wheel[4];
		wheel[0]=vehicle->WheelPressure.frontLeft; 	
		wheel[1]=vehicle->WheelPressure.frontRight; 	
		wheel[2]=vehicle->WheelPressure.rearLeft; 	
		wheel[3]=vehicle->WheelPressure.rearRight; 	
		if(write(clientSocket, &wheel, sizeof(wheel))!=sizeof(wheel))
		{
			printf("Error writing data [%s]\n",strerror(errno));
			return (-1);	
		}
		return true;
	}
	
	if((strncmp(msg,"door",4)==0)&&((strncmp(msg[5],"0",1)||strncmp(msg[5],"1",1))))
	{
		State state[4];
		sscanf(msg,"door %d %d %d %d",&state[0],&state[1],&state[2],&state[3]);
		vehicle->Door.frontLeft=state[0];
		vehicle->Door.frontRight=state[1];
		vehicle->Door.rearLeft=state[2];
		vehicle->Door.rearRight=state[3];
		
		strcpy(answer,"ok");
		
		if(write(clientSocket, &answer, sizeof(answer))!=sizeof(answer))
		{
			printf("Error writing data [%s]\n",strerror(errno));
			return -1;
		}
		return true;
	}
	
	if((strncmp(msg,"speed",5)==0)&&(sscanf(msg,"speed %d",vehicle->speed)==1))
	{
	
		strcpy(answer,"ok");
		if(write(clientSocket, &answer, sizeof(answer))!=sizeof(answer))
		{
			printf("Error writing data [%s]\n",strerror(errno));
			return -1;
		}
		return true;
	}
	
	return false;
} 

