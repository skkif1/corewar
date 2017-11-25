//
// Created by Vitaliy Rudakov on 11/25/17.
//

#include "../includes/op.h"

static unsigned int g_id;

void c_lfork(t_process *process)
{
	unsigned int param;
	t_process *child_process;
	int i;

	param = process->counter;
	i = 0;
	param = bytes_to_int(process->counter + 1, 2) + process->counter - 1;
	param = (param >= MEM_SIZE) ? param % MEM_SIZE : param;
	child_process = (t_process*)malloc(sizeof(t_process));
	while(i < REG_NUMBER + 1)
		child_process->registers[i++] = 0;
	child_process->registers[1] = process->registers[1];
	child_process->color = process->color;
	child_process->counter = param;
	child_process->live = 0;
	child_process->current_op = 0;
	child_process->cycle_to_execute = 0;
	child_process->id = g_id++;
	child_process->player_num = process->player_num;
	ft_lstadd_end(&g_env->processes, ft_lstnew(child_process, sizeof(t_process)));
	process->counter += 3;
}
