#include "../includes/op.h"

t_env *g_env;

//static int	ap_basecheck(char c, int base)
//{
//	if (base <= 10)
//		return (c >= '0' && c <= ('9' + base - 10));
//	return ((c >= '0' && c <= '9') ||
//			(c >= 'A' && c <= ('A' + base - 10)) ||
//			(c >= 'a' && c <= ('a' + base - 10)));
//}
//
//int			ft_atoi_base(const char *str, int str_base)
//{
//	int i;
//	int	sign;
//	int atoi;
//
//	i = 0;
//	atoi = 0;
//	if (str_base < 2 || str_base > 16)
//		return (0);
//	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
//		i++;
//	sign = (str[i] == '-') ? -1 : 1;
//	if (str[i] == '+' || str[i] == '-')
//		i++;
//	while (ap_basecheck(str[i], str_base))
//	{
//		if (str[i] - 'a' >= 0)
//			atoi = atoi * str_base + (str[i] - 'a' + 10);
//		else if (str[i] - 'A' >= 0)
//			atoi = atoi * str_base + (str[i] - 'A' + 10);
//		else
//			atoi = atoi * str_base + (str[i] - '0');
//		i++;
//	}
//	return (sign * atoi);
//}
//
//void	error_exit(char *str)
//{
//
//}

//void    register_players_auto(t_list *players)
//{
//    char    file[6000];
//	t_list  *fd_l;
//	int 	fd,size;
//
//	fd_l = g_env->player_files;
//	while (fd_l)
//	{
//		ft_putstr(fd_l->content);
//		ft_putstr("\n");
//		if ((fd = open(fd_l->content, O_RDONLY)) < 0)
//			exit(EXIT_FAILURE);
//		while (read(fd, file, 1 ))
//		{
//			printf("%x\n", ft_atoi_base(&file[0], 16));
//		}
//		size = lseek(fd, 0, SEEK_END);
//		printf("-%d\n",size);
//		fd_l = fd_l->next;
//	}
//	exit(111);
//}

void register_players(t_list *players)
{
    t_player *player;
    t_player *player2;

    //static unsigned int name = 4294967295;
    player = malloc(sizeof(t_player));
    player2 = malloc(sizeof(t_player));


    ft_memcpy(player->player_name, "zork", ft_strlen("zork"));
    player->player_number = 4294967295;
    player->code_len = 3;
    player->color = 3;

	player->code = malloc(sizeof(char) * 20);
	player->code[0] = 12;
	player->code[1] = 0;
	player->code[2] = 100;
	player->code[3] = '\0';


    ft_lstadd(&players, ft_lstnew(player, sizeof(t_player)));

    ft_memcpy(player2->player_name, "zork2", ft_strlen("zork2"));
    player2->player_number = 4294967294;
    player2->code_len = 5;
    player2->color = 5;


    player2->code = malloc(sizeof(char) * 5);
    player2->code[0] = 1;
    player2->code[1] = 255;
    player2->code[2] = 255;
    player2->code[3] = 255;
    player2->code[4] = 253;
    player2->code[5] = '\0';

    ft_lstadd(&players, ft_lstnew(player2, sizeof(t_player)));

    g_env->player_in_game = 2;

    g_env->players = players;

    while (players)
    {
        add_new_player(players->content);
        players = players->next;
    }


}

void add_new_player(t_player *player)
{
    int start;
    int j;
    int end;

    j = 0;
    start = (unsigned int) (MEM_SIZE / g_env->player_in_game * (4294967295 - player->player_number));
    end = start + player->code_len;
	player->live_in_period = 0;
    add_new_process(start, player);

    while (start < end)
    {
        g_env->global_field[start++] = player->code[j++];
    }
    register_color_changes(start - player->code_len, player->code_len, player->color);
    rewrite_memory(g_env->global_field);
}


void init_env()
{
    g_env = malloc(sizeof(t_env));
    ft_memset(g_env->global_field, 0, MEM_SIZE);
    g_env->cycle_to_die = CYCLE_TO_DIE;
    g_env->cycle = 0;
    g_env->vis_delay = 1000;
    g_env->vis_run = 0;
    g_env->player_files = NULL;
}
