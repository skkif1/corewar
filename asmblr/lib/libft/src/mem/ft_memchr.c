/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapteli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 11:20:01 by skapteli          #+#    #+#             */
/*   Updated: 2017/03/06 17:16:41 by skapteli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char *copy_s;

	copy_s = s;
	while (n--)
	{
		if (*copy_s++ == (unsigned char)c)
			return ((void *)(copy_s - 1));
	}
	return (NULL);
}
