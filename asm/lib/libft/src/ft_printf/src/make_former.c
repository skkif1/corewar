/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_former.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapteli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 12:24:50 by skapteli          #+#    #+#             */
/*   Updated: 2017/03/04 13:14:53 by skapteli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** make_former_without_specif - makes former without specificator
** for example: %-10y
*/

void	make_former_without_specif(t_struc *temp, char **former, char *str)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = ft_strlen(str);
	while (valid(str[i]) == 1)
		i++;
	if (i < len)
		ONECH = str[i];
	i = (i == len ? i : (i + 1));
	*former = (char *)malloc(sizeof(char) * (i + 1));
	while (i-- > 0)
	{
		(*former)[j] = str[j];
		j++;
	}
	(*former)[j] = '\0';
}

void	make_former(t_struc *temp, char **former, char *str)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	while (nonspec(str[i]) == 1)
	{
		if (valid(str[i]) == 1 || str[i] == '\0')
			i++;
		else
			break ;
	}
	if (nonvalid(str[i]))
		make_former_without_specif(temp, former, str);
	else
	{
		i++;
		*former = (char *)malloc(sizeof(char) * (i + 1));
		while (i-- > 0)
		{
			(*former)[j] = str[j];
			j++;
		}
		(*former)[j] = '\0';
	}
}
