/*
 * =====================================================================================
 *
 *       Filename:  dig_t.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  22/04/15 21:35:10
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  teaddict (), cyberasker@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <netdb.h>

int main (int argc, char *argv[]) {
    struct hostent *hstnm;
    if (argc != 2) {
        fprintf(stderr, "usage: %s hostname\n", argv[0]);
        return 1;
    }
    hstnm = gethostbyname (argv[1]);
    if (!hstnm)
        return 1;
    printf ("Name: %s\n", hstnm->h_name);
    return 0;
}
