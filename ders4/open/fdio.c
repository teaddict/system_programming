/*
 * =====================================================================================
 *
 *       Filename:  textio.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  14/04/15 10:14:45
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  teaddict (), cyberasker@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

//HER SATIRIN SONUN END OF LINE KARAKTERI VAR

#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/types.h>
#include<stdio.h>
#include<errno.h>

int show_open()
{
	int x,y,z;
	char *filename="./fopen.dat",str[128];
	int vals[1000]={[0 ... 999]=0xff}, vals2[1000];
	int fd, flags;
	mode_t mode;
	
	flags=O_WRONLY | O_CREAT | O_EXCL; //create a new file, no overwrite
	mode=S_IRUSR | S_IWUSR | S_IRGRP;
	
	fd=open(filename,flags,mode);

	if(fd==-1)
	{	//terminal IO üserine yazdırıyor burda tıpkı bi file yazdırır gibi
		fprintf(stderr,"fopen failed.error=%s (%d)\n",strerror(errno));
		return(-1);
	}
	
	if(write(fd,(char *)vals,sizeof(vals)) != sizeof(vals))
	{	//üç karakter okur
		fprintf(stderr,"fopen failed.error=%s (%d)\n",strerror(errno));
		return(-1);
	}
	
	close(fd);
	fd=-1;


	//setup for reading
	flags=O_RDONLY;
	fd=open(filename,flags,0);

	if(fd==-1)
	{
		fprintf(stderr,"fopen failed.error=%s (%d)\n",strerror(errno));
		return(-1);
	}
	
	
	if(read(fd,(char *)vals2,sizeof(vals2)) != sizeof(vals2))
	{	
		fprintf(stderr,"fopen failed.error=%s (%d)\n",strerror(errno));
		return(-1);
	}

	close(fd);

return(0);
}


int main()
{
	show_open();
	return 0;

}
