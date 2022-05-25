#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "menu.h"
#define EXIT 4

int main(){
        int serverfd = socket (AF_INET, SOCK_STREAM, 0);

        if (serverfd == -1){
                  perror ("");
                  return EXIT_FAILURE;
        }
        printf ("Socket Descriptor = %d \n", serverfd);
        struct sockaddr_in server;
        server.sin_family = AF_INET;
        server.sin_port = htons (8000);
        server.sin_addr.s_addr = htonl(INADDR_ANY);

        if(bind (serverfd, (struct sockaddr *) &server, sizeof (server)) <0)
        {
                  perror ("Socket binding fail");
                  exit (EXIT_FAILURE);
        }
        printf ("Bind successful \n");
        if(listen (serverfd, 4) <0){
                  perror ("");
                  exit (EXIT_FAILURE);
        }
        printf ("Listening to connections \n");

        struct sockaddr_in client;
        int len=sizeof(struct sockaddr_in);
        int clientfd = accept (serverfd, (struct sockaddr *) &client, &len);
        if(clientfd == -1){
                  perror ("");
                  exit (EXIT_FAILURE);
        }
        printf ("Connection established \n");
        char buffer[100] = "";
        while(1){
                read (clientfd, buffer, 20);
                printf ("client : %s \n", buffer);
                int recv_client = atoi(buffer);
                if(recv_client == EXIT){
                        break;
                }
        }
        return 0;
}
