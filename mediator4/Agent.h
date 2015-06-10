/*
 * =====================================================================================
 *
 *       Filename:  Agent.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/06/15 19:23:53
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  teaddict (), cyberasker@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */


/*
#sistem mantığı şöyle olacak.
#subject değişkeninde konumuzu tutacağız
#haber = 1 , sohbet = 2 , genel = 3, haber sohbet = 4, haber genel = 5, sohbet genel = 6 , değerleri olarak saklancak
#subject = 1 ise 1 ,4 ve 5 de üye olmuş ajanlara mesaj gidecek
#subject = 2 ise 2 ve  6 ya mesaj gidecek
#subject = 3 ise 3 , 5 ve 6 ya mesaj gidecek
*/

typedef struct
{
        int clientID;
        int subject;
}Agent;

