#include "../includes/op.h"
void zjmp(t_process *process)
{
	unsigned int address;

	address = bytes_to_int(&g_env->global_field[process->counter + 1], IND_SIZE);

		if (process->carry == 1)
			process->counter += address;
		else
			process->counter += IND_SIZE + 1;
}