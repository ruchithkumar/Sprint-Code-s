#include<stdio.h>
#include<stdlib.h>
#include "display_fcfs_sjf.h"
#define FILENAME "data.dat"
bool display()
{
        struct node *p_trav = g_p_head;

        print_lines();
        printf("\nprocess_id\tarrival_time\tburst_time\n");
        print_lines();
        while(p_trav != NULL)
        {
                printf("\n %d\t\t%d\t\t%d ",p_trav->pid,p_trav->arr_t, p_trav->bur_t);
                p_trav = p_trav->next;
        }
        printf("\n");
        print_lines();
        return true;
}


bool readfile()
{
        FILE *fp;
        processes_t process;
        fp = fopen(FILENAME, "r");
        if (fp == NULL)
        {
                printf("Error : Unable to open for reading\n");

                return false;
        }
        while (fscanf(fp, "%d %d %d", &process.pid, &process.arr_t, &process.bur_t) != EOF)
        {
                process.c_t = 0;
                process.t_a_t = 0;
                process.w_t = 0;
                insert_linkedlist(process);
        }
        fclose(fp);
        return true;
}

void print_lines()
{
        for(int i=0;i<60;i++)
        {
                printf("-");
        }
}

