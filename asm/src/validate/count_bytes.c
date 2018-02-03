/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_bytes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapteli <skapteli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 18:49:57 by obohosla          #+#    #+#             */
/*   Updated: 2018/02/03 16:49:42 by skapteli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				count_and_save_bytes(t_lst *tmp_l, t_op *op_l)
{
	int			i;

	i = -1;
	tmp_l->bytes++;
	op_l->acb ? tmp_l->bytes++ : 0;
	while (++i < 3)
	{
		if (tmp_l->args[i].is_arg & T_DIR)
			tmp_l->bytes += op_l->label_size;
		if (tmp_l->args[i].is_arg & T_IND)
			tmp_l->bytes += 2;
		if (tmp_l->args[i].is_arg & T_REG)
			tmp_l->bytes += 1;
	}
	return (tmp_l->bytes);
}

void			count_bytes_of_each_lst(t_st *st)
{
	t_lst		*tmp_l;

	st->header->magic = COREWAR_EXEC_MAGIC;
	st->header->prog_size = 0;
	tmp_l = st->list;
	while (tmp_l)
	{
		if (tmp_l->op_code)
			st->header->prog_size +=
				count_and_save_bytes(tmp_l, get_one_op_l(st, tmp_l->op_code));
		tmp_l = tmp_l->next;
	}
}

int				get_label_bytes_2(t_lst *curr_l, char *str_label, int int_arg)
{
	t_lst		*tmp_l;

	tmp_l = curr_l;
	while (tmp_l->next)
	{
		if (tmp_l->next->label && ft_strequ(tmp_l->next->label, str_label))
			return (int_arg);
		if (tmp_l->next->op_code)
			int_arg += tmp_l->next->bytes;
		tmp_l = tmp_l->next;
	}
	error_line(20, curr_l->number_str);
	return (0);
}

int				get_label_bytes_1(t_lst *curr_l, char *str_label, int int_arg)
{
	t_lst		*tmp_l;

	if (curr_l->label && ft_strequ(curr_l->label, str_label))
		return (int_arg);
	tmp_l = curr_l;
	while (tmp_l->prev)
	{
		if (tmp_l->prev->op_code)
			int_arg -= tmp_l->prev->bytes;
		if (tmp_l->prev->label && ft_strequ(tmp_l->prev->label, str_label))
			return (int_arg);
		if (!tmp_l->prev->label &&
				tmp_l->prev->prev &&
				tmp_l->prev->prev->label &&
				!tmp_l->prev->prev->op_code &&
				ft_strequ(tmp_l->prev->prev->label, str_label))
			return (int_arg);
		tmp_l = tmp_l->prev;
	}
	return (get_label_bytes_2(curr_l, str_label, curr_l->bytes));
}

void			count_label_bytes(t_st *st)
{
	int			i;
	t_lst		*tmp_l;

	tmp_l = st->list;
	while (tmp_l)
	{
		if (tmp_l->op_code)
		{
			i = -1;
			while (++i < 3)
			{
				if ((tmp_l->args[i].is_arg & (T_DIR | T_IND))
						&& (tmp_l->args[i].char_arg))
					tmp_l->args[i].int_arg =
						get_label_bytes_1(tmp_l, tmp_l->args[i].char_arg, 0);
			}
		}
		tmp_l = tmp_l->next;
	}
}
