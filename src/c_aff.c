/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_aff.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omotyliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 19:47:45 by omotyliu          #+#    #+#             */
/*   Updated: 2018/01/21 19:47:49 by omotyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

int		validate_aff(int *arr)
{
	int	res;

	res = 0;
	if (arr[0] == T_REG)
		res = 1;
	type_to_size(arr, 4);
	return (res);
}

void	aff(t_process *process)
{
	unsigned char	coding_byte;
	int				arg_type[3];
	int				reg;

	coding_byte = g_env->global_field[process->counter + 1];
	get_arg_types(arg_type, coding_byte);
	if (!validate_aff(arg_type))
	{
		process->counter += 2;
	}
	else
	{
		reg = g_env->global_field[process->counter + 2];
		if (g_env->vis == 0)
			ft_printf("Aff: %c\n", (char)(process->registers[reg] % 256));
		process->counter += 3;
	}
}
