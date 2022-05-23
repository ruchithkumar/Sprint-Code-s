#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "display_rr.h"
#define FILENAME "data.dat"

bool rr_algo();
int insert_linkedlist(processes_t );


struct node *g_p_head = NULL;
struct node *g_p_tail = NULL;

//inserting conetenst of file to linkedlist

int insert_linkedlist(processes_t process)
{
        struct node *p_temp = malloc(sizeof(struct node));
        if(p_temp==NULL)
        {
                perror("");
                return -1;
        }
        else
        {
                p_temp->pid = process.pid;
                p_temp->arr_t = process.arr_t;
                p_temp->bur_t = process.bur_t;
                p_temp->bur_t1 = process.bur_t;
                p_temp->c_t = process.c_t;
                p_temp->t_a_t = process.t_a_t;
                p_temp->w_t = process.w_t;
                if(g_p_head == NULL)
                {
                        g_p_head =g_p_tail =p_temp;
                        p_temp->next=g_p_tail;
                        p_temp->prev=g_p_head;
                }
                else
                {
                        g_p_head->prev=p_temp;
                        g_p_tail->next = p_temp;
                        p_temp->prev=g_p_tail;
                        p_temp->next=g_p_head;
                        g_p_tail = p_temp;
                }
        }
        return 0;
}

// performing rr algorithm

bool rr_algo(void)
{
        int sum=0,time_quantum=0;
        printf("\n enter the time quantum\n");
        scanf("%d",&time_quantum);
        struct node *i=g_p_head;
        struct node *p_ptr=NULL;
        float total_w_t=0.0;
        int count=0;
        printf("\n");
        print_lines();
        printf("\nprocess_id\ta_time\tb_time\tc_time\tt_time\tw_time\n");
        print_lines();
        for(i;i!=NULL;)
        {
                if((i->bur_t== time_quantum) && (i->bur_t > 0))
                {
                        sum=sum+i->bur_t;
                        i->c_t=sum;
                        i->bur_t-=time_quantum;
                        i->t_a_t=(i->c_t)-(i->arr_t);
                        i->w_t=(i->t_a_t)-(i->bur_t1);
                        printf("\n%d\t\t%d\t%d\t%d\t%d\t%d",i->pid,i->arr_t,i->bur_t1,i->c_t,i->t_a_t,i->w_t);
                        count++;
                        total_w_t+=i->w_t;
                        p_ptr=i->prev;
                        p_ptr->next=i->next;
                        p_ptr=i->next;
                        p_ptr->prev=i->prev;
                        p_ptr=i;
                        i=i->next;
                        free(p_ptr);
                        p_ptr=NULL;
                }
else if((i->bur_t < time_quantum) && (i->bur_t > 0))
                {
                        sum=sum+i->bur_t;
                        i->c_t=sum;
                        i->bur_t=0;
                        i->t_a_t=(i->c_t)-(i->arr_t);
                        i->w_t=(i->t_a_t)-(i->bur_t1);
                        printf("\n%d\t\t%d\t%d\t%d\t%d\t%d",i->pid,i->arr_t,i->bur_t1,i->c_t,i->t_a_t,i->w_t);
                        count++;
                        total_w_t+=i->w_t;
                        p_ptr=i->prev;
                        p_ptr->next=i->next;
                        p_ptr=i->next;
                        p_ptr->prev=i->prev;
                        p_ptr=i;
                        i=i->next;
                        free(p_ptr);
                        p_ptr=NULL;
                }
                else if((i->bur_t > time_quantum) && (i->bur_t > 0))
                {
                        sum+=time_quantum;
                        i->c_t=sum;
                        i->bur_t-=time_quantum;
                        i=i->next;
                }
                else
                {
                        break;
                }
    }
        printf("\n");
        print_lines();
        printf("\n");
        printf("\n AVERAGE WAITING TIME IS %f\n",total_w_t/count);
        return true;
}
#if 0
int main()
{

        readfile_rr();
        display_rr();
        rr_algo();

}

