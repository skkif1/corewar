#include "../includes/op.h"

t_env *g_env;

//void    register_players_auto(t_list *players)
//{
//    char    *file;
//
//    file = NULL;
//
////    while (get_next_line());
//}

void register_players(t_list *players)
{
    t_player *player;
    t_player *player2;

    //static unsigned int name = 4294967295;
    player = malloc(sizeof(t_player));
    player2 = malloc(sizeof(t_player));


    ft_memcpy(player->player_name, "zork", ft_strlen("zork"));
    player->player_number = 4294967295;
    player->code_len = 17;
    player->color = 3;

    player->code = malloc(sizeof(char) * 20);
    player->code[0] = 1;
    player->code[1] = 255;
    player->code[2] = 255;
    player->code[3] = 255;
    player->code[4] = 255;
    player->code[5] = 2;
    player->code[6] = 208;
    player->code[7] = 0;
    player->code[8] = 0;
    player->code[9] = 4;
    player->code[10] = 11;
    player->code[11] = 104;
    player->code[12] = 4;
    player->code[13] = 0;
    player->code[14] = 20;
    player->code[15] = 0;
    player->code[16] = 20;
    player->code[17] = '\0';


    ft_lstadd(&players, ft_lstnew(player, sizeof(t_player)));

    ft_memcpy(player2->player_name, "zork2", ft_strlen("zork2"));
    player2->player_number = 4294967294;
    player2->code_len = 5;
    player2->color = 5;


    player2->code = malloc(sizeof(char) * 5);
    player2->code[0] = 1;
    player2->code[1] = 255;
    player2->code[2] = 255;
    player2->code[3] = 255;
    player2->code[4] = 253;
    player2->code[5] = '\0';

    ft_lstadd(&players, ft_lstnew(player2, sizeof(t_player)));

    g_env->player_in_game = 2;

    g_env->players = players;

    while (players)
    {
        add_new_player(players->content);
        players = players->next;
    }


}

void add_new_player(t_player *player)
{
    int start;
    int j;
    int end;

    j = 0;
    start = (unsigned int) (MEM_SIZE / g_env->player_in_game * (4294967295 - player->player_number));
    end = start + player->code_len;

    add_new_process(start, player);

    while (start < end)
    {
        g_env->global_field[start++] = player->code[j++];
    }
    register_color_changes(start - player->code_len, player->code_len, player->color);
    rewrite_memory(g_env->global_field);

}


void init_env()
{
    g_env = malloc(sizeof(t_env));
    ft_memset(g_env->global_field, 0, MEM_SIZE);
    g_env->cycle_to_die = CYCLE_TO_DIE;
    g_env->cycle = 0;
    g_env->vis_delay = 1000;
    g_env->vis_run = 0;
    g_env->player_files = NULL;
}
