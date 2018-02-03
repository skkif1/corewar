/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudakov <vrudakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 19:07:21 by omotyliu          #+#    #+#             */
/*   Updated: 2018/01/28 19:27:48 by vrudakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

t_list *g_notifications;
static int g_per_second;

void	rewrite_notification(void)
{
	t_list			*temp;
	t_notification	*not;

	temp = g_notifications;
	wmove(g_stat, 20, 0);
	while (temp)
	{
		not = temp->content;
		wattron(g_stat, COLOR_PAIR(not->color));
		wprintw(g_stat, "%s\n", not->notification);
		wattroff(g_stat, COLOR_PAIR(not->color));
		temp = temp->next;
	}
}

void	print_player_info(t_list *temp)
{
	t_player	*player;

	while (temp)
	{
		player = temp->content;
		wattron(g_stat, COLOR_PAIR(player->color));
		wprintw(g_stat, "name: %s\n", player->player_name);
		wattroff(g_stat, COLOR_PAIR(player->color));
		wprintw(g_stat, "     last live: %d\n", player->last_live);
		wprintw(g_stat, "     lives in curent period: %d\n",
		player->live_in_period);
		temp = temp->next;
	}
}

void	rewrite_stat(void)
{
	t_list		*temp;

	if (!g_env->vis)
		return ;
	wmove(g_stat, 0, 0);
	wprintw(g_stat, "\n");
	wprintw(g_stat, "CYCLE PER SECOND: %d \n", 1000 / g_env->vis_delay);
	wprintw(g_stat, "CYCLE TO DIE: %d \n", g_env->cycle_to_die);
	wprintw(g_stat, "CYCLE DELTA: %d \n", CYCLE_DELTA);
	wprintw(g_stat, "NBR LIVE: %d \n\n", NBR_LIVE);
	wprintw(g_stat, "PROCESSES: %d \n\n", lst_size(g_env->processes));
	wprintw(g_stat, "CYCLE: %u\n\n", g_env->cycle);
	wprintw(g_stat, "PLAYERS:\n");
	temp = g_env->players;
	print_player_info(temp);
	wprintw(g_stat,
		"\nLEGEND:\n   w - start/stop\n   s - incr speed\n   a - decr speed\n");
	rewrite_notification();
	wrefresh(g_stat);
}

int		check_press(int button)
{
	if (button == 119)
	{
		g_env->vis_run = 0;
		return (0);
	}
	if (button == 115)
	{
		g_per_second = (g_per_second == 500) ? 500 : ++g_per_second;
		g_per_second = (g_per_second > 500) ? 500 : g_per_second;
		g_env->vis_delay = 1000 / g_per_second;
	}
	else if (button == 97)
	{
		g_per_second = (g_per_second <= 1) ? 1 : --g_per_second;
		g_env->vis_delay = 1000 / g_per_second;
	}
	else if (button == 27 && getch() != 91)
	{
		dell_window();
		exit(0);
	}
	return (1);
}

int		manage_ui(void)
{
	int button;

	if (!g_env->vis)
		return (1);
	if (!g_env->vis_run)
		pause_war();
	move(0, 0);
	timeout(g_env->vis_delay);
	button = getch();
	attron(COLOR_PAIR(1));
	printw("...........");
	attroff(COLOR_PAIR(1));
	return (check_press(button));
}
