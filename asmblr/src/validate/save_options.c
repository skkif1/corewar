/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_options.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapteli <skapteli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 20:14:26 by skapteli          #+#    #+#             */
/*   Updated: 2017/12/08 14:40:36 by skapteli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			extract_reg(t_lst *curr_l, int i, char *src)
{
	int			reg_numb;

	curr_l->args[i].is_arg = T_REG;
	reg_numb = ft_atoi(src + 1);
	if ((reg_numb >= 0) && (reg_numb <= REG_NUMBER) && is_only_digits(src + 1))
		curr_l->args[i].int_arg = reg_numb;
	else
		error_line(17, curr_l->number_str);
}

void			extract_direct(t_lst *curr_l, int i, char *src)
{
	curr_l->args[i].is_arg = T_DIR;
	if (is_only_digits(src + 1))
		curr_l->args[i].int_arg = ft_atoi(src + 1);
	else if ((src[1] == LABEL_CHAR) && (src[2] != '\0'))
		curr_l->args[i].char_arg = ft_strdup(src + 2);
	else
		error_line(18, curr_l->number_str);
}

void			extract_ind(t_lst *curr_l, int i, char *src)
{
	curr_l->args[i].is_arg = T_IND;
	if (is_only_digits(src))
		curr_l->args[i].int_arg = ft_atoi(src);
	else if ((src[0] == LABEL_CHAR) && (src[1] != '\0'))
		curr_l->args[i].char_arg = ft_strdup(src + 2);
	else
		error_line(19, curr_l->number_str);
}

void			save_label(t_lst *curr_l, int start, int end)
{
	int		length;

	if (start == end)
		error_line(6, curr_l->number_str);
	length = end - start;
	curr_l->label = ft_strnew((size_t)length);
	ft_strncpy(curr_l->label, &curr_l->str[start], (size_t)length);
}

void			save_opcode(t_st *st, t_lst *curr_l, int start, int end)
{
	int		length;

	if (start == end)
		error_line(6, curr_l->number_str);
	length = end - start;
	curr_l->op_code = ft_strnew((size_t)length);
	ft_strncpy(curr_l->op_code, &curr_l->str[start], (size_t)length);
	if (!is_opcode(st, curr_l->op_code))
		error_line(15, curr_l->number_str);
}
