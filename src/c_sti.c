#include "../includes/op.h"


int validate_sti(int *mass, t_process *process)
{
	int i;

	i = 0;
	if((mass[1] == T_REG || mass[1] == T_DIR || mass[1] == T_IND) &&
	   (mass[2] == T_REG || mass[2] == T_DIR ) && (mass[0] == T_REG))
		i = 1;
	if(!i)
	{
		type_to_size(mass, 2);
		invalid_coding_byte(mass, process);
	}
	return i;
}


unsigned int get_second_st(const int *params, t_process *process)
{
	unsigned int res;

	res = bytes_to_int(process->counter + 3 + params[1], 2);

	if(params[2] == 1)
	{
		res = g_env->global_field[process->counter + 3 + params[1]];
		res = process->registers[res];
	}

	return res;
}


unsigned int get_first_st(const int *params, t_process *process) {
	unsigned int res;


	res = bytes_to_int(process->counter + 3, 2);
	if (params[1] == T_IND)
		res = bytes_to_int(res + 2, 2);

	if (params[1] == T_REG) {
		res = g_env->global_field[process->counter + 3];
		res = process->registers[res];
	}
	return res;
}


void sti(t_process *process)
{
	int coding_byte;
	unsigned int value;
	unsigned int first;
	unsigned int second;
	int params[3];

	coding_byte = g_env->global_field[process->counter + 1];
	get_arg_types(params, coding_byte);
	if(!validate_sti(params, process))
		return;

    first = get_first_st(params, process);
    type_to_size(params, 2);
    second = get_second_st(params, process);
	value = g_env->global_field[process->counter + 2];
	if(validate_reqistry(value))
	{
		value = process->registers[value];
		bytes_to_memory(first + second, &value, 4, process->color);
	}
	process->counter += params[0] + params[1] + params[2] + 2;
}
