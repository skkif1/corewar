/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_main_information.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapteli <skapteli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 16:14:25 by skapteli          #+#    #+#             */
/*   Updated: 2017/12/16 19:00:10 by obohosla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			check_separator_char_num(const char *str, int str_num)
{
	int			i;
	int			separator_num;

	i = 0;
	separator_num = 0;
	while (str[i])
	{
		if ((str[i] == COMMENT_CHAR1) || (str[i] == COMMENT_CHAR2))
			return ;
		if (str[i] == SEPARATOR_CHAR)
		{
			separator_num++;
			if (separator_num > 2)
				too_much_char_error(SEPARATOR_CHAR, str_num);
			if (str[i + 1] == SEPARATOR_CHAR)
				error_line(6, str_num);
		}
		i++;
	}
}

void			lex_valid_opcodes_arguments(t_st *st, t_lst *curr_l)
{
	int			i;

	check_separator_char_num(curr_l->str, curr_l->number_str);
	i = extract_label_and_opcode(st, curr_l);
	if (curr_l->str[i])
		extract_opcode_args(curr_l, i);
}

void			handle_main_information(t_st *st, int i)
{
	t_lst		*tmp_l;

	tmp_l = st->list;
	while (tmp_l)
	{
		i = skip_white_spaces(tmp_l->str, 0);
		if (tmp_l->str[0] == '\0' || is_only_white_spaces(tmp_l->str) ||
				(tmp_l->str[i] && ((tmp_l->str[i] == COMMENT_CHAR1)
						|| (tmp_l->str[i] == COMMENT_CHAR2))))
		{
			if (!tmp_l->next)
			{
				delete_node(st, tmp_l);
				tmp_l = NULL;
			}
			else
			{
				tmp_l = tmp_l->next;
				delete_node(st, tmp_l->prev);
			}
			continue ;
		}
		lex_valid_opcodes_arguments(st, tmp_l);
		tmp_l = tmp_l->next;
	}
}
