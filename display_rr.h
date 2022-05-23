#include<stdbool.h>
#ifndef DISPLAY_RR_H
#define DISPLAY_RR_H

typedef struct
{
        int pid;
        int arr_t;
        int bur_t;
        int c_t;
        int t_a_t;
        int w_t;
}processes_t;

extern struct node *g_p_head;
extern struct node *g_p_tail;



struct node{
        int pid;
        int arr_t;
        int bur_t;
        int bur_t1;
        int c_t;
        int t_a_t;
        int w_t;
        int rem;
        struct node *next;
        struct node *prev;
};

bool readfile_rr();
bool display_rr();
void print_lines();
int insert_linkedlist(processes_t);


#endif

