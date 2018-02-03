/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapteli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 18:23:45 by skapteli          #+#    #+#             */
/*   Updated: 2017/03/06 17:17:51 by skapteli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;
	int		k;

	k = -1;
	i = ft_strlen(s1);
	if ((s2 = (char *)(malloc(sizeof(char) * i + 1))) == NULL)
		return (NULL);
	while (i > ++k)
		s2[k] = s1[k];
	s2[i] = '\0';
	return (s2);
}
