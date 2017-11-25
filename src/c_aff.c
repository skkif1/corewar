
#include "../includes/op.h"
int 	validate_aff(int *arr)
{
	int res;

	res = 0;
	if(arr[0] == T_REG)
		res = 1;
	type_to_size(arr, 4);
	return res;
}

void	aff(t_process *process)
{
	unsigned char 	coding_byte;
	int 			arg_type[3];
	int 			reg;
	char			str[1];

	coding_byte = g_env->global_field[process->counter + 1];
	get_arg_types(arg_type, coding_byte);

	if(!validate_aff(arg_type))
	{
		process->counter += 3;
	}
	else
	{
		reg = process->counter + 2;
		str[0] = (char)process->registers[reg] / 256;
		add_notification(&str[0], process);


	}

}