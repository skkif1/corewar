/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_label_and_opcode.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapteli <skapteli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 16:18:35 by skapteli          #+#    #+#             */
/*   Updated: 2017/12/07 18:04:45 by skapteli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			check_last_char_in_label_or_opcode(char c, int line)
{
	if ((c != LABEL_CHAR && !is_white_space(c)) || c == '\0')
		error_line(6, line);
}

void			check_double_label(t_st *st, t_lst *curr_l)
{
	int			doubl;
	t_lst		*tmp_l;

	doubl = 0;
	tmp_l = st->list;
	while (tmp_l)
	{
		if (tmp_l->label && ft_strequ(tmp_l->label, curr_l->label))
			doubl++;
		if (doubl == 2)
			error_line(21, tmp_l->number_str);
		tmp_l = tmp_l->next;
	}
}

int				extract_label_and_opcode(t_st *st, t_lst *curr_l)
{
	int			i;
	int			j;

	i = skip_white_spaces(curr_l->str, 0);
	j = i;
	while ((curr_l->str[j]) && (curr_l->str[j] != LABEL_CHAR) &&
			is_label_char(LABEL_CHARS, curr_l->str[j]))
		j++;
	check_last_char_in_label_or_opcode(curr_l->str[j], curr_l->number_str);
	if (curr_l->str[j] == LABEL_CHAR)
	{
		save_label(curr_l, i, j);
		check_double_label(st, curr_l);
		j++;
		i = skip_white_spaces(&curr_l->str[j], j);
		j = i;
		if (curr_l->str[j] == '\0')
			return (j);
		while (curr_l->str[j] && is_label_char(LABEL_CHARS, curr_l->str[j]))
			j++;
		save_opcode(st, curr_l, i, j);
	}
	else
		save_opcode(st, curr_l, i, j);
	return (j);
}
