/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_data_in_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohosla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 19:05:05 by obohosla          #+#    #+#             */
/*   Updated: 2017/12/19 19:10:03 by obohosla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			write_header(t_st *st, char **str, int *i)
{
	int			j;

	(*str)[(*i)++] = (char)(st->header->magic >> 24);
	(*str)[(*i)++] = (char)(st->header->magic >> 16);
	(*str)[(*i)++] = (char)(st->header->magic >> 8);
	(*str)[(*i)++] = (char)(st->header->magic);
	j = -1;
	while (++j < PROG_NAME_LENGTH + 4)
		(*str)[(*i)++] = st->header->prog_name[j];
	(*str)[(*i)++] = (char)(st->header->prog_size >> 24);
	(*str)[(*i)++] = (char)(st->header->prog_size >> 16);
	(*str)[(*i)++] = (char)(st->header->prog_size >> 8);
	(*str)[(*i)++] = (char)(st->header->prog_size);
	j = -1;
	while (++j < COMMENT_LENGTH + 4)
		(*str)[(*i)++] = st->header->comment[j];
}

void			write_acb(t_lst *curr_l, char **str, int *i)
{
	int			j;
	char		acb;

	j = -1;
	acb = 0;
	while (++j < 3)
	{
		if (curr_l->args[j].is_arg & T_REG)
			acb = acb | (char)T_REG;
		if (curr_l->args[j].is_arg & T_DIR)
			acb = acb | (char)T_DIR;
		if (curr_l->args[j].is_arg & T_IND)
			acb = acb | (char)T_IND;
		acb = acb << 2;
	}
	(*str)[(*i)++] = acb;
}

void			write_args(t_args *arg, char **str, int *i, int bytes_quantity)
{
	if (bytes_quantity == 1)
		(*str)[(*i)++] = (char)arg->int_arg;
	if (bytes_quantity == 2)
	{
		(*str)[(*i)++] = (char)(arg->int_arg >> 8);
		(*str)[(*i)++] = (char)arg->int_arg;
	}
	if (bytes_quantity == 4)
	{
		(*str)[(*i)++] = (char)(arg->int_arg >> 24);
		(*str)[(*i)++] = (char)(arg->int_arg >> 16);
		(*str)[(*i)++] = (char)(arg->int_arg >> 8);
		(*str)[(*i)++] = (char)arg->int_arg;
	}
}

void			write_op(t_lst *curr_l, char **str, int *i, t_op *op)
{
	int			j;

	j = -1;
	(*str)[(*i)++] = (char)op->id;
	if (op->acb)
		write_acb(curr_l, str, i);
	while (++j < 3)
	{
		if (curr_l->args[j].is_arg & T_REG)
			write_args(&curr_l->args[j], str, i, T_REG);
		if (curr_l->args[j].is_arg & T_DIR)
			write_args(&curr_l->args[j], str, i, op->label_size);
		if (curr_l->args[j].is_arg & T_IND)
			write_args(&curr_l->args[j], str, i, T_IND);
	}
}

void			write_data_in_file(t_st *st)
{
	t_lst		*tmp_l;
	char		*str;
	int			i;
	int			fd;

	i = 0;
	tmp_l = st->list;
	str = ft_strnew(sizeof(t_header) + st->header->prog_size);
	write_header(st, &str, &i);
	while (tmp_l)
	{
		if (tmp_l->op_code)
			write_op(tmp_l, &str, &i, get_one_op_l(st, tmp_l->op_code));
		tmp_l = tmp_l->next;
	}
	fd = open(st->name_cor, O_CREAT | O_TRUNC | O_RDWR,
			S_IRWXU | S_IRWXG | S_IRWXO);
	write(fd, str, (sizeof(t_header) + st->header->prog_size));
	close(fd);
	ft_putstr("Your CHAMP is written in ");
	ft_putstr(st->name_cor);
	write(1, "\n", 1);
	free(str);
}
