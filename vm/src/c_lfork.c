/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_lfork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omotyliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 19:17:19 by omotyliu          #+#    #+#             */
/*   Updated: 2018/01/21 19:17:21 by omotyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

static unsigned int g_id;

void	set_proc(t_process *child_process, t_process *proc)
{
	child_process->color = proc->color;
	child_process->name = ft_strdup(proc->name);
	child_process->live = proc->live;
	child_process->carry = proc->carry;
	child_process->current_op = 0;
	child_process->cycle_to_execute = 0;
	child_process->is_child = 1;
	child_process->say_live = proc->say_live;
	child_process->id = g_id++;
	child_process->player_num = proc->player_num;
}

void	c_lfork(t_process *proc)
{
	int			param;
	t_process	*child_process;
	int			i;

	i = 0;
	param = bytes_to_int(proc->counter + 1, 2) + proc->counter;
	param = (param >= MEM_SIZE) ? param % MEM_SIZE : param;
	child_process = (t_process*)malloc(sizeof(t_process));
	while (i < REG_NUMBER + 1)
	{
		child_process->registers[i] = proc->registers[i];
		i++;
	}
	set_proc(child_process, proc);
	child_process->counter = param;
	proc->counter += 3;
	if (child_process->counter >= MEM_SIZE)
		child_process->counter = child_process->counter % MEM_SIZE;
	ft_lstadd(&g_env->processes, ft_lstnew(child_process, sizeof(t_process)));
	g_env->process_number++;
	free(child_process);
}
