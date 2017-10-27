#include "../includes/op.h"

int validate_st(int *mass)
{
	int  i;

	i = 0;

	if(mass[0] == T_REG && (mass[1] == T_IND || mass[1] == T_REG))
		i = 1;
	type_to_size(mass);
	return i;
}

void st(t_process *process)
{
	int coding_byte;
	unsigned int value;
	int registry;
	int address;
	int arg_type[3];

	coding_byte = g_env->global_field[process->counter + 1];
	get_arg_types(arg_type, coding_byte);
	if(!validate_st(arg_type))
		invalid_coding_byte(arg_type, process);
	else
	{
		registry = g_env->global_field[process->counter + T_REG + 1];
		value = big_to_little(process->registers[registry]);

		if(arg_type[1] == IND_SIZE) {
			address = bytes_to_int(&g_env->global_field[process->counter + T_REG + 2], arg_type[1]);
			address = process->counter + (address % IDX_MOD);
			ft_memcpy(&g_env->global_field[address], &value, DIR_SIZE);
		}
		else
		{
			address = g_env->global_field[process->counter + T_REG + 2];
			process->registers[address] = value;
		}
		process->counter += 2 + T_REG + arg_type[1];
		register_color_changes(address, 4, process->color);
		rewrite_memory(g_env->global_field);
	}
}