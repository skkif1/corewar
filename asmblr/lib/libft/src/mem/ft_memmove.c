/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapteli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 19:44:32 by skapteli          #+#    #+#             */
/*   Updated: 2017/03/06 17:16:53 by skapteli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*copy_dst;
	const unsigned char	*copy_src;

	copy_dst = dst;
	copy_src = src;
	if (len)
	{
		if (copy_src < copy_dst)
		{
			copy_dst += len;
			copy_src += len;
			while (len--)
				*--copy_dst = *--copy_src;
		}
		else
			while (len--)
				*copy_dst++ = *copy_src++;
	}
	return (dst);
}
