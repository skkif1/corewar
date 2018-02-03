/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_output_str_o.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapteli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 13:17:31 by skapteli          #+#    #+#             */
/*   Updated: 2017/03/04 13:34:44 by skapteli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

#define CONDMINWIDTH 	(OCT == 1 && UNUM != 0 && PRWI)
#define PRWI			(PRECIS < MINWIDTH && WIDTH < MINWIDTH)

/*
**  Put str left if MINUS == 1, add another FLAGS + ITOANUM
*/

void	put_str_left_o(t_struc *temp, char **str)
{
	int		i;
	int		k;
	int		j;

	(UNUM == 0 && ISDOT == 1) ? (DISCHNUM = -1) : 0;
	i = (OCT == 1 && DISCHNUM > PRECIS) ? 1 : 0;
	(OCT == 1 && (i - 1) >= 0) ? ((*str)[i - 1] = '0') : 0;
	(PRECIS > DISCHNUM) ? (i += PRECIS - DISCHNUM) : 0;
	j = 0;
	k = 0;
	while (k++ < DISCHNUM && (*str)[i])
		(*str)[i++] = ITOANUM[j++];
}

/*
**  Put str right if MINUS == 0, add another FLAGS + ITOANUM
*/

void	put_str_right_o(t_struc *temp, char **str)
{
	int		i;
	int		j;
	int		k;

	(ZERO == 1) ? put_zero_beg(temp, str, WIDTH) : 0;
	(UNUM == 0 && ISDOT == 1 && OCT == 0) ? (DISCHNUM = -1) : 0;
	i = MINWIDTH - DISCHNUM;
	(OCT == 1 && (i - 1) >= 0) ? ((*str)[i - 1] = '0') : 0;
	j = 0;
	k = 0;
	while (k++ < DISCHNUM && (*str)[i])
		(*str)[i++] = ITOANUM[j++];
}

/*
** Make str for o specifier, add flags, add width, add precis
*/

void	make_str_o(t_struc *temp, char **str)
{
	(MINUS == 1) ? ZERO = 0 : 0;
	if (PRECIS != 0)
	{
		(ZERO == 1) ? (ZERO = 0) : 0;
		MINUS == 1 ? put_zero_beg(temp, str, PRECIS) :
			put_zero_end(str, PRECIS, MINWIDTH);
	}
	(MINUS == 1) ? put_str_left_o(temp, str) :
		put_str_right_o(temp, str);
}

/*
**	Find MINWIDTH and allocate the memory for str and put ' '
*/

char	*make_output_str_o(t_struc *temp)
{
	char	*str;

	MINWIDTH = DISCHNUM;
	(PRECIS > DISCHNUM && PRECIS >= WIDTH) ? (MINWIDTH = PRECIS) : 0;
	(WIDTH > DISCHNUM && WIDTH > PRECIS) ? (MINWIDTH = WIDTH) : 0;
	if (UNUM == 0 && ISDOT == 1 && OCT == 0)
		(WIDTH == 0 && PRECIS == 0) ? (MINWIDTH = 0) : 0;
	else
		CONDMINWIDTH ? (MINWIDTH = MINWIDTH + 1) : 0;
	if (!(str = (char*)malloc(sizeof(char) * (MINWIDTH + 1))))
		return (NULL);
	str = ft_memset(str, ' ', MINWIDTH);
	str[MINWIDTH] = '\0';
	make_str_o(temp, &str);
	return (str);
}
