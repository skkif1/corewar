/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapteli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 13:32:08 by skapteli          #+#    #+#             */
/*   Updated: 2017/03/25 13:32:11 by skapteli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_buffer	*new_b(int init)
{
	t_buffer	*new;

	new = malloc(sizeof(t_buffer));
	new->d = init;
	new->next = NULL;
	new->start = NULL;
	new->content = NULL;
	return (new);
}

static int		write_to_line(char **line, t_buffer *now)
{
	char	*new_l;
	size_t	i;

	if (!(new_l = malloc(ft_strlen(*line) + ft_strlen(now->content) + 1)))
		return (-1);
	i = -1;
	while ((*line)[++i] != '\0')
		new_l[i] = (*line)[i];
	while (*(now->content) && *(now->content) != '\n')
		new_l[i++] = *((now->content)++);
	new_l[i] = '\0';
	free(*line);
	*line = new_l;
	if (*(now->content))
	{
		(now->content)++;
		return (1);
	}
	return (0);
}

static int		read_start(t_buffer *now, char **line, int fd)
{
	int readed;
	int w;

	if (!(now->content = malloc(BUFF_SIZE + 1)))
		return (-1);
	now->start = now->content;
	while ((readed = read(fd, now->content, BUFF_SIZE)))
	{
		if (readed == -1)
			return (-1);
		(now->content)[readed] = '\0';
		w = write_to_line(line, now);
		if (w == 1)
			return (1);
		if (w == -1)
			return (-1);
		now->content = now->start;
	}
	free(now->start);
	now->content = NULL;
	now->start = NULL;
	if (**line)
		return (1);
	return (0);
}

static int		read_further(t_buffer *now, char **line, int fd)
{
	if (write_to_line(line, now))
		return (1);
	free(now->start);
	now->content = NULL;
	now->start = NULL;
	return (read_start(now, line, fd));
}

int				get_next_line(const int fd, char **line)
{
	static t_buffer		*buf;
	t_buffer			*now;

	if (!line || !(*line = ft_strdup("")))
		return (-1);
	if (!buf)
		buf = new_b(fd);
	now = buf;
	while (now->next && now->d != fd)
		now = now->next;
	if (now->d != fd)
	{
		now->next = new_b(fd);
		now = now->next;
	}
	if (now->start)
		return (read_further(now, line, fd));
	return (read_start(now, line, fd));
}
