#include "../includes/op.h"


/*
 * modify carry flag
 * */

int validate_args(int *mass)
{
	if((mass[0] == T_IND || mass[0] == T_DIR) && mass[1] == T_REG)
		return 1;
	type_to_size(mass);
	return 0;
}

void ld(t_process *process)
{
	char coding_byte;
	unsigned int value;
	int reqistry;
	int arg_type[3];
	value = 0;
	reqistry = 1;

	coding_byte = g_env->global_field[process->counter + 1];
	get_arg_types(arg_type, coding_byte);
	if(!validate_args(arg_type))
	{
		process->counter += arg_type[0] + arg_type[1];
		return;

		/*
		 * when coding byte is broken we shoul jump size of coding byte params
		 *
		 * */
	}

	if ((int)coding_byte == 144)
	{
		value = bytes_to_int(&g_env->global_field[process->counter + T_REG + 1], DIR_SIZE);
		reqistry = g_env->global_field[process->counter + T_REG + DIR_SIZE + T_REG];
		process->counter += T_REG + DIR_SIZE + T_REG + 1;
	}if((int)coding_byte == 208)
	{
		value = bytes_to_int(&g_env->global_field[process->counter + T_REG + 1], IND_SIZE);
		ft_memcpy(&value, &g_env->global_field[process->counter + value], IND_SIZE);
		reqistry = g_env->global_field[process->counter + T_REG + IND_SIZE + T_REG];
		process->counter += T_REG + IND_SIZE + T_REG + 1;
	}

	process->registers[reqistry] = value;
	if(value == 0)
		process->carry = 1;
}