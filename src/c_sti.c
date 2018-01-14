#include "../includes/op.h"

int valid_registry[2] = {1,1};

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
		invalid_coding_byte(mass, process, 3);
	}
	return i;
}


int get_second_st(const int *params, t_process *process)
{
    int res;

	res = (short)bytes_to_int(process->counter + 3 + params[1], 2);

	if(params[2] == 1)
	{
		res = g_env->global_field[process->counter + 3 + params[1]];
        if(validate_reqistry(res))
        {
            res = process->registers[res];
        } else
        {
            valid_registry[1] = 0;
        }

	}

	return res;
}


int get_first_st(const int *params, t_process *process) {

    int res;

	res = (short)bytes_to_int(process->counter + 3, 2);
	if (params[1] == T_IND)
		res = bytes_to_int(res + 2, 2);
//
	if (params[1] == T_REG)
    {
		res = g_env->global_field[process->counter + 3];
		if(validate_reqistry(res))
        {
            res = process->registers[res];
        } else
        {
            valid_registry[0] = 0;
        }
        valid_registry[0] = 2;
	}
	return res;
}


void sti(t_process *process) {
    int coding_byte;
    unsigned int value;
    int first;
    int second;
    int params[3];

    coding_byte = g_env->global_field[process->counter + 1];
    get_arg_types(params, coding_byte);
    if (!validate_sti(params, process))
        return;
    first = get_first_st(params, process);
    type_to_size(params, 2);
    second = get_second_st(params, process);
    value = g_env->global_field[process->counter + 2];
    if (validate_reqistry(value) && valid_registry[0] && valid_registry[1])
    {
        value = big_to_little(process->registers[value]);
        first = process->counter + (first + second) % IDX_MOD;
        if(first < 0)
        {
            first = MEM_SIZE + first;
        }
        bytes_to_memory(first % MEM_SIZE, &value, 4, process->color);
    }
    process->counter += params[0] + params[1] + params[2] + 2;
}