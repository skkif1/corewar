/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_fork.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omotyliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 19:28:33 by omotyliu          #+#    #+#             */
/*   Updated: 2018/01/21 19:28:35 by omotyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

static unsigned int g_id;

void	c_fork(t_process *pr)
{
	int			param;
	t_process	*child_process;
	int			i;

	i = 0;
	param = ((short)bytes_to_int(pr->counter + 1, 2)) % IDX_MOD + pr->counter;
	child_process = (t_process*)malloc(sizeof(t_process));
	while (i < REG_NUMBER + 1)
		child_process->registers[i] = pr->registers[i++];
	child_process->color = pr->color;
	child_process->name = ft_strdup(pr->name);
	child_process->live = pr->live;
	child_process->counter = param;
	child_process->carry = pr->carry;
	child_process->say_live = pr->say_live;
	child_process->current_op = 0;
	child_process->is_child = 1;
	child_process->id = g_id++;
	child_process->player_num = pr->player_num;
	g_env->process_number++;
	pr->counter += 3;
	if (child_process->counter >= MEM_SIZE)
		child_process->counter = child_process->counter % MEM_SIZE;
	ft_lstadd(&g_env->processes, ft_lstnew(child_process, sizeof(t_process)));
	free(child_process);
}
