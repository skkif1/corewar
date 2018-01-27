/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omotyliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 19:26:24 by omotyliu          #+#    #+#             */
/*   Updated: 2018/01/27 19:26:27 by omotyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

void	register_color_changes(int start, int len, int color)
{
	int i;

	i = 0;
	while (i < len)
	{
		g_colors[start + i] = color;
		i++;
	}
}

void	hold_ui(void)
{
	while (1)
	{
		manage_ui();
	}
}

void	pause_war(void)
{
	int button;

	while (1)
	{
		button = getch();
		if (button == 119)
		{
			g_env->vis_run = 1;
			return ;
		}
		move(0, 0);
	}
}

void	rewrite_memory(unsigned char *buff)
{
	int i;
	int color;

	if (!g_env->vis)
		return ;
	i = wmove(memory, 0, 0) - wmove(memory, 0, 0) - 1;
	while (i++ < MEM_SIZE)
	{
		color = check_cursor(i);
		if (color == 0)
		{
			wattron(memory, COLOR_PAIR(g_colors[i]));
			wprintw(memory, "%.2x", buff[i]);
			wattroff(memory, COLOR_PAIR(g_colors[i]));
			wprintw(memory, " ");
		}
		else
		{
			wattron(memory, COLOR_PAIR(color));
			wprintw(memory, "%.2x", buff[i]);
			wattroff(memory, COLOR_PAIR(color));
			wprintw(memory, " ");
		}
	}
	wrefresh(memory);
}

int		check_cursor(int position)
{
	t_list	*temp;
	int		color;

	temp = g_env->processes;
	color = 0;
	while (temp)
	{
		if (((t_process*)temp->content)->id != 2000000000 &&
			((t_process*)temp->content)->counter == position)
		{
			color = ((t_process*)temp->content)->color + 1;
		}
		temp = temp->next;
	}
	return (color);
}
