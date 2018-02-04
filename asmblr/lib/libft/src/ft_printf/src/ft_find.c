/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapteli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 12:55:04 by skapteli          #+#    #+#             */
/*   Updated: 2017/03/04 12:56:02 by skapteli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	find_flags(char c, t_struc *temp)
{
	c == '-' ? MINUS = 1 : 0;
	c == '+' ? PLUS = 1 : 0;
	c == ' ' ? SPACE = 1 : 0;
	c == '#' ? OCT = 1 : 0;
	c == '0' ? ZERO = 1 : 0;
}

int		find_width(char *former, t_struc *temp, va_list arg)
{
	int		width;
	int		i;
	char	*wid;

	i = 0;
	if (former[i] == '*')
	{
		WIDTH = (int)va_arg(arg, int);
		(WIDTH < 0) ? (MINUS = 1) : 0;
		WIDTH = (WIDTH < 0) ? -(WIDTH) : WIDTH;
		return (1);
	}
	while (former[i] >= '0' && former[i] <= '9' && former[i])
		i++;
	wid = (char *)malloc(sizeof(char) * (i + 1));
	wid = ft_strncpy(wid, former, i + 1);
	width = ft_atoi(wid);
	free(wid);
	WIDTH = width;
	return (get_discharge((long long int)width));
}

int		find_precis(char *former, t_struc *temp, va_list arg)
{
	char	*prec;
	int		i;
	int		precis;

	i = 0;
	former++;
	ISDOT = 1;
	if (former[i] == '*')
		PRECIS = (int)va_arg(arg, int);
	if (former[i] == '*')
		return (2);
	while (former[i] >= '0' && former[i] <= '9' && former[i])
		i++;
	prec = (char *)malloc(sizeof(char) * (i + 1));
	prec = ft_strncpy(prec, former, i + 1);
	precis = ft_atoi(prec);
	free(prec);
	PRECIS = precis;
	return ((i == 0) ? 1 : ((long long int)(get_discharge(precis) + 1)));
}

int		find_specif(char *former, t_struc *temp)
{
	if ((*former == 's' || *former == 'S' || *former == 'p' ||
		*former == 'd' || *former == 'D' || *former == 'i' ||
		*former == 'o' || *former == 'O' || *former == 'u' ||
		*former == 'U' || *former == 'x' || *former == 'X' ||
		*former == 'c' || *former == 'C' || *former == 'b' ||
		*former == 'q' || *former == 'm') && *former)
	{
		SPECIF = *former;
		return (1);
	}
	return (0);
}
