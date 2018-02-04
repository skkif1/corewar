/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapteli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 13:26:14 by skapteli          #+#    #+#             */
/*   Updated: 2017/03/06 17:22:02 by skapteli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	int				flag;

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] && i < len)
	{
		if (big[i] == little[0])
		{
			j = 0;
			flag = 1;
			while (little[j] && flag == 1)
			{
				if (big[i + j] != little[j])
					flag = 0;
				j++;
			}
			if (flag == 1 && (i + j) <= len)
				return ((char *)(big + i));
		}
		i++;
	}
	return (NULL);
}
