/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapteli <skapteli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 18:17:10 by skapteli          #+#    #+#             */
/*   Updated: 2017/12/07 18:35:41 by skapteli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	free_string(char *str)
{
	if (str == NULL)
		return ;
	free(str);
	str = NULL;
}

void	free_two_dimensional_char_array(char **array)
{
	int	i;

	i = 0;
	if (array == NULL)
		return ;
	while (array[i])
	{
		free_string(array[i]);
		i++;
	}
	free(array);
}
