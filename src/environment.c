#include "../includes/op.h"

void		reverse_bytes(unsigned int *bytes, int size)
{
	unsigned char	*save;
	int 			i;
	unsigned int	res;

	res = 0;
	save = (unsigned char *)malloc(sizeof(unsigned char) * size);
	i = -1;
	while (++i < size)
	{
		save[i] = (unsigned char) ((*bytes) >> (i * 8));
		res+= save[i] << (8 * (size - 1 - i));
	}
	*bytes = res;

}

t_player*	fill_player(header_t *head, unsigned char *prog)
{
	t_player	*player;
	static unsigned int player_num = 4294967295;
	static int color = 3;

	player = malloc(sizeof(t_player));
	player->code = (unsigned char*)malloc(sizeof(unsigned char) * head->prog_size);
	player->code_len = head->prog_size;
	player->player_number = player_num;
	player->color = color;
	ft_memcpy(player->player_name, head->prog_name, 128);
	ft_memcpy(player->code, prog, head->prog_size);

	player_num--;
	color += 2;
	return (player);
}

void    register_players_auto(t_list *players)
{
    header_t		*head;
	t_list          *fd_l;
	int 			fd;
	unsigned char	*prog;
	int 			i;


	i = 0;
	head = (header_t*)malloc(sizeof(header_t)); //2192
	fd_l = g_env->player_files;

	while (fd_l)
	{
		if ((fd = open(fd_l->content, O_RDONLY)) < 0)
			exit(EXIT_FAILURE);
		if(read(fd, head, sizeof(header_t)) != sizeof(header_t))
			exit(666);
		reverse_bytes(&head->prog_size, 4);
		reverse_bytes(&head->magic, 4);
		if (head->magic != 15369203) // ea83f3
		{
			ft_putstr("Wrong magic!!!");
			exit(EXIT_FAILURE);
		}
		prog = (unsigned char*)malloc(sizeof(unsigned char) * head->prog_size);
		if (read(fd,prog, head->prog_size + 1) != head->prog_size)
		{
			ft_putstr("Read prog not valid");
			exit(EXIT_FAILURE);
		}
		ft_lstadd(&players, ft_lstnew(fill_player(head, prog), sizeof(t_player)));
		free(prog);
		close(fd);
		fd_l = fd_l->next;
	}
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
