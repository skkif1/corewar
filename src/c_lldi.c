	//
// Created by Vitaliy Rudakov on 11/18/17.
//

#include "../includes/op.h"

static unsigned int get_first(int *param, t_process *process)
{
	unsigned int value;

	if(param[0] == T_REG)
	{
		value = g_env->global_field[process->counter + 2];
		value = process->registers[value];
	} else if(param[0] == T_IND)
	{
		value = bytes_to_int(process->counter + 2, param[0]);
		value = bytes_to_int(value, 4);
	} else
		value = bytes_to_int(process->counter + 2, param[0]);
	return value;
}

static unsigned int get_second(int *param, t_process *process)
{
	unsigned int value;

	int jump = 0;


		if(param[0] == T_IND)
			jump  = IND_SIZE;
		if(param[0] == T_REG)
			jump = 1;
		if(param[0] == T_DIR)
			jump = DIR_SIZE;

	if(param[1] == T_REG)
	{
		value = bytes_to_int(process->counter + 2 + jump, 2);
		value = process->registers[value];
	}
	if(param[1] == T_DIR)
	{
		value = bytes_to_int(process->counter + 2 + jump, 2);
	}
	return value;
}

int validate_lldi(int *mass, t_process *process)
{
	int i;

	i = 0;
	if((mass[0] == T_REG || mass[0] == T_DIR || mass[0] == T_IND) &&
	   (mass[1] == T_REG || mass[1] == T_DIR) && (mass[2] == T_REG))
		i = 1;

	if(!i)
	{
		type_to_size(mass, 2);
		invalid_coding_byte(mass, process, 3);
	}
	return i;
}


void lldi(t_process *process)
{
	unsigned int coding_byte;
	unsigned int first;
	unsigned int second;
	unsigned int value;

	int params[3];

	coding_byte = g_env->global_field[process->counter + 1];
	get_arg_types(params, coding_byte);
	if(!validate_lldi(params, process))
		return;
	first = get_first(params, process);
	second = get_second(params, process);
	type_to_size(params, 2);
	coding_byte = g_env->global_field[process->counter + 2 + params[0] + params[1]];
	if(validate_reqistry(coding_byte))
	{
		value = bytes_to_int(first + second + process->counter, REG_SIZE);
		if(coding_byte != 1)
            process->registers[coding_byte] = value;
		if(value == 0)
			process->carry = 1;
		else
			process->carry = 0;
	}
	process->counter += params[0] + params[1] + params[2] + 2;
}