/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapteli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 13:32:15 by skapteli          #+#    #+#             */
/*   Updated: 2017/03/25 13:32:17 by skapteli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <libft.h>
# define BUFF_SIZE 10000

int				get_next_line(int fd, char **line);

typedef struct	s_buffer
{
	int					d;
	char				*content;
	char				*start;
	struct s_buffer		*next;
}				t_buffer;

#endif
