/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapteli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 13:56:54 by skapteli          #+#    #+#             */
/*   Updated: 2017/03/06 17:15:35 by skapteli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(long copy_n, int mod)
{
	int i;

	i = 0;
	while (mod > 0)
	{
		if (copy_n / mod != 0)
			i++;
		mod = mod / 10;
	}
	return (i);
}

static int	ft_iszero(char *str, long copy_n)
{
	if (copy_n == 0)
	{
		str[0] = '0';
		return (1);
	}
	return (0);
}

static int	ft_isnegative(char *str, long copy_n)
{
	if (copy_n < 0)
	{
		str[0] = '-';
		return (1);
	}
	return (0);
}

static char	*ft_makestr(char *str, int mod, long copy_n, int i)
{
	while (mod > 0)
	{
		if (copy_n >= 0)
			str[i] = copy_n / mod + '0';
		copy_n = (copy_n - (copy_n / mod) * mod);
		mod = mod / 10;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		mod;
	long	copy_n;

	copy_n = n;
	i = 0;
	mod = 1000000000;
	if (!(str = (char *)malloc(sizeof(char) * ft_size(copy_n, mod) + 2)))
		return (NULL);
	if (ft_iszero(str, copy_n))
		return (str);
	if (ft_isnegative(str, copy_n))
	{
		copy_n = -copy_n;
		i++;
	}
	while ((copy_n / mod) == 0)
		mod = mod / 10;
	str = ft_makestr(str, mod, copy_n, i);
	return (str);
}
