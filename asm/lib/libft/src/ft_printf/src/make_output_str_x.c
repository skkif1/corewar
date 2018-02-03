/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_output_str_x.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapteli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 13:18:46 by skapteli          #+#    #+#             */
/*   Updated: 2017/03/04 13:26:31 by skapteli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

#define CONDMINWIDTH (OCT == 1 && UNUM != 0 && PRWI)
#define PRWI		(PRECIS <= MINWIDTH && WIDTH < MINWIDTH)
#define CONDFORP1	(UNUM == 0 && SPECIF == 'p' && ISDOT == 1 && PRECIS == 0)
#define CONDFORP2 	(UNUM == 0 && SPECIF == 'p' && ISDOT == 0 && WIDTH == 0)
#define CONDFORP3 	(UNUM == 0 && SPECIF == 'p' && ISDOT == 1 && PRECIS != 0)

/*
**  Put str left if MINUS == 1, add another FLAGS + ITOANUM
*/

void	put_str_left_x(t_struc *temp, char **str)
{
	int		i;
	int		k;
	int		j;

	(UNUM == 0 && ISDOT == 1) ? (DISCHNUM = -1) : 0;
	i = (OCT == 1) ? 2 : 0;
	if (OCT == 1)
	{
		(*str)[0] = '0';
		if (SPECIF == 'X')
			((*str)[1] = 'X');
		else
			((*str)[1] = 'x');
	}
	(PRECIS > DISCHNUM) ? (i += PRECIS - DISCHNUM) : 0;
	j = 0;
	k = 0;
	while (k++ < DISCHNUM && (*str)[i])
		(*str)[i++] = ITOANUM[j++];
}

/*
**  Put str right if MINUS == 0, add another FLAGS + ITOANUM
*/

void	put_str_right_x(t_struc *temp, char **str)
{
	int		i;
	int		j;
	int		k;
	int		oct;

	(ZERO == 1) ? put_zero_beg(temp, str, WIDTH) : 0;
	(UNUM == 0 && ISDOT == 1 && OCT == 0) ? (DISCHNUM = -1) : 0;
	i = CONDFORP1 ? MINWIDTH : (MINWIDTH - DISCHNUM);
	if (OCT == 1)
	{
		if (ZERO == 1)
			oct = 2;
		else
			oct = (PRECIS > DISCHNUM) ? (MINWIDTH - PRECIS) : i;
		if (SPECIF == 'X')
			((*str)[oct - 1] = 'X');
		else
			((*str)[oct - 1] = 'x');
		(*str)[oct - 2] = '0';
	}
	j = 0;
	k = 0;
	while (k++ < DISCHNUM && (*str)[i])
		(*str)[i++] = ITOANUM[j++];
}

/*
** Make str for x specifier, add flags, add width, add precis
*/

void	make_str_x(t_struc *temp, char **str)
{
	(MINUS == 1) ? ZERO = 0 : 0;
	if (PRECIS != 0)
	{
		(ZERO == 1) ? (ZERO = 0) : 0;
		MINUS == 1 ? put_zero_beg(temp, str, PRECIS) :
			put_zero_end(str, PRECIS, MINWIDTH);
	}
	(MINUS == 1) ? put_str_left_x(temp, str) :
		put_str_right_x(temp, str);
}

/*
**	Find minwidth for p specif
*/

void	find_minwidth_for_p(t_struc *temp)
{
	MINWIDTH = DISCHNUM + 2;
	(PRECIS > DISCHNUM && PRECIS > WIDTH && PRECIS > MINWIDTH) ?
		(MINWIDTH = PRECIS) : 0;
	(WIDTH > DISCHNUM && WIDTH > PRECIS && WIDTH > MINWIDTH) ?
		(MINWIDTH = WIDTH) : 0;
	(PRECIS >= DISCHNUM + 2 && WIDTH < DISCHNUM + 2) ?
		(MINWIDTH = MINWIDTH + 2) : 0;
	CONDFORP1 ? (MINWIDTH = 2) : 0;
	CONDFORP2 ? (MINWIDTH = 3) : 0;
}

/*
**	Find MINWIDTH and allocate the memory for str and put ' '
*/

char	*make_output_str_x(t_struc *temp)
{
	char	*str;

	if (SPECIF == 'p')
		find_minwidth_for_p(temp);
	else
	{
		MINWIDTH = DISCHNUM;
		(PRECIS > DISCHNUM && PRECIS >= WIDTH) ? (MINWIDTH = PRECIS) : 0;
		(WIDTH > DISCHNUM && WIDTH > PRECIS) ? (MINWIDTH = WIDTH) : 0;
		if (UNUM == 0 && ISDOT == 1)
			(WIDTH == 0 && PRECIS == 0) ? (MINWIDTH = 0) : 0;
		else
			CONDMINWIDTH ? (MINWIDTH = MINWIDTH + 2) : 0;
	}
	if (!(str = (char*)malloc(sizeof(char) * (MINWIDTH + 1))))
		return (NULL);
	str = ft_memset(str, ' ', MINWIDTH);
	str[MINWIDTH] = '\0';
	make_str_x(temp, &str);
	return (str);
}
