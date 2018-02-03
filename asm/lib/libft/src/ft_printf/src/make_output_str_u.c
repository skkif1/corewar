/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_output_str_u.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapteli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 13:18:07 by skapteli          #+#    #+#             */
/*   Updated: 2017/03/04 13:18:30 by skapteli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
**  Put str left if MINUS == 1, add another FLAGS + ITOANUM
*/

void	put_str_left_u(t_struc *temp, char **str)
{
	int		i;
	int		k;
	int		j;

	(UNUM == 0 && ISDOT == 1) ? (DISCHNUM = -1) : 0;
	i = 0;
	(PRECIS > DISCHNUM) ? (i += PRECIS - DISCHNUM) : 0;
	j = 0;
	k = 0;
	while (k++ < DISCHNUM && (*str)[i])
		(*str)[i++] = ITOANUM[j++];
}

/*
**  Put str right if MINUS == 0, add another FLAGS + ITOANUM
*/

void	put_str_right_u(t_struc *temp, char **str)
{
	int		i;
	int		j;
	int		k;

	(ZERO == 1) ? put_zero_beg(temp, str, WIDTH) : 0;
	(UNUM == 0 && ISDOT == 1) ? (DISCHNUM = -1) : 0;
	i = MINWIDTH - DISCHNUM;
	j = 0;
	k = 0;
	while (k++ < DISCHNUM && (*str)[i])
		(*str)[i++] = ITOANUM[j++];
}

/*
** Make str for u specifier, add flags, add width, add precis
*/

void	make_str_u(t_struc *temp, char **str)
{
	(MINUS == 1) ? ZERO = 0 : 0;
	if (PRECIS != 0)
	{
		(ZERO == 1) ? (ZERO = 0) : 0;
		MINUS == 1 ? put_zero_beg(temp, str, PRECIS) :
			put_zero_end(str, PRECIS, MINWIDTH);
	}
	(MINUS == 1) ? put_str_left_u(temp, str) :
		put_str_right_u(temp, str);
}

/*
**	Find MINWIDTH and allocate the memory for str and put ' '
*/

char	*make_output_str_u(t_struc *temp)
{
	char	*str;

	MINWIDTH = DISCHNUM;
	(PRECIS > DISCHNUM && PRECIS >= WIDTH) ? (MINWIDTH = PRECIS) : 0;
	(WIDTH > DISCHNUM && WIDTH > PRECIS) ? (MINWIDTH = WIDTH) : 0;
	if (UNUM == 0 && ISDOT == 1)
		(WIDTH == 0 && PRECIS == 0) ? (MINWIDTH = 0) : 0;
	str = (char*)malloc(sizeof(char) * (MINWIDTH + 1));
	str = ft_memset(str, ' ', MINWIDTH);
	str[MINWIDTH] = '\0';
	make_str_u(temp, &str);
	return (str);
}
