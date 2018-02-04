/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapteli <skapteli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 20:03:13 by skapteli          #+#    #+#             */
/*   Updated: 2017/12/07 13:35:44 by skapteli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		is_white_space(char c)
{
	if (c == '\t' || c == ' ' || c == '\n' || c == '\v' || c == '\f' ||
			c == '\r')
		return (1);
	return (0);
}

int		is_label_char(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

int		valid_int(char *num_str, const char *src, int i, int l)
{
	while (ft_isdigit(num_str[l]))
		l++;
	if (num_str[l] == '\0')
	{
		if (l >= 10)
		{
			if (l > 10)
				return (0);
			while (i < l)
			{
				if (num_str[i] > src[i])
					return (0);
				if (num_str[i] == src[i])
					i++;
				else
					return (1);
			}
		}
		return (1);
	}
	return (0);
}

int		is_only_digits(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-')
	{
		i++;
		if (s[i] == '\0')
			return (0);
		return (valid_int(&s[i], "2147483648", 0, 0));
	}
	if (s[i] == '\0')
		return (0);
	return (valid_int(&s[i], "4294967295", 0, 0));
}

int		is_opcode(t_st *st, char *op_code)
{
	int	i;

	i = -1;
	while (++i < 17)
		if (ft_strequ(st->op[i].name, op_code))
			return (1);
	return (0);
}
