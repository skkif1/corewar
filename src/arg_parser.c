#include "../includes/op.h"

static void handle_flags(int argc,char** argv)
{
	int i;

	i = 1;
	g_env->vis = 0;
	g_env->dump = -1;
	while (i < argc)
	{
		if (argv[i][0] != '-')
			return ;
		if (!ft_strcmp(argv[i], "-n"))
			g_env->vis = 1;
		if(!ft_strcmp(argv[i], "-dump"))
		{
			if (g_env->dump != 0 || i + 1 > argc || !ft_isdigitstr(argv[i + 1]))
			{
				ft_putstr("Error, -dump.");
				exit(EXIT_FAILURE);
			}
			g_env->vis = 0;
			g_env->dump = ft_atoi(argv[i + 1]);
			i++;
		}
		i++;
	}
}

void parse_args(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc > 1)
		handle_flags(argc,argv);
	else
	{
		ft_putstr("usage");
		exit(EXIT_FAILURE);
	}
    while (i < argc)
	{
		if (ft_strrchr(argv[i], '.') != NULL && ft_strcmp(ft_strrchr(argv[i], '.'), ".cor") == 0)
			ft_lstadd_end(&g_env->player_files, ft_lstnew(argv[i], ft_strlen(argv[i]) + 1));
		i++;
	}
	g_env->player_in_game = lst_size(g_env->player_files);
	if(g_env->player_in_game > MAX_PLAYERS || g_env->player_in_game == 0)
	{
		ft_printf("number of players in 1 and %d\n",  MAX_PLAYERS);
		exit(EXIT_FAILURE);
	}
}
