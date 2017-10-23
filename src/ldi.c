#include "../includes/op.h"

void type_size(int *mass)
{
	int i;

	i = 0;
	while(i < 3)
	{
		if (mass[i] == T_IND)
			mass[i] = IND_SIZE;
		i++;
	}
}


unsigned int get_first(int param, t_process *process)
{
	unsigned int value;

	if(param == T_REG)
	{
		value = g_env->global_field[process->counter + 2];
		value = process->registers[value];
	} else if(param == T_IND)
	{
		value = bytes_to_int(&g_env->global_field[process->counter + 2], 2);
		value = bytes_to_int(&g_env->global_field[value], 4);
	} else
		value = bytes_to_int(&g_env->global_field[process->counter + 2], 2);
	return value;
}

unsigned int get_second(int param, t_process *process)
{
	unsigned int value;

	if(param == T_REG) {
		value = g_env->global_field[process->counter + 2 + IND_SIZE];
		value = process->registers[value];
	} else
		value = bytes_to_int(&g_env->global_field[process->counter + 2 + IND_SIZE], 2);
	return value;
}


void ldi(t_process *process)
{
	unsigned int coding_byte;
	unsigned int first;
	unsigned int second;
	unsigned int value;

	int params[3];

	coding_byte = g_env->global_field[process->counter + 1];
	get_arg_types(params, coding_byte);
	if(check_param(params))
	{
		//invalid params
	}
	first = get_first(params[0], process);
	second = get_second(params[1], process);
	coding_byte = g_env->global_field[process->counter + 6];
	value = bytes_to_int(&g_env->global_field[first + second], REG_SIZE);
	process->registers[coding_byte] = value;
	process->counter += 7;
}

