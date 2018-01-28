/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omotyliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 19:53:49 by omotyliu          #+#    #+#             */
/*   Updated: 2018/01/21 19:53:52 by omotyliu         ###   ########.fr       */
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
void get_number(char **argv, int place)
{
    int add = 0;

    if(g_env->numbers == NULL)
    {
        g_env->numbers = "|";
    }
    if(place - 2 >= 1)
    {
        if (ft_strcmp(argv[place - 2], "-n") == 0)
        {
                if(ft_isdigitstr(argv[place - 1]))
                {
                    g_env->numbers = ft_strjoin(g_env->numbers, argv[place - 1]);
                    g_env->numbers = ft_strjoin(g_env->numbers, "|");
                    add = 1;
                }
            }
    }
    if(!add)
    {
        g_env->numbers = ft_strjoin(g_env->numbers, "loll");
        g_env->numbers = ft_strjoin(g_env->numbers, "|");
    }
}

void		parse_args(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc > 1)
		handle_flags(argc, argv);
	else
	{
		ft_putstr("usage:\n-v turn on visualization\n-n set the number of next player (in case of wrong value number will set by VM)\n-dump dump memory on cycle\n");
		exit(EXIT_FAILURE);
	}
	while (i < argc)
	{
		if (ft_strrchr(argv[i], '.') != NULL && ft_strcmp(ft_strrchr(argv[i], '.'), ".cor") == 0)
        {
            ft_lstadd_end(&g_env->player_files, ft_lstnew(argv[i], ft_strlen(argv[i]) + 1));
            get_number(argv, i);
        }
		i++;
	}
	g_env->player_in_game = lst_size(g_env->player_files);
	if (g_env->player_in_game > MAX_PLAYERS)
	{
		ft_printf("number of players in 1 and %d\n", MAX_PLAYERS);
		exit(EXIT_FAILURE);
	} else if (g_env->player_in_game == 0)
    {
        ft_printf("no valid players found\n", MAX_PLAYERS);
        exit(EXIT_FAILURE);
    }
}



