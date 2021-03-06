/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_add.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omotyliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 19:46:37 by omotyliu          #+#    #+#             */
/*   Updated: 2018/01/21 19:46:40 by omotyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

int		validate_add(int *mass, t_process *process)
{
	int	i;

	i = 0;
	if (mass[0] == T_REG && mass[1] == T_REG && mass[2] == T_REG)
		i = 1;
	type_to_size(mass, 4);
	if (!i)
	{
		invalid_coding_byte(mass, process, 3);
		return (0);
	}
	return (1);
}

void	add(t_process *process)
{
	int	coding_byte;
	int	r1;
	int	r2;
	int	r3;
	int	arg_type[3];

	coding_byte = g_env->global_field[process->counter + 1];
	get_arg_types(arg_type, coding_byte);
	if (!validate_add(arg_type, process))
		return ;
	r1 = g_env->global_field[process->counter + 2];
	r2 = g_env->global_field[process->counter + 3];
	r3 = g_env->global_field[process->counter + 4];
	if ((validate_reqistry(r1) && validate_reqistry(r2) &&
		validate_reqistry(r3)))
	{
		if (get_opcode_by_name(process->current_op) == 3)
			arg_type[0] = process->registers[r1] + process->registers[r2];
		else
			arg_type[0] = process->registers[r1] - process->registers[r2];
		process->registers[r3] = arg_type[0];
	}
	process->counter += 5;
	process->carry = (arg_type[0] == 0) ? 1 : 0;
}
