#include "../includes/op.h"

void parse_args(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc > 1)
	{
		if (!ft_strcmp(argv[1], "-n"))
			g_env->vis = 1;
		else
			g_env->vis = 0;
    }
    while (i < argc)
	{
		if ()
		i++;
	}
}
