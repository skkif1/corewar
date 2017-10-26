#include "../includes/op.h"


unsigned int make_op(t_process *process, unsigned int first, unsigned int second)
{
	unsigned int res;

	if(g_env->global_field[process->counter] == 6)
		res = first & second;
	else if(g_env->global_field[process->counter] == 7)
		res = first | second;
	else
		res = first ^ second;
	return res;
}

void and(t_process *process)
{
	char coding_byte;
	unsigned int first;
	unsigned int second;
	unsigned int regist;
	unsigned int value;
	int params[3];

	coding_byte = g_env->global_field[process->counter + 1];
	get_arg_types(params, coding_byte);
	if (check_param(params))
	{
		///bad params
	}
	type_to_size(params);

	first = bytes_to_int(&g_env->global_field[process->counter + 2], params[0]);
	second = bytes_to_int(&g_env->global_field[process->counter + 2 + params[0]], params[1]);

	if (params[0] == IND_SIZE || params[0] == 1)
		first = (params[0] == IND_SIZE) ? bytes_to_int(&g_env->global_field[first], DIR_SIZE) : process->registers[first];
	if(params[1] == IND_SIZE || params[1] == 1)
		second = (params[0] == IND_SIZE) ? bytes_to_int(&g_env->global_field[second], DIR_SIZE) : process->registers[second];
	regist = g_env->global_field[process->counter + 2 + params[0] + params[1]];
	value = make_op(process, first, second);
	process->registers[regist] = value;
	if (value == 0)
		process->carry = 1;
	process->counter += params[0] + params[1] + params[2] + 2;
}





