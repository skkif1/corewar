/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudakov <vrudakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 19:50:02 by vrudakov          #+#    #+#             */
/*   Updated: 2018/01/28 20:29:58 by vrudakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

void			add_all_players(t_list *players)
{
	t_list *temp;

	g_env->players = players;
	set_fake_numbers();
	if (g_env->vis)
		init_screen();
	temp = players;
	g_env->players = players;
	while (temp)
	{
		add_new_player(temp->content);
		temp = temp->next;
	}
}

void			add_new_player(t_player *player)
{
	int start;
	int j;
	int end;

	j = 0;
	start = (unsigned int)(MEM_SIZE / g_env->player_in_game * (4294967295 -
		player->real_num));
	end = start + player->code_len;
	player->live_in_period = 0;
	add_new_process(start, player);
	while (start < end)
	{
		g_env->global_field[start++] = player->code[j++];
	}
	register_color_changes(start - player->code_len,
							player->code_len, player->color);
	rewrite_memory(g_env->global_field);
}

unsigned int	get_number_f(unsigned int num)
{
	t_list		*temp;
	t_player	*player;

	temp = g_env->players;
	while (temp)
	{
		player = temp->content;
		if (player->player_number == num)
		{
			return (get_number_f(num - 1));
		}
		temp = temp->next;
	}
	return (num);
}

void			set_fake_numbers(void)
{
	t_list		*temp;
	t_player	*player;
	char		**numbers;
	int			i;

	i = 0;
	numbers = ft_strsplit(g_env->numbers, '|');
	temp = g_env->players;
	while (numbers[i] != NULL)
		i++;
	i--;
	while (temp)
	{
		player = temp->content;
		if (ft_strcmp(numbers[i], "loll") == 0)
			player->player_number = get_number_f(4294967295);
		else
		{
			check_number_avail(player, (unsigned int)ft_atoi(numbers[i]));
			player->player_number = (unsigned int)ft_atoi(numbers[i]);
		}
		i--;
		temp = temp->next;
	}
}

void			check_number_avail(t_player *player_to, unsigned int num)
{
	t_list		*temp;
	t_player	*player;

	temp = g_env->players;
	while (temp)
	{
		player = temp->content;
		if (player->player_number == num)
		{
			ft_printf("%s you cant take this number, it allready taken by %s\n",
				player_to->player_name, player->player_name);
			exit(0);
		}
		temp = temp->next;
	}
}
