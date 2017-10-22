#include "../includes/op.h"

int get_param_type(char first, char second)
{
	if(first + second == 2)
		return T_REG;
	else if(first == 0 && second == 1)
		return T_IND;
	else if(first == 1 && second == 0)
		return T_DIR;
	return 0;
}


int get_value_by_coding_byte(char coding_byte, char parm_number, const unsigned char *memory, unsigned int *value)
{

	char i;
	char first;
	char second;


	i = 7;
	if(parm_number == 2)
		i = 5;
	if (parm_number == 3)
		i = 3;
	first = (char) ((coding_byte >> i--) & 0x01);
	second = (char) ((coding_byte >> i) & 0x01);
	i  = (char) get_param_type(first, second);

	if (i == T_REG)
		*value = bytes_to_int(memory, 1);
	if (i == T_DIR)
		*value = bytes_to_int(memory, 4);
	if (i == T_IND)
	{
		*value = bytes_to_int(memory, 2);
		*value = bytes_to_int(&g_env->global_field[*value], DIR_SIZE);
	}
	return i;
}

