/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_opcode_args.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapteli <skapteli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 20:27:16 by skapteli          #+#    #+#             */
/*   Updated: 2017/12/07 17:48:57 by skapteli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char			*strdup_without_white_spaces(char *src)
{
	char		*tmp;

	tmp = src;
	while (*tmp)
	{
		if (!is_white_space(*tmp))
			tmp++;
		else
			ft_memcpy(tmp, tmp + 1, ft_strlen(tmp) + 1);
	}
	return (ft_strdup(src));
}

char			*cut_comment(char *str_with_comment)
{
	char		*clean_str;
	int			i;

	i = 0;
	while (str_with_comment[i] && (str_with_comment[i] != COMMENT_CHAR1)
			&& (str_with_comment[i] != COMMENT_CHAR2))
		i++;
	clean_str = ft_strnew((size_t)i);
	ft_strncpy(clean_str, str_with_comment, (size_t)i);
	return (clean_str);
}

void			extract_opcode_args(t_lst *curr_l, int i)
{
	char		*dup_s;
	char		*src;
	char		**arr_s;

	dup_s = strdup_without_white_spaces(&curr_l->str[i]);
	src = cut_comment(dup_s);
	if (src[0] == SEPARATOR_CHAR || src[ft_strlen(src) - 1] == SEPARATOR_CHAR)
		error_line(6, curr_l->number_str);
	arr_s = ft_strsplit(src, ',');
	i = -1;
	while (arr_s[++i] && (i < 3))
	{
		if (arr_s[i][0] == 'r')
			extract_reg(curr_l, i, arr_s[i]);
		else if (arr_s[i][0] == DIRECT_CHAR)
			extract_direct(curr_l, i, arr_s[i]);
		else
			extract_ind(curr_l, i, arr_s[i]);
	}
	free_string(dup_s);
	free_string(src);
	free_two_dimensional_char_array(arr_s);
}
