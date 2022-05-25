#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <strings.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "menu.h"
#define EXIT 4

int main(){
        int clientfd = socket (AF_INET, SOCK_STREAM, 0);

        if (clientfd < 0){
                  perror ("Socket connection failed...");
                  exit (0);
        }

        struct sockaddr_in server;

        server.sin_family = AF_INET;
        server.sin_port = htons (8000);
	server.sin_addr.s_addr=htonl(INADDR_LOOPBACK);
	
       // server.sin_addr.s_addr = inet_addr ("192.168.0.105");

        if (connect (clientfd, (struct sockaddr *) &server, sizeof (server)) <0){
                  printf ("Connection failed...");
                  exit (0);
        }


        char buff[20] = " ";

        while(1){

                 printf("\n-----------------------------------------------------------------------------");
                 printf("\n\t CONTENTS \t\n");
                 printf("-----------------------------------------------------------------------------");
                 printf("\n1\timplement first come first serve\n2\timplement shortest job first\n3\timplement round robin\n4\texit\n");
		 printf("\n");
                 __fpurge(stdin);
                 fgets(buff, 20, stdin);
                 write(clientfd, buff, sizeof(buff));
		 int d=atoi(buff);
                 if(d == 4){
                       break;
                 }
		 fun(d);
        }
        close(clientfd);

        return 0;
}
