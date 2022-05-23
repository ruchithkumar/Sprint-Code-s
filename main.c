#include<sys/wait.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
	int op1;
	while(1)
	{ 
		printf("\n-----------------------------------------------------------------------------");
   		printf("\n\t CONTENTS \t\n");
		printf("-----------------------------------------------------------------------------");
		printf("\n1\timplement first come first serve\n2\timplement shortest job first\n3\timplement round robin\n4\texit\n");
    		scanf("%d",&op1);
    		switch (op1)
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
			case 4:;
			        exit(EXIT_SUCCESS);
			break;
			default:
			       printf("invalid\n");
			break;

   		 }wait(NULL);	
	}
}
