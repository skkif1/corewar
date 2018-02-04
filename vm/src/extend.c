/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extend.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudakov <vrudakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 20:29:07 by vrudakov          #+#    #+#             */
/*   Updated: 2018/01/28 20:30:04 by vrudakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

int				lst_size(t_list *list)
{
	t_list	*temp;
	int		i;

	i = 0;
	temp = list;
	if (temp == NULL)
		return (0);
	while (temp)
	{
		if (((t_process*)temp->content)->id != 2000000000)
		{
			i++;
		}
		temp = temp->next;
	}
	return (i);
}

int				get_opcode_by_name(char *name)
{
	int i;

	i = 0;
	while (i < 16)
	{
		if (!strcmp(name, g_tab[i].name))
			return (i);
		i++;
	}
	return (-1);
}

void			print_exit(char *str)
{
	ft_putstr(str);
	exit(EXIT_FAILURE);
}
