/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapteli <skapteli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 16:48:10 by skapteli          #+#    #+#             */
/*   Updated: 2017/12/08 14:49:41 by skapteli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			header_validation(void)
{
	if (COMMENT_CHAR1 != '#' || LABEL_CHAR != ':' || DIRECT_CHAR != '%' ||
			SEPARATOR_CHAR != ',' || CMD_CHAR_D != '.' || CMD_CHAR_Q != '"' ||
			REG_NUMBER != 16 || CYCLE_TO_DIE != 1536 || CYCLE_DELTA != 50 ||
			NBR_LIVE != 21 || MAX_CHECKS != 10 || T_REG != 1 || T_DIR != 2 ||
			T_IND != 4 || T_LAB != 8 || COMMENT_CHAR2 != ';' ||
			!ft_strequ(LABEL_CHARS, "abcdefghijklmnopqrstuvwxyz_0123456789"))
		error_(11);
	if (COMMENT_CHAR1 == '\n' || LABEL_CHAR == '\n' || DIRECT_CHAR == '\n' ||
		SEPARATOR_CHAR == '\n' || COMMENT_CHAR1 == ' ' || LABEL_CHAR == ' ' ||
		DIRECT_CHAR == ' ' || SEPARATOR_CHAR == ' ' || CMD_CHAR_D == '"' ||
			COMMENT_CHAR2 == '\n' || COMMENT_CHAR2 == ' ')
		error_(11);
	if (ft_strchr(LABEL_CHARS, LABEL_CHAR) ||
			ft_strchr(LABEL_CHARS, SEPARATOR_CHAR) ||
			ft_strchr(LABEL_CHARS, COMMENT_CHAR1) ||
			ft_strchr(LABEL_CHARS, COMMENT_CHAR2) ||
			ft_strchr(LABEL_CHARS, DIRECT_CHAR) ||
			ft_strchr(LABEL_CHARS, CMD_CHAR_D))
		error_(11);
	((PROG_NAME_LENGTH < 1) || (PROG_NAME_LENGTH > 128) ? error_(12) : 0);
	((COMMENT_LENGTH < 1) || (COMMENT_LENGTH > 2048) ? error_(13) : 0);
	(COREWAR_EXEC_MAGIC > 0xffffffff) ? error_(14) : 0;
}

void			valid_fname_and_header(t_st *st, char **argv)
{
	int			i;
	int			length;
	int			len;
	int			l;

	i = -1;
	length = 0;
	len = (int)ft_strlen(argv[1]);
	if (argv[1][len - 1] != 's' || argv[1][len - 2] != '.')
		error_(1);
	if (len < 3)
		error_(2);
	l = len;
	while ((l > 0) && argv[1][l - 1] != '/')
	{
		l--;
		length++;
	}
	st->name_cor = ft_strnew((size_t)length - 1 + 3 + 1);
	while (++i < length - 1)
		st->name_cor[i] = argv[1][len - length + i];
	st->name_cor[i] = 'c';
	st->name_cor[i + 1] = 'o';
	st->name_cor[i + 2] = 'r';
	header_validation();
}

int				main(int argc, char **argv)
{
	t_st		*st;

	if (argc != 2)
		error_(0);
	st = initial_st();
	valid_fname_and_header(st, argv);
	get_info_from_file(st, argv[1]);
	lexical_valid_end_extract_data(st);
	compare_extracted_args_with_op(st);
	count_bytes_of_each_lst(st);
	count_label_bytes(st);
	write_data_in_file(st);
	free_st(st);
	return (0);
}
