#include "../includes/op.h"
void st(t_process *process)
{
	int coding_byte;
	unsigned int value;
	int registry;
	int address;

	coding_byte = g_env->global_field[process->counter + 1];
	registry = g_env->global_field[process->counter + T_REG + 1];
	value = process->registers[registry];


	if(coding_byte == 112) // regitry + indirect params
	{
		address = bytes_to_int(&g_env->global_field[process->counter + T_REG + 2], IND_SIZE);
		address = process->counter + (address % IDX_MOD);
		ft_memcpy(&g_env->global_field[address], &value, DIR_SIZE);
		register_color_changes(address, 4, process->color);
		rewrite_memory(g_env->global_field);
		process->counter += 2 + T_REG + IND_SIZE;
	}else if (coding_byte == 80)
	{
		address = bytes_to_int(&g_env->global_field[process->counter + T_REG + 2], T_REG);
		process->registers[address] = value;
		process->counter += 2 + T_REG + T_REG;
	}
}