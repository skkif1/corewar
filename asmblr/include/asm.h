/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapteli <skapteli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 16:49:21 by skapteli          #+#    #+#             */
/*   Updated: 2017/12/08 17:38:28 by skapteli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../lib/libft/includes/libft.h"
# include "op.h"

typedef struct		s_args
{
	int				is_arg;
	int				int_arg;
	char			*char_arg;
}					t_args;

typedef struct		s_lst
{
	struct s_lst	*prev;
	int				number_str;
	char			*str;
	char			*label;
	char			*op_code;
	t_args			*args;
	int				bytes;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_op
{
	char			name[5];
	int				numb_args;
	int				type_args[3];
	int				id;
	int				cycles;
	char			description[50];
	int				acb;
	int				carry;
	int				label_size;
}					t_op;

typedef struct		s_header
{
	unsigned int	magic;
	char			prog_name[PROG_NAME_LENGTH + 1];
	unsigned int	prog_size;
	char			comment[COMMENT_LENGTH + 1];
}					t_header;

typedef struct		s_st
{
	t_lst			*list;
	int				is_header;
	t_header		*header;
	t_op			*op;
	char			*name_cor;
}					t_st;
/*
**	Memory allocation
*/
t_st				*initial_st(void);
t_lst				*get_new_node();
/*
**	Free memory
*/
void				make_free_node(t_lst *cur_node);
void				free_lst_node_args(t_lst *node);
void				free_list(t_st *st);
void				free_st(t_st *st);
void				free_two_dimensional_char_array(char **array);
void				free_string(char *str);
/*
**	Validation
*/
void				valid_fname_and_header(t_st *st, char **argv);
void				handle_main_information(t_st *st, int i);
void				extract_opcode_args(t_lst *curr_l, int i);
int					extract_label_and_opcode(t_st *st, t_lst *curr_l);
void				lex_valid_opcodes_arguments(t_st *st, t_lst *curr_l);
void				compare_extracted_args_with_op(t_st *st);
void				count_bytes_of_each_lst(t_st *st);
void				count_label_bytes(t_st *st);
/*
**	validate -> lexical_valid_end_extract_data.c
*/
size_t				word_len(char *word);
t_lst				*join_and_save(t_lst *tmp_l, int i, char *dst, int h_len);
t_lst				*save_in_h(t_lst *tmp_l, char *dst, char *h_str, int h_len);
t_lst				*get_nm_and_comment(t_st *st, t_lst *tmp_l, char *curr_str);
void				lexical_valid_end_extract_data(t_st *st);
/*
**	Validate helpers
*/
int					is_white_space(char c);
int					is_label_char(char *s, char c);
int					is_only_digits(char *s);
int					is_opcode(t_st *st, char *op_code);
/*
**	Saving
*/
void				save_label(t_lst *curr_l, int start, int end);
void				save_opcode(t_st *st, t_lst *curr_l, int start, int end);
void				extract_direct(t_lst *curr_l, int i, char *src);
void				extract_reg(t_lst *curr_l, int i, char *src);
void				extract_ind(t_lst *curr_l, int i, char *src);
/*
**	read -> get_info_from_file.c
*/
int					skip_white_spaces(char *str, int i);
int					is_only_white_spaces(char *str);
t_lst				*sv_in_list(t_st *st, t_lst *list, char *str, int str_num);
void				read_save_in_lst(t_st *st, int fd);
void				get_info_from_file(t_st *st, char *file_name);
/*
**	Errors
*/
void				error_(int key);
void				perror_(char *str);
void				error_line(int key, int line);
void				too_much_char_error(char c, int line);
void				error_parameter(int param_num, char *opcode, int line);
/*
**	List manipulations
*/
void				delete_node(t_st *st, t_lst *curr_l);
t_lst				*delete_first_part_of_list(t_lst *curr_l);
/*
**	Options manipulations
*/
t_op				*get_one_op_l(t_st *st, char *op_code);
void				write_data_in_file(t_st *st);
#endif
