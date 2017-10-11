#include "op.h"

t_env *g_env;

void do_operation(t_process *process)
{
    process->counter++;
    if (process->counter == MEM_SIZE)
        process->counter = 0;
    place_cursor(process);
}



int lst_size(t_list *list)
{
    t_list *temp;
    int i;

    i = 0;
    temp = list;

    while (temp)
    {
        i++;
        temp = temp->next;
    }
    return i;
}

int delete_process(t_list* node_ptr)
{
    if (node_ptr->next)
    {
        t_list *temp = node_ptr->next;
        node_ptr->content    = temp->content;
        node_ptr->next    = temp->next;
        free(temp);
        return 0;
    } else
    return 1;
}


int check_processes()
{

    t_list *processes;
    int nbr_flag;


    nbr_flag = 0;
    processes = g_env->procesesses;

    while (processes)
    {
        if (((t_process*)processes->content)->live == 0)
        {
            if (delete_process(processes))
                    return 1;
            continue;
        }
        else
        {
            if (((t_process*)processes->content)->live >= NBR_LIVE)
                    nbr_flag++;
                ((t_process*)processes->content)->live = 0;
                ((t_process*)processes->content)->carry = 0;
                ((t_process*)processes->content)->last_live = 0;
        }
            processes = processes->next;
    }
    if (nbr_flag != 0)
        g_env->cycle_to_die -= CYCLE_DELTA;
    return 0;
}

void start_cycle()
{
    t_list *temp;
    int i;
    i = 0;

    while (1)
    {
        temp = g_env->procesesses;
        while (temp)
        {
            do_operation(temp->content);
            temp = temp->next;
        }
        rewrite_memory(g_env->global_field);
        g_env->cycle++;
        usleep(3000);
        if (i++ == g_env->cycle_to_die)
        {
            i = 0;
            if (check_processes())
                break;
            continue;
        }
    }
}
