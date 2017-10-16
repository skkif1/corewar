#ifndef COREWAR_OP_H
#define COREWAR_OP_H

#include <panel.h>
#include "libft/ft_printf.h"


#define IND_SIZE				2
#define REG_SIZE				4
#define DIR_SIZE				REG_SIZE


# define REG_CODE				1
# define DIR_CODE				2
# define IND_CODE				3


#define MAX_ARGS_NUMBER			4
#define MAX_PLAYERS				4
#define MEM_SIZE				(4*1024)
#define IDX_MOD					(MEM_SIZE / 8)
#define CHAMP_MAX_SIZE			(MEM_SIZE / 6)

#define COMMENT_CHAR			'#'
#define LABEL_CHAR				':'
#define DIRECT_CHAR				'%'
#define SEPARATOR_CHAR			','

#define LABEL_CHARS				"abcdefghijklmnopqrstuvwxyz_0123456789"

#define NAME_CMD_STRING			".name"
#define COMMENT_CMD_STRING		".comment"

#define REG_NUMBER				16

#define CYCLE_TO_DIE			1536
#define CYCLE_DELTA				50
#define NBR_LIVE				21
#define MAX_CHECKS				10
#define MARGIN                  2 //custom def


typedef char	t_arg_type;

#define T_REG					1
#define T_DIR					2
#define T_IND					4
#define T_LAB					8


# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)
# define COREWAR_EXEC_MAGIC		0xea83f3



typedef struct		s_op
{
    char			*name;
    int				arg_number;
    char			arg_type[3];
    int			    order;
    int				duration;
    char			*desc;
    char			opcode;
    char			dir_as_label;
}					t_op;

typedef struct		header_s
{
    unsigned int		magic;
    char				prog_name[PROG_NAME_LENGTH + 1];
    unsigned int		prog_size;
    char				comment[COMMENT_LENGTH + 1];
}					header_t;


typedef struct		process_s
{
    char *name;
    unsigned int registers[REG_NUMBER];
    char carry;
    unsigned int counter;
    int color;
    unsigned int live;
    char *current_op;
    int cycle_to_execute;
}					t_process;

typedef struct		player_s
{
    unsigned char *code;
    unsigned int code_len;
    char *player_name[PROG_NAME_LENGTH];
    unsigned int player_number;
    unsigned int last_live;
    int color;
}					t_player;

typedef struct		env_s
{
    t_list *processes;
    unsigned char global_field[MEM_SIZE];
    int player_in_game;
    unsigned int cycle;
    int cycle_to_die;
    t_list *players;
    char vis;

}					t_env;

extern void (*operation[16])(t_process *process);
extern t_op g_tab[17];
extern t_env *g_env;


//comands

void live(t_process *process);


//operation_exec function

int get_operation(t_process *process);
void init_operation(int command, t_process *process);



//ui functions
void rewrite_memory(unsigned char *buff);
void register_color_changes(int start, int len, int color);
void init_screen();
void dell_window();
void place_cursor(t_process *process);

//process function
void add_new_process(int position, t_player *player);


//envi functions
void add_new_player(t_player *player);
void init_env();
void register_players(t_list *players);


//cycle functions
void start_cycle();

//util
int lst_size(t_list *list);
void screen_cycle_status();
int get_opcode_by_name(char *name);


//parse arg
void parse_args(int argc, char **argv);

#endif //COREWAR_OP_H
