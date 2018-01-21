/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omotyliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 17:44:43 by omotyliu          #+#    #+#             */
/*   Updated: 2018/01/21 17:44:46 by omotyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

t_env *g_env;

void	do_operation(t_process *process)
{
	int operation;

	if (process->counter >= MEM_SIZE)
		process->counter = process->counter % MEM_SIZE;
	operation = get_operation(process);
	if (process->id != 2000000000)
	{
		if (operation != -1)
			init_operation(operation, process);
		if (process->counter >= MEM_SIZE)
			process->counter = process->counter % MEM_SIZE;
	}
}

int		check_processes(void)
{
	t_list *processes;

	processes = g_env->processes;
	while (processes)
	{
		if (((t_process *)processes->content)->say_live == 0)
			((t_process *)processes->content)->id = 2000000000;
		else
			reset_process(processes->content);
		processes = processes->next;
	}
	if (lst_size(g_env->processes) == 0)
		return (1);
	if (g_env->num_live >= NBR_LIVE || g_env->checks == MAX_CHECKS - 1)
	{
		g_env->cycle_to_die -= CYCLE_DELTA;
		g_env->checks = 0;
	}
	else
	{
		g_env->checks++;
	}
	g_env->num_live = 0;
	return (0);
}

void	dump_memory(void)
{
	int i;

	i = 1;
	while (i <= MEM_SIZE)
	{
		ft_printf("%.2x ", g_env->global_field[i - 1]);
		if (i % 64 == 0)
		{
			ft_printf("\n");
		}
		i++;
	}
}

int		check_processes_rewrite(void)
{
	if (check_processes())
	{
		g_env->cycle++;
		rewrite_memory(g_env->global_field);
		rewrite_stat();
		return (1);
	}
	return (0);
}

void	start_cycle(void)
{
	t_list	*temp;
	int		i;

	i = 0;
	while (1)
	{
		if (!manage_ui())
			continue ;
		temp = g_env->processes;
		while (temp)
		{
			do_operation(temp->content);
			temp = temp->next;
		}
		if (g_env->cycle == g_env->dump - 1)
		{
			dump_memory();
			break ;
		}
		if (i++ >= g_env->cycle_to_die - 1)
		{
			i = 0;
			if (check_processes_rewrite())
				break ;
		}
		g_env->cycle++;
		rewrite_memory(g_env->global_field);
		rewrite_stat();
	}
}
