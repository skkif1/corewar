#include "../includes/op.h"
void zjmp(t_process *process)
{
	unsigned int address;

	address = (short)bytes_to_int(process->counter + 1, IND_SIZE);

		if (process->carry == 1)
			process->counter += (address);
		else
			process->counter += IND_SIZE + 1;
}