/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   istrue.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapteli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 13:12:58 by skapteli          #+#    #+#             */
/*   Updated: 2017/03/04 13:13:50 by skapteli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		valid(char c)
{
	if (c == '#' || c == '-' || c == '+' || c == ' ' || c == 'h' || c == 'l' ||
		c == 'j' || c == 'z' || c == '.' || (c >= '0' && c <= '9') || c == '*')
		return (1);
	return (0);
}

int		nonspec(char c)
{
	if (c != 's' && c != 'S' && c != 'p' && c != 'd' && c != 'D' && c != 'i' &&
		c != 'o' && c != 'O' && c != 'u' && c != 'U' && c != 'x' && c != 'X' &&
		c != 'c' && c != 'C' && c != 'b' && c != 'q' && c != 'm' && c != '\0')
		return (1);
	return (0);
}

int		nonvalid(char c)
{
	if (c != '#' && c != '-' && c != '+' && c != ' ' && c != 'h' && c != 'l' &&
		c != 'j' && c != 'z' && c != '.' && c != '*' && c != '\0')
		return (1);
	return (0);
}

int		emptystruc(t_struc *temp, char c)
{
	if (MINUS == '\0' && PLUS == '\0' && SPACE == '\0' && OCT == '\0' &&
		ZERO == '\0' && ONECH == '\0' && WIDTH == 0 && PRECIS == 0 &&
		LENGTH0 == '\0' && LENGTH1 == '\0' && SPECIF == '\0' &&
		MINWIDTH == 0 && NUM == 0 && DISCHNUM == 0 && ITOANUM == NULL &&
		ISDOT == 0 && UNUM == 0 && CH == '\0' && TAB == NULL && c == '\0')
		return (1);
	return (0);
}
