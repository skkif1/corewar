/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudakov <vrudakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 17:34:06 by omotyliu          #+#    #+#             */
/*   Updated: 2018/01/28 21:28:03 by vrudakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

void		reverse_bytes(unsigned int *bytes, int size)
{
	unsigned char	*save;
	int				i;
	unsigned int	res;

	res = 0;
	save = (unsigned char *)malloc(sizeof(unsigned char) * size);
	i = -1;
	while (++i < size)
	{
		save[i] = (unsigned char)((*bytes) >> (i * 8));
		res += save[i] << (8 * (size - 1 - i));
	}
	free(save);
	*bytes = res;
}

void		fill_player(t_header *head, unsigned char *prog, t_list **players)
{
	t_player				*player;
	static int				color = 3;
	static unsigned int		player_num = 4294967295;

	player = malloc(sizeof(t_player));
	player->code = (unsigned char*)
			malloc(sizeof(unsigned char) * head->prog_size);
	player->code_len = head->prog_size;
	if (head->prog_size > CHAMP_MAX_SIZE)
	{
		ft_printf("Error: File 42.cor has large a code (%d bytes > %d bytes)\n",
			head->prog_size, CHAMP_MAX_SIZE);
		exit(EXIT_FAILURE);
	}
	player->real_num = player_num--;
	player->color = color;
	ft_memcpy(player->player_name, head->prog_name, 128);
	ft_memcpy(player->code, prog, head->prog_size);
	player->color = color;
	color += 2;
	ft_lstadd(players, ft_lstnew(player, sizeof(t_player)));
	free(prog);
	free(head);
	free(player);
}

void		register_players_auto(t_list **players)
{
	t_header		*head;
	t_list			*fd_l;
	int				fd;
	unsigned char	*prog;

	fd_l = g_env->player_files;
	while (fd_l)
	{
		head = (t_header*)malloc(sizeof(t_header));
		if ((fd = open(fd_l->content, O_RDONLY)) < 0)
			exit(EXIT_FAILURE);
		if (read(fd, head, sizeof(t_header)) != sizeof(t_header))
			exit(666);
		reverse_bytes(&head->prog_size, 4);
		reverse_bytes(&head->magic, 4);
		if (head->magic != 15369203)
			print_exit("Wrong magic!!!");
		prog = (unsigned char*)malloc(sizeof(unsigned char) * head->prog_size);
		if (read(fd, prog, head->prog_size + 1) != head->prog_size)
			print_exit("Read prog not valid");
		fill_player(head, prog, players);
		close(fd);
		fd_l = fd_l->next;
	}
	add_all_players(*players);
}
