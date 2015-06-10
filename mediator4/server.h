/*
 * =====================================================================================
 *
 *       Filename:  server.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/06/15 22:11:20
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  teaddict (), cyberasker@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef SERVER_H
#define SERVER_H
#define bool int
#define true 1
#define false 0

#include<sys/socket.h>
#include<sys/types.h>
#include<errno.h>
#include<stdio.h>
#include<string.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>
#include "Agent.h"

bool initializeConnection(int *serverSocket, int port); /*Bu fonksiyonda, soket yaratma
ve bind işlemi yapılır ve sunucu soketin
numarası serverSocket ile döndürülür.*/
int makeConnection(int serverSocket); /*Burada, serverSocket ile listen işlemi
başlatılır, bağlantı talebi gelince, bağlantı kabul
(accept) edilmesine mütaakip, bağlantı
soketinin numarası döndürülür.*/

void *register_agent(void *socket_desc);
/* burda thread açılır ve yeni ajan kaydedilir */

void *sendMessage(void *socket_desc);
/*burda thread açılır ve mesajlar yönlendirilir */


#endif


