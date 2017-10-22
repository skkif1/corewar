#include "../includes/op.h"

t_env *g_env;

void add_new_process(int position, t_player *player)
{

    t_process *process = NULL;

    int i;
    i = 0;

    process = (t_process*)malloc(sizeof(t_process));
    while(i < REG_NUMBER)
    {
        process->registers[i] = 0;
        i++;
    }
    process->registers[1] = player->player_number;
    process->color = player->color;
    process->counter = (unsigned int) position;
    process->live = 0;
    process->current_op = 0;
    process->cycle_to_execute = 0;
    ft_lstadd(&g_env->processes, ft_lstnew(process, sizeof(t_process)));
};




