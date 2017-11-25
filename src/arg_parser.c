#include "../includes/op.h"

void parse_args(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc > 1)
	{
		if (!ft_strcmp(argv[1], "-n"))
			g_env->vis = 1;
		else
			g_env->vis = 0;
		if(argv[2] && !ft_strcmp(argv[2], "-dump"))
		{
			g_env->vis = 0;
			g_env->dump = ft_atoi(argv[3]);
		}
    }

    while (i < argc)
	{
		if (ft_strstr(argv[i], ".cor"))
			ft_lstadd_end(&g_env->player_files, ft_lstnew(argv[i], ft_strlen(argv[i]) + 1));
		i++;
	}
	g_env->player_in_game = lst_size(g_env->player_files);
	if(g_env->player_in_game > MAX_PLAYERS)
	{
		ft_printf("number of players in 1 and %d\n",  MAX_PLAYERS);
		exit(EXIT_FAILURE);
	}
}
