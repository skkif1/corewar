/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapteli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 12:58:17 by skapteli          #+#    #+#             */
/*   Updated: 2017/03/04 12:59:20 by skapteli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

long long int				find_number_di(t_struc *temp, va_list arg)
{
	long long int	n;

	if (LENGTH0 == '\0')
		n = (int)va_arg(arg, int);
	if (LENGTH0 == 'h')
	{
		if (LENGTH1 == 'h')
			n = (signed char)va_arg(arg, int);
		else
			n = (short int)va_arg(arg, int);
	}
	if (LENGTH0 == 'l')
	{
		if (LENGTH1 == 'l')
			n = (long long int)va_arg(arg, long long int);
		else
			n = (long int)va_arg(arg, long int);
	}
	if (LENGTH0 == 'j')
		n = (intmax_t)va_arg(arg, intmax_t);
	if (LENGTH0 == 'z')
		n = (size_t)va_arg(arg, size_t);
	return (n);
}

unsigned long long int		make_buf(int dischnum)
{
	unsigned long long int	buf;

	buf = 1;
	while (dischnum-- > 1)
		buf *= 10;
	return (buf);
}

char						*itoa_num(long long int n, int dischnum)
{
	int						i;
	unsigned long long int	buf;
	char					*str;

	i = 0;
	buf = make_buf(dischnum);
	n = (n < 0) ? -n : n;
	(n == 0) ? (str = (char*)malloc(sizeof(char) * 2)) :
		(str = (char *)malloc(sizeof(char) * (dischnum + 1)));
	if (n == 0)
		str[i++] = '0';
	else
	{
		while (buf > 0)
		{
			str[i++] = (char)((n / buf) + '0');
			n %= buf;
			buf /= 10;
		}
	}
	str[i] = '\0';
	return (str);
}

void						add_num_in_struc_di(t_struc *temp, long long int n)
{
	NUM = n;
	DISCHNUM = get_discharge(n);
	ITOANUM = itoa_num(n, DISCHNUM);
}

void						ft_print_di(t_struc *temp, va_list arg)
{
	long long int	n;
	char			*str;

	if (SPECIF == 'D')
	{
		LENGTH0 = 'l';
		LENGTH1 = '\0';
		SPECIF = 'd';
	}
	n = find_number_di(temp, arg);
	add_num_in_struc_di(temp, n);
	str = make_output_str_di(temp);
	write(1, str, MINWIDTH);
	if (ITOANUM)
		free(ITOANUM);
	free(str);
}
