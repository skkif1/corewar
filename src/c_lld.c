/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_lld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omotyliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 19:02:55 by omotyliu          #+#    #+#             */
/*   Updated: 2018/01/21 19:02:59 by omotyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

int		validate_lld(int *mass)
{
	int res;

	res = 0;
	if ((mass[0] == T_IND || mass[0] == T_DIR) && mass[1] == T_REG)
		res = 1;
	type_to_size(mass, 4);
	return (res);
}

void	lld(t_process *process)
{
	int				coding_byte;
	unsigned int	value;
	int				reqistry;
	int				arg_type[3];

	coding_byte = g_env->global_field[process->counter + 1];
	get_arg_types(arg_type, coding_byte);
	if (!validate_lld(arg_type))
		process->counter = (arg_type[0] == 0 && arg_type[1] == 0) ?
	process->counter + 3 : process->counter + arg_type[0] + arg_type[1] + 2;
	else
	{
		value = bytes_to_int(process->counter + T_REG + 1, arg_type[0]);
		if (arg_type[0] == IND_SIZE)
			value = bytes_to_int(value, IND_SIZE);
		reqistry = get_register(process->counter, T_REG + arg_type[0] + T_REG);
		if (validate_reqistry(reqistry))
		{
			process->registers[reqistry] = value;
			process->carry = (value == 0) ? 1 : 0;
		}
		process->counter += T_REG + arg_type[0] + T_REG + 1;
	}
}
