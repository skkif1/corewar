/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapteli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 12:50:31 by skapteli          #+#    #+#             */
/*   Updated: 2017/03/06 17:21:59 by skapteli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char				*ptr;
	unsigned int		i;

	i = 0;
	if (!(ptr = (char *)(malloc(sizeof(char) * size + 1))))
		return (NULL);
	while (i < size + 1)
		ptr[i++] = '\0';
	return (ptr);
}
