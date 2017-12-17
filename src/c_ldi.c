#include "../includes/op.h"

unsigned int get_first(int *param, t_process *process)
{
	unsigned int value;

    value = bytes_to_int(process->counter + 2, 2);
  //  value = bytes_to_int(value, 4);

    if(param[0] == 1)
    {
        value = g_env->global_field[process->counter + 2];
        value = process->registers[value];
    }
    return value;

}

unsigned int get_second(int *param, t_process *process)
{
	unsigned int value;

	value = bytes_to_int(process->counter + 2 + param[0], 2);

	if(param[1] == 1) {
		value = g_env->global_field[process->counter + 2 + param[0]];
		value = process->registers[value];
	}

	return value;
}

int validate_ldi(int *mass, t_process *process)
{
	int i;

	i = 0;
	if((mass[0] == T_REG || mass[0] == T_DIR || mass[0] == T_IND) &&
	   (mass[1] == T_REG || mass[1] == T_DIR) && (mass[2] == T_REG))
		i = 1;

	if(!i)
	{
		type_to_size(mass, 2);
		invalid_coding_byte(mass, process);
	}
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
	type_to_size(params, 2);
	first = get_first(params, process);
	second = get_second(params, process);

	coding_byte = g_env->global_field[process->counter + 2 + params[0] + params[1]];
	if(validate_reqistry(coding_byte))
	{
		value = bytes_to_int(process->counter + first + second, REG_SIZE);
		process->registers[coding_byte] = big_to_little(value);
	}
	process->counter += params[0] + params[1] + params[2] + 2;
}