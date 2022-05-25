#include<sys/wait.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include "menu.h"

void fun(int d)
{
	
	//int ch=atoi(buffer);
	switch (d)
                {
                        case 1:;
                               if (fork()==0)
                               {
                                char *args1[]={"./fcfs",NULL};
                                execv(args1[0],args1);
                               }
                        break;
                        case 2:;
                               if(fork()==0)
                               {
                                char *args2[]={"./sjf",NULL};
                                execv(args2[0],args2);
                               }
                        break;
                        case 3:;
                               if(fork()==0)
                               {
                                char *args3[]={"./rr",NULL};
                                execv(args3[0],args3);
                               }
                        break;
                 //      case 4:;
                   //             exit(EXIT_SUCCESS);
                     //   break;
                        default:
                               printf("invalid\n");
                        break;

                 }wait(NULL);
}
