/*
 * =====================================================================================
 *
 *       Filename:  VehicleServer.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/05/15 00:38:34
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  teaddict (), cyberasker@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */


#ifndef VEHICLESERVER_H
#define VEHICLESERVER_H

#include"VehicleControl.h"
#include <stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<errno.h>
#include<arpa/inet.h>

#define true 1
#define false 0

int initializeConnection(int *serverSocket, int port);
/*Bu fonksiyonda, soket yaratma ve bind
işlemi yapılır ve sunucu soketin
numarası
serverSocket ile
döndürülür.*/
int makeConnection();
/*Burada, listen işlemi başlatılır,
bağlantı talebi gelince, bağlantı kabul
(accept) edilmesine mütaakip, bağlantı
soketinin numarası döndürülür.*/
int answerMessage(int clientSocket,Vehicle *); 
/*clientSocket numarasına sahip
bağlantıdan gelen mesaj olup
olmadığına bakılır (read ile),
mesaj varsa
cevap gönderilir
(write ile). Hangi mesaja hangi
cevap döndürülecek, Tablo 1’de
belirtilmiştir.*/

#endif