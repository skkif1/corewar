/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudakov <vrudakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 17:06:14 by omotyliu          #+#    #+#             */
/*   Updated: 2018/01/28 22:07:22 by vrudakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_OP_H
# define COREWAR_OP_H
# include <panel.h>
# include "../libft/includes/ft_printf.h"
# define IND_SIZE				2
# define REG_SIZE				4
# define DIR_SIZE				REG_SIZE
# define REG_CODE				1
# define DIR_CODE				2
# define IND_CODE				3
# define MAX_ARGS_NUMBER			4
# define MAX_PLAYERS				4
# define MEM_SIZE				(4*1024)
# define IDX_MOD					(MEM_SIZE / 8)
# define CHAMP_MAX_SIZE			(MEM_SIZE / 6)
# define COMMENT_CHAR			'#'
# define LABEL_CHAR				':'
# define DIRECT_CHAR				'%'
# define SEPARATOR_CHAR			','
# define LABEL_CHARS				"abcdefghijklmnopqrstuvwxyz_0123456789"
# define NAME_CMD_STRING			".name"
# define COMMENT_CMD_STRING		".comment"
# define REG_NUMBER				17
# define CYCLE_TO_DIE			1536
# define CYCLE_DELTA				50
# define NBR_LIVE				21
# define MAX_CHECKS				10
# define MARGIN                  2
# define BYTES_PER_ROW       64
# define ROW_LEN             (BYTES_PER_ROW * 3)
# define COL_LEN             (MEM_SIZE / BYTES_PER_ROW)
# define T_REG					1
# define T_DIR					2
# define T_IND					4
# define T_LAB					8
# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)
# define COREWAR_EXEC_MAGIC		0xea83f3

typedef char					t_arg_type;
typedef struct					s_op
{
	char						*name;
	int							arg_number;
	char						arg_type[3];
	int							order;
	int							duration;
	char						*desc;
	char						opcode;
	char						dir_as_label;
}								t_op;

typedef struct					s_header
{
	unsigned int				magic;
	char						prog_name[PROG_NAME_LENGTH + 1];
	unsigned int				prog_size;
	char						comment[COMMENT_LENGTH + 1];
}								t_header;

typedef struct					s_process
{
	char						*name;
	unsigned int				registers[REG_NUMBER];
	char						carry;
	int							counter;
	int							color;
	unsigned int				live;
	char						*current_op;
	unsigned int				id;
	unsigned int				player_num;
	int							cycle_to_execute;
	int							say_live;
	int							is_child;
}								t_process;

typedef struct					s_player
{
	unsigned char				*code;
	unsigned int				code_len;
	char						*player_name[PROG_NAME_LENGTH];
	unsigned int				player_number;
	unsigned int				real_num;
	unsigned int				last_live;
	int							live_in_period;
	int							color;
}								t_player;

typedef struct					s_env
{
	t_list						*processes;
	unsigned char				global_field[MEM_SIZE];
	int							player_in_game;
	int							cycle;
	int							cycle_to_die;
	t_list						*players;
	char						vis;
	char						vis_run;
	int							vis_delay;
	t_list						*player_files;
	int							process_number;
	int							num_live;
	int							checks;
	int							dump;
	char						*numbers;
}								t_env;

typedef struct					s_notification
{
	int							color;
	char						*notification;
}								t_notification;

extern void (*g_operation[16])(t_process *process);
extern t_op g_tab[17];
extern t_env *g_env;
int g_colors[MEM_SIZE];
WINDOW *g_memory;
WINDOW *g_stat;

void							live(t_process *process);
void							ld(t_process *process);
void							sti(t_process *process);
void							st(t_process *process);
void							add(t_process *process);
void							sub(t_process *process);
void							and(t_process *process);
void							zjmp(t_process *process);
void							ldi(t_process *process);
void							c_fork(t_process *pr);
void							lld(t_process *process);
void							lldi(t_process *process);
void							c_lfork(t_process *proc);
void							aff(t_process *process);
void							rewrite_common(void);
int								get_operation(t_process *process);
void							init_operation(int command, t_process *process);
void							get_arg_types(int *mass, char coding_byte);
void							rewrite_memory(unsigned char *buff);
void							register_color_changes(int start, int len,
								int color);
void							init_screen();
void							dell_window();
int								manage_ui();
void							rewrite_stat();
void							hold_ui();
void							add_new_process(int position, t_player *player);
void							reset_process(t_process	*process);
void							add_new_player(t_player *player);
void							init_env();
void							start_cycle();
int								lst_size(t_list *list);
int								get_opcode_by_name(char *name);
int								bytes_to_int(int start, int size);
unsigned int					big_to_little(unsigned int value);
void							winner(void);
void							print_exit(char *str);
void							add_all_players(t_list *players);
void							set_fake_numbers(void);
void							check_number_avail(t_player *player_to,
								unsigned int num);
t_player						*find_player(unsigned int number);
void							type_to_size(int *mass, int dir_size);
int								validate_reqistry(int value);
void							invalid_coding_byte(const int *arg_t,
								t_process *proc, int params);
int								get_register(int counter, int skip);
void							pause_war();
int								check_cursor(int position);
void							parse_args(int argc, char **argv);
void							bytes_to_memory(int start, const void *value,
								size_t len, int color);
void							register_players_auto(t_list **players);

#endif
