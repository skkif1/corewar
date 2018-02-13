/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapteli <skapteli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 17:15:00 by skapteli          #+#    #+#             */
/*   Updated: 2018/02/03 16:45:39 by skapteli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static t_op	g_op[17] =
{
	{{0}, 0, {0, 0, 0}, 0, 0, {0}, 0, 0, 0},
	{"live", 1, {T_DIR, 0, 0}, 1, 10, "alive", 0, 0, 4},
	{"ld", 2, {T_DIR | T_IND, T_REG, 0}, 2, 5, "load", 1, 0, 4},
	{"st", 2, {T_REG, T_IND | T_REG, 0}, 3, 5, "store", 1, 0, 0},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0, 0},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0, 0},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0, 4},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0, 4},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0, 4},
	{"zjmp", 1, {T_DIR, 0, 0}, 9, 20, "jump if zero", 0, 1, 2},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 1, 2},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 1, 2},
	{"fork", 1, {T_DIR, 0, 0}, 12, 800, "fork", 0, 1, 2},
	{"lld", 2, {T_DIR | T_IND, T_REG, 0}, 13, 10, "long load", 1, 0, 4},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 1, 2},
	{"lfork", 1, {T_DIR, 0, 0}, 15, 1000, "long fork", 0, 1, 2},
	{"aff", 1, {T_REG, 0, 0}, 16, 2, "aff", 1, 0, 0}
};

void		init_op(t_st *st)
{
	int	i;

	i = -1;
	st->op = (t_op *)malloc(sizeof(t_op) * 17);
	while (++i < 17)
		st->op[i] = g_op[i];
}

t_st		*initial_st(void)
{
	int		i;
	t_st	*st;

	i = -1;
	st = (t_st *)malloc(sizeof(t_st));
	st->list = NULL;
	st->header = (t_header *)malloc(sizeof(t_header));
	while (++i <= PROG_NAME_LENGTH)
		st->header->prog_name[i] = '\0';
	i = -1;
	while (++i <= COMMENT_LENGTH)
		st->header->comment[i] = '\0';
	st->is_header = 0;
	init_op(st);
	return (st);
}

t_args		*get_new_args(void)
{
	t_args	*args;
	int		i;

	if (!(args = (t_args *)malloc(sizeof(t_args) * 3)))
		return (NULL);
	i = -1;
	while (++i < 3)
	{
		args[i].is_arg = 0;
		args[i].int_arg = 0;
		args[i].char_arg = NULL;
	}
	return (args);
}

t_lst		*get_new_node(void)
{
	t_lst	*node;

	if (!(node = (t_lst *)malloc(sizeof(t_lst))))
		return (NULL);
	node->prev = NULL;
	node->str = NULL;
	node->number_str = 0;
	node->label = NULL;
	node->op_code = NULL;
	node->args = get_new_args();
	node->bytes = 0;
	node->next = NULL;
	return (node);
}
