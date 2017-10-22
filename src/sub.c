#include "../includes/op.h"


/*
 * modify carry flag
 * */

void sub(t_process *process)
{
	int coding_byte;
	int r1;
	int r2;
	int r3;

	coding_byte = g_env->global_field[process->counter + 1];
	if (coding_byte == 84)
	{
		r1 = g_env->global_field[process->counter + 2];
		r2 = g_env->global_field[process->counter + 3];
		r3 = g_env->global_field[process->counter + 4];
		process->registers[r3] = process->registers[r1] - process->registers[r2];
		process->counter += 5;
	}
}
