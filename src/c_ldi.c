#include "../includes/op.h"

unsigned int get_first(int *param, t_process *process)
{
	unsigned int value;

	if(param[0] == T_REG)
	{
		value = g_env->global_field[process->counter + 2];
		value = process->registers[value];
	} else if(param[0] == IND_SIZE)
	{
		value = bytes_to_int(process->counter + 2, param[0]);
		value = bytes_to_int(value, 4);
	} else
		value = bytes_to_int(process->counter + 2, param[0]);
	return value;
}

unsigned int get_second(int *param, t_process *process)
{
	unsigned int value;

	if(param[1] == T_REG) {
		value = g_env->global_field[process->counter + 2 + IND_SIZE];
		value = process->registers[value];
	} else
		value = bytes_to_int(process->counter + 2 + IND_SIZE, 2);
	return value;
}

int validate_ldi(int *mass, t_process *process)
{
	int i;

	i = 0;
	if((mass[0] == T_REG || mass[0] == T_DIR || mass[0] == T_IND) &&
	   (mass[1] == T_REG || mass[1] == T_DIR || mass[1] == T_IND) && (mass[2] == T_REG))
		i = 1;
	type_to_size(mass, 2);
	if(!i)
		invalid_coding_byte(mass, process);
	return i;
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
	if(!validate_ldi(params, process))
		return;
	first = get_first(params, process);
	second = get_second(params, process);
	coding_byte = g_env->global_field[process->counter + 2 + params[0] + params[1]];
	value = bytes_to_int(first + second, REG_SIZE);
	process->registers[coding_byte] = value;
	process->counter += params[0] + params[1] + params[2] + 2;
}