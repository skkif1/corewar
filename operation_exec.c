#include "op.h"


int get_opcode(t_process *process)
{
    int op = (g_env->global_field[process->counter])  - 1;
    if (op >= 0 && op <= 16)
        return op;
    return -1;
}

int get_operation(t_process *process)
{
    int op;


    if (process->current_op == 0)
    {
        if((op = get_opcode(process)) == -1)
        {
            process->counter++;
            return -1;
        }
        process->current_op = g_tab[op].name;
        process->cycle_to_execute = g_tab[op].duration - 1;
    } else
    {
        process->cycle_to_execute--;
        if (process->cycle_to_execute == 0)
        {
            op = get_opcode_by_name(process->current_op);
            return op;
        }
    }
    return -1;
}

void init_operation(int command, t_process *process)
{
    operation[command](process);
    printf("\n\n\n");
    process->current_op = 0;
}
