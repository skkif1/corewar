/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_length.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapteli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 12:49:27 by skapteli          #+#    #+#             */
/*   Updated: 2017/03/04 13:45:54 by skapteli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

#define CONDHL		(former[i + 1] == 'h' || former[i + 1] == 'l')

void	try_put_z(t_struc *temp)
{
	LENGTH0 = 'z';
	if (LENGTH1 != '\0')
		LENGTH1 = '\0';
}

void	try_put_j(t_struc *temp)
{
	if (LENGTH0 != 'z')
	{
		LENGTH0 = 'j';
		if (LENGTH1 != '\0')
			LENGTH1 = '\0';
	}
}

int		try_put_l(char *former, t_struc *temp)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(former);
	if (LENGTH0 != 'j' && LENGTH0 != 'z')
	{
		LENGTH0 = 'l';
		if (LENGTH1 == 'h')
			LENGTH1 = '\0';
	}
	if (i != len && former[i + 1] != '\0' && former[i + 1] == 'l' &&
		LENGTH0 != 'j' && LENGTH0 != 'z')
	{
		LENGTH1 = 'l';
		return (2);
	}
	return (1);
}

int		try_put_h(char *former, t_struc *temp)
{
	int		i;

	i = 0;
	if (LENGTH0 == 'h' && LENGTH1 == 'h' && former[i] == 'h' &&
		former[i + 1] == 'h')
		return (2);
	if (LENGTH0 == 'h' && former[i + 1] == 'h')
		return (1);
	if (LENGTH1 == 'h' && former[i + 1] != '\0' && former[i + 1] != 'h')
	{
		LENGTH1 = '\0';
		return (1);
	}
	if (LENGTH0 != 'l' && LENGTH0 != 'j' && LENGTH0 != 'z')
		LENGTH0 = 'h';
	if (former[i + 1] != '\0' && former[i + 1] == 'h' && LENGTH1 != 'l' &&
		LENGTH0 != 'l' && LENGTH0 != 'j' && LENGTH0 != 'z')
	{
		LENGTH1 = 'h';
		return (2);
	}
	return (1);
}

int		find_length(char *former, t_struc *temp)
{
	int		i;
	int		len;

	if (former[0] == 'z')
		try_put_z(temp);
	else if (former[0] == 'j')
		try_put_j(temp);
	else if (former[0] == 'l')
		return (((try_put_l(former, temp) == 1) ? 1 : 2));
	else if (former[0] == 'h')
		return (((try_put_h(former, temp) == 1) ? 1 : 2));
	i = 0;
	while (former[i] != 'l' && former[i] != 'h' && former[i] != 'j' &&
			former[i] != 'z' && former[i])
		i++;
	if (former[i] == '\0')
		return (0);
	else
	{
		LENGTH0 = former[i];
		len = ft_strlen(former);
		if (len != i)
			CONDHL ? LENGTH1 = former[i + 1] : 0;
	}
	return ((LENGTH1 == '\0') ? 1 : 2);
}
