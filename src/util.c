/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omotyliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 16:58:57 by omotyliu          #+#    #+#             */
/*   Updated: 2018/01/21 16:59:03 by omotyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

int				lst_size(t_list *list)
{
	t_list	*temp;
	int		i;

	i = 0;
	temp = list;
	if (temp == NULL)
		return (0);
	while (temp)
	{
		if (((t_process*)temp->content)->id != 2000000000)
		{
			i++;
		}
		temp = temp->next;
	}
	return (i);
}

int				get_opcode_by_name(char *name)
{
	int i;

	i = 0;
	while (i < 16)
	{
		if (!strcmp(name, g_tab[i].name))
			return (i);
		i++;
	}
	return (-1);
}

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

void	winner(void)
{
    t_list			*temp;
    unsigned int	last;
    t_player		*player;
    char *res = "Conclusion:\nPlayer %u (%s) won\n";
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
    if(last != 0)
    {
        if(!g_env->vis)
        ft_printf(res, player->player_number,
                  player->player_name);
        else
        {
            rewrite_stat();
            wprintw(stat, res, player->player_number, player->player_name);
            wrefresh(stat);
        }
    } else
    {
        if(!g_env->vis)
            ft_printf("Drow\n");
        else
        {
            rewrite_stat();
            wprintw(stat, "Conclusion:\nBots are sucks\nNo lives announced\n");
            wrefresh(stat);
        }
    }
}