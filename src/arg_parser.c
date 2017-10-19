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
    }

    while (i < argc)
	{
		if (ft_strstr(argv[i], ".cor"))
			ft_lstadd(&g_env->player_files, ft_lstnew(argv[i], sizeof(argv[i]) + 1));
		i++;
	}
//	t_list	*plist;
//
//	plist = g_env->player_files;
//	while (plist)
//	{
//
//		plist = plist->next;
//	}
}
