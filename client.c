#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main(){

  char *ip = "127.0.0.2";
  int port = 8808;

  int sock;
  struct sockaddr_in addr;
  socklen_t addr_size;
  char buffer[1024];
  int n;

  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0){
    perror("[-]Socket error");
    exit(1);
  }
  printf("[+]TCP server socket created.\n");

  memset(&addr, '\0', sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = port;
  addr.sin_addr.s_addr = inet_addr("127.0.0.1");

  connect(sock, (struct sockaddr*)&addr, sizeof(addr));
  printf("Connected to the server.\n");

  
  for(;;)
  {
      printf("\n\n\t\t\t*****************************\n");
        printf("\t\t\tSCHEDULING ALGORITHMS\n");
 printf("\t\t\t*****************************\n\n");

        printf("\t\t\t1. FCFS\n");
        printf("\t\t\t2. SJF\n");
        printf("\t\t\t3. RR\n\n");
        printf("\t\t\t4. Exit\n\n");
        bzero(buffer, 1024);
        read(sock, buffer, sizeof(buffer));
        if ((strncmp(buffer, "exit", 4)) == 0) {
            printf("Client Exit...\n");
            break;
        }
        send(sock, buffer, strlen(buffer), 0);
  }
  strcpy(buffer, "HELLO, THIS IS CLIENT.");
  printf("Client: %s\n", buffer);

  bzero(buffer, 1024);
  recv(sock, buffer, sizeof(buffer), 0);
  printf("Server: %s\n", buffer);

  close(sock);
  printf("Disconnected from the server.\n");

  return 0;

}