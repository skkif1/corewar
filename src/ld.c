#include "../includes/op.h"

void ld(t_process *process)
{
	int coding_byte;
	unsigned int value;
	int reqistry;

	coding_byte = g_env->global_field[process->counter + 1];
	if (coding_byte == 144)
	{
		value = bytes_to_int(&g_env->global_field[process->counter + T_REG + 1], 4);
		reqistry = g_env->global_field[process->counter + T_REG + DIR_SIZE + T_REG];
		process->registers[reqistry] = value;
		process->counter += T_REG + DIR_SIZE + T_REG + 1;
	} else
	{
		//using sti
	}
}