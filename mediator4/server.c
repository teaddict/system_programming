/*
 * =====================================================================================
 *
 *       Filename:  server.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/06/15 22:18:20
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  teaddict (), cyberasker@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

/*burda sadece ./server ile çalıştırıyoruz
bu ekran bizim log ekranımız. server üstündeki tüm işlemleri 
burdan okuyabilir görebiliriz
*/


#include"server.h"
#include <sys/ioctl.h>
#include<semaphore.h>
#include<pthread.h>

#define MAX_CLIENT 5

Agent agent[MAX_CLIENT];
int agentnum=0;

sem_t sem2;

pthread_mutex_t mutex;

bool initializeConnection(int *serverSocket, int port)
{
        int server;
        /*Adresi olusturalim.*/
        struct sockaddr_in saddr;
        saddr.sin_family=AF_INET;
        saddr.sin_port=htons(port);
        saddr.sin_addr.s_addr=htonl(INADDR_ANY);
        /*Sunucu olarak baglanti isteklerini dinleyecek soketi yaratalim.*/
        server=socket(PF_INET, SOCK_STREAM, 0);
        if(server==-1){
                printf("Error on socket creation [%s]\n",strerror(errno));
                return false;
        }
        /*Sokete olusturdugumuz adresi ve ayarlari baglayalim.*/
        if(bind(server, (struct sockaddr *)&saddr, sizeof(struct sockaddr))==-1){
                printf("Error on socket bind [%s]\n",strerror(errno));
                return false;
        }
        /*Sunucu soketi, dinleme isleminde kullanilmak uzere dondurelim. */
        *serverSocket=server;
        return true;
}



/* burda thread açılır ve yeni ajan kaydedilir */
void *register_agent(void *socket_desc)
{
	//Get the socket descriptor
    int sock = *(int*)socket_desc;
    int read_size;
    char *message , client_message[2000];

    //Receive a message from client
    if( (read_size = recv(sock , client_message , 2000 , 0)) > 0 )
    {
        //end of string marker
                client_message[read_size] = '\0';
		puts(client_message);
		char *ptr;
	        char *nptr;
        	char tmp[100];
       		int tmpsubject;
        	int i=0;
        	nptr=strdup(client_message);
        	/*Gelen mesajin icerigine bakalim. Icerigine uygun cevap gonderelim.*/
        	ptr=strtok(nptr, ";");
        	while(ptr !=NULL)
		{
                /*GELEN MESAJ: name; */
                /*GELEN MESAJ: ; */
                	if(strstr(ptr,"register"))
                	{
                        /* mesajı al*/
                        	sscanf(ptr,"%s %d",tmp,&tmpsubject); //ayırdık
                        	agent[agentnum].clientID=sock;
				agent[agentnum].subject=tmpsubject;
				agentnum=agentnum+1;
				printf("agentnum: %d\n",agentnum);		
			}
			ptr=strtok(NULL, ";");
		}
                //clear the message buffer
		free(nptr);
                memset(client_message, 0, 2000);
    		//Send some messages to the client
    		message = "Welcome! You are connected to server!\n";
    		write(sock , message , strlen(message));
    
   		sleep(1);
    }//end if

    if(read_size == 0)
    {
        puts("Client disconnected");
        fflush(stdout);
    }
    else if(read_size == -1)
    {
        perror("recv failed");
    }

//    sem_post(&sem2);
    return 0;

	
}


