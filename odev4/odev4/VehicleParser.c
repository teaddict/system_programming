/*
 * =====================================================================================
 *
 *       Filename:  VehicleParser.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  28/03/15 17:48:14
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  teaddict (), cyberasker@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include"VehicleParser.h"
#include<stdlib.h>

bool parseTemp(char *str,float *motor,float *indoor,float *outdoor)
{
	char *ptr;
	char *nptr;
	char tmp[100];
	int temp;
	bool ret = false;

	nptr=strdup(str);
	
	ptr=strtok(nptr,";");
	while(ptr!=NULL)
	{
		if(strstr(ptr,"temp")!=NULL)
		{
			ret=true;
			break;
		}
		ptr=strtok(NULL,";");
	}
	free(nptr);
	
	sscanf(ptr,"%s %d",tmp,&temp);
	*motor=(float)((temp&0xff000000)>>24);
	*indoor=(float)((temp&0x00ff0000)>>16);
	*outdoor=(float)((temp&0x0000ff00)>>8);

	return ret;
	

/* BENIM YAPTIĞIM ÇALIŞAN
	int number;
	sscanf(str,"%d",&number);
	int *x=(int *)motor;
	int *y=(int *)indoor;
	int *z=(int *)outdoor;

	*x=(number & 0XFF000000) >> 24;
	*y=(number & 0x00FF0000) >> 16;
	*z=(number & 0x0000FF00) >> 8;
	
	*motor=(float)(*x);
	*indoor=(float)(*y);
	*outdoor=(float)(*z);	
	if(isdigit(*x)&&isdigit(*y)&&isdigit(*z))
		return true;
	else
		return false;
*/
}

bool parseName(char *str, char *name)
{
	char *ptr;
	char *nptr;
	char n[100];
	char nam[100];
	bool ret = false;
	
	nptr=strdup(str);
	ptr=strtok(nptr,";");
	
	while(ptr!=NULL)
	{
		if(strncmp("name",ptr,4)==0)
		{
			ret=true;
			break;
		}
	ptr=strtok(NULL,";");
	}
	free(nptr);
	
	sscanf(ptr,"%s %s",n,nam);
	strncpy(name,nam,strlen(nam));
	
	return ret;
}

bool parseSpeed(char *str, int *speed)
{
	char *ptr;
	char *nptr;
	char tmp[100];
	bool ret=false;
	
	nptr=strdup(str);
	ptr=strtok(nptr, ";");
	while(ptr !=NULL)
	{
		if(strstr(ptr,"speed")!=NULL)
		{
			ret=true;
			break;
		}
	ptr=strtok(NULL, ";");
	}
	free(nptr);
	
	sscanf(ptr,"%s %d",tmp,speed);
	return ret;
}

bool parseDoor(char *str, State *fL, State *fR, State *rL, State *rR)
{
	char *ptr;
	char *nptr;
	char tmp[100];
	int door[4];
	bool ret=false;

	nptr=strdup(str);
	ptr=strtok(nptr, ";");
	
	while(ptr !=NULL)
	{
		if(strstr(ptr,"door")!=NULL)
		{
			ret=true;
			break;
		}
	ptr=strtok(NULL, ";");
	}
	free(nptr);
	
	sscanf(ptr,"%s %d %d %d %d",tmp,&door[0],&door[1],&door[2],&door[3]);
	
	*fL=door[0];
	*fR=door[1];
	*rL=door[2];
	*rR=door[3];
	
	return ret;
}

bool parseWheelPress(char *str, int *fL, int *fR, int *rL, int *rR)
{

	char *ptr;
	char *nptr;
	char tmp[100];
	int press;
	bool ret=false;

	nptr=strdup(str);
	ptr=strtok(nptr, ";");
	while(ptr !=NULL)
	{
		if(strstr(ptr,"wheelpress")!=NULL)
		{
			ret=true;
			break;
		}
	ptr=strtok(NULL, ";");
	}
	free(nptr);
	
	sscanf(ptr,"%s %d",tmp,&press);
	
	*fL=(int)((press&0xff000000)>>24);
	*fR=(int)((press&0x00ff0000)>>16);
	*rL=(int)((press&0x0000ff00)>>8);
	*rR=(int)((press&0x000000ff));

	return ret;

}

