/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omotyliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 19:21:23 by omotyliu          #+#    #+#             */
/*   Updated: 2018/01/27 19:21:34 by omotyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

WINDOW	*create_memory_window(void)
{
	WINDOW *wraper;
	WINDOW *memory;

	wraper = newwin(COL_LEN + 2, ROW_LEN + 2, MARGIN, MARGIN);
	memory = newwin(COL_LEN, ROW_LEN, MARGIN + 1, MARGIN + 1);
	wrefresh(wraper);
	wrefresh(memory);
	return (memory);
}

WINDOW	*create_stat_window(void)
{
	WINDOW *wrapper;
	WINDOW *stat;

	wrapper = newwin(COL_LEN + 2, 60, MARGIN, ROW_LEN + 10);
	stat = newwin(COL_LEN - 2, 60 - 2, MARGIN + 1, ROW_LEN + 11);
	wrefresh(wrapper);
	wrefresh(stat);
	return (stat);
}

void	init_def_color(void)
{
	int i;

	i = 0;
	start_color();
	init_pair(1, COLOR_CYAN, COLOR_BLACK);
	init_pair(2, COLOR_WHITE, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	init_pair(4, COLOR_BLACK, COLOR_GREEN);
	init_pair(5, COLOR_RED, COLOR_BLACK);
	init_pair(6, COLOR_BLACK, COLOR_RED);
	init_pair(7, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(8, COLOR_BLACK, COLOR_MAGENTA);
	init_pair(9, COLOR_YELLOW, COLOR_BLACK);
	init_pair(10, COLOR_BLACK, COLOR_YELLOW);
	init_pair(11, COLOR_BLUE, COLOR_BLACK);
	init_pair(12, COLOR_BLACK, COLOR_BLUE);
	init_pair(13, COLOR_CYAN, COLOR_BLACK);
	init_pair(14, COLOR_BLACK, COLOR_CYAN);
	while (i < MEM_SIZE)
		g_colors[i++] = 2;
}

void	init_screen(void)
{
	chtype background;

	initscr();
	signal(SIGWINCH, NULL);
	init_def_color();
	background = '.' | COLOR_PAIR(1);
	bkgd(background);
	curs_set(0);
	refresh();
	memory = create_memory_window();
	stat = create_stat_window();
}

void	dell_window(void)
{
	delwin(memory);
	delwin(stat);
	endwin();
}
