/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapteli <skapteli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 19:26:20 by skapteli          #+#    #+#             */
/*   Updated: 2017/11/30 20:53:15 by skapteli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				skip_white_spaces(char *str, int i)
{
	int			j;

	j = 0;
	while ((str[j] == '\t' || str[j] == ' ' || str[j] == '\n' ||
			str[j] == '\v' || str[j] == '\f' || str[j] == '\r'))
	{
		i++;
		j++;
	}
	return (i);
}

int				is_only_white_spaces(char *str)
{
	int			i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\t' || str[i] == ' ' || str[i] == '\n' ||
			str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
			i++;
		else
			return (0);
	}
	return (1);
}

t_lst			*sv_in_list(t_st *st, t_lst *list, char *str, int str_num)
{
	t_lst		*curr_l;

	curr_l = get_new_node();
	curr_l->str = ft_strdup(str);
	curr_l->number_str = str_num;
	free(str);
	if (st->list == NULL)
		st->list = curr_l;
	else
	{
		curr_l->prev = list;
		list->next = curr_l;
	}
	list = curr_l;
	return (list);
}

void			read_save_in_lst(t_st *st, int fd)
{
	int			str_num;
	char		*s;
	t_lst		*list;

	str_num = 0;
	list = NULL;
	while (get_next_line(fd, &s) && ++str_num)
		list = sv_in_list(st, list, s, str_num);
	free(s);
}

void			get_info_from_file(t_st *st, char *file_name)
{
	int			fd;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		perror_(file_name);
	read_save_in_lst(st, fd);
	close(fd);
}
