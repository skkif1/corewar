#include "../includes/op.h"


/*
 * modify carry flag
 * */

void ld(t_process *process)
{
	int coding_byte;
	unsigned int value;
	int reqistry;

	coding_byte = g_env->global_field[process->counter + 1];

	if (coding_byte == 144)
	{
		value = bytes_to_int(&g_env->global_field[process->counter + T_REG + 1], DIR_SIZE);
		reqistry = g_env->global_field[process->counter + T_REG + DIR_SIZE + T_REG];
		process->counter += T_REG + DIR_SIZE + T_REG + 1;
	}if(coding_byte == 208)
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