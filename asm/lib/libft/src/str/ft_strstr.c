/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapteli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 12:46:21 by skapteli          #+#    #+#             */
/*   Updated: 2017/03/06 17:22:08 by skapteli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	len = ft_strlen(little);
	if (len == 0)
		return ((char *)big);
	while (big[i])
	{
		j = 0;
		while (big[i + j] == little[j])
		{
			if (j == len - 1)
				return ((char *)big + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
