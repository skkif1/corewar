#include "../includes/op.h"

int get_param_type(char first, char second)
{
	if(first + second == 2)
		return T_IND;
	else if(first == 0 && second == 1)
		return T_REG;
	else if(first == 1 && second == 0)
		return T_DIR;
	return 0;
}


void get_arg_types(int *mass, char coding_byte)
{
	int i;
	int j;
	char first;
	char second;

	i = 7;
	j = 0;
	while (i > 1)
	{
		first = (char) ((coding_byte >> i--) & 0x01);
		second = (char) ((coding_byte >> i--) & 0x01);
		mass[j++] = get_param_type(first, second);
	}
}

int check_param(int *mass)
{
	int i;

	i = 0;
	while (i < 3)
	{
		if (mass[i++] == -1)
			return 0;
	}
	return 1;
}


