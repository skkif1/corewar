/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_output_str_di.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapteli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 13:15:05 by skapteli          #+#    #+#             */
/*   Updated: 2017/03/04 13:55:06 by skapteli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

#define CONDMINWIDTH1 	(PRWI2 && (PLUS == 1 || SPACE == 1 || NUM < 0))
#define CONDMINWIDTH2 	(PRWI && NUM >= 0 && (SPACE == 1 || PLUS == 1))
#define PRWI			(WIDTH < MINWIDTH && PRECIS < MINWIDTH)
#define PRWI2			(PRECIS > 0 && PRECIS >= MINWIDTH)

/*
**  Put str left if MINUS == 1, add another FLAGS + ITOANUM
*/

void	put_str_left(t_struc *temp, char **str)
{
	int		i;
	int		k;
	int		j;

	if (PLUS == 1)
	{
		if (NUM < 0)
			((*str)[0] = '-');
		else
			((*str)[0] = '+');
	}
	(SPACE == 1 && NUM > 0) ? ((*str)[0] = ' ') : 0;
	(SPACE == 1 && NUM < 0) ? ((*str)[0] = '-') : 0;
	(NUM < 0) ? ((*str)[0] = '-') : 0;
	(NUM == 0 && ISDOT == 1) ? (DISCHNUM = -1) : 0;
	i = (SPACE == 1 || PLUS == 1 || NUM < 0) ? 1 : 0;
	(PRECIS > DISCHNUM) ? (i += PRECIS - DISCHNUM) : 0;
	j = 0;
	k = 0;
	while (k++ < DISCHNUM && (*str)[i])
		(*str)[i++] = ITOANUM[j++];
}

/*
**	Put sign in right place
*/

void	put_sign_in_str(t_struc *temp, char **str)
{
	int		sign;

	if (ZERO == 1)
	{
		if (PLUS == 1)
		{
			(NUM < 0) ? ((*str)[0] = '-') : 0;
			(NUM >= 0) ? ((*str)[0] = '+') : 0;
		}
		(SPACE == 1 && NUM > 0) ? ((*str)[0] = ' ') : 0;
		(NUM < 0) ? ((*str)[0] = '-') : 0;
	}
	else
	{
		sign = (PRECIS > DISCHNUM) ? (MINWIDTH - PRECIS - 1) :
			(MINWIDTH - DISCHNUM - 1);
		if (PLUS == 1)
		{
			(NUM < 0) ? ((*str)[sign] = '-') : 0;
			(NUM >= 0) ? ((*str)[sign] = '+') : 0;
		}
		(SPACE == 1 && NUM > 0) ? ((*str)[sign] = ' ') : 0;
		(NUM < 0) ? ((*str)[sign] = '-') : 0;
	}
}

/*
**  Put str right if MINUS == 0, add another FLAGS + ITOANUM
*/

void	put_str_right(t_struc *temp, char **str)
{
	int		i;
	int		j;
	int		k;

	(ZERO == 1) ? put_zero_beg(temp, str, WIDTH) : 0;
	(PLUS == 1) ? SPACE = 0 : 0;
	(NUM == 0 && ISDOT == 1) ? (DISCHNUM = -1) : 0;
	put_sign_in_str(temp, str);
	i = MINWIDTH - DISCHNUM;
	j = 0;
	k = 0;
	while (k++ < DISCHNUM && (*str)[i])
		(*str)[i++] = ITOANUM[j++];
}

/*
** Make str for d and i specifier, add flags, add width, add precis
*/

void	make_str_di(t_struc *temp, char **str)
{
	(MINUS == 1) ? ZERO = 0 : 0;
	(PLUS == 1) ? SPACE = 0 : 0;
	if (PRECIS != 0 || ISDOT == 1)
	{
		(ZERO == 1) ? (ZERO = 0) : 0;
		MINUS == 1 ? put_zero_beg(temp, str, PRECIS) :
			put_zero_end(str, PRECIS, MINWIDTH);
	}
	(MINUS == 1) ? put_str_left(temp, str) : put_str_right(temp, str);
}

/*
**	Find MINWIDTH and allocate the memory for str and put ' '
*/

char	*make_output_str_di(t_struc *temp)
{
	char	*str;

	if (NUM < 0)
		(MINWIDTH = DISCHNUM + 1);
	else
		(MINWIDTH = DISCHNUM);
	(PRECIS > DISCHNUM && PRECIS >= WIDTH) ? (MINWIDTH = PRECIS) : 0;
	(WIDTH > DISCHNUM && WIDTH > PRECIS) ? (MINWIDTH = WIDTH) : 0;
	if (NUM == 0 && ISDOT == 1)
		(WIDTH == 0 && PRECIS == 0 && PLUS == 0 && SPACE == 0) ?
			(MINWIDTH = 0) : 0;
	else
	{
		MINWIDTH = CONDMINWIDTH1 ? (MINWIDTH + 1) : MINWIDTH;
		MINWIDTH = CONDMINWIDTH2 ? (MINWIDTH + 1) : MINWIDTH;
	}
	if (!(str = (char*)malloc(sizeof(char) * (MINWIDTH + 1))))
		return (NULL);
	str = ft_memset(str, ' ', MINWIDTH);
	str[MINWIDTH] = '\0';
	make_str_di(temp, &str);
	return (str);
}
