/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_m.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapteli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 13:00:38 by skapteli          #+#    #+#             */
/*   Updated: 2017/03/04 13:01:07 by skapteli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print(t_struc *temp, unsigned const char *tmp, size_t j, size_t size)
{
	const char	*str;
	int			k;
	size_t		i;

	str = "0123456789abcdef";
	i = 0;
	while (i < 16 && i + j < size)
	{
		k = *(tmp + i + j);
		write(1, (str + (k >> 4) % 16), 1);
		write(1, (str + k % 16), 1);
		(i % 2) ? write(1, " ", 1) : 0;
		MINWIDTH++;
		i++;
	}
	while (i < 16)
	{
		write(1, "  ", 2);
		(i % 2) ? write(1, " ", 1) : 0;
		MINWIDTH++;
		i++;
	}
}

void	print_memory(t_struc *temp, void *addr, size_t size)
{
	unsigned const char	*tmp;
	size_t				i;
	size_t				j;
	int					d;

	j = 0;
	tmp = addr;
	while (j < size)
	{
		print(temp, tmp, j, size);
		i = 0;
		while (i < 16 && i + j < size)
		{
			d = *(tmp + i + j);
			(d >= 32 && d <= 126) ? write(1, &d, 1) : write(1, ".", 1);
			MINWIDTH++;
			i++;
		}
		j += 16;
		write(1, "\n", 1);
	}
}

/*
**	m to print memory
*/

void	ft_print_m(t_struc *temp, va_list arg)
{
	void	*addr;
	size_t	size;

	addr = (void *)va_arg(arg, void*);
	size = (size_t)va_arg(arg, size_t);
	print_memory(temp, addr, size);
}
