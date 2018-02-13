/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_manipulations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapteli <skapteli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 15:40:47 by skapteli          #+#    #+#             */
/*   Updated: 2017/12/07 18:06:20 by skapteli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	delete_node(t_st *st, t_lst *curr_l)
{
	t_lst	*prev_l;
	t_lst	*next_l;

	prev_l = curr_l->prev;
	next_l = curr_l->next;
	if (prev_l == NULL)
	{
		make_free_node(curr_l);
		if (!next_l)
			error_(15);
		next_l->prev = NULL;
		st->list = next_l;
		return ;
	}
	prev_l->next = next_l;
	if (next_l)
		next_l->prev = prev_l;
	make_free_node(curr_l);
}

t_lst	*delete_first_part_of_list(t_lst *curr_l)
{
	t_lst	*tmp_l;

	if (!curr_l)
		error_(10);
	tmp_l = curr_l->prev;
	while (tmp_l)
	{
		make_free_node(tmp_l);
		tmp_l = tmp_l->prev;
	}
	curr_l->prev = NULL;
	return (curr_l);
}

t_op	*get_one_op_l(t_st *st, char *op_code)
{
	int	i;

	i = -1;
	while (++i < 17)
		if (ft_strequ(st->op[i].name, op_code))
			break ;
	return (&st->op[i]);
}
