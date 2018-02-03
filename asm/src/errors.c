/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapteli <skapteli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 18:28:34 by skapteli          #+#    #+#             */
/*   Updated: 2017/12/08 18:03:45 by skapteli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char		*g_error[22] =
{
	"Usage: ./asm filename.s\n",
	"Error: wrong file extension, should be \'filename.s\'\n",
	"Error: too short filename\n",
	"Error: invalid label char\n",
	"Error: duplicate .name\n",
	"Error: duplicate .comment\n",
	"Lexical error\n",
	"Champion name's/comment's size is wrong (min/max/max: 0/128/2048)\n",
	"Error: Wrong symbol (use: abcdefghijklmnopqrstuvwxyz_0123456789)\n",
	"Error: First requires .name and .comment, before op.code.\n",
	"Sorry, but your file is shit..\n",
	"Error: Not valid symbol in the header.\n",
	"Error: need PROG_NAME_LENGTH 1 ... 128.\n",
	"Error: need COMMENT_LENGTH 1 ... 2048.\n",
	"Error: Wrong COREWAR_EXEC_MAGIC number.\n",
	"Error: Not valid opcode.\n",
	"Error: Too many args.\n",
	"Error: Wrong T_REG.\n",
	"Error: Wrong T_DIR.\n",
	"Error: Wrong T_IND.\n",
	"Error: No such label bites while attempting to dereference token.\n",
	"Error: There is double label.\n"
};

void			error_(int key)
{
	ft_printf("%s", g_error[key]);
	exit(0);
}

void			perror_(char *str)
{
	perror(str);
	exit(0);
}

void			error_line(int key, int line)
{
	ft_printf("In line %d: %s", line, g_error[key]);
	exit(0);
}

void			too_much_char_error(char c, int line)
{
	ft_printf("Too much \'%c\' in line %d", c, line);
	exit(0);
}

void			error_parameter(int param_num, char *opcode, int line)
{
	ft_printf("Invalid parameter %d for instruction %s in line %d",
				param_num + 1, opcode, line);
	exit(0);
}
