/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapteli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 13:55:41 by skapteli          #+#    #+#             */
/*   Updated: 2017/03/06 17:22:15 by skapteli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_emty(void)
{
	char	*str;

	str = (char *)malloc(sizeof(char));
	str[0] = '\0';
	return (str);
}

char		*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		len;
	int		num;

	str = NULL;
	i = 0;
	if (s)
	{
		len = ft_strlen(s) - 1;
		num = len;
		while (((s[i] == ' ') || (s[i] == '\n') || (s[i] == '\t')) && (s[i]))
			if (s[i++ + 1] == '\0')
				return (str = ft_emty());
		while ((s[len] == ' ') || (s[len] == '\n') || (s[len] == '\t'))
			len--;
		if (!(str = ft_strnew(len - i + 1)))
			return (NULL);
		if (num == (len - i + 1))
			str = ft_strcpy(str, s);
		else
			ft_strncpy(str, (s + i), (len - i + 1));
		return (str);
	}
	return (NULL);
}
