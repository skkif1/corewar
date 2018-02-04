/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_structures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapteli <skapteli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 13:51:56 by skapteli          #+#    #+#             */
/*   Updated: 2017/12/07 18:34:14 by skapteli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			make_free_node(t_lst *cur_node)
{
	free_lst_node_args(cur_node);
	free(cur_node);
	cur_node = NULL;
}

void			free_args_struct(t_args *args)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (args[i].char_arg)
			free(args[i].char_arg);
		i++;
	}
	free(args);
}

void			free_lst_node_args(t_lst *node)
{
	if (node->str)
		free(node->str);
	if (node->label)
		free(node->label);
	if (node->op_code)
		free(node->op_code);
	free_args_struct(node->args);
	node->str = NULL;
	node->label = NULL;
	node->op_code = NULL;
}

void			free_list(t_st *st)
{
	t_lst		*curr_l;
	t_lst		*tmp_l;

	tmp_l = st->list;
	while (tmp_l)
	{
		curr_l = tmp_l;
		free_lst_node_args(curr_l);
		tmp_l = curr_l->next;
		free(curr_l);
		curr_l = NULL;
	}
}

void			free_st(t_st *st)
{
	if (st->list != NULL)
		free_list(st);
	free(st->header);
	free(st->op);
	free(st->name_cor);
	free(st);
	st = NULL;
}
