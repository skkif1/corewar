#include "op.h"

t_env g_env;



void do_operation(t_process *process)
{
    process->counter++;
    place_cursor(process);
    rewrite_memory(g_env.global_field);
}

void start_cycle()
{
    t_list *temp;

    int i = 0;
    while (i < 10)
    {

        temp = g_env.all_process;
        while (temp)
        {
            do_operation(temp->content);
            temp = temp->next;
        }
        sleep(1);
        i++;
    }
}