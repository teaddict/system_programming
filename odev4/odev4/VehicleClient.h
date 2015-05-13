/*
 * =====================================================================================
 *
 *       Filename:  VehicleClient.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/05/15 01:31:12
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  teaddict (), cyberasker@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#ifndef VEHICLECLIENT_H
#define VEHICLECLIEN_H

#include"VehicleControl.h"
#include <stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<errno.h>
#include<arpa/inet.h>

#define true 1
#define false 0

int makeConnection(char *ip, int port);
/*Burada, verilen ip
numarasina ve port numarasi
ile baglanti işlemi kurulur.
Baglanti kurulduğunda soket
numarası döndürülür. Hata
varsa -1 döndürür.*/
int answerMessage(int socket, char *msg); /*socket numarasına sahip
bağlantıya mesaj gonderirip,
gelen cevap mesajinin
eğerlendirmesi yapılır.
Hangi mesajların
gönderilebileceği ve
karşılığında dönecek cevap
formatı Tablo 1’de
belirtilmiştir.*/
#endif