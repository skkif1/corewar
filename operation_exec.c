#include "op.h"

int get_operation(t_process *process)
{

    int op = (g_env->global_field[process->counter]);
    op = op - 1;

    if (process->current_op != 0)
    {
        if (process->cycle_to_execute == g_tab[op].duration)
        {
            process->current_op = 0;
            return op;
        }
        else
            process->cycle_to_execute++;
    } else
    {
        process->current_op = g_tab[op].name;
        process->cycle_to_execute = g_tab[op].duration;
    }
    return -1;
}

void init_operation(int command, t_process *process)
{
    operation[command](process);
}