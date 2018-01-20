//
// Created by Vitaliy Rudakov on 11/25/17.
//

#include "../includes/op.h"

static unsigned int g_id;

void c_lfork(t_process *process)
{
    int param;
	t_process *child_process;
	int i;

	i = 0;
    param = bytes_to_int(process->counter + 1, 2) + process->counter;
    param = (param >= MEM_SIZE) ? param % MEM_SIZE : param;
    child_process = (t_process*)malloc(sizeof(t_process));
    while(i < REG_NUMBER + 1)
        child_process->registers[i++] = 0;
    child_process->registers[1] = process->registers[1];
    child_process->color = process->color;
    child_process->name = ft_strdup(process->name);
    child_process->live = process->live;
    child_process->counter = param;
    child_process->carry = process->carry;
    child_process->current_op = 0;
    child_process->cycle_to_execute = 0;
    child_process->id = 10;
    child_process->say_live = process->say_live;
    child_process->id = g_id++;
    child_process->player_num = process->player_num;
    ft_lstadd(&g_env->processes, ft_lstnew(child_process, sizeof(t_process)));
    g_env->process_number++;
    process->counter += 3;
    free(child_process);
}
