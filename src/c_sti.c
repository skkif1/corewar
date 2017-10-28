#include "../includes/op.h"

void sti(t_process *process)
{
	int coding_byte;
	unsigned int value;
	int registry;
	int address;

	address = 0;
	coding_byte = g_env->global_field[process->counter + 1];
	registry = g_env->global_field[process->counter + T_REG + 1];
	value = process->registers[registry];

	unsigned int temp = process->counter +  T_REG + 2;
	if (coding_byte == 104)
		address = bytes_to_int(temp, 2) + bytes_to_int(temp + 2, 2) + process->counter;

	// no implementation of other cding_byte

	bytes_to_memory(address, &value, 4);
	register_color_changes(address, 4, process->color);
	rewrite_memory(g_env->global_field);
	process->counter += 1 + T_REG + DIR_SIZE;
}
