/*
 * =====================================================================================
 *
 *       Filename:  dig.c
 *
 *    Description:  dns resolve
 *
 *        Version:  1.0
 *        Created:  22/04/15 21:24:19
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
#include<arpa/inet.h>
#include<netdb.h>
int main(int argc,char **argv)
{
	char dest[]="anadolu.edu.tr";
	struct hostent *hstinfo;
	struct in_addr **addr_list;

//ARGUMAN ALARAK : ./dig google.com
/*	
	hstinfo=gethostbyname(argv[1]);
	if(hstinfo == NULL) {
          fprintf(stderr, "rlogin: %s: unknown host\n", argv[1]);
          exit(2);
	}
*/
	if((hstinfo=gethostbyname(dest))==NULL)
	{ printf("not found\n"); }
	
	addr_list=(struct in_addr **)hstinfo->h_addr_list;
	printf("DNS lookup [%s] address [%s]\n",hstinfo->h_name,inet_ntoa(*addr_list[0]));

return 0;
}


