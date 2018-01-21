/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_write_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omotyliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 17:06:14 by omotyliu          #+#    #+#             */
/*   Updated: 2018/01/21 17:06:21 by omotyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

int		normalize_cursor(int *start)
{
	*start = (*start + 1 == MEM_SIZE) ? 0 : *start + 1;
	return (*start);
}

int		bytes_to_int(int start, int size)
{
	int l;

	l = 0;
	start = (start >= MEM_SIZE) ? start % MEM_SIZE : start;
	if (size == 1)
	{
		return (g_env->global_field[start]);
	}
	if (size == 4)
	{
		l =
		(unsigned char)(g_env->global_field[start]) << 24 |
		(unsigned char)(g_env->global_field[normalize_cursor(&start)]) << 16 |
		(unsigned char)(g_env->global_field[normalize_cursor(&start)]) << 8 |
		(unsigned char)(g_env->global_field[normalize_cursor(&start)]);
	}
	else
	{
		l = (unsigned char)(g_env->global_field[start]) << 8 |
			(unsigned char)(g_env->global_field[normalize_cursor(&start)]);
	}
	return (l);
}

void	bytes_to_memory(int start, const void *value, size_t len, int color)
{
	unsigned char *val;

	val = (unsigned char *)value;
	start = (start >= MEM_SIZE) ? start % MEM_SIZE : start;
	g_env->global_field[start] = *val++;
	register_color_changes(start, 1, color);
	len--;
	while (len--)
	{
		g_env->global_field[normalize_cursor(&start)] = *val++;
		register_color_changes(start, 1, color);
	}
	rewrite_memory(g_env->global_field);
}
