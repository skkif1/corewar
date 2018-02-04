/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_oux.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapteli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 13:01:54 by skapteli          #+#    #+#             */
/*   Updated: 2017/03/04 13:38:36 by skapteli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

#define BIGSPECIF (SPECIF == 'O' || SPECIF == 'X')

/*
**	Get next argument in correct type
*/

unsigned long long int	find_number_oux(t_struc *temp, va_list arg)
{
	unsigned long long int	n;

	if (LENGTH0 == '\0')
		n = (unsigned int)va_arg(arg, unsigned int);
	if (LENGTH0 == 'h')
	{
		if (LENGTH1 == 'h')
			n = (unsigned char)va_arg(arg, unsigned int);
		else
			n = (unsigned short int)va_arg(arg, unsigned int);
	}
	if (LENGTH0 == 'l')
	{
		if (LENGTH1 == 'l')
			n = (unsigned long long int)va_arg(arg, unsigned long long int);
		else
			n = (unsigned long int)va_arg(arg, unsigned long int);
	}
	if (LENGTH0 == 'j')
		n = (intmax_t)va_arg(arg, intmax_t);
	if (LENGTH0 == 'z')
		n = (size_t)va_arg(arg, size_t);
	return (n);
}

/*
**	Unsigned long long int to char transformation
*/

char					*uitoa_base(t_struc *temp, int base)
{
	unsigned long long int	n;
	int						i;
	char					*str;
	char					*hex;

	i = 1;
	(BIGSPECIF) ? (hex = "0123456789ABCDEF") : 0;
	(!BIGSPECIF) ? (hex = "0123456789abcdef") : 0;
	n = UNUM;
	if (base < 1)
		return (NULL);
	while (n /= base)
		i++;
	DISCHNUM = i;
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i] = '\0';
	n = UNUM;
	(n == 0U) ? (str[0] = '0') : 0;
	while (n)
	{
		str[--i] = hex[(n % base)];
		n /= base;
	}
	return (str);
}

void					add_num_in_struc_oux(t_struc *temp,
												unsigned long long int n)
{
	UNUM = n;
	if (SPECIF == 'u' || SPECIF == 'U')
		ITOANUM = uitoa_base(temp, 10);
	else if (SPECIF == 'o' || SPECIF == 'O')
		ITOANUM = uitoa_base(temp, 8);
	else if (SPECIF == 'x' || SPECIF == 'X' || SPECIF == 'p')
		ITOANUM = uitoa_base(temp, 16);
	(PRECIS == 1 && UNUM == 0 && SPECIF == 'p') ? (OCT = 1) : 0;
	(PLUS == 1) ? (PLUS = 0) : 0;
	(SPACE == 1) ? (SPACE = 0) : 0;
}

void					change_struct_for_uop(t_struc *temp)
{
	if (SPECIF == 'p')
	{
		OCT = 1;
		LENGTH0 = 'l';
		LENGTH1 = '\0';
	}
	if (SPECIF == 'O')
	{
		LENGTH0 = 'l';
		LENGTH1 = '\0';
		SPECIF = 'o';
	}
	if (SPECIF == 'U')
	{
		LENGTH0 = 'l';
		LENGTH1 = '\0';
		SPECIF = 'u';
	}
}

/*
**	Print o, u, x, O, U, X, p specifier
*/

void					ft_print_oux(t_struc *temp, va_list arg)
{
	unsigned long long int	n;
	char					*str;

	if (SPECIF == 'O' || SPECIF == 'p' || SPECIF == 'U')
		change_struct_for_uop(temp);
	n = find_number_oux(temp, arg);
	add_num_in_struc_oux(temp, n);
	if (SPECIF == 'u' || SPECIF == 'U')
		str = make_output_str_u(temp);
	if (SPECIF == 'o' || SPECIF == 'O')
		str = make_output_str_o(temp);
	if (SPECIF == 'x' || SPECIF == 'X' || SPECIF == 'p')
		str = make_output_str_x(temp);
	write(1, str, MINWIDTH);
	if (ITOANUM)
		free(ITOANUM);
	free(str);
}
