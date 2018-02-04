/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapteli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 12:02:34 by skapteli          #+#    #+#             */
/*   Updated: 2017/03/06 17:16:44 by skapteli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *copy_s1;
	const unsigned char *copy_s2;

	copy_s1 = s1;
	copy_s2 = s2;
	while (n--)
	{
		if (*copy_s1 != *copy_s2)
			return (*copy_s1 - *copy_s2);
		else
		{
			copy_s1++;
			copy_s2++;
		}
	}
	return (0);
}
