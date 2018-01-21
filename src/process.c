/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omotyliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 17:12:18 by omotyliu          #+#    #+#             */
/*   Updated: 2018/01/21 17:12:22 by omotyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

t_env				*g_env;
static unsigned int	g_id;

void	add_new_process(int position, t_player *player)
{
	t_process	*process;
	int			i;

	i = 0;
	process = (t_process*)malloc(sizeof(t_process));
	while (i < REG_NUMBER + 1)
	{
		process->registers[i] = 0;
		i++;
	}
	process->registers[1] = player->player_number;
	process->color = player->color;
	process->counter = position;
	process->live = 0;
	process->name = strdup((const char *)player->player_name);
	process->current_op = 0;
	process->say_live = 0;
	process->cycle_to_execute = 0;
	process->id = g_id++;
	process->player_num = player->player_number;
	process->is_child = 0;
	ft_lstadd(&g_env->processes, ft_lstnew(process, sizeof(t_process)));
	g_env->process_number++;
	free(process);
}

void	reset_process(t_process *process)
{
	t_player	*player;

	process->live = 0;
	process->say_live = 0;
	player = find_player(process->registers[1]);
	if (player != NULL)
		player->live_in_period = 0;
}
