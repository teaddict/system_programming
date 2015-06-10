/*
 * =====================================================================================
 *
 *       Filename:  client.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/06/15 23:22:49
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  teaddict (), cyberasker@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#ifndef CLIENT_H
#define CLIENT_H
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

int makeConnection(char *ip, int port);
/*Burada, verilen ip ve port degerine sahip
sunucu ile baglanti kurulur ve baglantinin
soket numarasi dondurulur.
Basarisizise, -1 doner.*/

//the print messages thread function
void *print_messages(void *);

//the send messages thread function
void *send_messages(void *);

#endif
