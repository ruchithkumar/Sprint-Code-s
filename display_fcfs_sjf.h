#ifndef DISPLAY_FCFS_SJF_H
#define DISPLAY_FCFS_SJF_H
#include <stdbool.h>
// creating the linkedlist

struct node
{
        int pid;
        int arr_t;
        int bur_t;
        int c_t;
        int t_a_t;
        int w_t;
        struct node *next;
};

extern struct node *g_p_head ;
extern struct node *g_p_tail ;

// creating a structure to store jobs data

typedef struct
{
        int pid;
        int arr_t;
        int bur_t;
        int c_t;
        int t_a_t;
        int w_t;
}processes_t;


void print_lines();
bool display();
bool readfile();
int insert_linkedlist(processes_t);
#endif

