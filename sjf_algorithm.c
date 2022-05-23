#include<stdio.h>
#include<stdlib.h>
#include "display_fcfs_sjf.h"
#define FILENAME "data.dat"
int insert_linkedlist(processes_t );
bool sort_list();
bool sjf_algo();


struct node *g_p_head = NULL;
struct node *g_p_tail = NULL;


int insert_linkedlist(processes_t process)
{
        struct node *p_temp=malloc(sizeof(struct node));
        if(p_temp==NULL)
        {
                perror("");
                return -1;
        }
        else
        {
                p_temp->pid=process.pid;
                p_temp->arr_t=process.arr_t;
                p_temp->bur_t=process.bur_t;
                p_temp->c_t=process.c_t;
                p_temp->t_a_t=process.t_a_t;
                p_temp->w_t=process.w_t;
                if(g_p_head==NULL)
                {
                        g_p_head=g_p_tail=p_temp;
                }
                else
                {
                        g_p_tail->next=p_temp;
                        g_p_tail=p_temp;
                }
                g_p_tail->next=NULL;
        }
        return 0;
}
// sorting list bsaed on burst time

bool sort_list(void)
{
        processes_t var;
        for(struct node *i = g_p_head; i != NULL; i = i->next)
        {
                for(struct node *j = i->next; j != NULL; j = j->next)
                {
                        if(i->bur_t > j->bur_t)
                        {
                                var.pid = i->pid;
                                var.arr_t = i->arr_t;
                                var.bur_t = i->bur_t;
                                i->pid = j->pid;
                                i->arr_t = j->arr_t;
                                i->bur_t = j->bur_t;
                                j->pid = var.pid;
                                j->arr_t = var.arr_t;
                                j->bur_t = var.bur_t;
                        }
                        else if(i->bur_t == j->bur_t)
                        {
                                if(i->arr_t > j->arr_t)
                                {
                                        var.arr_t = i->arr_t;
                                        var.bur_t = i->bur_t;
                                        var.pid = i->pid;
                                        i->pid = j->pid;
                                        i->arr_t = j->arr_t;
                                        i->bur_t = j->bur_t;
                                        j->pid = var.pid;
                                        j->arr_t = var.arr_t;
                                        j->bur_t = var.bur_t;
                                }
                        }
                }
        }

return true;
}
bool sjf_algo(void)
{
        int sum = 0;
        float total_wait = 0;
        for (struct node *i = g_p_head; i != NULL; i = i->next)
        {
                sum = sum+i->bur_t;
                i->c_t = sum;
                i->t_a_t = (i->c_t)-(i->arr_t);
                i->w_t = (i->t_a_t)-(i->bur_t);
                total_wait += i->w_t;
        }
        printf("\n");
        printf("\n");
        print_lines();
        printf("\nprocess_id\ta_time\tb_time\tc_time\tt_time\tw_time\n");
        print_lines();
        int count = 0;
        for(struct node *i = g_p_head; i!=NULL;i=i->next)
        {
                printf("\n%d\t\t%d\t%d\t%d\t%d\t%d",i->pid,i->arr_t,i->bur_t,i->c_t,i->t_a_t,i->w_t);
                count++;
        }
        printf("\n");
        print_lines();
        float avg = (total_wait/count);
        printf("\n");
        printf("\nAVERAGE WAITING TIME IS %f\n",avg);
        return true;
}

// freeing the dynamically allocated memory

void delete(void)
{
        for(struct node *i=g_p_head;i!=NULL;i=g_p_head)
        {
                g_p_head=g_p_head->next;
                free(i);
                i=NULL;
        }
}
int main()
{
        readfile();
        printf("\n\t\t*****SHORTEST JOB FIRST*****\n");
        display();
        sort_list();
        sjf_algo();
        delete();

        exit(EXIT_SUCCESS);
}

