/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_zero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapteli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 12:35:37 by skapteli          #+#    #+#             */
/*   Updated: 2017/03/04 13:20:30 by skapteli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** put 0 at the end of str n times
*/

void	put_zero_end(char **str, int n, int len)
{
	while (n-- > 0)
		(*str)[--len] = '0';
}

/*
** put 0 at the beginning of str n times
*/

void	put_zero_beg(t_struc *temp, char **str, int n)
{
	int		i;
	int		j;

	j = 0;
	if (SPACE == 1 || PLUS == 1)
		i = 1;
	else
		i = 0;
	((SPECIF == 'x' || SPECIF == 'X' || SPECIF == 'p') && OCT == 1) ?
		(i = 2) : 0;
	while (j++ < n)
		(*str)[i++] = '0';
}
