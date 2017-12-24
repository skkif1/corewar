//
// Created by Vitaliy Rudakov on 11/18/17.
//

#include "../includes/op.h"

int validate_lld(int *mass)
{
	int res;

	res = 0;

	if((mass[0] == T_IND || mass[0] == T_DIR) && mass[1] == T_REG)
		res = 1;
	type_to_size(mass, 4);
	return res;
}

void lld(t_process *process)
{
	int coding_byte;
	unsigned int value;
	int reqistry;
	int arg_type[3];

	coding_byte = g_env->global_field[process->counter + 1];
	get_arg_types(arg_type, coding_byte);

	if(!validate_lld(arg_type))
	{
		if(arg_type[0] == 0 && arg_type[1] == 0)
			process->counter += 3;
		else
			process->counter += arg_type[0] + arg_type[1] + 2;
	} else {
		value = bytes_to_int(process->counter + T_REG + 1, arg_type[0]);
		if(arg_type[0] == IND_SIZE)
			value = bytes_to_int(value, IND_SIZE);
		reqistry = g_env->global_field[process->counter + T_REG + arg_type[0] + T_REG];
		if(validate_reqistry(reqistry))
		{
			if(process->registers[reqistry] != 1)
                process->registers[reqistry] = value;

            if(value == 0)
				process->carry = 1;
			else
				process->carry = 0;
		}
		process->counter += T_REG + arg_type[0] + T_REG + 1;
	}
}