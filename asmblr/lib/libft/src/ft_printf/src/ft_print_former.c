/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_former.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapteli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 13:00:08 by skapteli          #+#    #+#             */
/*   Updated: 2017/03/04 13:00:15 by skapteli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_former(t_struc *temp, va_list arg)
{
	if (SPECIF == 's')
		(PRECIS < 0) ? (PRECIS = -PRECIS) : 0;
	else
	{
		(PRECIS < 0) ? (ISDOT = 0) : 0;
		PRECIS = (PRECIS < 0) ? 0 : PRECIS;
	}
	if (SPECIF == 'd' || SPECIF == 'i' || SPECIF == 'D')
		ft_print_di(temp, arg);
	if (SPECIF == 'o' || SPECIF == 'O' || SPECIF == 'u' || SPECIF == 'U' ||
		SPECIF == 'x' || SPECIF == 'X' || SPECIF == 'p')
		ft_print_oux(temp, arg);
	(SPECIF == 'c' || SPECIF == 'C') ? ft_print_c(temp, arg) : 0;
	(SPECIF == 's' || SPECIF == 'S') ? ft_print_s(temp, arg) : 0;
	(SPECIF == 'b') ? ft_print_b(temp, arg) : 0;
	(SPECIF == 'q') ? ft_print_q(temp, arg) : 0;
	(SPECIF == 'm') ? ft_print_m(temp, arg) : 0;
	(SPECIF == '\0') ? ft_print_no_specif(temp, arg) : 0;
}
