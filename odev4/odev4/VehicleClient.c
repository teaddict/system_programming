/*
 * =====================================================================================
 *
 *       Filename:  VehicleClient.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/05/15 01:31:56
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  teaddict (), cyberasker@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */
#include"VehicleClient.h"

/*Burada, verilen ip
numarasina ve port numarasi
ile baglanti işlemi kurulur.
Baglanti kurulduğunda soket
numarası döndürülür. Hata
varsa -1 döndürür.*/
int makeConnection(char *ip, int port)
{
	int socket_fd;
	struct sockaddr_in caddr;
	
	caddr.sin_family=AF_INET;
	caddr.sin_port=htons(port);
	
	if(inet_aton(ip,&caddr.sin_addr)==0)
	{
		return -1;
	}
	
	socket_fd=socket(PF_INET,SOCK_STREAM,0);
	if(socket_fd==-1)
	{
		printf("error on client socket creation [%s]\n",strerror(errno));
		return -1;
	}
	if(connect(socket_fd,(struct sockaddr *)&caddr,sizeof(struct sockaddr))==-1)
	{	
		printf("error on client socket conenction [%s]\n",strerror(errno));
		return -1;
	}
	
	printf("Connected to server with client id: %d\n",socket_fd);
	return socket_fd;
}

/*değerlendirmesi yapılır.
Hangi mesajların
gönderilebileceği ve
karşılığında dönecek cevap
formatı Tablo 1’de
belirtilmiştir.*/
int answerMessage(int socket, char *msg)
{
	printf("message: %s\n",msg);
	if(strncmp(msg,"name",4)==0)
	{
	char answer[100];
		if(read(socket, &answer, sizeof(answer))!=sizeof(answer)){
			printf("Error reading data [%s]\n",strerror(errno));
			return (-1);
		}	
	printf("----------------------------------------------------\n");
	printf("Name: %s\n",answer);
	}
	
	if(strncmp(msg,"temp",4)==0)
	{
		int temp[4];
		if(read(socket, &temp, sizeof(temp))!=sizeof(temp)){
                        printf("Error reading data [%s]\n",strerror(errno));
                        return (-1);
                }
		
		printf("Temperature: (motor) %d , (indoor) %d , (outdoor) %d\n",temp[0],temp[1],temp[2]);
	}
	
	
	if(strncmp(msg,"door",4)==0)
	{
		int door[4];
		
			if(read(socket, &door, sizeof(door))!=sizeof(door)){
                        printf("Error reading data [%s]\n",strerror(errno));
                        return (-1);
                }	
		printf("Door: (frontLeft) %d ,(frontRight) %d,(rearLeft) %d,(rearRight) %d\n",door[0],door[1],door[2],door[3]);
	}
	
	if(strncmp(msg,"speed",5)==0)
	{
		int speed;
		if(read(socket, &speed, sizeof(speed))!=sizeof(speed))
		{
            printf("Error reading data [%s]\n",strerror(errno));
        	return (-1);
        }
	
		printf("Speed: %d\n",speed);

	}
	if(strncmp(msg,"wheelpress",10)==0)
	{
		int wheel[4];
		
		if(read(socket,&wheel, sizeof(wheel))!=sizeof(wheel))
        {
        	printf("Error writing data [%s]\n",strerror(errno));
        	return (-1);
        }
		printf("Wheel Pressure : (frontLeft) %d ,(frontRight) %d ,(rearLeft) %d, (rearRight) %d\n",wheel[0],wheel[1],wheel[2],wheel[3]);
	}
	
//	if(strncmp(msg,"temp",4))
//	if(strncmp(msg,"temp",4))
}


