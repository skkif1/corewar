/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_lexical.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapteli <skapteli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 17:37:54 by skapteli          #+#    #+#             */
/*   Updated: 2017/12/16 19:00:43 by obohosla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

size_t			word_len(char *word)
{
	size_t		i;

	i = 0;
	(word[i] == '.' ? i++ : 0);
	while (ft_isalpha(word[i]))
		i++;
	return (i);
}

t_lst			*join_and_save(t_lst *tmp_l, int i, char *dst, int h_len)
{
	int			j;

	((((int)ft_strlen(tmp_l->str) - i) > h_len) ? error_(7) : 0);
	ft_strncpy(dst, &tmp_l->str[i], (size_t)h_len + 1);
	tmp_l = tmp_l->next;
	while (tmp_l && !ft_strchr(tmp_l->str, CMD_CHAR_Q))
	{
		if (((int)ft_strlen(dst) + (int)ft_strlen(tmp_l->str) + 1) > h_len)
			error_line(7, tmp_l->number_str);
		ft_strcat(dst, "\n");
		ft_strcat(dst, tmp_l->str);
		tmp_l = tmp_l->next;
	}
	i = 0;
	(!tmp_l ? error_(10) : 0);
	while (tmp_l->str[i] != CMD_CHAR_Q)
		i++;
	j = skip_white_spaces(&tmp_l->str[i + 1], i + 1);
	((tmp_l->str[j] != '\0') ? error_line(6, tmp_l->number_str) : 0);
	(((int)ft_strlen(dst) + 1 + i) > h_len ?
		error_line(7, tmp_l->number_str) : 0);
	ft_strcat(dst, "\n");
	ft_strncat(dst, tmp_l->str, (size_t)i);
	return (tmp_l->next);
}

t_lst			*save_in_h(t_lst *tmp_l, char *dst, char *h_str, int h_len)
{
	int			i;
	int			j;
	int			len;

	i = skip_white_spaces(tmp_l->str, 0);
	i += (int)ft_strlen(h_str);
	i = skip_white_spaces(&tmp_l->str[i], i);
	if (tmp_l->str[i] != CMD_CHAR_Q)
		error_line(6, tmp_l->number_str);
	j = ++i;
	while (tmp_l->str[j] && tmp_l->str[j] != CMD_CHAR_Q)
		j++;
	if (tmp_l->str[j] == '\0')
		return (join_and_save(tmp_l, i, dst, h_len));
	len = j - i;
	if ((len > h_len) || (len < 0))
		error_(7);
	j++;
	j = skip_white_spaces(&tmp_l->str[j], j);
	if (tmp_l->str[j] != '\0')
		error_line(6, tmp_l->number_str);
	ft_strncpy(dst, &tmp_l->str[i], (size_t)len);
	dst[len] = '\0';
	return (tmp_l->next);
}

t_lst			*get_nm_and_comment(t_st *st, t_lst *tmp_l, char *curr_str)
{
	if (ft_strnequ(NAME_CMD_STRING, curr_str, word_len(curr_str)))
	{
		if (st->header->prog_name[0] == '\0')
			tmp_l = save_in_h(tmp_l, st->header->prog_name,
							NAME_CMD_STRING, PROG_NAME_LENGTH);
		else
			error_(4);
	}
	else if (ft_strnequ(COMMENT_CMD_STRING, curr_str, word_len(curr_str)))
	{
		if (st->header->comment[0] == '\0')
			tmp_l = save_in_h(tmp_l, st->header->comment,
							COMMENT_CMD_STRING, COMMENT_LENGTH);
		else
			error_(5);
	}
	else
		error_line(8, tmp_l->number_str);
	if (st->header->prog_name[0] != '\0' && st->header->comment[0] != '\0')
		st->is_header = 1;
	return (tmp_l);
}

void			lexical_valid_end_extract_data(t_st *st)
{
	int			i;
	t_lst		*tmp_l;

	tmp_l = st->list;
	while (tmp_l && (!st->is_header))
	{
		i = skip_white_spaces(tmp_l->str, 0);
		if (tmp_l->str[0] == '\0' || is_only_white_spaces(tmp_l->str) ||
			(tmp_l->str[i] && ((tmp_l->str[i] == COMMENT_CHAR1)
						|| (tmp_l->str[i] == COMMENT_CHAR2))))
		{
			tmp_l = tmp_l->next;
			continue;
		}
		if (tmp_l->str[i] == CMD_CHAR_D)
		{
			tmp_l = get_nm_and_comment(st, tmp_l, &tmp_l->str[i]);
			continue;
		}
		error_line(9, tmp_l->number_str);
	}
	st->list = delete_first_part_of_list(tmp_l);
	handle_main_information(st, 0);
}
