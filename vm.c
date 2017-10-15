#include "op.h"

t_env *g_env;

int main()
{

//    init_screen();


    init_env();
    t_list *players = NULL;
    register_players(players);
    start_cycle();

//    getch();
//    dell_window();
}
