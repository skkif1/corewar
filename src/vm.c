#include "../includes/op.h"

t_env *g_env;

int main(int argc, char **argv)
{


    init_env();
    parse_args(argc, argv);

    if (g_env->vis)
        init_screen();

    t_list *players = NULL;
    register_players(players);
//    register_players_auto(players);
    start_cycle();

    if(g_env->vis)
    {
        getch();
        dell_window();
    }

}
