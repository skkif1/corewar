/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapteli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 12:56:53 by skapteli          #+#    #+#             */
/*   Updated: 2017/03/04 12:58:08 by skapteli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Make str for c specifier add width, add precis
*/

void	make_str_c(t_struc *temp, char **str)
{
	(MINUS == 1) ? ZERO = 0 : 0;
	(ZERO == 1) ? put_zero_beg(temp, str, MINWIDTH) : 0;
	if (MINUS == 1)
		((*str)[0] = CH);
	else
		((*str)[MINWIDTH - 1] = CH);
}

/*
**	Find MINWIDTH and allocate the memory for str and put ' '
*/

char	*make_output_str_c(t_struc *temp)
{
	char	*str;

	MINWIDTH = DISCHNUM;
	(WIDTH > DISCHNUM) ? (MINWIDTH = WIDTH) : 0;
	if (!(str = (char*)malloc(sizeof(char) * (MINWIDTH + 1))))
		return (NULL);
	str = ft_memset(str, ' ', MINWIDTH);
	str[MINWIDTH] = '\0';
	make_str_c(temp, &str);
	return (str);
}

/*
**	Print c specifier
*/

void	ft_print_c(t_struc *temp, va_list arg)
{
	unsigned char	c;
	char			*str;

	(SPECIF == 'C') ? (LENGTH0 = 'l') : 0;
	(SPECIF == 'C') ? (SPECIF = 'c') : 0;
	if (LENGTH0 == 'l')
		c = (char)va_arg(arg, wchar_t);
	else
		c = (unsigned char)va_arg(arg, int);
	CH = c;
	DISCHNUM = 1;
	str = make_output_str_c(temp);
	write(1, str, MINWIDTH);
	free(str);
}
