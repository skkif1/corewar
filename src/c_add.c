#include"../includes/op.h"


int validate_add(int *mass, t_process *process)
{
	int i;

	i = 0;

	if(mass[0] == T_REG && mass[1] == T_REG && mass[2] == T_REG)
		i = 1;
	type_to_size(mass);
	if(!i)
		invalid_coding_byte(mass, process);
	return 1;
}


void add(t_process *process)
{
	int coding_byte;
	int r1;
	int r2;
	int r3;
	int arg_type[3];


	coding_byte = g_env->global_field[process->counter + 1];
	get_arg_types(arg_type, coding_byte);
	if(!validate_add(arg_type, process))
		return;
	r1 = g_env->global_field[process->counter + 2];
	r2 = g_env->global_field[process->counter + 3];
	r3 = g_env->global_field[process->counter + 4];
	if(!((r1 > 0 && r1 <= 16) && (r2 > 0 && r2 <= 16) && (r3 > 0 && r3 <= 16)))
		return;
	process->registers[r3] = process->registers[r1] + process->registers[r2];
	process->counter += 5;
	process->carry = (char) ((process->registers[r3] == 0) ? 1 : 0);
}
