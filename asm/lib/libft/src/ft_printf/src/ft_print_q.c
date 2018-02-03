/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_q.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapteli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 13:03:29 by skapteli          #+#    #+#             */
/*   Updated: 2017/03/04 13:03:30 by skapteli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	add_num_in_struc_q(t_struc *temp, unsigned long long int n,
		unsigned int base)
{
	UNUM = n;
	ITOANUM = uitoa_base(temp, base);
	(PLUS == 1) ? (PLUS = 0) : 0;
	(SPACE == 1) ? (SPACE = 0) : 0;
}

/*
**	q to print any (int)base
*/

void	ft_print_q(t_struc *temp, va_list arg)
{
	unsigned long long int	n;
	unsigned int			base;
	char					*str;

	n = find_number_oux(temp, arg);
	base = (unsigned int)va_arg(arg, unsigned int);
	if (base < 2)
		return ;
	add_num_in_struc_q(temp, n, base);
	str = make_output_str_o(temp);
	write(1, str, MINWIDTH);
	if (ITOANUM)
		free(ITOANUM);
	free(str);
}
