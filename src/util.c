/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudakov <vrudakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 16:58:57 by omotyliu          #+#    #+#             */
/*   Updated: 2018/01/28 20:28:45 by vrudakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

unsigned int	big_to_little(unsigned int value)
{
	value = ((value >> 24) & 0xff) |
			((value << 8) & 0xff0000) |
			((value >> 8) & 0xff00) |
			((value << 24) & 0xff000000);
	return (value);
}

int				get_register(int process_counter, int skip)
{
	process_counter += skip;
	if (process_counter > MEM_SIZE - 1)
	{
		return (g_env->global_field[process_counter % MEM_SIZE]);
	}
	return (g_env->global_field[process_counter]);
}

void			extend_winner(char *res, unsigned int last, t_player *player)
{
	if (last != 0)
	{
		if (!g_env->vis)
			ft_printf(res, player->player_number, player->player_name);
		else
		{
			rewrite_stat();
			wmove(stat, 40, 0);
			wprintw(stat, res, player->player_number, player->player_name);
			wrefresh(stat);
		}
	}
	else
	{
		if (!g_env->vis)
			ft_printf("Drow\n");
		else
		{
			rewrite_stat();
			wmove(stat, 30, 0);
			wprintw(stat, "Conclusion:\nBots are sucks\nNo lives announced\n");
			wrefresh(stat);
		}
	}
}

void			winner(void)
{
	t_list			*temp;
	unsigned int	last;
	t_player		*player;
	char			*res;

	res = "Conclusion:\nPlayer %u (%s) won\n";
	temp = g_env->players;
	last = 0;
	while (temp)
	{
		if (((t_player*)temp->content)->last_live > last)
		{
			last = ((t_player*)temp->content)->last_live;
			player = temp->content;
		}
		temp = temp->next;
	}
	extend_winner(res, last, player);
}
