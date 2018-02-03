/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapteli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 13:03:48 by skapteli          #+#    #+#             */
/*   Updated: 2017/03/04 13:04:35 by skapteli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
**  Put str left if MINUS == 1, add another FLAGS + TAB
*/

void	put_str_left_s(t_struc *temp, char ***str)
{
	int		i;
	int		k;
	int		j;
	char	*nul;

	nul = "(null)";
	i = 0;
	j = 0;
	k = 0;
	if (TAB)
		while (k++ < DISCHNUM && (**str)[i] && TAB[j])
			(**str)[i++] = TAB[j++];
	else
		while (k++ < DISCHNUM && (**str)[i] && nul[j])
			(**str)[i++] = nul[j++];
}

/*
**  Put str right if MINUS == 0, add another FLAGS + TAB
*/

void	put_str_right_s(t_struc *temp, char ***str)
{
	int		i;
	int		j;
	int		k;
	char	*nul;

	nul = "(null)";
	i = MINWIDTH - DISCHNUM;
	j = 0;
	k = (PRECIS == 0 && ISDOT == 1) ? DISCHNUM : 0;
	if (TAB)
		while (k++ < DISCHNUM && (**str)[i] && TAB[j])
			(**str)[i++] = TAB[j++];
	else
		while (k++ < DISCHNUM && (**str)[i] && nul[j])
			(**str)[i++] = nul[j++];
}

/*
** Make str for s specifier add width, add precis
*/

void	make_str_s(t_struc *temp, char **str)
{
	(MINUS == 1) ? ZERO = 0 : 0;
	(ZERO == 1) ? put_zero_beg(temp, str, MINWIDTH) : 0;
	(MINUS == 1) ? put_str_left_s(temp, &str) :
		put_str_right_s(temp, &str);
}

/*
**	Find MINWIDTH and allocate the memory for str and put ' '
*/

char	*make_output_str_s(t_struc *temp)
{
	char	*str;

	(SPECIF == 'S') ? (LENGTH0 = 'l') : 0;
	(SPECIF == 'S') ? (SPECIF = 's') : 0;
	if (TAB == NULL)
		(MINWIDTH = 6);
	else
		(MINWIDTH = DISCHNUM);
	(TAB == NULL) ? (DISCHNUM = MINWIDTH) : 0;
	(PRECIS == 0 && ISDOT == 1) ? (MINWIDTH = 0) : 0;
	(PRECIS != 0 && PRECIS < MINWIDTH) ? (DISCHNUM = PRECIS) : 0;
	(PRECIS != 0 && PRECIS < MINWIDTH) ? (MINWIDTH = PRECIS) : 0;
	(WIDTH > MINWIDTH) ? (MINWIDTH = WIDTH) : 0;
	if (!(str = (char*)malloc(sizeof(char) * (MINWIDTH + 1))))
		return (NULL);
	str = ft_memset(str, ' ', MINWIDTH);
	str[MINWIDTH] = '\0';
	make_str_s(temp, &str);
	return (str);
}

/*
**	Print s specifier
*/

void	ft_print_s(t_struc *temp, va_list arg)
{
	char	*tab;
	char	*str;

	if (LENGTH0 == 'l')
		tab = (char *)va_arg(arg, wchar_t *);
	else
		tab = (char *)va_arg(arg, char *);
	TAB = tab;
	if (tab)
		DISCHNUM = ft_strlen(tab);
	str = make_output_str_s(temp);
	write(1, str, MINWIDTH);
	free(str);
}
