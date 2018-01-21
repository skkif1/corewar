/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_ld.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omotyliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 19:23:56 by omotyliu          #+#    #+#             */
/*   Updated: 2018/01/21 19:23:59 by omotyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

int		validate_ld(int *mass)
{
	int	res;

	res = 0;
	if ((mass[0] == T_IND || mass[0] == T_DIR) && mass[1] == T_REG)
		res = 1;
	type_to_size(mass, 4);
	return (res);
}

void	ld(t_process *process)
{
	int				coding_byte;
	unsigned int	value;
	int				reqistry;
	int				arg_type[3];

	coding_byte = g_env->global_field[process->counter + 1];
	get_arg_types(arg_type, coding_byte);
	if (!validate_ld(arg_type))
		process->counter = (arg_type[0] == 0 && arg_type[1] == 0) ?
	process->counter + 2 : process->counter + arg_type[0] + arg_type[1] + 2;
	else
	{
		value = bytes_to_int(process->counter + T_REG + 1, arg_type[0]);
		if (arg_type[0] == IND_SIZE)
			value = bytes_to_int(process->counter + value, DIR_SIZE);
		reqistry = g_env->global_field[process->counter + T_REG +
		arg_type[0] + T_REG];
		if (validate_reqistry(reqistry))
		{
			process->registers[reqistry] = value;
			process->carry = (process->registers[reqistry] == 0) ? 1 : 0;
		}
		process->counter += T_REG + arg_type[0] + T_REG + 1;
	}
}
