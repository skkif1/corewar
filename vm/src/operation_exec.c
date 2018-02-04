/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_exec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omotyliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 17:17:50 by omotyliu          #+#    #+#             */
/*   Updated: 2018/01/21 17:17:56 by omotyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

int		get_opcode(t_process *process)
{
	int op;

	op = (g_env->global_field[process->counter]) - 1;
	if (op >= 0 && op <= 16)
	{
		return (op);
	}
	return (-1);
}

int		get_operation(t_process *process)
{
	int op;

	if (process->current_op == 0)
	{
		if ((op = get_opcode(process)) == -1)
		{
			process->counter++;
			return (-1);
		}
		process->current_op = g_tab[op].name;
		process->cycle_to_execute = g_tab[op].duration - 1;
	}
	else
	{
		process->cycle_to_execute--;
		if (process->cycle_to_execute == 0)
		{
			op = get_opcode_by_name(process->current_op);
			return (op);
		}
	}
	return (-1);
}

void	init_operation(int command, t_process *process)
{
	g_operation[command](process);
	process->current_op = 0;
}
