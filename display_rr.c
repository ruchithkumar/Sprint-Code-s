#include<stdio.h>
#include<stdlib.h>
#include "display_rr.h"
#include<stdbool.h>
#define FILENAME "data.dat"


// displaying the contents of jobs

bool display_rr()
{
        struct node *p_trav =g_p_head;
        printf("\n\t\t*****ROUND ROBIN*****\n");
        print_lines();
        printf("\nprocess_id\tarrival_time\tburst_time\n");
        print_lines();
        do
        {
                printf("\n %d\t\t%d\t\t%d",p_trav->pid,p_trav->arr_t, p_trav->bur_t);
                p_trav = p_trav->next;
        }while(p_trav!=g_p_head);
        printf("\n");
        print_lines();
        return true;
}


// reading the contents of jobs from a file

bool readfile_rr()
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

