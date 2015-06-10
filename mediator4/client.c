/*
 * =====================================================================================
 *
 *       Filename:  client.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/06/15 23:25:52
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  teaddict (), cyberasker@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

/* bu bizim client programımız ./client haber vs.
şeklinde çalıştırıyoruz. burdaki switch menusu 1 mesaj okumak için
2 mesaj atmak için 3 çıkış için.
hangi ekranda olursak olalım 1,2,3 komutları işliyor ve ona göre sonuç veriyor.
*/

/*üye olduğumuz gruplar sayesinde gelen mesajları okuyabiliriz.
ama üye olmadığımız gruplara da mesaj atabiliriz. her mesajda hangi grupa atıcağımızı belirleriz.
*/

#include"client.h"
#include<pthread.h>
#include<semaphore.h>

#define READ 1
#define WRITE 2

sem_t sem1,sem2;

pthread_t thread_print,thread_send;
pthread_mutex_t mutex,condition;


int semaphore = 0;

void acquire(int);

//the print messages thread function
void *print_messages(void *socket_desc)
{
    int sock = *(int*)socket_desc;
    int read_size;
    char *message , client_message[2000];
    
    while( (read_size = recv(sock , client_message , 2000 , 0)) > 0 )
    {
    		sem_wait(&sem1);
		pthread_mutex_lock(&mutex);
        	//end of string marker
                client_message[read_size] = '\0';
		printf("\n####gelen mesaj###\n");
		puts(client_message);
		printf("\n##################\n");
		
    		//CLEAR MESSAGE BUFFER
		memset(client_message, 0, 2000);
		pthread_mutex_unlock(&mutex);
    		acquire(WRITE);
    		sleep(3);
    }
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


//the send messages thread function
void *send_messages(void *socket_desc)
{
	int sock = *(int*)socket_desc;
	int read_size;

	char msg[100];
        char tmpmsg[100];
	
	while(1)
        {
		sem_wait(&sem2);
		pthread_mutex_lock(&mutex);
                /*Once kullanicidan sunucudaki bilgileri degistirmek isteyip istemedigini
                soralim.*/
                printf("mesaj formatı: <topic> <msg>;\n");
                printf("mesaj giriniz:\n");
                scanf("%[^\n]", tmpmsg);
                strcpy(msg,tmpmsg);
                if(write(sock, msg, strlen(msg))!=strlen(msg))
                {
                        printf("Error sending data [%s]\n",strerror(errno));
                }
                else
                {
                        printf("mesaj gönderildi...\n");
                        printf("gönderilen mesaj : %s\n",msg);
                }
		
		memset(msg, 0, 100);	
		memset(tmpmsg, 0, 100);
		pthread_mutex_unlock(&mutex);
		acquire(READ);
		sleep(3);
	}
}

int makeConnection(char *ip, int port)
{
        int socket_fd;
        /*Adresi olusturalim.*/
        struct sockaddr_in caddr;
        caddr.sin_family=AF_INET;
        caddr.sin_port=htons(port);
        if(inet_aton(ip,&caddr.sin_addr)==0)
        {
                return (-1);
        }
        /*Sunucu olarak baglanti kuracak soketi yaratalim.*/
        socket_fd=socket(PF_INET, SOCK_STREAM, 0);
        if(socket_fd==-1)
        {
                printf("Error on socket creation [%s]\n",strerror(errno));
                return (-1);
        }
        /*Suucuya baglanti istegi gonderip, baglantiyi kuralim.*/
        if(connect(socket_fd,(const struct sockaddr *)&caddr,sizeof(struct sockaddr))==-1)
        {
                printf("Error on socket connect [%s]\n",strerror(errno));
                return (-1);
        }
        /*Baglanti kurulan soket numarasini dondurelim.*/
        return socket_fd;
}

void acquire (int process) 
{

	printf ("Acquiring semaphore\n");
    		
	if (process == READ) 
	{
		printf("process read\n");	
		sem_post(&sem1);
    	}
	else if (process == WRITE) 
	{
		printf("process write\n");
		sem_post(&sem2);
    	}
	else 
	{
      		fprintf (stderr, "Illegal parameter in acquire!\n");
      		exit (1);
    	}
}


int main(int argc, char **argv)
{
        int port=7777;
        char ip[16]="127.0.0.1";
        char msg[100];
        int tmpsubject;
	int sockID;
	
	sem_init(&sem1, 0, 0); //Initialize to zero
	sem_init(&sem2, 0, 0); //Initialize to zero
        
	if(argc<2)
        {
                printf("less arguments... \n");
		printf("enter ./client x\n");
                return 0;
        }
	
	if(argc==2)
        {
                if(!strncmp(argv[1],"haber",5))
                {
                        tmpsubject=1;
                }
                else if(!strncmp(argv[1],"sohbet",6))
                {
                        tmpsubject=2;
                }

                else if(!strncmp(argv[1],"genel",5))
                {
                        tmpsubject=3;
                }
                else
                {
                        printf("False arguments...\n");
                        return 0;
                }


        }//end of 2

	else if(argc==3)
        {
                if(!(strncmp(argv[1],"haber",5) && strncmp(argv[2],"sohbet",6)))
                {
                        tmpsubject=4;
                }

                else if(!(strncmp(argv[1],"haber",5) && strncmp(argv[2],"genel",5)))
                {
                        tmpsubject=5;
                }

                else if(!(strncmp(argv[1],"sohbet",6) && strncmp(argv[2],"genel",5)))
                {
                        tmpsubject=6;
                }
                else
                {
                        printf("False arguments...\n");
                        return 0;
                }
        } //end of 3

         /*Sunucu ile baglanti kuralim.*/
        if((sockID=makeConnection(ip,port))==-1)
        {
                printf("Unsuccesful setup for connection...\n");
                return 0;
        }
	
	sprintf(msg,"register %d;",tmpsubject);
        if(write(sockID, msg, strlen(msg))!=strlen(msg))
        {
                printf("Error sending data [%s]\n",strerror(errno));
        }
        else
        {
                printf("agent registered\n");
                printf("gönderilen mesaj %s\n",msg);
        }
	
	if( pthread_create( &thread_print , NULL ,  print_messages , (void*) &sockID) < 0)
        {
        	perror("could not create thread");
                return 1;
        }
        if( pthread_create( &thread_send , NULL ,  send_messages , (void*) &sockID) < 0)
        {
                perror("could not create thread");
                return 1;
        }
	
	int nextProcess;
	while (1) 
	{	
        	printf ("\nScheduler: Next process to run((reading messages - 1) OR (writing messages - 2) OR (exit - 3) :\n");
        	scanf ("%d", &nextProcess);
      		switch (nextProcess) 
		{
      			case 1: sem_post(&sem1);
			//	acquire(READ); //YAZMAYI KİLİTLE
				break;
      			case 2: sem_post(&sem2);
			//	acquire(WRITE); //OKUMAYI KİLİTLE
				break;
			case 3:
				kill(thread_print,SIGTERM);
				kill(thread_send,SIGTERM);
				exit(0);
      			default:
				printf ("Scheduler: Entered illegal command: %c\n", nextProcess);
				break;
      		}
   	}//end while
	
	close(sockID);
	return 0;
}
