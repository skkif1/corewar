/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudakov <vrudakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 19:53:49 by omotyliu          #+#    #+#             */
/*   Updated: 2018/01/28 21:42:39 by vrudakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

static void	handle_flags(int argc, char **argv)
{
	int	i;

	i = 1;
	g_env->vis = 0;
	g_env->dump = -1;
	while (i < argc)
	{
		if (argv[i][0] != '-')
			return ;
		if (!ft_strcmp(argv[i], "-v"))
			g_env->vis = 1;
		if (!ft_strcmp(argv[i], "-dump"))
		{
			if (g_env->dump > 0 || i + 1 > argc || !ft_isdigitstr(argv[i + 1]))
			{
				ft_putstr("Error, -dump.");
				exit(EXIT_FAILURE);
			}
			g_env->vis = 0;
			g_env->dump = (unsigned int)ft_atoi(argv[i + 1]);
			i++;
		}
		i++;
	}
}

void		get_number(char **argv, int place)
{
	int add;

	if ((add = 0) == 0 && g_env->numbers == NULL)
		g_env->numbers = ft_strdup("|");
	if (place - 2 >= 1)
	{
		if (ft_strcmp(argv[place - 2], "-n") == 0)
		{
			if (ft_isdigitstr(argv[place - 1]))
			{
				g_env->numbers = ft_append(g_env->numbers, argv[place - 1],
					ft_strlen(g_env->numbers), ft_strlen(argv[place - 1]));
				g_env->numbers = ft_append(g_env->numbers, "|",
					ft_strlen(g_env->numbers), 1);
				add = 1;
			}
		}
	}
	if (!add)
	{
		g_env->numbers = ft_append(g_env->numbers,
			"loll", ft_strlen(g_env->numbers), 4);
		g_env->numbers = ft_append(g_env->numbers,
			"|", ft_strlen(g_env->numbers), 1);
	}
}

void		parse_args(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc > 1)
		handle_flags(argc, argv);
	else
		print_exit("usage:\n-v turn on visualization\n-n set the number of next"
	" player (in case of wrong value number will set by VM)\n-dump dump"
	" memory on cycle\n");
	while (i < argc)
	{
		if (ft_strrchr(argv[i], '.') != NULL && ft_strcmp(ft_strrchr(argv[i],
			'.'), ".cor") == 0)
		{
			ft_lstadd_end(&g_env->player_files, ft_lstnew(argv[i],
				ft_strlen(argv[i]) + 1));
			get_number(argv, i);
		}
		i++;
	}
	g_env->player_in_game = lst_size(g_env->player_files);
	if (g_env->player_in_game > MAX_PLAYERS)
		print_exit("number of players in 1 and 4\n");
	else if (g_env->player_in_game == 0)
		print_exit("no valid players found\n");
}
