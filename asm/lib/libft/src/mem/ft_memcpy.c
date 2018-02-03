/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapteli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 17:25:59 by skapteli          #+#    #+#             */
/*   Updated: 2017/03/06 17:16:46 by skapteli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*copy_dest;
	const char	*copy_src;

	copy_dest = dest;
	copy_src = src;
	while (n--)
		*copy_dest++ = *copy_src++;
	return (dest);
}
