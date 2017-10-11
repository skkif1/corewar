#include "op.h"

t_env *g_env;

void add_new_process(int position, t_player *player)
{

    t_process *process = NULL;
    process = init_new_process(player);
    process->registers[0] = player->player_number;
    process->color = player->color;
    process->counter = (unsigned int) position;
    process->live = 0;
    ft_lstadd(&g_env->procesesses, ft_lstnew(process, sizeof(t_process)));
};

t_process *init_new_process(t_player *player)
{
    t_process *process;

    process = (t_process*)malloc(sizeof(t_process));
    int i;
    i = 0;
    while(i < REG_NUMBER)
    {
        process->registers[i] = 0;
        i++;
    }
    process->registers[0] = player->player_number;
    process->carry = 0;
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



