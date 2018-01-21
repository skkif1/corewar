/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omotyliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 16:52:39 by omotyliu          #+#    #+#             */
/*   Updated: 2018/01/21 16:52:54 by omotyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

t_player	*find_player(unsigned int number)
{
	t_list *temp;

	temp = g_env->players;
	while (temp)
	{
		if (((t_player*)temp->content)->player_number == number)
			return ((t_player*)temp->content);
		temp = temp->next;
	}
	return (0);
}

void		type_to_size(int *mass, int dir_size)
{
	int i;

	i = 0;
	while (i < 3)
	{
		if (mass[i] == T_IND)
			mass[i] = IND_SIZE;
		else
		{
			if (mass[i] == T_DIR)
			{
				mass[i] = dir_size;
			}
		}
		i++;
	}
}

void		invalid_coding_byte(const int *arg_t, t_process *proc, int params)
{
	if (params == 2)
	{
		if (arg_t[0] == 0 && arg_t[1] == 0)
		{
			proc->counter += 2;
		}
		else
		{
			proc->counter += arg_t[0] + arg_t[1] + 2;
		}
	}
	else if (arg_t[0] == 0 && arg_t[1] == 0 && arg_t[2] == 0)
	{
		proc->counter += 2;
	}
	else
	{
		proc->counter += arg_t[0] + arg_t[1] + arg_t[2] + 2;
	}
}

int			validate_reqistry(int value)
{
	if (value > 0 && value <= 16)
		return (1);
	return (0);
}
