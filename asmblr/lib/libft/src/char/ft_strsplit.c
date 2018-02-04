/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapteli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 13:56:15 by skapteli          #+#    #+#             */
/*   Updated: 2017/03/06 17:15:20 by skapteli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_s(char const *s, char c, int i)
{
	int n;

	n = 0;
	if (s)
	{
		while (s[i] != c && s[i])
		{
			i++;
			n++;
		}
		return (n);
	}
	else
		return (0);
}

static int	ft_count(char const *s, char c)
{
	int		i;
	int		word;
	int		isword;

	i = 0;
	word = 0;
	if (s)
	{
		while (s[i])
		{
			while (s[i] != c && s[i])
			{
				isword = 1;
				i++;
			}
			if (s[i] == c || s[i] == '\0')
			{
				if (isword == 1)
					word += 1;
				isword = 0;
				i++;
			}
		}
	}
	return (word);
}

static char	**ft_makeptr(char const *s, char c, char **ptr)
{
	int		i;
	int		j;
	int		word;

	word = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			j = 0;
			if (!(ptr[word] = (char *)malloc(sizeof(char *) *
				ft_s(s, c, i) + 1)))
				return (NULL);
			while (s[i] != c && s[i])
				ptr[word][j++] = s[i++];
			ptr[word++][j] = '\0';
		}
	}
	ptr[word] = 0;
	return (ptr);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**ptr;

	if (!(ptr = (char **)malloc(sizeof(char**) * ft_count(s, c) + 1)))
		return (NULL);
	if (s)
	{
		ptr = ft_makeptr(s, c, ptr);
		return (ptr);
	}
	else
		return (NULL);
}
