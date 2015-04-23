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

#include<stdio.h>
#include<errno.h>
#include<string.h>
#include<string.h>

int show_open()
{
	int x,y,z;
	FILE *file;
	char *filename="./fopen.dat",str[128];
	
	file=fopen(filename,"r+");

	if(file==NULL)
	{	//terminal IO üserine yazdırıyor burda tıpkı bi file yazdırır gibi
		fprintf(stderr,"fopen failed.error=%s (%d)\n",strerror(errno));
		return(-1);
	}
	
	while(!feof(file))
	{	//üç karakter okur
		if(fscanf(file,"%d %d %d",&x,&y,&z)==3)
		{
			printf("read coordinates %d %d %d \n ",x,y,z);
		}
		//128 karakter okudu ve yazdırdı -> satır sonu karakterini de alır. '\n' dahil
		if(!feof(file))
		{
			fgets(str,128,file);
			if(fgets(str,128,file)!=NULL)
				printf("read line %s \n",str);
		}
	}
	
	x=21;
	y=34;
	z=98;
//DOSYAYA VERİ YAZDIRDIK
	fprintf(file,"%d %d %d\n",x,y,z);
	printf("%d %d %d\n",x,y,z);
	
	if(fputs(str,file)>=0)
		printf("wrote line [%s]\n",str);

	fflush(file);
//close file	
	fclose(file);

return(0);
}


int main()
{
	show_open();
	return 0;

}
