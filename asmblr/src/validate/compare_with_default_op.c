/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_with_default_op.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapteli <skapteli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 14:49:23 by skapteli          #+#    #+#             */
/*   Updated: 2017/12/16 18:58:37 by obohosla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			check_args_in_options(t_op *op_l, t_lst *curr_l)
{
	int		i;

	i = 0;
	if (op_l->numb_args && !curr_l->args[i].is_arg)
		error_parameter(i, curr_l->op_code, curr_l->number_str);
	if (!op_l->numb_args && !curr_l->args[i].is_arg)
		return (0);
	while (i < 3)
	{
		if (!(op_l->type_args[i]) && !(curr_l->args[i].is_arg))
			return (0);
		if (!(op_l->type_args[i] & curr_l->args[i].is_arg))
			error_parameter(i, curr_l->op_code, curr_l->number_str);
		i++;
	}
	return (0);
}

void		compare_extracted_args_with_op(t_st *st)
{
	t_lst	*tmp_l;

	tmp_l = st->list;
	while (tmp_l)
	{
		check_args_in_options((get_one_op_l(st, tmp_l->op_code)), tmp_l);
		tmp_l = tmp_l->next;
	}
}
