/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapteli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 12:56:18 by skapteli          #+#    #+#             */
/*   Updated: 2017/03/04 12:56:42 by skapteli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	add_num_in_struc_b(t_struc *temp, unsigned long long int n)
{
	UNUM = n;
	ITOANUM = uitoa_base(temp, 2);
	(PLUS == 1) ? (PLUS = 0) : 0;
	(SPACE == 1) ? (SPACE = 0) : 0;
}

/*
**	b to print in binary
*/

void	ft_print_b(t_struc *temp, va_list arg)
{
	unsigned long long int	n;
	char					*str;

	n = find_number_oux(temp, arg);
	add_num_in_struc_b(temp, n);
	str = make_output_str_o(temp);
	write(1, str, MINWIDTH);
	if (ITOANUM)
		free(ITOANUM);
	free(str);
}
