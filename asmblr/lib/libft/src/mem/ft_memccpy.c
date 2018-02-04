/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapteli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 09:23:30 by skapteli          #+#    #+#             */
/*   Updated: 2017/03/06 17:16:36 by skapteli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char		*copy_dst;
	const char	*copy_src;

	copy_dst = dst;
	copy_src = src;
	while (n--)
	{
		*copy_dst++ = *copy_src;
		if (*copy_src == (char)c)
			return (copy_dst);
		copy_src++;
	}
	return (NULL);
}
