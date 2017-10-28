#include "../includes/op.h"

unsigned int normalize_cursor(unsigned int *start)
{
	*start = (*start + 1 == MEM_SIZE)? 0 : *start + 1;
	return *start;
}

unsigned int bytes_to_int(unsigned int start, int size)
{
	unsigned int l = 0;

	start = (start >= MEM_SIZE) ? start % MEM_SIZE : start;
	if (size == 4)
	{
		l = (unsigned char)(g_env->global_field[start]) << 24 |
			(unsigned char)(g_env->global_field[normalize_cursor(&start)]) << 16 |
			(unsigned char)(g_env->global_field[normalize_cursor(&start)]) << 8 |
			(unsigned char)(g_env->global_field[normalize_cursor(&start)]);
	} else
	{

		l = (unsigned char)(g_env->global_field[start]) << 8 |
			(unsigned char)(g_env->global_field[normalize_cursor(&start)]);
	}
	return l;
}

void bytes_to_memory(unsigned int start, const void *value, size_t len)
{

	unsigned char *val;

	val = (unsigned char *) value;
	start = (start >= MEM_SIZE) ? start % MEM_SIZE : start;

	g_env->global_field[start] = *val++;
	len--;
	while (len--)
	{
		g_env->global_field[normalize_cursor(&start)] = *val++;
	}
}