/*burda thread açılır ve mesajlar yönlendirilir */
void *sendMessage(void *socket_desc)
{
    int sock = *(int*)socket_desc;
    int read_size;
    char *message , client_message[2000];
        
    while( (read_size = recv(sock , client_message , 2000 , 0)) > 0 )
    {
        //end of string marker
		pthread_mutex_lock(&mutex);
                client_message[read_size] = '\0';
		printf("client- %d sent [%s]\n",sock,client_message);
                char *ptr;
                char *nptr;
                char tmp[100],tmpmsg[100],msg[100];
                int tmpsubject;
                int i=0;
                nptr=strdup(client_message);
                /*Gelen mesajin icerigine bakalim. Icerigine uygun cevap gonderelim.*/
                ptr=strtok(nptr, ";");
                while(ptr !=NULL)
                {
			if(strstr(ptr,"haber")!=NULL)
                	{
                        /* mesajı al*/
                        	sscanf(ptr,"%s %[^\t\n]",tmp,tmpmsg); //ayırdık
                        	sprintf(msg,"[%s] %s;",tmp,tmpmsg); // formatlayıp gönderiyoruz
				printf("formatlı mesaj :%s %s\n",tmp,tmpmsg);
				printf("agentnum: %d\n",agentnum);		
                        	for(i=0; i<agentnum; i++)
                        	{
					printf("agent id : %d subject: %d\n",agent[i].clientID,agent[i].subject); 
                                	//kendi kendine göndermesin
                                	if(agent[i].clientID==sock)
                                        {continue;}
                                	if(agent[i].subject==1 || agent[i].subject==4 || agent[i].subject==5)
                                	{
                                        	if(write(agent[i].clientID,msg,strlen(msg))!=strlen(msg))
                                        	{
                                                	printf("Error writing data [%s]\n",strerror(errno));
                                        	}
						else
							printf("message sent to agent.clientID:%d\n",agent[i].clientID);
                                	}
                        	}
                	}
			
			else if(strstr(ptr,"sohbet")!=NULL)
                        {
                        /* mesajı al*/
                                sscanf(ptr,"%s %[^\t\n]",tmp,tmpmsg); //ayırdık
                                sprintf(msg,"[%s] %s;",tmp,tmpmsg); // formatlayıp gönderiyoruz
                                for(i=0; i<agentnum; i++)
                                {
                                        //kendi kendine göndermesin
                                        if(agent[i].clientID==sock)
                                        {continue;}

                                        if(agent[i].subject==2 || agent[i].subject==4 || agent[i].subject==6)
                                        {
                                                if(write(agent[i].clientID,msg,strlen(msg))!=strlen(msg))
                                                {
                                                        printf("Error writing data [%s]\n",strerror(errno));
                                                }
                                        }
                                }
                        }
			else if(strstr(ptr,"genel")!=NULL)
                        {
                        /* mesajı al*/
                                sscanf(ptr,"%s %[^\t\n]",tmp,tmpmsg); //ayırdık
                                sprintf(msg,"[%s] %s;",tmp,tmpmsg); // formatlayıp gönderiyoruz
                                for(i=0; i<agentnum; i++)
                                {
                                        //kendi kendine göndermesin
                                        if(agent[i].clientID==sock)
                                        {continue;}

                                        if(agent[i].subject==3 || agent[i].subject==5 || agent[i].subject==6)
                                        {
                                                if(write(agent[i].clientID,msg,strlen(msg))!=strlen(msg))
                                                {
                                                        printf("Error writing data [%s]\n",strerror(errno));
                                                }
                                        }
                                }
                        }
			else
			{
				printf("\nseçilen başlık bulunmamakta....\n");
			}
	
			ptr=strtok(NULL, ";");
                }//end second while
    
    		//clear the message buffer
    		free(nptr);
    		memset(client_message, 0, 2000);
		pthread_mutex_unlock(&mutex);
	}//end first while
    if(read_size == 0)
    {
        puts("Client disconnected");
        fflush(stdout);
    }
    else if(read_size == -1)
    {
        perror("recv failed");
    }

    return 0;
}

int main(int argc,char **argv)
{
	int serverSocket;
	int port=7777;
	if(!initializeConnection(&serverSocket,port))
        {
                printf("Unsuccesful initialization for connection...\n");
                return 0;
        }
	
	struct sockaddr_in caddr;
        int client[MAX_CLIENT];
        /*Baglanti istekleri icin dinlemeye baslayalim.*/
        if(listen(serverSocket, 5)==-1)
        {
                printf("Error on socket listen [%s]\n",strerror(errno));
                return (-1);
        }
        /*Baglanti talebi geldi, baglantinin idamesini yeni bir sokete tahsis edelim.*/
        uint32_t inet_len=sizeof(caddr);
	pthread_t thread_reg[MAX_CLIENT],thread_send[MAX_CLIENT];
        int i=0, j=0;
        /*maxClient sayisi kadar musteri ile bagnalti kuruluyor.*/
       
// Set the socket I/O mode: In this case FIONBIO
// enables or disables the blocking mode for the
// socket based on the numerical value of iMode.
// If iMode = 0, blocking is enabled;
// If iMode != 0, non-blocking mode is enabled.
        int iMode=1;
	for(i=0; i<MAX_CLIENT; i++)
	{
        	ioctl(client[i], FIONBIO, &iMode);
        }
	int noThread=0;
	while(noThread < 5)
        {	
		//this is where client connects. svr will hang in this mode until client conn
		client[noThread]=accept(serverSocket, (struct sockaddr *)&caddr, &inet_len);
		printf("Server new client connection [%s/%d]\n",inet_ntoa(caddr.sin_addr),caddr.sin_port);
                if( pthread_create( &thread_reg[noThread] , NULL ,  register_agent , (void*) &client[noThread]) < 0)
                {
                        perror("could not create thread");
                        return 1;
                }
		if( pthread_create( &thread_send[noThread] , NULL ,  sendMessage , (void*) &client[noThread]) < 0)
                {
                        perror("could not create thread");
                        return 1;
                }
                puts("Register assigned");
		
		noThread++;
        }
	
	noThread=0;
	while(noThread < 5)
	{
//		sem_wait(&sem2);

                pthread_join( thread_reg[noThread], NULL);
                pthread_join( thread_send[noThread] , NULL);
		puts("sendMessage thread assigned");
		noThread++;
	}
       
	/*Soketleri kapatalim.*/
        for(i=0;i<MAX_CLIENT;i++)
        {
                close(client[i]);
        }


    	return 0;
}


