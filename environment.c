#include "op.h"

t_env g_env;

void add_new_process(t_player *player)
{

    t_process *process = NULL;
    process = init_new_process();
    ft_lstadd(&g_env.all_process, ft_lstnew(process, sizeof(t_process)));
    player->player_number = process->registers[0];
    process->counter = 0;
};


void add_new_player()
{
    t_player *player;

    player = malloc(sizeof(t_player));


    ft_memcpy(player->player_name, "zork", ft_strlen("zork"));

    player->code = malloc(sizeof(char) * 5);
    player->code[0] = 3;
    player->code[1] = 112;
    player->code[2] = 1;
    player->code[3] = 0;
    player->code[4] = 42;
    player->code[5] = '\0';



    add_new_process(player);



    ft_memcpy(g_env.global_field, player->code, 5);
    register_color_changes(0, 5, 3);
    rewrite_memory(g_env.global_field);
}


void init_env()
{
    ft_memset(g_env.global_field, 0, 1024 * 4);
}
