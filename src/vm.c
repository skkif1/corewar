/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omotyliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 16:48:12 by omotyliu          #+#    #+#             */
/*   Updated: 2018/01/21 16:48:20 by omotyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

t_env *g_env;

int		main(int argc, char **argv)
{
	t_list *players;

	players = NULL;
	init_env();
	parse_args(argc, argv);
	g_env->vis_delay = 1;
	if (g_env->vis)
		init_screen();
	register_players_auto(&players);
	start_cycle();
	if (g_env->vis)
		hold_ui();
	if (g_env->vis)
	{
		getch();
		dell_window();
	}
}

void		init_env(void)
{
	g_env = malloc(sizeof(t_env));
	ft_memset(g_env->global_field, 0, MEM_SIZE);
	g_env->cycle_to_die = CYCLE_TO_DIE;
	g_env->cycle = 0;
	g_env->vis_delay = 1000;
	g_env->checks = 0;
	g_env->vis_run = 0;
	g_env->player_files = NULL;
	g_env->dump = -1;
}
