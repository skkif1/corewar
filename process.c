#include "op.h"

t_process *init_new_process()
{
    static unsigned int name;
    static int color;

    t_process *process;

    process = (t_process*)malloc(sizeof(t_process));
    int i;
    i = 0;
    while(i < REG_NUMBER)
    {
        process->registers[i] = 0;
        i++;
    }
    process->registers[0] = name++;
    process->carry = 0;
    process->color = color + 3;
    color++;
    return process;
}


void process_to_string(t_process *process)
{
    printf("process name %d \n", process->name);
    printf("process cary %d \n", process->carry);
    int i = 0;

    while (i < REG_NUMBER)
    {
        printf("registr %d  value %d \n", i + 1, process->registers[i]);
        i++;
    }
}
